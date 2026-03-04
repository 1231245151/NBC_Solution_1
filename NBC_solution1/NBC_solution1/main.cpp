#include <stdio.h>

void SetPotion(int count, int* p_HPPotion, int* p_MPPotion);
void HealStat(int Heal, int* p_Stat, int* p_Potion);
void DoublePowerUP(int* p_Stat);

enum PlayerStat
{
	HP,
	MP,
	ATK,
	DEF,


	End
};

void main()
{
	int Status[End] = { 50,50,10,10 };
	int HPPotion = 0;
	int MPPotion = 0;
	int Level = 1;

	// 입력
	while (true)
	{
		printf("hp와 mp를 입력하세요 : ");
		scanf_s("%d %d", &Status[0], &Status[1]);

		if (Status[HP] <= 50 || Status[MP] <= 50)
		{
			printf("hp와 mp는 50을 초과해야합니다!\n");
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		printf("공격력과 방어력을 입력하세요 : ");
		scanf_s("%d %d", &Status[ATK], &Status[DEF]);

		if (Status[ATK] <= 0 || Status[DEF] <= 0)
		{
			printf("공격력과 방어력은 0보다 커야합니다!\n");
		}
		else
		{
			break;
		}
	}

	// 포션 설정
	SetPotion(5, &HPPotion, &MPPotion);
	printf("hp포션, mp포션 5개가 지급되었습니다.\n=======================================\n");

	// 관리창
	while (true)
	{
		static int Num = 0;

		printf("<스텟 관리창>\n");
		printf("1. HP UP\n");
		printf("2. MP UP\n");
		printf("3. 공격력 UP\n");
		printf("4. 방어력 UP\n");
		printf("5. 현재 스텟 UP\n");
		printf("6. Level UP\n");
		printf("0. 나가기\n");

		printf("번호를 입력하세요 : ");
		scanf_s("%d", &Num);

		switch (Num)
		{
		case 1:
			HealStat(20, &Status[HP], &HPPotion);
			break;
		case 2:
			HealStat(20, &Status[MP], &MPPotion);
			break;
		case 3:
			DoublePowerUP(&Status[ATK]);
			break;
		case 4:
			DoublePowerUP(&Status[DEF]);
			break;
		case 5:
			printf("\n<현재 스텟>\n");
			printf("Level : %d HP : %d MP : %d ATK : %d DEF : %d\n<보유중인 포션>\nHP포션 : %d MP포션 : %d\n\n", Level, Status[HP], Status[MP], Status[ATK], Status[DEF], HPPotion, MPPotion);
			break;
		case 6:
			SetPotion(1, &HPPotion, &MPPotion);
			Level += 1;
			printf("Level UP! 현재 레벨은 %d가 되었습니다. 포션을 각각 한개 지급합니다.\n", Level);
			printf("현재 보유한 HP 포션 : %d, MP 포션 : %d\n", HPPotion, MPPotion);
			break;
		case 0:
			printf("프로그램을 종료합니다.\n");
			break;


		default:
			printf("잘못된 입력입니다.\n");
			break;
		}

	
		// 종료
		if (!Num)
		{
			break;
		}
	}


}

// 현재 포션의 개수설정
void SetPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion += count;
	*p_MPPotion += count;
}

// 현재 포션의 개수가 0개가 아니라면 +20, 없다면 오류출력 공격력이나 방어력을 보내지않게 주의
void HealStat(int Heal, int* p_Stat, int* p_Potion)
{
	if (*p_Potion > 0)
	{
		*p_Stat += 20;
		*p_Potion -= 1;

		printf("포션을 사용하였습니다. 현재 스텟 : %d   남은 포션 : %d\n", *p_Stat, *p_Potion);
	}
	else
	{
		printf("포션이 없습니다.\n");
	}
}

// 공격력이나 방어력을 2배한다. HP나 MP를 보내지않게 주의
void DoublePowerUP(int* p_Stat)
{
	*p_Stat *= 2;
	printf("파워업! 해당 스텟이 배로 증가합니다. 현재 스텟 %d\n", *p_Stat);
}
