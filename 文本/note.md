## ͳ�ƿ��ֽڵ��ַ�������  
```cpp
wchar_t *p="aaa";  
int len=wcslen(p2);  
```

## CString ת char *  

```cpp
CString str("aaa");
CSringA tmp;    //CString�ڶ��ֽڻ�����ΪCSringA,�ڿ��ֽڻ�����ΪCStringW
tmp=str; 
char *p=tmp.GetBuffer();
```

## �¼������뻥����������ں˶���  

## ����Զ�����Ϣ 

1. ������Ϣ��  

Eg:
```cpp
#define WM_RECVDATA WM_USER+1
```  

2. ��ͷ�ļ���`DECLARE_MESSAGE_MAP()`�Ϸ������Ϣ��Ӧ����ԭ������  

Eg:
```cpp
afx_msg void OnrecvData(WPARAM wParam,LPARAM lParam);
```    

3. ��Դ�ļ���`BEGIN_MESSAGE_MAP( )`��`END_MESSAGE_MAP()`֮�������Ϣӳ��  

Eg:
```cpp
ON_MESSAGE(WM_RECVDATA,OnRecvData)
```

4. ��д��Ϣ��Ӧ������ʵ�� 

5. �������򷢳���Ϣ�ĵط�ʹ��SendMessage��PostMessage������Ϣ  