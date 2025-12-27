#include <iostream>
#include <vector>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n;
	int value;
	int	i_array;
	int	i_stack;
	int	i_result;
	int current_num;
	std::vector<int> array(0);
	std::vector<int> stack(0);
	std::vector<char> result(0);

	// Insert and Set initial data
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> value;
		array.push_back(value);
	}

	i_array = 0;
	i_stack = -1;
	i_result = -1;
	current_num = 1;
	while (1)
	{
		// Stop if all pop or stack size over than n!
		if (i_array >= n || i_stack > n)
			break ;
		// push number if stack empty!
		if (stack.size() == 0)
		{
			stack.push_back(current_num);
			result.push_back('+');
			i_stack++;
			i_result++;
			current_num++;
		}
		// Check top of stack if stack isn't empty!
		else
		{
			// Same with top of stack and array
			if (stack[i_stack] != array[i_array])
			{
				stack.push_back(current_num);
				result.push_back('+');
				i_stack++;
				i_result++;
				current_num++;
			}
			// Diff with top of stack and array
			else
			{
				stack.pop_back();
				result.push_back('-');
				i_stack--;
				i_result++;
				i_array++;
			}
		}
	}

	/* Print result! */

	// Error if stack isn't empty!
	if (i_stack != -1)
		std::cout << "NO\n";
	// Success if stack empty!
	else
	{
		for (int i = 0; i <= i_result; i++)
			std::cout << result[i] << "\n";
	}

	return (0);
}
