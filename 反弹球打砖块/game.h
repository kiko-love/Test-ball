/*ͷ�ļ�����������������ģ�������õ���ȫ�ֱ������������ṹ���Լ���׼���ÿ���Ϣ*/
/*��д�ߣ���195 ���� 201908128*/
/*��дʱ�䣺2020/05/11 ��2020/05/31 */
/*�ۼ��޸���ҪBUG����10 */

#ifndef  _GAME_H_
	#define _GAME_H_

#define WIDTH 9*120
#define HEIGHT 30*20
#define ROW 5
#define COLS 9
//����ṹ��
typedef struct board_info
{
	int x, y;

}_board;
//С��ṹ��
typedef struct  ball_info
{
	int x, y;
	int vx, vy;
	int radius;

}_ball;
//ש��ṹ��
typedef struct brick_info
{
	int x, y;
	int color;
}_brick;
//��ҽṹ��
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
extern int add_line;//ש�����ӵ�����
extern int brick_num;
extern int score;//��ҵ÷֣�1��=1��ש
extern bool result;//�ж�С���Ƿ���䣬��Ϊ��Ϸ�����ı�־
extern int add_time;//ש�����ӵ�ʱ����
extern int end;
extern char buf[100];//д�������ļ���·������
extern int play_sec;
extern int board_dertx;//ľ���ƶ��ٶ�
extern int ballvy_temp;//С���ʼ��������ٶ�
extern int ballvx_temp;//С���ʼ��������ٶ�
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