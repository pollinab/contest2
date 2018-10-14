//Задано N точек на плоскости. Указать (N−1) -звенную несамопересекающуюся незамкнутую ломаную,
//проходящую через все эти точки.
#include<iostream>

void InsertionSort(int** points, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int cur_x = points[i][0];
        int cur_y = points[i][1];
        int j;
        for (j = i - 1; j >= 0 && (cur_x < points[j][0] || (cur_x == points[j][0] && cur_y < points[j][1])); --j)
        {
            points[j + 1][0] = points[j][0];
            points[j + 1][1] = points[j][1];
        }
        points[j + 1][0] = cur_x;
        points[j + 1][1] = cur_y;
    }
}

int main()
{
    int n, x, y;
    std::cin >> n;
    int **points = new int* [n];
    for (int i = 0; i < n; ++i)
    {
        points[i] = new int [2];
        std::cin >> x >> y;
        points[i][0] = x;
        points[i][1] = y;
    }
    InsertionSort(points, n);
    for (int i = 0; i < n; ++i)
    {
        std::cout << points[i][0] << " " << points[i][1] << std::endl;
    }
    for (int i = 0; i < n; ++i)
    {
        delete []points[i];
    }
    delete []points;
    return 0;
}
