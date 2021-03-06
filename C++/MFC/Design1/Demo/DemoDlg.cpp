
// DemoDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Demo.h"
#include "DemoDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.1415926

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDemoDlg 对话框



CDemoDlg::CDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_Border[0] = CPoint(0, 40);        // 设定左上角坐标(0, 40)
	m_Border[1] = CPoint(600, 260);     // 设定右下角坐标(1000, 260)

	m_nUnitStep = 20;                  // 设定默认的移动步长为5
	m_dLen = 100;                      // 设定默认的正五边形长度为100
	m_Ord[0].x = 275;                  // 设定默认的正五边形顶点横坐标
	m_Ord[0].y = 50;                   // 设定默认的正五边形顶点纵坐标
	
}

void CDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LEFT, m_nLeftDis);
}

BEGIN_MESSAGE_MAP(CDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LEFT, &CDemoDlg::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHT, &CDemoDlg::OnBnClickedRight)
END_MESSAGE_MAP()


// CDemoDlg 消息处理程序

BOOL CDemoDlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 计算正五边形其他四个顶点坐标
	m_Ord[1].x = m_Ord[0].x - m_dLen*sin(54 / 180. * PI);
	m_Ord[1].y = m_Ord[0].y + m_dLen*cos(54 / 180. * PI);
	m_Ord[2].x = m_Ord[0].x - m_dLen / 2.0;
	m_Ord[2].y = m_Ord[0].y + sqrt(2 * m_dLen*m_dLen*(1 - cos(108 / 180. * PI)) - m_dLen*m_dLen / 4);
	m_Ord[3].x = m_Ord[2].x + m_dLen;
	m_Ord[3].y = m_Ord[2].y;
	m_Ord[4].x = m_Ord[1].x + sqrt(2 * m_dLen*m_dLen*(1 - cos(108 / 180. * PI)));
	m_Ord[4].y = m_Ord[1].y;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDemoDlg::OnPaint()
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
		CPaintDC dc(this);
		CPen Pen, *pOldPen;
		CBrush Brush, *pOldBrush;
		Pen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));    // 创建画笔Pen，指定为红色实线
		Brush.CreateSolidBrush(RGB(255, 0, 0));        // 创建红色画刷Brush

		pOldPen = dc.SelectObject(&Pen);               // 选择画笔Pen绘图
		dc.Polygon(m_Ord, 5);

		pOldBrush = dc.SelectObject(&Brush);           // 选择画刷Brush填充
		dc.Polygon(m_Ord, 5);

		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDemoDlg::OnBnClickedLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i <= 4; ++i) m_Ord[i].x -= m_nUnitStep;    // 正五边形顶点坐标左移

	SelectRectPaint();
}


void CDemoDlg::OnBnClickedRight()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i <= 4; ++i) m_Ord[i].x += m_nUnitStep;    // 正五边形顶点坐标右移

	SelectRectPaint();
}

void CDemoDlg::SelectRectPaint()
{
	CRect rt(m_Border[0].x, m_Border[0].y, m_Border[1].x, m_Border[1].y);    // 指定作废区域rt
	InvalidateRect(&rt);           // 发送WM_PAINT消息
}
