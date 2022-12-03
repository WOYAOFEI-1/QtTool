#ifndef START_H
#define START_H

#include "hook.h"
#include <memory>

class showMessage;
class Start : public QObject
{
    Q_OBJECT
public:
    Start();
    ~Start();
private:
    Hook hook;//钩子对象
    std::unique_ptr<showMessage> msg;
private slots:
    void checkType(Hook::Type);
};

#endif // START_H
