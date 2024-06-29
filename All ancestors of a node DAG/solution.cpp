struct node;

struct Node {
    int val;
    vector<int> childs;
    vector<int> parents;

    Node() {
        val = -1;
        childs = vector<int>();
        parents = vector<int>();
    }
};

void createOrUpdate(vector<Node>& nodes, vector<int>edge) {
    int nodesSize = nodes.size();

    if (nodes[edge[0]].val == -1) {
        nodes[edge[0]].val = edge[0];
    }
    if (nodes[edge[1]].val == -1) {
        nodes[edge[1]].val = edge[1];
    }
    if (find(nodes[edge[0]].childs.begin(), nodes[edge[0]].childs.end(), edge[1]) == nodes[edge[0]].childs.end()) {
        nodes[edge[0]].childs.push_back(edge[1]);
    }
    if (find(nodes[edge[1]].parents.begin(), nodes[edge[1]].parents.end(), edge[0]) == nodes[edge[1]].parents.end()) {
        nodes[edge[1]].parents.push_back(edge[0]);
    }
}

void dfs(vector<Node>& nodes, int node, vector<int>& route) {
    int parentsSize = nodes[node].parents.size();
    int nodesSize = nodes.size();

    if (nodesSize > 10) {
        dfs(nodes.begin(), nodes.begin() + nodesSize / 2, node, route);
        dfs(nodes.begin() + nodesSize / 2, nodes.end(), node, route);
    }

    for (int i = 0; i < parentsSize; i++) {
        if (find(route.begin(), route.end(), nodes[node].parents[i]) == route.end()) {
            if (find(route.begin(), route.end(), nodes[node].parents[i]) == route.end()) {
                route.push_back(nodes[node].parents[i]);
            }
            dfs(nodes, nodes[node].parents[i], route);
        }
    }
}

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>res(n);
        int edgesSize = edges.size();
        vector<Node> nodes(n, Node());

        for (int i = 0; i < edgesSize; i++) {
            createOrUpdate(nodes, edges[i]);
        }

        for (int i = 0; i < n; i++) {
            vector <int> route;
            dfs(nodes, i, route);
            std::sort(route.begin(), route.end());
            res[i] = route;
        }

        return res;
    }
};