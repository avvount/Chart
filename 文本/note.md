## 统计宽字节的字符串长度  
```cpp
wchar_t *p="aaa";  
int len=wcslen(p2);  
```

## CString 转 char *  

```cpp
CString str("aaa");
CSringA tmp;    //CString在多字节环境下为CSringA,在宽字节环境下为CStringW
tmp=str; 
char *p=tmp.GetBuffer();
```