#include "afxwin.h"

class CDemoApp:public CWinApp
{
public:
	BOOL InitInstance();
};

class CDemoWnd:public CFrameWnd
{
public:
	CDemoWnd();    // ���캯��
	~CDemoWnd();    // ��������

public:
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnRButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	int m_nMapMode;
};

CDemoApp theApp;    // ����Ӧ�ó������