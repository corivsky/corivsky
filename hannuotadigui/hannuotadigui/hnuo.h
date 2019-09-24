#pragma once
//修改by陈墨仙
#include<stdio.h>
static FILE* fp;
class Hanoilmpl {


public:
	void init(int panzishuliang)
	{
		m_panzishuliang = panzishuliang;
		for (int i = 1; i <= m_panzishuliang; i++)
		{
		
		top[1][i] = i;
		top[2][i] = 0;
		top[3][i] = 0;
		}
	}
		void hanoi(int n, int A, int B, int C) {
			if (n == 1) {
				m_xuhao = top[A][getTop(A)];
				move(A, C);
			}
			else {
				hanoi(n - 1, A, C, B);//步骤1 按ACB数序执行N-1的汉诺塔移动
				m_xuhao = top[A][getTop(A)];
				move(A, C);             //步骤2   执行最大盘子移动
				hanoi(n - 1, B, A, C);//步骤3 按BAC数序执行N-1的汉诺塔移动
			}
		}

private:
		void move(char A, char C) {//执行最大盘子的从A-C的移动
			fprintf(fp, "h[%d]:%d->%d\n", m_xuhao, A, C);
			
			top[C][getTop(C) + 1] = top[A][getTop(A)];
			top[A][getTop(A)] = 0;
		}

		int getTop(int A)
		{
			int t = 0;
			for (int i = 1; i <= m_panzishuliang; i++)
			{
				if (top[A][i] != 0)
				{
					t = i;
				}
				else
				{
					break;
				}
			}
			return t;
		}

		int m_xuhao;
		int top[4][34];//0号不用
		int m_panzishuliang;
};
/*————————————————
版权声明：本文为CSDN博主「PharahBai」的原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https ://blog.csdn.net/xb2355404/article/details/79144451
*/