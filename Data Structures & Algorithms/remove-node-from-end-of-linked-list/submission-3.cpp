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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) {
            return nullptr; 
        }

        ListNode* temp = head; 

        int length = 0; 
        while(temp) {
            temp = temp->next; 
            ++length; 
        }

        int nodeIndex = length - n;
        length = 0; 

        if(nodeIndex < 0) {
            return nullptr; 
        }

        ListNode* dummy = new ListNode(); 
        dummy->next = head; 

        ListNode *prev = dummy, *current = dummy->next; 

        while(nodeIndex != length) {
            prev = prev->next; 
            current = current->next; 
            ++length; 
        }        

        temp = current->next; 
        prev->next = temp; 
        current->next = nullptr; 
        delete current; 

        head = dummy->next; 
        dummy->next = nullptr; 

        delete dummy;


        return head; 
    }
};
