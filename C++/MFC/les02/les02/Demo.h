/* les02 */
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
	LRESULT OnLButtonDown(
		WPARAM wParam,
		LPARAM lParam);

	DECLARE_MESSAGE_MAP();
};

CDemoApp theApp;    // ����Ӧ�ó������