
// Demo02Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Demo02.h"
#include "Demo02Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDemo02Dlg �Ի���




CDemo02Dlg::CDemo02Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDemo02Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nBrushType = 0;
	m_nIsChecked = 0;
}

void CDemo02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_SOLID, m_nBrushType);
	DDX_Check(pDX, IDC_CHECK1, m_nIsChecked);
	DDX_Control(pDX, IDC_RED, m_Red);
	DDX_Control(pDX, IDC_GREEN, m_Green);
	DDX_Control(pDX, IDC_BLUE, m_Blue);
}

BEGIN_MESSAGE_MAP(CDemo02Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDemo02Dlg::OnBnClickedButton1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CDemo02Dlg ��Ϣ�������

BOOL CDemo02Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	m_Red.SetScrollRange(0, 255);
	m_Green.SetScrollRange(0, 255);
	m_Blue.SetScrollRange(0, 255);

	m_Red.SetScrollPos(255);
	m_Green.SetScrollPos(0);
	m_Blue.SetScrollPos(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDemo02Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDemo02Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CBrush Brush;
		CBrush *pOldBrush = NULL;
		UpdateData(TRUE);

		if(m_nIsChecked == 1){
			switch(m_nBrushType)
			{
			case 0:    // ��ɫ��ˢ
				// Brush.CreateSolidBrush(RGB(255, 0, 0));    // �̶�ֵ
				// ����������λ�����ݲ���ͼ
				Brush.CreateSolidBrush(
					RGB(m_Red.GetScrollPos(),
					    m_Green.GetScrollPos(),
					    m_Blue.GetScrollPos()));
				break;
			case 1:    // ��ֱ����
				// Brush.CreateHatchBrush(HS_CROSS, RGB(255, 0, 0));    // �̶�ֵ
				// ����������λ�����ݲ���ͼ
				Brush.CreateHatchBrush(HS_CROSS,
					RGB(m_Red.GetScrollPos(),
					    m_Green.GetScrollPos(),
					    m_Blue.GetScrollPos()));
				break;
			case 2:    // ��������
				// Brush.CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 0));    // �̶�ֵ
				// ����������λ�����ݲ���ͼ
				Brush.CreateHatchBrush(HS_DIAGCROSS,
					RGB(m_Red.GetScrollPos(),
					    m_Green.GetScrollPos(),
					    m_Blue.GetScrollPos()));
				break;
			}
		}

		pOldBrush = dc.SelectObject(&Brush);
		dc.Ellipse(10, 10, 310, 120);
		dc.SelectObject(pOldBrush);

		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDemo02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDemo02Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	InvalidateRect(NULL);
}


void CDemo02Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch(nSBCode)
	{
	case SB_THUMBTRACK:    // �϶�����
		// �϶������ʱ��û�д�����λ�õĻ���������ܻ�ȥ�������Ҫ����λ�ô���
		pScrollBar->SetScrollPos(nPos);
		break;
	case SB_LINELEFT:
		// �����ƶ���΢����ʱ��Ҫ�Զ����䲽����С��
		pScrollBar->SetScrollPos(
			pScrollBar->GetScrollPos()-1);    // �����ƶ� -1
		break;
	case SB_LINERIGHT:
		// �����ƶ���΢����ʱ��Ҫ�Զ����䲽����С��
		pScrollBar->SetScrollPos(
			pScrollBar->GetScrollPos()+1);    // �����ƶ� +1
		break;
	case SB_PAGELEFT:
		// �����ƶ����ֵ���ʱ��Ҫ�Զ����䲽����С��
		pScrollBar->SetScrollPos(
			pScrollBar->GetScrollPos()-10);    // �����ƶ� -10
		break;
	case SB_PAGERIGHT:
		// �����ƶ����ֵ���ʱ��Ҫ�Զ����䲽����С��
		pScrollBar->SetScrollPos(
			pScrollBar->GetScrollPos()+10);    // �����ƶ� +10
		break;		
	}

	// InvalidateRect() ��ͷ�Ĳ���ָ�����ϲ�ˢ�µ�����������˸���أ�Ӧ��ֻ���ϻ�ͼ������
	// dc.Ellipse(10, 10, 310, 120);    ��������(10, 10, 310, 120)����
	CRect rt(10, 10, 310, 120);    // ��ͼ������
	InvalidateRect(&rt);    // ����WM_PAINT��Ϣ
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
