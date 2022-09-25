#include <iostream>
#include <cstring>
using namespace std;

void bubble_sort(char** a,char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    cout << "Please enter the quantity of the string and the length limit for these strings: ";
    cin >> x >> y; // get the number of strings and their lentgh limit
    char **ptr = (char**)malloc(x*sizeof(char*));
    for(int arr=0;arr<x;arr++) {
        *(ptr+arr) = (char*)malloc(y*sizeof(char));
    }
    //reset value of the ptr[0] and ignore the '\n' from the last input
    memset(ptr[0], 0, sizeof ptr[0]); 
    cin.ignore();
    
    // input the string into the dynamic array
    for(int i=0;i<x;i++) {
        cout << "Please enter the " << i+1 << " string" << endl;
        string name;
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
            if(**(ptr+j)<**(ptr+j+1))
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
    for(int i=0;i<x;i++) free(*(ptr+i));
    free(ptr);
    
    return 0;
}
