class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int low=0;
        int high = a.size()-1;
        /*
        In the below valley and slops if we have a point * we can say that if(a[mid+1] < a[mid])
        the peak will be present on the left side of the similary if we have a point and a[mid] < a[mid+1]
        the peak will be on right side so move low = mid+1
        \                      /\
         \      /\            /  \
          \-*  /  \  /\      /    \
           \  /    \/  \  *-/
            \/          \  /
                         \/
        */
        while(low<high) {
            int mid = (low+high)/2;
            if(a[mid] > a[mid+1]) {
                high=mid;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
};