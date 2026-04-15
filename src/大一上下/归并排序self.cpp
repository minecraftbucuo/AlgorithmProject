// 2024.10.3

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = arr[mid + i + 1];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] > R[j]) {
			arr[k] = R[j];
			j++;
		} else {
			arr[k] = L[i];
			i++;
		}
		k++;
	}

	for (; i < n1; i++) {
		arr[k] = L[i];
		k++;
	}


	for (; j < n2; j++) {
		arr[k] = R[j];
		k++;
	}

//	while (i < n1) {
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	while (j < n2) {
//		arr[k] = R[j];
//		j++;
//		k++;
//	}

}

void merge_sort(vector<int> &arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) >> 1;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

int main() {
	vector<int> arr = {2, 4, 1, 67, 23, 456, 567, 323, 56};
	merge_sort(arr, 0, arr.size() - 1);

	for (int num : arr) {
		cout << num << " ";
	}
	return 0;
}
