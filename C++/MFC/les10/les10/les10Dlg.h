
// les10Dlg.h : ͷ�ļ�
//

#pragma once
#include "mscomm.h"


// Cles10Dlg �Ի���
class Cles10Dlg : public CDialog
{
// ����
public:
	Cles10Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LES10_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
