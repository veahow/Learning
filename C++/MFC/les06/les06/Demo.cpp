#include "Demo.h"

BOOL CDemoApp::InitInstance()    // MFC入口函数
{
	CDemoWnd *pMainWnd = NULL;
	pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("Demo MFC Key and Mouse"));

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
	ON_MESSAGE(WM_PAINT, OnPaint)
	ON_MESSAGE(WM_KEYDOWN, OnKeyDown)
END_MESSAGE_MAP()

LRESULT CDemoWnd::OnPaint(
	WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);

	return 0;
}

LRESULT CDemoWnd::OnKeyDown(
	WPARAM wParam, LPARAM lParam)
{
	// 使用条件分支语句if
	if(wParam == 'A') AfxMessageBox(_T("你按下了字母A键！"));
	if(wParam == 'B') AfxMessageBox(_T("你按下了字母B键！"));

	// 使用条件分支语句switch
	switch(wParam)
	{
	case VK_LEFT:
		AfxMessageBox(_T("你按下了←键！"));
		break;
	case VK_RIGHT:
		AfxMessageBox(_T("你按下了→键！"));
		break;
	case VK_UP:
		AfxMessageBox(_T("你按下了↑键！"));
		break;
	case VK_DOWN:
		AfxMessageBox(_T("你按下了↓键！"));
		break;
	}

	return 0;
}