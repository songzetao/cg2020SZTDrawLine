
// cg2020SZTDrawLineView.cpp: Ccg2020SZTDrawLineView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "cg2020SZTDrawLine.h"
#include<string.h>
#endif

#include "cg2020SZTDrawLineDoc.h"
#include "cg2020SZTDrawLineView.h"
#include"CCSelectControl.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ccg2020SZTDrawLineView

IMPLEMENT_DYNCREATE(Ccg2020SZTDrawLineView, CView)

BEGIN_MESSAGE_MAP(Ccg2020SZTDrawLineView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// Ccg2020SZTDrawLineView 构造/析构

Ccg2020SZTDrawLineView::Ccg2020SZTDrawLineView() noexcept
{
	// TODO: 在此处添加构造代码
	m_wndHeight = 0;
	m_wndWidth = 0;


}

Ccg2020SZTDrawLineView::~Ccg2020SZTDrawLineView()
{
}

BOOL Ccg2020SZTDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Ccg2020SZTDrawLineView 绘图

void Ccg2020SZTDrawLineView::OnDraw(CDC* /*pDC*/)
{
	Ccg2020SZTDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	
	CDC* pDC = GetDC();
	CPen* pOLDPEN = pDC->SelectObject(&pen);
	int r = sqrt(150*150+400*400);
	pDC->Ellipse(m_wndWidth / 2 - r, m_wndHeight / 2 - r, m_wndWidth / 2 + r, m_wndHeight / 2 + r);
	pDC->MoveTo(0, m_wndHeight / 2); 
	pDC->LineTo(m_wndWidth, m_wndHeight / 2);
	pDC->MoveTo(m_wndWidth / 2, 0);
	pDC->LineTo(m_wndWidth / 2, m_wndHeight); 
	pDC->SelectObject(pOLDPEN);
	//pDC->FillRect();
	CBrush* oldBrush = new CBrush(RGB(1, 1, 1));
	int flag = 1;
	if (flag ) {
		clock_t startTime, endTime;
		startTime = clock();//计时开始
		for (int i = 0; i < 200; i++) {
			this->DDAlineError(pDC, 0, 0, 99, 100);
		}
		endTime = clock();//计时结束
		float t;
		t = endTime - startTime;
		float err = 0;
		for (int i = 0; i < 200; i++) {
			err += this->DDAlineError(pDC, 0, 0, 99, 100);
		}
		/*CString str;
		str.Format(L"%f", t);
		pDC->TextOutW(100, 120, str);*/
		pDoc->aTime = t;
		pDoc->aError = err;
		pDoc->m_ddaRunTime = t;
		pDoc->UpdateAllViews(this);

		startTime = clock();//计时开始
		for (int i = 0; i < 200; i++) {
			this->Bline(pDC, 0, 0, 99, 100);
			/*this->Bline(pDC, 0, 0, -150, -400);*/
		}
		endTime = clock();//计时结束
		t = endTime - startTime;
		pDoc->bTime = t;

		for (int i = 0; i < 200; i++) {
			err += this->BlineError(pDC, 0, 0, 99, 100);
		}
		pDoc->bError = err;


		startTime = clock();//计时开始
		for (int i = 0; i < 200; i++) {
			this->Mline(pDC, 0, 0, 99, 100);
			/*this->Mline(pDC, 0, 0, -150, -400);*/
		}
		endTime = clock();//计时结束
		t = endTime - startTime;
		pDoc->mTime = t;
		for (int i = 0; i < 200; i++) {
			this->MlineError(pDC, 0, 0, 99, 100, err);
		}
		pDoc->mError = err;
		flag = 0;
	}
		
		

	if (pDoc->m_opMode == 0) {
		this->DDAline(pDC, 0, 0, 400, 150);
		this->DDAline(pDC, 0, 0, 400, -150);
		this->DDAline(pDC, 0, 0, -400, 150);
		this->DDAline(pDC, 0, 0, -400, -150);
		this->DDAline(pDC, 0, 0, 150, 400);
		this->DDAline(pDC, 0, 0, -150, 400);
		this->DDAline(pDC, 0, 0, 150, -400);
		this->DDAline(pDC, 0, 0, -150, -400);
		this->DDAline(pDC, 0, 0, 100, 100);
		
		
	}
	else if (pDoc->m_opMode == 1) {
		this->Bline(pDC, 0, 0, 400, 150);
		this->Bline(pDC, 0, 0, 400, -150);
		this->Bline(pDC, 0, 0, -400, 150);
		this->Bline(pDC, 0, 0, -400, -150);
		this->Bline(pDC, 0, 0, 150, 400);
		this->Bline(pDC, 0, 0, -150, 400);
		this->Bline(pDC, 0, 0, 150, -400);
		this->Bline(pDC, 0, 0, -150, -400);
		this->Bline(pDC, 0, 200, 100, 200);
		CString m_bRunTime;

		
	
	}
	else if(pDoc->m_opMode==2) {
		this->DDAline(pDC, 0, 0, 400, 150);
		this->DDAline(pDC, 0, 0, 400, -150);
		this->DDAline(pDC, 0, 0, -400, 150);
		this->DDAline(pDC, 0, 0, -400, -150);
		this->DDAline(pDC, 0, 0, 150, 400);
		this->DDAline(pDC, 0, 0, -150, 400);
		this->DDAline(pDC, 0, 0, 150, -400);
		this->DDAline(pDC, 0, 0, -150, -400);
		this->Bline(pDC, 0, 0, 400, 150);
		this->Bline(pDC, 0, 0, 400, -150);
		this->Bline(pDC, 0, 0, -400, 150);
		this->Bline(pDC, 0, 0, -400, -150);
		this->Bline(pDC, 0, 0, 150, 400);
		this->Bline(pDC, 0, 0, -150, 400);
		this->Bline(pDC, 0, 0, 150, -400);
		this->Bline(pDC, 0, 0, -150, -400);
		this->Mline(pDC, 0, 100, 100, 100);
		this->Bline(pDC, 0, 200, 100, 200);
	}
	else if(pDoc->m_opMode == 3)
	{
		this->Mline(pDC, 0, 100, 100, 100);
		this->Mline(pDC, 0, 0, 400, 150);
		this->Mline(pDC, 0, 0, 400, -150);
		this->Mline(pDC, 0, 0, -400, 150);
		this->Mline(pDC, 0, 0, -400, -150);
		this->Mline(pDC, 0, 0, 150, 400);
		this->Mline(pDC, 0, 0, -150, 400);
		this->Mline(pDC, 0, 0, 150, -400);
		this->Mline(pDC, 0, 0, -150, -400);
		this->Mline(pDC, 0, 0, 100, 100);
	}
	
	//pDC->SelectObject(oldbrush);
	//RealseDC(pDC);

	


	////CBrush brush(RGB(x, x, x));//根据自己需要填充颜色
	////CBrush* oldbrush;
	////oldbrush = pDC->SelectObject(&brush);//选新的画刷
	////pDC->Ellispe(x1, y1, x2, y2);
	////pDC->SelectObject(oldbrush);//将原来的画刷选回去
	////RealseDC(pDC); // 释放DC

	//pDC->FillRect(Rectangle(), oldBrush);
	// TODO: 在此处为本机数据添加绘制代码
}


// Ccg2020SZTDrawLineView 打印

BOOL Ccg2020SZTDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Ccg2020SZTDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Ccg2020SZTDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Ccg2020SZTDrawLineView 诊断

#ifdef _DEBUG
void Ccg2020SZTDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void Ccg2020SZTDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ccg2020SZTDrawLineDoc* Ccg2020SZTDrawLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ccg2020SZTDrawLineDoc)));
	return (Ccg2020SZTDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// Ccg2020SZTDrawLineView 消息处理程序


void Ccg2020SZTDrawLineView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_wndWidth = cx;
	m_wndHeight = cy;

	// TODO: 在此处添加消息处理程序代码
}




