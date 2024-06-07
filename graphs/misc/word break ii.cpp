// https://leetcode.com/problems/word-break-ii/
class Solution {
public:
    string conString(vector<string> a) {
        string temp="";
        for(auto x: a) {
            temp+=x+' ';
        }
        temp.pop_back();
        return temp;
    }
    void dfs(int ind, string s, vector<string> &temp, vector<string> &ans, unordered_set<string> st) {
        if(ind==s.length()) {
            string final = conString(temp);
            ans.push_back(final);
            return;
        }
        string t="";
        for(int i=ind; i<s.length(); i++) {
            t=t+s[i];
            if(st.find(t)!=st.end()) {
                // if string t present in set then do dfs on next index 
                temp.push_back(t);
                dfs(i+1, s, temp, ans, st);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto word: wordDict) {
            st.insert(word);
        }
        vector<string> ans;
        vector<string> temp;
        dfs(0, s, temp, ans, st);
        return ans;
    }
};