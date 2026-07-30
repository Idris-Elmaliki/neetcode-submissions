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
        if(head == nullptr || head->next == nullptr)
            return;

        int length = 0; 

        ListNode* temp = head; 
        while(temp) {
            ++length; 
            temp = temp->next; 
        }

        ListNode* current = head; 

        for(int i = 0; current->next != nullptr; i++) {
            if(i % 2 == 0) {
                ListNode* prev = current; 

                while(prev->next->next) {
                    prev = prev->next;  
                }
                ListNode* t = prev->next; 

                prev->next = t->next; 
                t->next = current->next; 
                current->next = t;
            }

            current = current->next; 
        } 
    }
};
