/* les00 */
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
};

CDemoApp theApp;

