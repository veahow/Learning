#include "Demo.h"

BOOL CDemoApp::InitInstance()    // MFC入口函数
{
	CDemoWnd *pMainWnd = NULL;
	pMainWnd = new CDemoWnd();
	pMainWnd->Create(NULL, _T("My First MFC Program"));
	
	pMainWnd->ShowWindow(m_nCmdShow);
	pMainWnd->UpdateWindow();
	m_pMainWnd = pMainWnd;

	return TRUE;
}

CDemoWnd::CDemoWnd()    // 构造函数
{
}

CDemoWnd::~CDemoWnd()    // 析构函数
{
}

BEGIN_MESSAGE_MAP(CDemoWnd, CFrameWnd)
	ON_MESSAGE(WM_LBUTTONDOWN, OnLButtonDown)
	ON_MESSAGE(WM_PAINT, OnPaint)
END_MESSAGE_MAP()


LRESULT CDemoWnd::OnLButtonDown(
	WPARAM wParam, LPARAM lParam)
{
	// 1
	//AfxMessageBox(_T("你按下了鼠标左键！"));

	// 2
	//CClientDC dc(this);
	//dc.Ellipse(50, 50, 250, 250);

	return 0;
}

LRESULT CDemoWnd::OnPaint(
	WPARAM wParam, LPARAM lParam)
{
	CPaintDC dc(this);
	CPen Pen, *pOldPen;
	Pen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	pOldPen = dc.SelectObject(&Pen);

	CBrush Brush, BrushHS, *pOldBrush;
	Brush.CreateSolidBrush(RGB(255, 0, 0));
	pOldBrush = dc.SelectObject(&Brush);

	//dc.SelectStockObject(BLACK_BRUSH);
	//dc.SetMapMode(MM_LOMETRIC);

	//dc.Ellipse(50, 50, 450, 350);
	dc.MoveTo(50, 50);
	dc.LineTo(200, 50);

	dc.Rectangle(100, 100, 300, 400);

	BrushHS.CreateHatchBrush(HS_CROSS, RGB(255, 255, 0));
	dc.SelectObject(&BrushHS);
	//dc.Ellipse(100, 100, 350, 250);
	/*
	dc.SelectStockObject(ANSI_FIXED_FONT);
	dc.TextOut(50, 50, _T("This is a text demo"));
	dc.SelectStockObject(ANSI_VAR_FONT);
	dc.TextOut(50, 100, _T("This is a text demo"));
	//*/
	CFont Font;
	CFont *pOldFont = NULL;
	Font.CreateFont(50, 0, 0, 0, 700, 0, 0, 0,
		GB2312_CHARSET, OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH, _T("楷体"));
	pOldFont = dc.SelectObject(&Font);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(255, 255, 0));
	//dc.TextOut(50, 50, _T("绘图工具与颜色"));
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldFont);

	return 0;
}