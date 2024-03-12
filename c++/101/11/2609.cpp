#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 根据先序和中序遍历构建二叉树
TreeNode* buildTree(char* preorder, char* inorder, int preStart, int inStart, int inEnd) {
    if (preStart > strlen(preorder) - 1 || inStart > inEnd) {
        return NULL;
    }

    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = preorder[preStart];

    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }

    root->left = buildTree(preorder, inorder, preStart + 1, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, preStart + inIndex - inStart + 1, inIndex + 1, inEnd);

    return root;
}

// 后序遍历二叉树
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c", root->val);
}

int main() {
    char preorder[1000];
    char inorder[1000];
    int n;
    while(scanf("%d",&n) != EOF) {
        scanf("%s", preorder);
        scanf("%s", inorder);
        TreeNode* root = buildTree(preorder, inorder, 0, 0, strlen(inorder) - 1);
        postorderTraversal(root);
        printf("\n");
    }
    return 0;
}
