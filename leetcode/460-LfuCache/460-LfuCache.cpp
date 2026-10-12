// Last updated: 10/12/2026, 9:54:15 PM
class LFUCache {
private:
    int capacity;
    int minFreq; // Tracks our lowest loyalty tier for instant eviction
    
    // 1. Key -> {Value, Frequency}
    unordered_map<int, pair<int, int>> keyValFreq;
    
    // 2. Frequency Bucket -> Doubly Linked List of Keys (Front = MRU, Back = LRU)
    unordered_map<int, list<int>> freqBuckets;
    
    // 3. Key -> Bookmark (Iterator) pointing to exactly where it is in the bucket
    unordered_map<int, list<int>::iterator> keyIter;

    // Helper: Promotes a key to the next loyalty tier
    void promote(int key) {
        int freq = keyValFreq[key].second;
        
        // 1. Remove from current bucket
        freqBuckets[freq].erase(keyIter[key]);
        
        // 2. If the lowest tier is now empty, the min tier moves up!
        if (freqBuckets[freq].empty() && minFreq == freq) {
            minFreq++;
        }
        
        // 3. Update to new frequency
        int newFreq = freq + 1;
        keyValFreq[key].second = newFreq;
        
        // 4. Put at the FRONT (Most Recently Used) of the new bucket
        freqBuckets[newFreq].push_front(key);
        keyIter[key] = freqBuckets[newFreq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        // If key doesn't exist, return -1
        if (keyValFreq.find(key) == keyValFreq.end()) {
            return -1; 
        }
        
        // Customer bought a coffee! Promote them and return value.
        promote(key);
        return keyValFreq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;
        
        // Case 1: Customer already exists -> Update value and promote
        if (keyValFreq.find(key) != keyValFreq.end()) {
            keyValFreq[key].first = value;
            promote(key);
            return;
        }
        
        // Case 2: Store is FULL -> Kick out the LRU from the lowest tier bucket
        if (keyValFreq.size() == capacity) {
            // Get the person at the back of the minFreq bucket
            int evictKey = freqBuckets[minFreq].back();
            
            // Erase them from all records
            freqBuckets[minFreq].pop_back();
            keyValFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }
        
        // Case 3: Brand new customer
        keyValFreq[key] = {value, 1}; // New customers start at tier 1
        minFreq = 1;                  // Reset the lowest tier tracker to 1
        
        freqBuckets[1].push_front(key);  
        keyIter[key] = freqBuckets[1].begin();
    }
};