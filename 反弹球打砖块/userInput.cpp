#include "game.h"
/*
���ܣ�ʵʱ��ȡ�û����̲�����Ϣ
��������
����ֵ����
*/
void userControl()
{
	char input;

	input = _getch();
	if (input == 'a' || input == 75)
	{
		direction = 0;
		boardpos.x -=board_dertx;
		if (boardpos.x < 0)
		{
			boardpos.x = 0;
		}
	}
	if (input == 'd' || input == 77)
	{
		direction = 1;
		boardpos.x += board_dertx;
		if (boardpos.x >= 9 * 120 - 200)
		{
			boardpos.x = 9 * 120 - 200;
		}

	}
	if (input == 0x1b)
	{
		//closegraph();
		exit(0);
	}
}