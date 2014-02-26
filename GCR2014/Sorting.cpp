/////////////
//
//Sorting: https://code.google.com/codejam/contest/2924486/dashboard#s=p2
//
/////////////

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <string>

#define MAX_BOOK_COUNT 2001

using namespace std;

int SortBookIndex(int book[], int bookIndex[], bool bDecrease)
{
	int bookCount = bookIndex[0];
	int selectedBookIndex;

	for (int currentIndex = 1; currentIndex < bookCount; ++currentIndex)
	{
		selectedBookIndex = currentIndex;

		for(int nextIndex = currentIndex + 1; nextIndex <= bookCount ; ++nextIndex)
		{
			if (bDecrease)
			{
				if (book[bookIndex[nextIndex]] > book[bookIndex[selectedBookIndex]] )
				{
					selectedBookIndex = nextIndex;
				}
			}
			else
			{
				if (book[bookIndex[nextIndex]] < book[bookIndex[selectedBookIndex]])
				{
					selectedBookIndex = nextIndex;
				}

			}
		}

		int temp = bookIndex[currentIndex];
		bookIndex[currentIndex] = bookIndex[selectedBookIndex];
		bookIndex[selectedBookIndex] = temp; 
	}
	return 0;
}


int SortBooks(int books[])
{
	int Odd_Index[MAX_BOOK_COUNT + 1];
	int Even_Index[MAX_BOOK_COUNT + 1];
	int Odd_Book_Lable[MAX_BOOK_COUNT + 1];
	int SortedBooks[MAX_BOOK_COUNT+1];

	Odd_Index[0] = Even_Index[0] = Odd_Book_Lable[0] = 0;

	for(int bookIndex = 1;  bookIndex <= books[0] ; bookIndex++)
	{
		if(books[bookIndex] % 2 == 0)
		{
			Even_Index[++Even_Index[0]] = bookIndex;
		}
		else if (abs(books[bookIndex] % 2) == 1 )
		{
			Odd_Index[++Odd_Index[0]] = bookIndex;
			Odd_Book_Lable[++Odd_Book_Lable[0]] = bookIndex;
		}
	}

	SortBookIndex(books, Even_Index, true);
	SortBookIndex(books, Odd_Index, false);

	SortedBooks[0] = books[0];


	int currOdd, currEven;
	currOdd = currEven = 1;

	int OddCount = 0;
	int OddLabelPostion = 1;

	for (int sortedIndex = 1; sortedIndex <= SortedBooks[0]; ++sortedIndex)
	{
		if ( OddCount < Odd_Book_Lable[0])
		{
			if (sortedIndex < Odd_Book_Lable[OddLabelPostion])
			{
		 		SortedBooks[sortedIndex] = books[Even_Index[currEven++]];
			}
			else if(sortedIndex == Odd_Book_Lable[OddLabelPostion])
			{
				SortedBooks[sortedIndex] = books[Odd_Index[currOdd++]];
				OddCount++;
				OddLabelPostion++;
			}
		}
		else
		{
			SortedBooks[sortedIndex] = books[Even_Index[currEven++]];
		}
	}

	for (int i = 0; i < SortedBooks[0]; ++i)
	{
		books[i] = SortedBooks[i];
	}

	return 0;
}




int main(int argc, char* argv[])
{

	int book_Array[2001];

	string inputFile = "C-small-practice.in";
	string outputFile = "C-small-practice.out";

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

 	string str_case_count;
 	std::getline(input,str_case_count);

 	int case_count;
 	case_count = atoi(str_case_count.c_str());

 	string line;
 	int index = 0;

 	int case_number = 1;
 	while(std::getline(input,line))
 	{	
 		book_Array[0] = atoi(line.c_str());
 		std::getline(input,line);

 		stringstream ss(line);
 		string book;

 		int bookIndex = 1;

 		while(getline(ss,book,' '))
 		{
 			book_Array[bookIndex++] = atoi(book.c_str());
 		}

 		SortBooks(book_Array);

 		output <<"Case #"<<case_number++<<":";
 		for (int i = 1; i <= book_Array[0]; ++i)
 		{
 			output<<" "<<book_Array[i];
 		}
 		output<<endl;
 	}


 	input.close();
 	output.flush();
 	output.close();

 	return 0;

}