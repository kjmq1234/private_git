#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct card
{
	char shape;
	char num[3];
};

_Bool royal_straight_flush(struct card mycard[]);
_Bool back_straight_flush(struct card mycard[]);
_Bool straight_flush(struct card mycard[]);
_Bool four_card(struct card mycard[]);
_Bool full_house(struct card mycard[]);
_Bool flush(struct card mycard[]);
_Bool mountain(struct card mycard[]);
_Bool back_straight(struct card mycard[]);
_Bool straight(struct card mycard[]);
_Bool triple(struct card mycard[]);
_Bool two_pair(struct card mycard[]);
_Bool one_pair(struct card mycard[]);
int	compare(const void* a, const void* b);
int	isflush(struct card mycard[]);
int check_deck(struct card mycard[]);
void option1(struct card mycard[]);
void option2(struct card mycard[]);
void print_deck(int sig);
int	check_valid(struct card* cards);
int	shape_valid(struct card cards);
int	num_valid(struct card cards);
int	isstraight(struct card* mycard);

int	main(void)
{
	struct card mycard[5];
	int	sig;

	srand(time(0));
	printf("1. 직접 입력		2. 랜덤 생성\n\n");
	printf("번호를 입력하세요 : ");
	scanf("%d", &sig);
	printf("\n");
	if (sig == 1)
		option1(mycard);
	else if (sig == 2)
		option2(mycard);
	else
		printf("잘못된 번호입니다. 다시 입력하세요\n");

	while (1)
	{
		printf("===============================================================\n");
		printf("1. 직접 입력 2. 랜덤 생성 3. 종료\n\n");
		printf("번호를 입력하세요 : ");
		scanf("%d", &sig);
		printf("\n");
		if (sig == 1)
			option1(mycard);
		else if (sig == 2)
			option2(mycard);
		else if (sig == 3)
			break;
		else
			printf("잘못된 번호입니다. 다시 입력하세요\n");
	}
}

_Bool royal_straight_flush(struct card mycard[])
{
	if (isflush(mycard) == 0)
		return (0);
	if ((strcmp(mycard[0].num, "A") == 0) && (strcmp(mycard[1].num, "10") == 0) && (strcmp(mycard[2].num, "J") == 0) && (strcmp(mycard[3].num, "Q") == 0) && (strcmp(mycard[4].num, "K") == 0))
		return (1);
	else
		return (0);
}

_Bool back_straight_flush(struct card mycard[])
{

	const char deck[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	if (isflush(mycard) == 0)
		return (0);
	int	tmp = 0;

	for (int i = 0; i < 5; i++)
	{
		if (strcmp(mycard[i].num, deck[tmp++]) != 0)
			return (0);
	}
	return (1);
}

_Bool straight_flush(struct card mycard[])
{

	if ((isflush(mycard) == 0) || isstraight(mycard) == 0)
		return (0);
	else
		return (1);
}

_Bool four_card(struct card mycard[])
{
	for (int i = 0; i < 2; i++)
	{
		if ((strcmp(mycard[i].num, mycard[i + 1].num) == 0) && (strcmp(mycard[i].num, mycard[i + 2].num) == 0) && ((strcmp(mycard[i].num, mycard[i + 3].num)) == 0))
			return (1);
	}
	return (0);
}
_Bool full_house(struct card mycard[])
{
	if ((((strcmp(mycard[0].num, mycard[1].num) == 0) && (strcmp(mycard[0].num, mycard[2].num) == 0)) && ((strcmp(mycard[3].num, mycard[4].num)) == 0)) || (((strcmp(mycard[2].num, mycard[3].num) == 0) && (strcmp(mycard[2].num, mycard[4].num) == 0)) && ((strcmp(mycard[0].num, mycard[1].num)) == 0)))
		return (1);
	else
		return (0);
}
_Bool flush(struct card mycard[])
{
	if (isflush(mycard) == 1)
		return (1);
	else
		return (0);
}
_Bool mountain(struct card mycard[])
{
	if ((strcmp(mycard[0].num, "A") == 0) && (strcmp(mycard[1].num, "10") == 0) && (strcmp(mycard[2].num, "J") == 0) && (strcmp(mycard[3].num, "Q") == 0) && (strcmp(mycard[4].num, "K") == 0))
		return (1);
	else
		return (0);
}

_Bool back_straight(struct card mycard[])
{
	int	tmp = 0;
	const char deck[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	for (int i = 0; i < 5; i++)
	{
		if (strcmp(mycard[i].num, deck[tmp++]) != 0)
			return (0);
	}
	return (1);
}

_Bool straight(struct card mycard[])
{
	if (isstraight(mycard) == 0)
		return (0);
	else
		return (1);
}

_Bool triple(struct card mycard[])
{
	for (int i = 0; i < 3; i++)
	{
		if ((strcmp(mycard[i].num, mycard[i + 1].num) == 0) && strcmp((mycard[i].num), mycard[i + 2].num) == 0)
			return (1);
	}
	return (0);
}

_Bool two_pair(struct card mycard[])
{
	int	num = 0;

	for (int i = 0; i < 4; i++)
	{
		if (strcmp(mycard[i].num, mycard[i + 1].num) == 0)
			num++;
	}
	if (num == 2)
		return (1);
	else
		return (0);
}

_Bool one_pair(struct card mycard[])
{
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(mycard[i].num, mycard[i + 1].num) == 0)
			return (1);
	}
	return (0);
}

