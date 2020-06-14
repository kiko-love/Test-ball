#include "game.h"
/*
功能：二维数组定时偏移处理函数
参数：无
返回值：无
*/
void matrix_dev()
{
	int i, j;
	if (add_line>=50)
	{
		add_line = 0;
	}
	//二维数组向下偏移一行
	for (i = 0; i < ROW + add_line-1; i++)
	{
		for ( j = 0; j < COLS; j++)
		{
			map[ROW + add_line - i-1][j] = map[ROW + add_line - i - 2][j];
		}
	}
	//更新新增的第一行砖块颜色信息
	for ( j = 0; j < COLS; j++)
	{
		map[0][j].color = rand() % 4;
	}
}