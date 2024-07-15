#include <stdio.h>

// 交换两个元素
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// 堆化一个子树
void heapify(int arr[], int n, int i) {
  int largest = i;       // 根节点
  int left = 2 * i + 1;  // 左子节点
  int right = 2 * i + 2; // 右子节点

  // 如果左子节点大于根节点
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // 如果右子节点大于当前最大节点
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // 如果最大值不是根节点
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    // 递归堆化子树
    heapify(arr, n, largest);
  }
}

// 堆排序主函数
void heapSort(int arr[], int n) {
  // 构建最大堆
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // 一个接一个地从堆中取出元素
  for (int i = n - 1; i > 0; i--) {
    // 移动当前根到数组末尾
    swap(&arr[0], &arr[i]);

    // 调整剩余元素形成堆
    heapify(arr, i, 0);
  }
}

// 打印数组
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: ");
  printArray(arr, n);

  heapSort(arr, n);

  printf("排序后的数组: ");
  printArray(arr, n);

  return 0;
}
