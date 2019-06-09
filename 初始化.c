/ *
 *函数名：initGame（）
 *功能描述：对游戏数据进行初始化*函数名：exitGame
 *功能描述：退出当前游戏
 *参数：游戏界面数据
* /
void initGame（int data [ROW] [COL]）
{
    int i，j;

    的printf（ “\ 033 [2J”）; / *清屏* /
    系统（“stty -icanon”）; / *关闭缓冲* /
    system（“stty -echo”）; / *关闭回显* /
    fflush（stdout中）; / *刷新* /

    / *设置背景数据* /
    for（i = 0; i <ROW; i ++）
    {
        for（j = 0; j <COL; j ++）
    	{
    	    data [i] [j] = Bg;
    	}
    }
}

void exitGame（void）
{
    系统（“stty icanon”）; / *开缓冲* /
    系统（“stty echo”）; / *开回显* /
    的putchar（ '\ n'）;
    出口（0）;
}
