#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
//#include <vector> 
using namespace std;

void radm(int*arr, int n){
    srand(time(NULL));
    for(int j=0;j<n;j++){
	unsigned tmp = rand()+rand();
        arr[j] = tmp%50000+1;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {

    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void checkf(int* a,int size) {
    //check if ordered increasing or not O(n)
    for(int i=0;i<size;i++) {
        if(a[i]>a[i+1]) {
            cout<<"ERROR!"<<endl;
            return;
 }
    }
    cout << "Richtig"<<endl;
}

int main(){
    int n;
    long double start,end;
    cout << "Please input n:"<<endl;
    cin >> n;
    int arr[n];

    cout << "Enter 1 for insertion sort\nEnter 2 for quick sort\nEnter 3 for merge sort\n";
    int k;
    cin >> k;

    radm(arr,n);
    srand(time(NULL));
    start = clock();
    if(k==1){
        insertionSort(arr,n);
        cout <<"insertion";
    }else if(k==2){
        quickSort(arr,0,n-1);
        cout << "quick";
    }else if(k==3){
        mergeSort(arr,0,n-1);
        cout << "merge";
    }
    else
        cout<<"input error";
    end = clock();
    printArray(arr,n);
    checkf(arr,n-1);
    cout <<"Time waste :"<<(end-start)/CLOCKS_PER_SEC<<"sec"<<endl;
    return 0;
}

