class Solution {
    int root(int[] id, int v) {
        int i = v;
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
    boolean find (int[] id, int u, int v) {
        return root(id, u) == root(id, v);
    }
    
    void union(int[] id, int[] sz, int u, int v) {
        int ru = root(id, u);
        int rv = root(id, v);
        
        if(sz[ru] > sz[rv]) {
            id[rv] = ru;
            sz[ru] = sz[ru] + sz[rv];
        } else {
            id[ru] = rv;
            sz[rv] = sz[ru] + sz[rv];
        }
    }
    
    public int longestConsecutive(int[] nums) {
        int len = nums.length;
        if(len <= 1) 
            return len;
        
        int ans = 1;
        int [] sz = new int[len];
        int [] id = new int[len];
        boolean [] valid = new boolean [len];
        HashMap<Integer,Integer> ntoind = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < len; i++) {
            sz[i] = 1;
            id[i] = i;
            
            if(!ntoind.containsKey(nums[i])) {
                ntoind.put(nums[i],i);
                valid[i] = true;
            }
            else valid[i] = false;
        }
        for(int i = 0; i < len; i++) {
            if(!valid[i]) continue;
            
            if(ntoind.containsKey(nums[i] - 1)) {
                int ind = ntoind.get(nums[i]-1);
                if(!find(id, i, ind))
                    union(id, sz, i,ind);
            }
            if(ntoind.containsKey(nums[i]+1)) {
                int ind = ntoind.get(nums[i]+1);
                if(!find(id,i,ind))
                    union(id,sz,i,ind);
            }
        }
        
        for(int i = 0; i < len; i++)
            if(sz[i] > ans) ans = sz[i];
            
        return ans;
        
    }
}
