
// MFCApplication2View.h : ��������� ������ CMFCApplication2View
//

#pragma once


class CMFCApplication2View : public CView
{
protected: // ������� ������ �� ������������
	CPoint p1, p2;
	CPen pen1;
	CBrush brush1;
	CMFCApplication2View();
	DECLARE_DYNCREATE(CMFCApplication2View)

// ��������
public:
	CMFCApplication2Doc* GetDocument() const;

// ��������
public:

// ���������������
public:
	virtual void OnDraw(CDC* pDC);  // �������������� ��� ��������� ����� �������������
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����������
public:
	virtual ~CMFCApplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnElementCircle32777();
	afx_msg void OnElementSquare32778();
	afx_msg void OnElementAda();
};

#ifndef _DEBUG  // ���������� ������ � MFCApplication2View.cpp
inline CMFCApplication2Doc* CMFCApplication2View::GetDocument() const
   { return reinterpret_cast<CMFCApplication2Doc*>(m_pDocument); }
#endif

