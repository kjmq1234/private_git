#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
int	compare(const struct card* one, const struct card* two);


struct card
{
	char shape;
	char num[3];
};

int	main(void)
{
	struct card mycard[5];
	int	sig;

	printf("1. 직접 입력 2. 랜덤 생성\n\n");
	printf("번호를 입력하세요 : ");
	scanf("%d", &sig);
	printf("\n");
	if (sig == 1)
	{
		printf("5개의 카드 정보를 입력하세요.\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d번 카드 무늬와 숫자 : ", i + 1);
			scanf("%c ", &mycard[i].shape);
			getchar();
			scanf("%s", mycard[i].num);
		}
		qsort(mycard, 5, sizeof(struct card), compare);

		for (int i = 0; i < 5; i++)
		{
			printf("%d: %s\n", i, mycard[i].num);
		}
		printf("\n");
		printf("결과 : \n");
		if (royal_straight_flush(mycard))
			printf("로얄 스트레이트 플래쉬\n");
		else if (back_straight_flush(mycard))
			printf("백 스트레이트 플래쉬\n");
		else if (straight_flush(mycard))
			printf("스트레이트 플래쉬\n");
		else if (four_card(mycard))
			printf("포 카드\n");
		else if (full_house(mycard))
			printf("풀 하우스\n");
		else if (flush(mycard))
			printf("플래쉬\n");
		else if (mountain(mycard))
			printf("마운틴\n");
		else if (back_straight(mycard))
			printf("백 스트레이트\n");
		else if (straight(mycard))
			printf("스트레이트\n");
		else if (triple(mycard))
			printf("트리플\n");
		else if (two_pair(mycard))
			printf("투 페어\n");
		else if (one_pair(mycard))
			printf("원 페어\n");
		else
			printf("노 페어\n");
	}
	else if (sig == 2)
	{
		printf("1. royal_straight_flush 2. back_straight_flush\n");
		printf("3. straight_flush 4. four_card\n");
		printf("5. full_house 6. flush\n");
		printf("7. mountain 8. back_straight\n");
		printf("9. straight 10. triple\n");
		printf("11. two_pair 12. one_pair\n\n");
		printf("무슨 족보를 생성할까요? ");
		scanf("%d", &sig);
		printf("생성된 카드 :\n");
		printf("1번 족보를 생성하기 위한 카드 생성 시도 :\n");
	}
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
		{
			printf("5개의 카드 정보를 입력하세요.\n");
			for (int i = 0; i < 5; i++)
			{
				printf("%d번 카드 무늬와 숫자 : ", i + 1);
				scanf("%c ", &mycard[i].shape);
				getchar();
				scanf("%s", mycard[i].num);
			}
			printf("\n");
			printf("결과 : \n");
			if (royal_straight_flush(mycard))
				printf("로얄 스트레이트 플래쉬\n");
			else if (back_straight_flush(mycard))
				printf("백 스트레이트 플래쉬\n");
			else if (straight_flush(mycard))
				printf("스트레이트 플래쉬\n");
			else if (four_card(mycard))
				printf("포 카드\n");
			else if (full_house(mycard))
				printf("풀 하우스\n");
			else if (flush(mycard))
				printf("플래쉬\n");
			else if (mountain(mycard))
				printf("마운틴\n");
			else if (back_straight(mycard))
				printf("백 스트레이트\n");
			else if (straight(mycard))
				printf("스트레이트\n");
			else if (triple(mycard))
				printf("트리플\n");
			else if (two_pair(mycard))
				printf("투 페어\n");
			else if (one_pair(mycard))
				printf("원 페어\n");
			else
				printf("노 페어\n");
		}
		else if (sig == 2)
		{
			printf("1. royal_straight_flush 2. back_straight_flush\n");
			printf("3. straight_flush 4. four_card\n");
			printf("5. full_house 6. flush\n");
			printf("7. mountain 8. back_straight\n");
			printf("9. straight 10. triple\n");
			printf("11. two_pair 12. one_pair\n\n");
			printf("무슨 족보를 생성할까요? ");
			scanf("%d", &sig);
			printf("생성된 카드 :");

			printf("1번 족보를 생성하기 위한 카드 생성 시도 :\n");
		}
		else if (sig == 3)
			break;
		else
			printf("잘못된 번호입니다. 다시 입력하세요\n");
	}
}

_Bool royal_straight_flush(struct card mycard[])
{
	return 0;
}

_Bool back_straight_flush(struct card mycard[])
{
	return 0;

}
_Bool straight_flush(struct card mycard[])
{
	return 0;
}
_Bool four_card(struct card mycard[])
{
	return 0;
}
_Bool full_house(struct card mycard[])
{
	return 0;
}
_Bool flush(struct card mycard[])
{
	return 0;
}
_Bool mountain(struct card mycard[])
{
	return 0;
}
_Bool back_straight(struct card mycard[])
{
	if ((strcmp(mycard[0].num, "2") == 0) && (strcmp(mycard[1].num, "3") == 0) && (strcmp(mycard[2].num, "4") == 0) && (strcmp(mycard[3].num, "5") == 0) && (strcmp(mycard[4].num, "A") == 0))
		return (1);
	else
		return (0);
}
_Bool straight(struct card mycard[])
{
	return 0;
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
	char buf[3];

	//for (int i = 0; i < 4; i++)
	//{
	//	if (strcmp(mycard[i].num, mycard[i + 1].num) == 0)
	//	{
	//		strcpy(buf, mycard[i].num);
	//	}
	//}
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

int	compare(const struct card* one, const struct card* two)
{
	if (strcmp(one->num, two->num) > 0)
		return (1);
	else if (strcmp(one->num, two->num) < 0)
		return (-1);
	else
		return (0);
}
