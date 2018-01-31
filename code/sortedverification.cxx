#include<iostream>
#include<fstream>
#include "json.hpp"
#include<string>
using namespace std;
int main(int argc, char** argv) {

	std::ifstream file;
	file.open(argv[1]);
	nlohmann::json j,jout;
	if(file.is_open())
	{
		file>>j;
	}
	int samplesWithInversions=0;
	int init=1;
	int count=0;
	for(auto itr = j.begin();itr !=j.end();itr++)
	{
		if(itr.value().is_array())
		{
			for(auto i=j[itr.key()].begin(); i<j[itr.key()].end()-1;i++)
			{	
				if(*i>*(i+1))
				{
					std::vector<int> c_vector {*i, *(i+1)};
  					nlohmann::json j_vec(c_vector);
					jout[itr.key()]["ConsecutiveInversions"][std::to_string(count)]=j_vec;		
					if(init){jout[itr.key()]["sample"]=j[itr.key()];init=0;samplesWithInversions++;}
				}
				count++;
			}
			count=0;
			init=1;
		}
	}
	jout["metadata"] = j["metadata"];
	jout["metadata"]["file"]=argv[1];
	jout["metadata"]["samplesWithInversions"]=samplesWithInversions;
	cout<<jout;
	return 0;
}
