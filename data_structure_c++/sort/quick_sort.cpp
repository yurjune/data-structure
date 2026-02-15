#include <iostream>
#include <vector>

using namespace std;

int median(vector<int> &data, int left, int right) {
  int mid = left + (right - left) / 2;
  int x = data[left];
  int y = data[mid];
  int z = data[right];
  if ((y <= x && x <= z) || (z <= x && x <= y)) return left;
  if ((z <= y && y <= x) || (x <= y && y <= z)) return mid;
  return right;
}

int partition(vector<int> &data, int left, int right) {
  int m = median(data, left, right);
  swap(data[left], data[m]); // fix pivot to first index

  int pivot = data[left];
  int i = left + 1;
  int j = right;

  while (true) {
    while (i <= right && data[i] <= pivot) i++;
    while (j >= left + 1 && data[j] > pivot) j--;
    if (i > j) break;
    swap(data[i], data[j]);
  }

  swap(data[left], data[j]);
  return j;
}

void quick_sort(vector<int> &data, int left, int right) {
  if (left >= right) return;

  int p = partition(data, left, right);
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
