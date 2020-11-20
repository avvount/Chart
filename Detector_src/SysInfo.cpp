#include "SysInfo.h"
#include <windows.h>
#include <strsafe.h>

typedef void (WINAPI *PGNSI)(LPSYSTEM_INFO);
typedef BOOL (WINAPI *PGPI)(DWORD, DWORD, DWORD, DWORD, PDWORD);

CSysInfo::CSysInfo()
{
	ZeroMemory(&m_info, sizeof(m_info));
}

CSysInfo::~CSysInfo()
{

}

SystemInfoDef* CSysInfo::GetAll()
{
	GetDotNetFramework();
	GetOperatingSystem();
	GetFeasibility();
	return &m_info;
}

void CSysInfo::GetDotNetFramework()
{
	DWORD dwInstall;
	DWORD dwRelease;
	DWORD dwSP;
	DWORD dwSize;
	HKEY hkResult;
	m_info.bIsFullVersion = false;
	//检测 HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v4\Full\Install - 1
	//         if(HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v4\Full\Release - 378389)
	//             => .net Framework 4.5 Full
	//         else
	//             => .net Framework 4.0 Full
	if(ERROR_SUCCESS==RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v4\\Full", 0, KEY_READ, &hkResult))
	{
		dwSize = sizeof(dwInstall);
		if(ERROR_SUCCESS==RegQueryValueExW(hkResult, L"Install", 0, 0, (LPBYTE)&dwInstall, &dwSize)
			&& 1==dwInstall)
		{
			if (ERROR_SUCCESS==RegQueryValueExW(hkResult, L"Release", 0, 0, (LPBYTE)&dwRelease, &dwSize)
				&& 0x0005C615==dwRelease)
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 4.5 Full");
				m_info.iFrameworkVer = 45;
				m_info.bIsFullVersion = true;
			}
			else
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 4.0 Full");
				m_info.iFrameworkVer = 40;
				m_info.bIsFullVersion = true;
			}
			return;
		}
		RegCloseKey(hkResult);
	}
	
	//检测 HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v4\Client\Install - 1
	//         if(HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v4\Client\Release - 378389)
	//             => .net Framework 4.5 Client Profile
	//         else
	//             => .net Framework 4.0 Client Profile
	if(ERROR_SUCCESS==RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v4\\Client", 0, KEY_READ, &hkResult))
	{
		dwSize = sizeof(dwInstall);
		if(ERROR_SUCCESS==RegQueryValueExW(hkResult, L"Install", 0, 0, (LPBYTE)&dwInstall, &dwSize)
			&& 1==dwInstall)
		{
			if (ERROR_SUCCESS==RegQueryValueExW(hkResult, L"Release", 0, 0, (LPBYTE)&dwRelease, &dwSize)
				&& 0x0005C615==dwRelease)
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 4.5 Client Profile");
				m_info.iFrameworkVer = 45;
			}
			else
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 4.0 Client Profile");
				m_info.iFrameworkVer = 40;
			}
			return;
		}
		RegCloseKey(hkResult);
	}

	//检测 HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v3.5\Install - 1
	//         if(HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v3.5\SP - 1)
	//             => .net Framework 3.5 Service Pack 1
	//         else
	//             => .net Framework 3.5
	if(ERROR_SUCCESS==RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v3.5", 0, KEY_READ, &hkResult))
	{
		dwSize = sizeof(dwInstall);
		if(ERROR_SUCCESS==RegQueryValueExW(hkResult, L"Install", 0, 0, (LPBYTE)&dwInstall, &dwSize)
			&& 1==dwInstall)
		{
			if (ERROR_SUCCESS==RegQueryValueExW(hkResult, L"SP", 0, 0, (LPBYTE)&dwSP, &dwSize)
				&& 1==dwSP)
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 3.5 Service Pack 1");
			}
			else
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 3.5");
			}
			m_info.iFrameworkVer = 35;
			return;
		}
		RegCloseKey(hkResult);
	}

	//检测 HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v3.0\Install - 1
	//         if(HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v3.0\SP - 2)
	//             => .net Framework 3.0 Service Pack 2
	//         else if(HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v3.0\SP - 1)
	//             => .net Framework 3.0 Service Pack 1
	//         else
	//             => .net Framework 3.0
	if(ERROR_SUCCESS==RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v3.0", 0, KEY_READ, &hkResult))
	{
		dwSize = sizeof(dwInstall);
		if(ERROR_SUCCESS==RegQueryValueExW(hkResult, L"Install", 0, 0, (LPBYTE)&dwInstall, &dwSize)
			&& 1==dwInstall)
		{
			if (ERROR_SUCCESS==RegQueryValueExW(hkResult, L"SP", 0, 0, (LPBYTE)&dwSP, &dwSize)
				&&(2==dwSP || 1==dwSP))
			{
				if(2==dwSP)
				{
					StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 3.0 Service Pack 2");
				}
				else
				{
					StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 3.0 Service Pack 1");
				}
			}
			else
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 3.0");
			}
			m_info.iFrameworkVer = 30;
			return;
		}
		RegCloseKey(hkResult);
	}
	//检测 HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v2.0.50727\Install - 1
	//         if(HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v2.0.50727\SP - 2)
	//             => .net Framework 2.0 Service Pack 2
	//         else if(HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v2.0.50727\SP - 1)
	//             => .net Framework 2.0 Service Pack 1
	//         else
	//             => .net Framework 2.0
	if(ERROR_SUCCESS==RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v2.0.50727", 0, KEY_READ, &hkResult))
	{
		dwSize = sizeof(dwInstall);
		if(ERROR_SUCCESS==RegQueryValueExW(hkResult, L"Install", 0, 0, (LPBYTE)&dwInstall, &dwSize)
			&& 1==dwInstall)
		{
			if (ERROR_SUCCESS==RegQueryValueExW(hkResult, L"SP", 0, 0, (LPBYTE)&dwSP, &dwSize)
				&&(2==dwSP || 1==dwSP))
			{
				if(2==dwSP)
				{
					StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 2.0 Service Pack 2");
				}
				else
				{
					StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 2.0 Service Pack 1");
				}
			}
			else
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 2.0");
			}
			m_info.iFrameworkVer = 20;
			return;
		}
		RegCloseKey(hkResult);
	}

	//检测 HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v1.1.4322\Install - 1
	//         else if(HKLM\SOFTWARE\Microsoft\NET Framework Setup\NDP\v1.1.4322\SP - 1)
	//             => .net Framework 1.1 Service Pack 1
	//         else
	//             => .net Framework 1.1
	if(ERROR_SUCCESS==RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP\\v1.1.4322", 0, KEY_READ, &hkResult))
	{
		dwSize = sizeof(dwInstall);
		if(ERROR_SUCCESS==RegQueryValueExW(hkResult, L"Install", 0, 0, (LPBYTE)&dwInstall, &dwSize)
			&& 1==dwInstall)
		{
			if (ERROR_SUCCESS==RegQueryValueExW(hkResult, L"SP", 0, 0, (LPBYTE)&dwSP, &dwSize)
				&& 1==dwSP)
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 1.1 Service Pack 1");
			}
			else
			{
				StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L".net Framework 1.1");
			}
			m_info.iFrameworkVer = 11;
			return;
		}
		RegCloseKey(hkResult);
	}

	StringCchCopyW(m_info.szDotNetFramework, INFO_LENGTH, L"No .net Framework detected.");
	m_info.iFrameworkVer = 0;
}

