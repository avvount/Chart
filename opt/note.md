## ͳ�ƿ��ֽڵ��ַ�������  
```cpp
wchar_t *p="aaa";  
int len=wcslen(p2);  
```

## CString ת char *  

```cpp
CString str("aaa");
CSringA tmp;    
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

2. ��ͷ�ļ��������Ϣ��Ӧ����ԭ������  

Eg:
```cpp
afx_msg LRESULT OnrecvData(WPARAM wParam,LPARAM lParam);
```    

3. ��Դ�ļ���`BEGIN_MESSAGE_MAP( )`��`END_MESSAGE_MAP()`֮�������Ϣӳ�䣬��Ҫд��` //}}AFX_MSG_MAP`��֮��    

Eg:
```cpp
ON_MESSAGE(WM_RECVDATA,OnRecvData)
```

4. ��д��Ϣ��Ӧ������ʵ�� 

5. �������򷢳���Ϣ�ĵط�ʹ��SendMessage��PostMessage������Ϣ  

## ��Ķ�̬����  

��ͷ�ļ������`DECLARE_DYNCREATE(class_name)`�꣬Դ�ļ������`IMPLEMENT_DYNCREATE(class_name , base_class_name)`�ꡣ

## Sublime��ݼ�����  

1. `Ctrl + hjkl `�����ƶ����,����ѡ��->��ݼ�������������´���  
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

2. ����vimģʽ

���û������н�`Vintage`��`ignored_packages`��ɾ��  

