#include <bits/stdc++.h>
using namespace std;

void prims(int n, vector <vector<int>> adj[]){
    priority_queue <pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>> > pq;
    vector <int> visited(n,0);
    // weight, node
    pq.push({0,0});
    int sum = 0;
    vector<int> parent(n, -1);

    while (!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (visited[node] == 1) continue;

        visited[node] = 1;
        sum += wt;
        if (parent[node] != -1)
            cout << parent[node] << '-' << node << ": " << wt << endl;

        for (auto it: adj[node]){
            if (!visited[it[0]]){
                pq.push({it[1],it[0]});
                parent[it[0]] = node;
            }
        }
    }
    cout << "MST cost: " << sum;
}

int main(){
    int n,m;
    cout << "Enter no of vertices: "; cin >> n;
    cout << "Enter no of edges: "; cin >> m;
    vector <vector<int>> adj[n];
    int u,v,w;
    for (int i = 0; i < m; i++){
        cout << "Enter edge and weight: ";
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    prims(n,adj);
    return 0;
}
