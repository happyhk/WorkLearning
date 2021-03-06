# 平衡二叉树

## 题目描述

给定一个二叉树，判断它是否是高度平衡的二叉树。<br>

本题中，一棵高度平衡二叉树定义为：<br>

一个二叉树*每个节点* 的左右两个子树的高度差的绝对值不超过1。<br>

## 题解（C++）

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool result = true;
    bool isBalanced(TreeNode* root) {
      maxDepth(root);
      return result;
    }
    int maxDepth(TreeNode* root){
      if(root == nullptr){
        return 0;
      }
      int l = maxDepth(root->left);
      int r = maxDepth(root->right);
      if(abs(l-r) > 1) result = false;
      return max(l,r) + 1;
    }
};
```

## 思路

本质上是一个树的前序遍历，并且用一个数值记录每个分支的深度，取最大深度并且左右分支进行比较，如果大于1的话返回false，否则返回true。<br>
