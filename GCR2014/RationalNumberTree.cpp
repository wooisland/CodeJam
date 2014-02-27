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


int RationalNumber(unsigned long long location, unsigned long long&p, unsigned long long &q)
{
	if (location == 1)
	{
		p = q = 1;
	}
	else
	{
		unsigned long long parentP, parentQ;
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

int RationalLocation(unsigned long long p, unsigned long long q, unsigned long long &location)
{

	location = 0;
	unsigned long long preLocation;

	if (p < q)
	{
		RationalLocation(p, q - p, preLocation);

		location = 2 * preLocation;
	}
	else if ( p > q)
	{
		RationalLocation(p - q, q, preLocation);

		location = 2 * preLocation + 1;
	}
	else if ( p == q)
	{
		location = 1;
	}

	return 0;
}

void Solve()
{
	unsigned long long input_number;
	scanf("%llu", &input_number);

	unsigned long long postion, p, q;
	
	if (input_number == 1)
	{
		scanf("%llu", &postion);
		RationalNumber(postion, p, q);
		printf("%llu %llu", p, q);
	
	}
	else if (input_number == 2)
	{
		scanf("%llu", &p);
		scanf("%llu", &q);
		RationalLocation(p,q,postion);
		printf("%llu", postion);
	}
}

int main(int argc, char* argv[])
{
	int case_count;

	scanf("%d", &case_count);

	for (int i = 0; i < case_count; ++i)
	{
		printf("Case #%d: ", i + 1);
		Solve();
		printf("\n");
	}

}
