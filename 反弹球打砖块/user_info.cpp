#include "game.h"
typedef struct Linklist
{
	char nickname[13];
	int p_Score;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int p_sec;
	float score_index;
	struct Linklist *next;
}Link;//链表用
_gamer player;
int count;//文本行数
char name[13];//玩家昵称字符串数组
int y, m, d, h, mi, s, sc, pt;//为temp结构体中数据赋值
float ind;
/*
功能：特殊函数：获取鼠标光标信息
参数：无
返回值：无
*/
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
/*
功能：特殊函数：隐藏鼠标光标
参数：无
返回值：无
*/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/*
功能：获取玩家昵称等基本信息函数
参数：无
返回值：无
*/
void user_read()
{
	system("mode con cols=60lines=30 ");
	system("color 06");
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
	//char gamerNickname[13];//玩家昵称
	fflush(stdin);
	printLogo();
	printf_s("●亲爱的玩家你好，请输入你的昵称：");
	scanf_s("%s", gamerNickname);
	while (1)
	{
		if (strlen(gamerNickname)>12)
		{
			memset(gamerNickname, 0, sizeof(char[32]));
			system("cls");
			printLogo();
			printf_s("●请输入长度小于12的昵称：");
			scanf_s("%s", gamerNickname);
		}
		else
		{
			break;
		}
	}
	menu();
}
/*
功能：加载游戏主菜单
参数：无
返回值：无
*/
int menu()
{
	int ichioce;
	system("cls");
	printLogo();
	printf_s("\t\t        ■亲爱的%s，欢迎来到弹力球■\n\n", gamerNickname);
	printf_s("1.开始游戏\n");
	printf_s("2.难度选择\n");
	printf_s("3.查看排行榜\n");
	printf_s("4.退出游戏\n");
	printf_s("请输入您的选择：");
	scanf("%d", &ichioce);
	while (1)
	{
		if (ichioce == 1)
		{
			return 1;
			break;
		}
		if (ichioce == 2)
		{
			modeChange();
			return 2;
			break;
		}
		if (ichioce ==3)
		{
			readUserinfo();
			break;
		}
		if (ichioce == 4)
		{
			printf_s("\n期待再次与您相遇！\n");
			Sleep(1000);
			exit(0);
		}
		else
		{
			system("cls");
			printLogo();
			printf_s("\t\t        ■亲爱的%s，欢迎来到弹力球■\n\n", gamerNickname);
			printf_s("1.开始游戏\n");
			printf_s("2.难度选择\n");
			printf_s("3.查看排行榜\n");
			printf_s("4.退出游戏\n");
			printf_s("输入错误，请重新输入您的选择：");
			scanf("%d", &ichioce);
		}
	}
}
/*
功能：难度选择函数
参数：无
返回值：无
*/
void modeChange()
{
	int num;
	system("cls");
	printLogo();
	printf_s("\t\t\t\t■难度选择■\n\n");
	printf_s("1.普通模式\n");
	printf_s("2.困难模式\n");
	printf_s("3.地狱模式\n");
	printf_s("4.返回菜单\n");
	printf_s("请输入您的选择：");
	scanf("%d", &num);
	while (1)
	{
		if (num==1)
		{
			board_dertx = 20, ballvx_temp = 2, ballvy_temp = 2, add_time_temp = 2000;
			break;
		}
		if (num==2)
		{
			board_dertx = 25, ballvx_temp = 2, ballvy_temp = 2, add_time_temp = 1500;
			break;
		}
		if (num==3)
		{
			board_dertx = 35, ballvx_temp = 3, ballvy_temp = 3, add_time_temp = 1000;
			break;
		}
		if (num==4)
		{
			menu();
			break;
		}
		else
		{
			system("cls");
			printLogo();
			printf_s("\t\t\t\t■难度选择■\n\n");
			printf_s("1.普通模式\n");
			printf_s("2.困难模式\n");
			printf_s("3.地狱模式\n");
			printf_s("4.返回菜单\n");
			printf_s("输入错误，请重新选择：");
			scanf("%d", &num);
		}
		}
	
	

}
/*
功能：打印游戏LOGO
参数：无
返回值：无
*/
void printLogo()
{
	printf_s("------------------------------------------------------------");
	printf_s("                             ■        ■           \n");
	printf_s("                 ■■■■      ■    ■\n");
	printf_s("                       ■    ■■■■■■\n");
	printf_s("                       ■    ■   ■   ■\n ");
	printf_s("                ■■■■    ■■■■■■\n");
	printf_s("                 ■          ■   ■   ■\n ");
	printf_s("                ■■■■    ■■■■■■\n");
	printf_s("                       ■         ■  \n");
	printf_s("                       ■   ■■■■■■■\n");
	printf_s("                       ■         ■\n");
	printf_s("                 ■■■■         ■\n");
	printf_s("                                  ■ \n");
	printf_s("------------------------------------------------------------");
}
/*
功能：读取文件中的游戏数据
参数：无
返回值：无
*/
void readUserinfo()
{
	FILE	*fp;

	int i=1,n,length;
	float index;
	system("cls");
	printLogo();
	printf_s("\t\t\t\t●排行榜●\n");
	_getcwd(buf, sizeof(buf));
	strcat(buf, "\\USER.dat");
	if ((fp = fopen(buf, "r")) == NULL )
	{
		printf_s("\n\n→还没有记录哦，先去玩一局游戏吧！\n");
	}
	else
	{
		n = fscanf(fp, "%s %d %d %d %d %d %d %d %d %f",player.nickname,&player.p_Score, &player.year, 
			&player.month, &player.day, &player.hour, &player.minute, &player.second, &player.p_sec,&player.score_index);
		if (n==-1)
		{
			printf_s("\n\n→还没有记录哦，先去玩一局游戏吧！\n");
		}
		else if (n!=-1)
		{
			printf_s("\n排名\t玩家昵称     分数    游戏日期\t\t    游戏时长");
		}
	
		index= player.score_index;
		length = strlen(player.nickname);
		while (n==10)
		{
			printf_s("%d:\t%s",i,player.nickname);
			for (int i = 0; i < 12-length-3; i++)
			{
				printf_s(" ");
			}
			printf_s("%6d%10d/%d/%d %d:%d:%d%6d秒\n", player.p_Score, player.year, player.month, player.day, player.hour, player.minute, player.second, player.p_sec);
			i++;
			n = fscanf(fp, "%s %d %d %d %d %d %d %d %d %f", player.nickname, &player.p_Score, &player.year, 
				&player.month, &player.day, &player.hour, &player.minute, &player.second, &player.p_sec, &player.score_index);
			length = strlen(player.nickname);
		}
	}
	printf_s("\n\n按任意键返回");
	_getch();
	if (fp!=NULL)
	{
		fclose(fp);
	}
	
	menu();
}
/*
功能：创建临时链表储存排行榜数据，便于排序后写入文件
参数：链表头结构体指针，链表节点个数
返回值：链表头结构体指针
*/
Link *CreatLink(Link *head, int n)
{
	FILE *fp;
	Link *p,*end;
	//end= (Link*)malloc(sizeof(Link*));
	fp = fopen(buf, "r+");
	if (fp == NULL)
	{
		fp = fopen(buf, "w+");
		fclose(fp);
		return head;
	}
	
	for (int i = 0; i < n; i++)
	{
		p = (Link*)malloc(sizeof(Link*));
		fscanf(fp, "%s %d %d %d %d %d %d %d %d %f", name, &sc, &y, &m, &d, &h, &mi, &s, &pt, &ind);
		{
			strcpy(p->nickname, name);
			p->p_Score = sc;
			p->year = y;
			p->month = m;
			p->day = d;
			p->hour = h;
			p->minute = mi;
			p->second = s;
			p->p_sec = pt;
			p->score_index = ind;
		}
		if (head==NULL)
		{
			head = p;
		}
		else
		{
			end->next = p;
		}
		end = p;
	
	}
	if (head != NULL)
	{
		end->next = NULL;
	}
	/*while (head!=NULL)
	{
		printf_s("%s %d %d %d %d %d %d %d %d %f\n", head->nickname, head->p_Score, head->year,
			head->month,head->day,head->hour, head->minute, head->second, head->p_sec, head->score_index);
		head = head->next;
	}
	system("pause");*/
	fclose(fp);
	return head;
}
/*
功能：统计文件文本行数并创建链表
参数：无
返回值：文件存放的数据条数（文本行数）
*/
int Count_line()
{
	FILE *fp;
	char ch;
	fp = fopen(buf, "r+");
	if (fp==NULL)
	{
		fp = fopen(buf, "w+");
		fclose(fp);
		return count;
	}
	while (!feof(fp))
	{
		if (fscanf(fp, "%s %d %d %d %d %d %d %d %d %f", name, &sc, &y, &m, &d, &h, &mi, &s, &pt, &ind)==10)
		{
			count++;
		}
		
	}
	//rewind(fp);
	if (count==0)
	{
		fclose(fp);
		return count;
	}
	//count--;
	printf_s("%d\n", count);
	system("pause");
	fclose(fp);

	return count;
}
/*
功能：插入节点，完成排序
参数：链表头结构体指针，本次游戏数据结构体指针，排名指数
返回值：链表头结构体指针
*/
Link *Insert(Link *head, Link*temp, float index)
{
	Link *pMove, *pInsert,*pBefore;
	int flag = 0;
	pInsert = temp;
	//测试本次游戏数据
	printf_s("%s %d %d %d %d %d %d %d %d %f\n", pInsert->nickname, pInsert->p_Score, pInsert->year,
		pInsert->month, pInsert->day, pInsert->hour, pInsert->minute, pInsert->second, pInsert->p_sec, pInsert->score_index);
	system("pause");
	if (head==NULL)
	{
		head = pInsert;
		pInsert->next = NULL;
		return head;
	}
	pMove = head;
	while (pInsert->p_Score < pMove->p_Score&&pMove->next!=NULL)
	{
		pBefore = pMove;
		pMove = pMove->next;
	}
	
	if (pMove == head)
	{
		if (pInsert->p_Score < pMove->p_Score)
		{
			head->next = pInsert;
			pInsert->next = NULL;
		}
		else
		{
			pInsert->next = head;
			head = pInsert;
		}
			
			printf_s("第一类\n");
	}
	else if (pMove->next==NULL&&pInsert->p_Score < pMove->p_Score)
	{
		pMove->next = pInsert;
		pInsert->next = NULL;
		printf_s("第二类\n");
	}
	else
	{
		pBefore->next = pInsert;
		pInsert->next = pMove;
		flag = 1;
		printf_s("第三类\n");
	}	
	//测试插入后链表数据
	/*while (head != NULL)
	{
		printf_s("%s %d %d/%d/%d %d:%d:%d %d %f\n", head->nickname, head->p_Score, head->year,
			head->month, head->day, head->hour, head->minute, head->second, head->p_sec, head->score_index);
		head = head->next;
	}
	system("pause");*/
	return head;
}
/*
功能：***写用户信息***
参数：无
返回值：无
*/
void printUserinfo()
{
	FILE *fp;
	time_t t;
	struct tm * lt=NULL;
	Link *temp,*head=NULL;
	temp = (Link*)malloc(sizeof(Link*));
	time(&t);//获取Unix时间戳。
	lt = localtime(&t);//转为时间结构。
	_getcwd(buf, sizeof(buf));
	strcat(buf, "\\USER.dat");
	if ((fp = fopen(buf, "r+")) == NULL)
	{
		fp = fopen(buf, "w+");
	}
	//为临时结点赋值，储存本次游戏数据
	{
		player.score_index = (float)score / play_sec;
		temp->year = lt->tm_year + 1900;
		temp->month = lt->tm_mon + 1;
		temp->day = lt->tm_mday;
		temp->hour = lt->tm_hour;
		temp->minute = lt->tm_min;
		temp->second = lt->tm_sec;
		temp->p_sec = play_sec;
		temp->score_index = player.score_index;
		temp->p_Score = score;
		strcpy(temp->nickname, gamerNickname);
	}
	head = CreatLink(head, Count_line());//貌似问题暂时解决了
	head = Insert(head, temp, player.score_index);
	/*while (head != NULL)
	{
		printf_s("1\n");
		head = head->next;
	}
	system("pause");
	
	while (head != NULL)
	{
		printf_s("1\n");
		head = head->next;
	}
	system("pause");*/
	Link *head_temp, *p_mov;
	head_temp = head;
	if (head==NULL)
	{
		printf("head为NULL\n");
		system("pause");
	}

	fclose(fp);
	fp = fopen(buf, "w+");
	if (fp==NULL)
	{
		printf("找不到游戏数据文件!\n");
		exit(1);
	}
	while (head!= NULL)
	{
		fprintf(fp, "%s %d %d %d %d %d %d %d %d %f\n", head->nickname, head->p_Score, head->year, 
			head->month, head->day, head->hour, head->minute, head->second, head->p_sec, head->score_index);
		head =head->next;

	}
	while (head_temp!=NULL)
	{
		p_mov = head_temp;
		head_temp = head_temp->next;
		free(p_mov);
	}
	head = NULL;
	count = 0;
	fclose(fp);
}