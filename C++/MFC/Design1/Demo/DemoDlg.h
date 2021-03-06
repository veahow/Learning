
// DemoDlg.h: 头文件
//

#pragma once
#include "afxwin.h"

// CDemoDlg 对话框
class CDemoDlg : public CDialog
{
// 构造
public:
	CDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CPoint m_Ord[5];                    // 定义五边形的五个点坐标
	CPoint m_Border[2];                  // 指定边界左上角坐标与左下角坐标
	double m_dLen;                      // 定义正五边形的边长
	int m_nUnitStep;                    // 定义左右移动的步长
	void SelectRectPaint();             // 定义指定刷新区域的函数
	afx_msg void OnBnClickedLeft();     // 左移
	afx_msg void OnBnClickedRight();    // 右移
};
