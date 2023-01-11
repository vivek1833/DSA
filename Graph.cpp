#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V; // No. of vertices
    vector<int> adj[100];

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
};

void DFS(vector<int> adj[], vector<int> &visited, int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(adj, visited, *i);
}

vector<int> bfs(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(V, 0);
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        vis[curr] = 1;
        ans.push_back(curr);

        for (auto i : adj[curr])
        {
            if (vis[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return ans;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    vector<int> v;
    v = bfs(4, g.adj);
    for (auto i : v)
        cout << i << " "; // 0 1 2 3

    vector<int> visited(4, 0);
    cout << "DFS is (starting from vertex 2) \n";
        DFS(g.adj, visited, 2); // 2 0 1 3

    return 0;
}
