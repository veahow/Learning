/* les07 */
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
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);    // ���������Ϣ��ӳ��Ĵ�����
	LRESULT OnMouseMove(WPARAM wParam, LPARAM lParam);    // ����϶���Ϣ��ӳ��Ĵ�����
	LRESULT OnLButtonUp(WPARAM wParam, LPARAM lParam);    // ����ſ���Ϣ��ӳ��Ĵ�����
	DECLARE_MESSAGE_MAP()    // ��Ϣӳ���

public:
	// ��һ�鶨������
	int m_nX0;
	int m_nY0;

	// �ڶ��鶨������
	int m_nX1;
	int m_nY1;
};

CDemoApp theApp;