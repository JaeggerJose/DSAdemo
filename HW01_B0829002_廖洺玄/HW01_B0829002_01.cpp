#include <iostream>
#include <cstring>
using namespace std;

void bubble_sort(char** a,char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}
5
int main() {
    int x, y;
    cout << "Please enter the quantity of the string and the length limit for these strings: ";
    cin >> x >> y; // get the number of strings and their lentgh limit
    char **ptr = new char*[x]; //allocate the first dimension of the array
    for(int arr=0;arr<x;arr++) {
        ptr[arr] = new char[y]; //allocate the second dimension of the array
        memset(ptr[arr], 0, sizeof ptr[arr]); //reset value of the ptr[0] and ignore the '\n' from the last inputsds
    }
	
    cin.ignore();
    
    // input the string into the dynamic array
    for(int i=0;i<x;i++) {
        cout << "Please enter the " << i+1 << " string" << endl;
        string name= "";
        getline(cin, name);
        while(name.length()>y) {
            cout << "Your input is too long, Please input it angain" << endl;
            getline (cin, name);
        }
        for(int j=0; j<name.length();j++) {
            ptr[i][j] = name[j];
        }
    }
    
    //compare and swap the string using bubble sort
    for(int i=0; i<x-1;i++) {
        for(int j =0;j<x-i-1;j++) {
            if(ptr[j][0]<ptr[j+1][0])
    			bubble_sort(ptr+j, ptr+j+1);
        }
    }
    
    //print the result after sorting out
    cout << "--------Output--------" << endl;
    for(int i=0;i<x;i++) {
        cout << "The result of " << i+1 << " string is ";
        for(int j=0;j<y;j++) {
            cout << ptr[i][j];
        }
        cout << endl;
    }
    
    //free the allocated memory out
    for(int i=0;i<x;i++) {delete[] ptr[i];}
    delete[] ptr;
    
    return 0;
}
