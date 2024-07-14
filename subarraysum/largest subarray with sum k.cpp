// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        map<int, int> mp;
        int k=0;
        int sum=0;
        int ans = 0;
        for(int i=0; i<n; i++) {
            sum+=a[i];
            int rem = sum-k;
            if(sum==k) {
                ans = max(ans, i+1);
            }
            if(mp.find(rem)!=mp.end()) {
                ans = max(ans, i-mp[rem]);
            }
            if(mp.find(sum)==mp.end())    
                mp[sum]=i;
        }
        return ans;
        // Your code here
    }
};