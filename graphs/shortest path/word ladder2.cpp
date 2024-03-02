class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel{beginWord};
        int level=0;
        vector<vector<string>> ans;
        while(!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            // erase all words that has been used in prev level to transform
            if(vec.size()>level) {
                level++;
                for(auto it:usedOnLevel) {
                    st.erase(it);
                }
            }
            string word = vec.back();
            if(word==endWord) {
                if(ans.size()==0) {
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()) {
                    ans.push_back(vec);
                }
            }

            for(int i=0; i<word.size(); i++) {
                char org = word[i];
                for(char c='a'; c<='z'; c++) {
                    word[i]=c;
                    if(st.find(word)!=st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                    word[i]=org;
                }
            }
        }
        return ans;
    }
};