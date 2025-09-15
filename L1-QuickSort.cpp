#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

int partition(int a[], int l, int h)
{                                                       // TC - O(n log n) - best and average case
    int pivot = a[l];                                   //      - O(n^2) - worst case  
    int i = l, j = h, temp;                             // SC - O(log n)

    while (i < j)
    {
        while (i <= h && a[i] <= pivot)
            i++;
        while (a[j] > pivot) 
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int j = partition(a, l, h);
        quicksort(a, l, j - 1); 
        quicksort(a, j + 1, h);
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
    quicksort(a, 0, n - 1);
    clock_t end = clock();

    cout << "\nSorted Elements are: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken for sorting " << n << " elements is: " << time << " seconds";

    ofstream file("quicksort.txt", ofstream::app);
    for (i = 10000; i <= 100000; i += 2000)
    {
        n = i;
        int *b = new int[n];
        for (j = 0; j < n; j++)
            b[j] = rand() % 1000;

        clock_t s = clock();
        quicksort(b, 0, n - 1);
        clock_t e = clock();
        double t = (double)(e - s) / CLOCKS_PER_SEC;

        file << n << "\t" << t << "\n";
        delete[] b;
    }
    file.close();

    cout << "\nTime to sort 10000 to 100000 (incrementing 2000 per iteration) elements is added to the file quicksort.txt";
    return 0;
}