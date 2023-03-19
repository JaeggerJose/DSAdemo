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
    for(int i=1;i<size_v;i++){ //from v[1] check to v[size_v-1]
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
            do i++; while(pivot>v[i]&&i<=right);
            do j--; while(pivot<v[j]);
            if(i<j) swap(v[i],v[j]);
        }while(i<j);
        swap(v[left],v[j]);
        QuickSort(v,left,j-1);
        QuickSort(v,j+1,right);
    }
}
void MergePass(int low, int mid, int high, vector<int> &nums) {
    if (low >= high) return;
    int l = low, r = mid + 1, k = 0, size = high - low + 1;
    vector<int> sorted(size, 0);
    while (l <= mid and r <= high)
        sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
    while (l <= mid) 
        sorted[k++] = nums[l++];
    while (r <= high) 
        sorted[k++] = nums[r++];
    for (k = 0; k < size; k++)
        nums[k + low] = sorted[k];
}

void MergeSort(vector<int>& nums, int start, int end){
    if(start < end){
        int mid=start+(end-start)/2;
        MergeSort(nums, start, mid);
        MergeSort(nums, mid + 1, end);
        MergePass(start, mid, end, nums);
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
    for(int i=size_v/2 -1;i>=0;i--)
        Adjust(v,i,size_v);
    for(int i=size_v-1;i>=0;i--) {
        swap(v[0],v[i]);
        Adjust(v,0,i);
    }
}

void CheckVector(vector<int> v,int size_v) {
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
    cout<<"Please Enter the total number you need: ";
    cin>>num;
    for(int i=0;i<num;i++) {
        unsigned x=rand(), y=rand();
        unsigned tmp=((x+y)%50000)+1;
        v.push_back(tmp);
    }
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
    //PrintVector(v,v.size());
    CheckVector(v,v.size()); //to Check the Vector is increasing or not
    cout<<"It takes time: " << double(end_time - begin_time)/CLOCKS_PER_SEC << endl;
    return 0;
}

