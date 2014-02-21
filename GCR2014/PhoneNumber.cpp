////
//
// Question at:https://code.google.com/codejam/contest/2924486/dashboard
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

string rules[] = {"","","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple","test11"};
string numbers[] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten"};


int ParsePhoneNumber(string phone,string format, string& output)
{
	//Split the format string by '-'
	std::vector<string> fmts;
	std::string item;

	std::stringstream  ss(format);
	while(std::getline(ss,item,'-'))
	{
		if (!item.empty())
		{
			fmts.push_back(item);
		}
	}

	output = " ";

	int startIndex = 0;
	int endIndex = 0;
	for (int i = 0; i < fmts.size(); ++i)
	{
		int readCount = atoi(fmts[i].c_str());
		int repeateCount = 1;
		endIndex = startIndex + readCount;

		char curChar = '\0';
		char nextChar = '\0';

		for (int index = startIndex; index < endIndex ; ++index)
		{
			curChar = phone[index];
			if ( index + 1 < endIndex )
			{
				nextChar = phone[index + 1];

				if (nextChar == curChar && repeateCount <= 9)
				{
					repeateCount++;
					continue;
				}
				else
				{
					if(repeateCount > 1)
					{
						output.append(rules[repeateCount]);
						output.append(" ");
						repeateCount = 1;
					}
				}
			}
			else
			{
				if(repeateCount > 1)
				{
					output.append(rules[repeateCount]);
					output.append(" ");
					repeateCount = 1;
				}
			}

			output.append(numbers[atoi(&curChar)]);
			output.append(" ");
		}


		startIndex += readCount;
	}

	return 0;
}



int main(int argc, char* argv[])
{
	string inputFile = "A-large-practice.in";
	string outputFile = "A-large-practice.out";

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

    string phone_number, format;
   	string phone_output;

   	int i = 1;
    while( i <= case_number)
    {
    	input >> phone_number >> format;
    	ParsePhoneNumber(phone_number,format,phone_output);

    	output<<"Case #"<<i<<":"<<phone_output<< endl;
    	i++;
    }

    input.close();
    output.flush();
    output.close();

}