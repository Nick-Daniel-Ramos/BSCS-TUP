#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

class Array{
private:
    int arr1[128] = {1,2,3,4,5};
    int last = 4;
public:
    int getLast(){
        static int temp = last;
        return temp;
    }

    bool isDuplicate(int n){
        int i;
        for(i = 0; i <= last; i++){
            if(n == arr1[i]){
                return true;
            }
        }
        return false;
    }

    int locate(int n){
        int i;
        for(i = 0; i <= last; i++){
            if(n < arr1[i]){
                return i;
            }
        }
        return last + 1;
    }

    void inSort(int n){
        int i;
        int pos;
        if(!isDuplicate(n)){
            pos = locate(n);
            for(i = last; i >= pos; i--){
                arr1[i + 1] = arr1[i];
            }
            arr1[pos] = n;
            last++;
        }
    }

    void display(){
        int i;

        cout << "Array: ";
        for(i = 0; i <= last; i++){
            cout << setw(5) << arr1[i];
        }
    }
};

int main(){
    srand(time(0));
    Array one;

    int i;
    int rNum;

    for(i = 0; i <= one.getLast(); i++){
        rNum = (rand() % 10 + 1);
        cout << "Insert: ";
        cout << rNum << endl;
        one.inSort(rNum);
    }
    cout << endl;
    one.display();
}
