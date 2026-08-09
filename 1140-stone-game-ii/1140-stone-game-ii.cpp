class Solution {
public:
    int dp[101][101];
    int suffixSum[101];
    int solve(int i , int M , int n){
        if(i>=n) return 0;

        if(i+2*M >=n) return suffixSum[i];

        if(dp[i][M]!=-1) return dp[i][M];

        int maxStones=0;
        for(int X=1;X<=2*M ;X++){
            maxStones = max(maxStones, suffixSum[i] - solve(i + X, max(M, X), n));

        }
        return dp[i][M] = maxStones;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        suffixSum[n-1]= piles[n-1];
        for(int i = n-2 ; i>= 0 ; i--){
            suffixSum[i] = suffixSum[i+1]+piles[i];
        }
        return solve(0,1,n);

    }
};