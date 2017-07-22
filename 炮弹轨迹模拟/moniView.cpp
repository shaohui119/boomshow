// moniView.cpp : implementation of the CMoniView class
//

#include "stdafx.h"
#include "moni.h"
#include "iostream.h"
#include "moniDoc.h"
#include "moniView.h"
#include "math.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMoniView

IMPLEMENT_DYNCREATE(CMoniView, CView)

BEGIN_MESSAGE_MAP(CMoniView, CView)
	//{{AFX_MSG_MAP(CMoniView)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoniView construction/destruction

CMoniView::CMoniView()
{
	// TODO: add construction code here

}

CMoniView::~CMoniView()
{
}

BOOL CMoniView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMoniView drawing




HCURSOR m_HCross;
int m_Dragging;
 POINT point;
 POINT endpoint;
 POINT processpoint;
POINT beginpoint;
POINT origin;
double speedx,speedy;
int left=0;
int right=0;

//设置变量



void CMoniView::OnDraw(CDC* pDC)
{
	CMoniDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
   
	// TODO: add draw code for native data here
   
	CClientDC dc(this); 
   	CPen pen(PS_SOLID,10,RGB(0,0,0));
	CPen *pOldPen = dc.SelectObject(&pen);
	dc.MoveTo(origin);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);
    //水平线变粗
	point.x=0;
	point.y=700;
	pDC->SetPixel(point,RGB(250,0,0));
	

	pDC->MoveTo(point.x,point.y);//画线的起点选择
	
	origin.x=9000;
	origin.y=700;
	pDC->LineTo(origin.x,origin.y);
	//画地平线
	/*CClientDC dc(this);*/
	//pDC->MoveTo(endpoint.x+2,endpoint.y+2);
    //pDC->LineTo(processpoint.x+2,processpoint.y+2);

CFont font;
   font.CreatePointFont(500, "Garamond");//第一个表示字形大小
   CFont *pFont = pDC->SelectObject(&font);

COLORREF color = RGB(0,0,255);//文字颜色
   pDC->SetTextColor(color);
   pDC->TextOut(400, 100, "炮弹轨迹模拟", 12);//文字左上角位置，写的文字，文字的数目
                                           
pDC->SelectObject(pFont);
   font.DeleteObject();

   CFont font1;
   font1.CreatePointFont(250, "Garamond");//第一个表示字形大小
  CFont *pFont1 = pDC->SelectObject(&font1);
COLORREF color1 = RGB(0,0,0);//文字颜色
   pDC->SetTextColor(color1);
   pDC->TextOut(530, 180, "制作人：李绍辉 林诗钧", 21);//文字左上角位置，写的文字，文字的数目
                                           
   //写文字
   

	

}

/////////////////////////////////////////////////////////////////////////////
// CMoniView printing

BOOL CMoniView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMoniView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
	
}

void CMoniView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMoniView diagnostics

#ifdef _DEBUG
void CMoniView::AssertValid() const
{
	CView::AssertValid();
}