void CSysInfo::GetOperatingSystem()
{
	OSVERSIONINFOEX osvi;
	SYSTEM_INFO si;
	PGNSI pGNSI;
	PGPI pGPI;
	BOOL bOsVersionInfoEx;
	DWORD dwType;

	ZeroMemory(&si, sizeof(SYSTEM_INFO));
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));

	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	bOsVersionInfoEx = GetVersionEx((OSVERSIONINFO*) &osvi);

	m_info.iWindowsVer = osvi.dwMajorVersion*10+osvi.dwMinorVersion;
	m_info.iServicePackVer = osvi.wServicePackMajor*10+osvi.wServicePackMinor;

	LPWSTR pszOS = m_info.szOperatingSystem;

	pGNSI = (PGNSI) GetProcAddress(
		GetModuleHandle(L"kernel32.dll"), 
		"GetNativeSystemInfo");
	if(NULL != pGNSI)
		pGNSI(&si);
	else
		GetSystemInfo(&si);

	if ( VER_PLATFORM_WIN32_NT==osvi.dwPlatformId && 
		osvi.dwMajorVersion > 4 )
	{
		StringCchCopyW(pszOS, INFO_LENGTH, L"Microsoft ");

		if ( osvi.dwMajorVersion == 6 )
		{
			if( osvi.dwMinorVersion == 0 )
			{
				if( osvi.wProductType == VER_NT_WORKSTATION )
					StringCchCatW(pszOS, INFO_LENGTH, L"Windows Vista ");
				else StringCchCatW(pszOS, INFO_LENGTH, L"Windows Server 2008 " );
			}

			if ( osvi.dwMinorVersion == 1 )
			{
				if( osvi.wProductType == VER_NT_WORKSTATION )
					StringCchCatW(pszOS, INFO_LENGTH, L"Windows 7 ");
				else StringCchCatW(pszOS, INFO_LENGTH, L"Windows Server 2008 R2 " );
			}

			pGPI = (PGPI) GetProcAddress(
				GetModuleHandle(L"kernel32.dll"), 
				"GetProductInfo");

			pGPI( osvi.dwMajorVersion, osvi.dwMinorVersion, 0, 0, &dwType);

			switch( dwType )
			{
			case PRODUCT_ULTIMATE:
				StringCchCatW(pszOS, INFO_LENGTH, L"Ultimate Edition" );
				break;
			case PRODUCT_PROFESSIONAL:
				StringCchCatW(pszOS, INFO_LENGTH, L"Professional" );
				break;
			case PRODUCT_HOME_PREMIUM:
				StringCchCatW(pszOS, INFO_LENGTH, L"Home Premium Edition" );
				break;
			case PRODUCT_HOME_BASIC:
				StringCchCatW(pszOS, INFO_LENGTH, L"Home Basic Edition" );
				break;
			case PRODUCT_ENTERPRISE:
				StringCchCatW(pszOS, INFO_LENGTH, L"Enterprise Edition" );
				break;
			case PRODUCT_BUSINESS:
				StringCchCatW(pszOS, INFO_LENGTH, L"Business Edition" );
				break;
			case PRODUCT_STARTER:
				StringCchCatW(pszOS, INFO_LENGTH, L"Starter Edition" );
				break;
			case PRODUCT_CLUSTER_SERVER:
				StringCchCatW(pszOS, INFO_LENGTH, L"Cluster Server Edition" );
				break;
			case PRODUCT_DATACENTER_SERVER:
				StringCchCatW(pszOS, INFO_LENGTH, L"Datacenter Edition" );
				break;
			case PRODUCT_DATACENTER_SERVER_CORE:
				StringCchCatW(pszOS, INFO_LENGTH, L"Datacenter Edition (core installation)" );
				break;
			case PRODUCT_ENTERPRISE_SERVER:
				StringCchCatW(pszOS, INFO_LENGTH, L"Enterprise Edition" );
				break;
			case PRODUCT_ENTERPRISE_SERVER_CORE:
				StringCchCatW(pszOS, INFO_LENGTH, L"Enterprise Edition (core installation)" );
				break;
			case PRODUCT_ENTERPRISE_SERVER_IA64:
				StringCchCatW(pszOS, INFO_LENGTH, L"Enterprise Edition for Itanium-based Systems" );
				break;
			case PRODUCT_SMALLBUSINESS_SERVER:
				StringCchCatW(pszOS, INFO_LENGTH, L"Small Business Server" );
				break;
			case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
				StringCchCatW(pszOS, INFO_LENGTH, L"Small Business Server Premium Edition" );
				break;
			case PRODUCT_STANDARD_SERVER:
				StringCchCatW(pszOS, INFO_LENGTH, L"Standard Edition" );
				break;
			case PRODUCT_STANDARD_SERVER_CORE:
				StringCchCatW(pszOS, INFO_LENGTH, L"Standard Edition (core installation)" );
				break;
			case PRODUCT_WEB_SERVER:
				StringCchCatW(pszOS, INFO_LENGTH, L"Web Server Edition" );
				break;
			}
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2 )
		{
			if( GetSystemMetrics(SM_SERVERR2) )
				StringCchCatW(pszOS, INFO_LENGTH, L"Windows Server 2003 R2, ");
			else if ( osvi.wSuiteMask & VER_SUITE_STORAGE_SERVER )
				StringCchCatW(pszOS, INFO_LENGTH, L"Windows Storage Server 2003");
			else if ( osvi.wSuiteMask & VER_SUITE_WH_SERVER )
				StringCchCatW(pszOS, INFO_LENGTH, L"Windows Home Server");
			else if( osvi.wProductType == VER_NT_WORKSTATION &&
				si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64)
			{
				StringCchCatW(pszOS, INFO_LENGTH, L"Windows XP Professional x64 Edition");
			}
			else StringCchCatW(pszOS, INFO_LENGTH, L"Windows Server 2003, ");

			// Test for the server type.
			if ( osvi.wProductType != VER_NT_WORKSTATION )
			{
				if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_IA64 )
				{
					if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
						StringCchCatW(pszOS, INFO_LENGTH, L"Datacenter Edition for Itanium-based Systems" );
					else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
						StringCchCatW(pszOS, INFO_LENGTH, L"Enterprise Edition for Itanium-based Systems" );
				}

				else if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64 )
				{
					if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
						StringCchCatW(pszOS, INFO_LENGTH, L"Datacenter x64 Edition" );
					else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
						StringCchCatW(pszOS, INFO_LENGTH, L"Enterprise x64 Edition" );
					else StringCchCatW(pszOS, INFO_LENGTH, L"Standard x64 Edition" );
				}

				else
				{
					if ( osvi.wSuiteMask & VER_SUITE_COMPUTE_SERVER )
						StringCchCatW(pszOS, INFO_LENGTH, L"Compute Cluster Edition" );
					else if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
						StringCchCatW(pszOS, INFO_LENGTH, L"Datacenter Edition" );
					else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
						StringCchCatW(pszOS, INFO_LENGTH, L"Enterprise Edition" );
					else if ( osvi.wSuiteMask & VER_SUITE_BLADE )
						StringCchCatW(pszOS, INFO_LENGTH, L"Web Edition" );
					else StringCchCatW(pszOS, INFO_LENGTH, L"Standard Edition" );
				}
			}
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1 )
		{
			StringCchCatW(pszOS, INFO_LENGTH, L"Windows XP ");
			if( osvi.wSuiteMask & VER_SUITE_PERSONAL )
				StringCchCatW(pszOS, INFO_LENGTH, L"Home Edition" );
			else StringCchCatW(pszOS, INFO_LENGTH, L"Professional" );
		}

		if ( osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0 )
		{
			StringCchCatW(pszOS, INFO_LENGTH, L"Windows 2000 ");

			if ( osvi.wProductType == VER_NT_WORKSTATION )
			{
				StringCchCatW(pszOS, INFO_LENGTH, L"Professional" );
			}
			else 
			{
				if( osvi.wSuiteMask & VER_SUITE_DATACENTER )
					StringCchCatW(pszOS, INFO_LENGTH, L"Datacenter Server" );
				else if( osvi.wSuiteMask & VER_SUITE_ENTERPRISE )
					StringCchCatW(pszOS, INFO_LENGTH, L"Advanced Server" );
				else StringCchCatW(pszOS, INFO_LENGTH, L"Server" );
			}
		}

		// Include service pack (if any) and build number.
		size_t stLen = 0;
		StringCchLength(osvi.szCSDVersion, 128, &stLen);
		if( stLen > 0 )
		{
			StringCchCatW(pszOS, INFO_LENGTH, L" ");
			StringCchCatW(pszOS, INFO_LENGTH, osvi.szCSDVersion);
		}

		TCHAR buf[80];

		StringCchPrintf( buf, 80, L" (build %d)", osvi.dwBuildNumber);
		StringCchCatW(pszOS, INFO_LENGTH, buf);

		if ( osvi.dwMajorVersion >= 6 )
		{
			if ( si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64 )
				StringCchCatW(pszOS, INFO_LENGTH, L", 64-bit" );
			else if (si.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_INTEL )
				StringCchCatW(pszOS, INFO_LENGTH, L", 32-bit");
		}
	}
	else
	{  
		StringCchCatW(pszOS, INFO_LENGTH, L"Unknown Windows edition.");
	}
}

void CSysInfo::GetFeasibility()
{
	m_info.bNeedXpSp3 = FALSE;
	m_info.bNeedDotNetFx4 = FALSE;
	if(m_info.iFrameworkVer>=40)
	{
		StringCchCopyW(m_info.szFeasibility, INFO_LENGTH, L"满足运行需求");
	}
	else
	{
		if(m_info.iWindowsVer==60 && m_info.iServicePackVer<10) //Vista
		{
			StringCchCopyW(m_info.szFeasibility, INFO_LENGTH, L"需要先后安装Windows Vista SP1 和 .net Framework 4.0");
			m_info.bNeedDotNetFx4 = TRUE;
		}
		else if(m_info.iWindowsVer==51 && m_info.iServicePackVer<30) //XP
		{
			StringCchCopyW(m_info.szFeasibility, INFO_LENGTH, L"需要先后安装Windows XP SP3 和 .net Framework 4.0");
			m_info.bNeedXpSp3 = TRUE;
			m_info.bNeedDotNetFx4 = TRUE;
		}
		else
		{
			StringCchCopyW(m_info.szFeasibility, INFO_LENGTH, L"需要安装 .net Framework 4.0");
			m_info.bNeedDotNetFx4 = TRUE;
		}
	}
}
