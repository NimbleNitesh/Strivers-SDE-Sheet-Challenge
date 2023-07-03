#include <list>
#include <map>
#include <unordered_map>
class LRUCache
{
public:
    list<int> doubly_linked_list;
    int n;
    map<int, list<int>::iterator> store;
    unordered_map<int, int> full;

    LRUCache(int capacity)
    {
        // Write your code here
        n=capacity;
    }

    int get(int key)
    {
        // Write your code here
        if(store.find(key)!=store.end())
        {
            doubly_linked_list.erase(store[key]);
            doubly_linked_list.push_front(key);
            store[key]=doubly_linked_list.begin();
            return full[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(store.find(key)!=store.end())
        {
            doubly_linked_list.erase(store[key]);
            doubly_linked_list.push_front(key);
            store[key]=doubly_linked_list.begin();
            full[key]=value;
            return;
        }
        int cur_size=doubly_linked_list.size();
        if(cur_size==n)
        {
            int lru_key=doubly_linked_list.back();
            doubly_linked_list.pop_back();
            full.erase(full.find(lru_key));
            store.erase(store.find(lru_key));
        }
        full[key]=value;
        doubly_linked_list.push_front(key);
        store[key]=doubly_linked_list.begin();

    }
};
