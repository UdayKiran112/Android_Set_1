#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class MyHashMap
{
private:
    static const int BUCKET_SIZE = 1009;
    vector<pair<int, int>> table[BUCKET_SIZE];

    int hash(int key)
    {
        return key % BUCKET_SIZE;
    }

public:
    MyHashMap() {}

    void put(int key, int value)
    {
        int idx = hash(key);
        for (auto &p : table[idx])
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }
        table[idx].emplace_back(key, value);
    }

    int get(int key)
    {
        int idx = hash(key);
        for (auto &p : table[idx])
        {
            if (p.first == key)
                return p.second;
        }
        return -1;
    }

    void remove(int key)
    {
        int idx = hash(key);
        auto &bucket = table[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if (it->first == key)
            {
                bucket.erase(it);
                return;
            }
        }
    }
};

int main()
{
    MyHashMap obj;
    string line;

    while (getline(cin, line))
    {
        if (line == "exit;" || line == "exit")
            break;

        if (line.find("put") != string::npos)
        {
            int key, value;
            sscanf(line.c_str(), "obj.put(%d, %d);", &key, &value);
            obj.put(key, value);
        }
        else if (line.find("get") != string::npos)
        {
            int key;
            sscanf(line.c_str(), "obj.get(%d);", &key);
            cout << obj.get(key) << endl;
        }
        else if (line.find("remove") != string::npos)
        {
            int key;
            sscanf(line.c_str(), "obj.remove(%d);", &key);
            obj.remove(key);
        }
        // Ignore "MyHashMap obj;" and empty lines
    }

    return 0;
}
