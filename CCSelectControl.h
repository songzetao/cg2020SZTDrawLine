#pragma once



// CCSelectControl 窗体视图

class CCSelectControl : public CFormView
{
	DECLARE_DYNCREATE(CCSelectControl)

protected:
	CCSelectControl();           // 动态创建所使用的受保护的构造函数
	virtual ~CCSelectControl();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECTCONTROL };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBline();
	afx_msg void OnClickedCompare();
	afx_msg void OnClickedDdaline();
	afx_msg void OnClickedCeshi();
	afx_msg void OnClickedMline();
	afx_msg void OnClickedError();
	afx_msg void OnClickedTime();
	afx_msg void OnClickedSmooth();
//	virtual void OnInitialUpdate();
//	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
//	float m_bRunTime;
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};


