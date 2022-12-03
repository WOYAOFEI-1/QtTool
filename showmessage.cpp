#include "showmessage.h"
#include "ui_showmessage.h"
#include <QCloseEvent>
#include <QScreen>
showMessage::showMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showMessage)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &showMessage::refresh);
    connect(ui->pushButton_2, &QPushButton::pressed, this, &showMessage::refreshFourSecond);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);

    QScreen *screen = qApp->primaryScreen();
    int widthMax = screen->size().width() / 3;            //屏幕宽
    int heightMax = screen->size().height() / 3;
    int widthMin = screen->size().width() / 6;            //屏幕宽
    int heightMin = screen->size().height() / 6;

    this->setMaximumSize(widthMax, heightMax);
    this->setMinimumSize(widthMin, heightMin);
    this->resize(widthMin, heightMin);
   // this->setSize(widthMin, heightMin);
   // this->overrideWindowFlags(Qt::WindowStaysOnTopHint);
}

showMessage::~showMessage()
{
    delete ui;
}

void showMessage::closeEvent(QCloseEvent *e)
{
    hide();
    e->ignore();
}

void showMessage::refresh()
{
    auto time = clock();
    ui->lineEdit->setText(QString::number(time));
}


void showMessage::refreshFourSecond()
{

}

void showMessage::mousePressEvent(QMouseEvent *event)
{

   if (event->button() == Qt::LeftButton)
    {
       mouse_press = true;
       mousePoint = event->globalPos() - this->pos();
       event->accept();
   }
//   else if(event->button() == Qt::RightButton){
//        //如果是右键
//        this->close();

//    }
}
void showMessage::mouseMoveEvent(QMouseEvent *event)
{

//    if(event->buttons() == Qt::LeftButton){  //如果这里写这行代码，拖动会有点问题
    if(mouse_press){
        move(event->globalPos() - mousePoint);
//        event->accept();
    }
}

void showMessage::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}
