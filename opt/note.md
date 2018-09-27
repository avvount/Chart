## 统计宽字节的字符串长度  
```cpp
wchar_t *p="aaa";  
int len=wcslen(p2);  
```

## CString 转 char *  

```cpp
CString str("aaa");
CSringA tmp;    
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

2. 在头文件中添加消息响应函数原型声明  

Eg:
```cpp
afx_msg LRESULT OnrecvData(WPARAM wParam,LPARAM lParam);
```    

3. 在源文件中`BEGIN_MESSAGE_MAP( )`和`END_MESSAGE_MAP()`之间添加消息映射，不要写在` //}}AFX_MSG_MAP`宏之间    

Eg:
```cpp
ON_MESSAGE(WM_RECVDATA,OnRecvData)
```

4. 编写消息响应函数的实现 

5. 在引发或发出消息的地方使用SendMessage或PostMessage发送消息  

## 类的动态创建  

在头文件中添加`DECLARE_DYNCREATE(class_name)`宏，源文件中添加`IMPLEMENT_DYNCREATE(class_name , base_class_name)`宏。

## Sublime快捷键设置  

1. `Ctrl + hjkl `快速移动光标,在首选项->快捷键设置中添加以下代码  
```json
[
	{ "keys": ["ctrl+h"], "command": "move", "args": {"by": "characters", "forward": false} },
	{ "keys": ["ctrl+l"], "command": "move", "args": {"by": "characters", "forward": true} },
	{ "keys": ["ctrl+k"], "command": "move", "args": {"by": "lines", "forward": false} },
	{ "keys": ["ctrl+j"], "command": "move", "args": {"by": "lines", "forward": true} },
	{ "keys": ["ctrl+shift+h"], "command": "move", "args": {"by": "words", "forward": false} },
	{ "keys": ["ctrl+shift+l"], "command": "move", "args": {"by": "word_ends", "forward": true} },
]
```

2. 开启vim模式

在用户设置中将`Vintage`从`ignored_packages`中删除  

