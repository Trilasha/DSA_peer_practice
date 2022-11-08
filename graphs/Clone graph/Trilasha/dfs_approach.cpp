/*
Trilasha Mazumder
*/


/*
// Definition for a Node.
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
*/

//dfs approach

class Solution {
public: 
    map<Node*,Node*> mp;

    Node* dfs(Node* node)
    {
        vector<Node*> neighbour;
        Node* cloned_node=new Node(node->val);
        mp[node]=cloned_node;
        //mp[clone]=actual
        //mp[cloned_node]=node --> RUNTIIME_error --> because have to push_back the cloned_node into the neighbour not the actual node so the in the map created, key--> node, value-->cloned_node

        for(auto &adjNode:node->neighbors)
        {
            if(mp.find(adjNode)==mp.end())
            {
                neighbour.push_back(dfs(adjNode));
            }
            else
            neighbour.push_back(mp[adjNode]);
        }

        cloned_node->neighbors=neighbour;

        //backtracking ultimately returns the root node at the end 
        return cloned_node;
    }


    Node* cloneGraph(Node* node) {
        //

        if(node==NULL)
        return NULL;


        //
        if(node->neighbors.size()==0)
        {
            Node* cloneNode=new Node(node->val);
            return cloneNode;
        }


        //
        return dfs(node);
    }
};