#include <iostream>

void quad_tree(int start_r, int start_c, int size, std::string *picture)
{
	// start_r start_c위치의 색을 initial_color에 저장
	char initial_color = picture[start_r][start_c];

	for (int current_r = start_r; current_r < start_r + size; current_r++)
	{
		for (int current_c = start_c; current_c < start_c + size; current_c++)
		{
			// 지정된 구역 (현재 위치로부터 가로 세로 size만큼 떨어진 위치까지)을
			// 돌면서 initial_color와 다른 색이 발견된다면 
			// 색을 구분해야 하므로 쪼갠다.
			if (initial_color != picture[current_r][current_c])
			{
				std::cout << "(";

				// 시작 위치와 size를 쪼개서 함수를 재호출 한다.
				quad_tree(start_r, start_c, size / 2, picture);
				quad_tree(start_r, start_c + size / 2, size / 2, picture);
				quad_tree(start_r + size / 2, start_c, size / 2, picture);
				quad_tree(start_r + size / 2, start_c + size / 2, size / 2, picture);

				std::cout << ")";
				
				return ;
			}
		}
	}

	std::cout << initial_color;
}

int main()
{
	// 영상의 크기를 입력
	int N; std::cin >> N;
	// 문자열로 표현된 영상을 입력 받음
	std::string *picture = new std::string [N];
	for (int r = 0; r < N; r++)
		std::cin >> picture[r];

	quad_tree(0, 0, N, picture);

	// 메모리 반납
	delete[] picture;

	return (0);
}
