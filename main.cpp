#include <QtGui>
#include <QDebug>
#include <QThread>
#include <QApplication>

#if BENCHMARK
static QTime performanceTimer;
#endif

#include "mainwindow.h"

int main( int argc, char **argv )
{
  QApplication app( argc, argv );
  
  MainWindow mainWindow;
  mainWindow.setFixedSize(1360,768);
  mainWindow.showNormal();
  return app.exec();
}
