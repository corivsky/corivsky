// helloworld.cpp : Defines the entry point for the console application.
//
//by 陈墨仙 2019-07-18
//完全不用递归解汉诺塔
//修改 by陈墨仙 2019-9-24
//#include "stdafx.h"
//#include <windows.h>

//#include <iostream>
#include <stdio.h>

int h[34];//为了便于理解，0号元素不用,zhuzishuliang个盘子
int a[4][34];
int b[4];
int jihao;
int dijici;
FILE *fp;
int zhuzishuliang = 0;
void printH()
{
    //system("cls");
    for (int i = 1; i <= zhuzishuliang+1; i++)
    {
        printf("%d:%d\t", i, a[3][i]);
    }
    
}
bool jiancha(int * h)//检测是否在下面的都是编号小的
{
    int d[4];
    d[1] = 0;
    d[2] = 0;
    d[3] = 0;
    for (int j = 1; j < 4; j++)
    {
        for (int i = 1; i < zhuzishuliang+1; i++)
        {
            if (a[j][i] == 0 || a[j][i] > a[j][i - 1])
            {
                
            }
            else
            {
                printf("error  a[%d][%d] = %d a[%d][%d]=%d", j, i - 1, a[j][i - 1], j, i, a[j][i]);
                scanf("%d");
                return false;
            }
        }
    }
    return true;
}
bool shunxu(int zhuzi)
{
    for (int i = 1; i < b[zhuzi]; i++)
    {
        if (a[zhuzi][i] == zhuzishuliang+1 - i)
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}
bool chenggong(int n, int zhuzi)//n号盘是否都移到3
{
    
    int d = 0;
    int t = zhuzishuliang+1;
    for (int i = zhuzishuliang; i > zhuzishuliang - n; i--)
    {
        if (a[zhuzi][zhuzishuliang+1 - i] != n-i + 1)
        {
            return false;
            
        }
    }
    
    return true;
    
}
int jc3()//检测3号柱的盘子有几个
{
    
    int d = 0;
    int t = zhuzishuliang+1;
    for (int i = zhuzishuliang; i > 0; i--)
    {
        if (h[i] == 3)
        {
            d = d + 1;
            t = i;
        }
    }
    return d;
}
int jc1()//检测1号柱的盘子有几个
{
    
    int d = 0;
    int t = zhuzishuliang+1;
    for (int i = zhuzishuliang; i > 0; i--)
    {
        if (h[i] == 1)
        {
            d = d + 1;
            t = i;
        }
    }
    return d;
}
void initH()
{
    for (int i = 0; i < zhuzishuliang+1; i++)
    {
        h[i] = 1;
        a[1][i] = i;
        a[2][i] = 0;
        a[3][i] = 0;
    }
    b[1] = zhuzishuliang+1;
    b[2] = 1;
    b[3] = 1;
}
int jc2()//检测2号柱从zhuzishuliang往下盘子有几个
{
    
    int d = 0;
    int t = zhuzishuliang+1;
    for (int i = zhuzishuliang; i > 0; i--)
    {
        if (h[i] == 2)
        {
            d = d + 1;
            t = i;
        }
    }
    return d;
}
int getTop(int zhuzi)//获得zhuzi编号的柱子最顶层的盘子序号
{
    int d = 0;
    int t = 0;
    for (int i = 1; i < zhuzishuliang+1; i++)
    {
        if (h[i] == zhuzi && i > t)//盘子序号越大，说明盘子越小
        {
            
            t = i;
        }
    }
    return t;
}
bool jiou(int s)
{
    if (s % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void change(int i, int yuan, int mubiao)
{
    int p;
    if (h[i] == yuan)
    {
        h[i] = mubiao;
        a[mubiao][b[mubiao]] = i;
        b[mubiao] = b[mubiao] + 1;
        a[yuan][b[yuan]] = 0;
        b[yuan] = b[yuan] - 1;
        fprintf(fp,"h[%d]:%d->%d", i, yuan, mubiao);
    }
    else
    {
        fprintf(fp,"Error  h[%d] = %d", i, h[i]);
        printf("Error  h[%d] = %d", i, h[i]);
        scanf("%d",&p);
    }
    jiancha(h);
}

int chu2(int n, int cishu)
{
    for (int j = 1; j <= cishu; j++)
    {
        n = n / 2;
    }
    return n;
}
void jihaopan(int n)
{
    int i = 1;
    int yuan = n;
    while (1)
    {
        if (n % 2 == 1)
        {
            jihao = i;
            dijici = chu2(yuan, i) + 1;
            break;
        }
        n = n / 2;
        i = i + 1;
    }
    
    //printf("几号盘%d,第几次%d",jihao,dijici);
}

int main(int argc, char * argv[])
{
    printf("汉诺塔!\n");
    int times = 0;
    
    int ji = 1;
    char shuliang[24];
    printf("请输入柱子数量，必须是奇数且小于33，小于33是因为数组设置大小就那么大过了要越界\n");
    scanf("%d", &zhuzishuliang);
    printf("收到%d\n",zhuzishuliang);
    
    snprintf(shuliang,sizeof(shuliang), "%d.txt", zhuzishuliang);
    printf("注释：h[3]:1->3表示：h[3]的3指序号3的盘子，序号越大盘子越小，1->3表示从1号柱移到3号柱，结果保存在%s\n", shuliang);
    fp = fopen(shuliang, "w+");
    fprintf(fp,"新一次%d\n",zhuzishuliang);
    initH();
    for (int i = 1; i < 5559060534555523; i++)
    {
        jihaopan(i);
        if (jiou(jihao) == false)
        {
            int tmp;
            tmp = dijici % 3;
            if (tmp == 1)
            {
                change(getTop(1), 1, 3);
            }
            else if (tmp == 2)
            {
                change(getTop(3), 3, 2);
            }
            else
            {
                change(getTop(2), 2, 1);
            }
        }
        else
        {
            int tmp;
            tmp = dijici % 3;
            if (tmp == 1)
            {
                change(getTop(1), 1, 2);
            }
            else if (tmp == 2)
            {
                change(getTop(2), 2, 3);
            }
            else
            {
                change(getTop(3), 3, 1);
            }
        }
        if (chenggong(zhuzishuliang, 3))
        {
            printf("成功了！请移步txt观看过程。\n");
            break;
        }
    }
    
    fclose(fp);
    scanf("%d",&zhuzishuliang);
    return 0;
}

