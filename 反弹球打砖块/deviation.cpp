#include "game.h"
/*
���ܣ���ά���鶨ʱƫ�ƴ�����
��������
����ֵ����
*/
void matrix_dev()
{
	int i, j;
	if (add_line>=50)
	{
		add_line = 0;
	}
	//��ά��������ƫ��һ��
	for (i = 0; i < ROW + add_line-1; i++)
	{
		for ( j = 0; j < COLS; j++)
		{
			map[ROW + add_line - i-1][j] = map[ROW + add_line - i - 2][j];
		}
	}
	//���������ĵ�һ��ש����ɫ��Ϣ
	for ( j = 0; j < COLS; j++)
	{
		map[0][j].color = rand() % 4;
	}
}