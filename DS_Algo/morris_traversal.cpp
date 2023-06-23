#include <bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int val;
    TreeNode *left, *right;

    TreeNode()
    {

        // you can use this.left or not doesn't matter
        left = NULL;
        right = NULL;
        val = -1;
    }
};

vector<int> inorderTraversal(TreeNode *root)
{

    vector<int> v;

    while (root)
    {

        if (root->left == NULL)
        {
            v.push_back(root->val);
            root = root->right;
        }
        else
        {

            TreeNode *pre = root->left;
            while (pre->right != NULL && pre->right != root)
            {

                pre = pre->right;
            }

            if (pre->right == NULL)
            {

                pre->right = root;
                /// write here it will give preorder
                root = root->left;
            }
            else
            {

                v.push_back(root->val); // if we remove this and
                root = root->right;
                pre->right = NULL;
            }
        }
    }

    return v;
}

vector<int> preorderTraversal(TreeNode *root)
{

    vector<int> v;
    if (!root)
        return v;
    TreeNode *cur = root;
    while (cur)
    {

        if (!cur->left)
        {

            v.push_back(cur->val);
            cur = cur->right;
        }
        else
        {

            TreeNode *pre = cur->left;
            while (pre->right && pre->right != cur)
            {

                pre = pre->right;
            }

            if (pre->right)
            {

                pre->right = NULL;
                cur = cur->right;
            }
            else
            {

                pre->right = cur;
                v.push_back(cur->val);
                cur = cur->left;
            }
        }
    }

    return v;
}

vector<int> postorderTraversal(TreeNode *root)
{

    vector<int> v;
    if (!root)
        return v;

    TreeNode *cur = root;

    while (cur)
    {

        if (!cur->right)
        {
            v.push_back(cur->val);
            cur = cur->left;
        }
        else
        {

            TreeNode *pre = cur->right;

            while (pre->left && pre->left != cur)
            {

                pre = pre->left;
            }

            if (pre->left)
            {

                pre->left = NULL;
                cur = cur->left;
            }
            else
            {

                pre->left = cur;
                v.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    reverse(v.begin(), v.end());
    return v;
}

int main()
{

    return 0;
}