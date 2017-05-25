
// CxImageARDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CCxImageARDlg ��ȭ ����
class CCxImageARDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCxImageARDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	
// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CXIMAGEAR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CCxImageARDoc cxImageARDoc;
	int result_option;
	CxImage* original;
	CxImage* result;

public:
	CStatic m_pic_original;
	CStatic m_pic_result;

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	
	//Butten events
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnBnClickedBtnGray();
	afx_msg void OnBnClickedBtnBin();
	afx_msg void OnBnClickedBtnEdge();
	afx_msg void OnBnClickedBtnLabel();
	afx_msg void OnBnClickedBtnAr();
};
