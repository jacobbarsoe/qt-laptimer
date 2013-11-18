
#include "laptime.h"

#include <QColor>
#include <QFont>
#include <QPen>
#include <QBrush>
#include <QDebug>

Laptime::Laptime(int index, QColor col)
{
  m_color = col;
  m_lane = index;
  m_flash = false;
  reset();
  timer.setSingleShot(false);

  connect(&timer, SIGNAL(timeout()), this, SLOT(newBestTime()));
}

void Laptime::reset()
{
  m_lapTime = 0; 
  m_lapAvg = 0;
  m_lapCount = 0;
  m_lapBest = 999999999999999;
  m_lapsToCatch = 0;
  m_lastlapTimeABS = 999999999999999;
}

void Laptime::newBestTime()
{
  static int count = 0;
  if (count % 2 == 0)
    m_flash = true;
  else
    m_flash = false;
  if (++count % 8 == 0) {
    timer.stop();
    m_flash = false;
  }
  emit update();

}

void Laptime::new_lap_time(int gpio, double lap)
{
  if (gpio == m_lane) 
    {
      double diff  = lap - m_lastlapTimeABS;
      m_lastlapTimeABS = lap;
      if (diff > 0) {
	m_lapTime = diff;
	m_lapCount++;
	m_lapAvg = m_lapAvg + (m_lapTime - m_lapAvg)/m_lapCount;
	if (m_lapTime < m_lapBest) {
	  m_lapBest = m_lapTime;
	  //if new best make screen flash in timer start
	  emit update();
	  timer.start(100);
	}
	else
	  emit update();
      }
    }
}


void Laptime::paintEvent(QPaintEvent *ev)
{
  QPainter painter(this);
  painter.setRenderHint (QPainter:: Antialiasing);

  if (m_flash)
    painter.setBrush(QBrush(m_color.lighter(200)));
  else
    painter.setBrush(QBrush(m_color));

  QPen pen;
  pen.setStyle(Qt::NoPen);
  painter.setPen(pen);

  QFont f = painter.font();
  f.setPointSize(70*width()/800);
  f.setBold(true);
  painter.setFont(f);

  QRect bg(0,0, width(), height());
  painter.drawRoundedRect(bg, 10.0f, 10.f);

  //font color
  pen.setStyle(Qt::SolidLine);
  pen.setColor(QColor(43,43,43));
  painter.setPen(pen);

  QRect time1(10,                   0, width()/2-2*10, height()/2);
  QRect time2(width()/2+10,         0, width()/2-2*10, height()/2);
  QRect time3(          10,height()/2, width()/2-2*10, height()/2);
  QRect time4(width()/2+10,height()/2, width()/2-2*10, height()/2);
  //laptime
  painter.drawText(time1,
           Qt::AlignRight,
           QString::number(m_lapTime, 'f', 3)); //display ms

  //lap count
  painter.drawText(time2,
                   Qt::AlignRight,
           QString::number(m_lapCount,10)); //display ms

  //laps avg
  painter.drawText(time3,
           Qt::AlignRight,
           QString::number(m_lapAvg, 'f', 3)); //display ms

  //laps best
  double best = 0;
  if (m_lapBest < 99999999)
    best = m_lapBest;
  painter.drawText(time4,
           Qt::AlignRight,
           QString::number(best, 'f', 3)); //display ms

  QRect caption1(width()/20,                     0, width()/5, height()/10);
  QRect caption2(width()/2+width()/20 ,          0, width()/5, height()/10);
  QRect caption3(width()/20,            height()/2, width()/5, height()/10);
  QRect caption4(width()/2+width()/20 , height()/2, width()/5, height()/10);

  f.setPointSize(14*width()/800);
  f.setBold(false);
  painter.setFont(f);

  //draw helper texts
  painter.drawText(caption1,
		   Qt::AlignLeft | Qt::AlignTop,
		   QString("Last Lap")); //display ms
  painter.drawText(caption2,
		   Qt::AlignLeft | Qt::AlignTop,
		   QString("Lap count")); //display ms
  painter.drawText(caption3,
		   Qt::AlignLeft | Qt::AlignTop,
		   QString("Avg Laptime")); //display ms
  painter.drawText(caption4,
		   Qt::AlignLeft | Qt::AlignTop,
		   QString("Best Laptime")); //display ms

}