void Ccg2020SZTDrawLineView::DDAline(CDC* pDC, int x1, int y1, int x2, int y2)
{
	int steps;
	float m, x, y, dx, dy;
	x = x1 + 0.5f;
	y = y1 + 0.5f;
	steps = abs(x2 - x1) > abs(y2 - y1) ? abs(x2 - x1) : abs(y2 - y1);

	dx = (float)(x2 - x1) / steps;
	dy = (float)(y2 - y1) / steps;

	for (int i = 0; i < steps; i++) {
		pDC->SetPixel((int)x + m_wndWidth / 2, (int)m_wndHeight / 2 - y, RGB(1, 255, 1));
		x += dx;
		y += dy;
	}
}



float Ccg2020SZTDrawLineView::DDAlineError(CDC* pDC,int x1, int y1, int x2, int y2)
{
	int steps;
	float m, x, y, dx, dy;
	float error=0;

	x = x1 + 0.5f;
	y = y1 + 0.5f;
	steps = abs(x2 - x1) > abs(y2 - y1) ? abs(x2 - x1) : abs(y2 - y1);

	dx = (float)(x2 - x1) / steps;
	dy = (float)(y2 - y1) / steps;

	for (int i = 0; i < steps; i++) {
		error += abs(x - int(x)) + abs(y - int(y));
		pDC->SetPixel((int)x + m_wndWidth / 2, (int)m_wndHeight / 2 - y, RGB( 1, 255, 1));
		x += dx;
		y += dy;
	}
	return error;
}

