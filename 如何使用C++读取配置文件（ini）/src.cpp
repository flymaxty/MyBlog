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