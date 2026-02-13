#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int> &data) {
  int n = data.size();
  for (int i = 1; i < n; i++) {
    int el = data[i];
    int j = i - 1;
    while (j >= 0 && data[j] > el) {
      data[j + 1] = data[j]; // 한 칸씩 밀어내기
      j--;
    }
    data[j + 1] = el; // 오른쪽 자리에 삽입
  }
}

int main() {
  vector<int> vec = {5, 2, 9, 1, 4, 8, 3};
  insertion_sort(vec);

  for (int v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
