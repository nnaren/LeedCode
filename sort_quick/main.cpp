#include "quicksort.h"
#include <iostream>
#include <vector>
int main()
{
    int a[8] = {3,6,1,5,7,8,2,4};
    int low = 0, high = sizeof(a)/4-1;
    quickSort(a,low,high);

    std::vector<int> list = {3, 6, 1, 5, 7, 8, 2, 4};
    quickSortUseVector(&list, low, high);
    return 0;
}