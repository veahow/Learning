
// les12View.h : Cles12View 类的接口
//

#pragma once
// #include "MyDLL.h"

class Cles12View : public CView
{
protected: // 仅从序列化创建
	Cles12View();
	DECLARE_DYNCREATE(Cles12View)

// 特性
public:
	Cles12Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cles12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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
	int m_nRun;    // 0:空闲状态 1:采集状态
	int m_nLineType; // 0:实线 1:虚线 2:点线
	int m_nPointNum;
	CPoint m_Point[100];
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // les12View.cpp 中的调试版本
inline Cles12Doc* Cles12View::GetDocument() const
   { return reinterpret_cast<Cles12Doc*>(m_pDocument); }
#endif

