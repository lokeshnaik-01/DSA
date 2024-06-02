class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(), 0);
        vector<int> nextHighest(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int ind=st.top();
                st.pop();
                res[ind]=i-ind;
                nextHighest[ind]=i;
            }
            st.push(i);
        }
       
        for(auto i: nextHighest) {
            cout << i << " ";
        }
        return res;
    }
};