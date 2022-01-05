#include "dataStructure.h"


int HashFunction_Div(string url, int HASHTABLESIZE)
{
    int hashValue = 0;
    for (int i = 0; i < url.length(); i++)
        hashValue += url[i] * i;
    return hashValue % HASHTABLESIZE;
}
int HashFunction_Mul(string url, int HASHTABLESIZE)
{
    double hashValue = 0;
    for (int i = 0; i < url.length(); i++)
        hashValue += url[i];
    double temp = hashValue * 0.618033987;
    int temp1 = temp;
    hashValue = temp - temp1;
    hashValue= (double)HASHTABLESIZE * hashValue;
    return hashValue;
}

int CollisionResolutionInsert(HashTable* URL[], int hashValue, int HASHTABLESIZE)
{
    while (URL[hashValue]->check)
    {
        hashValue = (hashValue + 1) % HASHTABLESIZE;
    }
    return hashValue;
}
