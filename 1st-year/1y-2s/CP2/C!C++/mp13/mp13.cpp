#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#define MAX 5
using namespace std;

const string file_name = "sample.txt";

typedef struct Record {
    string name;
    int quiz1, quiz2, quiz3;

    // Default constructor (REQUIRED for array)
    Record() {
        name = "";
        quiz1 = 0;
        quiz2 = 0;
        quiz3 = 0;
    }

    // Parameterized constructor
    Record(string p_name, int p_q1, int p_q2, int p_q3) {
        name = p_name;
        quiz1 = p_q1;
        quiz2 = p_q2;
        quiz3 = p_q3;
    }
} student;

class MyClass {
    private:
        student individual[MAX]; // array of structure
        int last;

        bool isFull() {
            return last == MAX - 1;
        }
        bool isEmpty() {
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
        float average(int q1, int q2, int q3) {
            return (q1 + q2 + q3) / 3.0;
        }

    public:
        MyClass() { // initialize the array to empty
            last = -1;
        }

        void addRecord(student n) {
            if (isFull()) {
                cout << "Record is full!" << endl;
                return;
            }
            individual[++last] = n;
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

        void display() {
            if (isEmpty()) {
                cout << "Array is empty" << endl;
                return;
            }

            float ave;
            cout << left << setw(4)  << "No."
                         << setw(20) << "NAME"
                         << setw(10) << "QUIZ 1"
                         << setw(10) << "QUIZ 2"
                         << setw(10) << "QUIZ 3"
                         << setw(10) << "AVERAGE"
                         << setw(10) << "REMARKS" << endl;

            for (int i = 0; i <= last; i++) {
                ave = average(individual[i].quiz1, individual[i].quiz2, individual[i].quiz3);
                cout << left << setw(4)  << i + 1
                             << setw(20) << individual[i].name
                             << setw(10) << individual[i].quiz1
                             << setw(10) << individual[i].quiz2
                             << setw(10) << individual[i].quiz3
                             << setw(10) << ave
                             << setw(10) << (ave >= 75 ? "PASSED" : "FAILED") << endl;
            }
        }

        void retrieve() {
            ifstream fp(file_name);
            string lineStr;
            while (getline(fp, lineStr)) {
                stringstream ss(lineStr);
                string name, q1Str, q2Str, q3Str;
                int r_qz1, r_qz2, r_qz3;

                // split using comma
                if (getline(ss, name, ',') && getline(ss, q1Str, ',') &&
                    getline(ss, q2Str, ',') && getline(ss, q3Str)) {
                    r_qz1 = stoi(q1Str); // string to integer
                    r_qz2 = stoi(q2Str);
                    r_qz3 = stoi(q3Str);
                    if (!name.empty()) {
                        addRecord(Record(name, r_qz1, r_qz2, r_qz3));
                    }
                }
            }
            fp.close();
        }

        void save() {
            ofstream fp(file_name);
            if (!fp.is_open()) {
                cout << "Error: Could not open file for saving!" << endl;
                return;
            }
            for (int i = 0; i <= last; i++) {
                fp << individual[i].name  << ","
                   << individual[i].quiz1 << ","
                   << individual[i].quiz2 << ","
                   << individual[i].quiz3 << endl;
            }
            fp.close();
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

int main() {
    MyClass m_class;
    student main;
    m_class.retrieve();  // load from file
    m_class.display();   // show data

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
            m_class.save();      // save back to file
            exit(0);
        default:
            cout << "1-4 lang po mam/ser\n";
            system("pause");
        }
    }
}
