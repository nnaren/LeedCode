#include"LFUCache.hpp"

int main()
{
    LFUCache* lFUCache = new LFUCache(2);
    lFUCache->put(1, 1); // 缓存是 {1=1}
    lFUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    lFUCache->get(1);    // 返回 1
    lFUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lFUCache->get(2);    // 返回 -1 (未找到)
    lFUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lFUCache->get(1);    // 返回 -1 (未找到)
    lFUCache->get(3);    // 返回 3
    lFUCache->get(4);    // 返回 4
}