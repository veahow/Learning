
// les12View.cpp : Cles12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cles12View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DAQ_START, &Cles12View::OnDaqStart)
	ON_UPDATE_COMMAND_UI(ID_DAQ_START, &Cles12View::OnUpdateDaqStart)
	ON_COMMAND(ID_DAQ_STOP, &Cles12View::OnDaqStop)
	ON_UPDATE_COMMAND_UI(ID_DAQ_STOP, &Cles12View::OnUpdateDaqStop)

	// ���һ����Ϣӳ��
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

// Cles12View ����/����

Cles12View::Cles12View()
{
	// TODO: �ڴ˴���ӹ������
	m_nRun = 0;    // ��ʼ��״̬Ϊ����״̬
	m_nLineType = 0;    // ��ʼ��Ϊʵ��
	m_nPointNum = 0;
	for(int k = 0; k < 100; ++k)
	{
		m_Point[k].x = 50+8*k;    // ��8Ϊ�������ȵطֲ�
		m_Point[k].y = 0;
	}

}

Cles12View::~Cles12View()
{
}

BOOL Cles12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cles12View ����

void Cles12View::OnDraw(CDC *pDC)
{
	Cles12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	// ��������
	CPen PenGrid;
	CPen *pOldPen = NULL;

	PenGrid.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	pOldPen = pDC->SelectObject(&PenGrid);

	for(int k = 0; k < 11; ++k)    // �����겻�䣬�������������
	{
		pDC->MoveTo(50, 50+50*k);
		pDC->LineTo(850, 50+50*k);
	}

	for(int k = 0; k < 17; ++k)    // �����겻�䣬�������������
	{
		pDC->MoveTo(50+50*k, 50);
		pDC->LineTo(50+50*k, 550);
	}

	// ��������
	CPen PenLine;

	switch(m_nLineType)
	{
	case 0:
		PenLine.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
		break;
	case 1:
		PenLine.CreatePen(PS_DASH, 1, RGB(255, 0, 0));    // DASH&DOT �߿�����Сһ��
		break;
	case 2:
		PenLine.CreatePen(PS_DOT, 1, RGB(255, 0, 0));
		break;
	}

	pDC->SelectObject(&PenLine);    // ���´����Ļ��������豸��ͷȥ
	pDC->Polyline(m_Point, m_nPointNum);
	pDC->SelectObject(pOldPen);
}


// Cles12View ��ӡ


void Cles12View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cles12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cles12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cles12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// Cles12View ���

#ifdef _DEBUG
void Cles12View::AssertValid() const
{
	CView::AssertValid();
}

void Cles12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cles12Doc* Cles12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cles12Doc)));
	return (Cles12Doc*)m_pDocument;
}
#endif //_DEBUG


// Cles12View ��Ϣ�������


void Cles12View::OnDaqStart()
{
	// TODO: �ڴ���������������
	m_nRun = 1;    // �ɼ�״̬
	SetTimer(0, 500, NULL);
	//::AfxMessageBox(_T("����ɼ�״̬"));
}


void Cles12View::OnUpdateDaqStart(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	// ����״̬����ʹ�á������ɼ����˵�
	if(m_nRun == 0) pCmdUI->Enable(TRUE);
	else pCmdUI->Enable(FALSE);
}


void Cles12View::OnDaqStop()
{
	// TODO: �ڴ���������������
	m_nRun = 0;    // ����״̬
	KillTimer(1);
	//::AfxMessageBox(_T("�������״̬"));
}


void Cles12View::OnUpdateDaqStop(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	// �ɼ�״̬����ʹ�á�ֹͣ�ɼ����˵�
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnTimer(nIDEvent);
}
