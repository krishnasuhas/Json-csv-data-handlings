#include<iostream>
#include<fstream>
#include "json.hpp"
#include<string>
using namespace std;
int main(int argc, char** argv) {

	std::ifstream file1,file2;
	file1.open(argv[1]);
	file2.open(argv[2]);
	nlohmann::json j1,j2,jout;
	if(file1.is_open())file1>>j1;
	if(file2.is_open())file2>>j2;
	int samplesWithConflicts=0;
	int init=1;
	int count=0;
	for(auto itr1 = j1.begin(),itr2 = j2.begin();itr1 !=j1.end(),itr2 !=j2.end();itr1++,itr2++)
	{
		if(itr1.value().is_array()&&itr2.value().is_array()&&itr1.key()==itr2.key())
		{
			for(auto i1=j1[itr1.key()].begin(),i2=j2[itr2.key()].begin(); i1<j1[itr1.key()].end(),i2<j2[itr2.key()].end();i1++,i2++)
			{	
				if(*i1!=*i2)
				{
					std::vector<int> c_vector {*i1, *i2};
  					nlohmann::json j_vec(c_vector);
					jout[itr1.key()]["Mismatches"][std::to_string(count)]=j_vec;
					if(init)
					{
						jout[itr1.key()]["sample1"]=j1[itr1.key()];
						jout[itr1.key()]["sample2"]=j2[itr2.key()];
						init=0;
						samplesWithConflicts++;
					}
				}
				count++;
			}
			count=0;
			init=1;
		}
	}
	jout["metadata"]["samplesWithConflictingResults"] = samplesWithConflicts;
	jout["sample1"]["metadata"]=j1["metadata"];
	jout["sample2"]["metadata"]=j2["metadata"];
	jout["sample1"]["metadata"]["file"]=argv[1];
	jout["sample2"]["metadata"]["file"]=argv[2];
	cout<<jout;
	return 0;
}
