/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 * 
 * 
 * 
 * Skiplist skiplist = new Skiplist();

skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // 返回 false
skiplist.add(4);
skiplist.search(1);   // 返回 true
skiplist.erase(0);    // 返回 false，0 不在跳表中
skiplist.erase(1);    // 返回 true
skiplist.search(1);   // 返回 false，1 已被擦除

 */

#include "Skiplist.hpp"

int main()
{
    // int target = 1;
    // int num = 3;
    Skiplist* obj = new Skiplist();
    // bool param_1 = obj->search(target);
    obj->add(1);
    obj->add(2);
    obj->add(3);
    if(obj->search(0))
        cout << "Found!" << endl;   // 返回 false
    obj->add(4);
    obj->search(1);   // 返回 true
    // obj->erase(0);    // 返回 false，0 不在跳表中
    // obj->erase(1);    // 返回 true
    // obj->search(1);   // 返回 false，1 已被擦除


    // bool param_3 = obj->erase(num);
}