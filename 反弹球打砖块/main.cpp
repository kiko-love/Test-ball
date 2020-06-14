#include "game.h"
#pragma comment(lib,"Winmm.lib")
IMAGE brick[4];
IMAGE ball[2];
IMAGE board;
IMAGE life[3];
_board boardpos = { WIDTH/2-70,HEIGHT-25 };
_ball ballpos = { WIDTH / 2 - 30 ,HEIGHT - 75,0,0 };
_brick map[ROW+50][COLS];
int brick_num = 0;
int direction = 2;
bool result = true;
int score = 0;//������Ϸ�÷�
int chance = 3;//����ֵ
int add_line = 0;;//ש�����ӵ�����
int add_time = 0;//ש�����ӵļ��ʱ��(��ms��
int randdirection = 0;//С��ʼ������������־
int end = 0;//ש��������Ļ��־
int flag = 0;//���濪ʼ�˶�־
int board_dertx = 20;//����
int ballvy_temp = 2;//��ʼ��С��������ٶ�
int ballvx_temp = 2;//��ʼ��С����߼��ٶ�
int add_time_temp=2000;
char gamerNickname[13];
int play_sec=0;//��Ϸ��ʱ
char buf[100];//д�������ļ���·������
time_t t;//ʱ�������ݣ����ڼ�¼�����Ϸʱ�������
struct tm * lt;//���Ϸ��������ʹ���ʹ�ã�ʱ��ṹ�壬��¼������ʱ����
char IsContinue;//��Ϸѭ����־
/*
���ܣ���ʼ��ͼƬ��Դ
��������
����ֵ����
*/
void loadResource()
{
	loadimage(&brick[yellow], "brick1.png", 120, 30);
	loadimage(&brick[orange], "brick2.png", 120, 30);
	loadimage(&brick[red], "brick3.png", 120, 30);
	loadimage(&brick[green], "brick4.png", 120, 30);
	loadimage(&board, "bar.png", 200, 20);
	loadimage(&ball[0], "ball.bmp", 30, 30);
	loadimage(&ball[1], "ball1.bmp", 30, 30);
	loadimage(&life[2], "life3.png", 100, 30);
	loadimage(&life[1], "life2.png", 100, 30);
	loadimage(&life[0], "ͼƬ2.png", 100, 30);
}

/*
���ܣ����ö�ά�����������ש�����ɫ
��������
����ֵ����
*/
void makebrick()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < ROW + add_line; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			map[i][j].color = rand() % 4;
		}
	}
}
/*
���ܣ���ש��
��������
����ֵ����
*/
void drawBrick()
{
	if ((ROW + add_line) * 30 >= boardpos.y)
	{
		result = false;
	}
	for (int i =0; i < ROW + add_line; i++)//ש������
	{
		for (int j = 0; j < COLS; j++)//ש������
		{
			int x = j * 120;
			int y = i * 30;
			switch (map[i][j].color)
			{
			case yellow:
			case orange:
			case red:
			case green:
				putimage(x, y, &brick[map[i][j].color]);
				map[i][j].x = x;
				map[i][j].y = y;
				break;
			case black:
				setfillcolor(BLACK);
				solidrectangle(x, y, x + 120, y + 30);
				break;
			}
		}
	}
}
/*
���ܣ�������
��������
����ֵ����
*/
void drawBoardl()
{
	putimage(boardpos.x, boardpos.y, &board);
}
/*
���ܣ���С��
��������
����ֵ����
*/
void drawBall()
{
	ballpos.x += ballpos.vx;
	ballpos.y += ballpos.vy;

	putimage(ballpos.x, ballpos.y, &ball[1], SRCAND);
	putimage(ballpos.x, ballpos.y, &ball[0], SRCPAINT);
}
/*
���ܣ���Ϸ���ݳ�ʼ��
��������
����ֵ����
*/
void startup()
{
	lt = localtime(&t);//תΪʱ��ṹ��
	play_sec = lt->tm_sec;
	add_line = 0;
	add_time = 0;
	score = 0;
	ballpos.x = WIDTH / 2+15 ;
	ballpos.y = HEIGHT / 2;
	boardpos = { WIDTH / 2 - 70,HEIGHT - 25 };
	ballpos.vy *= -1;
	result = true;
	flag = 0;
	ballpos.vx = 0;
	ballpos.vy = 0;
	makebrick();
	chance = 3;//��Ϸ����ֵ
	srand((unsigned int)time(NULL));
	randdirection = rand() % 2;
}

/*
���ܣ�������
��������
����ֵ����ϵͳ��������
*/
int main()
{
	//	gotoxy(0, 0);//����
	//HideCursor();//����
	startup();
	user_read();
	loadResource();
	mciSendString("open background.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("open hit.mp3 alias mymusic", NULL, 0, NULL);
	//ȫ��ѭ��
	
		//startup();
		initgraph(WIDTH, HEIGHT);
		//��Ϸ����ˢ��
		while (1)
		{
			BeginBatchDraw();
			cleardevice();
			drawBrick();
			drawBoardl();
			drawBall();
			if (_kbhit())
			{
				if (flag == 0)
				{
					mciSendString("play mymusic repeat", NULL, 0, NULL);
					if (randdirection == 0)
					{
						ballpos.vx = ballvx_temp;
					}
					if (randdirection == 1)
					{
						ballpos.vx = -ballvx_temp;
					}
					ballpos.vy = -ballvy_temp;
					flag = 1;
				}
				userControl();
			}
			//direction = 2;
			ballCollision();
			if (result == false && end == 0)
			{

				MessageBoxA(NULL, "С����䣬������Ϸ��������һ�������λ���", "��Ϸ�����", MB_OK);
				chance--;
				if (chance == 0)
				{
					break;
				}
				else
				{
					result = true;
					cleardevice();
					drawBrick();
					drawBoardl();
					drawBall();
				}
			}
			if (result == false && end == 1)
			{
				MessageBoxA(NULL, "С��ש��ѹ�ô�����������������Ϸ����", "GameOver", MB_OK);
				chance = 0;
				break;
			}
			Sleep(15);
			if (flag == 1)
			{
				add_time++;
				if (add_time % 200 == 0 && add_time != 0)
				{
					play_sec++;
				}
			}
			EndBatchDraw();
		}
		mciSendString("stop mymusic", NULL, 0, NULL);
		mciSendString("close mymusic", NULL, 0, NULL);
		closegraph();
		if (chance == 0)
		{
			system("cls");
			system("mode con cols=60lines=30 ");
			SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);//ϵͳapi���̶����ڣ�����Ϊ�������Ŵ��ڴ�С
			printLogo();
		}
		printUserinfo();
		printf("�������\n");
		printf("\n\n���ֵò���Ŷ�����˴ε÷�Ϊ%d��������ʱΪ%d��%d\n\n", score, play_sec, chance);
		system("pause");
		//menu();
	
	//exit(0);
	return 0;
}