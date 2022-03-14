#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PidView.h"
#include "NoteDialog.h"
#include "Titlebar/titlebar.h"
#include "PidAlgorithmThread/PidAlgorithmThread.h"
//第一步：定义PID变量结构体，代码如下
typedef struct _gPid {
	float SetTargetHeight;					//定义设定值(飞机的目标高度)
	float ActualHeight;						//实际值（飞机的实际高度）
	float err;								//定义偏差值
	float err_last;							//定义上一个偏差值
	float Kp, Ki, Kd;						//定义比例、积分、微分系数
	float integral;							//定义积分值
	float OutSpeed;							//定义飞机速度（控制执行器的变量，实际是通过升力控制飞机的速度方向与大小）
	float LoadValue;						//定义负载值，这里模拟为风阻的风速
	float LastOutSpeed;						//通过速度变化求出位移变化即飞机的实际高度

}MyPid;
class PidView : public QMainWindow
{
    Q_OBJECT

public:
    PidView(QWidget *parent = Q_NULLPTR);
	void setViewInterface(QCustomPlot *customPlot);
	void PidViewGraph();
private:
	Ui::PidViewClass ui;
	TitleBar* pTitleBar;
	NoteDialog *pNoteDialog;
	RecordCalculateThread * dataCollection = NULL;               //数据采集 与 算法运行 线程

	QVector<QCheckBox*>CheckBoxSet;
	QVector<int>    GraphSelectedByCheckBox;         //记录都有哪些波形被选择  0代表第一波形

	QTimer ReplotGraphTimer;
	QTimer refreshAxisTimer;                //因为共用一个横轴的原因 所以要实时更新坐标轴信息
	QCPAxisRect *curveRect[4];              //曲线坐标系
	QCPAxis *onlyCurveXAxis;               //共用的时间轴
	bool timeAxisSelectFlage = false;       //时间轴是否被点选标志位
	int selectRect;                         //表格响应鼠标事件（拖拽和拉伸）的位置

	//pid部分
	void PID_GetDrawPoints();
	void PID_init(MyPid& VirtualPid);
	float PID_realize(MyPid& VirtualPid);
private slots:
	void onCheckBoxSet(int i);	//选择波形时触发该槽

	void ReplotGraphSlot();                          //数据界面刷新
	void RefreshAxisSlot();                     //定时刷新坐标轴的信号槽
	void onPushButtonSlot();

	void on_horizontalSliderP_valueChanged(int value);
	void on_horizontalSliderI_valueChanged(int value);
	void on_horizontalSliderD_valueChanged(int value);

	void mousePress();
	void mouseWheel();
	void selectionChanged();
	void contextMenuRequest(QPoint pos);        //鼠标右键  图像复位
signals:
	void dataOperationSignal();                 //一波数据整理后 送给线程 使之继续发送新的数据
};
