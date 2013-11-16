#ifndef LAPTIME_H
#define LAPTIME_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Laptime : public QWidget
{
 Q_OBJECT

 public:
  Laptime(int lane, QColor col);
  void reset();

 protected:
  void paintEvent(QPaintEvent *ev);

 public slots:
  void new_lap_time(int gpio, double time);

 private:
  double  m_lapTime;
  double  m_lastlapTimeABS;
  double  m_lapAvg;
  int     m_lapCount;
  double  m_lapBest;
  double  m_lapsToCatch;
  int     m_lane;
  QColor  m_color;
};

#endif //LAPTIME_H
