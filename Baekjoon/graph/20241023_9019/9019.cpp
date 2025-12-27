#include <iostream>
#include <deque>
#include <vector>
#include <string>

#define NONVISIT 0
#define VISIT 1

int A, B;
std::deque<std::string> instructions;
std::vector<int> visit(10001);

void	instructionD(int &n)
{
	n *= 2;
	n %= 10000;
}

void	instructionS(int &n)
{
	n -= 1;
}

void	instructionL(int &n)
{
	n *= 10;
	n = (n % 10000) + (n / 10000);
}

void	instructionR(int &n)
{
	n = n + (n % 10 * 10000);
	n /= 10;
}

int	execute(std::string & instruction)
{
	size_t	strLen = instruction.length();
	int num = A;
	
	for (size_t i = 0; i < strLen; i++)
	{
		if (instruction[i] == 'D')
			instructionD(num);
		else if (instruction[i] == 'S')
			instructionS(num);
		else if (instruction[i] == 'L')
			instructionL(num);
		else if (instruction[i] == 'R')
			instructionR(num);
	}
	return (num);
}

void	bfs()
{
	std::string currentInstruction = instructions.front();
	int			convertInstruction = execute(currentInstruction);

	instructions.pop_front();

	if (visit[convertInstruction] == VISIT)
		return ;
	visit[convertInstruction] = VISIT;

	if (convertInstruction == B)
	{
		std::cout << currentInstruction << "\n";
		instructions.clear();
	}
	else
	{
		instructions.push_back(currentInstruction + "D");
		instructions.push_back(currentInstruction + "S");
		instructions.push_back(currentInstruction + "L");
		instructions.push_back(currentInstruction + "R");
	}
}

int main(void)
{
// Number of test case T
	int T;
	std::cin >> T;

	while(T--)
	{
	// set A, B
		std::cin >> A >> B;
	// clear deque
		instructions.clear();
	// clear visit
		for (int i = 0; i <= 10000; i++)
			visit[i] = NONVISIT;
		visit[A] = VISIT;
	
	// push_back basic instruction in queue
		instructions.push_back(std::string("D"));
		instructions.push_back(std::string("S"));
		instructions.push_back(std::string("L"));
		instructions.push_back(std::string("R"));

	// bfs to find result!
		while (!instructions.empty())
			bfs();
	}



	return (0);
}