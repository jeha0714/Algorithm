#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 구조체 영역
typedef struct tagnode
{
	struct tagnode* prevnode;
	struct tagnode* nextnode;

	int data;

}node;


// 지하철 고유번호 주소값을 저장.
node* address_Subway[1000001];



/* 함수 정의 */


// tail과 head 연결
void Interlink( int first, int last)
{
	address_Subway[last]->nextnode = address_Subway[first];
	address_Subway[first]->prevnode = address_Subway[last];
}


void BN( int original, int new )
{
	//original역 다음 역의 고유 번호를 출력한다.
	printf("%d\n", address_Subway[ original ]->nextnode->data);

	// 노드 생성 연결
	node* NewNode = (node*)malloc(sizeof(node));

	NewNode->data = new;
	NewNode->nextnode = address_Subway[original]->nextnode;
	NewNode->prevnode = address_Subway[original];

	address_Subway[NewNode->data] = NewNode;

	// 기존 노드 최신화
	address_Subway[original]->nextnode->prevnode = NewNode;
	address_Subway[original]->nextnode = NewNode;
}


void BP( int original, int new)
{
	//original역의 이전 역의 고유 번호를 출력한다.
	printf("%d\n", address_Subway[ original ]->prevnode->data);

	// 노드 생성 연결
	node* NewNode = (node*)malloc(sizeof(node));

	NewNode->data = new;
	NewNode->nextnode = address_Subway[original];
	NewNode->prevnode = address_Subway[original]->prevnode;

	address_Subway[NewNode->data] = NewNode;

	// 기존 노드 최신화
	address_Subway[original]->prevnode->nextnode = NewNode;
	address_Subway[original]->prevnode = NewNode;
}


void CN( int original)
{
	// original역의 위치를 찾는다.
	printf("%d\n", address_Subway[original]->nextnode->data);

	// 기존 노드 최산화.
	address_Subway[original]->nextnode = address_Subway[original]->nextnode->nextnode;
		//free(address_Subway[original]->nextnode->prevnode);
	address_Subway[original]->nextnode->prevnode = address_Subway[original];
}


void CP( int original)
{
	// original역의 위치를 찾는다.
	printf("%d\n", address_Subway[original]->prevnode->data);

	// 기존 노드 최산화.
	address_Subway[original]->prevnode = address_Subway[original]->prevnode->prevnode;
		//free(address_Subway[original]->prevnode->nextnode);
	address_Subway[original]->prevnode->nextnode = address_Subway[original];
}




int main(void)
{
	int num_Subway, construction_Subway;
	scanf("%d %d", &num_Subway, &construction_Subway);

	int first, last; // 처음과 마지막에 입력되는 역의 고유값을 저장한 변수값


	node* current = NULL;

	// 공사 이전에 역을 연결하기 위한 반복문
	for (int now_Try = 0; now_Try < num_Subway; now_Try++)
	{
		int subway_data;  scanf("%d", &subway_data);

		if (now_Try == 0)
		{
			// 새 노드 생성 값 최신화.
			node* NewNode = (node*)malloc(sizeof(node));
			NewNode->data = subway_data;
			NewNode->nextnode = NULL;
			NewNode->prevnode = NULL;

			// 배열 적절한 위치에 주소값 대입
			address_Subway[NewNode->data] = NewNode;

			// 위치 변경
			current = NewNode;
		}
		
		else
		{
			// 새 노드 생성 값 최신화.
			node* NewNode = (node*)malloc(sizeof(node));
			NewNode->data = subway_data;
			NewNode->nextnode = NULL;
			NewNode->prevnode = current;

			// 기존 노드 최신화
			current->nextnode = NewNode;

			// 배열 적절한 위치에 주소값 대입
			address_Subway[NewNode->data] = NewNode;

			// 위치 변경
			current = current->nextnode;
		}

		if (now_Try == 0)
			first = subway_data;

		if (now_Try == num_Subway - 1)
			last = subway_data;
	}

	// 맨 끝 노드르 맨 앞 헤드와 연결.
	Interlink( first, last);
		

	// 해당되는 공사 작업 문자열을 받아들이고 해당되는 공사 작업에 맞게 함수 호출.
	for (int now_Try = 0; now_Try < construction_Subway; now_Try++)
	{
		char situation[4]; scanf("%s", situation);

		if (strcmp(situation, "BN") == 0)
		{
			int original_sub_Num, new_sub_Num; scanf("%d %d", &original_sub_Num, &new_sub_Num);
			BN(original_sub_Num, new_sub_Num);
		}

		else if (strcmp(situation, "BP") == 0)
		{
			int original_sub_Num, new_sub_Num; scanf("%d %d", &original_sub_Num, &new_sub_Num);
			BP(original_sub_Num, new_sub_Num);
		}

		else if (strcmp(situation, "CN") == 0)
		{
			int original_sub_Num; scanf("%d", &original_sub_Num);
			CN(original_sub_Num);
		}

		else if (strcmp(situation, "CP") == 0)
		{
			int original_sub_Num; scanf("%d", &original_sub_Num);
			CP(original_sub_Num);
		}

	}
	


	return 0;
}