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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(); 
        ListNode* current = dummy; 

        ListNode *temp1 = list1, *temp2 = list2; 
        while(temp1 && temp2) {
            if(temp1->val <= temp2->val) {
                current->next = temp1; 
                current = current->next; 

                temp1 = temp1->next; 
            }
            else {
                current->next = temp2; 
                current = current->next; 

                temp2 = temp2->next; 
            }
        }

        if(temp1 == nullptr) {
            while(temp2) {
                current->next = temp2; 
                current = current->next; 

                temp2 = temp2->next; 
            }
        }
        else {
            while(temp1) {
                current->next = temp1; 
                current = current->next; 

                temp1 = temp1->next; 
            }
        }

        current = dummy->next; 

        dummy->next = nullptr;
        delete dummy; 

        return current; 
    }
};
