#include<iostream>
#include<cstdlib>
#include<cstdio>

struct Stack
{
    int* buffer;
    int bufferSize;
    int top;
    Stack()
    {
        const int Size = 60;
        buffer = new int[Size];
        bufferSize = Size;
        top = -1;
    }
    Stack(int l)
    {
        buffer = new int[l];
        bufferSize = l;
        top = -1;
    }
    ~Stack()
    {
        delete[] buffer;
    }
    void grow()
    {
        int* newBuffer = new int[bufferSize * 10];
        for (int i = 0; i < bufferSize; ++i)
        {
            newBuffer[i] = buffer[i];
        }
        delete[] buffer;
        buffer = newBuffer;
        bufferSize *= 10;
    }
    void push(int elem)
    {
        if (top + 1 >= bufferSize)
            grow();
        buffer[++top] = elem;
    }
    int pop()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return buffer[top--];
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int PivotIndex(int *arr, int n, int first) //выбор опорного элемента медиана трех
{
    int middle = first + n / 2;
    if (arr[first] < arr[first + n - 1])
    {
        if (arr[first] > arr[middle])
            return first;
        if (arr[first + n - 1] < arr[middle])
            return first + n - 1;
        return middle;
    }
    else
    {
        if (arr[first] < arr[middle])
            return first;
        if (arr[first + n - 1] > arr[middle])
            return first + n - 1;
        return middle;
    }
}

int Partition(int *arr, int n, int first)
{
    int pivotIndex = PivotIndex(arr, n, first);
    std::swap(arr[pivotIndex], arr[first + n - 1]);
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

void InsertionSort(int* arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int cur = arr[i];
        int j;
        for (j = i - 1; j >= 0 && cur < arr[j]; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = cur;
    }
}

void QuickSort(int* arr, int n, int first)
{
    const int min_n = 100;
    int part;
    Stack S; //вместо рекурсии используем стек
    S.push(n);
    S.push(first);
    while (!S.isEmpty())
    {
        first = S.pop();
        n = S.pop();
        if (n < min_n) //не сортируем короткие массивы
            continue;
        else
        {
            part = Partition(arr, n, first);
            if (part > 0)
            {
                S.push(part);
                S.push(first);
            }
            if (part + 1 < n)
            {
                S.push(n - (part + 1));
                S.push(part + first + 1);
            }
        }
    }
}
int main()
{
    int n = 0;
    int *arr = new int [25000000];
    while(scanf("%d %d %d %d %d %d %d %d %d %d", &arr[n], &arr[n + 1], &arr[n + 2], &arr[n + 3], &arr[n + 4], &arr[n + 5], &arr[n + 6], &arr[n + 7], &arr[n + 8], &arr[n + 9]) != EOF)
    {
        n += 10;
    }
    QuickSort(arr, n, 0);
    InsertionSort(arr, n); //сортируем короткие части вставками
    for (int i = 9; i < n; i += 10)
    {
        printf("%d ", arr[i]);
    }
    delete[] arr;
    return 0;
}

