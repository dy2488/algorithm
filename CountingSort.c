#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 找出数组中的最大值
int findMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// 找出数组中的最小值
int findMin(int arr[], int n) {
  int min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

// 计数排序主函数
void countingSort(int arr[], int n) {
  int max = findMax(arr, n);
  int min = findMin(arr, n);
  int range = max - min + 1;

  int *count = (int *)malloc(range * sizeof(int));
  int *output = (int *)malloc(n * sizeof(int));

  // 初始化计数数组
  memset(count, 0, range * sizeof(int));

  // 统计每个元素的出现次数
  for (int i = 0; i < n; i++) {
    count[arr[i] - min]++;
  }

  // 累加计数数组中的值
  for (int i = 1; i < range; i++) {
    count[i] += count[i - 1];
  }

  // 根据计数数组中的值，将元素放到输出数组中的正确位置
  for (int i = n - 1; i >= 0; i--) {
    output[count[arr[i] - min] - 1] = arr[i];
    count[arr[i] - min]--;
  }

  // 将排序后的数组复制回原数组
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  // 释放内存
  free(count);
  free(output);
}

// 打印数组
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组: ");
  printArray(arr, n);

  countingSort(arr, n);

  printf("排序后的数组: ");
  printArray(arr, n);

  return 0;
}
