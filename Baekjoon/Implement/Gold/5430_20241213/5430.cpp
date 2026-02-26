#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string	p; // function to arr
int n; // # of arr
string	sArr; // string of array
vector<int>	vArr; // vector of array

int main(void)
{
	int		T;
	char	*token;
	int		s, e; // two pointer for arr
	int		currPoint;

/* test case */
	cin >> T;
	for (int t = 0; t < T; t++)
	{
	/* clear data */
		vArr.clear();

	/* input data */
		cin >> p >> n >> sArr;

		vArr.reserve(n);
		token = strtok(const_cast<char *>(sArr.c_str()), "[,]");
		while (token != NULL)
		{
			vArr.push_back(atoi(token));
			token = strtok(NULL, "[,]");
		}

	/* do function */
		s = 0;
		e = n - 1;
		currPoint = s;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				if (currPoint == s)
					currPoint = e;
				else if (currPoint == e)
					currPoint = s;
			}
			else if (p[i] == 'D')
			{
				if (s > e)
				{
					cout << "error\n";
					currPoint = -2;
					break ;
				}
				else if (currPoint == s)
					currPoint = ++s;
				else if (currPoint == e)
					currPoint = --e;
			}
		}

	/* print result */
		if (currPoint == -2)
			continue ;

		std::cout << "[";
		if (currPoint == s)
		{
			for (int i = s; i <= e; i++)
			{
				if (i != e)
					std::cout << vArr[i] << ',';
				else
					std::cout << vArr[i];
			}
		}
		else if (currPoint == e)
		{
			for (int i = e; i >= s; i--)
			{
				if (i != s)
					std::cout << vArr[i] << ',';
				else
					std::cout << vArr[i];
			}
		}
		std::cout << "]\n";
	}

	return (0);
}
