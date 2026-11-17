
/*
    Question 2: Hash Table Project

    PRN: 202501100027
    Seed: 27
    Scenario: Mango Varieties
    Dataset Size: 20
    Hash Table Size: 17
    Hash Function: Mid-Square
    Collision Handling: Separate Chaining
*/

#include <iostream>
using namespace std;
const int M = 17;

struct Node
{
    int key;
    Node* next;
};

Node* hashTable[M] = {nullptr};

int midSquareHash(int key)
{
    long long square = (long long)key * key;

    int middle = (square / 10) % 100;

    return middle % M;
}

void insert(int key)
{
    int index = midSquareHash(key);

    Node* newNode = new Node;

    newNode->key = key;
    newNode->next = nullptr;

    if (hashTable[index] == nullptr)
    {
        hashTable[index] = newNode;
    }
    else
    {
        Node* temp = hashTable[index];

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Inserted " << key
         << " at index " << index << endl;
}

void display()
{
    cout << "\n========== HASH TABLE ==========\n";

    for (int i = 0; i < M; i++)
    {
        cout << "Index " << i << " : ";

        Node* temp = hashTable[i];

        if (temp == nullptr)
        {
            cout << "NULL";
        }

        while (temp != nullptr)
        {
            cout << temp->key;

            if (temp->next != nullptr)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    cout << "================================\n";
}

int main()
{
    int values[20] =
    {
        27, 40, 53, 66, 79,
        92, 5, 18, 31, 44,
        57, 70, 83, 96, 9,
        22, 35, 48, 61, 74
    };
    
    cout << "\nINSERTING ALL DATASET VALUES\n";

    for (int i = 0; i < 20; i++)
    {
        insert(values[i]);
    }

    display();

    cout << "PERSONALIZED DATASET" << endl;
    cout << "PRN: 202501100027" << endl;

    cout << "Dataset: ";

    for (int i = 0; i < 20; i++)
    {
        cout << values[i] << " ";
    }

    cout << "\nHASH FUNCTION TEST\n";

    for (int i = 0; i < 20; i++)
    {
        cout << "Key: " << values[i]
            << " Hash Index: "
            << midSquareHash(values[i]) << endl;
    }

    cout << endl;

    return 0;
}
