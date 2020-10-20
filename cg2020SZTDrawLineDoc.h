
// cg2020SZTDrawLineDoc.h: Ccg2020SZTDrawLineDoc 类的接口
//


#pragma once


class Ccg2020SZTDrawLineDoc : public CDocument
{
protected: // 仅从序列化创建
	Ccg2020SZTDrawLineDoc() noexcept;
	DECLARE_DYNCREATE(Ccg2020SZTDrawLineDoc)

// 特性
public:
	int m_opMode;
	int time;
	float aTime;//DDA算法的时间
	float bTime;//B算法的时间
	float mTime;//中点画线算法的时间
	float aError;//DDA算法的误差
	float bError;//B算法的误差
	float mError;//中点画线算法的误差
	float aSmooth;//DDA算法的光滑度
	float bSmooth;//B算法的光滑度
	float mSmooth;//中点画线算法的光滑度
	float m_ddaRunTime;
	float m_bRunTime;
	float m_mRunTime;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Ccg2020SZTDrawLineDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
