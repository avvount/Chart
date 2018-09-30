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

```sql
CREATE TABLE `information` (
  `InstrumentID` varchar(16) NOT NULL COMMENT '��Լ����',
  `TradingDay` date DEFAULT NULL COMMENT '������',
  `UpdateTime` time DEFAULT NULL COMMENT '����޸�ʱ��',
  `LastPrice` float DEFAULT NULL COMMENT '���¼�',
  `BidPrice` float DEFAULT NULL COMMENT '���',
  `AskPrice` float DEFAULT NULL COMMENT '����',
  `BidVolume` int(11) DEFAULT NULL COMMENT '����',
  `AskVolue` int(11) DEFAULT NULL COMMENT '����',
  `Volume` int(11) DEFAULT NULL COMMENT '�ɽ���',
  `RiseAndFall` float DEFAULT NULL COMMENT '�ǵ�',
  `Increase` float DEFAULT NULL COMMENT '�Ƿ�',
  `OpenInterest` double DEFAULT NULL COMMENT '�ֲ���',
  `DailyInterest` double DEFAULT NULL COMMENT '������',
  `OpenPrice` float DEFAULT NULL COMMENT '����',
  `HighestPrice` float DEFAULT NULL COMMENT '��߼�',
  `LowestPrice` float DEFAULT NULL COMMENT '��ͼ�',
  `SettlementPrice` float DEFAULT NULL COMMENT '�����',
  `ClosePrice` float DEFAULT NULL COMMENT '������',
  `PreOpenInterest` double DEFAULT NULL COMMENT '��ֲ���',
  `PreClosePrice` float DEFAULT NULL COMMENT '������',
  `PreSettlementPrice` float DEFAULT NULL COMMENT '�����',
  PRIMARY KEY (`InstrumentID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8

```

```sql
CREATE TABLE `update1` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '�������ݱ��',
  `InstrumentID` varchar(20) DEFAULT NULL COMMENT '��Լ����',
  `TradingDay` date DEFAULT NULL COMMENT '������',
  `UpdateTime` time DEFAULT NULL COMMENT '����޸�ʱ��',
  `PreSettlementPrice` float DEFAULT NULL COMMENT '�����',
  `PreClosePrice` float DEFAULT NULL COMMENT '������',
  `PreOpenInterest` double DEFAULT NULL COMMENT '��ֲ���',
  `OpenPrice` float DEFAULT NULL COMMENT '����',
  `HighestPrice` float DEFAULT NULL COMMENT '��߼�',
  `LowestPrice` float DEFAULT NULL COMMENT '��ͼ�',
  `ClosePrice` float DEFAULT NULL COMMENT '������',
  `SettlementPrice` float DEFAULT NULL COMMENT '�����',
  `LastPrice` float DEFAULT NULL COMMENT '���¼�',
  `Volume` int(11) DEFAULT NULL COMMENT '�ɽ���',
  `OpenInterest` double DEFAULT NULL COMMENT '�ֲ���',
  `BidPrice1` float DEFAULT NULL COMMENT '�����һ',
  `BidVolume1` int(11) DEFAULT NULL COMMENT '������һ',
  `AskPrice1` float DEFAULT NULL COMMENT '������һ',
  `AskVolume1` int(11) DEFAULT NULL COMMENT '������һ',
  `BidPrice2` float DEFAULT NULL COMMENT '����۶�',
  `BidVolume2` int(11) DEFAULT NULL COMMENT '��������',
  `AskPrice2` float DEFAULT NULL COMMENT '�����۶�',
  `AskVolume2` int(11) DEFAULT NULL COMMENT '��������',
  `BidPrice3` float DEFAULT NULL COMMENT '�������',
  `BidVolume3` int(11) DEFAULT NULL COMMENT '��������',
  `AskPrice3` float DEFAULT NULL COMMENT '��������',
  `AskVolume3` int(11) DEFAULT NULL COMMENT '��������',
  `BidPrice4` float DEFAULT NULL COMMENT '�������',
  `BidVolume4` int(11) DEFAULT NULL COMMENT '��������',
  `AskPrice4` float DEFAULT NULL COMMENT '��������',
  `AskVolume4` int(11) DEFAULT NULL COMMENT '��������',
  `BidPrice5` float DEFAULT NULL COMMENT '�������',
  `BidVolume5` int(11) DEFAULT NULL COMMENT '��������',
  `AskPrice5` float DEFAULT NULL COMMENT '��������',
  `AskVolume5` int(11) DEFAULT NULL COMMENT '��������',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=879 DEFAULT CHARSET=latin1

```