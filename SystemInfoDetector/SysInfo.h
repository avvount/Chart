#pragma once
#include "windows.h"

#define INFO_LENGTH 128

struct SystemInfoDef
{
	//Windows版本
	WCHAR szOperatingSystem[INFO_LENGTH];
	INT iWindowsVer; //eg. Windows7 => 61
	INT iServicePackVer; //eg. Major * 10 + Minor

	//.net Framework版本
	WCHAR szDotNetFramework[INFO_LENGTH];
	INT iFrameworkVer; //eg. 4.5 => 45
	BOOL bIsFullVersion;

	//运行可行性
	WCHAR szFeasibility[INFO_LENGTH];

	BOOL bNeedXpSp3;
	BOOL bNeedDotNetFx4;
};

class CSysInfo
{
public:
	CSysInfo();
	~CSysInfo();

	SystemInfoDef* GetAll();

private:
	void GetDotNetFramework();
	void GetOperatingSystem();
	void GetFeasibility();
	SystemInfoDef m_info;
};
