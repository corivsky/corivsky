#include <stdio.h>
#include "hnuo.h"
int main()
{
	int panzishuliang=1;
	printf_s("请输入盘子数量，必须为奇数，不超过33个\n");
	scanf_s("%d", &panzishuliang);
	char shuliang[12];
	sprintf_s(shuliang, sizeof(shuliang), "递归%d\.txt", panzishuliang);
	fopen_s(&fp,shuliang, "w+");
	Hanoilmpl *hanoi = new Hanoilmpl();
	hanoi->init(panzishuliang);
	hanoi->hanoi(panzishuliang,1,2,3);
	fclose(fp);

	printf_s("递归文件生成成功\n");
	scanf_s("%d",&panzishuliang);
	return 1;
}