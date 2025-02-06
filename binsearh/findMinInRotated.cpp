class Solution {
public:
    int f(int low, int high, vector<int> nums, int &ans) {
        while(low<high) {
            int mid = (low+high)/2;
            if(nums[high] < nums[mid]) {
                low=mid+1;
            }
            else {
                high=mid;
            }
        }
        return nums[low];
    }
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        return f(0, n-1, nums, ans);
    }
};