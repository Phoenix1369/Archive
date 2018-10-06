struct Node {
    int key, stmp;
    Node* next;
};

class LRUCache {
    unordered_map<int,int> cache, times;
    Node* head;
    Node* tail;
    int cap, t;
    
    void build(int key) {
        if (head == nullptr) {
            head = tail = new Node { key, times.at(key), nullptr };
        } else {
            tail->next = new Node { key, times.at(key), nullptr };
            tail = tail->next;
        }
    }
    
    void flush() {
        while (head && ((int)cache.size() > cap)) {
            int key = head->key;

            if (head->stmp == times.at(key)) {
                cache.erase(key);
                times.erase(key);
            }
            Node* node = head;
            head = head->next;
            delete node;
        }
    }
    
public:
    LRUCache(int capacity) {
        cache.clear();
        times.clear();
        head = tail = nullptr;
        cap = capacity;
        t = 0;
    }
    
    int get(int key) {
        flush();
        
        if (!cache.count(key)) {
            return -1;
        }
        times[key] = t++;
        
        build(key);
        return cache.at(key);
    }
    
    void put(int key, int value) {
        cache[key] = value;
        times[key] = t++;
        
        build(key);
        flush();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
