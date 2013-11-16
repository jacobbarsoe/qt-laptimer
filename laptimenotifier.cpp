#include "laptimenotifier.h"

#include <QDebug>

LaptimeNotifier* LaptimeNotifier::instance() 
{
    static LaptimeNotifier* instance = 0;
    if (instance == 0) {
        instance = new LaptimeNotifier;
    }
    return instance;
}


LaptimeNotifier::LaptimeNotifier ()
{
#ifndef PCSIM
    file.setFileName("/dev/gpio-event");
#else
    file.setFileName("./test.dat");
#endif
    file.open(QIODevice::ReadOnly);

    //we use a socket notifier because qfile does not work on device files   
    sn = new QSocketNotifier(file.handle(), QSocketNotifier::Read);
    connect(sn, SIGNAL(activated(int)), this, SLOT(parseData())); 
}

void LaptimeNotifier::connectLane(Laptime *ln)
{
  connect(this,
	  SIGNAL(sig_new_lap(int, double)),
	  ln, 
	  SLOT(new_lap_time(int, double)));
  sn->setEnabled(true);
}

void LaptimeNotifier::parseData(void)
{
  sn->setEnabled(false);
  this->start();
}

void LaptimeNotifier::run(void)
{
  //select this is threaded
  char buf[256] ;
  while(true) {
    int len = file.readLine(buf, 256);
    if ( len != -1 ) { // new line ready
      doParse(new QString(buf));
      sn->setEnabled(true);
      return;
    }
    msleep(10);
  }
}


void LaptimeNotifier::doParse(QString *s) 
{
  bool ok, ok2;
  int lane;
  double time;
  QStringList data = s->split(" ", QString::SkipEmptyParts);
  if (data.size() > 2) {

    lane = data[0].toInt(&ok, 10);
    time = data[2].toDouble(&ok2);

    if (ok && ok2) 
      sig_new_lap(lane, time); 
  }
}
