#include "Demo.h"

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
}

CDemoWnd::~CDemoWnd()    // ��������
{
}

BEGIN_MESSAGE_MAP(CDemoWnd, CFrameWnd)
	ON_MESSAGE(WM_LBUTTONDOWN, OnLButtonDown)
	ON_MESSAGE(WM_PAINT, OnPaint)
END_MESSAGE_MAP()


LRESULT CDemoWnd::OnLButtonDown(
	WPARAM wParam, LPARAM lParam)
{
	//AfxMessageBox(_T("�㰴������������"));
	CClientDC dc(this);
	dc.Ellipse(50, 50, 250, 250);
	return 0;
}

LRESULT CDemoWnd::OnPaint(
	WPARAM wParam, LPARAM lParam)
{
	return 0;
}