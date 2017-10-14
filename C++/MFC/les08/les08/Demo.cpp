/* les08 */
#include "Demo.h"

BOOL CDemoApp::InitInstance()    // MFC入口函数
{
	CDemoWnd *pMainWnd = NULL;
	pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("Demo MFC Drawing"));

	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;

	return TRUE;
}

CDemoWnd::CDemoWnd()    // 构造函数
{
	m_nX0 = 0;
	m_nY0 = 0;
	m_nX1 = 0;
	m_nY1 = 0;
	m_nPicNum = 0;
}

CDemoWnd::~CDemoWnd()    // 析构函数
{
}

BEGIN_MESSAGE_MAP(CDemoWnd, CFrameWnd)
	ON_MESSAGE(WM_LBUTTONDOWN, OnLButtonDown)
	ON_MESSAGE(WM_MOUSEMOVE, OnMouseMove)
	ON_MESSAGE(WM_LBUTTONUP, OnLButtonUp)
	ON_MESSAGE(WM_PAINT, OnPaint)
END_MESSAGE_MAP()

LRESULT CDemoWnd::OnPaint(
	WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);

	for(int i = 0; i < m_nPicNum; ++i)
	{
		if(m_Pic[i].m_nPicType == 0) dc.Rectangle(
			m_Pic[i].m_nX0, m_Pic[i].m_nY0,
			m_Pic[i].m_nX1, m_Pic[i].m_nY1);

		if(m_Pic[i].m_nPicType == 1) dc.Ellipse(
			m_Pic[i].m_nX0, m_Pic[i].m_nY0,
			m_Pic[i].m_nX1, m_Pic[i].m_nY1);
	}

	return 0;
}

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
	CClientDC dc(this);

	// 擦除旧图
	dc.SelectStockObject(WHITE_PEN);    // 白色画刷

	if((wParam & MK_CONTROL) &&
		(wParam & MK_LBUTTON)) dc.Rectangle(
		m_nX0, m_nY0, m_nX1, m_nY1);

	if((wParam & MK_SHIFT) &&
		(wParam & MK_LBUTTON)) dc.Ellipse(
		m_nX0, m_nY0, m_nX1, m_nY1);

	// 保存新坐标，绘制新的图形
	m_nX1 = LOWORD(lParam);
	m_nY1 = HIWORD(lParam);

	dc.SelectStockObject(BLACK_PEN);    // 黑色画刷

	if((wParam & MK_CONTROL) &&
		(wParam & MK_LBUTTON)) dc.Rectangle(
		m_nX0, m_nY0, m_nX1, m_nY1);

	if((wParam & MK_SHIFT) &&
		(wParam & MK_LBUTTON)) dc.Ellipse(
		m_nX0, m_nY0, m_nX1, m_nY1);

	return 0;
}

LRESULT CDemoWnd::OnLButtonUp(
	WPARAM wParam, LPARAM lParam)
{
	CClientDC dc(this);

	m_nX1 = LOWORD(lParam);
	m_nY1 = HIWORD(lParam);

	if(wParam & MK_CONTROL)
	{
		dc.Rectangle(m_nX0, m_nY0, m_nX1, m_nY1);
		m_Pic[m_nPicNum].m_nPicType = 0;
		m_Pic[m_nPicNum].m_nX0 = m_nX0;
		m_Pic[m_nPicNum].m_nY0 = m_nY0;
		m_Pic[m_nPicNum].m_nX1 = m_nX1;
		m_Pic[m_nPicNum].m_nY1 = m_nY1;
		m_nPicNum++;
	}

	if(wParam & MK_SHIFT)
	{
		dc.Ellipse(m_nX0, m_nY0, m_nX1, m_nY1);
		m_Pic[m_nPicNum].m_nPicType = 0;
		m_Pic[m_nPicNum].m_nX0 = m_nX0;
		m_Pic[m_nPicNum].m_nY0 = m_nY0;
		m_Pic[m_nPicNum].m_nX1 = m_nX1;
		m_Pic[m_nPicNum].m_nY1 = m_nY1;
		m_nPicNum++;
	}

	return 0;
}