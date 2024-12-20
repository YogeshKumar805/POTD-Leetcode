class Solution {
    public TreeNode reverseOddLevels(TreeNode root) {
        boolean f = false;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int s = q.size();
            TreeNode t[] = new TreeNode[s];
            for (int i = 0; i < s; i++) {
                TreeNode temp = q.remove();
                t[i] = temp;
                if (temp.left != null) {
                    q.add(temp.left);
                    q.add(temp.right);
                }
            }
            if (f) {
                for (int i = 0, j = t.length - 1; i < j; i++, j--) {
                    int temp = t[i].val;
                    t[i].val = t[j].val;
                    t[j].val = temp;
                }
            }
            f = !f;
        }
        return root;
    }
}
