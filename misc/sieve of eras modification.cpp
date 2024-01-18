class Solution {
public:
    vector<int> sieve(int n) {
        vector<int> smallestPrimeFactor(n+1, 1);
        for (int i=2; i<=n;i++) {
            smallestPrimeFactor[i] = i;
        }
        
        for(int p=2; p*p<=n; p++) {
            if(smallestPrimeFactor[p]==p) {
                for(int i=p*p; i<=n; i++) {
                    if(smallestPrimeFactor[i]==i) {
                        smallestPrimeFactor[i] = p;
                    }
                }
            }
        }
        return smallestPrimeFactor;
    }
    int sumPowerOfNumbers(int val, vector<int> smallestPrimeFactor) {
        int c=0;
        while(val>1) {
            int primeFactor = smallestPrimeFactor[val];
            int power =0;
            while(val%primeFactor==0) {
                val=val/primeFactor;
                power++;
            }
            c+=power;
        }
        return c;
    }
	int sumOfPowers(int a, int b){
	    int n = max(b, 2);
	    vector<int> smallestPrimeFactor = sieve(n);
	    int c=0;
	    for(int i=a; i<=b; i++) {
	        c+=sumPowerOfNumbers(i, smallestPrimeFactor);
	    }
	    return c;
	}
};