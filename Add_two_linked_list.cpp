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
class Solution
{
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev(NULL), *curr(head), *next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(ListNode *&head, int data)
    {
        ListNode *n = new ListNode(data);
        if (head == NULL)
        {
            head = n;
            return;
        }
        ListNode *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;        
    }

    ListNode *Add(ListNode *h1, ListNode *h2)
    {
        int carry(0);
        ListNode *ans = NULL;

        while (carry != 0 or h1 != NULL or h2 != NULL)
        {
            int val1 = 0, val2 = 0, sum = 0, digit = 0;;
            if (h1)
                val1 = h1->val;
            if (h2)
                val2 = h2->val;

            sum = val1 + val2 + carry;
            digit = sum % 10;
            carry = sum / 10;
            
            insertAtTail(ans, digit);
            if (h1)
                h1 = h1->next;
            if (h2)
                h2 = h2->next;
        }
        return ans;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    { 
        ListNode *ans = Add(l1, l2);
        return(ans);
    }
};
