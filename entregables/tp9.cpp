#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility> 
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>
#define heap priority_queue
using namespace std;

int dist(string v, string w) {
    int acc = 0;
    for (int i = 0; i < v.size(); ++i) {
        int c1 = v[i] - '0', c2 = w[i] - '0';
        int diff = abs(c1 - c2);
        acc += min(diff, 10 - diff);
    }
    return acc;
}

int prim(const vector<list<pair<int, int>>>& adj, int start) {
    int n = adj.size();
    vector<int> minDist(n, INT_MAX);
    vector<bool> visited(n, false);
    // el heap tiene guardado el indice del nodo vecino en el array de nodos y el peso
    heap<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    minDist[start] = 0;
    min_heap.push({0, start});

    int totalCost = 0;
    
    while (!min_heap.empty()) {
        int u = min_heap.top().second;
        min_heap.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalCost += minDist[u];

        for (const auto& [v, weight] : adj[u]) {
            if (!visited[v] && weight < minDist[v]) {
                minDist[v] = weight;
                min_heap.push({weight, v});
            }
        }
    }

    return totalCost;
}

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        int n;
        cin >> n;
        vector<string> nodes(n);
        for (int i = 0; i < n; ++i) {
            cin >> nodes[i];
        }

        int cantidad_minima_de_arranque = INT_MAX;
        for (int i = 0; i < n; ++i) {
            cantidad_minima_de_arranque = min(cantidad_minima_de_arranque, dist("0000", nodes[i]));
        }

        vector<list<pair<int, int>>> adj(n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = dist(nodes[i], nodes[j]);
                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        int result = prim(adj, 0) + cantidad_minima_de_arranque;
        cout << result << endl;
    }

    return 0;
}
