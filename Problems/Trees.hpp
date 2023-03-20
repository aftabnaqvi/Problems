//
//  Trees.hpp
//  Problems
//
//  Created by Syed Naqvi on 3/19/23.
//

#ifndef Trees_hpp
#define Trees_hpp

#include <stdio.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree{
public:
    bool isSameTrees(TreeNode* p, TreeNode* q);
    bool isSameTreesUsingStack(TreeNode* p, TreeNode* q);
    bool isSameTreesUsingQueue(TreeNode* p, TreeNode* q);
};

#endif /* Trees_hpp */
