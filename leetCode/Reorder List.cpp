// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:

// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:

// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return ;
        }
        ListNode* slow = new ListNode();
        ListNode* fast = new ListNode();
        slow = head;
        fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = new ListNode();
        ListNode* curr = new ListNode();
        ListNode* Next = new ListNode();


        curr = slow->next;
        //cout<<"it is"<<slow->val<<endl;
        slow->next = NULL;
        Next = NULL;
        prev = NULL;

        while (curr != NULL) {
            //cout<<"ppr";
            Next = curr->next;
            curr->next = prev;
            // cout<<curr->val<<" ";
            prev = curr;
            curr = Next;
        }

        // i have revesred the linked list above
        // now  we will merge both


        ListNode* temp = prev;
        ListNode* itr = head;
        ListNode* nxt = prev;
        while (temp != NULL) {
            nxt = temp->next;
            temp->next = itr->next;
            itr->next = temp;
            if (itr->next != NULL) {
                itr = itr->next->next;
            }
            temp = nxt;
        }
        return;
    }
};