/* les00 */
#include "Demo.h"

BOOL CDemoApp::InitInstance()
{
	CDemoWnd *pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("MFCÑÝÊ¾³ÌÐò"));
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;

	return TRUE;
}

CDemoWnd::CDemoWnd()
{
}

CDemoWnd::~CDemoWnd()
{
}