/////////////
//
//Sorting: https://code.google.com/codejam/contest/2924486/dashboard#s=p2
//
/////////////
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Solve()
{
	int book_number, book;
	scanf("%d",&book_number);

	std::vector<int> odd_books;
	std::vector<int> even_books;
	std::vector<int> all_books;

	for (int i = 0; i < book_number; ++i)
	{
		scanf("%d", &book);
		all_books.push_back(book);

		if ( book%2 == 0)
		{
			even_books.push_back(book);
		}
		else
		{
			odd_books.push_back(book);
		}
	}

	sort(odd_books.begin(),odd_books.end());
	sort(even_books.begin(),even_books.end());
	reverse(even_books.begin(), even_books.end());


	int odd_index, even_index;
	odd_index = even_index = 0;

	for (vector<int>::size_type ix = 0 ; ix != all_books.size() ; ++ ix)
	{
		if(all_books[ix] % 2 == 0)
		{
			all_books[ix] = even_books[even_index++];
		}
		else
		{
			all_books[ix] = odd_books[odd_index++];
		}
	}


	for (vector<int>::size_type ix = 0 ; ix != all_books.size() ; ++ ix)
	{
		printf("%d ", all_books[ix]);
	}
	printf("\n");

}


int main(int argc, char const *argv[])
{
	int case_cout;

	scanf("%d",&case_cout);

	for (int i = 0; i < case_cout; ++i)
	{
		printf("Case #%d: ",i+1);
		Solve();
	}

	return 0;
}