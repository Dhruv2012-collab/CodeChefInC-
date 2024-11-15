class Solution {
  public:
    void postOrderTraversal(Node* root) {
        if (root == NULL) {
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->val << " ";
    }
};
