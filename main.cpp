
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

int midSquareHash(int key)
{
    long long square = (long long)key * key;

    int middle = (square / 10) % 100;

    return middle % M;
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
