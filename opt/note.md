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

```sql
CREATE TABLE `information` (
  `InstrumentID` varchar(16) NOT NULL COMMENT '合约代码',
  `TradingDay` date DEFAULT NULL COMMENT '交易日',
  `UpdateTime` time DEFAULT NULL COMMENT '最后修改时间',
  `LastPrice` float DEFAULT NULL COMMENT '最新价',
  `BidPrice` float DEFAULT NULL COMMENT '买价',
  `AskPrice` float DEFAULT NULL COMMENT '卖价',
  `BidVolume` int(11) DEFAULT NULL COMMENT '买量',
  `AskVolue` int(11) DEFAULT NULL COMMENT '卖量',
  `Volume` int(11) DEFAULT NULL COMMENT '成交量',
  `RiseAndFall` float DEFAULT NULL COMMENT '涨跌',
  `Increase` float DEFAULT NULL COMMENT '涨幅',
  `OpenInterest` double DEFAULT NULL COMMENT '持仓量',
  `DailyInterest` double DEFAULT NULL COMMENT '日增仓',
  `OpenPrice` float DEFAULT NULL COMMENT '今开盘',
  `HighestPrice` float DEFAULT NULL COMMENT '最高价',
  `LowestPrice` float DEFAULT NULL COMMENT '最低价',
  `SettlementPrice` float DEFAULT NULL COMMENT '今结算',
  `ClosePrice` float DEFAULT NULL COMMENT '今收盘',
  `PreOpenInterest` double DEFAULT NULL COMMENT '昨持仓量',
  `PreClosePrice` float DEFAULT NULL COMMENT '昨收盘',
  `PreSettlementPrice` float DEFAULT NULL COMMENT '昨结算',
  PRIMARY KEY (`InstrumentID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8

```

```sql
CREATE TABLE `update1` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '接收数据编号',
  `InstrumentID` varchar(20) DEFAULT NULL COMMENT '合约代码',
  `TradingDay` date DEFAULT NULL COMMENT '交易日',
  `UpdateTime` time DEFAULT NULL COMMENT '最后修改时间',
  `PreSettlementPrice` float DEFAULT NULL COMMENT '昨结算',
  `PreClosePrice` float DEFAULT NULL COMMENT '昨收盘',
  `PreOpenInterest` double DEFAULT NULL COMMENT '昨持仓量',
  `OpenPrice` float DEFAULT NULL COMMENT '今开盘',
  `HighestPrice` float DEFAULT NULL COMMENT '最高价',
  `LowestPrice` float DEFAULT NULL COMMENT '最低价',
  `ClosePrice` float DEFAULT NULL COMMENT '今收盘',
  `SettlementPrice` float DEFAULT NULL COMMENT '今结算',
  `LastPrice` float DEFAULT NULL COMMENT '最新价',
  `Volume` int(11) DEFAULT NULL COMMENT '成交量',
  `OpenInterest` double DEFAULT NULL COMMENT '持仓量',
  `BidPrice1` float DEFAULT NULL COMMENT '申买价一',
  `BidVolume1` int(11) DEFAULT NULL COMMENT '申买量一',
  `AskPrice1` float DEFAULT NULL COMMENT '申卖价一',
  `AskVolume1` int(11) DEFAULT NULL COMMENT '申卖量一',
  `BidPrice2` float DEFAULT NULL COMMENT '申买价二',
  `BidVolume2` int(11) DEFAULT NULL COMMENT '申买量二',
  `AskPrice2` float DEFAULT NULL COMMENT '申卖价二',
  `AskVolume2` int(11) DEFAULT NULL COMMENT '申卖量二',
  `BidPrice3` float DEFAULT NULL COMMENT '申买价三',
  `BidVolume3` int(11) DEFAULT NULL COMMENT '申买量三',
  `AskPrice3` float DEFAULT NULL COMMENT '申卖价三',
  `AskVolume3` int(11) DEFAULT NULL COMMENT '申卖量三',
  `BidPrice4` float DEFAULT NULL COMMENT '申买价四',
  `BidVolume4` int(11) DEFAULT NULL COMMENT '申买量四',
  `AskPrice4` float DEFAULT NULL COMMENT '申卖价四',
  `AskVolume4` int(11) DEFAULT NULL COMMENT '申卖量四',
  `BidPrice5` float DEFAULT NULL COMMENT '申买价五',
  `BidVolume5` int(11) DEFAULT NULL COMMENT '申买量五',
  `AskPrice5` float DEFAULT NULL COMMENT '申卖价五',
  `AskVolume5` int(11) DEFAULT NULL COMMENT '申卖量五',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=879 DEFAULT CHARSET=latin1

```