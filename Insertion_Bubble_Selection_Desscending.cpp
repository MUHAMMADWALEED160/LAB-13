#include <iostream>
#include <algorithm> // for reverse
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {55853, 56067, 56154, 56177, 56274, 56673, 56765, 56983, 55405, 55434, 55465, 55590, 55632, 55633, 55652, 44391, 44647, 47777, 53759, 55181, 55223, 55469, 55566, 55579, 55584, 55225, 55330, 55349, 55356, 55691, 55700, 55766, 55780, 55843};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {55853, 56067, 56154, 56177, 56274, 56673, 56765, 56983, 55405, 55434, 55465, 55590, 55632, 55633, 55652, 44391, 44647, 47777, 53759, 55181, 55223, 55469, 55566, 55579, 55584, 55225, 55330, 55349, 55356, 55691, 55700, 55766, 55780, 55843};
    int o = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {55853, 56067, 56154, 56177, 56274, 56673, 56765, 56983, 55405, 55434, 55465, 55590, 55632, 55633, 55652, 44391, 44647, 47777, 53759, 55181, 55223, 55469, 55566, 55579, 55584, 55225, 55330, 55349, 55356, 55691, 55700, 55766, 55780, 55843};
    int p = sizeof(arr3) / sizeof(arr3[0]);


    cout << "Original array: ";
    printArray(arr1, n);

    insertionSort(arr1, n);
    reverse(arr1, arr1 + n);
    cout << "Insertion Sort (Descending): ";
    printArray(arr1, n);

    bubbleSort(arr2, o);
    reverse(arr2, arr2 + o);
    cout << "Bubble Sort (Descending): ";
    printArray(arr2, o);

    selectionSort(arr3, p);
    reverse(arr3, arr3 + p);
    cout << "Selection Sort (Descending): ";
    printArray(arr3, p);

    return 0;
}
