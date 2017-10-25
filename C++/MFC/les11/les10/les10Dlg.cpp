
// les10Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "les10.h"
#include "les10Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Cles10Dlg 对话框


Cles10Dlg::Cles10Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cles10Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_szSendData = _T("");
	m_szRecvData = _T("");
	m_szRecvData = _T("");
	m_nBaudRate = 0;
}

void Cles10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MSCOMM, m_myComm);
	DDX_Text(pDX, IDC_SENDDATAAREA, m_szSendData);
	DDX_Text(pDX, IDC_RECVDATAAREA, m_szRecvData);
	DDX_Control(pDX, IDC_PORT, m_Port);
	DDX_Text(pDX, IDC_BAUD, m_nBaudRate);
}

BEGIN_MESSAGE_MAP(Cles10Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENCOM, &Cles10Dlg::OnBnClickedOpencom)
	ON_BN_CLICKED(IDC_CLOSECOM, &Cles10Dlg::OnBnClickedClosecom)
	ON_BN_CLICKED(IDC_SENDDATA, &Cles10Dlg::OnBnClickedSenddata)
END_MESSAGE_MAP()


// Cles10Dlg 消息处理程序

BOOL Cles10Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// 添加列表选项
	m_Port.AddString(_T("COM11"));
	m_Port.AddString(_T("COM12"));
	m_Port.AddString(_T("COM13"));
	m_Port.AddString(_T("COM14"));

	m_Port.SetCurSel(0);    // 设置默认选中项
	m_nBaudRate = 9600;
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cles10Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Cles10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BEGIN_EVENTSINK_MAP(Cles10Dlg, CDialog)
	ON_EVENT(Cles10Dlg, IDC_MSCOMM, 1, Cles10Dlg::OnComm, VTS_NONE)
END_EVENTSINK_MAP()


void Cles10Dlg::OnComm()    // 处理MSComm控件发出的消息，在这函数里头处理接收到的数据
{
	// TODO: 在此处添加消息处理程序代码
	VARIANT var_in;    // 可变类型->可存储任何类型的变量
	COleSafeArray sa_in;    // 特殊数组
	BYTE RxData[1024];    // 定义字节数组
	long len;    // 存储数据量

	if(m_myComm.get_CommEvent() == 2)    // 判断接收到了数据之后
	{
		var_in = m_myComm.get_Input();
		sa_in = var_in;
		len = sa_in.GetOneDimSize();    // 查询一维数组的大小

		// 一个字节一个字节地取数据 取到RxData
		for(long k = 0; k < len; ++k)
		{
			// 第一个参数：位置的指针 第二个参数：目的指针 
			sa_in.GetElement(&k, RxData+k);
		}

		// 显示到编辑框里头

		for(long k = 0; k < len; ++k)
		{
			m_szRecvData += RxData[k];
		}

		m_szRecvData += _T("\r\n");    // 接收数据换行

		UpdateData(FALSE);    // DDX 将变量m_szRecvData里头的数据传送到控件编辑框里
		
	}
}


void Cles10Dlg::OnBnClickedOpencom()
{
	// TODO: 在此添加控件通知处理程序代码

	// 需要考虑串口是否关闭，万一正在通信时再次设置会有大问题
	if(m_myComm.get_PortOpen())    // 如果打开，先关闭端口
	{
		m_myComm.put_PortOpen(FALSE);
	}

	UpdateData(TRUE);    // DDX 将控件的数据传送到变量里头
	CString szTmp;
	int index = m_Port.GetCurSel();
	m_Port.GetLBText(index, szTmp);
	szTmp.Delete(0, 3);    // 删除第0个位置后的3个字符 例如"COM11"变为"11"

	BYTE buf[10];    // 将szTmp的值导入到buf中
	memset(buf, 0x00, 10);
	for(int k = 0; k < szTmp.GetLength(); ++k)
	{
		buf[k] = szTmp[k];
	}
	int nPort = atoi((const char*)buf);    // 需要强制转换，高版本VS检查严格

	m_myComm.put_CommPort(nPort);    // COM11
	m_myComm.put_InBufferSize(1024);
	m_myComm.put_OutBufferSize(1024);
	m_myComm.put_InputLen(0);    // 清空输入缓冲区
	m_myComm.put_InputMode(1);    // 二进制
	m_myComm.put_RThreshold(1);

	szTmp.Format(_T("%d,n,8,1"), m_nBaudRate);    // 构造格式化的字符串
	m_myComm.put_Settings(szTmp);

	m_myComm.put_PortOpen(TRUE);    // 打开端口
	::AfxMessageBox(_T("串口打开成功"));
}


void Cles10Dlg::OnBnClickedClosecom()
{
	// TODO: 在此添加控件通知处理程序代码

	// 关闭串口
	if(m_myComm.get_PortOpen())
	{
		m_myComm.put_PortOpen(FALSE);
		::AfxMessageBox(_T("串口关闭成功"));
	}else{
		::AfxMessageBox(_T("串口已关闭"));
	}
}


void Cles10Dlg::OnBnClickedSenddata()
{
	// TODO: 在此添加控件通知处理程序代码
	// 准备数据
	CByteArray SendData;    // 定义字节数组
	BYTE TxData[1024];    // BYTE = unsigned char

	UpdateData(TRUE);    // DDX 将编辑框的数据取到变量m_szSendData里头去

	int len = m_szSendData.GetLength();
	for(int k = 0; k < len; ++k)
	{
		TxData[k] = m_szSendData[k];   
	}

	SendData.RemoveAll();
	SendData.SetSize(len);

	for(int k = 0; k < len; ++k)
	{
		SendData.SetAt(k, TxData[k]);
	}

	if(m_myComm.get_PortOpen())
	{
		// 将SendData包装成COleVariant 缓冲区只认这种类型
		m_myComm.put_Output(COleVariant(SendData));
	}else{
		::AfxMessageBox(_T("请先打开串口"));
	}
}