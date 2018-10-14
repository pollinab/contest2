/*¬ супермаркете решили оптимизировать показ рекламы.
»звестно расписание прихода и ухода покупателей (два целых числа).
 аждому покупателю необходимо показать минимум 2 рекламы.
–екламу можно транслировать только в целочисленные моменты времени.
ѕокупатель может видеть рекламу от момента прихода до момента ухода из магазина.
¬ каждый момент времени может показыватьс€ только одна реклама.
—читаетс€, что реклама показываетс€ мгновенно.
≈сли реклама показываетс€ в момент ухода или прихода, то считаетс€, что посетитель успел еЄ посмотреть.
“ребуетс€ определить минимальное число показов рекламы.*/
#include<iostream>

void SiftDown(int** arr, int heapSize, int i)
{
    int left, right, largest;
    bool stop = false;
    while(!stop)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;
        if (left < heapSize && (arr[left][1] > arr[i][1] || (arr[left][1] == arr[i][1] && arr[left][0] < arr[i][0])))
            largest = left;
        if (right < heapSize && (arr[right][1] > arr[largest][1] || (arr[right][1] == arr[largest][1] && arr[right][0] < arr[largest][0])))
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

void BuildHeap(int** arr, int heapSize)
{
    for (int i = heapSize / 2 - 1; i >= 0; --i)
        SiftDown(arr, heapSize, i);
}

void HeapSort(int** arr, int n)
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

int main()
{
    int n, t1, t2;
    std::cin >> n;
    int **arr = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int [2];
        std::cin >> t1 >> t2;
        arr[i][0] = t1;
        arr[i][1] = t2;
    }
    HeapSort(arr, n);
    int lastAd = arr[0][1];
    int prevAd = arr[0][1] - 1;
    int amount = 2;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i][0] > lastAd)
        {
            prevAd = arr[i][1] - 1;
            lastAd = arr[i][1];
            amount += 2;
        }
        else if (arr[i][0] > prevAd)
        {
            prevAd = lastAd;
            lastAd = arr[i][1];
            ++amount;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        delete []arr[i];
    }
    delete []arr;
    std::cout << amount;
    return 0;
}
