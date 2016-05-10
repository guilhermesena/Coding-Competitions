/**

 * Definition for a binary tree node.

 * public class TreeNode {

 *     int val;

 *     TreeNode left;

 *     TreeNode right;

 *     TreeNode(int x) { val = x; }

 * }

 */

 

 class Pair {

     TreeNode t;

     Boolean v;

     Pair(TreeNode t, Boolean v) {

         this.t = t;

         this.v = v;

     }

     

     public boolean equals(Object obj) {

         Pair p = (Pair) obj;

         return (t == p.t && v == p.v);

     }

     

     public int hashCode() {

         int hash = 3;

         hash = 53*hash + t.hashCode();

         hash = 53*hash + v.hashCode();

         return hash;

     }

 }

 

public class Solution {

    int robRec(TreeNode root, boolean include, HashMap <Pair, Integer> marked) {

        if (root == null) return 0;

        if(marked.containsKey(new Pair(root, include))) return marked.get(new Pair(root, include));

        

        int v = 0;

        if(include) 

            v = root.val;

            

        int ans = Math.max (v + robRec(root.left, false, marked) + robRec(root.right, false, marked), robRec(root.left, true, marked) + robRec(root.right, true, marked));

        marked.put(new Pair(root, include), ans);

        

        return ans;

        

    }

    

    public int rob(TreeNode root) {

        HashMap<Pair, Integer> marked = new HashMap<Pair, Integer>();

        return Math.max(robRec(root, false, marked), robRec(root, true, marked));    

    }

}
