#pragma once
#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QPainter>
class QLabel;
class QPushButton;

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget* parent = 0, int Mode = 0);
    ~TitleBar();
    QPushButton* m_pMinimizeButton;
    QLabel* m_pTitleLabel;
    QPushButton* m_pMaximizeButton;

    QString qssTitleBar;
    QColor backGround;

    bool isRun = true;
protected:
    void mouseDoubleClickEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    bool eventFilter(QObject* obj, QEvent* event);
    void paintEvent(QPaintEvent*);
private:
    QStringList qssMain;
    int modeFlage;
    QLabel* m_pIconLabel;
    QPushButton* m_pCloseButton;

    void updateMaximize();
private slots:
    void onClicked();
signals:
    void syncWidthToMenuBar(int);
    void syncCenWidget();

};

#endif // TITLEBAR_H
