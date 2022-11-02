class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> day(len,0);
        stack<int>st{};
        
        /*using classic stack using to compaire the new temp. with old temp., if the old temp. is less than new one,
        opearte the value with new date and pop it out.*/
        
        for(int i=0;i<len;i++){
                while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                    int num = st.top();
                    day[num] = i-num;
                    st.pop();
                }
            st.push(i);
        }
        return day;
    }
};