//
//  Trees.cpp
//  Problems
//
//  Created by Syed Naqvi on 3/19/23.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "Trees.hpp"


using namespace std;

bool Tree::isSameTrees(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    
    if (p == nullptr || q == nullptr) {
        return false;
    }
    
    return (p->val == q->val) && isSameTrees(p->left, q->left) && isSameTrees(p->right, q->right);
}

bool Tree::isSameTreesUsingStack(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    
    if (p == nullptr || q == nullptr) {
        return false;
    }
    
    std::stack<TreeNode*> s1, s2;
    s1.push(p);
    s2.push(q);
    while(!s1.empty() && !s2.empty()) {
        TreeNode* curr1 = s1.top();
        TreeNode* curr2 = s2.top();
        s1.pop();
        s2.pop();
        
        // If the left child of one tree exists and the left
        // child of the other tree does not exist, then
        // trees are not identical
        if ((curr1 != nullptr && curr2 == nullptr) || (curr1 == nullptr && curr2 != nullptr))
            return false;
 
//        // If the right child of one tree exists and the
//        // right child of the other tree does not exist,
//        // then trees are not identical
        if (curr1 == nullptr && curr2 == nullptr)
            return true;
        
        if (curr1->val != curr2->val) {
            return false;
        }
        
        if(curr1) {
            s1.push(curr1->left);
            s1.push(curr1->right);
        }
        
        if(curr2) {
            s2.push(curr2->left);
            s2.push(curr2->right);
        }
    }
    
    return true;
}

bool Tree::isSameTreesUsingQueue(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr) {
        return true;
    }
    
    if (p == nullptr || q == nullptr) {
        return false;
    }
    
    std::queue<TreeNode*> q1, q2;
    
    q1.push(p);
    q2.push(q);
    
    while(!q1.empty() && !q2.empty()) {
        TreeNode* curr1 = q1.front();
        TreeNode* curr2 = q2.front();
        
        q1.pop();
        q2.pop();
        
        if(curr1->val != curr2->val) {
            return false;
        }
        
        // If the left child of one tree exists and the left
        // child of the other tree does not exist, then
        // trees are not identical
        if ((curr1->left != nullptr && curr2->left == nullptr) || (curr1->left == nullptr && curr2->left != nullptr))
            return false;
 
        // If the right child of one tree exists and the
        // right child of the other tree does not exist,
        // then trees are not identical
        if ( (curr1->right != nullptr && curr2->right == nullptr) || (curr1->right == nullptr && curr2->right != nullptr) )
            return false;
        
        if(curr1->left) {
            q1.push(curr1->left);
        }
        if(curr2->left) {
            q2.push(curr2->left);
        }
        
        if(curr1->right) {
            q1.push(curr1->right);
        }
        if(curr2->right) {
            q2.push(curr2->right);
        }
        
    }
    return true;
}

TreeNode* buildTree()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(100);
    root->right = new TreeNode(200);
    root->left->left = new TreeNode(150);
    root->left->right = new TreeNode(180);
    root->right->left = new TreeNode(160);
    root->right->right = new TreeNode(180);
    return root;
}

TreeNode* buildTree2()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(100);
    root->right = new TreeNode(200);
    root->left->left = new TreeNode(150);
    root->left->right = new TreeNode(180);
    root->right->left = new TreeNode(160);
    root->right->right = new TreeNode(180);
    return root;
}

void callTreeFucntions(){
    TreeNode* root1 = buildTree();
    TreeNode* root2 = buildTree2();
    
    Tree tree;
    cout << "isSame: " << tree.isSameTrees(root1, root2) << endl;
    cout << "isSameTreesUsingQueue: " << tree.isSameTreesUsingQueue(root1, root2) << endl;
    cout << "isSameTreesUsingStacks: " << tree.isSameTreesUsingStack(root1, root2) << endl;
}

int main(){
    callTreeFucntions();
    return 0;
}
