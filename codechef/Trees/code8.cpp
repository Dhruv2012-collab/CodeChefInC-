class Solution {
  public:
    void inOrderTraversal(Node* root) {
        if (root == NULL) {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
};
