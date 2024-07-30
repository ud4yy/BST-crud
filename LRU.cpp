#include <bits/stdc++.h>
class LRUCache
{
    //LRU cache with node structure
public:
    class node{
        //node structure, doubly linked list based
        public:
        node *prev;
        node *next;
        int data;
        int key;

        node(int key,int val){
            this->data=val;
            this->key=key;
            prev = nullptr; 
            next = nullptr; 
        }
    };
    //Cache has primary head and tail
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap=0;
    unordered_map<int,node *> mpp;
    
    //init cache by head tail connect thing
     LRUCache(int capacity)
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    //removing node from DLL vanilla
    void Remove(node *n){
            node *p = n->prev;
            node *z = n->next;
            p->next = z;
            z->prev = p;
    }
    //Adding Node next to Head,
     void Add(node *n) {
        n->next = head->next;
        n->prev = head; 
        head->next->prev = n; 
        head->next = n; 
     }
    //if it is present show the data, remove it 
    //and add it to head next, else return -1
    int get(int key)
    {
        if(mpp.find(key)!=mpp.end()){
            node *n = mpp[key];
            int data=n->data;
           // mpp.erase(key);
            Remove(n);
            Add(n);
            mpp[key] = head->next;
            return data;
        }
        return -1;
    }
    //first remove the delete the node if present,
    //if capacity full then remove the lru node
    //add the node to head next
    void put(int key, int value)
    {
        // Write your code here
        if(mpp.find(key)!=mpp.end()){
            node *n = mpp[key];
            Remove(n);
            mpp.erase(key);
        }
        if(mpp.size()==cap){
            node *p=tail->prev;
            mpp.erase(p->key);
            Remove(p);
        }
        node *X = new node(key,value);
        Add(X);
        mpp[key]=head->next;
    }
};
