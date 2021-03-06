
// DemoView.cpp: CDemoView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Demo.h"
#endif

#include "DemoDoc.h"
#include "DemoView.h"

#include "math.h"

#define PI 3.1415926

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CView)

BEGIN_MESSAGE_MAP(CDemoView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDemoView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()

	// 一对一命令映射
	ON_COMMAND(ID_START, &CDemoView::OnStart)
	ON_UPDATE_COMMAND_UI(ID_START, &CDemoView::OnUpdateStart)
	ON_COMMAND(ID_STOP, &CDemoView::OnStop)
	ON_UPDATE_COMMAND_UI(ID_STOP, &CDemoView::OnUpdateStop)

	// 多对一命令映射
	ON_COMMAND_RANGE(ID_POS_ROT, ID_NEG_ROT, &CDemoView::OnRot)
	ON_UPDATE_COMMAND_UI_RANGE(ID_POS_ROT, ID_NEG_ROT, &CDemoView::OnUpdateRot)

	// 定时器
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CDemoView 构造/析构

CDemoView::CDemoView()
{
	// TODO: 在此处添加构造代码
	m_nStart = 0;    // 初始状态下为停止运动状态
	m_nIsNeg = 1;    // 初始状态下为逆时针运动

	// 初始化椭圆左上角和右下角坐标
	point[1].x = 150;
	point[1].y = 50;
	point[2].x = 550;
	point[2].y = 350;

	//计算中心点坐标
	point[0].x = (point[1].x + point[2].x) / 2.;    // 计算中心点point[0].x坐标
	point[0].y = (point[1].y + point[2].y) / 2.;    // 计算中心点point[0].y坐标

	alpha = 0;    // 初始角度为0
	r = 30;       // 圆的半径大小
}

CDemoView::~CDemoView()
{
}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDemoView 绘图

void CDemoView::OnDraw(CDC *pDC)
{
	CDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CPen PenEllipse, *pOldPen = NULL;
	PenEllipse.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	pOldPen = pDC->SelectObject(&PenEllipse);
	pDC->Ellipse(point[1].x, point[1].y, point[2].x, point[2].y);
	pDC->SelectObject(pOldPen);

	// alpha每次转过的角度为PI的100等分
	switch (m_nIsNeg)
	{
	case 0:    // 顺时针:0
		alpha += PI / 100;
		break;
	case 1:    // 逆时针:1
		alpha -= PI / 100;
		break;
	}

	// 使用椭圆参数方程运算，匀角速度运动
	CPen PenRound;
	PenRound.CreatePen(PS_SOLID, 3, RGB(255, 255, 0));    // 黄色画笔
	pDC->SelectObject(&PenRound);
	pDC->Ellipse(point[0].x + abs(point[1].x - point[0].x) * cos(alpha) - r,
		point[0].y + abs(point[1].y - point[0].y) * sin(alpha) - r,
		point[0].x + abs(point[1].x - point[0].x) * cos(alpha) + r,
		point[0].y + abs(point[1].y - point[0].y) * sin(alpha) + r);
	CBrush Brush;
	Brush.CreateSolidBrush(RGB(255, 255, 0));    // 黄色画刷
	pDC->SelectObject(&Brush);
	pDC->Ellipse(point[0].x + abs(point[1].x - point[0].x) * cos(alpha) - r,
		point[0].y + abs(point[1].y - point[0].y) * sin(alpha) - r,
		point[0].x + abs(point[1].x - point[0].x) * cos(alpha) + r,
		point[0].y + abs(point[1].y - point[0].y) * sin(alpha) + r);

}


// CDemoView 打印


void CDemoView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDemoView 诊断

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CDemoView 消息处理程序


void CDemoView::OnStart()
{
	// TODO: 在此添加命令处理程序代码
	m_nStart = 1;    // 开始运动

	SetTimer(1, 100, NULL);    // 设置ID为1的定时器，延时100ms
}


void CDemoView::OnUpdateStart(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	// 若处于停止运动状态，则使开始运动键可以点击，而使停止运动键无法点击
	if (m_nStart == 0) pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);
}


void CDemoView::OnStop()
{
	// TODO: 在此添加命令处理程序代码
	m_nStart = 0;    // 停止运动

	KillTimer(1);    // 将ID为1的定时器销毁
}


void CDemoView::OnUpdateStop(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	// 若处于开始运动状态，则使停止运动键可以点击，而使开始运动键无法点击
	if (m_nStart == 1) pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);
}

void CDemoView::OnRot(UINT nID)
{
	/*
	    #define ID_POS_ROT 32773
		#define ID_NEG_ROT 32774
	    m_nIsNeg 逆时针:1 顺时针:0
	*/
	m_nIsNeg = nID - ID_POS_ROT;
}

void CDemoView::OnUpdateRot(CCmdUI *pCmdUI)
{
	// 菜单项ID: pCmdUI->m_nID - ID_POS_ROT
	if (m_nIsNeg == pCmdUI->m_nID - ID_POS_ROT) pCmdUI->SetRadio(TRUE);
	else pCmdUI->SetRadio(FALSE);
}

void CDemoView::OnTimer(UINT_PTR nIDEvent)
{
	CRect rt(point[1].x - r, point[1].y - r, point[2].x + r, point[2].y + r);    // 作废椭圆区域rt
	InvalidateRect(&rt);    // 发送刷新消息WM_PAINT

	CView::OnTimer(nIDEvent);    // 递归调用->不断刷新
}