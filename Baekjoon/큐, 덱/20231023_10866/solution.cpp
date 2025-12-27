#include <iostream>
#include <string> // string type
#include <deque> // deque

using namespace std;

/* Main */
int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int	N;
	string	command;
	int	value;
	deque<int> deque;
	
	/* Set initial input */
	cin >> N;

	/* Operate command */
	for (int i = 0; i < N; i++)
	{
		// Input
		cin >> command;
		
		if (command.compare("push_front") == 0)
		{
			cin >> value;
			deque.push_front(value);
		}
		else if (command.compare("push_back") == 0)
		{
			cin >> value;
			deque.push_back(value);
		}
		else if (command.compare("pop_front") == 0)
		{
			if (deque.size() == 0)
				cout << -1 << "\n";
			else
			{
				cout << deque.front() << "\n";
				deque.pop_front();
			}
		}
		else if (command.compare("pop_back") == 0)
		{
			if (deque.size() == 0)
				cout << -1 << "\n";
			else
			{
				cout << deque.back() << "\n";
				deque.pop_back();
			}
		}
		else if (command.compare("size") == 0)
			cout << deque.size() << "\n";
		else if (command.compare("empty") == 0)
		{
			if (deque.size() == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (command.compare("front") == 0)
		{
			if (deque.size() == 0)
				cout << -1 << "\n";
			else
				cout << deque.front() << "\n";
		}
		else if (command.compare("back") == 0)
		{
			if (deque.size() == 0)
				cout << -1 << "\n";
			else
				cout << deque.back() << "\n";
		}
	}
	
	return (0);
}
