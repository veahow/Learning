
// Demo02Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Demo02.h"
#include "Demo02Dlg.h"
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


// CDemo02Dlg 对话框




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


// CDemo02Dlg 消息处理程序

BOOL CDemo02Dlg::OnInitDialog()
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

	m_Red.SetScrollRange(0, 255);
	m_Green.SetScrollRange(0, 255);
	m_Blue.SetScrollRange(0, 255);

	m_Red.SetScrollPos(255);
	m_Green.SetScrollPos(0);
	m_Blue.SetScrollPos(0);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDemo02Dlg::OnPaint()
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
		CBrush Brush;
		CBrush *pOldBrush = NULL;
		UpdateData(TRUE);

		if(m_nIsChecked == 1){
			switch(m_nBrushType)
			{
			case 0:    // 单色画刷
				// Brush.CreateSolidBrush(RGB(255, 0, 0));    // 固定值
				// 关联滚动条位置数据并绘图
				Brush.CreateSolidBrush(
					RGB(m_Red.GetScrollPos(),
					    m_Green.GetScrollPos(),
					    m_Blue.GetScrollPos()));
				break;
			case 1:    // 垂直网格
				// Brush.CreateHatchBrush(HS_CROSS, RGB(255, 0, 0));    // 固定值
				// 关联滚动条位置数据并绘图
				Brush.CreateHatchBrush(HS_CROSS,
					RGB(m_Red.GetScrollPos(),
					    m_Green.GetScrollPos(),
					    m_Blue.GetScrollPos()));
				break;
			case 2:    // 菱形网格
				// Brush.CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 0));    // 固定值
				// 关联滚动条位置数据并绘图
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

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDemo02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDemo02Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	InvalidateRect(NULL);
}


void CDemo02Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch(nSBCode)
	{
	case SB_THUMBTRACK:    // 拖动滑块
		// 拖动滑块的时候，没有处理新位置的话，滑块会跑回去，因此需要对新位置处理
		pScrollBar->SetScrollPos(nPos);
		break;
	case SB_LINELEFT:
		// 向左移动，微调的时候要自定义其步长大小。
		pScrollBar->SetScrollPos(
			pScrollBar->GetScrollPos()-1);    // 向左移动 -1
		break;
	case SB_LINERIGHT:
		// 向右移动，微调的时候要自定义其步长大小。
		pScrollBar->SetScrollPos(
			pScrollBar->GetScrollPos()+1);    // 向右移动 +1
		break;
	case SB_PAGELEFT:
		// 向左移动，粗调的时候要自定义其步长大小。
		pScrollBar->SetScrollPos(
			pScrollBar->GetScrollPos()-10);    // 向左移动 -10
		break;
	case SB_PAGERIGHT:
		// 向右移动，粗调的时候要自定义其步长大小。
		pScrollBar->SetScrollPos(
			pScrollBar->GetScrollPos()+10);    // 向右移动 +10
		break;		
	}

	// InvalidateRect() 里头的参数指定作废并刷新的区域，由于闪烁严重，应该只作废绘图的区域
	// dc.Ellipse(10, 10, 310, 120);    即该区域(10, 10, 310, 120)作废
	CRect rt(10, 10, 310, 120);    // 画图的区域
	InvalidateRect(&rt);    // 发送WM_PAINT消息
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
