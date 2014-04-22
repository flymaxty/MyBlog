#如何使用C++读取配置文件（ini）

##**ini文件简介**

ini是我们常见到的配置文件格式之一。

>ini是微软Windows操作系统中的文件扩展名（也常用在其他系统）。

>INI是英文“初始化（Initial）”的缩写。正如该术语所表示的，INI文件被用来对操作系统或特定程序初始化或进行参数设置。
>
>[百度百科](http://baike.baidu.com/view/1296365.htm)

通过它，可以将经常需要改变的参数保存起来（而且还可读），使程序更加的灵活。

这里有一个ini文件的示例。

	[School]
	ip = 10.15.40.123
	mask = 255.255.255.0
	gateway = 10.15.40.1
	dns = 211.82.96.1
	
	[Match]
	ip = 172.17.29.120
	mask = 255.255.255.0
	gateway = 172.17.29.1
	dns = 0.0.0.0


文件中保存的是不同场合下的IP设置参数。

在此之前，我曾介绍过如何用Python3读取ini配置，下面我将说明如何使用C++进行配置文件的生成和读取。

##**C++读取方法**

首先，C++读取ini配置需要用到`Windows.h`头文件。

	#include "Windows.h"

之后我们需要给出配置文件的路径。

	//配置文件的路径
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, ".\\IpConfig.ini");

接下来，我们可以使用`WritePrivateProfileString()`向配置文件中添加内容。

	WritePrivateProfileString("Hotel", "IP", "10.15.40.123", lpPath);
	WritePrivateProfileString("Hotel", "Mask", "255.255.255.0", lpPath);
	WritePrivateProfileString("Hotel", "Gateway", "10.15.40.1", lpPath);
	WritePrivateProfileString("Hotel", "DNS", "211.82.96.1", lpPath);

与Python相比，C++的写入工作在调用`WritePrivateProfileString()`时已经完成，所以不需要额外的代码。

以上就是写入配置文件的过程。

接下来我们使用`GetPrivateProfileString()`来读取刚才写入配置文件中的参数。

	LPTSTR Ip=new char[16];
	LPTSTR Mask=new char[16];
	LPTSTR Gateway=new char[16];
	LPTSTR DNS=new char[16];

	GetPrivateProfileString("Match","Ip","NULL",Ip,100,lpPath);
	GetPrivateProfileString("Match","Mask","NULL",Mask,100,lpPath);
	GetPrivateProfileString("Match","Gateway","NULL",Gateway,100,lpPath);
	GetPrivateProfileString("Match","DNS","NULL",DNS,100,lpPath);

	cout<<Ip<<endl;
	cout<<Mask<<endl;
	cout<<Gateway<<endl;
	cout<<DNS<<endl;

其中`GetPrivateProfileString()`函数中，第5个参数是缓冲区最大字符数量，这里定为100，其实可以直接指定为你要读取的值的实际大小。

##**完整示例**

下面是一个完整的示例程序，他将生成一个`IpConfig.ini`的配置文件，再读取文件中的数据，输出到屏幕上。

	#include "iostream.h"
	#include "Windows.h"
	#include <string>
	
	using namespace std;
	
	int main()
	{
		LPTSTR lpPath = new char[MAX_PATH];
		
		strcpy(lpPath, ".\\IpConfig.ini");
		
		WritePrivateProfileString("Hotel", "IP", "10.15.40.123", lpPath);
		WritePrivateProfileString("Hotel", "Mask", "255.255.255.0", lpPath);
		WritePrivateProfileString("Hotel", "Gateway", "10.15.40.1", lpPath);
		WritePrivateProfileString("Hotel", "DNS", "211.82.96.1", lpPath);
		
		WritePrivateProfileString("Match", "IP", "172.17.29.120", lpPath);
		WritePrivateProfileString("Match", "Mask", "255.255.255.0", lpPath);
		WritePrivateProfileString("Match", "Gateway", "172.17.29.1", lpPath);
		WritePrivateProfileString("Match", "DNS", "0.0.0.0", lpPath);
	
		
		LPTSTR Ip=new char[16];
		LPTSTR Mask=new char[16];
		LPTSTR Gateway=new char[16];
		LPTSTR DNS=new char[16];
	
		GetPrivateProfileString("Match","Ip","NULL",Ip,100,lpPath);
		GetPrivateProfileString("Match","Mask","NULL",Mask,100,lpPath);
		GetPrivateProfileString("Match","Gateway","NULL",Gateway,100,lpPath);
		GetPrivateProfileString("Match","DNS","NULL",DNS,100,lpPath);
	
		cout<<Ip<<endl;
		cout<<Mask<<endl;
		cout<<Gateway<<endl;
		cout<<DNS<<endl;
	
		delete [] lpPath;
		delete [] Ip;
		delete [] Mask;
		delete [] Gateway;
		delete [] DNS;
		
		return 0;
	}

##**总结**

与Python一样，C++读取ini文件也比较简单，当然这里我给出的只是一些简单的使用方法，如果想用更高级的功能，可以进一步参考MSDN中相关的文档。