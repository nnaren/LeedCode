#include "quicksort.h"
#include <iostream>
#include <vector>
int main()
{
    int a[8] = {3,6,1,5,7,8,2,4};
    int low = 0, high = sizeof(a)/4-1;
    quickSort(a,low,high);

    std::vector<int> list;
    list.push_back(3);
    list.push_back(6);
    list.push_back(1);
    list.push_back(5);
    list.push_back(7);
    list.push_back(8);
    list.push_back(2);
    list.push_back(4);
 
    quickSortUseVector(&list, low, high);
    return 0;
}