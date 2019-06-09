#ifndef  _FIVECHESS_h_
#define  _FIVECHESS_h_

/* 宏定义 */
#define    ROW   20	// 棋盘行数
#define    COL   20	// 棋盘列数

/* 玩家枚举 */
enum Player_e {
    Black,          // 黑方
    White,          // 白方
    Bg,             // 背景
};

/* 按键输入枚举 */
enum Key_e {
    UP,             // 上
    DOWN,           // 下
    LEFT,           // 左
    RIGHT,          // 右
    QUIT,           // 退出
    ENTER,          // 确认
    UNKNOW,         // 其它
};

/*
 * 函数名: initGame()
 * 功能描述: 对游戏数据进行初始化
 * 参数: 游戏界面数据
 * 返回值: 无
*/
void initGame(int data[ROW][COL]);

/*
 * 函数名: showGame()
 * 功能描述: 显示游戏里的所有元素
 * 参数: 1.游戏数据; 2.当前下棋方;
 *       3.光标横坐标; 4.光标纵坐标
 * 返回值: 无
*/
void showGame(int data[ROW][COL], int player, int idx, int idy);

/*
 * 函数名: playChess()
 * 函数功能: 检查当前位置是否可下棋,如果可下则下
 * 参数: 1.游戏数据; 2.玩家;
 *       3.下棋横坐标; 4.下棋的纵坐标
 * 返回值: 成功下棋返回1,失败返回0
*/
int playChess(int data[ROW][COL], int player, int x, int y);

/*
 * 函数名: getInput()
 * 功能描述: 获取用户输入
 * 参数: 无
 * 返回值: 用户输入所对应的整型值
*/
int getInput(void);

/*
 * 函数名: checkDown()
 * 功能描述: 检查棋子在当前位置能否下棋
 * 参数: 1.游戏数据; 2.棋子的横坐标; 3.棋子的纵坐标
 * 返回值: 可以下返回1,否则返回0
*/
int checkDown(int data[ROW][COL], int x, int y);

/*
 * 函数名: checkWin()
 * 功能描述: 检查当前下棋方是否胜利
 * 参数: 1.游戏数据; 2.棋子的横坐标;
 *       3.棋子的纵坐标; 4.下棋方
 * 返回值: 当前下棋方满足胜利条件返回1,否则返回0
*/
int checkWin(int data[ROW][COL], int x, int y, int player);

/*
 * 函数名: exitGame()
 * 功能描述: 退出当前游戏
 * 参数: 无
 * 返回值: 无
*/
void exitGame(void);

#endif   //_FIVECHESS_h_



