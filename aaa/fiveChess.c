#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fiveChess.h"

/*
 * 函数名: initGame()
 * 功能描述: 对游戏数据进行初始化
 * 参数: 游戏界面数据
*/
void initGame(int data[ROW][COL])
{
    int i, j;

    printf("\033[2J");      /* 清屏 */
    system("stty -icanon"); /* 关闭缓冲 */
    system("stty -echo");   /* 关闭回显 */
    fflush(stdout);         /* 刷新 */

    /* 设置背景数据 */
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
    	{
    	    data[i][j] = Bg;
    	}
    }
}

/*
 * 函数名: showGame()
 * 功能描述: 显示游戏里的所有元素
 * 参数: 1.游戏数据; 2.当前下棋方;
 *       3.光标横坐标; 4.光标纵坐标
 * 返回值: 无
*/
void showGame(int data[ROW][COL], int player, int idx, int idy)
{
    int i, j;

    printf("\033[1;1H"); // 定位到第一行第一列
    fflush(stdout);
    printf("\033[36m  Move the cursor to confirm the piece  (\033[34mq退出\033[36m)\033[0m\n\n");
    for (i = 0; i < ROW; i++)
    {
       printf("    ");
       for (j = 0; j < COL; j++)
       {
	       /* 光标位置特殊显示 */
           if (i == idy && j == idx)
    	   {
    	       switch (data[i][j])
    	       {
    	           case Bg   : printf(" \033[33m☐\033[0m"); break;
    	           case Black: printf(" \033[31m●\033[0m"); break;
    	           case White: printf(" \033[37m●\033[0m"); break;
    	       }
    	   }
    	   /* 光标以外正常显示 */
    	   else
    	   {
    	       switch (data[i][j])
    	       {
    	           case Bg   : printf(" \033[37m☐\033[0m"); break;
    	           case Black: printf(" \033[31m●\033[0m"); break;
    	           case White: printf(" \033[37m●\033[0m"); break;
    	       }
    	   }
       }
       putchar('\n');
    }
    putchar('\n');
    printf("\033[1;35m%s\033[0m方下棋:", player == Black ? "红":"白");
    fflush(stdout);
}

/*
 * 函数名: playChess()
 * 函数功能: 检查当前位置是否可下棋,如果可下则下
 * 参数: 1.游戏数据; 2.玩家;
 *       3.下棋横坐标; 4.下棋的纵坐标
 * 返回值: 成功下棋返回1,失败返回0
*/
int playChess(int data[ROW][COL], int player, int x, int y)
{
    /* 检查可否下棋 */
    if (checkDown(data,x,y) == 1)
    {
        /* 能下则下 */
    	data[y][x] = player;
    	return 1;
    }
    return 0;
}

/*
 * 函数名: getInput()
 * 功能描述: 获取用户输入
 * 参数: 无
 * 返回值: 用户输入所对应的整型值
*/
int getInput(void)
{
    int key;
    char ch;
    ch = getchar();
    /* 方向键 */
    if (ch=='\033' && getchar()=='[')
    {
        ch = getchar();
    	switch (ch)
    	{
    	    case 'A': key = UP;    break;
    	    case 'B': key = DOWN;  break;
    	    case 'C': key = RIGHT; break;
    	    case 'D': key = LEFT;  break;
    	}
    }
    /* 确认键 */
    else if (ch == '\n')
    {
        key = ENTER;
    }
    /* 退出键 */
    else if (ch == 'q')
    {
        key = QUIT;
    }
    /* 其它键 */
    else
	key = UNKNOW;

    return key;
}

/*
 * 函数名: checkDown()
 * 功能描述: 检查棋子在当前位置能否下棋
 * 参数: 1.游戏数据; 2.棋子的横坐标; 3.棋子的纵坐标
 * 返回值: 可以下返回1,否则返回0
*/

int checkDown(int data[ROW][COL], int x, int y)
{
    if (data[y][x] == Bg)
    {
        return 1;
    }
    else    // 如果不能下则不能下
    {
        return 0;
    }
}

/*
 * 函数名: checkWin()
 * 功能描述: 检查当前下棋方是否胜利
 * 参数: 1.游戏数据; 2.棋子的横坐标;
 *       3.棋子的纵坐标; 4.下棋方
 * 返回值: 当前下棋方满足胜利条件返回1,否则返回0
*/
int checkWin(int data[ROW][COL], int x, int y, int player)
{
    int i, j;
    int count = 0;
    int isWin = 0;

    /* 水平方向 */
    for (i = x-4; i <= x+4; i++)
    {
        /* 检查越界 */
    	if (i < 0 || i > COL-1)
    	{
    	    continue;
    	}
	    /* 棋子计数 */
    	if (data[y][i] == player)
    	{
    	    count++;
    	    if (count == 5)
    	    {
    	        isWin = 1;
    		    return isWin;
    	    }
    	}
    	else
    	{
    	    /* 清零重新计数 */
    	    count = 0;
    	}
    }

    count = 0;  // 必须清零

    /* 垂直方向 */
    for (j = y-4; j <= y+4; j++)
    {
	    /* 检查越界 */
        if (j < 0 || j > ROW-1)
    	{
    	    continue;
    	}
    	/* 棋子计数 */
    	if (data[j][x] == player)
    	{
    	    count++;
    	    if (count == 5)
    	    {
    	        isWin = 1;
    		return isWin;
    	    }
    	}
    	else
    	{
    	    /* 清零重新计数 */
    	    count = 0;
    	}
    }

    count = 0;  // 必须清零

    /* 斜线方向 */
    for (i=x-4,j=y+4; i<=x+4&&j>=0; i++,j--)
    {
	    /* 越界检查 */
        if (x<0 || x>COL-1 || y<0 || y>ROW-1)
    	{
    	    continue;
    	}
    	/* 棋子计数 */
    	if (data[j][i] == player)
    	{
    	    count++;
    	    if (count == 5)
    	    {
    	        isWin = 1;
    		return isWin;
    	    }
    	}
    	else
    	{
            /* 清零以重新计数 */
    	    count = 0;
    	}
    }
    count = 0;
    /* 反斜线方向 */
    for (i=x-4,j=y-4; i<=x+4&&j<=y+4; i++,j++)
    {
        /* 越界检查 */
	    if (x<0 || x>COL-1 || y<0 || y>ROW-1)
    	{
    	    continue;
    	}
    	/* 棋子计数 */
    	if (data[j][i] == player)
    	{
    	    count++;
    	    if (count == 5)
    	    {
    	        isWin = 1;
    		    return isWin;
    	    }
    	}
    	else
    	{
            /* 清零以重新计数 */
    	    count = 0;
    	}
    }

    return isWin;
}

/*
 * 函数名: exitGame()
 * 功能描述: 退出当前游戏
 * 参数: 无
 * 返回值: 无
*/
void exitGame(void)
{
    system("stty icanon"); /* 开缓冲 */
    system("stty echo");   /* 开回显 */
    putchar('\n');
    exit(0);
}


