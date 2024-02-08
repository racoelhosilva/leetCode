/* 
 * Problem: 133 
 * Name: Clone Graph
 * Difficulty: Medium
 * Topic: Graphs
 * Link: https://leetcode.com/problems/clone-graph/
 */
 
#include <bits/stdc++.h>
using namespace std;

// Graph Node Implementation
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//      Hash map + BFS
// Time Complexity: O(V+E) / O(n)
// Space Complexity: O(V)
Node* cloneGraph(Node* node) {
    if (node == nullptr) {return nullptr;}

    unordered_map<Node*, Node*> oldNewNodes;
    queue<Node*> remaining;

    oldNewNodes[node] = new Node(node->val);
    remaining.push(node);

    while (!remaining.empty()) {
        Node* current = remaining.front();
        remaining.pop();

        for (Node* adj : current->neighbors) {
            if (oldNewNodes.find(adj) == oldNewNodes.end()){
                oldNewNodes[adj] = new Node(adj->val);
                remaining.push(adj);
            }
            oldNewNodes[current]->neighbors.push_back(oldNewNodes[adj]);
        }
    }
    return oldNewNodes[node];
}

//      Hash map + DFS (stack)
// Time Complexity: O(V+E) / O(n)
// Space Complexity: O(V)
Node* cloneGraph(Node* node) {
    if (node == nullptr) {return nullptr;}

    unordered_map<Node*, Node*> oldNewNodes;
    stack<Node*> remaining;

    oldNewNodes[node] = new Node(node->val);
    remaining.push(node);

    while (!remaining.empty()) {
        Node* current = remaining.top();
        remaining.pop();

        for (Node* adj : current->neighbors) {
            if (oldNewNodes.find(adj) == oldNewNodes.end()){
                oldNewNodes[adj] = new Node(adj->val);
                remaining.push(adj);
            }
            oldNewNodes[current]->neighbors.push_back(oldNewNodes[adj]);
        }
    }
    return oldNewNodes[node];
}

//      Hash map + DFS (recursive)
// Time Complexity: O(V+E) / O(n)
// Space Complexity: O(V)
Node* cloneNode(Node* node, unordered_map<Node*, Node*>& oldNewNodes);
Node* cloneGraph(Node* node) {
    if (node == nullptr) {return nullptr;}
    unordered_map<Node*, Node*> oldNewNodes;
    return cloneNode(node, oldNewNodes);
}

Node* cloneNode(Node* node, unordered_map<Node*, Node*>& oldNewNodes){
    if (oldNewNodes.find(node) != oldNewNodes.end()){
        return oldNewNodes[node];
    }

    oldNewNodes[node] = new Node(node->val);
    for (Node* adj : node->neighbors) {
        oldNewNodes[node]->neighbors.push_back(cloneNode(adj, oldNewNodes));
    }
    return oldNewNodes[node];
}
