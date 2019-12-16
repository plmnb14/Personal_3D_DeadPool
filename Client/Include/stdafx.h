// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <ctime>
#include <process.h> // _beginthreadex �Լ��� ȣ���ϱ� ���ؼ� �ݵ�� �����ؾ� ��
#include <iostream>

using namespace std;

// Header
#include "Export_System.h"
#include "Export_Resources.h"
#include "Export_Utility.h"

// lib
#pragma comment(lib, "Engine.lib")

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif

#include <crtdbg.h>

#pragma comment(linker,"/entry:wWinMainCRTStartup /subsystem:console")

// Client Headers
#include "Define.h"

#include <crtdbg.h>