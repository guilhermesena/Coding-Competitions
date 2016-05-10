class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len == 0) return 0;
        
        map<char, int> last;
        int *dp = new int [len];
        int ans = 1;
        for(int i = 0; i < len; i++) last[s[i]] = -1;
        dp[0] = 1;
        last[s[0]] = 0;
      
        for(int i = 1; i < len; i++) {
            if(last[s[i]] == -1) dp[i] = dp[i-1] + 1;
            else dp[i] = min(dp[i-1] + 1, i - last[s[i]]);
            
            if(dp[i] > ans) ans = dp[i];
            
            last[s[i]] = i;
        }
        
        return ans;
    }
};
