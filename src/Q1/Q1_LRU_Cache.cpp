#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

class LRUCache
{
private:
    int capacity;
    list<int> usage;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        usage.erase(cache[key].second);
        usage.push_front(key);
        cache[key].second = usage.begin();
        return cache[key].first;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            usage.erase(cache[key].second);
        }
        else if (cache.size() == capacity)
        {
            int lru = usage.back();
            usage.pop_back();
            cache.erase(lru);
        }
        usage.push_front(key);
        cache[key] = {value, usage.begin()};
    }
};

int main()
{
    string line;
    LRUCache *lru = nullptr;

    while (getline(cin, line))
    {
        // Remove spaces
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());

        if (line == "exit;" || line == "exit")
            break;

        if (line.find("LRUCache") != string::npos)
        {
            // Format: LRUCachelru(2);
            int start = line.find('(') + 1;
            int end = line.find(')');
            int capacity = stoi(line.substr(start, end - start));
            lru = new LRUCache(capacity);
        }
        else if (line.find("lru.put") != string::npos)
        {
            // Format: lru.put(1,1);
            int start = line.find('(') + 1;
            int end = line.find(')');
            string args = line.substr(start, end - start);
            int comma = args.find(',');
            int key = stoi(args.substr(0, comma));
            int value = stoi(args.substr(comma + 1));
            lru->put(key, value);
        }
        else if (line.find("lru.get") != string::npos)
        {
            // Format: lru.get(1);
            int start = line.find('(') + 1;
            int end = line.find(')');
            int key = stoi(line.substr(start, end - start));
            cout << lru->get(key) << endl;
        }
    }

    delete lru;
    return 0;
}
