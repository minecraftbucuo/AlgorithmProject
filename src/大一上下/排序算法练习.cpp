//2024 11 5 看《算法导论》一书所学。
//堆排序
//#include<bits/stdc++.h>
//using namespace std;
//
//void max_heap(vector<int>& a, int i, int a_size) {
//	int max_idx = i;
//	if (2 * i < a_size) {
//		max_idx = a[max_idx] >= a[2 * i] ? max_idx : 2 * i;
//	}
//	if (2 * i + 1 < a_size) {
//		max_idx = a[max_idx] >= a[2 * i + 1] ? max_idx : 2 * i + 1;
//	}
//	if (max_idx != i) {
//		swap(a[i], a[max_idx]);
//		max_heap(a, max_idx, a_size);
//	}
//}
//
//void build_max_heap(vector<int>& a) {
//	for (int i = a.size() / 2; i >= 0; i--) {
//		max_heap(a, i, a.size());
//	}
//}
//
//void heap_sort(vector<int>& a) {
//	build_max_heap(a);
//	for (int i = a.size() - 1; i >= 1; i--) {
//		swap(a[0], a[i]);
//		max_heap(a, 0, i);
//	}
//}
//
//
//int main() {
//	vector<int> a = {34, 2, 32, 45, 125, 43, 23, 5, 65, 675};
//	heap_sort(a);
//	for (int num : a) {
//		cout << num << ' ';
//	}
//	return 0;
//}

//快速排序 2024 11 9 算法导论所学
//#include <bits/stdc++.h>
//using namespace std;
//
//int partition_sort(vector<int>& a, int left, int right) {
//	int x = a[right];
//	// 这其实是个双指针
//	int i = left;
//	for (int j = left; j <= right - 1; j++) {
//		if (a[j] < x) {
//			swap(a[i], a[j]);
//			i++;
//		}
//	}
//	swap(a[i], a[right]);
//	return i;
//}
//
//void quick_sort(vector<int>& a, int left, int right) {
//	if (left >= right) return;
//	int q = partition_sort(a, left, right);
//	quick_sort(a, left, q - 1);
//	quick_sort(a, q + 1, right);
//}
//
//
//int main() {
//	vector<int> a = {34, 2, 32, 45, 125, 43, 23, 5, 65, 675};
//	quick_sort(a, 0, a.size() - 1);
//	for (int num : a) {
//		cout << num << ' ';
//	}
//	return 0;
//}



