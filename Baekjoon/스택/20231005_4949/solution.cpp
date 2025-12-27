#include <iostream>
#include <string> // string type
#include <vector> // vector

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int					i;
	std::string			temp;
	std::string			str;
	std::vector<char>	stack;

	/* Check each string */
	while(1)
	{
		/* Clear variable */
		str.clear();
		stack.clear();

		/* Set input */
		while(1)
		{
			temp.clear();
			getline(std::cin, temp, '\n');
			str.append(temp);
			if (str.back() == '.')
				break ;
		}

		/* Break condition */
		if (str.compare(".") == 0)
			break;

		/* Read string and push,pop stack */
		for (i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
				stack.push_back('(');
			else if (str[i] == '[')
				stack.push_back('[');
			else if (str[i] == ')')
			{
				if (stack.back() == '(')
					stack.pop_back();
				else
					break ;
			}
			else if (str[i] == ']')
			{
				if (stack.back() == '[')
					stack.pop_back();
				else
					break ;
			}
		}

		/* Print result */
		if (stack.size() == 0 && i == str.size())
			std::cout << "yes\n";
		else
			std::cout << "no\n";
	}

	return (0);
}
