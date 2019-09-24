#pragma once
/*■■■■■■■■■■■■■■■■■■■■判断所有情况*/
#ifdef __linux__
#define  System_Linux
#define  Process_X64
#endif
#ifdef _M_IX86/*32bit处理器*/
#define  System_Windows
#define  Process_X86 
#endif
#ifdef _M_X64/*64bit AMD and Intel处理器(VC2008及以后)*/
#define  System_Windows
#define  Process_X64
#endif
#ifdef _M_IX64/* 64bit Itanium处理器*/
#define  System_Windows
#define  Process_X64
#endif
#ifdef _M_AMD64/*64bit AMD处理器 (VC2008以前)*/
#define  System_Windows
#define  Process_X64
#endif
/*■■■■■■■■■■■■■■■■■■■■应该在上面全面判断后才这里确认*/
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
#include <SDKDDKVer.h>/*兼容以前的系统*/
#include <tchar.h>
//#include "resource.h"//资源文件
#include <bitset>/*二进制*/
//#include <Afxwin.h>
//#include <afxwin.h>
#include <conio.h>/*需要在atlstr.h之前*/
#include"atlstr.h"/*控制台使用CString类,CRect,TRACE函数等,debug工程运行库为"多线程(MT)"或为"多线程DLL(/MD)"无法使用*/
#include <atlimage.h>/*使用CImage,控制台使用CString类,TRACE函数等,debug工程运行库为"多线程(MT)"或为"多线程DLL(/MD)"无法使用*/
/*---------------------------------------*/
#include<winSock2.h>/*windows网络编程,需要在windows.h之前*/
#include "Winhttp.h" 
#include <ws2tcpip.h>/*WSASend/WSARecv*/
#include <Ws2spi.h>/*WSPSend/WSPRecv*/
/*---------------------------------------*/
#define INITGUID/*必须在<Guiddef.h>之前,加载策略组*/
#include <Guiddef.h>/*策略组*/
#include <Gpedit.h>/*策略组CLSID_GroupPolicyObject函数*/
#include <shlwapi.h>
#include <direct.h>/*新建文件夹,getcwd函数*/
#pragma warning(disable: 4996)//getcwd
#include<ctime>/*系统时间*/
#include <tlhelp32.h>
#include <TlHelp32.h> //进程函数PROCESSENTRY32等
#include <Psapi.h>
#include <io.h>/*判断文件夹*/
#include <iphlpapi.h>/*网络适配器信息*/
#include <fstream>/*读写文件*/
#include <string>
#include <Process.h>
#define WIN32_LEAN_AND_MEAN/*从Windows头中排除极少使用的资料*/
#include <windows.h>/*GetPixel函数,窗口,Sleep,剪切板*/
#include <sys/timeb.h>/*通常包含time.h*/
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
#pragma comment(lib,"ws2_32.lib")/*windows网络编程*/
#pragma comment(lib,"psapi.lib")
#pragma comment(lib, "shlwapi.lib")
#define myhtons(A)(((WORD)(A)&0XFF00)>>8)|(((WORD)(A)&0X00FF)<<8)/*网络编程*/
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)/*网络编程*/
#endif
/*■■■■■■■■■■■■■■■■■■■■这部分属于跨平台的*/
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