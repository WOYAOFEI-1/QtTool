#include "start.h"
#include <QDebug>
#include "showmessage.h"

Start::Start()
{
    hook.installHook(&hook);
    qRegisterMetaType<Hook::Type>("Type");//为了信号中能传递自定义枚举类型，如果传递常规参数，可省略该行
    connect(&hook,SIGNAL(sendKeyType(Type)),this,SLOT(checkType(Type)));
    msg = std::make_unique<showMessage>();
}

Start::~Start()
{
    hook.unInstallHook();
}

void Start::checkType(Hook::Type type){

    switch (type) {
    case Hook::CTRL_ALT:
    {
        if (msg->isVisible())
        {
            msg->setVisible(false);
        }
        else
        {
            msg->show();
           // msg->activateWindow();
//msg->setWindowFlags(Qt::WindowStaysOnTopHint);
        }
        break;
    }
    default:
        break;
    }

}
