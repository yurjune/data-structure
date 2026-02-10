#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>> edges) {
  vector<vector<int>> graph(n, vector<int>{});
  vector<int> degrees(n, 0);

  for (auto edge : edges) {
    graph[edge[0]].push_back(edge[1]);
    degrees[edge[1]] += 1;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (degrees[i] == 0) {
      q.push(i);
    }
  }

  vector<int> res;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    res.push_back(node);

    for (auto el : graph[node]) {
      if (--degrees[el] == 0) {
        q.push(el);
      }
    }
  }

  return res.size() == n ? res : vector<int>{}; // check cycle
};

int main() {
  int n = 4;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
  vector<int> result = topologicalSort(n, edges); // [0,2,1,3] 또는 [0,1,2,3]

  for (int node : result) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