void CMoniView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMoniDoc* CMoniView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMoniDoc)));
	return (CMoniDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMoniView message handlers

void CMoniView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
     CDC   dcMem;
    dcMem.CreateCompatibleDC(&dc);             
    CBitmap   bmp;             
    bmp.LoadBitmap(IDB_BITMAP2); //IDB_BITMAP是你自己的图对应的ID            
    BITMAP   bitmap;             
    bmp.GetBitmap(&bitmap);             
    CBitmap   *pbmpOld=dcMem.SelectObject(&bmp);
    
    
        dc.BitBlt(50-left*60+right*60,400,bitmap.bmWidth*2,bitmap.bmHeight*2,&dcMem,0,0,SRCCOPY);
    
    dcMem.SelectObject(pbmpOld);
	//画炮

     OnDraw(&dc); //调用了OnDraw
	//画出地平线

	 CDC   dcMem1;
    dcMem1.CreateCompatibleDC(&dc);             
    CBitmap   bmp1;             
    bmp1.LoadBitmap(IDB_BITMAP4); //IDB_BITMAP是你自己的图对应的ID            
    BITMAP   bitmap1;             
    bmp1.GetBitmap(&bitmap1);             
    CBitmap   *pbmpOld1=dcMem1.SelectObject(&bmp1);
    
    
        dc.BitBlt(1200,0,bitmap1.bmWidth*2,bitmap1.bmHeight*2,&dcMem1,0,0,SRCCOPY);
    
    dcMem1.SelectObject(pbmpOld1);

   //右面的飞机

    CDC   dcMem2;
    dcMem2.CreateCompatibleDC(&dc);             
    CBitmap   bmp2;             
    bmp2.LoadBitmap(IDB_BITMAP5); //IDB_BITMAP是你自己的图对应的ID            
    BITMAP   bitmap2;             
    bmp2.GetBitmap(&bitmap2);             
    CBitmap   *pbmpOld2=dcMem2.SelectObject(&bmp2);
    
    
        dc.BitBlt(20,10,bitmap2.bmWidth*2,bitmap2.bmHeight*2,&dcMem2,0,0,SRCCOPY);
    
    dcMem2.SelectObject(pbmpOld2);

    //左面的飞机


	CDC   dcMem3;
    dcMem3.CreateCompatibleDC(&dc);             
    CBitmap   bmp3;             
    bmp3.LoadBitmap(IDB_BITMAP6); //IDB_BITMAP是你自己的图对应的ID            
    BITMAP   bitmap3;             
    bmp3.GetBitmap(&bitmap3);             
    CBitmap   *pbmpOld3=dcMem3.SelectObject(&bmp3);
    
    
        dc.BitBlt(0,695,bitmap3.bmWidth*2,bitmap3.bmHeight*2,&dcMem3,0,0,SRCCOPY);
    
    dcMem3.SelectObject(pbmpOld3);
	//草地

   CDC   dcMem4;
    dcMem4.CreateCompatibleDC(&dc);             
    CBitmap   bmp4;             
    bmp4.LoadBitmap(IDB_BITMAP7); //IDB_BITMAP是你自己的图对应的ID            
    BITMAP   bitmap4;             
    bmp4.GetBitmap(&bitmap4);             
    CBitmap   *pbmpOld4=dcMem4.SelectObject(&bmp4);
    
    
        dc.BitBlt(800,695,bitmap4.bmWidth*2,bitmap4.bmHeight*2,&dcMem4,0,0,SRCCOPY);
    
    dcMem4.SelectObject(pbmpOld4);
	//草地

	CDC   dcMem6;
    dcMem6.CreateCompatibleDC(&dc);             
    CBitmap   bmp6;             
    bmp6.LoadBitmap(IDB_BITMAP9); //IDB_BITMAP是你自己的图对应的ID            
    BITMAP   bitmap6;             
    bmp6.GetBitmap(&bitmap6);             
    CBitmap   *pbmpOld6=dcMem6.SelectObject(&bmp6);
    
    
        dc.BitBlt(1400,695,bitmap6.bmWidth*2,bitmap6.bmHeight*2,&dcMem6,0,0,SRCCOPY);
    
    dcMem6.SelectObject(pbmpOld6);


CDC   dcMem5;
    dcMem5.CreateCompatibleDC(&dc);             
    CBitmap   bmp5;             
    bmp5.LoadBitmap(IDB_BITMAP8); //IDB_BITMAP是你自己的图对应的ID            
    BITMAP   bitmap5;             
    bmp5.GetBitmap(&bitmap5);             
    CBitmap   *pbmpOld5=dcMem5.SelectObject(&bmp5);
    
    
        dc.BitBlt(1300,390,bitmap5.bmWidth*2,bitmap5.bmHeight*2,&dcMem5,0,0,SRCCOPY);
    
    dcMem5.SelectObject(pbmpOld5);

 
  //炮靶




	// TODO: Add your message handler code here
	
	// Do not call CView::OnPaint() for painting messages
}




