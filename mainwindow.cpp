
#include "mainwindow.h"
#include "laptimenotifier.h"
#include "laptime.h"

#include <QFont>
#include <QColor>

MainWindow::MainWindow() 
{
  setWindowFlags(Qt::FramelessWindowHint);
  setGeometry(0,0,800,480);
  layout = new QGridLayout(this);
  QList<QColor> colorList;
  colorList.append(QColor(255,0,0));
  colorList.append(QColor(0,255,0));

  QList<int> gpioLaneList;
  gpioLaneList.append(17);//lane 1
  gpioLaneList.append(18);//lane 2

  for (int i=0; i<2; i++) //for now change to argument handling later
  {
    Laptime *lt = new Laptime(gpioLaneList.at(i), colorList.at(i));
    LaptimeNotifier::instance()->connectLane(lt);
    layout->addWidget(lt, i, 0);
  }
  layout->setSpacing(10);
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
  QPainter painter(this);

  painter.setRenderHint (QPainter:: Antialiasing);

  painter.setBrush(QBrush(QColor(143,243,143)));

  QPen pen;
  pen.setStyle(Qt::NoPen);
  painter.setPen(pen);

  QRect bg(0,0, width(), height());
  painter.drawRoundedRect(bg, 10.0f, 10.f);
}
