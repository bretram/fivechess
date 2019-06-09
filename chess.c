#include <stdio.h>
#include "fiveChess.h"

int main(void)
{
    int data[ROW][COL];   /* 游戏数据 */
    int key;              /* 用户输入 */
    int isPlay = 0;       /* 是否已下棋 */
    int player = Black;   /* 黑方先下 */
    int idx = 0, idy = 0; /* 光标位置 */

    /* 游戏数据初始化 */
    initGame(data);

    /* 显示游戏 */
    showGame(data,player,idx,idy);

    /* 进入游戏 */
    while (1)
    {
        /* 获取用户输入 */
    	key = getInput();
    	switch (key)
    	{
    	    case UP    : if (idy > 0) idy--;      break;
    	    case DOWN  : if (idy < ROW-1) idy++;  break;
    	    case LEFT  : if (idx > 0) idx--;      break;
    	    case RIGHT : if (idx < COL-1) idx++;  break;
    	    case ENTER : isPlay = \
    	                 playChess(data,player,idx,idy);
    			                          break;
    	    case QUIT  : exitGame();              break;
    	    case UNKNOW:                       continue;
    	}

        /* 每操作一次就显示结果 */
    	showGame(data,player,idx,idy);

    	/* 如果有下棋则检查胜负 */
    	if (isPlay == 1)
    	{
            if (1 == checkWin(data,idx,idy,player))
    	    {
    	        fprintf(stdout, "\033[32m %s方胜利!\033[0m", \
    		                      player == Black ? "黑":"白");
    	        exitGame();
    	    }
    	    /* 没有分出胜负则换对手下 */
    	    player = (player == Black ? White : Black);
            /* 尾部工作 */
    	    showGame(data,player,idx,idy);
    	    isPlay = 0;
    	}
    }

    return 0;
}


