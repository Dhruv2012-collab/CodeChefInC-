class Solution {
  public:
    int maxNodeInBST(Node* root) {
        while (root != NULL && root->right != NULL) {
            root = root->right;
        }
        return root->val;
    }
};
