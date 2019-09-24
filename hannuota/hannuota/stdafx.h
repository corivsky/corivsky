#pragma once
/*�����������������������������������������ж��������*/
#ifdef __linux__
#define  System_Linux
#define  Process_X64
#endif
#ifdef _M_IX86/*32bit������*/
#define  System_Windows
#define  Process_X86 
#endif
#ifdef _M_X64/*64bit AMD and Intel������(VC2008���Ժ�)*/
#define  System_Windows
#define  Process_X64
#endif
#ifdef _M_IX64/* 64bit Itanium������*/
#define  System_Windows
#define  Process_X64
#endif
#ifdef _M_AMD64/*64bit AMD������ (VC2008��ǰ)*/
#define  System_Windows
#define  Process_X64
#endif
/*����������������������������������������Ӧ��������ȫ���жϺ������ȷ��*/
#ifdef  System_Linux
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<netdb.h>
#include <sys/ioctl.h>  
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/resource.h>
#include <unistd.h> 
#include<sys/mman.h>
#include <linux/if_ether.h>
#include <net/ethernet.h>
#include <linux/if_packet.h>  
#include <linux/if_arp.h>
#include <poll.h>
#endif
#ifdef  System_Windows
#include <SDKDDKVer.h>/*������ǰ��ϵͳ*/
#include <tchar.h>
//#include "resource.h"//��Դ�ļ�
#include <bitset>/*������*/
//#include <Afxwin.h>
//#include <afxwin.h>
#include <conio.h>/*��Ҫ��atlstr.h֮ǰ*/
#include"atlstr.h"/*����̨ʹ��CString��,CRect,TRACE������,debug�������п�Ϊ"���߳�(MT)"��Ϊ"���߳�DLL(/MD)"�޷�ʹ��*/
#include <atlimage.h>/*ʹ��CImage,����̨ʹ��CString��,TRACE������,debug�������п�Ϊ"���߳�(MT)"��Ϊ"���߳�DLL(/MD)"�޷�ʹ��*/
/*---------------------------------------*/
#include<winSock2.h>/*windows������,��Ҫ��windows.h֮ǰ*/
#include "Winhttp.h" 
#include <ws2tcpip.h>/*WSASend/WSARecv*/
#include <Ws2spi.h>/*WSPSend/WSPRecv*/
/*---------------------------------------*/
#define INITGUID/*������<Guiddef.h>֮ǰ,���ز�����*/
#include <Guiddef.h>/*������*/
#include <Gpedit.h>/*������CLSID_GroupPolicyObject����*/
#include <shlwapi.h>
#include <direct.h>/*�½��ļ���,getcwd����*/
#pragma warning(disable: 4996)//getcwd
#include<ctime>/*ϵͳʱ��*/
#include <tlhelp32.h>
#include <TlHelp32.h> //���̺���PROCESSENTRY32��
#include <Psapi.h>
#include <io.h>/*�ж��ļ���*/
#include <iphlpapi.h>/*������������Ϣ*/
#include <fstream>/*��д�ļ�*/
#include <string>
#include <Process.h>
#define WIN32_LEAN_AND_MEAN/*��Windowsͷ���ų�����ʹ�õ�����*/
#include <windows.h>/*GetPixel����,����,Sleep,���а�*/
#include <sys/timeb.h>/*ͨ������time.h*/
//#include "time.h"
#include <shlwapi.h>
#include <shlobj.h>
#include <atlbase.h>
#include <process.h>
#include <MSWSock.h>
#include <mswsock.h>
#include <locale.h>
#include <commctrl.h>
#pragma comment (lib, "mswsock.lib")
#pragma comment(lib,"Iphlpapi.lib")  
#pragma comment(lib,"winhttp.lib")
#pragma comment(lib,"ws2_32.lib")/*windows������*/
#pragma comment(lib,"psapi.lib")
#pragma comment(lib, "shlwapi.lib")
#define myhtons(A)(((WORD)(A)&0XFF00)>>8)|(((WORD)(A)&0X00FF)<<8)/*������*/
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)/*������*/
#endif
/*�����������������������������������������ⲿ�����ڿ�ƽ̨��*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <errno.h>
#include<stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <signal.h>
using namespace std;