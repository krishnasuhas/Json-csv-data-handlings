#include <iostream>
using namespace std;

int Partition(int numbers[], int i, int k,int &ma,int &nc) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   int pivot = 0;
   int temp = 0;
   bool done = false;
   
   /* Pick middle element as pivot */
   midpoint = i + (k - i) / 2;
   pivot = numbers[midpoint];
   ma++;
   l = i;
   h = k;
   
   while (!done) {
      
      /* Increment l while numbers[l] < pivot */
      while (numbers[l] < pivot) {
         ++l;
	ma++;
	nc++;
      }
      ma++;
      nc++;
      /* Decrement h while pivot < numbers[h] */
      while (pivot < numbers[h]) {
         --h;
	ma++;
	nc++;
      }
      ma++;
	nc++;
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
         /* Swap numbers[l] and numbers[h],
          update l and h */
         temp = numbers[l];
         numbers[l] = numbers[h];
         numbers[h] = temp;
      	ma=ma+4;   
         ++l;
         --h;
      }
   }
   
   return h;
}

void Quicksort(int numbers[], int i, int k,int&ma,int &nc) {
   int j = 0;
   
   /* Base case: If there are 1 or zero elements to sort,
    partition is already sorted */
   if (i >= k) {
      return;
   }
   
   /* Partition the data within the array. Value j returned
    from partitioning is location of last element in low partition. */
   j = Partition(numbers, i, k,ma,nc);
   
   /* Recursively sort low partition (i to j) and
    high partition (j + 1 to k) */
   Quicksort(numbers, i, j,ma,nc);
   Quicksort(numbers, j + 1, k,ma,nc);
   
   return;
}
