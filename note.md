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