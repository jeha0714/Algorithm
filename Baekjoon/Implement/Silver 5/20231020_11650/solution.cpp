#include <iostream>
#include <algorithm> // sort
#include <vector> // vector

bool compare(std::vector<int> a, std::vector<int> b)
{
	if (a.at(0) == b.at(0))
		return (a.at(1) < b.at(1));
	else
		return (a.at(0) < b.at(0));
}

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N;
	int	value;
	std::vector<std::vector<int> > coordinate1;
	std::vector <int> coordinate2;
	
	/* Set initial input */
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		coordinate1.push_back(coordinate2);
		std::cin >> value;
		coordinate1[i].push_back(value);
		std::cin >> value;
		coordinate1[i].push_back(value);
	}

	/* Sort */
	std::sort(coordinate1.begin(), coordinate1.end(), compare);

	/* Print */
	for (int i = 0; i < N; i++)
	{
		std::cout << coordinate1[i][0];
		std::cout << " ";
		std::cout << coordinate1[i][1];
		std::cout << "\n";
	}

	return (0);
}
