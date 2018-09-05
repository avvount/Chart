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

## 事件对象与互斥对象都属于内核对象  

## 添加自定义消息 

1. 定义消息宏  

Eg:
```cpp
#define WM_RECVDATA WM_USER+1
```  

2. 在头文件中`DECLARE_MESSAGE_MAP()`上方添加消息响应函数原型声明  

Eg:
```cpp
afx_msg void OnrecvData(WPARAM wParam,LPARAM lParam);
```    

3. 在源文件中`BEGIN_MESSAGE_MAP( )`和`END_MESSAGE_MAP()`之间添加消息映射  

Eg:
```cpp
ON_MESSAGE(WM_RECVDATA,OnRecvData)
```

4. 编写消息响应函数的实现 

5. 在引发或发出消息的地方使用SendMessage或PostMessage发送消息  