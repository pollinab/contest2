/*5_2. LSD для long long.
Дан массив неотрицательных целых 64-битных чисел.
Количество чисел не больше 106.
Отсортировать массив методом поразрядной сортировки LSD по байтам.*/

#include<iostream>

void CountingSort(long long* arr, int n, int byte, int* basket, int* index)
{
    long long *newArr = new long long [n];
    for (int i = 0; i < 256; ++i)
    {
        basket[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        basket[(arr[i] >> 8 * byte) & 255]++;
    }
    index[0] = 0;
    for (int i = 1; i < 256; ++i)
    {
        index[i] = index[i - 1] + basket[i - 1];
    }
    for (int i = 0; i < n; ++i)
    {
        newArr[index[(arr[i] >> 8 * byte) & 255]] = arr[i];
        ++index[(arr[i] >> 8 * byte) & 255];
    }
    for (int i = 0; i < n; ++i)
    {
        arr[i] = newArr[i];
    }
    delete [] newArr;
}

void LSD(long long *arr, int n)
{
    int *basket = new int [256];
    int *index = new int [256];
    for (int byte = 0; byte <= 7; ++byte)
    {
        CountingSort(arr, n, byte, basket, index);
    }
    delete [] basket;
    delete [] index;
}

int main()
{
    int n;
    std::cin >> n;
    long long *arr = new long long [n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    LSD(arr, n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    delete [] arr;
    return 0;
}
