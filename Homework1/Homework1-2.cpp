#include <iostream>
#include <cstring>
using namespace std;

int find_max(int *numlen, int x) {
    int max = 0;
    for(int i=0;i<x;i++) numlen[i] > max ? max = numlen[i] : 1;
    return max;
}

int main() {
    int x, y;
    cout << "Please enter the quantity of the string and the length limit for these strings: ";
    cin >> x >> y; // get the number of strings and their lentgh limit
    char **ptr = new char*[x]; //allocate the first dimension of the array
    for(int arr=0;arr<x;arr++) {
        ptr[arr] = new char[y]; //allocate the second dimension of the array
    }
    
    //reset value of the ptr[0] and ignore the '\n' from the last input
    memset(ptr[0], 0, sizeof ptr[0]); 
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
    //count the len of string before space
    int namelen[x];
    for(int i=0; i<x;i++) {
        for(int j =0;j<y;j++) {
            if(ptr[i][j]==' ') {
                namelen[i] = j;
                break;
            }
        }
    }
    //cout the needed added space in each string 
    int max = find_max(namelen, x);
    int add_space_num[x]={0};
    for(int i=0;i<x;i++)
        add_space_num[i] = max - namelen[i];
    //print the result after sorting out
    cout << "--------Output--------" << endl;
    for(int i=0;i<x;i++) {
        for(int k=0;k<add_space_num[i];k++) cout << " ";
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
