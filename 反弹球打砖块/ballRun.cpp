#include "game.h"
/*
功能：小球碰撞处理函数
参数：无
返回值：无
*/
void ballCollision()
{
	int ball_posY ;//砖块对应二维数组的纵坐标
	int ball_posX;//......横坐标
	int ball_posXp;//
	//小球遇到窗口边界反弹
	if ((ballpos.x + 30) >= WIDTH || ballpos.x <= 0)
	{
		if (ballpos.x <= 0)
		{
			ballpos.x = 0;
		}
		ballpos.vx = -ballpos.vx;
	}
	//小球遇到窗口边界反弹
	if (ballpos.y <= 0)
	{
		if (ballpos.x<=0)
		{
			ballpos.x = 0;
		}
		ballpos.vy = -ballpos.vy;
	}
	//小球遇到挡板反弹
	if (ballpos.x + 15 >= boardpos.x&&ballpos.x <= boardpos.x + 200 - 15 && ballpos.y >= boardpos.y - 20  && ballpos.y <= boardpos.y)
	{
		ballpos.vy = -ballpos.vy;
		//模拟挡板给予小球的横向加速度
		if (direction == 0)
		{
			ballpos.x -=2;
		}
		if (direction == 1)
		{
			ballpos.x +=2;
		}
	}
	//判断小球与砖块碰撞并消去砖块
	ball_posY = ballpos.y / 30;
	ball_posX = ballpos.x / 120;
	ball_posXp = (ballpos.x ) / 120+1;
	if (ball_posY < ROW + add_line&&ball_posX < COLS)
	{
		if (ballpos.x + 15 >= map[ball_posY][ball_posX].x&&ballpos.x+15 <= map[ball_posY][ball_posX].x + 120
			&& (ballpos.y <= map[ball_posY][ball_posX].y + 30 ))
		{
			if (map[ball_posY][ball_posX].color != black)
			{
	
				score++;
				map[ball_posY][ball_posX].color = black;
				ballpos.vx = -ballpos.vx;
				//ballpos.vy = -ballpos.vy;
			}
		}
		if (ballpos.x +30 >= map[ball_posY][ball_posX].x)
		{
			if (map[ball_posY][ball_posX].color != black)
			{
				brick_num++;
				/*if (brick_num / 4 == 0 && add_line <= 5)
				{
				add_line++;
				makebrick();
				}*/
				score++;
				map[ball_posY][ball_posX].color = black;
				ballpos.vx = -ballpos.vx;
				//ballpos.vy = -ballpos.vy;
			}
		}
		if (ballpos.x +15 >= map[ball_posY][ball_posX].x&&ballpos.x+15 <= map[ball_posY][ball_posX].x + 120 && ballpos.y +30>= map[ball_posY][ball_posX].y )
		{
			if (map[ball_posY][ball_posX].color != black)
			{
				brick_num++;
				/*if (brick_num / 4 == 0 && add_line <= 5)
				{
				add_line++;
				makebrick();
				}*/
				score++;
				map[ball_posY][ball_posX].color = black;
				ballpos.vx = -ballpos.vx;
				//ballpos.vy = -ballpos.vy;
			}
		}
		
	}
	if (ball_posY < ROW + add_line&&ball_posXp < COLS)
	{
		
		if (ballpos.x+30 <= map[ball_posY][ball_posX].x + 120&& map[ball_posY][ball_posX-1].color == black)
		{
			if (map[ball_posY][ball_posX].color != black)
			{
				brick_num++;
				score++;
				map[ball_posY][ball_posX].color = black;
				ballpos.vx = -ballpos.vx;
				//ballpos.vy = -ballpos.vy;
			}
		}

	}
	//判断：经过间隔时间后增加一行
	if (add_time % add_time_temp == 0  && add_time != 0)
	{
		add_line++;
		matrix_dev();
	}
	//玩家未接住小球
	if (ballpos.y > HEIGHT -30)
	{
		ballpos.x = WIDTH / 2-25;
		ballpos.y = HEIGHT / 2;
		ballpos.vy*=-1 ;
		result = false;
	}
}