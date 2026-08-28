#include <iostream>
#include <iomanip>
#include <string.h>
#define MAX 5

using namespace std;

typedef struct Record{
    string name;
    int quiz1, quiz2, quiz3;
} student;

class MyClass{
private:
    student individual[MAX];
    int last = -1;
    bool isfull(){
        return last == MAX - 1;
    }
    bool isEmpty(){
        return last == -1;
    }
    int locate(string p_name){
        int i;
        for(i = 0; i <= last; i++){
            if(individual[i].name == p_name){
                return i;
            }
        }
        return -1;
    }
    float average(int qz1, int qz2, int qz3){
        return (qz1 + qz2 + qz3) / 3.0;
    }
public:
    void addRecord(student n){
        if (isfull()){
            cout << "Record is full!" << endl;
            return;
        } else{
            last++;
            individual[last] = n;
        }
    }

    void delRecord(student n){
        if(isEmpty()){
            cout << "Record is empty!" << endl;
            system("pause");
        } else {
            int pos = locate(n.name);
            if(pos == -1){
                cout << n.name << " is not found!" << endl;
                system("pause");
            } else {
                int i;
                for(i = pos; i < last; i++){
                    individual[i] = individual[i+1];
                }
                last--;
                cout << n.name << " is successfully deleted!" << endl;
                system("pause");
            }
        }
    }

    void display(){
        int i;
        float ave;
        if(isEmpty()){
            cout << "Array is empty" << endl;
        } else {
            cout << left << setw(4) << "No."
                 << setw(20) << "NAME"
                 << setw(10) << "QUIZ 1"
                 << setw(10) << "QUIZ 2"
                 << setw(10) << "QUIZ 3"
                 << setw(10) << "AVERAGE"
                 << setw(10) << "REMARKS" << endl;
        }
        for(i = 0; i <= last; i++){
            ave = average(individual[i].quiz1, individual[i].quiz2, individual[i].quiz3);

            cout << left << setw(4) << i + 1
                << setw(20) << individual[i].name
                << setw(10) << individual[i].quiz1
                << setw(10) << individual[i].quiz2
                << setw(10) << individual[i].quiz3
                << setw(10) << ave
                << setw(10) << (ave >=75 ? "PASSED" : "FAILED") << endl;
        }
    }

    int menu(){
        int choice;

        system("cls");
        cout << "MENU\n\n";
        cout << "[1]Add Record" << endl;
        cout << "[2]Delete Record" << endl;
        cout << "[3]Display All Record" << endl;
        cout << "[4]Exit" << endl;
        cout << "Select [1-4] only: ";
        cin >> choice;
        cin.ignore();
        return choice;
    }
};

int main(){
    MyClass m_class;

    student main;

    while(true){
        switch(m_class.menu()){
        case 1:
            cout << "Input name: ";
            getline(cin, main.name);

            cout << "Quiz 1 score: "; cin >> main.quiz1;
            cout << "Quiz 2 score: "; cin >> main.quiz2;
            cout << "Quiz 3 score: "; cin >> main.quiz3;
            cin.ignore();

            m_class.addRecord(main);
            break;
        case 2:
            cout << "Input name: ";
            getline(cin, main.name);
            m_class.delRecord(main);
            break;
        case 3:
            m_class.display();
            system("pause");
            break;
        case 4:
            cout << "Thank you for using the program.";
            exit(0);
        default:
            cout << "1-4 lang po mam/ser\n";
            system("pause");
        }
    }
}
