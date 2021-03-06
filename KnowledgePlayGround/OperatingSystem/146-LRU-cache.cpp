//
// Created by linjliang on 2020/9/18.
//

/*
 * 运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制。
 * 它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key)
- 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。

写入数据 put(key, value)
- 如果关键字已经存在，则变更其数据值；
- 如果关键字不存在，则插入该组「关键字/值」。
  当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

进阶:
你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 // 缓存容量  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得关键字 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得关键字 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
 */

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int m_capacity;
    list<pair<int,int>> recent_list;                         // (key, value)
    unordered_map<int,list<pair<int,int>> ::iterator> mp;    // key : pos
public:
    LRUCache(int capacity):m_capacity(capacity) { }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        int val = mp[key]->second;
        put(key,val);
        return val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()){
            auto pos = mp[key];
            recent_list.erase(pos);
        }
        else if (recent_list.size() >= m_capacity){
            mp.erase(recent_list.back().first);
            recent_list.pop_back();
        }

        recent_list.push_front( {key,value} );
        mp[key] = recent_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout<<cache.get(1)<<endl;
    cache.put(3,3);
    cout<<cache.get(2)<<endl;
    cache.put(4,4);
    cout<<cache.get(1)<<endl;
    cout<<cache.get(3)<<endl;
    cout<<cache.get(4)<<endl;
}

/*
 * Note:
 *
 * 注意在get访问时，若数据存在，需要将其删掉，再重新插入链表头部 （因为其是最近访问的数据
 */