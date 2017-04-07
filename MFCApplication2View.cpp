
// MFCApplication2View.cpp : ���������� ������ CMFCApplication2View
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "MFCApplication2.h"
#endif

#include "MFCApplication2Doc.h"
#include "MFCApplication2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication2View

IMPLEMENT_DYNCREATE(CMFCApplication2View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication2View, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_CHAR()
	ON_COMMAND(ID_ELEMENT_CIRCLE32777, &CMFCApplication2View::OnElementCircle32777)
	ON_COMMAND(ID_ELEMENT_SQUARE32778, &CMFCApplication2View::OnElementSquare32778)
	ON_COMMAND(ID_ELEMENT_ADA, &CMFCApplication2View::OnElementAda)
END_MESSAGE_MAP()

// ��������/����������� CMFCApplication2View

CMFCApplication2View::CMFCApplication2View()
{

	pen1.CreatePen(PS_DASH, 1, RGB(0, 0, 255));
	brush1.CreateHatchBrush(HS_VERTICAL, RGB(255, 0, 0));
}

CMFCApplication2View::~CMFCApplication2View()
{
}

BOOL CMFCApplication2View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}


BOOL CMFCApplication2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	
	return DoPreparePrinting(pInfo);
}

void CMFCApplication2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CMFCApplication2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


#ifdef _DEBUG

void CMFCApplication2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication2Doc* CMFCApplication2View::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication2Doc)));
	return (CMFCApplication2Doc*)m_pDocument;
}
#endif //_DEBUG

void CMFCApplication2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	p1 = p2 = point;
	CView::OnLButtonDown(nFlags, point);
}

void CMFCApplication2View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags == MK_LBUTTON)
	{
		CPen pen1, pen2;
		pen1.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		pen2.CreateStockObject(WHITE_PEN);
		CClientDC d(this);
		d.SelectObject(&pen2);
		d.MoveTo(p1); d.LineTo(p2);
		p2 = point;
		d.SelectObject(&pen1);
		d.MoveTo(p1); d.LineTo(p2);
	}
	CView::OnMouseMove(nFlags, point);
}

void CMFCApplication2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	MyLine *p = new MyLine(p1, p2);
	CMFCApplication2Doc* pDoc = GetDocument();
	p->add(pDoc->pF);
	pDoc->SetModifiedFlag(1);

	CView::OnLButtonUp(nFlags, point);
}

void CMFCApplication2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	pDoc->text += (TCHAR)nChar;
	CClientDC dc(this);
	dc.TextOut(50, 50, pDoc->text);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
void CMFCApplication2View::OnDraw(CDC* pDC)
{
	CMFCApplication2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	pDC->SelectObject(pen);
	MyLine *p = pDoc->pF;
	while (p)
	{
		pDC->MoveTo(p->p1);
		pDC->LineTo(p->p2);
		p = p->pNext;
	}

	pDC->TextOut(50, 50, pDoc->text);
	if (pDoc->flagFig1)
	{
		pDC->SelectObject(&pen1);
		pDC->SelectObject(&brush1);
		pDC->Rectangle(100, 100, 200, 200);
	}
	if (pDoc->flagFig2)
	{
		pDC->SelectObject(&pen1);
		pDC->SelectObject(&brush1);
		pDC->Ellipse(300, 100, 400, 200);
	}
}


void CMFCApplication2View::OnElementCircle32777()
{
	CClientDC dc(this);
	dc.SelectObject(&pen1);
	dc.SelectObject(&brush1);
	dc.Ellipse(300, 100, 400, 200);
	CMFCApplication2Doc* pDoc = GetDocument();
	pDoc->flagFig2 = true;

}


void CMFCApplication2View::OnElementSquare32778()
{
	CClientDC dc(this);
	dc.SelectObject(&pen1);
	dc.SelectObject(&brush1);
	dc.Rectangle(100, 100, 200, 200);
	CMFCApplication2Doc* pDoc = GetDocument();
	pDoc->flagFig1 = true;
}


void CMFCApplication2View::OnElementAda()
{
	CClientDC dc(this);
	dc.SelectObject(&pen1);
	dc.SelectObject(&brush1);
	dc.Pie(100, 100, 200, 200, 100, 200, 300, 400);
	CMFCApplication2Doc* pDoc = GetDocument();
	pDoc->flagFig2 = true;
}

