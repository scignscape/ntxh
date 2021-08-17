
#include "displayimage.h"

#include <QMessageBox>

#include <QScrollBar>

#include <QGraphicsProxyWidget>

#include "mainwindow.h"


template<>
void DisplayImage_Scene_Item::handle_mouse_event<
  DisplayImage_Scene_Item::Mouse_Event_Modes::Left_Edit>(QMouseEvent* mev)
{

}

template<>
void DisplayImage_Scene_Item::handle_mouse_event<
  DisplayImage_Scene_Item::Mouse_Event_Modes::Left_Move>(QMouseEvent* mev)
{

}

template<>
void DisplayImage_Scene_Item::handle_mouse_event<
  DisplayImage_Scene_Item::Mouse_Event_Modes::Left_Init>(QMouseEvent* mev)
{
 if(!data_->drawingSquareEnabled_ && !data_->drawingEllipseEnabled_ && !data_->drawingPolygonEnabled_)
   QMessageBox::warning(this,"Warning!","Please select the shape's form");
 else
 {
  if(!data_->nameSelected_)
   data_->nameSelected_ = true;
  if(!data_->nameSelected_)
   QMessageBox::warning(this,"Warning!","Please select an instance name");
  else
  {
   data_->shapeID_.clear();
   //qui verranno gestite le condizione di inizio e di fine durante la creazione delle annotazioni

   DisplayImage_Data::Shape_Kind_Enabled_Classification sk = data_->current_enabled_shape_kind();

   switch(sk)
   {
   case DisplayImage_Data::Shape_Kind_Enabled_Classification::Rectangle:
    {
     if(data_->mStartPoint_.isNull())
     { //primo click
      data_->mStartPoint_ = mev->pos();
      data_->mEndPoint_ = mev->pos();
      data_->isMoving_ = true; //inizio
      update();
     }
    }
   }

  }
 }
}



template<>
void DisplayImage_Scene_Item::handle_mouse_event<
  DisplayImage_Scene_Item::Mouse_Event_Modes::Right_Edit>(QMouseEvent* mev)
{

}

template<>
void DisplayImage_Scene_Item::handle_mouse_event<
  DisplayImage_Scene_Item::Mouse_Event_Modes::Right_Move>(QMouseEvent* mev)
{

}

template<>
void DisplayImage_Scene_Item::handle_mouse_event<
  DisplayImage_Scene_Item::Mouse_Event_Modes::Right_Init>(QMouseEvent* mev)
{

}




void DisplayImage_Scene_Item::_handle_mouse_event(QMouseEvent* mev, Mouse_Event_Modes mem)
{
 switch(mem)
 {
#define TEMP_MACRO(x) case Mouse_Event_Modes::x: handle_mouse_event<Mouse_Event_Modes::x>(mev); return;
  TEMP_MACRO(Left_Edit)TEMP_MACRO(Left_Move)TEMP_MACRO(Left_Init)
  TEMP_MACRO(Right_Edit)TEMP_MACRO(Right_Move)TEMP_MACRO(Right_Init)
   default:break;
 }
}



////metodo per la gestione del click da parte dell'utente
//void DisplayImage_Scene_Item::mousePressEvent(QMouseEvent *mouseEvent)
//{
//// return;

// if(data_->pan_mode)
// {
//  mouseEvent->ignore();
//  return;
// }

// if(mouseEvent->button() == Qt::LeftButton) //  !data_->editing_ && !data_->shapeMoving_
// {

// }

