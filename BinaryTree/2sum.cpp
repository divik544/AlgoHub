/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    if(A == NULL)
    return 0;
    stack<TreeNode*> stk,enstk;
    TreeNode* start = A,*end = A;
    bool flag = 1;
    int turn1=1,turn2 = 1;
    while(start != end || flag)
    {
        flag = 0;
        while(start && turn1)
        {
            stk.push(start);
            start = start->left;
        }
        
        while(end && turn2)
        {
            enstk.push(end);
            end = end->right;
        }
        if(turn1)
        {
            if(stk.empty())
            return 0;
            start = stk.top();  
            stk.pop();
        }
        if(turn2)
        {
            if(enstk.empty())
            return 0;
            end = enstk.top();
            enstk.pop();
        }
        if(start->val+end->val == B)
        return (start != end);
        else if(start->val+end->val > B)
        {
            end = end->left;
            turn2 = 1;
            turn1 = 0;
        }
        
        else
        {
            start = start->right;
            turn1 = 1;
            turn2 = 0;
        }
    }
    return 0;
}
