class Solution {
public:
    bool checkPalin(int st, int ed, string s) {
        while(st <= ed) {
            if(s[st++]!=s[ed--]) {
                return false;
            }
        }
        return true;
    }
    void findPalindromes(string s, int ind, vector<string> v, vector<vector<string>> &ans) {
        if(ind == s.size()) {
            ans.push_back(v);
        }
        for(int i=ind; i<s.size(); i++) {
            if(checkPalin(ind, i, s)) {
                v.push_back(s.substr(ind, i-ind+1));
                findPalindromes(s,i+1,v,ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        findPalindromes(s, 0, v, ans);
        return ans;
    }
};