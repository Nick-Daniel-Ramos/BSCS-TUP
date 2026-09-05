#include<iostream>
#include<cstdlib>
#include<string>
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
        quiz2 = q2;
        quiz3 = q3;
    }
};

struct Node
{
    Record data;
    Node *next;
    Node *prev;

    Node(Record X)
    {
        data = X;
    }
};

class Student
{
private:
    Node *head, *tail;
public:
    mp3()
    {
        head = tail = NULL;
    }
    ~mp3()
    {
        Node *p = head;
        
    }
};


