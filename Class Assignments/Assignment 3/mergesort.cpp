#include <iostream>
using namespace std;
void merge(int *array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    // size of left and right sub-arrays
    nl = m - l + 1;
    nr = r - m;
    int larr[nl], rarr[nr];
    // fill left and right sub-arrays
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    // marge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl)
    { // extra element in left array
        array[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr)
    { // extra element in right array
        array[k] = rarr[j];
        j++;
        k++;
    }
}
void mergeSort(int *array, int l, int r)
{
    int m;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        // Sort first and second arrays
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}
int main()
{
    int arr[6] = {4, 3, 1, 7, 8, 0};
    cout << "Before : ";
    display(arr, 6);
    cout << endl;
    cout << "After : ";
    mergeSort(arr, 0, 6);
    display(arr, 6);
}