// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int i=0;
        int n=a.size();
        int buy, ans=0, sell;
        while(i<n-1) {
            while(i<n-1 && a[i+1]<a[i]) {
                i++;
            }
            if(i==n-1) {
                return ans;
            }
            buy = a[i++];
            while(i<n && a[i]>=a[i-1]) {
                i++;
            }
            sell=a[i-1];
            ans+=sell-buy;
        }
        return ans;
    }
};