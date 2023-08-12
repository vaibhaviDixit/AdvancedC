/*
Write a CPP program for handling of collision via open addressing Method-Double Hashing.

Input: values={19, 27, 36, 10, 64}, table_size=11

Output:
Enter a key that you want to search 36
36 found
The hash table looks like:
0
1
2
3 --> 36
4
5 --> 27
6
7
8 --> 19
9 --> 64
10 --> 10


*/

#include <bits/stdc++.h>
using namespace std;

// Predefining the size of the hash table.
#define SIZE_OF_TABLE 11

// Used for the second hash table.
// 8 and 11 are coprime numbers.
#define CO_PRIME 8

// Defining the hashTable vector.
vector<int> hashTable(SIZE_OF_TABLE);

class DoubleHash
{
    int size;

public:
    // To check whether the table is full or not.
    bool isFull()
    {
        // In case the table becomes full.
        return (size == SIZE_OF_TABLE);
    }

    // Calculating the first hash.
    int hash1(int key)
    {
        return (key % SIZE_OF_TABLE);
    }

    // Calculating the second hash.
    int hash2(int key)
    {
        return (CO_PRIME - (key % CO_PRIME));
    }

    DoubleHash()
    {
        size = 0;
        for (int i = 0; i < SIZE_OF_TABLE; i++)
            hashTable[i] = -1;
    }

    // Function for inserting a key into the hash table.
    void insertHash(int key)
    {
        // We first check whether the hash is full or not.
        if (isFull())
            return;

        // Obtaining the index from the first hash table.
        int index = hash1(key);

        // In case a collision occurs.
        if (hashTable[index] != -1)
        {
            // Obtaining the index from second hash table.
            int index2 = hash2(key);
            int i = 1;
            while (1)
            {
                // Obtaining the new index.
                int newIndex = (index + i * index2) % SIZE_OF_TABLE;

                //If no collision occurs, the key is stored.
                if (hashTable[newIndex] == -1)
                {
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        }

        //If no collision occurs, the key is stored.
        else
            hashTable[index] = key;
        size++;
    }

    // For searching a key in the hash table.
    void search(int key)
    {
        int i1 = hash1(key);
        int i2 = hash2(key);
        int i = 0;
        while (hashTable[(i1 + i * i2) % SIZE_OF_TABLE] != key)
        {
            if (hashTable[(i1 + i * i2) % SIZE_OF_TABLE] == -1)
            {
                cout << key << " does not exist" << endl;
                return;
            }
            i++;
        }
        cout << key << " found" << endl;
    }

    // For displaying the complete hash table.
    void displayHash()
    {
        for (int i = 0; i < SIZE_OF_TABLE; i++)
        {
            if (hashTable[i] != -1)
                cout << i << " --> "
                     << hashTable[i] << endl;
            else
                cout << i << endl;
        }
    }
};


int main()
{
    // Assuming the number of initial values to be 5.
    int n = 5, i, k;
    int a[100];

    // We first need to insert keys into the table.
    DoubleHash hash;
    cout << "Enter 5 values: \n";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        hash.insertHash(a[i]);
    }

    // First, we search for a key that is present in the table.
    cout << "Enter a key that you want to search \n";
    cin >> k;
    hash.search(k);

    // Lets display the hash table.
    // Since we took the SIZE_OF_TABLE as 11 we will get the indices from 0-10.
    cout << "\n The hash table looks like:\n";
    hash.displayHash();
    return 0;
}

/*
This C++ program demonstrates the implementation of double hashing as a method for handling collisions in a hash table.

The program defines a class named DoubleHash that encapsulates the functionality of the double hashing technique.
It includes two hash functions (hash1 and hash2) for calculating the indices in the hash table.
The hash table is represented by a vector named hashTable with a predefined size SIZE_OF_TABLE.
The isFull function checks whether the hash table is full.
The insertHash function inserts a given key into the hash table using double hashing to handle collisions.
The search function searches for a specific key in the hash table.
The displayHash function displays the entire hash table.
The main function initializes the DoubleHash object, inserts keys into the hash table, searches for a specific key,
and then displays the hash table.

*/