void Ccg2020SZTDrawLineView::Bline(CDC* pDC, int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, xSign, ySign, interChange = 0;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (dx < dy) {
		int temp;
		interChange = 1;
		temp = dx;
		dx = dy;
		dy = temp;
	}
	xSign = (x2 >= x1) ? 1 : -1;
	ySign = (y2 >= y1) ? 1 : -1;
	x = x1;
	y = y1;
	e = 2 * dy - dx;
	for (int i = 0; i <= dx; i++) {
		pDC->SetPixel(x + m_wndWidth / 2, m_wndHeight / 2 - y, RGB(0, 0, 255));
		if (e > 0) {
			e = e - 2 * dx;
			if (interChange)
				x += xSign;
			else
				y += ySign;
		}
		if (interChange)
			y += ySign;
		else
			x += xSign;
		e += 2 * dy;

	}
}

float Ccg2020SZTDrawLineView::BlineError(CDC* pDC, int x1, int y1, int x2, int y2)
{
	int x, y, dx, dy, e, xSign, ySign, interChange = 0;
	float error=0;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (dx < dy) {
		int temp;
		interChange = 1;
		temp = dx;
		dx = dy;
		dy = temp;
	}
	xSign = (x2 >= x1) ? 1 : -1;
	ySign = (y2 >= y1) ? 1 : -1;
	x = x1;
	y = y1;
	e = 2 * dy - dx;
	for (int i = 0; i <= dx; i++) {
		pDC->SetPixel(x + m_wndWidth / 2, m_wndHeight / 2 - y, RGB(0, 0, 255));
		if (e > 0) {
			error += 1 - float(dy)/dx;
		}
		else{
			error += float(dy) / dx;
		}
		if (e > 0) {
			e = e - 2 * dx;
			if (interChange)
				x += xSign;
			else
				y += ySign;
		}
		if (interChange)
			y += ySign;
		else
			x += xSign;
		e += 2 * dy;
		
	}
	return error;
}



//int Ccg2020SZTDrawLineView::Mline(CDC* pDC, int x1, int y1, int x2, int y2) {
//	if ((x2 - x1) <= 1 && (y2 - y1) <= 1) {
//		return 0;
//	}
//	else {
//		float mx, my;
//		mx = (float)(x1 + x2) / 2;
//		my = (float)(y1 + y2) / 2;
//		pDC->SetPixel((int)(mx+0.5) + m_wndWidth / 2, m_wndHeight / 2 - (int)(my+0.5), RGB(0, 0, 255));
//		this->Mline(pDC, x1, y1, mx, my);
//		this->Mline(pDC, mx, my, x2, y2);
//	}
//}

//int Ccg2020SZTDrawLineView::Mline(CDC* pDC, float x1, float y1, float x2, float y2) {
//	if (abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1) {	return 0;}
//	else {
//		pDC->SetPixel((int)((x1 + x2) / 2 + 0.5) + m_wndWidth / 2, m_wndHeight / 2 - (int)((y1 + y2) / 2 + 0.5), RGB(0, 0, 255));
//		this->Mline(pDC, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
//		this->Mline(pDC, (x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
//	}
//}

void Ccg2020SZTDrawLineView::MlineError(CDC* pDC, float x1, float y1, float x2, float y2,float &error) {
	if (abs(x2 - x1) > 1 || abs(y2 - y1) > 1) {  
		pDC->SetPixel((int)((x1 + x2) / 2 + 0.5) + m_wndWidth / 2, m_wndHeight / 2 - (int)((y1 + y2) / 2 + 0.5), RGB(0, 0, 255));
		error += abs(x1 + x2 / 2 - (int)((x1 + x2) / 2 + 0.5)) + abs((y1 + y2) / 2 - (int)((y1 + y2) / 2 + 0.5));
		this->MlineError(pDC, x1, y1, (x1 + x2) / 2, (y1 + y2) / 2,error);
		this->MlineError(pDC, (x1 + x2) / 2, (y1 + y2) / 2, x2, y2,error);
	}
}

void Ccg2020SZTDrawLineView::Mline(CDC* pDC, int x1, int y1, int x2, int y2) {
	if (abs(x2 - x1) > 1 || abs(y2 - y1) > 1) {
		int mx = (x1 + x2) / 2, my = (y1 + y2) / 2;
		pDC->SetPixel((int)(mx + 0.5) + m_wndWidth / 2, m_wndHeight / 2 - (int)(my + 0.5), RGB(0, 0, 255));
		this->Mline(pDC, x1, y1, mx, my);
		this->Mline(pDC, mx, my, x2, y2);
	}

}

void Ccg2020SZTDrawLineView::BresenhamArc(float theTa1, float theTa2, float R) {

}
