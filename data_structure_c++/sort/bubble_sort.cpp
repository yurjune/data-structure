#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &data) {
  int n = data.size();
  for (int i = 0; i < n - 1; i++) {
    // j < n-i: 이미 정렬된 부분은 제외
    for (int j = 1; j < n - i; j++) {
      if (data[j] < data[j - 1]) {
        swap(data[j], data[j - 1]);
      }
    }
  }
}

int main() {
  vector<int> vec = {5, 2, 9, 1, 4, 8, 3};
  bubble_sort(vec);

  for (int v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
