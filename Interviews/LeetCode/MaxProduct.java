public class Solution {
    public int maxProduct(int[] A) {
    	int len = A.length;
    	
    	if(len == 0) return 0;
    	if(len == 1) return A[0];
    	
    	int ans = A[0];
    	int [] pdpos = new int[len];
    	int [] pdneg = new int[len];
    	
    	pdpos[0] = (A[0] > 0) ? A[0] : 0;
    	pdneg[0] = (A[0] > 0) ? 0 : A[0];
    	for(int i = 1; i < len; ++i)
    	{
    	    if(A[i] > 0) {
    	        pdpos[i] = Math.max(A[i], pdpos[i-1]*A[i]);
    	        pdneg[i] = Math.min(pdneg[i-1]*A[i], 0);
    	    }
    	    else {
    	        pdpos[i] = Math.max(pdneg[i-1]*A[i], 0);
    	        pdneg[i] = Math.min(pdpos[i-1]*A[i], A[i]);
    	    }
    	    if(pdpos[i] > ans) ans = pdpos[i];
    	}
    	return ans;
    }
}
