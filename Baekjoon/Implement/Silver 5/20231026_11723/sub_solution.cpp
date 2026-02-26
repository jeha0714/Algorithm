#include <iostream>
#include <string>

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int		M, value;
	string	command;
	int		*S;
	
	/* Set initial input */
	cin >> M;
	S = new int[21]();

	/* Execute command */
	for (int i = 0; i < M; i++)
	{
		cin >> command;
		
		if (command.compare("add") == 0)
		{
			cin >> value;
			S[value] = 1;
		}
		else if (command.compare("remove") == 0)
		{
			cin >> value;
			S[value] = 0;
		}
		else if (command.compare("check") == 0)
		{
			cin >> value;
			if (S[value] == 1)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (command.compare("toggle") == 0)
		{
			cin >> value;
			if (S[value] == 1)
				S[value] = 0;
			else
				S[value] = 1;
		}
		else if (command.compare("all") == 0)
		{
			for (int i = 1; i <= 20; i++)
				S[i] = 1;
		}
		else if (command.compare("empty") == 0)
		{
			for (int i = 1; i <= 20; i++)
				S[i] = 0;
		}
	}

	return (0);
}
