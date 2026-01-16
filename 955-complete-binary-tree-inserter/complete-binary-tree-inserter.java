/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class CBTInserter {

        private TreeNode root;
    private Queue<TreeNode> q = new LinkedList<>();
    
    public CBTInserter(TreeNode root) {
        this.root = root;
        q.offer(root);
        while (q.peek().right != null) {
            TreeNode n = q.poll();
            q.offer(n.left);    
            q.offer(n.right);
        } 
    }
    
    public int insert(int v) {
        TreeNode p = q.peek();
        if (p.left == null) { 
            p.left = new TreeNode(v); 
        }else { 
            p.right = new TreeNode(v); 
            q.offer(p.left);
            q.offer(p.right);
            q.poll();
        }
        return p.val;
    }
		
    public TreeNode get_root() { return root; }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(val);
 * TreeNode param_2 = obj.get_root();
 */