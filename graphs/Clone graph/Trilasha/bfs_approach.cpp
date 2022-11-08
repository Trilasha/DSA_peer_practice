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

    Node* bfs(Node* node)
    {
        Node* source=new Node(node->val);
        mp[node]=source;

        queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(auto &adjNode:it->neighbors)
            {
                if(mp.find(adjNode)==mp.end())
                {
                    Node *cloned_node=new Node(adjNode->val);
                    q.push(adjNode);
                    mp[adjNode]=cloned_node;
                }
               // if(adjNode!=NULL)  --> NOT REQUIRED
                mp[it]->neighbors.push_back(mp[adjNode]);
            }
        }
        return source;
    }


    Node* cloneGraph(Node* node) {
        //

        if(node==NULL)
        return NULL;
        //
        // if(node->neighbors.size()==0)
        // {
        //     Node* cloneNode=new Node(node->val);
        //     return cloneNode;
        // }
        // this check is not required

        //
        return bfs(node);
    }
};