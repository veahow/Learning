/* les08 */
#include "afxwin.h"

class CDemoApp:public CWinApp
{
public:
	BOOL InitInstance();    // 初始化函数
};

class CPic    // 坐标类
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
	CDemoWnd();     // 构造函数
	~CDemoWnd();    // 析构函数

public:
	// 消息映射函数
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);    // 左键按下
	LRESULT OnMouseMove(WPARAM wParam, LPARAM lParam);      // 拖动鼠标 
	LRESULT OnLButtonUp(WPARAM wParam, LPARAM lParam);      // 左键放开
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);          // 刷新消息
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

CDemoApp theApp;            // 创建全局应用程序对象