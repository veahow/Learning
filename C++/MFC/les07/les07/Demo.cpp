/* les07 */
#include "Demo.h"

BOOL CDemoApp::InitInstance()
{
	CDemoWnd *pMainWnd = NULL;
	pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("Demo MFC Drawing"));

	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;

	return TRUE;
}

CDemoWnd::CDemoWnd()    // 析构函数
{
	// 第一组定点坐标初始化为0
	m_nX0 = 0;
	m_nY0 = 0;

	// 第二组定点坐标初始化为0
	m_nX1 = 0;
	m_nY1 = 0;
}

CDemoWnd::~CDemoWnd()
{
}

BEGIN_MESSAGE_MAP(CDemoWnd, CFrameWnd)
	ON_MESSAGE(WM_LBUTTONDOWN, OnLButtonDown)
	ON_MESSAGE(WM_MOUSEMOVE, OnMouseMove)
	ON_MESSAGE(WM_LBUTTONUP, OnLButtonUp)
END_MESSAGE_MAP()

LRESULT CDemoWnd::OnLButtonDown(
	WPARAM wParam, LPARAM lParam)
{
	m_nX0 = LOWORD(lParam);
	m_nY0 = HIWORD(lParam);

	return 0;
}

LRESULT CDemoWnd::OnMouseMove(
	WPARAM wParam, LPARAM lParam)
{
	m_nX1 = LOWORD(lParam);
	m_nY1 = HIWORD(lParam);

	CClientDC dc(this);

	if((wParam & MK_CONTROL) && (wParam & MK_LBUTTON)) dc.Rectangle(
		m_nX0, m_nY0, m_nX1, m_nY1);

	if((wParam & MK_SHIFT) && (wParam & MK_LBUTTON)) dc.Ellipse(
		m_nX0, m_nY0, m_nX1, m_nY1);

	return 0;
}

LRESULT CDemoWnd::OnLButtonUp(
	WPARAM wParam, LPARAM lParam)
{
	m_nX1 = LOWORD(lParam);
	m_nY1 = HIWORD(lParam);

	CClientDC dc(this);

	if(wParam & MK_CONTROL) dc.Rectangle(
		m_nX0, m_nY0, m_nX1, m_nY1);

	if(wParam & MK_SHIFT) dc.Ellipse(
		m_nX0, m_nY0, m_nX1, m_nY1);

	return 0;
}