int	compare(const void* a, const void* b)
{
	const char deck[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	struct card one = *(struct card*) a;
	struct card two = *(struct card*) b;

	for (int i = 0; i < 12; i++)
	{
		if (((strcmp(one.num, deck[i]) == 0)) && (strcmp(two.num, deck[i]) == 0))
			return (0);
		else if (strcmp(one.num, deck[i]) == 0)
			return (-1);
		else if (strcmp(two.num, deck[i]) == 0)
			return (1);
	}
	return (0);
}

int	isflush(struct card mycard[])
{
	char	com = mycard[0].shape;

	for (int i = 1; i < 5; i++)
	{
		char	com_two = mycard[i].shape;
		if (com != com_two)
			return (0);
	}
	return (1);
}

int check_deck(struct card mycard[])
{
	qsort(mycard, 5, sizeof(struct card), compare);
	if (royal_straight_flush(mycard))
		return (1);
	else if (back_straight_flush(mycard))
		return (2);
	else if (straight_flush(mycard))
		return (3);
	else if (four_card(mycard))
		return (4);
	else if (full_house(mycard))
		return (5);
	else if (flush(mycard))
		return (6);
	else if (mountain(mycard))
		return (7);
	else if (back_straight(mycard))
		return (8);
	else if (straight(mycard))
		return (9);
	else if (triple(mycard))
		return (10);
	else if (two_pair(mycard))
		return (11);
	else if (one_pair(mycard))
		return (12);
	else
		return (13);
}

void print_deck(int sig)
{
	switch (sig)
	{
	case 1:
		printf("로얄 스트레이트 플러쉬\n");
		break;
	case 2:
		printf("백 스트레이트 플러쉬\n");
		break;
	case 3:
		printf("스트레이트 플러쉬\n");
		break;
	case 4:
		printf("포카드\n");
		break;
	case 5:
		printf("풀하우스\n");
		break;
	case 6:
		printf("플러쉬\n");
		break;
	case 7:
		printf("마운틴\n");
		break;
	case 8:
		printf("백스트레이트\n");
		break;
	case 9:
		printf("스트레이트\n");
		break;
	case 10:
		printf("트리플\n");
		break;
	case 11:
		printf("투 페어\n");
		break;
	case 12:
		printf("원 페어\n");
		break;
	case 13:
		printf("노 페어\n");
	}
}

void option1(struct card mycard[])
{

	printf("5개의 카드 정보를 입력하세요.\n");
	while (1)
	{
		for (int i = 0; i < 5; i++)
		{
			printf("%d번 카드 무늬와 숫자 : ", i + 1);
			while (1)
			{
				getchar();
				scanf("%c ", &mycard[i].shape);
				scanf("%s", mycard[i].num);
				if ((shape_valid(mycard[i]) == 0) || (num_valid(mycard[i]) == 0))
				{
					printf("존재하지 않는 카드를 입력하셨습니다. 다시 입력해주세요.\n");
					printf("%d번 카드 무늬와 숫자 : ", i + 1);
				}
				else
					break;
			}
		}
		if (check_valid(mycard) == 0)
			printf("나올 수 없는 경우의 수입니다. 다시 입력해주세요.\n");
		else
			break;
	}
	printf("\n");
	printf("결과 : ");
	print_deck(check_deck(mycard));
}

void option2(struct card mycard[])
{
	int	sig;
	int cnt = 1;
	struct card sortcard[5];
	const char shape[4] = { 'S', 'D', 'H', 'C' };
	const char deck[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	printf("1. royal_straight_flush		2. back_straight_flush\n");
	printf("3. straight_flush		4. four_card\n");
	printf("5. full_house			6. flush\n");
	printf("7. mountain			8. back_straight\n");
	printf("9. straight			10. triple\n");
	printf("11. two_pair			12. one_pair\n\n");
	while (1)
	{
		printf("무슨 족보를 생성할까요? ");
		scanf("%d", &sig);
		if ((sig < 1) || (sig > 12))
			printf("잘못된 숫자를 입력했습니다. 다시 입력해주세요\n");
		else
			break;
	}

	while (1)
	{
		for (int i = 0; i < 5; i++)
		{

			mycard[i].shape = shape[rand() % 4];
			strcpy(mycard[i].num, deck[rand() % 13]);
			sortcard[i].shape = mycard[i].shape;
			strcpy(sortcard[i].num, mycard[i].num);
		}
		if ((check_deck(sortcard) == sig) && (check_valid(sortcard) == 1))
		{
			printf("생성된 카드 : ");
			for (int i = 0; i < 5; i++)
			{
				printf("%c %s", mycard[i].shape, mycard[i].num);
				if (i != 4)
					printf(", ");
			}
			printf("\n%d번 족보를 생성하기 위한 카드 생성 시도 : %d번\n", sig, cnt);
			break;
		}
		else
			cnt++;
	}
}

int	check_valid(struct card* cards)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if ((cards[i].shape == cards[j].shape) && (strcmp(cards[i].num, cards[j].num) == 0))
				return (0);
		}
	}
	return (1);
}

