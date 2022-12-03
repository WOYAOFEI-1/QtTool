#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include <QWidget>
#include <QMouseEvent>
namespace Ui {
class showMessage;
}

class showMessage : public QWidget
{
    Q_OBJECT

public:
    explicit showMessage(QWidget *parent = nullptr);
    ~showMessage();
    void closeEvent ( QCloseEvent * e ) override;
private slots:
    void refresh();
    void refreshFourSecond();
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QPoint mousePoint;
    bool mouse_press;
private:
    Ui::showMessage *ui;
};

#endif // SHOWMESSAGE_H
