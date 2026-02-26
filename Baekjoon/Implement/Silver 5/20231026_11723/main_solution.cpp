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
	int		S;
	
	/* Set initial input */
	cin >> M;
	S = 0;

	/* Execute command */
	for (int i = 0; i < M; i++)
	{
		cin >> command;
		
		if (command.compare("add") == 0)
		{
			cin >> value;
			S = S | ((int)1 << (value - 1));
		}
		else if (command.compare("remove") == 0)
		{
			cin >> value;
			S = S & ~((int)1 << (value - 1));
		}
		else if (command.compare("check") == 0)
		{
			cin >> value;
			if ((S & ((int)1 << (value - 1))) > 0)
				cout << 1 << "\n"; 
			else
				cout << 0 << "\n"; 
		}
		else if (command.compare("toggle") == 0)
		{
			cin >> value;
			S = S ^ ((int)1 << (value - 1));
		}
		else if (command.compare("all") == 0)
			S = S | ~((int)0);
		else if (command.compare("empty") == 0)
			S = S & (int)0;
	}

	return (0);
}
