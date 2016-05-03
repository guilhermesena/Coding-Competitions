public class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
		List<String> ans = new ArrayList<String>();
		if(root == null) return ans;
		if(root.left == null && root.right == null) {
			ans.add(root.val+"");
			return ans;
		}   

		if(root.left != null) {
			List<String> ls = binaryTreePaths(root.left);
			for(String s : ls) {
				ans.add(root.val+"->"+s);
			}
		}
		if(root.right != null) {
			List<String> rs = binaryTreePaths(root.right);
			for(String s : rs) {
				ans.add(root.val+"->"+s);
			}
		}
		return ans;
    }

}
