#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &data) {
  int n = data.size();
  for (int i = 0; i < n - 1; i++) {
    int mmin = i;
    for (int j = i + 1; j < n; j++) {
      if (data[mmin] > data[j]) {
        mmin = j;
      }
    }
    swap(data[mmin], data[i]);
  }
}

int main() {
  vector<int> vec = {5, 2, 9, 1, 4, 8, 3};
  selection_sort(vec);

  for (int v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
