
// MFCApplication2Doc.h : ��������� ������ CMFCApplication2Doc
//


#pragma once
#include "MyLine.h"

class CMFCApplication2Doc : public CDocument
{
protected: // ������� ������ �� ������������
	CMFCApplication2Doc();
	DECLARE_DYNCREATE(CMFCApplication2Doc)

// ��������
public:

	MyLine *pF;
	bool flagFig1, flagFig2;
	CString text;

public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CMFCApplication2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
