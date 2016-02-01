public class Solution {
    public static String minWindow(String s, String t) {
    	int [] rem = new int [256];
    	int remaining = t.length();
    	int minAns = s.length() + 1;
    	int ansStart = -1, ansEnd = -1;
    	int start = 0, end = 0; 
    	
    	int lent = t.length();
    	
    	for(int i = 0; i < lent; i++) {
    		rem[t.charAt(i)]++;
    	}
    	
    	int lens = s.length();
    	while(end < lens || start < lens) {
    		if(remaining == 0) {
    			//We'll try to decrease our window as much as we can
    			if(end - start < minAns) {
    				minAns = end - start;
    				ansStart = start;
    				ansEnd = end;
    			}
    			rem[s.charAt(start)]++;
    			if(rem[s.charAt(start)]>0) remaining++;
    			start++;
    			if(end >= lens && remaining > 0) break;
    			
    		}
    		else {
    			if(end >= lens) break;
    			//we'll have to increase our window
    			rem[s.charAt(end)]--;
    			if(rem[s.charAt(end)]>=0)remaining--;
    			end++;
    		}
    	}
        
    	if(minAns == lens + 1) return "";
    	else return s.substring(ansStart, ansEnd);
    	
    }
    
    public static void main(String[] args) {
    	String S = "ABDDDDDDDDDDDDDDDDCBAC";
    	String T = "ABC";
    	
    	System.out.println("ans: "+minWindow(S,T));
    }
}