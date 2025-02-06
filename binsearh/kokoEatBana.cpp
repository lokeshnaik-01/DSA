class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int low = 1;
        int high = maxPile;
        int mid;
        while(low<=high) {
            mid = (low+high)/2;

            long long ans = 0;
            for(int pile: piles) {
                ans += (pile+mid-1)/mid;
            }

            if(ans > h) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return low;
    }
};