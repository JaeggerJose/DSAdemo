class CustomStack {
    vector<int> st; // using vector to store the value array
    int capacity;
public:
    CustomStack(int maxSize) {
        capacity = maxSize; //give a fixed maximun number for stack
    }
    
    void push(int x) {
        if(st.size() == capacity) return; // determine if our stack size is more than its capacity, than we return directly do nothing
        st.push_back(x); //otherwise insert the value into out stack
    }
    
    int pop() {
        if(st.empty()) return -1; //determine if our stack dont have anything, than we need to return directly doing nothing
        int len = st.size(); //get the current location of pop of stack
        int num = st[len-1]; // using a variable to store the value, which will be poped out later and pop the value out
        st.pop_back();
        return num;
    }
    
    void increment(int k, int val) {
        if(st.empty()) return; // check if the stak is empty, than it will do nothing
        k > st.size() ? k = st.size() : 1; // compare the max capacity and k for loop to add value into the stack, which the location is under the compared number 
        for(int i =0; i<k;i++) {
            st[i] += val;
        }
    }
};