int	shape_valid(struct card cards)
{
	const char shape[4] = { 'S', 'D', 'H', 'C' };

	for (int i = 0; i < 4; i++)
	{
		if (cards.shape == shape[i])
			return (1);
	}
	return (0);
}

int	num_valid(struct card cards)
{
	const char deck[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	for (int i = 0; i < 13; i++)
	{
		if (strcmp(cards.num, deck[i]) == 0)
			return (1);
	}
	return (0);
}

int	isstraight(struct card* mycard)
{
	const char deck[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	int	tmp;

	for (int i = 0; i < 13; i++)
	{
		if (strcmp(mycard[0].num, deck[i]) == 0)
		{
			tmp = i;
			break;
		}
	}
	if ((strcmp(mycard[0].num, deck[0]) == 0) && (strcmp(mycard[4].num, deck[12]) == 0))
	{
		for (int i = 1; i < 5; i++)
		{
			tmp++;
			if (strcmp(mycard[i].num, deck[tmp]) != 0)
			{
				tmp = 13;
				for (int j = 4; j >= i; j--)
				{
					tmp--;
					if (strcmp(mycard[j].num, deck[tmp]) != 0)
						return (0);
				}
				return (1);
			}
		}
	}
	else
	{
		for (int i = 1; i < 5; i++)
		{
			tmp++;
			if (strcmp(mycard[i].num, deck[tmp]) != 0)
				return (0);
		}
	}
	return (1);
}