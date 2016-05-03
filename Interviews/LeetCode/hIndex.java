public class Solution {
	public int hIndex(int[] citations) {
		Arrays.sort(citations);
		int ans = 0;
		int len = citations.length;
		for(int i = 0; i < len; i++) {
			if(ans < Math.min(i+1, citations[len-i-1]))
				ans = Math.min(i+1, citations[len-i-1]);
		}
		return ans;
    }
}
