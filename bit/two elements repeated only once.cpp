// https://www.geeksforgeeks.org/find-two-non-repeating-elements-in-an-array-of-repeating-elements/

#include<bits/stdc++.h>
using namespace std;
vector<int> findTwoNonRepeating(vector<int> a) {
    int n = a.size();
    int xr=0;
    for(int x :a) {
        xr=xr^x;
    }
    // here xr will be xor of the two non repeating elements
    // we'll find right most set bit
    // if we conisder array 1,1,3,4 then xr=7
    // xr&~(xr-1) ==> 7&~6 ==> 7&1 ==> 1
    int rightMostSetBit = xr & ~(xr-1);
    int x=0;
    int y=0;
    for(int i=0; i<n; i++) {
        if(a[i]&rightMostSetBit) {
            // we basically are dividing array into two elements where we do xor for elements repeated twice will be 0
            x=x^a[i];
        }
        else {
            y=y^a[i];
        }
    }
    return {x,y};
}
int main() {
    vector<int> v = findTwoNonRepeating({1,1,3,4,4,10});

}