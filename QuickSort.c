#include <stdio.h>

// 交换两个元素的值
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// 分区函数，选择最后一个元素作为基准
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // 选择最后一个元素作为基准
  int i = (low - 1);     // 较小元素的索引

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// 快速排序的主函数
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    // 递归地对基准元素前后的子数组进行排序
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// 打印数组
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("原始数组: ");
  printArray(arr, n);
  quickSort(arr, 0, n - 1);
  printf("排序后的数组: ");
  printArray(arr, n);
  return 0;
}
