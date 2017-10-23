
// les10Dlg.h : 头文件
//

#pragma once
#include "mscomm.h"


// Cles10Dlg 对话框
class Cles10Dlg : public CDialog
{
// 构造
public:
	Cles10Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LES10_DIALOG };

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
	CMscomm m_myComm;
	DECLARE_EVENTSINK_MAP()
	void OnComm();
	afx_msg void OnBnClickedOpencom();
	afx_msg void OnBnClickedClosecom();
	afx_msg void OnBnClickedSenddata();
};
