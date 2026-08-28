#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#define MAX 5
#define array_size 128
using namespace std;

string name[MAX];
int quiz1[MAX], quiz2[MAX], quiz3[MAX], age[MAX];
int last = -1;

void addR(string naME, int qz1, int qz2, int qz3);
void delR(string naME);
void display();

int locate(string naME);
int menu();

bool isEmpty();
bool isFull();

float average(int qz1, int qz2, int qz3);

int main(){
    string name_menu;
    int q1, q2 ,q3;
    float average_menu = 0.0;

    while (true) {
        switch(menu()){
        case 1:
            cout << "Input name: ";
            getline(cin, name_menu);

            cout << "Quiz 1 score: "; cin >> q1;
            cout << "Quiz 2 score: "; cin >> q2;
            cout << "Quiz 3 score: "; cin >> q3;

            addR(name_menu, q1, q2, q3);
            break;
        case 2:
            cout << "Input name: ";
            getline(cin, name_menu);
            delR(name_menu);
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Thank you for using me.";
            exit(0);
        default:
            cout << "1-4 lang po mam/ser\n";
            system("pause");
        }
    }
    return 0;
}

void addR(string naME, int qz1, int qz2, int qz3){
    if(isFull()){
        printf("The array is already full!\n");
        system("pause");
    } else if(locate(naME)!= -1){
            cout << naME << " is already in record\n";
            system("pause");
            system("cls");
        } else {
        last++;
        name[last] = naME;
        quiz1[last] = qz1;
        quiz2[last] = qz2;
        quiz3[last] = qz3;
        cout << naME << " is successfully added!\n";
        system("pause");
    }
}
void delR(string naME){
    int i, p;
    if(isEmpty()){
        printf("The array is empty!\n");
        system("pause");
    } else {
        p = locate(naME);
        if(p==-1){
            cout << naME << " is not found\n";
            system("pause");
        } else{
            for(i=p;i<last;i++){
                name[i] = name[i+1];
                quiz1[i] = quiz1[i+1];
                quiz2[i] = quiz2[i+1];
                quiz3[i] = quiz3[i+1];
            }
            last--;
            cout << naME << " is successfully deleted\n";
            system("pause");
        }
    }
}
void display(){
    int i;
    float ave = 0.0;
    system("cls");

    if(isEmpty()){
        cout << "Array is empty\n";
    }else {

    cout << left << setw(4) << "No."
         << setw(20) << "NAME"
         << setw(10) << "QUIZ 1"
         << setw(10) << "QUIZ 2"
         << setw(10) << "QUIZ 3"
         << setw(10) << "AVERAGE"
         << setw(10) << "REMARKS" << std :: endl;

    for(i=0;i<=last;i++){

        ave = average(quiz1[i], quiz2[i], quiz3[i]);

        cout << left << setw(4) << i + 1
         << setw(20) << name[i]
         << setw(10) << quiz1[i]
         << setw(10) << quiz2[i]
         << setw(10) << quiz3[i]
         << setw(10) << ave
         << setw(10) << (ave >=75 ? "PASSED" : "FAILED") << std :: endl;
        }
    }
    system("pause");
}
int locate(string naME){
    int i;
    for(i=0;i<=last;i++){
        if(name[i] == naME)
            return i;
    }
    return -1;  // Not found
}

bool isEmpty(){
    return last == -1;
}
bool isFull(){
    return last == MAX-1;
}
int menu(){
    int choice;

    system("cls");
    cout << "MENU\n\n";
    cout << "[1]Add Record" << std :: endl;
    cout << "[2]Delete Record" << std :: endl;
    cout << "[3]Display All Record" << std :: endl;
    cout << "[4]Exit" << std :: endl;
    cout << "Select [1-4] only: " << std :: endl;
    cin >> choice;
    getchar();
    return choice;
}

float average(int qz1, int qz2, int qz3){
    return (float)(qz1 + qz2 + qz3) / 3.0;
}

