/ *
 *��������initGame����
 *��������������Ϸ���ݽ��г�ʼ��*��������exitGame
 *�����������˳���ǰ��Ϸ
 *��������Ϸ��������
* /
void initGame��int data [ROW] [COL]��
{
    int i��j;

    ��printf�� ��\ 033 [2J����; / *����* /
    ϵͳ����stty -icanon����; / *�رջ���* /
    system����stty -echo����; / *�رջ���* /
    fflush��stdout�У�; / *ˢ��* /

    / *���ñ�������* /
    for��i = 0; i <ROW; i ++��
    {
        for��j = 0; j <COL; j ++��
    	{
    	    data [i] [j] = Bg;
    	}
    }
}

void exitGame��void��
{
    ϵͳ����stty icanon����; / *������* /
    ϵͳ����stty echo����; / *������* /
    ��putchar�� '\ n'��;
    ���ڣ�0��;
}
