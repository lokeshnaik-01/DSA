class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int sign=1;
        int i=0;

        while(i<s.length() && s[i]==' ') {
            i++;
        }

        if(s[i]=='-') {
            sign=-1;
            i++;
        }
        else if(s[i]=='+') {
            i++;
        }

        int maxLimit = INT_MAX/10;
        // maxLimit =  2147483647/10 ----> 2^31-1 ----> 214748346
        while(i<s.length() && (s[i]>='0'&&s[i]<='9')) {
            int digit = s[i]-'0';
            if( ans > maxLimit || ( ans==maxLimit && digit>7 )) {
                return sign==-1 ? INT_MIN : INT_MAX;
            }
            ans = (ans*10)+digit;
            i++;
        }
        return ans*sign;
    }
};