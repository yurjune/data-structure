#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>> edges) {
  vector<vector<int>> graph(n, vector<int>{});

  for (auto edge : edges) {
    graph[edge[0]].push_back(edge[1]);
  }

  vector<bool> visit(n);
  vector<int> res;

  auto dfs = [&](auto &self, int node) -> void {
    visit[node] = true;
    for (int next : graph[node]) {
      if (visit[next] == 0) {
        self(self, next);
      }
    }
    res.push_back(node);
  };

  for (int i = 0; i < n; i++) {
    if (!visit[i]) {
      dfs(dfs, i);
    }
  }

  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int n = 4;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
  vector<int> result = topologicalSort(n, edges); // [0,2,1,3] or [0,1,2,3]

  for (int node : result) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
