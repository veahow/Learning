/* les08 */
#include "afxwin.h"

class CDemoApp:public CWinApp
{
public:
	BOOL InitInstance();
};

class CPic
{
public:
	int m_nPicType;    // 0:矩形 1:椭圆
	int m_nX0;
	int m_nY0;
	int m_nX1;
	int m_nY1;
};

class CDemoWnd:public CFrameWnd
{
public:
	CDemoWnd();    // 构造函数
	~CDemoWnd();    // 析构函数

public:
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnMouseMove(WPARAM wParam, LPARAM lParam);
	LRESULT OnLButtonUp(WPARAM wParam, LPARAM lParam);
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	// 第一组定位点坐标
	int m_nX0;
	int m_nY0;

	// 第二组定位点坐标
	int m_nX1;
	int m_nY1;

	CPic m_Pic[100];
	int m_nPicNum;
};

CDemoApp theApp;    // 定义应用程序对象