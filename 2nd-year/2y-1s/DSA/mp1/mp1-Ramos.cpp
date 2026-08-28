/*
NAME: RAMOS, NICK DANIEL B.
SECTION: BSCS-2A
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>

#define MAX 5

using namespace std;

struct Record
{
    string name;
    int quiz1;
    int quiz2;
    int quiz3;
    
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
        quiz2 = q2;
        quiz3 = q3;
    }
};

class Student
{
    private:
        Record std[MAX];
        int last;

        bool isFull();
        bool isEmpty();
        int locatePos(string n);
        float average(Record X);
        
    public:
        int locate(string n);
        void makeNull();
        void addRec(Record X);
        void delRec(string n);
        void updateRec(string n);
        void display();
        void save();
        void retrieve();
};

int menu();

int main()
{
    Record data;
    Student st;
    st.makeNull();
    st.retrieve();

    while (true)
    {
        switch (menu())
        {
        case 0:
            cout << "Exiting..." << endl;
            st.save();
            system("pause");
            exit(0);
        case 1:
            cout << "Input name: "; getline(cin, data.name);
            if(st.locate(data.name) != -1)
            {
                cout << "Duplicated Name" << endl;
                system("pause");
                break;
            }
            cout << "Input quiz 1: "; cin >> data.quiz1;
            cout << "Input quiz 2: "; cin >> data.quiz2;
            cout << "Input quiz 3: "; cin >> data.quiz3;
            getchar();
            st.addRec(data);
            break;
        case 2:
            cout << "Input name: "; getline(cin, data.name);
            st.updateRec(data.name);
            break;
        case 3:
            cout << "Input name: "; getline(cin, data.name);
            st.delRec(data.name);
            break;
        case 4:
            st.display();
            break;
        default:
            cout << "Select [0-4] only" << endl;
            system("pause");
            continue;
        }
    }
    
    return 0;
}

int menu()
{
    int choice;
    system("cls");
    cout << "MENU" << endl
    << "[1] Add Record" << endl
    << "[2] Update Record" << endl
    << "[3] Delete Record" << endl
    << "[4] Display" << endl
    << "[0] Exit" << endl
    << "Select [0-4]: "; cin >> choice; 
    getchar();
    return choice;
}

bool Student::isFull(){ return last == MAX-1;}
bool Student::isEmpty(){ return last == -1;}

int Student::locate(string n)
{
    for(int i = 0; i <= last; i++)
    {
        if(std[i].name == n) return i;
    }
    return -1;
}

int Student::locatePos(string n)
{
    int i;
    for(i = 0; i <= last; i++)
    {
        if(std[i].name > n) return i;
    }
    return i;
}

float Student::average(Record X){ return (X.quiz1 + X.quiz2 + X.quiz3)/3.0; }

void Student::makeNull(){ last = -1; }

void Student::addRec(Record X)
{
    if(isFull())
    {
        cout << "Record is full" << endl;
        system("pause");
        return;
    }
    int pos = locatePos(X.name);
    last++;
    for(int i = last; i > pos; i--)
    {
        std[i] = std[i-1];
    }
    std[pos] = X;
    cout << "Record successfully added" << endl;
    system("pause");
    return;
}

void Student::delRec(string n)
{
    if(isEmpty())
    {
        cout << "Record is empty" << endl;
        system("pause");
        return;
    }
    int pos = locate(n);
    if(pos == -1)
    {
        cout << "Record not found" << endl;
        system("pause");
        return;
    }
    for(int i = pos; i < last; i++)
    {
        std[i] = std[i+1];
    }
    last--;
    cout << "Record successfully deleted" << endl;
    system("pause");
    return;
}

void Student::display()
{
    if(isEmpty())
    {
        cout << "Record is empty" << endl;
        system("pause");
        return;
    }
    float ave = 0.0;
    cout << left << setw(20) << "NAME"
    << setw(10) << "QUIZ 1"
    << setw(10) << "QUIZ 2"
    << setw(10) << "QUIZ 3"
    << setw(10) << "AVERAGE"
    << setw(10) << "REMARKS" << endl;
    for(int i = 0; i <= last; i++)
    {
        ave = average(std[i]);
        cout << left << setw(20) << std[i].name
        << setw(10) << std[i].quiz1
        << setw(10) << std[i].quiz2
        << setw(10) << std[i].quiz3
        << setw(10) << ave
        << setw(10) << (ave >= 75 ? "PASSED": "FAILED") << endl;
    }
    system("pause");
    return;
}

void Student::updateRec(string n)
{
    if(isEmpty())
    {
        cout << "Record is empty" << endl;
        system("pause");
        return;
    }
    int pos = locate(n);
    int choice;
    if(pos == -1)
    {
        cout << "Record not found" << endl;
        system("pause");
        return;
    }

    while(true)
    {
        system("cls");
        cout << "UPDATE MENU" << endl
        << "Name: " << std[pos].name << endl
        << "[1] Update Quiz 1" << endl
        << "[2] Update Quiz 2" << endl
        << "[3] Update Quiz 3" << endl
        << "[0] Exit" << endl
        << "Select [0-3] only: "; cin >> choice;
        getchar();
        switch (choice)
        {
        case 0:
            cout << "Record successfully updated" << endl;
            cout << "Exiting..." << endl;
            system("pause");
            return;
        case 1:
            cout << "Input Quiz 1: "; cin >> std[pos].quiz1;
            getchar();
            break;
        case 2:
            cout << "Input Quiz 2: "; cin >> std[pos].quiz2;
            getchar();
            break;
        case 3:
            cout << "Input Quiz 3: "; cin >> std[pos].quiz3;
            getchar();
            break;
        default:
            cout << "Select [0-3] only" << endl;
            system("pause");
            continue;
        }
    }
}

void Student::save()
{
    ofstream file("sample.csv");
    if(!file)
    {
        cout << "File error" << endl;
        return;
    }
    for(int i = 0; i <= last; i++)
    {
        file << std[i].name << ","
        << std[i].quiz1 << ","
        << std[i].quiz2 << ","
        << std[i].quiz3 << endl;
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
        addRec(N);
    }
    file.close();
}