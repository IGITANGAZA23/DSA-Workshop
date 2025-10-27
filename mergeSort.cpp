#include <iostream>
using namespace std;

void mergeArray(int a[], int s, int mid, int e) {
    int i = s, j = mid + 1, k = 0;
    int temp[100];
    while (i <= mid && j <= e) {
        if (a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= e) temp[k++] = a[j++];
    for (int p = 0; p < k; p++) a[s + p] = temp[p];
}

void mergeSort(int a[], int s, int e) {
    if (s >= e) return;
    int mid = (s + e) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    mergeArray(a, s, mid, e);
}

int main() {
    int arr[] = {20, 10, 30, 50, 40, 60, 80, 70, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted array:" << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
