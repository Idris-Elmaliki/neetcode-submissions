/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0); 
        std::unordered_map<Node*, Node*> nodeMap; 

        Node* current = dummy; 

        Node* temp = head; 
        int i = 0; 
        while(temp) {
            Node* newNode = new Node(temp->val); 

            nodeMap.insert({temp, newNode});

            current->next = newNode;  
          
            current = current->next; 
            temp = temp->next; 
            ++i; 
        }

        current = dummy->next; 
        temp = head; 
        while(temp) {
            if(temp->random != nullptr) {
                current->random = nodeMap[temp->random];
            }

            temp = temp->next; 
            current = current->next; 
        }

        current = dummy->next; 
        dummy->next = nullptr; 

        delete dummy;

        return current; 
    }
};
