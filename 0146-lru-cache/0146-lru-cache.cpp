class LRUCache {
    int capacity;
    list<pair<int,int>> cacheList;
    unordered_map<int,list<pair<int,int>>::iterator> cacheMap;

    void moveToFront(list<pair<int,int>>::iterator it){
        cacheList.splice(cacheList.begin(),cacheList,it);
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if(it == cacheMap.end()){
            return -1;
        }
        moveToFront(it->second);

        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);

        if(it != cacheMap.end()){
            it->second->second = value;
            moveToFront(it->second);
            return;
        }
        if(cacheList.size() == capacity){
            auto lru = cacheList.back();
            cacheMap.erase(lru.first);
            cacheList.pop_back();
        }

        cacheList.push_front({key,value});
        cacheMap[key] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */