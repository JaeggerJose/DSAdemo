#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void bubble_sort(char** a,char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y, meth=1;
    cout << "Please enter the quantity of the string and the length limit for these strings: ";
    cin >> x >> y; // get the number of strings and their lentgh limit
    cout << "Now we also need the method used to allocate memory(1.New 2.Malloc):";
    cin >> meth;
    while(meth != 1 && meth != 2) {
        cout << "the method your are given is failed, please enter it again!" << endl;
        cout << "Now we also need the method used to allocate memory(1.New 2.Malloc):";
        cin >> meth;
    }
    //set the default method for allocating memory address
    char **ptr = new char*[x]; //allocate the first dimension of the array
    for(int arr=0;arr<x;arr++)
        ptr[arr] = new char[y]; //allocate the second dimension of the array
    if(meth == 2) {
        for(int i=0;i<x;i++) free(*(ptr+i));
        free(ptr);
        char **ptr = (char**)malloc(sizeof(char*)*x);
        for(int arr=0;arr<x;arr++) {
            *(ptr+arr) = (char*)malloc(sizeof(char)*y);
            memset(ptr[arr], 0, sizeof ptr[arr]); 
        }
    }
    
    //reset value of the ptr[0] and ignore the '\n' from the last input
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
        for(int j =0;j<x-1;j++) {
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
    if(meth == 1) {
        for(int i=0;i<x;i++) {delete[] ptr[i];}
        delete[] ptr;
    } else if (meth == 2){
        for(int i=0;i<x;i++) free(*(ptr+i));
        free(ptr);
    }
    return 0;
}
