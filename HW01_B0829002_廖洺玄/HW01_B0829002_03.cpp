#include <iostream>
#include <cstring>
using namespace std;

int find_max(int *numlen, int x) {
    int max = 0;
    for(int i=0;i<x;i++) numlen[i] > max ? max = numlen[i] : 1;
    return max;
}

int main() {
    int x, y=0;
    cout << "Please enter the quantity of strings: ";
    cin >> x; // get the number of strings and their lentgh limit
    cin.ignore(); //ignore the '\n' from the last input
    
    //input the string, meanwhile counting the lentgh of string
	string name[x];
	int stringlen[x];
	for(int i =0;i<x;i++) {
		cout << "Please enter the " << i+1 << " string" << endl;
		getline(cin, name[i]);
		stringlen[i] = name[i].length();
	}
	
	//get the longest string and allocate the memory address
	y = find_max(stringlen, x);
	cout << y << endl;
    char **ptr = new char*[x]; //allocate the first dimension of the array
    for(int arr=0;arr<x;arr++) {
        ptr[arr] = new char[y]; //allocate the second dimension of the array
    }
    memset(ptr[0], 0, sizeof ptr[0]); //reset value of the ptr[0]

    // input the string into the dynamic array
    for(int i=0;i<x;i++)
        for(int j=0; j<name[i].length();j++)
            ptr[i][j] = name[i][j];
            
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
