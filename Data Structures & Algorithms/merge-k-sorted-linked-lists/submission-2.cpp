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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr; 

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy; 

        while(lists.size() > 0) {
            int smallestNum = INT_MAX, index = -1; 
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i] == nullptr) {
                    lists.erase(lists.begin() + i);
                    --i; 
                }
                else if(lists[i]->val < smallestNum) {
                    index = i; 
                    smallestNum = lists[i]->val;
                }
            }

            if (index == -1) 
                break;

            ListNode* current = lists[index]; 
            lists[index] = lists[index]->next; 

            temp->next = current;
            current->next = nullptr;
  
            temp = temp->next; 
        }

        ListNode* head = dummy->next; 
        dummy->next = nullptr; 
        delete dummy; 

        return head; 
    }
};
