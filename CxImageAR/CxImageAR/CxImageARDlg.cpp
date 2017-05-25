
// CxImageARDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CxImageAR.h"
#include "CxImageARDlg.h"
#include "afxdialogex.h"
#include "CxImageARDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCxImageARDlg ��ȭ ����




CCxImageARDlg::CCxImageARDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCxImageARDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCxImageARDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_ORIGINAL, m_pic_original);
	DDX_Control(pDX, IDC_PIC_RESULT, m_pic_result);
}

BEGIN_MESSAGE_MAP(CCxImageARDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_OPEN, &CCxImageARDlg::OnBnClickedBtnOpen)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_GRAY, &CCxImageARDlg::OnBnClickedBtnGray)
	ON_BN_CLICKED(IDC_BTN_BIN, &CCxImageARDlg::OnBnClickedBtnBin)
	ON_BN_CLICKED(IDC_BTN_EDGE, &CCxImageARDlg::OnBnClickedBtnEdge)
	ON_BN_CLICKED(IDC_BTN_LABEL, &CCxImageARDlg::OnBnClickedBtnLabel)
	ON_BN_CLICKED(IDC_BTN_AR, &CCxImageARDlg::OnBnClickedBtnAr)
END_MESSAGE_MAP()


// CCxImageARDlg �޽��� ó����

BOOL CCxImageARDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	cxImageARDoc = CCxImageARDoc();
	result_option = OPTION_NO;

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCxImageARDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCxImageARDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCxImageARDlg::OnBnClickedBtnOpen()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	static TCHAR BASED_CODE szFilter[] = 
		_T("Supported Files(*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.j2k;*.jp2;;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf)|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.j2k;*.jp2;;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf|")
		_T("BMP Files(*.bmp)|*.bmp|")
		_T("GIF Files(*.gif)|*.gif|")
		_T("JPG Files(*.jpg;*.jpeg)|*.jpg;*.jpeg|")
		_T("PNG Files(*.png)|*.png|")
		_T("MNG Files(*.mng;*.jng;*.png)|*.mng;*.jng;*.png|")
		_T("ICO CUR Files(*.ico;*.cur)|*.ico;*.cur|")
		_T("TIF Files(*.tif;*.tiff)|*.tif;*.tiff|")
		_T("TGA Files(*.tga)|*.tga|")
		_T("PCX Files(*.pcx)|*.pcx|")
		_T("WBMP Files(*.wbmp)|*.wbmp|")
		_T("JP2 Files(*.j2k;*.jp2)|*.j2k;*.jp2|")
		_T("JPC Files(*.j2c;*.jpc)|*.j2c;*.jpc|")
		_T("PGX Files(*.pgx)|*.pgx|")
		_T("RAS Files(*.ras)|*.ras|")
		_T("PNM Files(*.pnm;*.pgm;*.ppm)|*.pnm;*.pgm;*.ppm|")
		_T("SKA Files(*.ska)|*.ska|")
		_T("RAW Files(*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf)|*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf|")
		_T("All Files(*.*)|*.*||");

	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	
	if(fileDlg.DoModal() == IDOK){
		/* OK butten clicked */
		cxImageARDoc.OnOpenImage(fileDlg.GetPathName(), 0);
		original = cxImageARDoc.GetImage();
		result = cxImageARDoc.GetImage();
	}
}


void CCxImageARDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(cxImageARDoc.GetImage() != NULL){
		
		CDC* pDC1, *pDC2;
		CRect rect1, rect2;
			
		pDC1 = m_pic_original.GetDC();
		m_pic_original.GetClientRect(&rect1);

		original->Draw(pDC1->m_hDC, rect1);

		pDC2 = m_pic_result.GetDC();
		m_pic_result.GetClientRect(&rect2);

		result->Draw(pDC2->m_hDC, rect2);


		ReleaseDC(pDC1);
		ReleaseDC(pDC2);
	}

	CDialogEx::OnTimer(nIDEvent);
}


int CCxImageARDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	this->SetTimer(0, 33, NULL);

	return 0;
}


void CCxImageARDlg::OnBnClickedBtnGray()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	result_option = OPTION_GRAY;
	if(cxImageARDoc.GetImage() != NULL){
		result = cxImageARDoc.Grayscale(cxImageARDoc.GetImage());
	}
}


void CCxImageARDlg::OnBnClickedBtnBin()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	result_option = OPTION_BIN;
	if(cxImageARDoc.GetImage() != NULL){
		result = cxImageARDoc.Binarization(cxImageARDoc.GetImage());
	}
}


void CCxImageARDlg::OnBnClickedBtnEdge()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	result_option = OPTION_EDGE;
	if(cxImageARDoc.GetImage() != NULL){
		result = cxImageARDoc.Edgedetection(cxImageARDoc.GetImage());
	}
}


void CCxImageARDlg::OnBnClickedBtnLabel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(cxImageARDoc.GetImage() != NULL){
		result = cxImageARDoc.Labeling(cxImageARDoc.GetImage());
	}
}


void CCxImageARDlg::OnBnClickedBtnAr()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(cxImageARDoc.GetImage() != NULL){
		static TCHAR BASED_CODE szFilter[] = 
			_T("Supported Files(*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.j2k;*.jp2;;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf)|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.j2k;*.jp2;;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf|")
			_T("BMP Files(*.bmp)|*.bmp|")
			_T("GIF Files(*.gif)|*.gif|")
			_T("JPG Files(*.jpg;*.jpeg)|*.jpg;*.jpeg|")
			_T("PNG Files(*.png)|*.png|")
			_T("MNG Files(*.mng;*.jng;*.png)|*.mng;*.jng;*.png|")
			_T("ICO CUR Files(*.ico;*.cur)|*.ico;*.cur|")
			_T("TIF Files(*.tif;*.tiff)|*.tif;*.tiff|")
			_T("TGA Files(*.tga)|*.tga|")
			_T("PCX Files(*.pcx)|*.pcx|")
			_T("WBMP Files(*.wbmp)|*.wbmp|")
			_T("JP2 Files(*.j2k;*.jp2)|*.j2k;*.jp2|")
			_T("JPC Files(*.j2c;*.jpc)|*.j2c;*.jpc|")
			_T("PGX Files(*.pgx)|*.pgx|")
			_T("RAS Files(*.ras)|*.ras|")
			_T("PNM Files(*.pnm;*.pgm;*.ppm)|*.pnm;*.pgm;*.ppm|")
			_T("SKA Files(*.ska)|*.ska|")
			_T("RAW Files(*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf)|*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf|")
			_T("All Files(*.*)|*.*||");

		CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	
		if(fileDlg.DoModal() == IDOK){
			/* OK butten clicked */
			cxImageARDoc.OnOpenImage(fileDlg.GetPathName(), 1);
		}
		result = cxImageARDoc.AugmentedReality(cxImageARDoc.GetImage());
	}
}
