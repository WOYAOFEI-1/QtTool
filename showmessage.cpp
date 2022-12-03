#include "showmessage.h"
#include "ui_showmessage.h"
#include <QCloseEvent>
#include <QScreen>
#include <QRandomGenerator>
#include <ctime>
#include <QLineSeries>
#include <QValueAxis>
#include <QTime>
showMessage::showMessage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showMessage)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &showMessage::refresh);
    connect(ui->pushButton_2, &QPushButton::pressed, this, &showMessage::refreshFourSecond);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);
    m_dataTable = generateRandomData(m_listCount, m_valueMax, m_valueCount);
    QChartView *chartView;

    chartView = new QChartView(createLineChart());
    ui->horizontalLayout->addWidget(chartView);
    ui->horizontalLayout->setContentsMargins(0, 0, 0, 0);
    ui->verticalLayout->setContentsMargins(0, 0, 0, 0);
    ui->horizontalLayout_2->setContentsMargins(0, 0, 0, 8);

    QScreen *screen = qApp->primaryScreen();
    int widthMax = screen->size().width() / 3;            //屏幕宽
    int heightMax = screen->size().height() / 3;
    int widthMin = 320;            //屏幕宽
    int heightMin = 319;

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
    QTime current_time = QTime::currentTime();

    int hour = current_time.hour();        //当前的小时
    int minute = current_time.minute();    //当前的分
    int second = current_time.second();    //当前的秒
    int msec = current_time.msec();        //当前的毫秒

    time_t now = time(0);
    qDebug() << hour << " " << minute << " " << second << " " << msec;
    series->setName("yuyonmgsheng");
    // 把 now 转换为字符串形式
  //  char* dt = ctime(&now);
   // ui->lineEdit->setText(QString(dt));
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
   else if(event->button() == Qt::RightButton){
        //如果是右键
        qApp->quit();

    }
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

DataTable showMessage::generateRandomData(int listCount, int valueMax, int valueCount)
{
    DataTable dataTable;

    // generate random data
    for (int i(0); i < listCount; i++) {
        DataList dataList;
        qreal yValue(0);
        for (int j(0); j < valueCount; j++) {
            yValue = yValue + QRandomGenerator::global()->bounded(valueMax / (qreal) valueCount);
            QPointF value((j + QRandomGenerator::global()->generateDouble()) * ((qreal) m_valueMax / (qreal) valueCount),
                          yValue);
            QString label = "Slice " + QString::number(i) + ":" + QString::number(j);
            dataList << Data(value, label);
        }
        dataTable << dataList;
    }

    return dataTable;
}

QChart *showMessage::createLineChart()
{
    //![1]
    QChart *chart = new QChart();
    chart->setTitle("Line chart");
    //![1]

    //![2]
    QString name("Series ");
    int nameIndex = 0;
    for (const DataList &list : m_dataTable) {
        series = new QLineSeries(chart);
        for (const Data &data : list)
            series->append(data.first);
        series->setName(name + QString::number(nameIndex));
        nameIndex++;
        chart->addSeries(series);
    }
    //![2]

    //![3]
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, m_valueMax);
    chart->axes(Qt::Vertical).first()->setRange(0, m_valueCount);
    //![3]
    //![4]
    // Add space to label to add space between labels and axis
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f  ");
    //![4]

    return chart;
}
