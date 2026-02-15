#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &data) {
  if (data.size() < 2)
    return;

  vector<int> buffer(data.size(), 0);

  auto divide = [&](auto &self, int left, int right) -> void {
    if (right - left <= 1)
      return;

    int mid = left + (right - left) / 2;
    self(self, left, mid);
    self(self, mid, right);

    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right) {
      if (data[i] <= data[j]) {
        buffer[k] = data[i];
        i += 1;
      } else {
        buffer[k] = data[j];
        j += 1;
      }
      k += 1;
    }

    while (i < mid) {
      buffer[k] = data[i];
      i += 1;
      k += 1;
    }
    while (j < right) {
      buffer[k] = data[j];
      j += 1;
      k += 1;
    }

    for (int p = left; p < right; p++) {
      data[p] = buffer[p];
    }
  };

  divide(divide, 0, data.size());
}

int main() {
  vector<int> vec = {5, 2, 9, 1, 4, 8, 3};
  merge_sort(vec);

  for (int v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
