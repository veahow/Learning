/* les08 */
#include "afxwin.h"

class CDemoApp:public CWinApp
{
public:
	BOOL InitInstance();
};

class CPic
{
public:
	int m_nPicType;    // 0:���� 1:��Բ
	int m_nX0;
	int m_nY0;
	int m_nX1;
	int m_nY1;
};

class CDemoWnd:public CFrameWnd
{
public:
	CDemoWnd();    // ���캯��
	~CDemoWnd();    // ��������

public:
	LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
	LRESULT OnMouseMove(WPARAM wParam, LPARAM lParam);
	LRESULT OnLButtonUp(WPARAM wParam, LPARAM lParam);
	LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

public:
	// ��һ�鶨λ������
	int m_nX0;
	int m_nY0;

	// �ڶ��鶨λ������
	int m_nX1;
	int m_nY1;

	CPic m_Pic[100];
	int m_nPicNum;
};

CDemoApp theApp;    // ����Ӧ�ó������