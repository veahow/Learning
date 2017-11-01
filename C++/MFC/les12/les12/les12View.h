
// les12View.h : Cles12View ��Ľӿ�
//

#pragma once
// #include "MyDLL.h"

class Cles12View : public CView
{
protected: // �������л�����
	Cles12View();
	DECLARE_DYNCREATE(Cles12View)

// ����
public:
	Cles12Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Cles12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDaqStart();
	afx_msg void OnUpdateDaqStart(CCmdUI *pCmdUI);
	afx_msg void OnDaqStop();
	afx_msg void OnUpdateDaqStop(CCmdUI *pCmdUI);
	afx_msg void OnDaqLine(UINT nID);
	afx_msg void OnUpdateDaqLine(CCmdUI *pCmdUI);

public:
	int m_nRun;    // 0:����״̬ 1:�ɼ�״̬
	int m_nLineType; // 0:ʵ�� 1:���� 2:����
	int m_nPointNum;
	CPoint m_Point[100];
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // les12View.cpp �еĵ��԰汾
inline Cles12Doc* Cles12View::GetDocument() const
   { return reinterpret_cast<Cles12Doc*>(m_pDocument); }
#endif

