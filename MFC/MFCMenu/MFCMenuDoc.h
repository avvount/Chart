
// MFCMenuDoc.h : CMFCMenuDoc ��Ľӿ�
//


#pragma once


class CMFCMenuDoc : public CDocument
{
protected: // �������л�����
	CMFCMenuDoc();
	DECLARE_DYNCREATE(CMFCMenuDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CMFCMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


