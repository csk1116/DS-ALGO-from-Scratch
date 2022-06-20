/*
we can use different technique to avoid hash collision.
This program use prime number as hash table's length to reduce the chances of collision.
Details are refer to: 
https://medium.com/swlh/why-should-the-length-of-your-hash-table-be-a-prime-number-760ec65a75d1

As result, using prime is not enough to avoid collision. 

another method using chaning and open addressing to resolve collision is refer to:
http://alrightchiu.github.io/SecondRound/hash-tableintrojian-jie.html
*/
#include <iostream>
#include <list>
using namespace std;

class HashTable
{
private:
    int capacity;
    list<int>* table;
    int hashFunction(int key)
    {
        cout << "hash index: " << key % capacity << endl;
        return (key % capacity);
    }
    int getNearestPrime(int num)
    {        
        while(!isPrime(num))
        {
            num++;
        }
        return num;
    }
    bool isPrime(int num)
    {
        if(num < 2)
            return false;
        for(int i = 2; i * i <= num; i++)
        {
            if(num % i == 0)
                return false;
        }
        return true;
    }
    int emptyCode = 999; 
public:
    HashTable(int size);
    ~HashTable();
    void insertItem(int key, int value);
    void deleteItem(int key, int value);
    void displayHash();
    int& operator[](int key);
};

HashTable::HashTable(int size)
{
    int primeSize = getNearestPrime(size);
    this->capacity = primeSize;
    table = new list<int>[capacity];
    cout << "hash table capacity: " << this->capacity << endl;
}

HashTable::~HashTable()
{
    delete [] table;
    cout << "deconstructed" << endl;
}

void HashTable::insertItem(int key, int value)
{
    int index = hashFunction(key);
    table[index].push_back(value);
}

void HashTable::deleteItem(int key, int value)
{
    int index = hashFunction(key);    
    list<int>::iterator it;
    for(it = table[index].begin(); it != table[index].end(); it++)
    {
        if(*it == value)
            break;  
    }

    if(it != table[index].end())
    {
        table[index].erase(it);
        cout << "key: " << key << ", value: " << value << " is successfully deleted" << endl;
    }
        
    else
        cout << "this key is not in the table" << endl;    
}

void HashTable::displayHash()
{
    for(int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        for(auto item: table[i])
            cout << " --> " << item;
        cout << endl;
    }
}

int& HashTable::operator[](int key)
{
    int index = hashFunction(key);
    if(table[index].empty())
    {
        cout << "this key is not in the table." << endl;
        return emptyCode;
    }        
    list<int>::iterator it;
    it = table[index].begin();
    return *it;
}

int main()
{       
    int key[] = {17, 23, 6, 8, 0 ,19, 20, 11};       
    int value[] = {1, 1, 2, 3, 4, 0, 0, 9};
    int size = sizeof(key) / sizeof(key[0]);    

    HashTable myHashTable(size);

    for(int i = 0; i < size; i++)
    {        
        cout << "insert key: " << key[i] << ", value: " << value[i] << endl;    
        myHashTable.insertItem(key[i], value[i]);    
    }

    myHashTable.displayHash();

    cout << myHashTable[23] << endl;
    
    myHashTable.deleteItem(23, 1);
    myHashTable.deleteItem(23, 1);

    myHashTable.displayHash();

    cout << myHashTable[23] << endl;
    return 0;
}