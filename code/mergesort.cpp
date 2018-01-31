#include <iostream>
#include "mergesort.h"
using namespace std;

void Merge(int numbers[], int i, int j, int k,int &ma,int &nc) {
   int mergedSize = k - i + 1;                // Size of merged partition
   int mergePos = 0;                          // Position to insert merged number
   int leftPos = 0;                           // Position of elements in left partition
   int rightPos = 0;                          // Position of elements in right partition
   int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary array
   
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
	ma=ma+2;
	nc++;
	if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
	  ma++;
      }
      
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         ma++;
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
	ma++;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
	ma++;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
      ma++;
   }
}

void MergeSort(int numbers[], int i, int k,int &ma,int &nc) {
   int j = 0;
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j,ma,nc);
      MergeSort(numbers, j + 1, k,ma,nc);
      
      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k,ma,nc);
   }
}
