#include <iostream>
#include <unordered_map>
#include <list>
#include <sstream>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> usage;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        usage.erase(cache[key].second);
        usage.push_front(key);
        cache[key].second = usage.begin();
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            usage.erase(cache[key].second);
        } else if (cache.size() == capacity) {
            int lru = usage.back();
            usage.pop_back();
            cache.erase(lru);
        }
        usage.push_front(key);
        cache[key] = {value, usage.begin()};
    }
};

int main() {
    string line;
    LRUCache* lru = nullptr;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        // Trim whitespace
        while (!line.empty() && isspace(line.back())) line.pop_back();

        if (line == "exit;" || line == "exit") break;

        if (line.find("LRUCache") != string::npos) {
            int capStart = line.find('(') + 1;
            int capEnd = line.find(')');
            int capacity = stoi(line.substr(capStart, capEnd - capStart));
            lru = new LRUCache(capacity);
        } else if (line.find("put") != string::npos) {
            int argStart = line.find('(') + 1;
            int argEnd = line.find(')');
            string args = line.substr(argStart, argEnd - argStart);
            int comma = args.find(',');
            int key = stoi(args.substr(0, comma));
            int value = stoi(args.substr(comma + 1));
            lru->put(key, value);
        } else if (line.find("get") != string::npos) {
            int argStart = line.find('(') + 1;
            int argEnd = line.find(')');
            int key = stoi(line.substr(argStart, argEnd - argStart));
            cout << lru->get(key) << endl;
        }
    }

    delete lru;
    return 0;
}
