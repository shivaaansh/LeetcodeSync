class Solution {
    int dp[35][2][2];

    int recursive( int idx,int tight, int last, string &s){
        if( idx >= s.length()) return 1;
        if( dp[idx][tight][last] != -1) return dp[idx][tight][last];

        int ans=0;
        int till=1;

        if( tight == 1) till=s[idx]-'0';
        if(last == 1) till=0;
        for(int i=0; i<=till; i++){
            ans+= recursive(idx+1, tight && (i==(s[idx]-'0')), i, s);
        }
        return dp[idx][tight][last]= ans;
    }

public:
    int findIntegers(int n) {
        memset(dp, -1, sizeof(dp));
        string s="";
        while( n ){
            char rem=(n % 2)+'0';
            s+=rem;
            n/=2;
        }
        reverse(s.begin(), s.end());
        return recursive( 0, 1, 0, s);
    }
};