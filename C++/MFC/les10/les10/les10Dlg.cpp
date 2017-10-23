
// les10Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "les10.h"
#include "les10Dlg.h"
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


// Cles10Dlg �Ի���




Cles10Dlg::Cles10Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cles10Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cles10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM, m_myComm);
}

BEGIN_MESSAGE_MAP(Cles10Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENCOM, &Cles10Dlg::OnBnClickedOpencom)
	ON_BN_CLICKED(IDC_CLOSECOM, &Cles10Dlg::OnBnClickedClosecom)
	ON_BN_CLICKED(IDC_SENDDATA, &Cles10Dlg::OnBnClickedSenddata)
END_MESSAGE_MAP()


// Cles10Dlg ��Ϣ�������

BOOL Cles10Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cles10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cles10Dlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Cles10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BEGIN_EVENTSINK_MAP(Cles10Dlg, CDialog)
	ON_EVENT(Cles10Dlg, IDC_MSCOMM, 1, Cles10Dlg::OnComm, VTS_NONE)
END_EVENTSINK_MAP()


void Cles10Dlg::OnComm()    // ����MSComm�ؼ���������Ϣ�����⺯����ͷ������յ�������
{
	// TODO: �ڴ˴������Ϣ����������
	VARIANT var_in;    // �ɱ�����->�ɴ洢�κ����͵ı���
	COleSafeArray sa_in;    // ��������
	BYTE RxData[128];    // �����ֽ�����
	long len;    // �洢������

	if(m_myComm.get_CommEvent() == 2)    // �жϽ��յ�������֮��
	{
		var_in = m_myComm.get_Input();
		sa_in = var_in;
		len = sa_in.GetOneDimSize();    // ��ѯһά����Ĵ�С

		// һ���ֽ�һ���ֽڵ�ȡ���� ȡ��RxData
		for(long k = 0; k < len + 2; ++k)
		{
			// ��һ��������λ�õ�ָ�� �ڶ���������Ŀ��ָ�� 
			sa_in.GetElement(&k, RxData+k);
		}
	}
}


void Cles10Dlg::OnBnClickedOpencom()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// ��Ҫ���Ǵ����Ƿ�رգ���һ����ͨ��ʱ�ٴ����û��д�����
	if(m_myComm.get_PortOpen())    // ����򿪣��ȹرն˿�
	{
		m_myComm.put_PortOpen(FALSE);
	}

	m_myComm.put_CommPort(11);    // COM11
	m_myComm.put_InBufferSize(1024);
	m_myComm.put_OutBufferSize(1024);
	m_myComm.put_InputLen(0);    // ������뻺����
	m_myComm.put_InputMode(1);    // ������
	m_myComm.put_RThreshold(1);
	m_myComm.put_Settings(_T("9600,n,8,1"));
	m_myComm.put_PortOpen(TRUE);    // �򿪶˿�
	::AfxMessageBox(_T("���ڴ򿪳ɹ�"));
}


void Cles10Dlg::OnBnClickedClosecom()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// �رմ���
	if(m_myComm.get_PortOpen())
	{
		m_myComm.put_PortOpen(FALSE);
		::AfxMessageBox(_T("���ڹرճɹ�"));
	}else{
		::AfxMessageBox(_T("�����ѹر�"));
	}
}


void Cles10Dlg::OnBnClickedSenddata()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ׼������
	CByteArray SendData;    // �����ֽ�����
	BYTE TxData[30];    // BYTE = unsigned char

	for(int k = 0; k < 10; ++k)
	{
		TxData[k] = 0x30 + k;    // ��ʼ��Ϊ0-9ʮ�����ֵ�ASCII��
	}

	SendData.RemoveAll();
	SendData.SetSize(10);

	for(int k = 0; k < 10; ++k)
	{
		SendData.SetAt(k, TxData[k]);
	}

	if(m_myComm.get_PortOpen())
	{
		// ��SendData��װ��COleVariant ������ֻ����������
		m_myComm.put_Output(COleVariant(SendData));
	}else{
		::AfxMessageBox(_T("���ȴ򿪴���"));
	}
}
