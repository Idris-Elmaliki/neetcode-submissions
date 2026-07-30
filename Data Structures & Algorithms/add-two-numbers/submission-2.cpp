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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1Sum = 0, l2Sum = 0;  
        int digitPlace = 1; 

        ListNode *temp1 = l1, *temp2 = l2; 
        while(temp1) {
            l1Sum += (temp1->val * digitPlace); 
            temp1 = temp1->next;

            digitPlace *= 10; 
        }

        digitPlace = 1; 
        while(temp2) {
            l2Sum += (temp2->val * digitPlace); 
            temp2 = temp2->next; 

            digitPlace *= 10;  
        }

        int totalSum = l1Sum + l2Sum; 

        ListNode* dummy = new ListNode(); 
        ListNode* current = dummy; 

        bool reachedZero = false; 
        while(!reachedZero) {
            int currentNum = totalSum % 10; 

            ListNode* newNode = new ListNode(currentNum); 
            current->next = newNode; 
            current = current->next; 

            totalSum /= 10; 

            if(totalSum == 0) {
                reachedZero = true; 
            }
        }


        ListNode* head = dummy->next; 
        dummy->next = nullptr; 
        delete dummy; 

        return head; 
    }
};
