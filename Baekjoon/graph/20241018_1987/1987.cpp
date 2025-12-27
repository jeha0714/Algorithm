#include <iostream>
#include <vector>
#include <string>

#define MAX2(x, y) (x > y ? x : y)
#define NONVISIT 0
#define VISIT 1

int R, C;
std::vector< std::string > str;

int	dfs(int x, int y, std::vector< std::vector<int> > &map, std::vector<int> &alpha)
{
/* stop case */
	if (x < 0 || x >= R || y < 0 || y >= C)
		return 0;
	else if (map[x][y] == VISIT)
		return 0;
	else if (alpha[str[x][y] - 'A'] == VISIT)
		return 0;

	// 방문한 현재 위치 기록
	map[x][y] = VISIT;
	alpha[str[x][y] - 'A'] = VISIT;

/* move case */
	int case1 = 1 + dfs(x - 1, y, map, alpha);

	int case2 = 1 + dfs(x + 1, y, map, alpha);

	int case3 = 1 + dfs(x, y - 1, map, alpha);

	int case4 = 1 + dfs(x, y + 1, map, alpha);

	// 백트래킹으로 돌아가기전 방문한 현재 위치 복원
	map[x][y] = NONVISIT;
	alpha[str[x][y] - 'A'] = NONVISIT;

	return (MAX2(MAX2(case1, case2), MAX2(case3, case4)));
}

int main(void)
{
	std::vector< std::vector<int> > map;
	std::vector<int> alpha(26 , 0);
	std::string	s;

	std::cin >> R >> C;
	str.reserve(R);
	map.reserve(R);
	for (int i = 0; i < R; i++)
	{
		std::cin >> s;
		str[i] = s;
		map[i].reserve(C);
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			map[i][j] = NONVISIT;
	}
	

	std::cout << dfs(0, 0, map, alpha) << "\n";

	return (0);
}