void CMoniView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate();
	
	/*CClientDC dc(this);
	point=beginpoint;
	//BOOL Ellipse(int x1,int y1,int x2,int y2);
	dc.Ellipse(beginpoint.x,beginpoint.y,beginpoint.x,beginpoint.y);
	
	endpoint = beginpoint;*///画点
    

	//
	::SetCursor(m_HCross);//这一句能防止左键单击的时候，保持鼠标样式不变
    beginpoint=point;
    endpoint=point;
    SetCapture();//捕获鼠标，充分控制鼠标
    m_Dragging=1;
    RECT Rect;
    GetClientRect(&Rect);//取得窗口当前显示坐标
    ClientToScreen(&Rect);//转换为屏幕坐标
    ::ClipCursor(&Rect);//限定光标在指定矩形了吗
   //杜仕浩



	CView::OnLButtonDown(nFlags, point);
}
void CMoniView::OnLButtonUp(UINT nFlags, CPoint point) 
{
    
	CClientDC dc(this);
	dc.MoveTo(endpoint);
	dc.LineTo(point);

	//画出线
    


       


	//
	if (m_Dragging)
    {
		m_Dragging=0;
        ::ReleaseCapture();//结束捕获鼠标
        ::ClipCursor(NULL);//解锁鼠标
        CClientDC ClientDC(this);
        ClientDC.SetROP2(R2_NOT);
        ClientDC.MoveTo(beginpoint);
        ClientDC.LineTo(endpoint);//擦去上一次的临时线
        ClientDC.SetROP2(R2_COPYPEN);//缺省绘图模式，像素为画笔颜色
        ClientDC.MoveTo(beginpoint);
        ClientDC.LineTo(point);//绘制固定线
        RedrawWindow();
    }
    //

	 speedx=fabs(endpoint.x-beginpoint.x)/2;
		speedy=fabs(endpoint.y-beginpoint.y)/2;
      //根据线段长度求初速度
    //李绍辉




	for(long t = 0; ; t++)
	{
			//RedrawWindow();
		beginpoint.x = 316-left*60+right*60+speedx*t;
		beginpoint.y = 442-speedy*t+5*t*t;
		dc.SetPixel(beginpoint,RGB(255,0,0));
		dc.Ellipse(beginpoint.x-13,beginpoint.y-13,beginpoint.x+13,beginpoint.y+13);
		
		Sleep(100);

        
		if(beginpoint.y >=560||beginpoint.x>=1020)
		{
		 
     CDC   dcMem;
    dcMem.CreateCompatibleDC(&dc);             
    CBitmap   bmp;             
    bmp.LoadBitmap(IDB_BITMAP3); //IDB_BITMAP是你自己的图对应的ID            
    BITMAP   bitmap;             
    bmp.GetBitmap(&bitmap);             
    CBitmap   *pbmpOld=dcMem.SelectObject(&bmp);
    
    
        dc.BitBlt(beginpoint.x-20,beginpoint.y-20,bitmap.bmWidth*2,bitmap.bmHeight*2,&dcMem,0,0,SRCCOPY);
    
    dcMem.SelectObject(pbmpOld);
			break;
		}
	
	}
	//运动轨迹
   //杜仕浩

   



	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, beginpoint);
}



//
void CMoniView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
      if (m_Dragging)
    {
        CClientDC ClientDC(this);
        ClientDC.SetROP2(R2_NOT);//逆转当前屏幕颜色来画线的绘图方式
        ClientDC.MoveTo(beginpoint);//
        ClientDC.LineTo(endpoint);   //擦去上一次的线
        ClientDC.MoveTo(beginpoint);
        ClientDC.LineTo(point);//绘制这一次的临时线
        endpoint=point;
    }

	
	CView::OnMouseMove(nFlags, point);
}
//杜仕浩

void CMoniView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	char cChar;//当前被按下的字符
    HCURSOR hCursor = 0;//显示光标句柄
    HCURSOR hPrevCursor = 0;//以前的光标句柄
    cChar = char(nChar);//将按下的键转换为字符
    if(cChar == VK_RIGHT)
	{
			Invalidate();
		right++;
	}
	   
	if(cChar == VK_LEFT)
		{
			Invalidate();
		left++;
	}
	
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
