class LRUCache {
    list<pair<int,int>>lru;
    map<int,list<pair<int,int>>::iterator>mp;
    int size;
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        int value=-1;
        if(mp.find(key)!=mp.end())
        {
            auto it=mp[key];
            value=it->second;
            lru.erase(it);
            lru.push_front({key,value});
            mp[key]=lru.begin();
        }
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            auto it=mp[key];
            lru.erase(it);
            lru.push_front({key,value});
            mp[key]=lru.begin();
        }
        else{
            lru.push_front({key,value});
            mp[key]=lru.begin();

            
        }

        if(lru.size()>size)
        {
            auto it=lru.back();
            lru.pop_back();
            mp.erase(it.first);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */