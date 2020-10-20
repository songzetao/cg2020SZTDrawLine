// CCSelectControl.cpp: 实现文件
//

#include "pch.h"
#include "cg2020SZTDrawLine.h"
#include"cg2020SZTDrawLineDoc.h"
#include"cg2020SZTDrawLineView.h"
#include"CCSelectControl.h"
#include"CCSelectControl.h"
#include"cg2020SZTDrawLineDoc.h"
#include"resource.h"


// CCSelectControl

IMPLEMENT_DYNCREATE(CCSelectControl, CFormView)

CCSelectControl::CCSelectControl()
	: CFormView(IDD_SELECTCONTROL)
	, m_ddaRunTime(_T("songzetao"))
{

	//  m_bRunTime = 0.0f;
}

CCSelectControl::~CCSelectControl()
{
}

void CCSelectControl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);

	//DDX_Text(pDX, IDC_DDARUNTIME, Ccg2020SZTDrawLineDoc::m_ddaRunTime);

	 
	DDX_Text(pDX, IDC_DDARUNTIME, m_ddaRunTime);
}

BEGIN_MESSAGE_MAP(CCSelectControl, CFormView)
	//ON_BN_CLICKED(IDC_BUTTON1, &CCSelectControl::OnBnClickedButton1)
	ON_BN_CLICKED(BLINE, &CCSelectControl::OnBnClickedBline)
	ON_BN_CLICKED(COMPARE, &CCSelectControl::OnClickedCompare)
	ON_BN_CLICKED(DDALINE, &CCSelectControl::OnClickedDdaline)
	ON_BN_CLICKED(MLINE, &CCSelectControl::OnClickedMline)
//	ON_BN_CLICKED(ERROR, &CCSelectControl::OnClickedError)
//	ON_BN_CLICKED(TIme, &CCSelectControl::OnClickedTime)
//	ON_BN_CLICKED(SMOOTH, &CCSelectControl::OnClickedSmooth)
END_MESSAGE_MAP()


// CCSelectControl 诊断

#ifdef _DEBUG
void CCSelectControl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CCSelectControl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCSelectControl 消息处理程序


void CCSelectControl::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CCSelectControl::OnBnClickedBline()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
	pDoc->m_opMode = 1;
	pDoc->UpdateAllViews(this);
	/*CString str("Compare");
	str.Format(L"%d", pDoc->time);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
	pDoc->UpdateAllViews(this);*/
	
	

}


void CCSelectControl::OnClickedCompare()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
	pDoc->m_opMode = 2;
	pDoc->UpdateAllViews(this);
	
	
}


void CCSelectControl::OnClickedDdaline()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
	pDoc->m_opMode = 0;
	pDoc->UpdateAllViews(this);
}





void CCSelectControl::OnClickedMline()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
	pDoc->m_opMode = 3;
	pDoc->UpdateAllViews(this);
}


//void CCSelectControl::OnClickedError()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
//	CString str;
//	str.Format(L"%f", pDoc->aError);
//	GetDlgItem(IDC_EDIT4)->SetWindowText(str);
//	str.Format(L"%f", pDoc->bError);
//	GetDlgItem(IDC_EDIT5)->SetWindowText(str);
//	str.Format(L"%f", pDoc->mError);
//	GetDlgItem(IDC_EDIT6)->SetWindowText(str);
//}


//void CCSelectControl::OnClickedTime()
//{
//	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
//	CString str;
//	str.Format(L"%f", pDoc->aTime);
//	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
//	CString strb;
//	strb.Format(L"%f", pDoc->bTime);
//	GetDlgItem(IDC_EDIT2)->SetWindowText(strb);
//	str.Format(L"%f", pDoc->mTime);
//	GetDlgItem(IDC_EDIT3)->SetWindowText(str);
//}


//void CCSelectControl::OnClickedSmooth()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
//	CString str("0.723916");
//	//str.Format(L"%f", pDoc->aTime);
//	GetDlgItem(IDC_EDIT7)->SetWindowText(str);
//	CString str1("0.623451");
//	//str.Format(L"%f", pDoc->aTime);
//	GetDlgItem(IDC_EDIT8)->SetWindowText(str1);
//	CString str2("0.900121");
//	//str.Format(L"%f", pDoc->aTime);
//	GetDlgItem(IDC_EDIT9)->SetWindowText(str2);
//}




void CCSelectControl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	//// TODO: 在此添加专用代码和/或调用基类
	//CStatic* ddaRunTime = (CStatic*)GetDlgItem(IDC_DDARUNTIME);
	//Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
	//CString DDA_Time;
	//DDA_Time.Format(_T("DDA Run time:%f"), pDoc->m_ddaRunTime);
	//ddaRunTime->SetWindowTextW(DDA_Time);
	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
	UpdateData(TRUE);
	m_ddaRunTime.Format(_T("DDA Run time:%f\nB Run time:%f\nM Run time:%f\n\nDDA Run error:%f\nB Run error:%f\nM Run error:%f"),
		pDoc->m_ddaRunTime,pDoc->m_bRunTime,pDoc->m_mRunTime,pDoc->aError,pDoc->bError,pDoc->mError);
	UpdateData(FALSE);
}


void CCSelectControl::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	Ccg2020SZTDrawLineDoc* pDoc = (Ccg2020SZTDrawLineDoc*)GetDocument();
	UpdateData(TRUE);
	m_ddaRunTime.Format(_T("DDA Run time:%f\nB Run time:%f\nM Run time:%f\n\nDDA Run error:%f\nB Run error:%f\nM Run error:%f"),
		pDoc->m_ddaRunTime, pDoc->m_bRunTime, pDoc->m_mRunTime, pDoc->aError, pDoc->bError, pDoc->mError);
	UpdateData(FALSE);
}
