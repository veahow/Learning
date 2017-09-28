#include "afxwin.h"

class CDemoApp:public CWinApp
{
public:
	BOOL InitInstance();
};

class CDemoWnd:public CFrameWnd
{
public:
	CDemoWnd();    // 构造函数
	~CDemoWnd();    // 析构函数

public:
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP();
};

CDemoApp theApp;    // 定义应用程序对象