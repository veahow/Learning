#include "Demo.h"

BOOL CDemoApp::InitInstance()    // MFC入口函数
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
END_MESSAGE_MAP()

LRESULT CDemoWnd::OnLButtonDown(
	WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(_T("你按下了鼠标左键！"));
	return 0;
}