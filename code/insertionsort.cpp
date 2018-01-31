// Insertion Sort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks
#include<iostream>
#include "insertionsort.h"
#include<ctime>
using namespace std;
void InsertionSort(std::vector<int>* numbers) {
   clock_t t1,t2;
   t1=clock();
   int nc=0;
   int ma=0;
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 1; i < numbers->size(); ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
         
         // Swap numbers[j] and numbers[j - 1]
         temp = (*numbers)[j];
         (*numbers)[j] = (*numbers)[j - 1];
         (*numbers)[j - 1] = temp;
         --j;
	nc++;
	ma=ma+6;
      }
	nc++;
	ma=ma+2;
   }
   t2=clock();
   double sec=double(t2-t1)/ CLOCKS_PER_SEC;
   cout<<sec<<","<<nc<<","<<ma<<",";
   return;
}
