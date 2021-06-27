
#include<unordered_map>
#include<list>
using namespace std;
#include"Node.hpp"
class LFUCache 
{
public:
    LFUCache(int _cap) {
        minFreq = 0;
        cap = _cap;
        keyToNodeIter.clear();
        freqToNode.clear();
    }
    
    int get(int key) 
    {
        if(!keyToNodeIter.count(key))
            return -1;
        auto tempNode = keyToNodeIter[key];
        int val = tempNode->val;
        int freq = tempNode->freq;
        freqToNode[freq].erase(tempNode);
        if(freqToNode[freq].size() == 0)
        {
            freqToNode.erase(freq);
            if(minFreq == freq)  
                ++minFreq;
        }
        freqToNode[freq+1].push_front(Node(key,val,freq+1));
        keyToNodeIter[key] = freqToNode[freq+1].begin();
        return val;
    }
    
    void put(int key, int value) 
    {
        if(cap == 0)
            return;
        if(!keyToNodeIter.count(key))
        {
            if(keyToNodeIter.size() == cap)
            {
                auto tempNode = freqToNode[minFreq].back();
                int tempKey = tempNode.key;
                keyToNodeIter.erase(tempKey);
                freqToNode[minFreq].pop_back();
                if(freqToNode[minFreq].size()==0)
                    freqToNode.erase(minFreq);
            }
            freqToNode[1].push_front(Node(key,value,1));
            keyToNodeIter[key] = freqToNode[1].begin();
            minFreq = 1;
        }
        else
        {
            auto tempNode = keyToNodeIter[key];
            int freq = tempNode->freq;
            freqToNode[freq].erase(tempNode);
            if(freqToNode[freq].size() == 0)
            {
                freqToNode.erase(freq);
                if(minFreq == freq)  
                    ++minFreq;
            }
            freqToNode[freq+1].push_front(Node(key,value,freq+1));
            keyToNodeIter[key] = freqToNode[freq+1].begin();
        }
        
    }
private:
    int cap;
    int minFreq;
    unordered_map<int, list<Node>> freqToNode;
    unordered_map<int, list<Node>::iterator> keyToNodeIter;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */