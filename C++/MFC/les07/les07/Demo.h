/* les07 */
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
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);    // 左键按下消息所映射的处理函数
	LRESULT OnMouseMove(WPARAM wParam, LPARAM lParam);    // 鼠标拖动消息所映射的处理函数
	LRESULT OnLButtonUp(WPARAM wParam, LPARAM lParam);    // 左键放开消息所映射的处理函数
	DECLARE_MESSAGE_MAP()    // 消息映射宏

public:
	// 第一组定点坐标
	int m_nX0;
	int m_nY0;

	// 第二组定点坐标
	int m_nX1;
	int m_nY1;
};

CDemoApp theApp;