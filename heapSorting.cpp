// Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell 
// data structure with modularity of programming language 
#include <iostream>
#include <vector>
#include <algorithm>

class HeapSort {
public:
    static void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    static void sort(std::vector<int>& arr) {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

class ShellSort {
public:
    static void sort(std::vector<int>& arr) {
        int n = arr.size();

        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
    }
};

int main() {
    std::vector<int> arrHeap = {12, 11, 13, 5, 6, 7};
    std::vector<int> arrShell = {12, 11, 13, 5, 6, 7};

    std::cout << "Original array for Heap Sort: ";
    for (int num : arrHeap)
        std::cout << num << " ";
    std::cout << std::endl;

    HeapSort::sort(arrHeap);

    std::cout << "Sorted array using Heap Sort: ";
    for (int num : arrHeap)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "\nOriginal array for Shell Sort: ";
    for (int num : arrShell)
        std::cout << num << " ";
    std::cout << std::endl;

    ShellSort::sort(arrShell);

    std::cout << "Sorted array using Shell Sort: ";
    for (int num : arrShell)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
