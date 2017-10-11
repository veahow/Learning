/* les04 */
#include "Demo.h"
#include "math.h"
#define PI 3.14159

BOOL CDemoApp::InitInstance()
{
	CDemoWnd *pMainWnd = NULL;
	pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("My First MFC Program"));

	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;

	return TRUE;
}

CDemoWnd::CDemoWnd()    // 构造函数
{
}

CDemoWnd::~CDemoWnd()    // 析构函数
{
}

BEGIN_MESSAGE_MAP(CDemoWnd, CFrameWnd)
	ON_MESSAGE(WM_LBUTTONDOWN, OnLButtonDown)
	ON_MESSAGE(WM_PAINT, OnPaint)
END_MESSAGE_MAP()

LRESULT CDemoWnd::OnLButtonDown(
	WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT CDemoWnd::OnPaint(
	WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);
	CPen PenGrid;
	CPen *pOldPen = NULL;
	PenGrid.CreatePen(PS_DASH, 1, RGB(255, 0, 0));
	pOldPen = dc.SelectObject(&PenGrid);

	// 绘制网格
	for(int k = 0; k < 7; ++k)
	{
		dc.MoveTo(50, 50 + k*50);
		dc.LineTo(550, 50 + k*50);
	}
	for(int k = 0; k < 11; ++k)
	{
		dc.MoveTo(50 + k*50, 50);
		dc.LineTo(50 + k*50, 350);
	}
	POINT point[100];    // 绘制曲线
	for(int k = 0; k < 100; ++k)
	{
		point[k].x = 50 + 5*k;
		point[k].y = 200 - 150*sin(0.01*4*PI*k);
	}
	CPen PenCurve;
	PenCurve.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	dc.SelectObject(&PenCurve);
	dc.Polyline(point, 100);
	dc.SelectObject(pOldPen);
	return 0;
}