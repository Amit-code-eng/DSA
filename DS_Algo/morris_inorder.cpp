#include <bits/stdc++.h>
using namespace std;



class TreeNode{

    public:
    int val;
    TreeNode* left,*right;

    TreeNode (){

        // you can use this.left or not doesn't matter
        left=NULL;
        right=NULL;
        val=-1;

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

                v.push_back(root->val);// if we remove this and 
                root = root->right;
                pre->right = NULL;
            }
        }
    }

    return v;
}

int main()
{

    return 0;
}