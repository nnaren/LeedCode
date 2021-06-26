#include<unordered_map>
using namespace std;
class Node
{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node (int k, int v)
    {
        this->key =k;
        this->val =v;
    }
};

class DoubleList
{
public:
    DoubleList( )
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
        size = 0;
    }
    
    void addLast(Node* x)
    {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    void remove(Node* x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }

    Node* removeFirst()
    {
        if(head->next == tail)
            return nullptr;
        Node* first = head->next;
        remove(first);
        return first;
    }

    int getSize()
    {
        return size;
    }
private:
    int size;
    Node* head;
    Node* tail;
};
class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if (!map.count(key))
        {
            return -1;
        }
        makeRecently(key);
        return map[key]->val;
    }
    
    void put(int key, int value) {
        if(map.count(key))
        {
            deleteKey(key);
            addRecently(key, value);
            return;
        }
        if(cap == cache.getSize())
        {
            removeLeastRecently();
        }
        addRecently(key, value);
    }

private:
    void makeRecently(int key)
    {
        Node* x = map[key];
        cache.remove(x);
        cache.addLast(x);
    }

    void addRecently(int key, int val)
    {
        Node* x = new Node(key, val);
        cache.addLast(x);
        map[key]= x;
    }

    void deleteKey(int key)
    {
        Node* x = map[key];
        cache.remove(x);
        map.erase(key);
    }

    void removeLeastRecently() 
    {
        Node* deletedNode = cache.removeFirst();
        int deletedKey = deletedNode->key;
        map.erase(deletedKey);
    }


private:
    unordered_map<int, Node*> map;
    DoubleList cache;
    int cap;
};






/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


