#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>

/* bfs 구현 */
std::string solve(int a, int b)
{
	int	currv, nextv;
	std::string currs, nexts;

	std::queue<std::pair<int, std::string> > myq;

	myq.push(std::make_pair(a, ""));

	while (!myq.empty())
	{
	/* pop */
		currv = myq.front().first;
		currs = myq.front().second;
		myq.pop();

	/* Dnode */
	nextv = (currv * 2) % 10000;
	nexts = currs + "D";
	if (nextv == b)
		return nexts;
	myq.push(std::make_pair(nextv, nexts));

	/* Snode */
	nextv = (currv - 1 < 0) ? 9999 : currv - 1;
	nexts = currs + "S";
	if (nextv == b)
		return nexts;
	myq.push(std::make_pair(nextv, nexts));

	/* Lnode */
	nextv = (currv % 1000) * 10 + (currv / 1000); 
	nexts = currs + "L";
	if (nextv == b)
		return nexts;
	myq.push(std::make_pair(nextv, nexts));

	/* Rnode */
	nextv = (currv % 10) * 1000 + (currv / 10); 
	nexts = currs + "R";
	if (nextv == b)
		return nexts;
	myq.push(std::make_pair(nextv, nexts));
	}

	return (NULL);
}

int main(void)
{
	FILE *fp;

	fp = fopen("input.txt", "r");

	int tc;
	int a, b;
	char c;
	char ans[1000];

	fscanf(fp, "%d", &tc);
	for (int i = 0; i < tc; i++)
	{
		fscanf(fp, "%d %d", &a, &b);
		fscanf(fp, "%c", &c);
		fgets(ans, 1000, fp);

		printf("%s\n", solve(a, b).c_str());
	}


	fclose(fp);
	return 0;
}
