// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="") {
            return "";
        }
        map<char, int> countT;
        for(char x:t) {
            countT[x]++;
        }
        map<char, int> window;
        int have = 0;
        int need = countT.size();
        int ans=INT_MAX;
        int left=0;
        int start=-1;
        int end=-1;
        for(int i=0; i<s.length(); i++) {
            char curr = s[i];
            window[curr]++;
            if(countT.find(curr)!=countT.end() && countT[curr]==window[curr]) {
                // checking if the character is present is countT
                // if number of characters are also same then we found the character.
                have++;
            }
            while(have==need) {
                // find substring with less length
                if(ans > i-left+1) {
                    start=left;
                    end=i;
                    ans = i-left+1;
                }
                window[s[left]]--;
                if(window[s[left]]==0) {
                    window.erase(s[left]);
                }
                
                // if character is present in countT but the character count has decrease
                // it means we the req characters are less now
                if(countT.find(s[left])!=countT.end() && window[s[left]]<countT[s[left]]) {
                    have--;
                }
                left++;
            }
        }
        if(start==-1 || end==-1) {
            return "";
        }
        cout << start << " " << end << endl;
        return s.substr(start, end-start+1);
    }
};