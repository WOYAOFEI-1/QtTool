//#include "globalapp.h".h"
//#include "ui_widget.h"
//#include <QDebug>
//#include <QMetaType>

//Widget::Widget(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::Widget)
//{
//    ui->setupUi(this);
//    hook.installHook(&hook);
//    qRegisterMetaType<Hook::Type>("Type");//为了信号中能传递自定义枚举类型，如果传递常规参数，可省略该行
//    connect(&hook,SIGNAL(sendKeyType(Type)),this,SLOT(checkType(Type)));
//}

//Widget::~Widget()
//{
//    delete ui;
//    hook.unInstallHook();
//}

//void Widget::checkType(Hook::Type type){
//    switch (type) {
//    case Hook::CHANGE:
//        ui->plainTextEdit->appendPlainText("按下按钮 Ctrl+1 \n");
//        break;
//    case Hook::CHANGEBACK:
//        ui->plainTextEdit->appendPlainText("按下按钮 Ctrl+2 \n");
//        break;
//    default:
//        break;
//    }

//}
