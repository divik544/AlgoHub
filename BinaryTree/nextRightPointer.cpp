// Populate next right pointers in the tree in O(1) space(No recursion No level order using queue)
// Level order without queue
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode *first = A,*cur = NULL,*prev = NULL;
    while(first)
    {
        cur = first;
        prev = NULL;
        while(cur)
        {
            if(prev == NULL)
            {
                if(cur->left)
                prev = cur->left;
                else if(cur->right)
                prev = cur->right;
                first = prev;
            }
            if(cur->left && prev != cur->left)
            {
                prev->next = cur->left;
                prev = prev->next;
            }
            if(cur->right && prev != cur->right)
            {
                prev->next = cur->right;
                prev = prev->next;
            }
            cur = cur->next;
        }
        if(prev != NULL)
        prev->next = NULL;
    }
}
