#include"stdafx.h"
#include "NoteDialog.h"
NoteDialog::NoteDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose); //走析构函数 attribute n.属性，特性。
	setWindowFlags(Qt::WindowStaysOnTopHint);//让进程窗口始终在最上层
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());  //这条语句在ui.setupUi(this)语句下面才有效果  隐藏原始边框

	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(onCloseButtonSlot()));//
}

NoteDialog::~NoteDialog()
{
}
void NoteDialog::onCloseButtonSlot()
{
	this->close();
}