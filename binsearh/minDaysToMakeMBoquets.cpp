class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());

        int ans = -1;

        while(low<=high) {
            int mid = (low+high)/2;
            int boqueCount = 0;
            int consecutiveCount=0;
            for(int i=0; i<arr.size(); i++) {
                if(arr[i]<=mid) {
                    consecutiveCount++;
                    if(consecutiveCount==k) {
                        boqueCount++;
                        consecutiveCount=0;
                    }
                }
                else {
                    consecutiveCount=0;
                }
            }
            if(boqueCount>=m) {
                ans=mid;
                high=mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};