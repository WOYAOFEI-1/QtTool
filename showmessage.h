#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include <QWidget>
#include <QMouseEvent>
#include <QChart>
#include <QChartView>
namespace Ui {
class showMessage;
}
class QLineSeries;
typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QList<DataList> DataTable;

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
    DataTable generateRandomData(int listCount, int valueMax, int valueCount);
    QChart *createLineChart();
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QLineSeries *series = nullptr;
    int m_listCount{1};
    int m_valueMax{24};
    int m_valueCount{7};
    QList<QChartView *> m_charts;
    DataTable m_dataTable;

    QPoint mousePoint;
    bool mouse_press;
private:
    Ui::showMessage *ui;
};

#endif // SHOWMESSAGE_H
