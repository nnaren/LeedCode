#include <iostream>
#include <thread>
#include "Solution.h"

int main() {
    ZeroEvenOdd prnt(60);
    function<void(int)> printNumber = [](int i ){cout << i;};
    // printNumber(3);
    thread t1(&ZeroEvenOdd::zero, &prnt, printNumber); 
    thread t2(&ZeroEvenOdd::odd, &prnt, printNumber);
    thread t3(&ZeroEvenOdd::even, &prnt, printNumber);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
