/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void insertAtTail(ListNode *&head, int data) {
        ListNode *n = new ListNode(data);
        if(head==NULL) {
            head = n;
            return;
        }
        
        ListNode *temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = n;            
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = new ListNode(-1);
        ListNode *h1(list1), *h2(list2);
        
        while(h1 && h2) {
            if(h1->val > h2->val) {
                insertAtTail(ans,h2->val);
                h2 = h2->next;
            } else {
                insertAtTail(ans,h1->val);
                h1 = h1->next;
            }
        }
        while(h1) {
            insertAtTail(ans,h1->val);
            h1 = h1->next;
        }
        while(h2) {
            insertAtTail(ans,h2->val);
            h2 = h2->next;
        }
        return ans->next;
    }
};
