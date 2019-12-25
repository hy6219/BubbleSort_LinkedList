#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
	struct tagNode* Next;
}Node;

Node* createNode(int data)
{
	Node* NewNode = NULL;
	NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = data;
	NewNode->Next = NULL;

	return NewNode;
}

void destroyNode(Node* node)
{
	free(node);
}

void appendNode(Node** Head, Node* node)
{
	if ((*Head) == NULL)
	{
		(*Head) = node;
	}
	else
	{
		Node* Current = NULL;

		Current = (*Head);

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Next = node;
	}	
}

void insertAfter(Node* Current, Node* node)
{
	//기존 노드의 다음 노드와 새로 삽입할 노드를 잇고
	node->Next = Current->Next;
	//기존 노드의 다음포인터와 새로 삽입할 노드 잇기
	Current->Next = node;
}

void insertHead(Node** Head, Node* node)
{
	if ((*Head) == NULL)
	{
		(*Head) = node;
	}
	else
	{
		node->Next = (*Head);//기존 헤드와 새로 삽입될 헤드노드의 포인터를 먼저 이어주고
		//이제 헤드는 새로 삽입한 노드로 대체
		(*Head) = node;
	}
}

void removeNode(Node** Head, Node* node)
{
	if ((*Head) == node)
	{
		(*Head) = node->Next;
	}
	else
	{
		
		Node* Current;
		Current = (*Head);

		while (Current->Next != node && Current != NULL)
		{
			Current = Current->Next;
		}

		if (Current != NULL)
		{
			//Current: 제거할 노드 이전의 노드
			Current->Next = node->Next;//제거 이전 노드의 다음 노드== 제거 노드 다음 노드
		}
	}
}
int size(Node* Head)
{
	Node* Current;
	Current = Head;
	int cnt = 0;
	while (Current != NULL)
	{
		Current = Current->Next;
		cnt++;
	}
	return cnt;
}

Node* SLL_GetNodeAt(Node* Head, int location)
{
	Node* Current = Head;

	while (Current != NULL && (--location) >= 0)
	{
		//--location: 노드가 1개 보다는 커야 진입
		//그 이유는 1개만 있으면
		//index==0
		//즉 바로 리턴해주면 되기 때문
		Current = Current->Next;
	}

	return Current;
}

void BubbleSort(Node* Head)
{
	int len = 0;
	//맨 끝 노드 정보를 알아두고, 그 끝 노드까지 비교, 정렬
	len = size(Head);

	Node* tail = NULL;

	int i = 0;
	//테일노드를 인덱스로 생각하면 len-1,... 1 (=len-(len-1)) 까지만 비교, 정렬하면 되므로 이에 대한 반복 수행
	while (i < len-1)
	{
		tail = SLL_GetNodeAt(Head, len - (i+1));
		Node* Current = Head;
		int temp = 0; //데이터 값만 바꾸어 주어도 되므로 노드의 데이터의 형인 int 이용
		printf("rotation #%d===\n", i);
;		while (Current != tail)
		{
			if (Current->Data > Current->Next->Data)
			{
				temp = Current->Next->Data;
				Current->Next->Data = Current->Data;
				Current->Data = temp;
			}
			Current = Current->Next;
		}
		
		Node* c= Head;

		while (c != NULL)
		{
			printf("%d\n", c->Data);
			c = c->Next;
			
		}

		i++;
	}

	
}
int main()
{
	Node* List = NULL;
	int i = 0;
	Node* NewNode = NULL;
	Node* Current = NULL;
	int count = 0;


	NewNode = createNode(10);
	appendNode(&List, NewNode);

	NewNode = createNode(1);
	appendNode(&List, NewNode);

	NewNode = createNode(4);
	appendNode(&List, NewNode);

	NewNode = createNode(6);
	appendNode(&List, NewNode);

	NewNode = createNode(3);
	appendNode(&List, NewNode);

	NewNode = createNode(9);
	appendNode(&List, NewNode);

	NewNode = createNode(7);
	appendNode(&List, NewNode);

	NewNode = createNode(5);
	appendNode(&List, NewNode);

	NewNode = createNode(2);
	appendNode(&List, NewNode);

	NewNode = createNode(8);
	appendNode(&List, NewNode);
	printf("=====Before=====\n");

	count = size(List);

	printf("노드 개수 : %d\n", count);

	for (i = 0; i < count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	BubbleSort(List);

	printf("=====After=====\n");

	for (i = 0; i < count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
}
