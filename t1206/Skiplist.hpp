#include<random>
#include <cstring>
#include<limits.h>
#include<iostream>

using namespace std;

#define SKIPLIST_MAXLEVEL 16
#define SKIPLIST_P 0.25

typedef struct SkipListNode {
    int  val;
    struct SkipListLevel  
    {
        // int span;
        struct SkipListNode *forward;
    } level[];
    SkipListNode (int _val, int sz=SKIPLIST_MAXLEVEL) 
        : val(_val)
    {
        SkipListNode* level = (SkipListNode*)malloc(sz*sizeof(SkipListLevel));
        memset(level, 0, sz * sizeof(SkipListLevel));
    }
} SkipListNode;



class Skiplist {
public:
    Skiplist() 
        :level(0),
        head(nullptr),
        tail(nullptr) 
    {
        tail = new SkipListNode(INT_MAX, 0);
        head = new SkipListNode(INT_MAX);
        for (int i = 0; i < SKIPLIST_MAXLEVEL; ++i) { 
        	head->level[i].forward = nullptr;
        }
    }

    bool search(int target) 
    {
        // int rank[SKIPLIST_MAXLEVEL];
        // struct SkipListNode* update[SKIPLIST_MAXLEVEL];
        struct SkipListNode* curNode = head;
        int curLevel = level;
        for (int curLevel = level-1; curLevel >=0; curLevel--)
        {
            
            while (curNode->level[curLevel].forward &&
                    curNode->val < target  )
            {
                curNode = curNode->level[curLevel].forward;
            }
            if (curNode->val==target)
                return true;
        }
        return false;
    }
    
    void add(int num) 
    {
        int curLevel, rLevel = randomLevel();
        if(rLevel > level)
        {
            level++ ;
            curLevel = level;
        }
        else
        {
            curLevel = rLevel;
        }
        SkipListNode *curNode = new SkipListNode(num, curLevel);

        struct SkipListNode* x = head;
        for (int i = 0; i <curLevel ; i++)
        {
            while (x->level[i].forward &&
                    x->level[i].forward->val <= num)
            {
                x = x->level[i].forward;
                
            }
            curNode->level[i].forward = x->level[i].forward;  
            x->level[i].forward = curNode;
        }
    }
    
    bool erase(int num) {
        return false;
    }
    int randomLevel(){
        int level = 1;
        while ((random() & 0xFFFF) < (SKIPLIST_P * 0xFFFF)) 
            ++level;
        return (level < SKIPLIST_MAXLEVEL) ? level : SKIPLIST_MAXLEVEL;
    }

private:
    struct SkipListNode  *head, *tail;
    int level;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */