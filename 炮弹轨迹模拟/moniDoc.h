// moniDoc.h : interface of the CMoniDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MONIDOC_H__43FEAC24_2498_4422_A76A_558231C2DF22__INCLUDED_)
#define AFX_MONIDOC_H__43FEAC24_2498_4422_A76A_558231C2DF22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMoniDoc : public CDocument
{
protected: // create from serialization only
	CMoniDoc();
	DECLARE_DYNCREATE(CMoniDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoniDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMoniDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMoniDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONIDOC_H__43FEAC24_2498_4422_A76A_558231C2DF22__INCLUDED_)
