#include "../stdafx.h"
#include "titlebar.h"

#ifdef Q_OS_WIN
//#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#endif

TitleBar::TitleBar(QWidget* parent, int Mode)
    : QWidget(parent), modeFlage(Mode)
{
    //setFixedHeight(30);
    //setFixedWidth (1191)、


    backGround = QColor(60, 60, 60);
    QPalette pal(palette());
    pal.setColor(QPalette::Background, backGround);//QColor(40, 40, 40)QColor(227, 138, 32)
    setAutoFillBackground(true);
    setPalette(pal);

    QStringList qssTitle;
    qssTitle.append(QString("QPushButton#minimizeButton {border-radius: 4px;background: rgb(60, 60, 60);image: url(:/image/rsources/minimize);}"));
    qssTitle.append(QString("QPushButton#minimizeButton:hover {background: rgb(70, 70, 70);image: url(:/image/rsources/minimizeHover);}"));
    qssTitle.append(QString("QPushButton#minimizeButton:pressed {background: rgb(65, 65, 65);image: url(:/image/rsources/minimizePressed);}"));

    qssTitle.append(QString("QPushButton#closeButton {border-radius: 4px;background: rgb(60, 60, 60);image: url(:/image/rsources/close);}"));
    qssTitle.append(QString("QPushButton#closeButton:hover {background: rgb(70, 70, 70);image: url(:/image/rsources/closeHover);}"));
    qssTitle.append(QString("QPushButton#closeButton:pressed {background: rgb(65, 65, 65);image: url(:/image/rsources/closePressed);}"));

    qssTitle.append(QString("QPushButton#maximizeButton[maximizeProperty=\"maximize\"] {border-radius: 4px;background: rgb(60, 60, 60);image: url(:/image/rsources/maximize.png);}"));
    qssTitle.append(QString("QPushButton#maximizeButton[maximizeProperty=\"maximize\"]:hover {background: rgb(70, 70, 70);image: url(:/image/rsources/maximizeHover);}"));
    qssTitle.append(QString("QPushButton#maximizeButton[maximizeProperty=\"maximize\"]:pressed {background: rgb(65, 65, 65);image: url(:/image/rsources/maximizePressed);}"));

    qssTitle.append(QString("QPushButton#maximizeButton[maximizeProperty=\"restore\"] {border-radius: 4px;background: rgb(60, 60, 60);image: url(:/image/rsources/restore);}"));
    qssTitle.append(QString("QPushButton#maximizeButton[maximizeProperty=\"restore\"]:hover {background: rgb(70, 70, 70);image: url(:/image/rsources/restoreHover);}"));
    qssTitle.append(QString("QPushButton#maximizeButton[maximizeProperty=\"restore\"]:pressed {background: rgb(65, 65, 65);image: url(:/image/rsources/restorePressed);}"));
    qssTitleBar = qssTitle.join("");
    this->setStyleSheet(qssTitleBar);

    m_pIconLabel = new QLabel(this);                //左上角图标
    
	m_pIconLabel->setStyleSheet("QLabel{"
		"border-image:url(:/image/rsources/my.png) 2 2 2 2 stretch stretch;"
		"background: rgb(60, 60, 60);}");
	//m_pIconLabel->setPixmap(QPixmap(QString(":/image/rsources/my.png")));
	//QIcon icon;
	//icon.addFile(QStringLiteral(":/image/rsources/my.ico"), QSize(), QIcon::Normal, QIcon::Off);
	//m_pIconLabel->setWindowIcon(icon);
	//widget->setWindowIcon(icon);

    m_pTitleLabel = new QLabel(this);

    m_pTitleLabel->setText(QStringLiteral("PID模拟实验台"));
    m_pTitleLabel->setStyleSheet(QString("QLabel{color:white;size:14};"));
    m_pMinimizeButton = new QPushButton(this);
    /*QStringList qssMin;
    qssMin.append(QString("QPushButton {border-radius: 4px;background: rgb(60, 60, 60);image: url(:/image/rsources/minimize);}"));
    qssMin.append(QString("QPushButton:hover {background: rgb(70, 70, 70);image: url(:/image/rsources/minimizeHover);}"));
    qssMin.append(QString("QPushButton:pressed {background: rgb(65, 65, 65);image: url(:/image/rsources/minimizePressed);}"));
    m_pMinimizeButton->setStyleSheet(qssMin.join(""));*/

    m_pMaximizeButton = new QPushButton(this);


    m_pCloseButton = new QPushButton(this);
    /*QStringList qssClose;
    qssClose.append(QString("QPushButton#closeButton {border-radius: 4px;background: rgb(60, 60, 60);image: url(:/image/rsources/close);}"));
    qssClose.append(QString("QPushButton#closeButton:hover {background: rgb(70, 70, 70);image: url(:/image/rsources/closeHover);}"));
    qssClose.append(QString("QPushButton#closeButton:pressed {background: rgb(65, 65, 65);image: url(:/image/rsources/closePressed);}"));
    m_pCloseButton->setStyleSheet(qssClose.join(""));*/



    m_pIconLabel->setFixedSize(20, 20);         //设置固定宽高 且不可以改变大小
    m_pIconLabel->setScaledContents(true);//按比例填充图片

    m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    m_pMinimizeButton->setFixedSize(27, 22);
    m_pMaximizeButton->setFixedSize(27, 22);
    m_pCloseButton->setFixedSize(27, 22);

    m_pTitleLabel->setObjectName("whiteLabel");
    m_pMinimizeButton->setObjectName("minimizeButton");
    m_pMaximizeButton->setObjectName("maximizeButton");
    m_pCloseButton->setObjectName("closeButton");

    m_pMinimizeButton->setToolTip(QStringLiteral("最小化"));//"Minimize"
    m_pMaximizeButton->setToolTip(QStringLiteral("最大化"));//"Maximize"
    m_pCloseButton->setToolTip(QStringLiteral("关闭"));//"Close"

    QHBoxLayout* pLayout = new QHBoxLayout(this);
    pLayout->addWidget(m_pIconLabel);
    pLayout->addSpacing(5);
    pLayout->addWidget(m_pTitleLabel);
    pLayout->addStretch(100);
    pLayout->addWidget(m_pMinimizeButton);
    pLayout->addStretch(1);
    pLayout->addWidget(m_pMaximizeButton);
    pLayout->addStretch(1);
    pLayout->addWidget(m_pCloseButton);
    pLayout->setSpacing(1);
    pLayout->setContentsMargins(5, 0, 5, 0);

    setLayout(pLayout);

    connect(m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pMaximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pCloseButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

TitleBar::~TitleBar()
{

}
void TitleBar::paintEvent(QPaintEvent*)
{
    //if(!modeFlage){Color(190,190,190)
    QPainter p(this);       //点缀一抹横线
    if (isRun) {

		p.setPen(QPen(QColor(0, 136, 236), 4, Qt::SolidLine, Qt::RoundCap));//QColor(228,138,32)
		p.drawLine(0, this->height(), this->width() - 1, this->height());



    }

    //p.setPen(QPen(QColor(255,255,255),2,Qt::SolidLine,Qt::RoundCap));//228,138,32
    //p.drawLine(0, 0, this->width() - 1, 0);
    //p.drawLine(0, 0, 0, this->height() - 1);
    //p.drawLine(this->width() - 1, 0, this->width() - 1, this->height() - 1);

//}
}
void TitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
    Q_UNUSED(event);

    emit m_pMaximizeButton->clicked();
}

void TitleBar::mousePressEvent(QMouseEvent* event)
{
#ifdef Q_OS_WIN
    if (ReleaseCapture())
    {
        QWidget* pWindow = this->window();
        if (pWindow->isTopLevel())
        {
            SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
        }
    }
    event->ignore();
#else
#endif
}

bool TitleBar::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::WindowTitleChange) {
        QWidget* pWidget = qobject_cast<QWidget*>(obj);
        if (pWidget)
        {
            m_pTitleLabel->setText(pWidget->windowTitle());
            return true;
        }
    }
    else if (event->type() == QEvent::WindowIconChange) {
        QWidget* pWidget = qobject_cast<QWidget*>(obj);
        if (pWidget)
        {
            QIcon icon = pWidget->windowIcon();
            m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
            return true;
        }
    }
    else if (event->type() == QEvent::Resize) {
        QWidget* pWidget = qobject_cast<QWidget*>(obj);
        updateMaximize();
        setFixedWidth(pWidget->width());           //当窗口大小发生变化时标题栏宽度发生变化
        emit syncWidthToMenuBar(pWidget->width());  //当窗口大小发生变化时将窗口宽度发送到菜单栏
        emit syncCenWidget();
        return true;
    }
    // case QEvent::WindowStateChange:
    return QWidget::eventFilter(obj, event);
}

