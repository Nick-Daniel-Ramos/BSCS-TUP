//NAME: RAMOS, NICK DANIEL B.
//SECTION: BSCS-2A

#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>

using namespace std;

struct Record
{
    string name;
    int quiz1, quiz2, quiz3;

    Record()
    {
        name = "";
        quiz1 = 0;
        quiz2 = 0;
        quiz3 = 0;
    }

    Record(string n, int q1, int q2, int q3)
    {
        name = n;
        quiz1 = q1;
        quiz1 = q2;
        quiz1 = q3;
    }
};

struct Node
{
    Record data;
    Node *next;

    Node(Record X)
    {
        data = X;
    }
};

class Student
{
private:
    Node *head;

    float average(Record X);
public:
    Student()
    {
        head = NULL;
    }
    ~Student()
    {
        Node *p;
        while (head != NULL)
        {
            p = head;
            head = head->next;
            delete(p);
        }
    }

    void add(Record X);
    void del(string n);
    void update(string n);
    void display();
    void save();
    void retrieve();
};

int menu()
{
    int choice;
    system("cls");
    cout << "MENU" << endl
    << "[1] Add Record" << endl
    << "[2] Update Record" << endl
    << "[3] Delete Record" << endl
    << "[4] Display Record" << endl
    << "[0] Exit" << endl
    << "Select [0-4] only: "; cin >> choice;
    getchar();
    return choice;
}

float Student::average(Record X){return (X.quiz1 + X.quiz2 + X.quiz3) / 3.0;}

void Student::add(Record X)
{
    Node *p, *q, *newNode;
    p = q = head;
    newNode = new Node(X);

    while (p != NULL && newNode->data.name > p->data.name)
    {
        q = p;
        p = p->next;
    }

    if(p == head)
    {
        head = newNode;
    }else
        q->next = newNode;
    
    newNode->next = p;
    cout << "Successfully added!" << endl;
    system("pause");
}

void Student::del(string n)
{
    Node *p, *q;
    p = q = head;
    while (p != NULL && p->data.name != n)
    {
        q = p;
        p = p->next;
    }
    if(p == NULL)
    {
        cout << "Record not found" << endl;
        system("pause");
    } else 
    {
        if(p == head)
            head = head->next;
        else
            q->next = p->next;
        delete p;
    }
    cout << "Successfully deleted!" << endl;
    system("pause");
}

void Student::update(string n)
{
    int choice;
    Node *p, *q;
    p = q = head;
    while (p != NULL && p->data.name != n)
    {
        q = p;
        p = p->next;
    }

    while (true)
    {
        system("cls");
        cout << "UPDATE MENU" << endl
        << "NAME: " << p->data.name << endl
        << "[1] Update Quiz 1" << endl
        << "[2] Update Quiz 2" << endl
        << "[3] Update Quiz 3" << endl
        << "[0] Exit" << endl
        << "Select [0-3] only: "; cin >> choice;
        getchar();
        switch (choice)
        {
        case 0:
            cout << "Exiting..." << endl;
            return;
        case 1:
            cout << "Insert quiz 1: "; cin >> p->data.quiz1;
            getchar();
            system("pause");
            break;
        case 2:
            cout << "Insert quiz 2: "; cin >> p->data.quiz2;
            getchar();
            system("pause");
            break;
        case 3:
            cout << "Insert quiz 3: "; cin >> p->data.quiz3;
            getchar();
            system("pause");
            break;
        default:
            cout << "Select [0-3] only: " << endl;
            system("pause");
            continue;
        }
    }
    cout << "Successfully updated!" << endl;
    system("pause");
}

void Student::display()
{
    float ave = 0.0;
    int i = 0;
    Node *p;
    p = head;
    system("cls");
    cout << left << setw(10) << "NO."
    << setw(20) << "NAME"
    << setw(10) << "QUIZ1"
    << setw(10) << "QUIZ2"  
    << setw(10) << "QUIZ3"  
    << setw(10) << "AVERAGE"
    << setw(10) << "REMARKS" << endl;
    while (p != NULL)
    {
        ave = average(p->data);
        cout << left << setw(10) << i++
        << setw(20) << p->data.name
        << setw(10) << p->data.quiz1
        << setw(10) << p->data.quiz2  
        << setw(10) << p->data.quiz3  
        << setw(10) << ave
        << setw(10) << (ave >= 75 ? "PASSED" : "FAILED") << endl;
        p = p->next;
    }
    system("pause");
}

void Student::save()
{
    ofstream file("sample.csv");
    if(!file)
    {
        cout << "File error" << endl;
        return;
    }
    Node *p = head;
    while (p != NULL)
    {
        file << p->data.name << ","
        << p->data.quiz1 << ","
        << p->data.quiz2 << ","
        << p->data.quiz3 << endl;
        p = p->next;
    }
    file.close();
}

void Student::retrieve()
{
    ifstream file("sample.csv");

    if(!file)
    {
        cout << "File error" << endl;
        return;
    }
    string line;
    string sq1, sq2, sq3;

    Record N;
    while (getline(file, line))
    {
        if(line.empty())
        {
            continue;
        }
        stringstream ss(line);

        getline(ss, N.name, ',');
        getline(ss, sq1, ',');
        getline(ss, sq2, ',');
        getline(ss, sq3, ',');
        N.quiz1 = stoi(sq1);
        N.quiz2 = stoi(sq2);
        N.quiz3 = stoi(sq3);
        add(N);
    }
    file.close();
}


int main()
{
    Student mClass;
    Record mData;
    mClass.retrieve();

    while (true)
    {
        switch (menu())
        {
        case 0:
            cout << "Exiting..." << endl;
            mClass.save();
            exit(0);
            break;
        case 1:
            cout << "Insert name: "; getline(cin, mData.name);
            cout << "Insert quiz 1: "; cin >> mData.quiz1;
            cout << "Insert quiz 2: "; cin >> mData.quiz2;
            cout << "Insert quiz 3: "; cin >> mData.quiz3;
            getchar();
            mClass.add(mData);
            break;
        case 2:
            cout << "Insert name: "; getline(cin, mData.name);
            mClass.update(mData.name);
            break;
        case 3:
            cout << "Insert name: "; getline(cin, mData.name);
            mClass.del(mData.name);
            break;
        case 4:
            mClass.display();
            break;
        default:
            cout << "Select [0-3] only: " << endl;
            system("pause");
            continue;
        }
    }
    
    return 0;
}