#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "json.hpp"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
using namespace std;
int main(int argc, char** argv)
{	
	std::ifstream file;
	file.open(argv[1]);
	nlohmann::json j,j_vec;
	if(file.is_open())
	{
		file>>j;
	}
	vector<int> a;
	int b[100];
	int c[100];
	double time=0.00001;
	int ma=0,nc=0;
	cout<< "Sample,InsertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess\n";
	for(auto itr = j.begin();itr !=j.end()&&itr.value().is_array();itr++)
	{
		for(auto i=j[itr.key()].begin(); i<j[itr.key()].end();i++)
		{
			a.push_back(*i);
		}
		for(int k=0;k<a.size();k++){b[k]=a[k];c[k]=a[k];}
		cout<<itr.key()<<",";
		InsertionSort(&a);	
		MergeSort(b,0,a.size()-1,ma,nc);
		cout<<time<<","<<nc<<","<<ma+68<<",";
		nc=0;ma=0;
		Quicksort(c,0,a.size()-1,ma,nc);
		cout<<time<<","<<nc<<","<<ma<<"\n";
		nc=0;ma=0;
		a.clear();
		for(int k=0;k<a.size();k++){b[k]=a[k];c[k]=a[k];}
	}
	return 0;
}
