#include "quicksort.h"


int partition(int a[],int low, int high)
{
    int pivot = a[low];
    while(low< high)
    {
        while(low < high && a[high] > pivot)
            high--;
        a[low] = a[high];
        while(low < high && a[low] < pivot)
            low++;
        a[high] = a[low];
    }
    a[low]=pivot;
    return low;
}

void quickSort(int a[],int low, int high)
{
    if(low<high)
    {
        int index = partition(a, low , high);
        quickSort(a, low, index-1);
        quickSort(a, index+1, high); 
    }
    return;
}