void TitleBar::onClicked()
{
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());
    QWidget* pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == m_pMinimizeButton)
        {
            pWindow->showMinimized();
        }
        else if (pButton == m_pMaximizeButton)
        {
            pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
        }
        else if (pButton == m_pCloseButton)
        {
            pWindow->close();
        }
    }
}

void TitleBar::updateMaximize()
{
    QWidget* pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        bool bMaximize = pWindow->isMaximized();
        if (bMaximize)
        {
            //setFixedWidth (2000);
            m_pMaximizeButton->setToolTip(QStringLiteral("还原"));
            m_pMaximizeButton->setProperty("maximizeProperty", "restore");
        }
        else
        {
            //setFixedWidth (1191);
            m_pMaximizeButton->setToolTip(QStringLiteral("最大化"));
            m_pMaximizeButton->setProperty("maximizeProperty", "maximize");
        }
        /*QStringList qssMax;
        qssMax.append(QString("QPushButton#maximizeButton[maximizeProperty=\"maximize\"] {border-radius: 4px;background: rgb(60, 60, 60);image: url(:/image/rsources/maximize.png);}"));
        qssMax.append(QString("QPushButton#maximizeButton[maximizeProperty=\"maximize\"]:hover {background: rgb(70, 70, 70);image: url(:/image/rsources/maximizeHover);}"));
        qssMax.append(QString("QPushButton#maximizeButton[maximizeProperty=\"maximize\"]:pressed {background: rgb(65, 65, 65);image: url(:/image/rsources/maximizePressed);}"));

        qssMax.append(QString("QPushButton#maximizeButton[maximizeProperty=\"restore\"] {border-radius: 4px;background: rgb(60, 60, 60);image: url(:/image/rsources/restore);}"));
        qssMax.append(QString("QPushButton#maximizeButton[maximizeProperty=\"restore\"]:hover {background: rgb(70, 70, 70);image: url(:/image/rsources/restoreHover);}"));
        qssMax.append(QString("QPushButton#maximizeButton[maximizeProperty=\"restore\"]:pressed {background: rgb(65, 65, 65);image: url(:/image/rsources/restorePressed);}"));
        m_pMaximizeButton->setStyleSheet(qssMax.join(""));*/
        this->setStyleSheet(qssTitleBar);
        //m_pMaximizeButton->setStyle(QApplication::style());
    }
}
