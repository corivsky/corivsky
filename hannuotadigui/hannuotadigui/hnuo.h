#pragma once
//�޸�by��ī��
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
				hanoi(n - 1, A, C, B);//����1 ��ACB����ִ��N-1�ĺ�ŵ���ƶ�
				m_xuhao = top[A][getTop(A)];
				move(A, C);             //����2   ִ����������ƶ�
				hanoi(n - 1, B, A, C);//����3 ��BAC����ִ��N-1�ĺ�ŵ���ƶ�
			}
		}

private:
		void move(char A, char C) {//ִ��������ӵĴ�A-C���ƶ�
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
		int top[4][34];//0�Ų���
		int m_panzishuliang;
};
/*��������������������������������
��Ȩ����������ΪCSDN������PharahBai����ԭ�����£���ѭ CC 4.0 BY - SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https ://blog.csdn.net/xb2355404/article/details/79144451
*/