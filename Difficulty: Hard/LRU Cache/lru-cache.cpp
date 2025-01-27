//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
  
  public:
    LRUCache(int cap) : capacity(cap) {}
    int get(int key) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return cacheMap[key]->second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;
        } else {
            if (cacheList.size() == capacity) {
                auto last = cacheList.back();
                cacheMap.erase(last.first);
                cacheList.pop_back();
            }
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends