class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(low<=high) {
            int mid = (low+high)/2;
            int count = 1;
            int sum = 0;
            bool cantOperate = false;
            for(int i=0; i<weights.size()-1; i++) {
                sum+=weights[i];
                if(sum+weights[i+1]>mid) {
                    count++;
                    sum=0;
                }
                if(weights[i]>mid) {
                    cantOperate = true;
                    break;
                }
            }
            if(cantOperate==false && count<=days) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};