/* les05 */

#include "Demo.h"
#include "math.h"

BOOL CDemoApp::InitInstance()    // MFC��ں���
{
	CDemoWnd *pMainWnd = NULL;
	pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("My First MFC Program"));

	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;

	return TRUE;
}

CDemoWnd::CDemoWnd()    // ���캯��
{
	m_nMapMode = MM_TEXT;
}

CDemoWnd::~CDemoWnd()    // ��������
{
}

BEGIN_MESSAGE_MAP(CDemoWnd, CFrameWnd)
	ON_MESSAGE(WM_LBUTTONDOWN, OnLButtonDown)
	ON_MESSAGE(WM_RBUTTONDOWN, OnRButtonDown)
	ON_MESSAGE(WM_PAINT, OnPaint)
END_MESSAGE_MAP()

LRESULT CDemoWnd::OnLButtonDown(
	WPARAM wParam, LPARAM lParam)
{
	m_nMapMode = MM_HIMETRIC;
	InvalidateRect(NULL);
	return 0;
}

LRESULT CDemoWnd::OnRButtonDown(
	WPARAM wParam, LPARAM lParam)
{
	m_nMapMode = MM_LOMETRIC;
	InvalidateRect(NULL);    // ����WM_PAINT
	return 0;
}

LRESULT CDemoWnd::OnPaint(
	WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);

	if(m_nMapMode == MM_TEXT)
	{
		dc.Rectangle(100, 100, 400, 400);
		dc.SelectStockObject(GRAY_BRUSH);
		dc.Ellipse(100, 100, 400, 400);
	}else{
		dc.SetMapMode(m_nMapMode);
		dc.Rectangle(100, -100, 400, -400);
		dc.SelectStockObject(GRAY_BRUSH);
		dc.Ellipse(100, -100, 400, -400);
	}

	return 0;
}