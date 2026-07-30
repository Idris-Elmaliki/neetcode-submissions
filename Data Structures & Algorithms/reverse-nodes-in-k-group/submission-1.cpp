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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr )
            return head; 
        
        ListNode* temp = head; 
        int length = 0; 

        while(temp) {
            temp = temp->next; 
            ++length; 
        }

        ListNode* dummy = new ListNode(); 
        dummy->next = head; 
        
        ListNode* current = dummy->next; 
        ListNode* prev = dummy; 

        while(length >= k && current->next) {
            ListNode* temp2 = current->next;

            for(int i = k; i > 1; i--) { 
                current->next = temp2->next; 
                temp2->next = prev->next; 
                prev->next = temp2;

                temp2 = current->next;
            }

            prev = current; 
            current = current->next; 

            length -= k; 
        }

        head = dummy->next; 
        dummy->next = 0; 
        delete dummy; 

        return head; 
    }
};
