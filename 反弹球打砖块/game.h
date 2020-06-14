/*头文件声明：包含其余子模块所有用到的全局变量、常量、结构体以及标准调用库信息*/
/*编写者：软工195 张艺 201908128*/
/*编写时间：2020/05/11 —2020/05/31 */
/*累计修改重要BUG数：10 */

#ifndef  _GAME_H_
	#define _GAME_H_

#define WIDTH 9*120
#define HEIGHT 30*20
#define ROW 5
#define COLS 9
//挡板结构体
typedef struct board_info
{
	int x, y;

}_board;
//小球结构体
typedef struct  ball_info
{
	int x, y;
	int vx, vy;
	int radius;

}_ball;
//砖块结构体
typedef struct brick_info
{
	int x, y;
	int color;
}_brick;
//玩家结构体
typedef struct gamer_info
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
}_gamer;
extern _brick map[ROW + 50][COLS];
extern _board boardpos;
extern _ball ballpos;
extern struct tm *lt;
extern int direction;
extern char gamerNickname[13];
extern int add_line;//砖块增加的行数
extern int brick_num;
extern int score;//玩家得分，1分=1块砖
extern bool result;//判定小球是否跌落，作为游戏结束的标志
extern int add_time;//砖块增加的时间间隔
extern int end;
extern char buf[100];//写入数据文件的路径数组
extern int play_sec;
extern int board_dertx;//木板移动速度
extern int ballvy_temp;//小球初始化纵向加速度
extern int ballvx_temp;//小球初始化横向加速度
extern int add_time_temp;
extern char nickname[32];
extern void printLogo();
extern void modeChange();
extern void loadResource();
extern void makebrick();
extern void drawBrick();
extern void drawBoardl();
extern void drawBall();
extern void ballCollision();
extern void userControl();
extern void matrix_dev();
extern void user_read();
extern void gotoxy(int x, int y);
extern void HideCursor();
extern void printUserinfo();
extern int	menu();
extern void readUserinfo();
enum brickColor
{
	yellow, orange, red, green, black
};

#endif
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <tchar.h> 
#include <graphics.h>
#include <windows.h>
#include <string.h>
#include <direct.h>