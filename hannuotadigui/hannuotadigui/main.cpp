#include <stdio.h>
#include "hnuo.h"
int main()
{
	int panzishuliang=1;
	printf_s("��������������������Ϊ������������33��\n");
	scanf_s("%d", &panzishuliang);
	char shuliang[12];
	sprintf_s(shuliang, sizeof(shuliang), "�ݹ�%d\.txt", panzishuliang);
	fopen_s(&fp,shuliang, "w+");
	Hanoilmpl *hanoi = new Hanoilmpl();
	hanoi->init(panzishuliang);
	hanoi->hanoi(panzishuliang,1,2,3);
	fclose(fp);

	printf_s("�ݹ��ļ����ɳɹ�\n");
	scanf_s("%d",&panzishuliang);
	return 1;
}