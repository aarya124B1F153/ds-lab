#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src;
    int des;
    int weight;
};

class DisjointSet {
public:
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu != pv)
            parent[pu] = pv;
    }
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int n, e;
    cout << "Enter number of houses: ";
    cin >> n;
    cout << "Enter number of connections: ";
    cin >> e;

    vector<Edge> edges(e);

    cout << "Enter each connection as (source destination cost)\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].src >> edges[i].des >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(n);
    int totalCost = 0;
    vector<Edge> result;

    for (int i = 0; i < e; i++) {
        int u = edges[i].src;
        int v = edges[i].des;
        int w = edges[i].weight;

        int parentU = ds.findParent(u);
        int parentV = ds.findParent(v);

        if (parentU != parentV) {
            ds.unionSet(u, v);
            result.push_back(edges[i]);
            totalCost += w;
        }
    }

    cout << "\nEdges in the Minimum Cost Pipeline Network:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].src << " -- " << result[i].des << " == " << result[i].weight << endl;
    }

    cout << "\nTotal Minimum Cost: " << totalCost << endl;

    return 0;
}

