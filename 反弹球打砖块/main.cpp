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
int score = 0;//本次游戏得分
int chance = 3;//生命值
int add_line = 0;;//砖块增加的行数
int add_time = 0;//砖块增加的间隔时间(（ms）
int randdirection = 0;//小球开始左右随机方向标志
int end = 0;//砖块铺满屏幕标志
int flag = 0;//画面开始运动志
int board_dertx = 20;//备用
int ballvy_temp = 2;//初始化小球纵向加速度
int ballvx_temp = 2;//初始化小球横线加速度
int add_time_temp=2000;
char gamerNickname[13];
int play_sec=0;//游戏用时
char buf[100];//写入数据文件的路径数组
time_t t;//时间类数据，用于记录玩家游戏时间和日期
struct tm * lt;//与上方数据类型搭配使用，时间结构体，记录年月日时分秒
char IsContinue;//游戏循坏标志
/*
功能：初始化图片资源
参数：无
返回值：无
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
	loadimage(&life[0], "图片2.png", 100, 30);
}

/*
功能：利用二维数组随机生成砖块的颜色
参数：无
返回值：无
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
功能：画砖块
参数：无
返回值：无
*/
void drawBrick()
{
	if ((ROW + add_line) * 30 >= boardpos.y)
	{
		result = false;
	}
	for (int i =0; i < ROW + add_line; i++)//砖块行数
	{
		for (int j = 0; j < COLS; j++)//砖块列数
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
功能：画挡板
参数：无
返回值：无
*/
void drawBoardl()
{
	putimage(boardpos.x, boardpos.y, &board);
}
/*
功能：画小球
参数：无
返回值：无
*/
void drawBall()
{
	ballpos.x += ballpos.vx;
	ballpos.y += ballpos.vy;

	putimage(ballpos.x, ballpos.y, &ball[1], SRCAND);
	putimage(ballpos.x, ballpos.y, &ball[0], SRCPAINT);
}
/*
功能：游戏数据初始化
参数：无
返回值：无
*/
void startup()
{
	lt = localtime(&t);//转为时间结构。
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
	chance = 3;//游戏生命值
	srand((unsigned int)time(NULL));
	randdirection = rand() % 2;
}

/*
功能：主函数
参数：无
返回值：由系统决定处理
*/
int main()
{
	//gotoxy(0, 0);//备用
	//HideCursor();//备用
	startup();
	user_read();
	loadResource();
	mciSendString("open background.mp3 alias mymusic", NULL, 0, NULL);
	mciSendString("open hit.mp3 alias mymusic", NULL, 0, NULL);
	/*
	全局循环，此处应该有一处while循环，但由于循环可能导致一个内存泄漏的BUG出现，
	暂未添加，有兴趣的朋友可以自行尝试，发现问题可以直接提交到issues，谢谢
	*/
	
		//startup();
		initgraph(WIDTH, HEIGHT);
		//游戏画面刷新
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

				MessageBoxA(NULL, "小球掉落，本局游戏结束，你一共有三次机会", "游戏结果：", MB_OK);
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
				MessageBoxA(NULL, "小球被砖块压得喘不过气啦，本局游戏结束", "GameOver", MB_OK);
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
			SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE)& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX);//系统api，固定窗口，设置为不可缩放窗口大小
			printLogo();
		}
		printUserinfo();
		printf("结算完成\n");
		printf("\n\n表现得不错哦，您此次得分为%d，共计用时为%d秒%d\n\n", score, play_sec, chance);
		system("pause");
		//menu();
	
	//exit(0);
	return 0;
}
