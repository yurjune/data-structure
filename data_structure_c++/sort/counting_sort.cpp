#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> counting_sort(vector<int> &data) {
  if (data.size() == 0) return {};

  int maxVal = *max_element(data.begin(), data.end()) + 1;

  // data의 각 원소의 등장 빈도수
  vector<int> freq(maxVal, 0);

  for (int el : data) {
    freq[el] += 1;
  }

  // freq[x] = x이하 원소의 총 개수
  // 향후 x가 들어갈 마지막 위치 + 1가 된다.
  for (int i = 1; i < freq.size(); i++) {
    freq[i] += freq[i - 1];
  }

  vector<int> res(data.size(), 0);
  // 뒤에서 부터 돌아야 stable sort
  for (int i = data.size() - 1; i >= 0; --i) {
    int el = data[i];
    int idx = freq[el] - 1;
    res[idx] = el;
    freq[el] -= 1;
  }
  return res;
}

int main() {
  vector<int> vec = {5, 2, 9, 1, 4, 8, 3};
  vec = counting_sort(vec);

  for (int v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
