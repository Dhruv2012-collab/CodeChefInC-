class Solution {
  public:
    int heightOfBinaryTree(Node* root) {
        if (root == NULL) {
            return -1; 
        }
        int leftHeight = heightOfBinaryTree(root->left);
        int rightHeight = heightOfBinaryTree(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
};