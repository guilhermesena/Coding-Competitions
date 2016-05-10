public class Solution {

    public boolean isValidSerialization(String preorder) {
        String[] nums = preorder.split(",");
        int len = nums.length;
        
        if(len == 1 && nums[0].charAt(0) == '#') return true;
  
        int [] next = new int[len];
        int [] nchild = new int[len];
        int last = -1;
        for(int i = 0; i < len; i++) {
             if(nums[i].charAt(0) != '#') {
                  int v = Integer.parseInt(nums[i]);
                  if(last != -1) {
                        if(nchild[last] == 2) return false;
                        nchild[last]++;
                        next[++last] = v;
                        nchild[last] = 0;
                  } else {
                        next[++last] = v;
                        nchild[last] = 0;
                 }
             }
             else {
                  if(last == -1 || nchild[last] == 2) return false;
                  nchild[last]++;
                  if(nchild[last] == 2) {
                      while(last >= 0 && nchild[last] == 2) {
                          nchild[last] = 0;
                          next[last] = 0;
                          last--;
                      }
                  }
             }
        }

        return (last == -1);
    }

}
