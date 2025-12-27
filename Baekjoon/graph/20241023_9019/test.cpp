#include <iostream>
#include <deque>
#include <vector>
#include <string>

#define NONVISIT 0
#define VISIT 1

int A, B;
std::deque<int> instructions;
std::vector<int> visit(10001);
std::vector<std::string> setInstruction(10001);

int	instructionD(int n)
{
	n *= 2;
	n %= 10000;

	return (n);
}

int	instructionS(int n)
{
	if (n == 0)
		n = 9999;
	else 
		n -= 1;

	return (n);
}

int	instructionL(int n)
{
	n *= 10;
	n = (n % 10000) + (n / 10000);

	return (n);
}

int	instructionR(int n)
{
	n = n + (n % 10 * 10000);
	n /= 10;

	return (n);
}

int	bfs()
{
	int n = instructions.front();

	instructions.pop_front();

	if (n == B)
	{
		std::cout << setInstruction[n] << "\n";
		return (0);
	}
	else
	{
		if (visit[instructionD(n)] == NONVISIT)
		{
			visit[instructionD(n)] = VISIT;
			setInstruction[instructionD(n)] = setInstruction[n] + "D";
			instructions.push_back(instructionD(n));
		}
		if (visit[instructionS(n)] == NONVISIT)
		{
			visit[instructionS(n)] = VISIT;
			setInstruction[instructionS(n)] = setInstruction[n] + "S";
			instructions.push_back(instructionS(n));
		}
		if (visit[instructionL(n)] == NONVISIT)
		{
			visit[instructionL(n)] = VISIT;
			setInstruction[instructionL(n)] = setInstruction[n] + "L";
			instructions.push_back(instructionL(n));
		}
		if (visit[instructionR(n)] == NONVISIT)
		{
			visit[instructionR(n)] = VISIT;
			setInstruction[instructionR(n)] = setInstruction[n] + "R";
			instructions.push_back(instructionR(n));
		}
	}
	return (1);
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
	// reset visit
		for (int i = 0; i <= 10000; i++)
			visit[i] = NONVISIT;
		visit[A] = VISIT;
	
	// push_back basic inst(ruction in queue
		if (visit[instructionD(A)] == NONVISIT)
		{
			visit[instructionD(A)] = VISIT;
			setInstruction[instructionD(A)] = "D";
			instructions.push_back(instructionD(A));
		}
		if (visit[instructionS(A)] == NONVISIT)
		{
			visit[instructionS(A)] = VISIT;
			setInstruction[instructionS(A)] = "S";
			instructions.push_back(instructionS(A));
		}
		if (visit[instructionL(A)] == NONVISIT)
		{
			visit[instructionL(A)] = VISIT;
			setInstruction[instructionL(A)] = "L";
			instructions.push_back(instructionL(A));
		}
		if (visit[instructionR(A)] == NONVISIT)
		{
			visit[instructionR(A)] = VISIT;
			setInstruction[instructionR(A)] = "R";
			instructions.push_back(instructionR(A));
		}

	// bfs to find result!
		while (bfs())
			;
	}

	return (0);
}