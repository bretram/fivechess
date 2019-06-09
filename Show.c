void initGame(int data[ROW][COL])
{
    int i, j;

    printf("\033[2J");      /* 清屏 */
    system("stty -icanon"); /* 关闭缓冲 */
    system("stty -echo");   /* 关闭回显 */
    printf("\033[?25l");    /* 隐藏鼠标 */
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
    printf("\033[36m***移动光标按确认下棋(\033[34mq退出\033[36m)***\033[0m\n\n");
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
    	           case Bg   : printf(" \033[42m+\033[0m"); break;
    	           case Black: printf(" \033[42m@\033[0m"); break;
    	           case White: printf(" \033[42m#\033[0m"); break;
    	       }
    	   }
    	   /* 光标以外正常显示 */
    	   else
    	   {
    	       switch (data[i][j])
    	       {
    	           case Bg   : printf(" +"); break;
    	           case Black: printf(" \033[33m@\033[0m"); break;
    	           case White: printf(" \033[36m#\033[0m"); break;
    	       }
    	   }
       }
       putchar('\n');
    }
    putchar('\n');
    printf("\033[1;35m%s\033[0m方下棋:", player == Black ? "黑":"白");
    fflush(stdout);
}