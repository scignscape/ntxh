
// // license___here

#include "ImgResource.h"

#include <QIcon>

#include <QDebug>

// package facsanadu.gui.resource;


/**
 * Common icons. By loading them once, memory is conserved
 * 
 * @author Johan Henriksson
 *
 */

/*
byte[] ImgResource::readStreamIntoArray(InputStream is) throws IOException
{
 if(is==null)
   throw new IOException("Inputstream is null");
 byte[] arr=LabnoteUtil.readStreamToArray(is);
 is.close();
 return arr;
}
*/

QPixmap* ImgResource::getIcon(QString name)
{
 //qDebug() << "I: " << QString("%1/%2").arg(DEFAULT_ICON_FOLDER).arg(name);

 QPixmap* pm = new QPixmap(QString("%1/%2").arg(DEFAULT_ICON_FOLDER).arg(name));  
 return pm;
/*
 try 
 {

  QPixmap pm; //=new QPixmap();
  pm.loadFromData(readStreamIntoArray(ImgResource.class.getResourceAsStream(name)));
  return pm;
 }  

 catch (...) //IOException e) 
 {
  //System.err.println("Unable to read "+name+" "+e.getMessage());
  return nullptr;
 }
*/
}


QPixmap& ImgResource::imgWindowIcon() { return *getIcon("programIcon.png"); }

QPixmap& ImgResource::moveRight() { return *getIcon("tango-go-next.png"); }
QPixmap& ImgResource::moveLeft() { return *getIcon("tango-go-previous.png"); }

QPixmap& ImgResource::moveUp() { return *getIcon("tango-go-up.png"); }
QPixmap& ImgResource::moveDown() { return *getIcon("tango-go-down.png"); }

QPixmap& ImgResource::icon_delete() { return *getIcon("tango-trash.png"); }

QPixmap& ImgResource::gateEllipse() { return *getIcon("fugue-shape-ellipse.png"); }
QPixmap& ImgResource::gateRect() { return *getIcon("fugue-shape-rect.png"); }
QPixmap& ImgResource::gatePolygon() { return *getIcon("fugue-shape-polygon.png"); }
QPixmap& ImgResource::gateRange() { return *getIcon("shape-interval.png"); }
QPixmap& ImgResource::gateSelect() { return *getIcon("drawSelect.png"); }


void ImgResource::setWindowIcon(QWidget* w)
{
 w->setWindowIcon(QIcon(imgWindowIcon()));
}

QLabel* ImgResource::label(QPixmap* p)
{
 QLabel* lab = new QLabel();
 lab->setPixmap(*p);
 return lab;
}