//#ifdef HIDE
// //qui viene gestito il tasto destro ed il tasto sinistro del mouse
// //con il tasto sinistro si creano le annotazioni
// if(mouseEvent->button() == Qt::LeftButton && !data_->editing_ && !data_->shapeMoving_)
// {
//  //Se nameSelected falso, allora non si potranno aggiungere nuove shape
//  if(!data_->drawingSquareEnabled_ && !data_->drawingEllipseEnabled_ && !data_->drawingPolygonEnabled_)
//    QMessageBox::warning(this,"Warning!","Please select the shape's form");
//  else
//  {
//   if(!data_->nameSelected_)
//    data_->nameSelected_ = true;
//   if(!data_->nameSelected_)
//    QMessageBox::warning(this,"Warning!","Please select an instance name");
//   else
//   {
//    data_->shapeID_.clear();
//    //qui verranno gestite le condizione di inizio e di fine durante la creazione delle annotazioni
//    if(data_->drawingSquareEnabled_)
//    {
//     if(data_->mStartPoint_.isNull())
//     { //primo click
//      data_->mStartPoint_ = mouseEvent->pos();
//      data_->mEndPoint_ = mouseEvent->pos();
//      data_->isMoving_ = true; //inizio
//      update();
//     }
//     else
//     { //secondo click
//      data_->points_.clear();
//      data_->points_ << data_->mStartPoint_ << QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry())
//              << data_->mEndPoint_ << QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry());
//      data_->isMoving_ = false; //fine
//      DisplayImage_Data::shape another;
//      another.form=square;
//      another.shapePoints = data_->points_;
//      data_->allEdits_ << another; //aggiunta della shape
//      onLineDraw(data_->allEdits_); //signal per MainWindow
//      data_->mStartPoint_ = QPoint();
//      data_->mEndPoint_ = QPoint();
//      data_->points_.clear();
//      update();
//     }
//    }
//    if(data_->drawingEllipseEnabled_)
//    {
//     if(data_->mStartPoint_.isNull())
//     { //primo click
//      data_->mStartPoint_ = mouseEvent->pos();
//      data_->mEndPoint_ = mouseEvent->pos();
//      data_->isMoving_ = true; //inizio
//      update();
//     }
//     else
//     { //secondo click
//      data_->points_.clear();
//      data_->points_ << data_->mStartPoint_ << QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry())
//             << data_->mEndPoint_ <<QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry());
//      data_->isMoving_ = false; //fine
//      DisplayImage_Data::shape another;
//      another.form = ellipse;
//      another.shapePoints = data_->points_;
//      data_->allEdits_ << another; //aggiunta della shape
//      onLineDraw(data_->allEdits_); //signal per MainWindow
//      data_->mStartPoint_ = QPoint();
//      data_->mEndPoint_ = QPoint();
//      data_->points_.clear();
//      update();
//     }
//    }
//    if(data_->drawingPolygonEnabled_)
//    {
//     if(data_->mStartPoint_.isNull())
//     { //primo click
//      data_->mStartPoint_ = mouseEvent->pos();
//      data_->mEndPoint_ = mouseEvent->pos();
//      data_->points_ << data_->mStartPoint_;
//      data_->isMoving_ = true; //inizio
//      update();
//     }
//     else
//     {
//      if(data_->points_.last()!=mouseEvent->pos())
//      { //aggiunta di un punto per il poligono con click successivi
//       if(!(mouseEvent->pos().x() >= data_->points_.first().x() - data_->radius_ &&
//            mouseEvent->pos().x() <= data_->points_.first().x() + data_->radius_ &&
//            mouseEvent->pos().y() >= data_->points_.first().y() - data_->radius_ &&
//            mouseEvent->pos().y() <= data_->points_.first().y() + data_->radius_))
//        data_->points_ << mouseEvent->pos();
//      }
//     }
//     //la parte terminale viene interamente gestita dal metodo per la gestione del doppio-click
//    }
//   }
//  }
// }
// //con il tasto destro si modificano le annotazioni
// if(mouseEvent->button() == Qt::RightButton && !data_->isMoving_)
// {
//  if(!data_->allEdits_.isEmpty())
//  {
//   //questo controllo vuole verificare se il click è stato fatto in prossimit�  di un quadratino
//   //se dovesse essere vero allora l'utente st�  spostando un punto e verr�  reso noto tramite editing
//   for(int i = 0; i < data_->allEdits_.size(); ++i)
//   {
//    for(int j=0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
//    {
//     if(mouseEvent->pos().x() >= data_->allEdits_[i].shapePoints[j].x()-data_->radius_ &&
//        mouseEvent->pos().x() <= data_->allEdits_[i].shapePoints[j].x()+data_->radius_ &&
//        mouseEvent->pos().y() >= data_->allEdits_[i].shapePoints[j].y()-data_->radius_ &&
//        mouseEvent->pos().y() <= data_->allEdits_[i].shapePoints[j].y()+data_->radius_)
//     {
//      data_->editing_ = true;
//      data_->pointPosition_ = j;
//      data_->shapePosition_ = i;
//     }
//    }
//   }
//   if(data_->editing_)
//   {
//    data_->shapeID_ = data_->allEdits_.at(data_->shapePosition_).id;
//    setTuple(data_->shapeID_);
//    data_->mEndPoint_ = mouseEvent->pos();
//    data_->isMoving_ = true; //inizio
//    update();
//   }
//   else{
//    //se il click non non è in prossimit�  di un quadratino si controlla se è allinterno di una shape
//    for(int i=0; i<data_->allEdits_.size(); ++i)
//    {
//     bool inside=false;
//     for(int j=0,k=data_->allEdits_.at(i).shapePoints.size() - 1; j < data_->allEdits_.at(i).shapePoints.size(); k = j++)
//     {
//      //questa condizione, reperibile su internet, verifica se il mouse è all'interno di tutti i punti di un poligono
//      //anche molto complesso, con molta precisione.
//      //se dovesse essere vero allora l'utente st�  spostando un'intera shape e verr�  reso noto tramite shapeMoving

