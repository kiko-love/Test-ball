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
}Link;//������
_gamer player;
int count;//�ı�����
char name[13];//����ǳ��ַ�������
int y, m, d, h, mi, s, sc, pt;//Ϊtemp�ṹ�������ݸ�ֵ
float ind;
/*
���ܣ����⺯������ȡ�������Ϣ
��������
����ֵ����
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
���ܣ����⺯�������������
��������
����ֵ����
*/
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
/*
���ܣ���ȡ����ǳƵȻ�����Ϣ����
��������
����ֵ����
*/
void user_read()
{
	system("mode con cols=60lines=30 ");
	system("color 06");
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);
	//char gamerNickname[13];//����ǳ�
	fflush(stdin);
	printLogo();
	printf_s("���װ��������ã�����������ǳƣ�");
	scanf_s("%s", gamerNickname);
	while (1)
	{
		if (strlen(gamerNickname)>12)
		{
			memset(gamerNickname, 0, sizeof(char[32]));
			system("cls");
			printLogo();
			printf_s("�������볤��С��12���ǳƣ�");
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
���ܣ�������Ϸ���˵�
��������
����ֵ����
*/
int menu()
{
	int ichioce;
	system("cls");
	printLogo();
	printf_s("\t\t        ���װ���%s����ӭ�����������\n\n", gamerNickname);
	printf_s("1.��ʼ��Ϸ\n");
	printf_s("2.�Ѷ�ѡ��\n");
	printf_s("3.�鿴���а�\n");
	printf_s("4.�˳���Ϸ\n");
	printf_s("����������ѡ��");
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
			printf_s("\n�ڴ��ٴ�����������\n");
			Sleep(1000);
			exit(0);
		}
		else
		{
			system("cls");
			printLogo();
			printf_s("\t\t        ���װ���%s����ӭ�����������\n\n", gamerNickname);
			printf_s("1.��ʼ��Ϸ\n");
			printf_s("2.�Ѷ�ѡ��\n");
			printf_s("3.�鿴���а�\n");
			printf_s("4.�˳���Ϸ\n");
			printf_s("���������������������ѡ��");
			scanf("%d", &ichioce);
		}
	}
}
/*
���ܣ��Ѷ�ѡ����
��������
����ֵ����
*/
void modeChange()
{
	int num;
	system("cls");
	printLogo();
	printf_s("\t\t\t\t���Ѷ�ѡ���\n\n");
	printf_s("1.��ͨģʽ\n");
	printf_s("2.����ģʽ\n");
	printf_s("3.����ģʽ\n");
	printf_s("4.���ز˵�\n");
	printf_s("����������ѡ��");
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
			printf_s("\t\t\t\t���Ѷ�ѡ���\n\n");
			printf_s("1.��ͨģʽ\n");
			printf_s("2.����ģʽ\n");
			printf_s("3.����ģʽ\n");
			printf_s("4.���ز˵�\n");
			printf_s("�������������ѡ��");
			scanf("%d", &num);
		}
		}
	
	

}
/*
���ܣ���ӡ��ϷLOGO
��������
����ֵ����
*/
void printLogo()
{
	printf_s("------------------------------------------------------------");
	printf_s("                             ��        ��           \n");
	printf_s("                 ��������      ��    ��\n");
	printf_s("                       ��    ������������\n");
	printf_s("                       ��    ��   ��   ��\n ");
	printf_s("                ��������    ������������\n");
	printf_s("                 ��          ��   ��   ��\n ");
	printf_s("                ��������    ������������\n");
	printf_s("                       ��         ��  \n");
	printf_s("                       ��   ��������������\n");
	printf_s("                       ��         ��\n");
	printf_s("                 ��������         ��\n");
	printf_s("                                  �� \n");
	printf_s("------------------------------------------------------------");
}
/*
���ܣ���ȡ�ļ��е���Ϸ����
��������
����ֵ����
*/
void readUserinfo()
{
	FILE	*fp;

	int i=1,n,length;
	float index;
	system("cls");
	printLogo();
	printf_s("\t\t\t\t�����а��\n");
	_getcwd(buf, sizeof(buf));
	strcat(buf, "\\USER.dat");
	if ((fp = fopen(buf, "r")) == NULL )
	{
		printf_s("\n\n����û�м�¼Ŷ����ȥ��һ����Ϸ�ɣ�\n");
	}
	else
	{
		n = fscanf(fp, "%s %d %d %d %d %d %d %d %d %f",player.nickname,&player.p_Score, &player.year, 
			&player.month, &player.day, &player.hour, &player.minute, &player.second, &player.p_sec,&player.score_index);
		if (n==-1)
		{
			printf_s("\n\n����û�м�¼Ŷ����ȥ��һ����Ϸ�ɣ�\n");
		}
		else if (n!=-1)
		{
			printf_s("\n����\t����ǳ�     ����    ��Ϸ����\t\t    ��Ϸʱ��");
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
			printf_s("%6d%10d/%d/%d %d:%d:%d%6d��\n", player.p_Score, player.year, player.month, player.day, player.hour, player.minute, player.second, player.p_sec);
			i++;
			n = fscanf(fp, "%s %d %d %d %d %d %d %d %d %f", player.nickname, &player.p_Score, &player.year, 
				&player.month, &player.day, &player.hour, &player.minute, &player.second, &player.p_sec, &player.score_index);
			length = strlen(player.nickname);
		}
	}
	printf_s("\n\n�����������");
	_getch();
	if (fp!=NULL)
	{
		fclose(fp);
	}
	
	menu();
}
/*
���ܣ�������ʱ���������а����ݣ����������д���ļ�
����������ͷ�ṹ��ָ�룬����ڵ����
����ֵ������ͷ�ṹ��ָ��
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
���ܣ�ͳ���ļ��ı���������������
��������
����ֵ���ļ���ŵ������������ı�������
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
���ܣ�����ڵ㣬�������
����������ͷ�ṹ��ָ�룬������Ϸ���ݽṹ��ָ�룬����ָ��
����ֵ������ͷ�ṹ��ָ��
*/
Link *Insert(Link *head, Link*temp, float index)
{
	Link *pMove, *pInsert,*pBefore;
	int flag = 0;
	pInsert = temp;
	//���Ա�����Ϸ����
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
			
			printf_s("��һ��\n");
	}
	else if (pMove->next==NULL&&pInsert->p_Score < pMove->p_Score)
	{
		pMove->next = pInsert;
		pInsert->next = NULL;
		printf_s("�ڶ���\n");
	}
	else
	{
		pBefore->next = pInsert;
		pInsert->next = pMove;
		flag = 1;
		printf_s("������\n");
	}	
	//���Բ������������
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
���ܣ�***д�û���Ϣ***
��������
����ֵ����
*/
void printUserinfo()
{
	FILE *fp;
	time_t t;
	struct tm * lt=NULL;
	Link *temp,*head=NULL;
	temp = (Link*)malloc(sizeof(Link*));
	time(&t);//��ȡUnixʱ�����
	lt = localtime(&t);//תΪʱ��ṹ��
	_getcwd(buf, sizeof(buf));
	strcat(buf, "\\USER.dat");
	if ((fp = fopen(buf, "r+")) == NULL)
	{
		fp = fopen(buf, "w+");
	}
	//Ϊ��ʱ��㸳ֵ�����汾����Ϸ����
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
	head = CreatLink(head, Count_line());//ò��������ʱ�����
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
		printf("headΪNULL\n");
		system("pause");
	}

	fclose(fp);
	fp = fopen(buf, "w+");
	if (fp==NULL)
	{
		printf("�Ҳ�����Ϸ�����ļ�!\n");
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