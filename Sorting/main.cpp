#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void PrintVector(vector<int>v, int size_v) {
    for(int i=0;i<size_v;i++)
        (i+1)%10==0 ? cout<<v[i]<<endl:cout<<v[i]<<"\t";
}

void InsertionSort(vector<int>& v, int size_v) {
    for(int i=1;i<size_v;i++){
        int key = v[i], j=i-1;
        while(j>=0 && v[j]>key) {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }
}

void QuickSort(vector<int>& v,int left,int right) {
    if(left<right) {
        int i=left,j=right+1,pivot=v[left];
        do{
            do i++; while(pivot>v[i]);
            do j--; while(pivot<v[j]);
            if(i<j){
                swap(v[i],v[j]);
            }
        }while(i<j);
        swap(v[left],v[j]);
        QuickSort(v,left,j-1);
        QuickSort(v,j+1,right);
    }
}
void merge(vector<int>& nums,int l, int r, int m){
    int n=nums.size();
    vector<int> ans(r-l+1);
    int i=l,j=m+1,k=0;
    while(i<=m && j<=r){
        if(nums[i]<=nums[j]){
            ans[k++]=nums[i++];
        }
        else{
            ans[k++]=nums[j++];
        }
    }
    while(i<=m){
        ans[k++]=nums[i++];
    }
    while(j<=r){
        ans[k++]=nums[j++];
    }
    for(int i=0;i<=r-l;i++){
        nums[l+i]=ans[i];
    }
}
void mergesort(vector<int>& nums,int l,int r){
    if(l>=r){
        return ;
    }
   int m=l+(r-l)/2;
    mergesort(nums,l,m);
    mergesort(nums,m+1,r);
    merge(nums,l,r,m);
}
vector<int> sortArray(vector<int>& nums) {
    int n=nums.size();
    mergesort(nums,0,n-1);
    return nums;
}

void CheckVector(vector<int> v,int size_v) {
    for(int i=0;i<size_v-1;i++) {
        if(v[i]>v[i+1]) {
            cout<<"ERROR!";
            return;
        }
    }
    cout << "Richtig";
}

int main() {
    srand(time(NULL)); //setting the random seed use current time
    int num=0;
    cout<<"Please Enter the total number you need: ";
    cin>>num;
    vector<int> v;
    for(int i=0;i<num;i++) {
        unsigned x = rand(), y=rand();
        unsigned tmp = ((x+y)%50000)+1; 
        v.push_back(tmp);
    }
    int method = 0;
    cout<<"Please Select the sorting method:(0.InsertionSort 1.QuickSort 2.MergeSort 3.HeapSort)";
    cin>>method;
    while(method>3||method<0) {
        cout<<"Error Method!! Please Enter it again: ";
        cin>>method;
    }
    cout<<"The method you use is method: "<<method << endl;
    if(method==0)
        InsertionSort(v,v.size());
    else if(method==1)
        QuickSort(v,0,v.size()-1);
    else if(method==2)
        sortArray(v);
    /*else if(method==3)
        HeapSort(v,v.size());*/
    PrintVector(v,v.size());
    CheckVector(v,v.size());
    return 0;
}