//      //?
//      if(((data_->allEdits_[i].shapePoints[j].y() >= mouseEvent->pos().y())
//        != (data_->allEdits_[i].shapePoints[k].y() >= mouseEvent->pos().y())) &&
//        (mouseEvent->pos().x() <= (data_->allEdits_[i].shapePoints[k].rx() - data_->allEdits_[i].shapePoints[j].rx())*
//        (mouseEvent->pos().y() - data_->allEdits_[i].shapePoints[j].ry())/
//        (data_->allEdits_[i].shapePoints[k].ry() - data_->allEdits_[i].shapePoints[j].ry()) + data_->allEdits_[i].shapePoints[j].rx()))
//          inside = !inside;
//     }
//     if(inside) data_->shapePosition_=i;
//    }
//    if(data_->shapePosition_!=-1)
//    {
//     if(data_->mStartPoint_.isNull())
//     {
//      data_->mStartPoint_ = mouseEvent->pos();
//      data_->mEndPoint_ = mouseEvent->pos();
//      data_->shapeID_ = data_->allEdits_.at(data_->shapePosition_).id;
//      setTuple(data_->shapeID_);
//      data_->shapeMoving_ = true;
//      update();
//     }
//    }
//   }
//  }
// }
//#endif
//}

////metodo per la gestione del rilascio del tasto premuto dall'utente
//void DisplayImage_Scene_Item::mouseReleaseEvent(QMouseEvent *mouseEvent)
//{
//// return;

// if(data_->pan_mode)
// {
//  mouseEvent->ignore();
//  return;
// }




// //questo controllo costinge l'utente a mantenere il tasto destro premuto
// //nel caso di rilascio all'ora l'utente ha terminato la modifica e i valori
// //vengono riportati allo stato precedente conservando eventuali modifiche
// //quindi se l'utente premesse a caso il programma non varierebbe stato
// if(mouseEvent->button() == Qt::RightButton && (data_->editing_ || data_->shapePosition_ != -1))
// {
//  if(data_->editing_)
//  {
//   data_->isMoving_ = false;
//   data_->editing_ = false; //fine
//   onLineDraw(data_->allEdits_); //signal per MainWindow
//   data_->pointPosition_ = 0;
//   data_->shapePosition_ = -1;
//  }
//  if(data_->shapePosition_ != -1)
//  {
//   data_->mEndPoint_ = mouseEvent->pos();
//   data_->shapeMoving_ = false; //fine
//   onLineDraw(data_->allEdits_); //signal per MainWindow
//   data_->mStartPoint_ = QPoint();
//   data_->mEndPoint_ = QPoint();
//   data_->shapePosition_ = -1;
//  }
//  update();
// }
//}

