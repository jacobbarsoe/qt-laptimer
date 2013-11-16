#ifndef LAPTIMENOTIFIER_H
#define LAPTIMENOTIFIER_H

#include <QWidget>
#include <QFile>
#include <QPair>
#include <QString>
#include <QSocketNotifier>
#include <QThread>

#include "laptime.h"

class LaptimeNotifier : QThread
{
  Q_OBJECT

public:
  static LaptimeNotifier* instance();
  void connectLane(Laptime *lt);

signals:
  void sig_new_lap(int lane, double time);

private:
  LaptimeNotifier(void);
  void doParse(QString *);
  void run();

  QSocketNotifier *sn;
  QFile file; 

private slots:
  void parseData(void);
};

#endif //LAPTIMENOTIFIER_H



