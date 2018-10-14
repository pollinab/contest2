/*4_1. Первые k элементов длинной последовательности.
Дана очень длинная последовательность целых чисел длины n.
Требуется вывести в отсортированном виде её первые k элементов.
Последовательность может не помещаться в память. Время работы O(n * log(k)).
Доп. память O(k). Использовать слияние.*/

#include<iostream>

void SiftDown(int* arr, int heapSize, int i)
{
    int left, right, largest;
    bool stop = false;
    while(!stop)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;
        if (left < heapSize && arr[left] > arr[i])
            largest = left;
        if (right < heapSize && arr[right] > arr[largest])
            largest = right;
        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            i = largest;
        }
        else
        {
            stop = true;
        }
    }
}

void BuildHeap(int* arr, int heapSize)
{
    for (int i = heapSize / 2 - 1; i >= 0; --i)
        SiftDown(arr, heapSize, i);
}

void HeapSort(int* arr, int n)
{
    int heapSize = n;
    BuildHeap(arr, heapSize);
    while (heapSize > 1)
    {
        std::swap(arr[0], arr[heapSize - 1]);
        --heapSize;
        SiftDown(arr, heapSize, 0);
    }
}

void Merge(int *arr1, int *arr2, int *arr3, int len1, int len2)
{
    int i = 0;
    int j = 0;
    while (j < len2 && i + j < len1)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[i + j] = arr1[i];
            ++i;
        }
        else
        {
            arr3[i + j] = arr2[j];
            ++j;
        }
    }
    if (i + j < len1)
    {
        while (i + j < len1)
        {
            arr3[i + j] = arr1[i];
            ++i;
        }
    }
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    int *arr1 = new int [k];
    int *arr2 = new int [k];
    int *res = new int [k];
    for (int i = 0; i < k; ++i)
    {
        std::cin >> res[i];
    }
    HeapSort(res, k);
    n -= k;
    while(n - k >= 0)
    {
        n -= k;
        for (int i = 0; i < k; ++i)
        {
            std::cin >> arr2[i];
            arr1[i] = res[i];
        }
        HeapSort(arr2, k);
        Merge(arr1, arr2, res, k, k);
    }
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr2[i];
    }
    for (int i = 0; i < k; ++i)
    {
        arr1[i] = res[i];
    }
    HeapSort(arr2, n);
    Merge(arr1, arr2, res, k, n);
    for (int i = 0; i < k; ++i)
    {
        std::cout << res[i] << " ";
    }
    delete [] arr1;
    delete [] arr2;
    delete [] res;
    return 0;
}
