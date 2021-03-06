
// DemoView.h: CDemoView 类的接口
//

#pragma once


class CDemoView : public CView
{
protected: // 仅从序列化创建
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

// 特性
public:
	CDemoDoc* GetDocument() const;

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
	virtual ~CDemoView();
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
	int m_nStart;       // 启动:1 停止:0
	int m_nIsNeg;       // 逆时针:1 顺时针:0

public:
	CPoint point[3];    // 0:椭圆中心点坐标 1:椭圆左上角坐标 2:椭圆右下角坐标
	double alpha;    // 椭圆参数方程的角度->匀角速度运动
	int r;           // 圆的半径

public:
	afx_msg void OnStart();
	afx_msg void OnUpdateStart(CCmdUI *pCmdUI);
	afx_msg void OnStop();
	afx_msg void OnUpdateStop(CCmdUI *pCmdUI);

	afx_msg void OnRot(UINT nID);
	afx_msg void OnUpdateRot(CCmdUI *pCmdUI);

	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // DemoView.cpp 中的调试版本
inline CDemoDoc* CDemoView::GetDocument() const
   { return reinterpret_cast<CDemoDoc*>(m_pDocument); }
#endif

