/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *head = NULL;
    if(A->val < B->val)
    {
        head = A;
        A = A->next;
    }
    else
    {
        head = B;
        B = B->next;
    }
    ListNode *k = head;
    while(A && B)
    {
        if(A->val < B->val)
        {
            k->next = A;
            A = A->next;
        }
        else
        {
            k->next = B;
            B = B->next;
        }
        k = k->next;
        
    }
    while(A)
    {
        k->next = A;
        A = A->next;
        k = k->next;
    }
    while(B)
    {
        k->next = B;
        B = B->next;
        k = k->next;
    }
    return head;
}
