#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void PrintVector(vector<int>v, int size_v) {
    for(int i=0;i<size_v;i++) //print out O(n)
        (i+1)%10==0 ? cout<<v[i]<<endl:cout<<v[i]<<"\t";
}

void InsertionSort(vector<int>& v, int size_v) {
    //from v[1] check to v[size_v-1]
    //O(n^2), here is O(n) and inside while loop is O(n), therefore O(n*n)
    for(int i=1;i<size_v;i++){
        int key=v[i], j=i-1;
        while(j>=0 && v[j]>key) //trace the value to from key to left or the value which smaller than you
            v[j--+1]=v[j];
        v[j+1]=key; //insert the vale to the right pos.
    }
}

void QuickSort(vector<int>& v,int left,int right) {
    if(left<right) {
        int i=left,j=right+1,pivot=v[left];
        do {
            do i++; while(pivot>v[i]&&i<=right); //move the i and prevent it to infinitive num
            do j--; while(pivot<v[j]);
            if(i<j) swap(v[i],v[j]);
        }while(i<j);
        swap(v[left],v[j]);
        //recursive to the smaller part O(logn) and multiple the inside do-while loop O(n) is O(nlogn)
        QuickSort(v,left,j-1);
         //recursive to the larger part O(logn) and multiple the inside do-while loop O(n) is O(nlogn)
        QuickSort(v,j+1,right);
    }
}

void MergePass(int left, int mid, int right, vector<int>& v) {
    if (left >= right) return;
    int l=left,
        r=mid+1,
        k=0,
        size=right-left+ 1;
    vector<int> tmpList(size, 0); //inite a same size vector
    //compare the left side and right side O(n)
    while(l<=mid && r<=right) {
        if(v[l]<v[r]) {
            tmpList[k++]=v[l++];
        } else {
            tmpList[k++]=v[r++];
        }
    }
    //the rest of parts copy into tmpList O(n)
    while(l<=mid) 
        tmpList[k++] = v[l++];
    while(r<=right) 
        tmpList[k++] = v[r++];
    //copy the sorted records into original vector O(n)
    for(int k=0;k<size;k++)
        v[k + left] = tmpList[k];
}
void MergeSort(vector<int>& v, int start, int end){
    if(start < end){
        int mid=start+(end-start)/2; // divdie it to 2 part
        //recursive to the left part and when start>=end start sorting O(logn) * inside_MergePass O(n)=O(nlogn)
        MergeSort(v, start, mid);
        //recursive to the left part and when start>=end start sorting O(logn) * inside_MergePass O(n)=O(nlogn)
        MergeSort(v, mid + 1, end);
        MergePass(start, mid, end, v);
    }
}

void Adjust(vector<int>& v, int root, int n) {
    int largest=root,
        left=2*root+1,
        right=2*root+2;
    if(left<n&&v[left]>v[largest])
        largest = left;
    if(right<n&&v[right]>v[largest])
        largest=right;
    if(largest!=root){
        swap(v[root],v[largest]);
        Adjust(v,largest,n);
    }
}
void HeapSort(vector<int>& v, int size_v){
    //construct max heap O(n), according to sigma(0 to k) (2^(i-k))*(k-i)<=sigma(0 to k-1)(k-i)/(2^(k-i))<2n=O(n)
    for(int i=size_v/2 -1;i>=0;i--)
        Adjust(v,i,size_v);
    // sorting from the largest to smallest meanwhile construct max heap
    //O(log(n+1))*(n-1)=O(nlogn)
    for(int i=size_v-1;i>=0;i--) {
        swap(v[0],v[i]);
        Adjust(v,0,i);
    }
}

void CheckVector(vector<int> v,int size_v) {
    //check if ordered increasing or not O(n)
    for(int i=0;i<size_v-1;i++) {
        if(v[i]>v[i+1]) {
            cout<<"ERROR!"<<endl;
            return;
 }
    }
    cout << "Richtig"<<endl;
}

int main() {
    srand(time(NULL)); //setting the random seed use current time
    int num=0, method = 0;
    vector<int> v;
    //input the needed numbers of records
    cout<<"Please Enter the total number you need: ";
    cin>>num;
    //random number part
    for(int i=0;i<num;i++) {
        unsigned x=rand(), y=rand();
        unsigned tmp=((x+y)%50000)+1;
        v.push_back(tmp);
    }
    //input and check the sorting method
    cout<<"Please Select the sorting method:(0.InsertionSort 1.QuickSort 2.MergeSort 3.HeapSort)";
    cin>>method;
    while(method>3||method<0) {
        cout<<"Error Method!! Please Enter it again: ";
        cin>>method;
    }
    cout<<"The method you use is method: "<<method<<endl;

    clock_t begin_time = clock(); //start the timer
    if(method==0)
        InsertionSort(v,v.size());
    else if(method==1)
        QuickSort(v,0,v.size()-1);
    else if(method==2)
        MergeSort(v,0,v.size()-1);
    else if(method==3)
        HeapSort(v,v.size());
    clock_t end_time = clock(); // end the timer
    PrintVector(v,v.size()); //want to print out all records open it.
    CheckVector(v,v.size()); //to Check the Vector is increasing or not
    cout<<"It takes time: " << double(end_time - begin_time)/CLOCKS_PER_SEC << endl;
    return 0;
}

