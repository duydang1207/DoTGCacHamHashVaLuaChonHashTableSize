#pragma once
#include "dataStructure.h"

int Search(HashTable* URL[], string url, int HASHTABLESIZE);

//va cham
int CollisionResolutionInsert_VC(HashTable* URL[], int hashValue, int prime, int& step, bool& check);
void Insert_VC(HashTable* URL[], string url, int prime, double& max, double& min, double& sum, int& sum_a);
