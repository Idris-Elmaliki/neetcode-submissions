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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;

        ListNode* dummy = new ListNode(); 
        dummy->next = head; 

        ListNode* prev = dummy; 
        ListNode* current = prev->next; 

        while(current && current->next) {
            ListNode* temp = current->next;
 
            current->next = temp->next; 
            temp->next = prev->next; 
            prev->next = temp;  
        }

        head = dummy->next; 

        dummy->next = nullptr;
        delete dummy;

        return head;
    }
};
