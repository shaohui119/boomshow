// moniView.h : interface of the CMoniView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MONIVIEW_H__7AA04368_87F0_4086_B991_EEEAC7B511D2__INCLUDED_)
#define AFX_MONIVIEW_H__7AA04368_87F0_4086_B991_EEEAC7B511D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMoniView : public CView
{
protected: // create from serialization only
	CMoniView();
	DECLARE_DYNCREATE(CMoniView)

// Attributes
public:
	CMoniDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoniView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMoniView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMoniView)
	afx_msg void OnPaint();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in moniView.cpp
inline CMoniDoc* CMoniView::GetDocument()
   { return (CMoniDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONIVIEW_H__7AA04368_87F0_4086_B991_EEEAC7B511D2__INCLUDED_)
