#include <iostream>
#include <string> // string type
#include <queue> // queue

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N, value;
	string	command;
	queue <int> queue;
	
	/* Set initial input */
	cin >> N;

	/* Execute command */
	for (int i = 0; i < N; i++)
	{
		cin >> command;

		if (command.compare("push") == 0)
		{
			cin >> value;
			queue.push(value);
		}
		else if (command.compare("pop") == 0)
		{
			if (queue.size() == 0)
				cout << -1 << "\n";
			else
			{
				cout << queue.front() << "\n";
				queue.pop();
			}
		}
		else if (command.compare("size") == 0)
		{
			cout << queue.size() << "\n";
		}
		else if (command.compare("empty") == 0)
		{
			if (queue.size() == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (command.compare("front") == 0)
		{
			if (queue.size() == 0)
				cout << -1 << "\n";
			else
				cout << queue.front() << "\n";
		}
		else if (command.compare("back") == 0)
		{
			if (queue.size() == 0)
				cout << -1 << "\n";
			else
				cout << queue.back() << "\n";
		}
	}

	return (0);
}
