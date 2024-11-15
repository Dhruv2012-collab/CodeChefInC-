/*
struct Node {
    int val; 
    Node *left;
    Node *right;

    Node(int node_value) {
        val = node_value;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    void preOrderTraversal(Node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->val << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
};
