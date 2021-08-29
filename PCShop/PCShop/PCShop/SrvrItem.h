
// SrvrItem.h : interface of the CPCShopSrvrItem class
//

#pragma once

class CPCShopSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(CPCShopSrvrItem)

// Constructors
public:
	CPCShopSrvrItem(CPCShopDoc* pContainerDoc);

// Attributes
	CPCShopDoc* GetDocument() const
		{ return reinterpret_cast<CPCShopDoc*>(COleServerItem::GetDocument()); }

// Overrides
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// Implementation
public:
	~CPCShopSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

