#include "algorithms.h"

using namespace std;
int Search(HashTable* URL[], string url, int HASHTABLESIZE)
{
    int hashValue = HashFunction_Div(url, HASHTABLESIZE); //gọi hash function để tạo hash value
    
    int valueLinear = 1;
    while (URL[hashValue]->key != url && valueLinear < HASHTABLESIZE)
    {
        hashValue = (hashValue + valueLinear) % HASHTABLESIZE;
        valueLinear++;
    }
    if (URL[hashValue]->key == url)
        return hashValue;
    return -1;
}
//va cham
int CollisionResolutionInsert_VC(HashTable* URL[], int hashValue, int prime, int& step, bool& check)
{
    while (URL[hashValue]->check)
    {
        check = true;
        step++;
        hashValue = (hashValue + 1) % prime;
    }
    return hashValue;
}
void Insert_VC(HashTable* URL[], string url, int prime, double& max, double& min, double& sum, int& sum_a)
{
    int hashValue = HashFunction_Div(url, prime);

    int step = 0;
    bool check = false;
    hashValue = CollisionResolutionInsert_VC(URL, hashValue, prime, step, check);

    sum += step;
    if (step > max)
        max = step;
    if (step < min && step>0)
        min = step;
    if (check)
        sum_a++;

    URL[hashValue]->check = true;
    URL[hashValue]->key = url;
    //Tìm url cha
    string url2 = url;
    url2.erase(url2.rfind('/'), url.length());//url2 là url phân cấp trước nó
    int indexParent = Search(URL, url2, prime); //tìm index cha

    if (indexParent >= 0 && URL[indexParent]->check)
    {
        Node* temp = URL[indexParent]->headNext;
        if (temp == nullptr)
        {
            temp = new Node();
            temp->next = nullptr;
            temp->index = hashValue;
            URL[indexParent]->headNext = temp;
        }
        else
        {
            while (temp->next != nullptr) temp = temp->next;
            Node* node = new Node();
            node->next = nullptr;
            node->index = hashValue;
            temp->next = node;
        }
        URL[hashValue]->prev = indexParent;
    }
}