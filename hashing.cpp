#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable {
private:
    int size; // ukuran tabel hash
    vector<string> table; // tabel hash

public:
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    int hashFunction(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash += key[i];
        }
        return hash % size;
    }

    void insert(string key, string value) {
        int index = hashFunction(key);
        table[index] = value;
    }

    string get(string key) {
        int index = hashFunction(key);
        return table[index];
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    hashTable.insert("apple", "buah");
    hashTable.insert("banana", "pisang");
    hashTable.insert("orange", "jeruk");

    cout << "Get value for key 'apple': " << hashTable.get("apple") << endl;
    cout << "Get value for key 'banana': " << hashTable.get("banana") << endl;
    cout << "Get value for key 'orange': " << hashTable.get("orange") << endl;

    hashTable.display();

    return 0;
}
