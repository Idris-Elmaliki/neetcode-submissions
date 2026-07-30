class Solution {
    std::unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* newNode = new Node(node->val);
        visited[node] = newNode;

        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.emplace_back(cloneGraph(neighbor));
        }

        return newNode;
    }
};