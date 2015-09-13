public class Solution {
    public int numSquares(int n) {
        int [] dp = new int [n+1];
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = 2000000000;
            for(int j = 1; i - j*j >= 0; j++) {
                if(dp[i-j*j]+1 < dp[i])
                    dp[i] = dp[i-j*j]+1;
            }
        }
        return dp[n];
    }
}
