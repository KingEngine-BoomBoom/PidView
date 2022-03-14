#pragma once

#include <QDialog>
#include "ui_NoteDialog.h"

class NoteDialog : public QDialog
{
	Q_OBJECT

public:
	NoteDialog(QWidget *parent = Q_NULLPTR);
	~NoteDialog();
private slots:
	void onCloseButtonSlot();//按下关闭键按键
private:
	Ui::NoteDialog ui;
};
