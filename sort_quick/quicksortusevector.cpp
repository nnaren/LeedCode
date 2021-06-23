#include "quicksort.h"
#include<iostream>
int partitionUseVector(vector<int>* a, int low, int high)
{
    int pivot = (*a)[low];
    while(low< high)
    {
        while(low < high && (*a)[high] > pivot)
            high--;
        (*a)[low] = (*a)[high];
        while(low < high && (*a)[low] < pivot)
            low++;
        (*a)[high] = (*a)[low];
    }
    (*a)[low]=pivot;
    // vector<int>::iterator it;
    cout<< endl;
    for(auto it=(*a).begin();it != (*a).end();it++ )
    {
        cout << *it<< " ";
    }
    return low;
}

void quickSortUseVector(vector<int> *a,int low, int high)
{
    if(low<high)
    {
        int index = partitionUseVector(a, low , high);
        quickSortUseVector(a, low, index-1);
        quickSortUseVector(a, index+1, high); 
    }
    return;
}
