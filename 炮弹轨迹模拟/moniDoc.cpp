// moniDoc.cpp : implementation of the CMoniDoc class
//

#include "stdafx.h"
#include "moni.h"

#include "moniDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMoniDoc

IMPLEMENT_DYNCREATE(CMoniDoc, CDocument)

BEGIN_MESSAGE_MAP(CMoniDoc, CDocument)
	//{{AFX_MSG_MAP(CMoniDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoniDoc construction/destruction

CMoniDoc::CMoniDoc()
{
	// TODO: add one-time construction code here

}

CMoniDoc::~CMoniDoc()
{
}

BOOL CMoniDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMoniDoc serialization

void CMoniDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMoniDoc diagnostics

#ifdef _DEBUG
void CMoniDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMoniDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMoniDoc commands
