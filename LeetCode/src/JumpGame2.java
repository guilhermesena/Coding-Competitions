class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        if(len <= 1) return 0;
        
        int maxreach = nums[0], nextmaxreach = 0;
        int ans = 1, cur = 0, next = 0;
        while(cur+nums[cur] < len-1) {
           for(int i = cur+1; i <= cur + nums[cur] && i < len; i++) {
                if(i + nums[i] >= next+nums[next]) {
                    next = i;
                }   
            }
            cur = next;
            ans++;
        }
        
        return ans;
    }
}