////metodo per gestione del movimento del mouse e la posizione del puntatore sull'immagine
//void DisplayImage_Scene_Item::mouseMoveEvent(QMouseEvent *mouseEvent)
//{
//// QGraphicsView* v = qobject_cast<QGraphicsView*>(parent());
//// v->mouseMoveEvent(mouseEvent);

// if(data_->pan_mode)
// {
//  mouseEvent->ignore();
//  return;
// }



//// return;
// //this_proxy_widget_->graphicsItem()->mouseMoveEvent(mouseEvent);

// //v->mouseM
// //this->QGraphicsProxyWidget::mouseMoveEvent(mouseEvent);

// //ogni volta che l'utente inizia un processo, attiver�  questo metodo che permetter�  a paintEvent
// //di visualizzare la posizione finale del mouse (in quel momento) e fare i calcoli necessari con esso
// //fino alla fine del processo
// if(data_->isMoving_ || data_->shapeMoving_)
// {
//  data_->mEndPoint_ = mouseEvent->pos();
//  update();
// }
// //questo metodo assega a mTempPoint un valore che poi attiver�  il metodo per la stampa di un bordo grigio
// //intorno ad un quadratino, presente in paintEvent
// if(!data_->allEdits_.isEmpty() && !data_->isMoving_ && data_->checked_ && !data_->shapeMoving_)
// {
//  for(int i=0; i < data_->allEdits_.size(); ++i)
//  {
//   for(int j=0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
//   {
//    if(mouseEvent->pos().x() >= data_->allEdits_[i].shapePoints[j].x() - data_->radius_ &&
//       mouseEvent->pos().x() <= data_->allEdits_[i].shapePoints[j].x() + data_->radius_ &&
//       mouseEvent->pos().y() >= data_->allEdits_[i].shapePoints[j].y() - data_->radius_ &&
//       mouseEvent->pos().y() <= data_->allEdits_[i].shapePoints[j].y() + data_->radius_)
//         data_->mTempPoint_ = data_->allEdits_.at(i).shapePoints.at(j);
//    update();
//   }
//  }
// }
// //questo metodo assega a mTempPoint un valore che poi attiver�  il metodo per la stampa di un bordo grigio
// //intorno ad un quadratino, presente in paintEvent, in particolare al primo punto di un polygono durante la sua costruzione
// if(data_->drawingPolygonEnabled_ && data_->points_.size() >= 3)
// {
//  if(mouseEvent->pos().x() >= data_->points_.first().x() - data_->radius_ &&
//     mouseEvent->pos().x() <= data_->points_.first().x() + data_->radius_ &&
//     mouseEvent->pos().y() >= data_->points_.first().y() - data_->radius_ &&
//     mouseEvent->pos().y() <= data_->points_.first().y() + data_->radius_)
//  {
//   data_->mTempPoint_ = data_->points_.first();
//   update();
//  }
// }
//}

////metodo per la gestione del doppio click dell'utente
//void DisplayImage_Scene_Item::mouseDoubleClickEvent(QMouseEvent *mouseEvent)
//{

// if(data_->pan_mode)
// {
//  mouseEvent->ignore();
//  return;
// }


// //questo evento serve unicamente per terminare il processo di creazione di un poligono
// //un doppio click casuale non attiver�  il codice per le condizioni necessarie
// if(mouseEvent->button() == Qt::LeftButton)
// {
//  if(data_->drawingPolygonEnabled_ && data_->points_.size() >= 3)
//  {
//   data_->isMoving_ = false;
//   DisplayImage_Data::shape another;
//   another.form = polygon;
//   another.shapePoints = data_->points_;
//   data_->allEdits_ << another;
//   onLineDraw(data_->allEdits_);
//   data_->mStartPoint_ = QPoint();
//   data_->mEndPoint_ = QPoint();
//   data_->points_.clear();
//   update();
//  }
// }
//}






