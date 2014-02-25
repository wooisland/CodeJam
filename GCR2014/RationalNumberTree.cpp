////
//
//  Question:https://code.google.com/codejam/contest/2924486/dashboard#s=p1
//
////

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

#include <string>

using namespace std;


int RationalNumber(long location, long&p, long &q)
{
	if (location == 1)
	{
		p = q = 1;
	}
	else
	{
		long parentP, parentQ;
		RationalNumber(location/2, parentP, parentQ);

		if (location % 2 == 0)
		{
			p = parentP;
			q = parentP + parentQ;
		}
		else
		{
			p = parentP + parentQ;
			q = parentQ;
		}
	}

	return 0;
}

int RationalLocation(long p, long q, long &location)
{
	location = 0;

	long currentP, currentQ;

	do
	{
		location++;
		RationalNumber(location,currentP,currentQ);
	}
	while(currentP != p || currentQ != q);

	return 0;
}

int main(int argc, char* argv[])
{

	string inputFile = "B-large-practice.in";
	string outputFile = "B-large-practice.out";

	switch(argc)
	{
		case 2:
			inputFile = string(argv[1]);
			break;
		case 3:
			inputFile = string(argv[1]);
			outputFile = string(argv[2]);
			break;
		default:
			break;
	}

	ifstream input;
	input.open(inputFile);

	ofstream output;
	output.open(outputFile);

	if (!input)
	{
		cerr<< "error:unable to open input file" << inputFile << endl;
		return -1;
	}

	string str_case_number;
	input >> str_case_number;

	int case_number = atoi(str_case_number.c_str());
    string s;

    string var1, var2;
   	string inputCount;


   	long p, q;
   	long location;


   	int i = 1;
    while( i <= case_number)
    {
    	input >> inputCount;

    	if ( atoi(inputCount.c_str()) == 1)
    	{
    	 	input >> var1;
    	 	RationalNumber(atoi(var1.c_str()), p, q);
    	 	output << "Case #" << i << ": "<< p <<" " << q << endl ;

    	}
    	else if ( atoi(inputCount.c_str()) == 2)
    	{
    		input >> var1 >> var2;
    		RationalLocation(atoi(var1.c_str()), atoi(var2.c_str()), location);
    		output << "Case #" << i << ": " << location << endl;
    	}
    	i++;
    }

    input.close();
    output.flush();
    output.close();

}
