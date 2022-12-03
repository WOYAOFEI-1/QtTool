#ifndef GETALLKEYEVENT_H
#define GETALLKEYEVENT_H

#include <QWidget>
#include "hook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class getAllKeyEvent; }
QT_END_NAMESPACE

class getAllKeyEvent : public QWidget
{
    Q_OBJECT

public:
    getAllKeyEvent (QWidget *parent = nullptr);
    ~getAllKeyEvent();

private slots:
    void checkType(Hook::Type);
private:
    Hook hook;//钩子对象
    Ui::getAllKeyEvent *ui;
};
#endif // GETALLKEYEVENT_H
