#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int median_of_three(vector<int> &v, int l, int r) {
  int m = l + (r - l) / 2;
  int x = v[l];
  int y = v[m];
  int z = v[r];

  if ((y <= x && x <= z) || (z <= x && x <= y)) return l;
  if ((z <= y && y <= x) || (x <= y && y <= z)) return m;
  return r;
}

int partition_lomuto(vector<int> &data, int left, int right) {
  int m = median_of_three(data, left, right);
  swap(data[m], data[right]); // place pivot to right

  int pivot = data[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (data[j] <= pivot) {
      i++;
      swap(data[i], data[j]);
    }
  }
  swap(data[i + 1], data[right]);
  return i + 1; // pivot position
}

void quick_sort(vector<int> &data, int left, int right) {
  if (left >= right) return;

  int p = partition_lomuto(data, left, right);
  quick_sort(data, left, p - 1);
  quick_sort(data, p + 1, right);
}

int main() {
  vector<int> vec = {5, 2, 9, 1, 4, 8, 3};
  quick_sort(vec, 0, vec.size() - 1);

  for (int v : vec) {
    cout << v << " ";
  }
  cout << endl;
}
