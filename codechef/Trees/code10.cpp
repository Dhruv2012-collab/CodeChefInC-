class Solution {
  public:
    bool searchInBST(Node* root, int x) {
        if (root == NULL) {
            return false;
        }
        if (root->val == x) {
            return true;
        }
        if (x < root->val) {
            return searchInBST(root->left, x);
        }
        return searchInBST(root->right, x);
    }
};
