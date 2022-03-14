#ifndef RECORDCALCULATETHREAD_H
#define RECORDCALCULATETHREAD_H
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<QSettings>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QtDebug>
#include <QThread>
//#include <unistd.h>
#include <QSemaphore>
#include <QWaitCondition>
#include <QMutex>
#include <QDir>
#include <QSharedMemory>
#include <Windows.h>
class RecordCalculateWork:public QObject
{
    Q_OBJECT
public:
    RecordCalculateWork(int Num);
    QTimer *recordCalculateTimer;
private:
    int unitNum;
    void FindMaxAndMin(double *pArr, int nStart, int nEnd, double&nMax, double&nMin);
   
public slots:
    void recordCalculate();
};

class RecordCalculateThread : public QThread
{
    Q_OBJECT
public:
    RecordCalculateThread(int Num);
    RecordCalculateWork *recordCalculateWork;
private:
    int unitNum;
protected:
    void run();
public slots:
    void closePthread();

};


#endif // RECORDCALCULATETHREAD_H
