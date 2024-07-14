// https://leetcode.com/problems/robot-collisions/description/
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[3] < b[3];
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> robots;
        int n = positions.size();

        for(int i=0; i<n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        vector<vector<int>> st;
        for(auto robot: robots) {
            if(robot[2]=='R' || st.empty() || st.back()[2]=='L') {
                st.push_back(robot);
                continue;
            }
            if(robot[2]=='L') {
                bool add=true;
                while(!st.empty() && st.back()[2]=='R' && add) {
                    int prevHealth = st.back()[1];
                    if(robot[1] > prevHealth) {
                        st.pop_back();
                        robot[1]-=1;
                    }
                    else if(robot[1] < prevHealth) {
                        st.back()[1]-=1;
                        add = false;
                    }
                    else {
                        st.pop_back();
                        add = false;
                    }
                }
                if(add) {
                    st.push_back(robot);
                }
            }
        }   

        vector<int> ans;
        sort(st.begin(), st.end(), cmp);
        for(auto robot: st) {
            ans.push_back(robot[1]);
        }
        return ans;
    }
};