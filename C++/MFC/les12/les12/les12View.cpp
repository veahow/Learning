
// les12View.cpp : Cles12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "les12.h"
#endif

#include "les12Doc.h"
#include "les12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cles12View

IMPLEMENT_DYNCREATE(Cles12View, CView)

BEGIN_MESSAGE_MAP(Cles12View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cles12View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DAQ_START, &Cles12View::OnDaqStart)
	ON_UPDATE_COMMAND_UI(ID_DAQ_START, &Cles12View::OnUpdateDaqStart)
	ON_COMMAND(ID_DAQ_STOP, &Cles12View::OnDaqStop)
	ON_UPDATE_COMMAND_UI(ID_DAQ_STOP, &Cles12View::OnUpdateDaqStop)

	// 多对一的消息映射
	ON_COMMAND_RANGE(
	    ID_DAQ_SOLID,
		ID_DAQ_DOT,
		&Cles12View::OnDaqLine)

	ON_UPDATE_COMMAND_UI_RANGE(
	    ID_DAQ_SOLID,
		ID_DAQ_DOT,
		&Cles12View::OnUpdateDaqLine)

	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cles12View 构造/析构

Cles12View::Cles12View()
{
	// TODO: 在此处添加构造代码
	m_nRun = 0;    // 初始化状态为空闲状态
	m_nLineType = 0;    // 初始化为实线
	m_nPointNum = 0;
	for(int k = 0; k < 100; ++k)
	{
		m_Point[k].x = 50+8*k;    // 以8为步长均匀地分布
		m_Point[k].y = 0;
	}

}

Cles12View::~Cles12View()
{
}

BOOL Cles12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cles12View 绘制

void Cles12View::OnDraw(CDC *pDC)
{
	Cles12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	// 绘制网格
	CPen PenGrid;
	CPen *pOldPen = NULL;

	PenGrid.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	pOldPen = pDC->SelectObject(&PenGrid);

	for(int k = 0; k < 11; ++k)    // 横坐标不变，纵坐标绘制网格
	{
		pDC->MoveTo(50, 50+50*k);
		pDC->LineTo(850, 50+50*k);
	}

	for(int k = 0; k < 17; ++k)    // 纵坐标不变，横坐标绘制网格
	{
		pDC->MoveTo(50+50*k, 50);
		pDC->LineTo(50+50*k, 550);
	}

	// 绘制曲线
	CPen PenLine;

	switch(m_nLineType)
	{
	case 0:
		PenLine.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		break;
	case 1:
		PenLine.CreatePen(PS_DASH, 1, RGB(255, 0, 0));    // DASH&DOT 线宽设置小一点
		break;
	case 2:
		PenLine.CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		break;
	}

	pDC->SelectObject(&PenLine);    // 将新创建的画笔送入设备里头去
	pDC->Polyline(m_Point, m_nPointNum);
	pDC->SelectObject(pOldPen);
}


// Cles12View 打印


void Cles12View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cles12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cles12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cles12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void Cles12View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cles12View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cles12View 诊断

#ifdef _DEBUG
void Cles12View::AssertValid() const
{
	CView::AssertValid();
}

void Cles12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cles12Doc* Cles12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cles12Doc)));
	return (Cles12Doc*)m_pDocument;
}
#endif //_DEBUG


// Cles12View 消息处理程序


void Cles12View::OnDaqStart()
{
	// TODO: 在此添加命令处理程序代码
	m_nRun = 1;    // 采集状态
	SetTimer(0, 500, NULL);
	//::AfxMessageBox(_T("进入采集状态"));
}


void Cles12View::OnUpdateDaqStart(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	// 空闲状态可以使用“启动采集”菜单
	if(m_nRun == 0) pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);
}


void Cles12View::OnDaqStop()
{
	// TODO: 在此添加命令处理程序代码
	m_nRun = 0;    // 空闲状态
	KillTimer(1);
	//::AfxMessageBox(_T("进入空闲状态"));
}


void Cles12View::OnUpdateDaqStop(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	// 采集状态可以使用“停止采集”菜单
	if(m_nRun == 1) pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);
}


void Cles12View::OnDaqLine(UINT nID)
{
	m_nLineType = nID-ID_DAQ_SOLID;
}

void Cles12View::OnUpdateDaqLine(CCmdUI *pCmdUI)
{
	if(m_nLineType ==
		pCmdUI->m_nID-ID_DAQ_SOLID) pCmdUI->SetCheck(TRUE);
	else pCmdUI->SetCheck(FALSE);

}

void Cles12View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnTimer(nIDEvent);
}
