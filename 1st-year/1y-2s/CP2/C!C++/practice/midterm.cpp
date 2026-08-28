#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>

using namespace std;

#define MAX_STUDENTS 30
#define NUM_SUBJECTS 5

void inputStudents(string names[], float grades[][5], int& counter);
void displayTable(string names[], float grades[][5], int counter);
void flagFailing(string names[], float grades[][5], int counter);

float computeAverage(float grades[], int n);
float findHighest(float grades[][5], int counter);
float findLowest(float grades[][5], int counter);
float recursiveSum(float arr[], int n);
float recursiveMax(float arr[], int n);

int recursiveSearch(string names[], string target, int i, int n);


int main(){
    string names[30];
    string target;
    float grades[30][5];
    float average = 0;
    int counter = 0;
    int choice;
    int pos;

    while(true){
        cout << "[1] Input Students" << endl;
        cout << "[2] Display Table" << endl;
        cout << "[3] Show Statistics" << endl;
        cout << "[4] Search Student" << endl;
        cout << "[5] Exit" << endl;
        cout << "Select [1-5]: ";
        cin >> choice;
        cin.ignore();
        switch(choice){
        case 1:
            inputStudents(names, grades, counter);
            system("cls");
            break;
        case 2:
            if(counter == 0){
                cout << "No record of students yet!" << endl;
                system("pause");
                system("cls");
                break;
            }
            displayTable(names, grades, counter);
            break;
        case 3:
            if(counter == 0){
                cout << "No record of students yet!" << endl;
                system("pause");
                system("cls");
                break;
            }
            cout << "Highest Average: " << findHighest(grades, counter) << endl;
            cout << "Lowest Average: " << findLowest(grades, counter) << endl;
            flagFailing(names, grades, counter);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "Enter student name: ";
            getline(cin, target);
            pos = recursiveSearch(names, target, 0, counter);

            cout << left << setw(20) << "NAME";
            cout << setw(10) << "SUB 1";
            cout << setw(10) << "SUB 2";
            cout << setw(10) << "SUB 3";
            cout << setw(10) << "SUB 4";
            cout << setw(10) << "SUB 5";
            cout << setw(10) << "AVERAGE";
            cout << setw(10) << "REMARKS" << endl;

            average = computeAverage(grades[pos], 5);

            cout << left << setw(20) << names[pos];
            cout << setw(10) << grades[pos][0];
            cout << setw(10) << grades[pos][1];
            cout << setw(10) << grades[pos][2];
            cout << setw(10) << grades[pos][3];
            cout << setw(10) << grades[pos][4];
            cout << setw(10) << average;
            cout << setw(10) << (average >= 75 ? "PASSED" : "FAILED") << endl;
            system("pause");
            system("cls");
            break;
        case 5:
            exit(0);
        }
    }

    return 0;
}

void inputStudents(string names[], float grades[][5], int& counter){
    int i, subject;
    char choice;
    do{
        subject = 0;

        cout << "Enter student name: "; getline(cin, names[counter]);
        cout << "Subject 1 Score: "; cin >> grades[counter][subject];
        while(grades[counter][subject] < 0 || grades[counter][subject] > 100){
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore();
            cout << "Input valid score: "; cin >> grades[counter][subject];
        }
        cout << "Subject 2 Score: "; cin >> grades[counter][++subject];
        while(grades[counter][subject] < 0 || grades[counter][subject] > 100){
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore();
            cout << "Input valid score: "; cin >> grades[counter][subject];
        }
        cout << "Subject 3 Score: "; cin >> grades[counter][++subject];
        while(grades[counter][subject] < 0 || grades[counter][subject] > 100){
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore();
            cout << "Input valid score: "; cin >> grades[counter][subject];
        }
        cout << "Subject 4 Score: "; cin >> grades[counter][++subject];
        while(grades[counter][subject] < 0 || grades[counter][subject] > 100){
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore();
            cout << "Input valid score: "; cin >> grades[counter][subject];
        }
        cout << "Subject 5 Score: "; cin >> grades[counter][++subject];
        while(grades[counter][subject] < 0 || grades[counter][subject] > 100){
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore();
            cout << "Input valid score: "; cin >> grades[counter][subject];
        }
        counter++;
        cout << "Do you wish to add more? [y/n] "; cin >> choice; cin.ignore();
    system("cls");
    }while(choice != 'n');
}

void displayTable(string names[], float grades[][5], int counter){
    int i;
    float average = 0;

    system("cls");
    cout << left << setw(10) << "NO.";
    cout << setw(20) << "NAME";
    cout << setw(10) << "SUB 1";
    cout << setw(10) << "SUB 2";
    cout << setw(10) << "SUB 3";
    cout << setw(10) << "SUB 4";
    cout << setw(10) << "SUB 5";
    cout << setw(10) << "AVERAGE";
    cout << setw(10) << "REMARKS" << endl;

    for(i = 0; i < counter; i++){
        average = computeAverage(grades[i], 5);

        cout << left << setw(10) << i+1;
        cout << setw(20) << names[i];
        cout << setw(10) << grades[i][0];
        cout << setw(10) << grades[i][1];
        cout << setw(10) << grades[i][2];
        cout << setw(10) << grades[i][3];
        cout << setw(10) << grades[i][4];
        cout << setw(10) << average;
        cout << setw(10) << (average >= 75 ? "PASSED" : "FAILED") << endl;
    }
    system("pause");
    system("cls");
}

float computeAverage(float grades[], int n){
    int i;
    float sum = recursiveSum(grades, n);
    return sum / n;
}

float findHighest(float grades[][5], int counter){
    float average = 0;
    float best = 0;
    int i;
    for(i = 0; i < counter; i++){
        average = computeAverage(grades[i], 5);
        if(average > best){
            best = average;
        }
    }
    return best;
}

float findLowest(float grades[][5], int counter){
    float average = 0;
    int i;
    float lowest = computeAverage(grades[0], 5);
    for(i = 0; i < counter; i++){
        average = computeAverage(grades[i], 5);
        if(average < lowest){
            lowest = average;
        }
    }
    return lowest;
}

void flagFailing(string names[], float grades[][5], int counter){
    int i;

    cout << "FAILING STUDENTS" << endl;
    cout << left << setw(20) << "NAME";
    cout << setw(10) << "SCORE";
    cout << setw(10) << "REMARKS" << endl;

    for(i = 0; i < counter; i++){
        float average = computeAverage(grades[i], 5);
        if(average < 75){
            cout << left << setw(20) << names[i];
            cout << setw(10) << average;
            cout << setw(10) << "FAILED" << endl;
        }
    }
}

float recursiveSum(float arr[], int n){
    if(n == 0){
        return 0;
    } else {
        return arr[0] + recursiveSum(arr + 1, n - 1);
    }
}
/*
float recursiveMax(float arr[], int n){
    if(n == 0){
        return 0;
    } else {
        if(arr[0] < recursiveMax(arr + 1, n - 1)){
        }
        return arr[n];
    }
}
*/

int recursiveSearch(string names[], string target, int i, int n){
    if (i == n){
        return -1;
    } else if(names[i] == target){
        return i;
    } else {
        return recursiveSearch(names, target, i + 1, n);
    }
}

