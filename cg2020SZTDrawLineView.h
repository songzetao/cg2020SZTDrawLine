
// cg2020SZTDrawLineView.h: Ccg2020SZTDrawLineView 类的接口
//

#pragma once


class Ccg2020SZTDrawLineView : public CView
{
protected: // 仅从序列化创建
	Ccg2020SZTDrawLineView() noexcept;
	DECLARE_DYNCREATE(Ccg2020SZTDrawLineView)

// 特性
public:
	Ccg2020SZTDrawLineDoc* GetDocument() const;
	int m_wndWidth, m_wndHeight;


// 操作
public:
	float DDAlineSmooth(CDC* pDC, int x1, int y1, int x2, int y2);
	void DDAline(CDC* pDC, int x1, int y1, int x2, int y2);
	float BlineSmooth(CDC* pDC, int x1, int y1, int x2, int y2);
	void Bline(CDC* pDC, int x1, int y1, int x2, int y2);
	//int Mline(CDC* pDC, float x1, float y1, float x2, float y2);
	void MlineSmooth(CDC* pDC, int x1, int y1, int x2, int y2, float& error, int& times);
	void Mline(CDC* pDC, int x1, int y1, int x2, int y2);
	void BresenhamArc(float theTa1, float theTa2, float R);
	float DDAlineError(CDC* pDC, int x1, int y1, int x2, int y2);
	float BlineError(CDC* pDC, int x1, int y1, int x2, int y2);
	void MlineError(CDC* pDC, float x1, float y1, float x2, float y2, float& error, int& times, int count);
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
	virtual ~Ccg2020SZTDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // cg2020SZTDrawLineView.cpp 中的调试版本
inline Ccg2020SZTDrawLineDoc* Ccg2020SZTDrawLineView::GetDocument() const
   { return reinterpret_cast<Ccg2020SZTDrawLineDoc*>(m_pDocument); }
#endif

