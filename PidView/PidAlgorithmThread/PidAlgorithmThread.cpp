#include "../stdafx.h"
#include "PidAlgorithmThread.h"



RecordCalculateWork::RecordCalculateWork(int Num):unitNum(Num)
{

}
void RecordCalculateWork::recordCalculate()     //数据转换、运算与分析
{
	//qDebug() << "entry Thread";
	//gThreadMutex.lock();
	//isCalculateFinish = 1;
	//gThreadMutex.unlock();
}
void RecordCalculateWork::FindMaxAndMin(double *pArr, int nStart, int nEnd, double &nMax, double &nMin)
{
    if (nEnd - nStart <= 1)
    {
        if(pArr[nStart] > pArr[nEnd])
        {
            nMax = pArr[nStart];
            nMin = pArr[nEnd];
        }
        else
        {
            nMax = pArr[nEnd];
            nMin = pArr[nStart];
        }
        return;
    }

    double nLeftMax = 0;
    double nLeftMin = 0;
    double nRightMax = 0;
    double nRightMin = 0;
    FindMaxAndMin(pArr, nStart, nStart+(nEnd-nStart)/2, nLeftMax, nLeftMin);
    FindMaxAndMin(pArr, nStart+(nEnd-nStart)/2+1, nEnd, nRightMax, nRightMin);

    nMax = nLeftMax > nRightMax ? nLeftMax : nRightMax;
    nMin = nLeftMin < nRightMin ? nLeftMin : nRightMin;
}
/*************************************************************************************************/

RecordCalculateThread::RecordCalculateThread(int Num):unitNum(Num)
{
}
void RecordCalculateThread::run()
{
    recordCalculateWork = new RecordCalculateWork(unitNum);//必须这么做
    exec();//重点
}
void RecordCalculateThread::closePthread()
{
    this->terminate();  //结束线程，线程是否立即终止取决于操作系统!!!exit()则直接退出没有智能处理功能。
    this->wait();
}