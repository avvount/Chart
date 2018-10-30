
void OnBnClickedButton1()
{
    // TODO: 在此添加控件通知处理程序代码

    ////测试用代码,向数据库中插入数据
    CString sql;
    CString InstrumentID;
    
    CTime tm; 
    tm = CTime::GetCurrentTime();
    CString TradingDay = tm.Format("%Y%m%d");
    CString UpdateTime = tm.Format("%H:%M:%S");
    CString TradingTime = tm.Format("%Y-%m-%d %H:%M:%S");
    int LastPrice, OpenPrice, PreSettlementPrice, PreClosePrice, PreOpenInterest,
	HighestPrice, LowestPrice, ClosePrice, SettlementPrice, Volume, OpenInterest,
	BidPrice1, BidVolume1, AskPrice1, AskVolume1, BidPrice2, BidVolume2, AskPrice2,
	AskVolume2, BidPrice3, BidVolume3, AskPrice3, AskVolume3, BidPrice4, BidVolume4,
	AskPrice4, AskVolume4, BidPrice5, BidVolume5, AskPrice5, AskVolume5;
	for (int k = 1; k < 15; k++)
	{
		InstrumentID.Format("IF19%02d", k);

		OpenPrice = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		LastPrice = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		PreOpenInterest = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		PreSettlementPrice = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		PreClosePrice = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		HighestPrice = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		LowestPrice = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		ClosePrice = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		SettlementPrice = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		OpenInterest = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidPrice1 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidPrice2 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidPrice3 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidPrice4 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidPrice5 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidVolume1 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidVolume2 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidVolume3 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidVolume4 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		BidVolume5 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);

		AskPrice1 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1100);
		AskPrice2 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1100);
		AskPrice3 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1100);
		AskPrice4 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1100);
		AskPrice5 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1100);
		AskVolume1 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		AskVolume2 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		AskVolume3 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		AskVolume4 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		AskVolume5 = (int)((sin((double)k) + 2) * 1500 + rand() % 3000 - 1000);
		Volume = rand() % 9999;

		sql.Format("INSERT INTO update1 (InstrumentID, TradingTime, TradingDay, UpdateTime, \
                           PreSettlementPrice, PreClosePrice, PreOpenInterest, \
                           OpenPrice, HighestPrice, LowestPrice, ClosePrice, \
                           SettlementPrice, LastPrice,Volume, OpenInterest, \
                           BidPrice1, BidVolume1, AskPrice1, AskVolume1,BidPrice2,\
                           BidVolume2, AskPrice2, AskVolume2, BidPrice3, BidVolume3,\
                           AskPrice3, AskVolume3, BidPrice4, BidVolume4, AskPrice4,\
                           AskVolume4,BidPrice5, BidVolume5, AskPrice5, AskVolume5) \
                           VALUES ('%s','%s','%s','%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\
                           %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d);"\
		, InstrumentID, TradingTime,TradingDay, UpdateTime, PreSettlementPrice,
		PreClosePrice, PreOpenInterest, OpenPrice, HighestPrice,
		LowestPrice, ClosePrice, SettlementPrice, LastPrice, Volume,
		OpenInterest, BidPrice1, BidVolume1, AskPrice1, AskVolume1,
		BidPrice2, BidVolume2, AskPrice2, AskVolume2, BidPrice3,
		BidVolume3, AskPrice3, AskVolume3, BidPrice4, BidVolume4,
		AskPrice4, AskVolume4, BidPrice5, BidVolume5, AskPrice5,
		AskVolume5);
		db.ExecuteSQL(sql);
	}
}

void OnBnClickedButton2()
{
    // TODO: 在此添加控件通知处理程序代码
    CString sql;
    CString InstrumentID;

    CTime tm = CTime::GetCurrentTime();
	CString TradingDay = tm.Format("%Y%m%d");
	CString UpdateTime = tm.Format("%H:%M:%S");

	int LastPrice, BidPrice, AskPrice, BidVolume, AskVolue, Volume, RiseAndFall, 
	OpenInterest, DailyInterest, OpenPrice, HighestPrice, LowestPrice, SettlementPrice,
	ClosePrice, PreOpenInterest, PreClosePrice, PreSettlementPrice, BidPrice1, AskPrice1,
	BidVolume1, AskVolume1;
	float Increase;
	for (int k = 1; k < 10; k++)
	{
		InstrumentID.Format("IF19%02d", k);
		LastPrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		BidPrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		AskPrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		
		OpenInterest = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		DailyInterest = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		OpenPrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		HighestPrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		LowestPrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		SettlementPrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		ClosePrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		PreOpenInterest = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		PreClosePrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		PreSettlementPrice = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		BidPrice1 = (int)((sin((double)k) + 2) * 500 + rand() % 3000);

		BidVolume1 = (int)((sin((double)k) + 2) * 500 + rand() % 3000);
		AskVolume1 = rand() % 998 + 1;
		AskPrice1 = rand() % 998 + 1;
		Volume = rand() % 9998 + 1;
		BidVolume = rand() % 998 + 1;
		AskVolue = rand() % 998 + 1;
		RiseAndFall = rand() % 300 - 150;
		Increase = (float)RiseAndFall / OpenPrice;

        sql.Format("update information set TradingDay='%s',UpdateTime = '%s',LastPrice=%d,\
                   BidPrice=%d, AskPrice=%d ,BidVolume=%d, AskVolue=%d,Volume=%d,RiseAndFall=%d ,\
                   Increase=%d, OpenInterest=%d, DailyInterest=%d,OpenPrice=%d, HighestPrice=%d, \
                   LowestPrice=%d, SettlementPrice=%d,ClosePrice=%d, PreOpenInterest=%d, PreClosePrice=%d,\
                   PreSettlementPrice=%d where InstrumentID = '%s'",\
                   TradingDay, UpdateTime,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,InstrumentID);
        db.ExecuteSQL(sql);


		//sql.Format("INSERT INTO information (InstrumentID,TradingDay,UpdateTime,LastPrice,BidPrice,AskPrice,BidVolume,AskVolue,Volume,RiseAndFall,Increase,OpenInterest,DailyInterest,OpenPrice,HighestPrice,LowestPrice,SettlementPrice,ClosePrice,PreOpenInterest,PreClosePrice,PreSettlementPrice) VALUES	('%s','%s','%s',%.2f,%.2f,%.2f,%d,%d,%d,%.2f,%.2f,%.4f,%.4f,%.2f,%.2f,%.2f,%.2f,%.2f,%.4f,%.2f,%.2f)",InstrumentID,TradingDay,UpdateTime,LastPrice,BidPrice,AskPrice,BidVolume,AskVolue,Volume,RiseAndFall,Increase,OpenInterest,DailyInterest,OpenPrice,HighestPrice,LowestPrice,SettlementPrice,ClosePrice,PreOpenInterest,PreClosePrice,PreSettlementPrice);
		sql.Format("update information set TradingDay='%s',UpdateTime = '%s',\
            RiseAndFall=%d ,Increase=%.2f, OpenInterest=%d,\
            DailyInterest=%d, OpenPrice=%d where InstrumentID = '%s'",
		TradingDay, UpdateTime, RiseAndFall, Increase, OpenInterest, DailyInterest,
		OpenPrice, InstrumentID);

		db.ExecuteSQL(sql);
	}


}