#include <iostream>
#include <string> // string type
#include <vector> // vector

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int T;
	int i;
	std::string str;
	std::vector<char> stack;

	/* Set initial input */
	std::cin >> T;

	/* Find result in each case */
	for (int test_case = 1; test_case <= T; test_case++)
	{
		/* Set str */
		str.clear();
		stack.clear();
		std::cin >> str;

		/* Read string and push,pop stack */
		for (i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
				stack.push_back('(');
			else if (str[i] == ')')
			{
				if (stack.size() > 0)
					stack.pop_back();
				else
					break ;
			}
		}

		/* Print result */
			// Print 'YES' 
			// if stack is empty and string reach the end.
		if (stack.size() == 0 && i == str.size())
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}

	return (0);
}
