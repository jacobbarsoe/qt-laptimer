#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QPainter>

class MainWindow : public QWidget
{
 public:
  MainWindow();

 protected:
  void paintEvent(QPaintEvent *ev);

 private:
  QGridLayout *layout;
};

#endif //MAINWINDOW_H



