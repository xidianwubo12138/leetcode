# include<iostream>
using namespace std;

class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void traverse(TreeNode * root) {
    traverse(root->left);
    traverse(root->right);
}

int main() {
    cout << "122" << endl;
    return 0;
}