
// ReadWriteDoc.h : CReadWriteDoc ��Ľӿ�
//


#pragma once


class CReadWriteDoc : public CDocument
{
protected: // �������л�����
	CReadWriteDoc();
	DECLARE_DYNCREATE(CReadWriteDoc)

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
	virtual ~CReadWriteDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//    afx_msg void OnCustomApiwrite();
};


