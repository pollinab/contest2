/*Реализуйте стратегию выбора опорного элемента “случайный элемент”.
Функцию Partition реализуйте методом прохода двумя итераторами от начала массива к концу.*/

#include<iostream>
#include<cstdlib>

int Partition(int *arr, int n, int first)
{
    int randIndex = first + rand() % n;
    std::swap(arr[randIndex], arr[first + n - 1]);
    int pivot = arr[first + n - 1];
    int i, j;
    for (i = first; arr[i] < pivot; ++i)
    {}
    j = i + 1;
    while (j < first + n - 1)
    {
        if (arr[j] <= pivot)
        {
            std::swap(arr[i], arr[j]);
            ++i;
        }
        ++j;
    }
    std::swap(arr[i], arr[first + n - 1]);
    return i - first;
}

int KStatDC(int *arr, int n, int k)
{
    int P = Partition(arr, n, 0);
    int first = 0;
    int last = n - 1;
    while (P != k)
    {
        P = first + Partition(arr, last - first + 1, first);
        if (P > k)
            last = P - 1;
        else
            first = P + 1;
    }
    return arr[k];
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    int *arr = new int [n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    std::cout << KStatDC(arr, n, k);
    delete [] arr;
    return 0;
}
