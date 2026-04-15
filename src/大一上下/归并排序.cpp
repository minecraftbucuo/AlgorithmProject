#include <iostream>
#include <vector>

// 合并两个有序数组
void merge(std::vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1;  // 左半部分元素个数
	int n2 = right - mid;      // 右半部分元素个数

	// 创建临时数组
	std::vector<int> L(n1), R(n2);

	// 拷贝数据到临时数组 L[] 和 R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	// 合并临时数组回到原数组
	int i = 0; // 初始索引第一个子数组
	int j = 0; // 初始索引第二个子数组
	int k = left; // 初始索引合并后的子数组
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// 拷贝剩余的L[]元素
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// 拷贝剩余的R[]元素
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

// 归并排序主函数
void merge_sort(std::vector<int>& arr, int left, int right) {
	if (left < right) {
		// 找到中间位置
		int mid = left + (right - left) / 2;

		// 递归地对两半进行排序
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);

		// 合并已排序的两半
		merge(arr, left, mid, right);
	}
}

int main() {
	std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
	int n = arr.size();

	// 调用归并排序
	merge_sort(arr, 0, n - 1);

	// 输出排序后的数组
	std::cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}
