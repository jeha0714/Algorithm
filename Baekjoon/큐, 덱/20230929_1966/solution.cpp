#include <iostream>
#include <algorithm> // sort
#include <list> // list
#include <vector> // vector

/* Sort descending order function! */
static bool compare (int x, int y)
{
	return (x > y);
}

/* Main function */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n_test, N, M;
	int value;
	std::list<int> a_importance_origin(0);
	std::vector<int> a_importance_sorted(0);
	int	printed;

	/* Set initial input */
	std::cin >> n_test;

	/* Operate each case */
	for (int nth_test = 1; nth_test <= n_test; nth_test++)
	{
		/* Set initial input in each case */
		std::cin >> N >> M;
		a_importance_origin.clear();
		a_importance_sorted.clear();
		for (int i = 0; i < N; i++)
		{
			std::cin >> value;
			a_importance_origin.push_back(value);
			a_importance_sorted.push_back(value);
		}

		/* Sorted descending order! */
		std::sort(a_importance_sorted.begin(), a_importance_sorted.end(), compare);

		/* Find when it print! */
		printed = 0;
		while (1)
		{
			// Requseting file locate front and currently most important file is front file
			if (M == 0 && a_importance_origin.front() == a_importance_sorted[printed])
			{
				printed++;
				break;
			}
			// Requseting file locate front and currently most important file locate somewhere 
			else if (M == 0 && a_importance_origin.front() != a_importance_sorted[printed])
			{
				value = a_importance_origin.front();
				a_importance_origin.pop_front();
				a_importance_origin.push_back(value);
				M = a_importance_origin.size() - 1;
			}
			// Requseting file locate somewhere and currently most important file is front file
			else if (M != 0 && a_importance_origin.front() == a_importance_sorted[printed])
			{
				printed++;
				a_importance_origin.pop_front();
				M--;
			}
			// Requseting file locate somewhere and currently most important file locate somewhere
			else
			{
				value = a_importance_origin.front();
				a_importance_origin.pop_front();
				a_importance_origin.push_back(value);
				M--;
			}
		}

		/* Print result each case! */
		std::cout << printed << "\n";
	}

	return (0);
}
