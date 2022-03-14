#pragma once
#include <QtWidgets>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <QSettings>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QtDebug>
#include <QThread>
#include <QSemaphore>
#include <QWaitCondition>
#include <QMutex>
#include <QDir>
#include <QSharedMemory>
#include <QObject>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QApplication>
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QtCore/qglobal.h>

#ifdef Q_OS_WIN
//#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#endif

#include "PidView.h"
#include "ui_PidView.h"

#include "Titlebar/titlebar.h"
#include "FlatUI/flatui.h"
//constexpr auto PID_POINTS_AMOUNT = 1000;				//模拟算法计算的点数
#define CURVEWIDE   1//不可以大于1.  画图的线宽
//#define POINTS_COUNT	500		//模拟绘图时的点数
////第一步：定义PID变量结构体，代码如下
//typedef struct _gPid {
//	float SetTargetHeight;					//定义设定值(飞机的目标高度)
//	float ActualHeight;						//实际值（飞机的实际高度）
//	float err;								//定义偏差值
//	float err_last;							//定义上一个偏差值
//	float Kp, Ki, Kd;						//定义比例、积分、微分系数
//	float integral;							//定义积分值
//	float OutSpeed;							//定义飞机速度（控制执行器的变量，实际是通过升力控制飞机的速度方向与大小）
//	float LastOutSpeed;						//通过速度变化求出位移变化即飞机的实际高度
//
//}MyPid;
extern QVector<double> HorizontalAxisValue;	//横轴数值
extern QVector<double> ActualValue;			//执行器（电机）输出值
extern QVector<double> DifferenceValue;		//目标值与输出值的差值