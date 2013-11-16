#include <QtGui>
#include <QDebug>
#include <QThread>

#if BENCHMARK
static QTime performanceTimer;
#endif

#include "mainwindow.h"

int main( int argc, char **argv )
{
  QApplication app( argc, argv );
  
  MainWindow mainWindow;

  mainWindow.show();
  return app.exec();
}
