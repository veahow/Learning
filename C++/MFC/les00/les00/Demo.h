/* les00 */
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
};

CDemoApp theApp;

