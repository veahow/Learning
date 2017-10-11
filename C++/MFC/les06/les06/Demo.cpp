#include "Demo.h"

BOOL CDemoApp::InitInstance()    // MFC��ں���
{
	CDemoWnd *pMainWnd = NULL;
	pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("Demo MFC Key and Mouse"));

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
	// ʹ��������֧���if
	if(wParam == 'A') AfxMessageBox(_T("�㰴������ĸA����"));
	if(wParam == 'B') AfxMessageBox(_T("�㰴������ĸB����"));

	// ʹ��������֧���switch
	switch(wParam)
	{
	case VK_LEFT:
		AfxMessageBox(_T("�㰴���ˡ�����"));
		break;
	case VK_RIGHT:
		AfxMessageBox(_T("�㰴���ˡ�����"));
		break;
	case VK_UP:
		AfxMessageBox(_T("�㰴���ˡ�����"));
		break;
	case VK_DOWN:
		AfxMessageBox(_T("�㰴���ˡ�����"));
		break;
	}

	return 0;
}