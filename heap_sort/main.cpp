#include "heapsort.hpp"
#include <iostream>
#include <vector>
int main()
{
    vector<int> a = {3,6,1,5,7,8,2,4};
    int n = 8;
    heapSort(a,n);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " -> ";
    }
    
    return 0;
}