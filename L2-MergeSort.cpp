#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

void merge(int a[], int low, int high, int mid)
{                                                                   // TC - O(n log n) -best , average , worst cases
    int i = low, j = mid + 1, k = 0;                                // SC - O(n)
    int temp[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    while (j <= high)
    {
        temp[k++] = a[j++];
    }

    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

int main()
{
    int n, i, j;
    int a[100000];

    cout << "Enter the Number of Elements to be sorted: ";
    cin >> n;

    cout << "The Random numbers are: ";
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
        cout << a[i] << " ";
    }

    clock_t start = clock();
    mergesort(a, 0, n - 1);
    clock_t end = clock();

    cout << "\nSorted Elements are: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken for sorting " << n << " elements is: " << time << " seconds";

    ofstream file("mergesort.txt", ofstream::app); 
    for (i = 10000; i <= 100000; i += 2000)
    {
        n = i;
        int *b = new int[n];
        for (j = 0; j < n; j++)
            b[j] = rand() % 1000;

        clock_t s = clock();
        mergesort(b, 0, n - 1);
        clock_t e = clock();
        double t = (double)(e - s) / CLOCKS_PER_SEC;

        file << n << "\t" << t << "\n";
        delete[] b;
    }
    file.close();

    cout << "\nTime to sort 10000 to 100000 (incrementing 2000 per iteration) elements is added to the file mergesort.txt";
    return 0;
}