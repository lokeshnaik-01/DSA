class Solution {
public:
    void dfs(string word, vector<string> &seq, string beginWord, vector<vector<string>> &ans, unordered_map<string, int> mp) {
        if(word==begin(word)) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        for(int i=0; i<word.size(); i++) {
            char org = word[i];
            for(char ch='a'; ch<='z'; ch++) {
                word[i]=ch;
                if(mp.find(word)!=mp.end()&&mp[word]+1==steps) {
                    seq.push_back(word);
                    dfs(word, seq, beginWord, ans, mp);
                    seq.pop_back();
                }
            }
            word[i]=org;
        }
    }
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        // we back trace instead of finding sequence from first we find it from last
        // if we do from back then the number of paths to traverse will be less
        queue<string> q;
        unordered_map<string, int> mp;
        unordered_set<string> st(wordList.begin(), wordList.end());
        q.push(beginWord);
        mp[beginWord]=1;
        st.erase(beginWord);
        while(!q.empty()) {
            string word = q.front();
            int steps = mp[word];
            q.pop();
            if(word==endWord) {
                break;
            }
            for(int i=0; i<word.size(); i++) {
                char org = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i]=ch;
                    if(st.find(word)!=st.end()) {
                        q.push(word);
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                }
                word[i]=org;
            }
        }
        vector<vector<string>> ans;
        if(mp.find(endWord)!=mp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq, beginWord, ans, mp);
        }
        return ans;
    }
};