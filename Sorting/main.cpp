void QuickSort(vector<int>& v,int left,int right) {
    if(left<right) {
        int i=left,j=right,pivot=v[left];
        do{
            do i++; while(pivot<v[i]);
            do j--; while(pivot>v[j]);
            if(i<j){
                int tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }while(i<j);
        int tmp = v[left];
        v[left] = v[j];
        v[j] = tmp;
        QuickSort(v,left,j-1);
        QuickSort(v,j+1,right);
    }

}
