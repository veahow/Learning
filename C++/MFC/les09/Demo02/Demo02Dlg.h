
// Demo02Dlg.h : 头文件
//

#pragma once


// CDemo02Dlg 对话框
class CDemo02Dlg : public CDialog
{
// 构造
public:
	CDemo02Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DEMO02_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	int m_nBrushType;
	int m_nIsChecked;
	CScrollBar m_Red;
	CScrollBar m_Green;
	CScrollBar m_Blue;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
