/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        map<int, UndirectedGraphNode *> _created;
        queue<UndirectedGraphNode *> _queue;
        UndirectedGraphNode* _node = new UndirectedGraphNode(node->label);
        _created.insert(make_pair(node->label, _node));
        _queue.push(node);
        _queue.push(_node);
        while (!_queue.empty()) {
            UndirectedGraphNode* current = _queue.front();
            _queue.pop();
            UndirectedGraphNode* _current = _queue.front();
            _queue.pop();
            vector<UndirectedGraphNode *>::const_iterator neigh = current->neighbors.begin();
            for ( ; neigh != current->neighbors.end(); neigh++) {
                int n_label = (*neigh)->label;
                UndirectedGraphNode* _neigh ;
                if (_created.find(n_label) == _created.end()) {
                    _neigh = new UndirectedGraphNode(n_label);
                    _created.insert(make_pair(n_label, _neigh));
                    _queue.push(*neigh);
                    _queue.push(_neigh);
                } else {
                    _neigh = _created.find(n_label)->second;
                }
                _current->neighbors.push_back(_neigh);
            }
        }
        return _node;
    }
};