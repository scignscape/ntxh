
#include "displayimage.h"

#include <QMessageBox>

#include <QScrollBar>

#include <QGraphicsProxyWidget>

#include "mainwindow.h"


//Questa classe gestisce tutto il livello di interazione tra:
//Le annotazioni, visualizzate su un'immagine di background, e
//le azioni dell'utente che interagir�  tramite puntatore sulle annotazioni.
//Gestendo quindi le seguenti operazioni:
//Visualizzazione, continua, delle shape prodotte
//La creazione di una nuova shape
//Lo spostamento di una shape
//Lo spostamento di un punto appartenente ad una shape
//Cambiare colore alla shape selezionata
//Per quanto riguarda l'eliminazione di una shape, la sua gestione è lasciata alla classe parent.




void DisplayImage::reset_scale(r8 factor)
{
 scrolled_image_pixmap_item_->setScale(factor);
 recenter_image();
}

void DisplayImage::recenter_image()
{
 int w = scrolled_image_pixmap_item_->boundingRect().width() *
   scrolled_image_pixmap_item_->scale();
 int h = scrolled_image_pixmap_item_->boundingRect().height() *
   scrolled_image_pixmap_item_->scale();

 int new_left = background_rectangle_center_x_ - (w/2);
 int new_top = background_rectangle_center_y_ - (h/2);

 scrolled_image_pixmap_item_->setPos(new_left, new_top);
}


void DisplayImage::recenter_scroll_center()
{
 if(!image_scene_item_)
   return;

 image_scene_item_->reset_background_to_original_position();

 scrolled_image_view_->centerOn(background_rectangle_center_x_, background_rectangle_center_y_);
}

void DisplayImage::recenter_scroll_top_left()
{
 if(!image_scene_item_)
   return;

 image_scene_item_->reset_background_to_original_position();

 qreal width = scrolled_image_view_->viewport()->width();
 qreal height = scrolled_image_view_->viewport()->height();

 QPointF pos = scrolled_image_pixmap_item_->pos();
 pos += {width/2, height/2};

 scrolled_image_view_->centerOn(pos);
}


void DisplayImage::load_image(QString file_path)
{
// main_layout_->removeWidget(scrolled_image_view_);
// scrolled_image_view_ = new QGraphicsView(this);


// main_layout_->addWidget(scrolled_image_view_);

// scrolled_image_view_->setScene(scrolled_image_scene_);

//// main_layout_->update();


 scrolled_image_pixmap_ = new QPixmap(file_path);

 int sipw = scrolled_image_pixmap_->width();
 int siph = scrolled_image_pixmap_->height();


 background_rectangle_ = scrolled_image_scene_->addRect(0, 0, sipw * 2, siph * 2);

 background_rectangle_center_x_ = background_rectangle_->boundingRect().x() +
   (background_rectangle_->boundingRect().width() / 2);

 background_rectangle_center_y_ = background_rectangle_->boundingRect().y() +
   (background_rectangle_->boundingRect().height() / 2);


 display_image_data_->setView(scrolled_image_pixmap_->toImage());

 image_scene_item_ = new DisplayImage_Scene_Item;// (this);
 image_scene_item_->set_data(display_image_data_);

 image_scene_item_->resize(sipw, siph);

 image_scene_item_->setParent(nullptr);

 QGraphicsProxyWidget* w =  scrolled_image_scene_->addWidget(image_scene_item_);
 w->setPos(sipw/2,siph/2);

 QGraphicsRectItem* background_center_rectangle = scrolled_image_scene_->addRect(
   (sipw/2) - 10, (siph/2) - 10, sipw + 20, siph + 20);

 image_scene_item_->set_original_position(background_center_rectangle->pos());


 background_center_rectangle->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
 background_center_rectangle->setBrush(Qt::darkCyan);

// QGraphicsRectItem* foreground_center_rectangle_ = scrolled_image_scene_->addRect(
//   (sipw/2) - 10, (siph/2) - 10, sipw, siph);
// foreground_center_rectangle_->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
// foreground_center_rectangle_->setVisible(false);
// QBrush qbr;
// qbr.setColor(QColor::fromRgba(qRgba(200, 200, 100, 100)));
// qbr.setStyle(Qt::BrushStyle::SolidPattern);
// foreground_center_rectangle_->setBrush(qbr);

 //foreground_center_rectangle


 w->graphicsItem()->setParentItem(background_center_rectangle);

 image_scene_item_->set_this_proxy_widget(w);
 image_scene_item_->set_background_item(background_center_rectangle);


 scrolled_image_pixmap_item_ = w;

}

void DisplayImage_Scene_Item::reset_background_to_original_position()
{
 background_item_->setPos(original_position_);
}


DisplayImage::DisplayImage(QWidget* parent) : QWidget(parent)
{

 // QGraphicsView* scrolled_image_view_;
 // QGraphicsScene* scrolled_image_scene_;
 // QGraphicsPixmapItem* scrolled_image_pixmap_item_;

 display_image_data_ = new DisplayImage_Data;
 image_scene_item_ = nullptr;

  scrolled_image_view_ = new QGraphicsView(this);
  scrolled_image_scene_ = new QGraphicsScene(this);

  scrolled_image_pixmap_ = nullptr;

  background_rectangle_ = nullptr;
  scrolled_image_pixmap_item_ = nullptr;

   //?scrolled_image_label_ = new QLabel("Scrolled Image ...", this);
   //?scrolled_image_label_->setPixmap(*scrolled_image_pixmap_);

  scrolled_image_view_->setScene(scrolled_image_scene_);

   //? scrolled_image_view_->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
  scrolled_image_view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
  scrolled_image_view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);


  main_layout_ = new QVBoxLayout;
  main_layout_->addWidget(scrolled_image_view_);
  setLayout(main_layout_);

  background_rectangle_center_x_ = 0;
  background_rectangle_center_y_ = 0;

}

//Costruttore della classe
//La classe parent è la classe MainWindow
DisplayImage_Scene_Item::DisplayImage_Scene_Item(QWidget *parent) : QWidget(parent)
{

 setAutoFillBackground(true);
 setBackgroundRole(QPalette::Window);
 setAcceptDrops(true);
 setMouseTracking(true);


}

DisplayImage_Data::DisplayImage_Data()
{
 current_drawn_shape_ = nullptr;

 multi_draw = true;

 pan_mode = false;

 isMoving_ = false;
 isPressed_ = false;
 isDoublePressed_ = false;
 shapeMoving_ = false;
 checked_ = false;
 editing_ = false;
 nameSelected_ = false;
 drawingSquareEnabled_ = false;
 drawingEllipseEnabled_ = false;
 drawingPolygonEnabled_ = false;
 pointPosition_ = 0;
 shapePosition_ = -1;
 shapeID_.clear();
 defaultColorsThickness();
}

//metodo privato che assegna i valori di default
void DisplayImage_Data::defaultColorsThickness()
{
 //in decimale, la presenza di uno dei tre colori fondamentali, andr�  da un minimo di zero ad un massimo di 255
 radius_ = 6;
 thickness_ = 3;
 myRed_ = 255;
 myGreen_ = 0;
 myBlue_ = 0;
 sqRed_ = 255;
 sqGreen_ = 255;
 sqBlue_ = 255;
 shapeRed_ = 0;
 shapeGreen_ = 255;
 shapeBlue_ = 0;
}

//metodo per assegnare i valori indicati dall'utente, invocato da MainWondow
void DisplayImage_Data::setColorsThickness(int in_radius, int in_thickness, int in_myRed, int in_myGreen, int in_MyBlue,
  int in_sqRed, int in_sqGreen, int in_sqBlue, int in_shapeRed, int in_shapeGreen, int in_shapeBlue)
{
 //tutti questi valori verranno poi creati da una classe appostia: la classe Options
 radius_ = in_radius;
 thickness_ = in_thickness;
 myRed_ = in_myRed;
 myGreen_ = in_myGreen;
 myBlue_ = in_MyBlue;
 sqRed_ = in_sqRed;
 sqGreen_ = in_sqGreen;
 sqBlue_ = in_sqBlue;
 shapeRed_ = in_shapeRed;
 shapeGreen_ = in_shapeGreen;
 shapeBlue_ = in_shapeBlue;
  //? update();
}

//assegna l'immagine su cui l'utente st�  lavorando, invocato da MainWindow
void DisplayImage_Data::setView(QImage image)
{
 //image è l'immagine scelta dall'utente e che poi verr�  stampata in background
 m_background_ = image;
  //?? update();
}

//modifica il valore di verit�  di drawingSquareEnabled, invocato da MainWindow
void DisplayImage_Data::enableSquareDraw()
{
 //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
 drawingSquareEnabled_ = true;
 drawingEllipseEnabled_ = false;
 drawingPolygonEnabled_ = false;
}

//modifica il valore di verit�  di drawingEllipseEnabled, invocato da MainWindow
void DisplayImage_Data::enableEllipseDraw()
{
 //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
 drawingEllipseEnabled_ = true;
 drawingSquareEnabled_ = false;
 drawingPolygonEnabled_ = false;
}

//modifica il valore di verit�  di drawingPolygonEnabled, invocato da MainWindow
void DisplayImage_Data::enablePolygonDraw()
{
 //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
 drawingPolygonEnabled_ = true;
 drawingSquareEnabled_ = false;
 drawingEllipseEnabled_ = false;
}

//modifica il valore di verit�  di checked, invocato da MainWindow
void DisplayImage_Data::enableHighlight(bool enable){
 //il valore di enable è calcolato sulla presenza o meno della spunta nel relativo bottone nell'interfaccia grafica del programma
 checked_ = enable;
}

//modifica il valore di verit�  di nameSelected, invocato da MainWindow
void DisplayImage_Data::setNameSelected(bool enable)
{
 nameSelected_ = enable;
}

//assegna l'id della shape selezionata dall'utente, invocato da MainWindow
void DisplayImage_Data::setShapeSelected(QString in_shapeID)
{
 //quando un utente seleziona una shape, cliccando su un valore (se presente) nella terza colonna allora MainWindow
 //aggiorner�  la shapeID di DisplayImage per visualizzare (con colore diverso) la shape selezionata
 shapeID_ = in_shapeID;
 //? update();
}

//assegna l'elenco delle shape disegnate sull'immagine, invocato da MainWindow
void DisplayImage_Data::setEdits(QList<shape> inputEdits)
{
 //la natura di inputEdist può essere diversa
 //l'invocazione, però, viene fatta per permettere alla classe di lavorare sulla copia originale dei dati
 if(!inputEdits.isEmpty())
   allEdits_ = inputEdits;
 else
   allEdits_.clear();
}

//esegue il resize delle shape in base al resize applicato in quel momento sull'immagine, invocato da MainWindow
void DisplayImage_Data::resizeEdits(int resize)
{
 //invocato dopo setEdits(), permette alla classe di calcolare la nuova posizione dei punti sui valori originali che saranno sempre in scala 1:1
 if(!allEdits_.isEmpty())
 {
  for(int i=0; i < allEdits_.size(); ++i)
  {
   for(int j=0; j < allEdits_.at(i).shapePoints.size(); ++j){
    allEdits_[i].shapePoints[j].rx()/=(100.0/(190-resize*18));
    allEdits_[i].shapePoints[j].ry()/=(100.0/(190-resize*18));
   }
  }
 }
}

//rimuove tutti i dati temporanei e quelli relativi all'immagine su cui si stava lavorando, annotazioni comprese. Invocato da MainWindow
void DisplayImage_Data::clear_image()
{
 //fa quello che farebbe reset, ma in più cancella tutte le annotazioni
 //invocato esplicitamente anche per cancellare tutte le annotazioni
 if(!allEdits_.isEmpty())
   allEdits_.clear();
 reset();
}

//rimuove tutti i dati temporanei, invocato da MainWindow
void DisplayImage_Data::reset()
{
 isMoving_ = false;
 isPressed_ = false;
 isDoublePressed_ = false;
 shapeMoving_ = false;
 editing_ = false;
 points_.clear();
 mStartPoint_ = QPoint();
 mEndPoint_ = QPoint();
 mTempPoint_ = QPoint();
 pointPosition_ = 0;
 shapePosition_ = -1;
  //? update();
}

//rimuove l'ultima annotazione effettutata, invocato da MainWindow
void DisplayImage_Data::clearLastEdits()
{
 if(!allEdits_.isEmpty())
   allEdits_.removeLast();
 //? update();
}

//metodo per la stampa su schermo di tutte le annotazioni e le varie operazioni effettuate dall'utente
void DisplayImage_Scene_Item::paintEvent(QPaintEvent*)
{
 //si definiscono due tipi di pen
 QPainter painter(this);
 QPen myPen(QColor(data_->myRed_, data_->myGreen_,data_->myBlue_), data_->thickness_, Qt::SolidLine); //myPen è per tutte le shape
 QPen shapePen(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_), data_->thickness_, Qt::SolidLine); //shapePen e per la shape selezionata dall'utente
 myPen.setCapStyle(Qt::RoundCap);
 shapePen.setCapStyle(Qt::RoundCap);
 painter.setPen(shapePen);
 painter.setBrush(QBrush(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_),Qt::Dense6Pattern)); //permette a painter di creare shape traslucide
 if(!data_->m_background_.isNull())
   painter.drawImage(0, 0, data_->m_background_); //riempe lo sfonfo con l'immagine scelta dall'utente

 if(!data_->editing_)
 { //il valore di verit�  di editing viene calcolato dai metodi che gestiscono il mouse
  //viene visualizzato su schermo la costruzione della shape
  if(data_->drawingSquareEnabled_ && data_->isMoving_)
  { //il valore di verit�  di isMoving viene calcolato dai metodi che gesticono il mouse
   //viene visualizzato su schermo la costruzione della shape rettangolare
   //per essere costruita, la shape, richiede un punto di inizio ed un punto di fine, che sar�  letto come il suo opposto
   //questi due punti permettono di ricavare gli altri due che inisieme formano una shape rettangolare
   data_->points_.clear();
   data_->points_ << data_->mStartPoint_ << QPoint(data_->mStartPoint_.rx(),data_->mEndPoint_.ry())
           << data_->mEndPoint_ << QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry());

   QRect square(data_->mStartPoint_.rx(), data_->mStartPoint_.ry(),
     (data_->mEndPoint_.rx() - data_->mStartPoint_.rx()), (data_->mEndPoint_.ry()-data_->mStartPoint_.ry()));
   painter.drawRect(square);
   for(int i=0; i < data_->points_.size(); ++i)
   {
    QRect rect(data_->points_[i].rx() - data_->radius_, data_->points_[i].ry() - data_->radius_, data_->radius_*2, data_->radius_*2);
    painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));

    qDebug() << "fr: " << rect;

   }
  }
  if(data_->drawingEllipseEnabled_ && data_->isMoving_)
  {
   //viene visualizzato su schermo la costruzione della shape circolare
   //per essere costruita, la shape, richiede un punto di inizio ed un punto di fine, che sar�  letto come il suo opposto
   //questi due punti permettono di ricavare gli altri due che inisieme formano una shape rettangolare
   data_->points_.clear();
   data_->points_ << data_->mStartPoint_ << QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry())
     << data_->mEndPoint_ << QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry());
   QRect ellipse(data_->mStartPoint_.rx(), data_->mStartPoint_.ry(),
     (data_->mEndPoint_.rx() - data_->mStartPoint_.rx()), (data_->mEndPoint_.ry() - data_->mStartPoint_.ry()));
   painter.drawEllipse(ellipse);
   for(int i=0; i<data_->points_.size(); ++i)
   {
    QRect rect(data_->points_[i].rx() - data_->radius_, data_->points_[i].ry() - data_->radius_, data_->radius_*2, data_->radius_*2);
    painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
   }
  }
  if(data_->drawingPolygonEnabled_ && data_->isMoving_)
  {
   //viene visualizzato su schermo la costruzione della shape poligonale
   //i vari punti formeranno una linea spezzata e solo all'ultimo passaggio (quello di chiusira)
   //si avr�  la shape come vera superficie poligonale
   for(int i=0; i < data_->points_.size()-1; ++i)
   {
    painter.drawLine(data_->points_.at(i), data_->points_.at(i+1));
    QRect rect(data_->points_[i].rx()- data_->radius_, data_->points_[i].ry() - data_->radius_, data_->radius_ * 2, data_->radius_ * 2);
    painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
   }
   painter.drawLine(data_->points_.last(), data_->mEndPoint_);
   QRect rect1(data_->points_.last().rx()-data_->radius_, data_->points_.last().ry() - data_->radius_, data_->radius_ * 2, data_->radius_ * 2); //solo per far si che la linea non vada sopra al quadratino
   painter.fillRect(rect1, QColor(data_->sqRed_,data_->sqGreen_, data_->sqBlue_));
   QRect rect2(data_->mEndPoint_.rx() - data_->radius_, data_->mEndPoint_.ry()-data_->radius_, data_->radius_ * 2, data_->radius_ * 2);
   painter.fillRect(rect2, Qt::yellow);
  }
  if(data_->shapeMoving_)
  { //il valore di verit�  di shapeMoving viene calcolato dai metodi che gesticono il mouse
   //viene gestito lo spostamento di un'intera shape e di tutti i suo punti
   int diffx = (data_->mEndPoint_.rx() - data_->mStartPoint_.rx());
   int diffy = (data_->mEndPoint_.ry() - data_->mStartPoint_.ry());

   //versione che permette ai punti di spostarsi se si esce
   for(int i=0; i < data_->allEdits_[data_->shapePosition_].shapePoints.size();++i)
   {
    int coox = data_->allEdits_[data_->shapePosition_].shapePoints[i].rx()+diffx;
    if(coox<0)
      coox=0;
    if(coox>this->size().width())
      coox=this->size().width();

    int cooy = data_->allEdits_[data_->shapePosition_].shapePoints[i].ry()+diffy;
    if(cooy<0)
      cooy=0;
    if(cooy > this->size().height())
      cooy=this->size().height();
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(i,QPoint(coox,cooy));
   }

   //versione che impedisce ai punti di uscire ma mantiene la forma
   /*
            bool outOfBorder=false;
            for(int i=0;i<allEdits[shapePosition].shapePoints.size();++i){
                int coox=allEdits[shapePosition].shapePoints[i].rx()+diffx;
                int cooy=allEdits[shapePosition].shapePoints[i].ry()+diffy;
                if(coox<0 || coox>this->size().width() || cooy<0 || cooy>this->size().height()) outOfBorder=true;
            }
            if(!outOfBorder){
                for(int i=0;i<allEdits[shapePosition].shapePoints.size();++i){
                    int coox=allEdits[shapePosition].shapePoints[i].rx()+diffx;
                    int cooy=allEdits[shapePosition].shapePoints[i].ry()+diffy;
                    allEdits[shapePosition].shapePoints.replace(i,QPoint(coox,cooy));
                }
            }
            */
   data_->mStartPoint_ = data_->mEndPoint_;
  }
 }
 else
 {
  //qui si passa alla modifica dei singoli punti
  //nel caso si stia modificando il punto di un poligono basta sostituire il valore
  data_->allEdits_[data_->shapePosition_].shapePoints.replace(data_->pointPosition_, data_->mEndPoint_);

  if(data_->allEdits_[data_->shapePosition_].form==square || data_->allEdits_[data_->shapePosition_].form==ellipse)
  {
   //altrimenti dal punto selezionato si calcola il suo opposto e con questi due nuovi punti
   //si visualizza la costruzione della nuova shape
   if(data_->pointPosition_ == 0)
   {
    data_->mStartPoint_= data_->allEdits_[data_->shapePosition_].shapePoints.at(2);
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(1,QPoint(data_->mEndPoint_.rx(),data_->mStartPoint_.ry()));
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(3,QPoint(data_->mStartPoint_.rx(),data_->mEndPoint_.ry()));
   }
   if(data_->pointPosition_ == 1)
   {
    data_->mStartPoint_ = data_->allEdits_[data_->shapePosition_].shapePoints.at(3);
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(0, QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry()));
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(2, QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry()));
   }
   if(data_->pointPosition_ == 2)
   {
    data_->mStartPoint_ = data_->allEdits_[data_->shapePosition_].shapePoints.at(0);
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(3, QPoint(data_->mEndPoint_.rx(),data_->mStartPoint_.ry()));
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(1, QPoint(data_->mStartPoint_.rx(),data_->mEndPoint_.ry()));
   }
   if(data_->pointPosition_ == 3)
   {
    data_->mStartPoint_ = data_->allEdits_[data_->shapePosition_].shapePoints.at(1);
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(2, QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry()));
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(0, QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry()));
   }
  }
  data_->mStartPoint_ = QPoint();
  data_->mEndPoint_ = QPoint();
 }
 if(!data_->allEdits_.isEmpty())
 {
  //qui vengono visualizzate su schermo tutte le shape terminate
  for(int i = 0; i < data_->allEdits_.size(); ++i)
  {
   if(!(data_->allEdits_.at(i).id.isNull()))
   {
    //qui si controlla se c'è una shape selezionata, quella selezionata avr�  un colore diverso per distinguerla dalle altre
    if(data_->allEdits_.at(i).id == data_->shapeID_)
    {
     painter.setPen(shapePen);
     painter.setBrush(QBrush(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_), Qt::Dense6Pattern));
    }
    else
    {
     painter.setPen(myPen);
     painter.setBrush(QBrush(QColor(data_->myRed_, data_->myGreen_, data_->myBlue_), Qt::Dense6Pattern));
    }
    painter.drawText(QPoint(data_->allEdits_[i].shapePoints.first().rx()+5,
      data_->allEdits_[i].shapePoints.first().ry()-3), data_->allEdits_.at(i).id);
   }
   else
   {
    painter.setPen(shapePen);
    painter.setBrush(QBrush(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_),Qt::Dense6Pattern));
   }
   //il metodo di stampa viene deciso a seconda del valore contenuto in form (una propriet�  della shape)
   if(data_->allEdits_.at(i).form==square)
   {
    QPoint temp = data_->allEdits_.at(i).shapePoints.at(2);
    QRect square(data_->allEdits_[i].shapePoints.first().rx(),data_->allEdits_[i].shapePoints.first().ry(),
                 (temp.rx() - data_->allEdits_[i].shapePoints.first().rx()),
                 (temp.ry() - data_->allEdits_[i].shapePoints.first().ry()));
    painter.drawRect(square);
    for(int j = 0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(data_->allEdits_[i].shapePoints[j].rx() - data_->radius_,
                data_->allEdits_[i].shapePoints[j].ry()- data_->radius_ , data_->radius_ * 2, data_->radius_ * 2);
     painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
    }
   }
   if(data_->allEdits_.at(i).form==ellipse)
   {
    QPoint temp = data_->allEdits_.at(i).shapePoints.at(2);
    QRect ellipse(data_->allEdits_[i].shapePoints.first().rx(), data_->allEdits_[i].shapePoints.first().ry(),
                  (temp.rx() - data_->allEdits_[i].shapePoints.first().rx()),
                  (temp.ry() - data_->allEdits_[i].shapePoints.first().ry()));
    painter.drawEllipse(ellipse);
    for(int j=0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(data_->allEdits_[i].shapePoints[j].rx() - data_->radius_,
                data_->allEdits_[i].shapePoints[j].ry() - data_->radius_, data_->radius_ * 2,data_->radius_ * 2);
     painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
    }
   }
   if(data_->allEdits_.at(i).form==polygon)
   {
    QVector<QPoint> vect;
    for(int j = 0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     vect.append(data_->allEdits_.at(i).shapePoints.at(j));
    }
    QPolygon poly(vect);
    painter.drawPolygon(poly);
    for(int j = 0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(data_->allEdits_[i].shapePoints[j].rx() - data_->radius_,
                data_->allEdits_[i].shapePoints[j].ry() - data_->radius_,
                data_->radius_ * 2, data_->radius_ * 2);
     painter.fillRect(rect, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
    }
   }
  }
 }
 //questo codice ha il compito di stampare un contorno grigio intorno al quadratino sul quale si sofferma il mouse
 //se le condizioni lo richiedono e permettono
 if(!data_->mTempPoint_.isNull())
 {
  QRect highlightEx(data_->mTempPoint_.rx() - (data_->radius_ + 3), data_->mTempPoint_.ry()- (data_->radius_ + 3),
                    (data_->radius_ + 3) * 2, (data_->radius_ + 3) * 2);
  painter.fillRect(highlightEx, Qt::gray);
  QRect highlightIn(data_->mTempPoint_.rx() - data_->radius_, data_->mTempPoint_.ry() - data_->radius_, data_->radius_ * 2, data_->radius_ * 2);
  painter.fillRect(highlightIn, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
  data_->mTempPoint_ = QPoint();
 }
}

//metodo per la gestione del click da parte dell'utente
void DisplayImage_Scene_Item::mousePressEvent(QMouseEvent* mev)
{
// return;

 if(data_->pan_mode)
 {
  mev->ignore();
  return;
 }

 Mouse_Event_Modes mem = Mouse_Event_Modes::N_A;

 if(mev->button() == Qt::LeftButton) //  !data_->editing_ && !data_->shapeMoving_
 {
  if(data_->editing_)
    mem = Mouse_Event_Modes::Left_Edit;
  else if(data_->shapeMoving_)
    mem = Mouse_Event_Modes::Left_Move;
  else
    mem = Mouse_Event_Modes::Left_Init;
 }

 _handle_mouse_event(mev, mem);

#ifdef HIDE
 //qui viene gestito il tasto destro ed il tasto sinistro del mouse
 //con il tasto sinistro si creano le annotazioni
 if(mouseEvent->button() == Qt::LeftButton && !data_->editing_ && !data_->shapeMoving_)
 {
  //Se nameSelected falso, allora non si potranno aggiungere nuove shape
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
    if(data_->drawingSquareEnabled_)
    {
     if(data_->mStartPoint_.isNull())
     { //primo click
      data_->mStartPoint_ = mouseEvent->pos();
      data_->mEndPoint_ = mouseEvent->pos();
      data_->isMoving_ = true; //inizio
      update();
     }
     else
     { //secondo click
      data_->points_.clear();
      data_->points_ << data_->mStartPoint_ << QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry())
              << data_->mEndPoint_ << QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry());
      data_->isMoving_ = false; //fine
      DisplayImage_Data::shape another;
      another.form=square;
      another.shapePoints = data_->points_;
      data_->allEdits_ << another; //aggiunta della shape
      onLineDraw(data_->allEdits_); //signal per MainWindow
      data_->mStartPoint_ = QPoint();
      data_->mEndPoint_ = QPoint();
      data_->points_.clear();
      update();
     }
    }
    if(data_->drawingEllipseEnabled_)
    {
     if(data_->mStartPoint_.isNull())
     { //primo click
      data_->mStartPoint_ = mouseEvent->pos();
      data_->mEndPoint_ = mouseEvent->pos();
      data_->isMoving_ = true; //inizio
      update();
     }
     else
     { //secondo click
      data_->points_.clear();
      data_->points_ << data_->mStartPoint_ << QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry())
             << data_->mEndPoint_ <<QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry());
      data_->isMoving_ = false; //fine
      DisplayImage_Data::shape another;
      another.form = ellipse;
      another.shapePoints = data_->points_;
      data_->allEdits_ << another; //aggiunta della shape
      onLineDraw(data_->allEdits_); //signal per MainWindow
      data_->mStartPoint_ = QPoint();
      data_->mEndPoint_ = QPoint();
      data_->points_.clear();
      update();
     }
    }
    if(data_->drawingPolygonEnabled_)
    {
     if(data_->mStartPoint_.isNull())
     { //primo click
      data_->mStartPoint_ = mouseEvent->pos();
      data_->mEndPoint_ = mouseEvent->pos();
      data_->points_ << data_->mStartPoint_;
      data_->isMoving_ = true; //inizio
      update();
     }
     else
     {
      if(data_->points_.last()!=mouseEvent->pos())
      { //aggiunta di un punto per il poligono con click successivi
       if(!(mouseEvent->pos().x() >= data_->points_.first().x() - data_->radius_ &&
            mouseEvent->pos().x() <= data_->points_.first().x() + data_->radius_ &&
            mouseEvent->pos().y() >= data_->points_.first().y() - data_->radius_ &&
            mouseEvent->pos().y() <= data_->points_.first().y() + data_->radius_))
        data_->points_ << mouseEvent->pos();
      }
     }
     //la parte terminale viene interamente gestita dal metodo per la gestione del doppio-click
    }
   }
  }
 }
 //con il tasto destro si modificano le annotazioni
 if(mouseEvent->button() == Qt::RightButton && !data_->isMoving_)
 {
  if(!data_->allEdits_.isEmpty())
  {
   //questo controllo vuole verificare se il click è stato fatto in prossimit�  di un quadratino
   //se dovesse essere vero allora l'utente st�  spostando un punto e verr�  reso noto tramite editing
   for(int i = 0; i < data_->allEdits_.size(); ++i)
   {
    for(int j=0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     if(mouseEvent->pos().x() >= data_->allEdits_[i].shapePoints[j].x()-data_->radius_ &&
        mouseEvent->pos().x() <= data_->allEdits_[i].shapePoints[j].x()+data_->radius_ &&
        mouseEvent->pos().y() >= data_->allEdits_[i].shapePoints[j].y()-data_->radius_ &&
        mouseEvent->pos().y() <= data_->allEdits_[i].shapePoints[j].y()+data_->radius_)
     {
      data_->editing_ = true;
      data_->pointPosition_ = j;
      data_->shapePosition_ = i;
     }
    }
   }
   if(data_->editing_)
   {
    data_->shapeID_ = data_->allEdits_.at(data_->shapePosition_).id;
    setTuple(data_->shapeID_);
    data_->mEndPoint_ = mouseEvent->pos();
    data_->isMoving_ = true; //inizio
    update();
   }
   else{
    //se il click non non è in prossimit�  di un quadratino si controlla se è allinterno di una shape
    for(int i=0; i<data_->allEdits_.size(); ++i)
    {
     bool inside=false;
     for(int j=0,k=data_->allEdits_.at(i).shapePoints.size() - 1; j < data_->allEdits_.at(i).shapePoints.size(); k = j++)
     {
      //questa condizione, reperibile su internet, verifica se il mouse è all'interno di tutti i punti di un poligono
      //anche molto complesso, con molta precisione.
      //se dovesse essere vero allora l'utente st�  spostando un'intera shape e verr�  reso noto tramite shapeMoving

      //?
      if(((data_->allEdits_[i].shapePoints[j].y() >= mouseEvent->pos().y())
        != (data_->allEdits_[i].shapePoints[k].y() >= mouseEvent->pos().y())) &&
        (mouseEvent->pos().x() <= (data_->allEdits_[i].shapePoints[k].rx() - data_->allEdits_[i].shapePoints[j].rx())*
        (mouseEvent->pos().y() - data_->allEdits_[i].shapePoints[j].ry())/
        (data_->allEdits_[i].shapePoints[k].ry() - data_->allEdits_[i].shapePoints[j].ry()) + data_->allEdits_[i].shapePoints[j].rx()))
          inside = !inside;
     }
     if(inside) data_->shapePosition_=i;
    }
    if(data_->shapePosition_!=-1)
    {
     if(data_->mStartPoint_.isNull())
     {
      data_->mStartPoint_ = mouseEvent->pos();
      data_->mEndPoint_ = mouseEvent->pos();
      data_->shapeID_ = data_->allEdits_.at(data_->shapePosition_).id;
      setTuple(data_->shapeID_);
      data_->shapeMoving_ = true;
      update();
     }
    }
   }
  }
 }
#endif
}

//metodo per la gestione del rilascio del tasto premuto dall'utente
void DisplayImage_Scene_Item::mouseReleaseEvent(QMouseEvent* mev)
{
// return;

 if(data_->pan_mode)
 {
  mev->ignore();
  return;
 }

 Mouse_Event_Modes mem = Mouse_Event_Modes::N_A;

 if(mev->button() == Qt::LeftButton) //  !data_->editing_ && !data_->shapeMoving_
 {
  if(data_->isMoving_)
  {
   mem = Mouse_Event_Modes::Left_Move_Release;
  }
 }

 _handle_mouse_event(mev, mem);

 return;


 //questo controllo costinge l'utente a mantenere il tasto destro premuto
 //nel caso di rilascio all'ora l'utente ha terminato la modifica e i valori
 //vengono riportati allo stato precedente conservando eventuali modifiche
 //quindi se l'utente premesse a caso il programma non varierebbe stato
 if(mev->button() == Qt::RightButton && (data_->editing_ || data_->shapePosition_ != -1))
 {
  if(data_->editing_)
  {
   data_->isMoving_ = false;
   data_->editing_ = false; //fine
   onLineDraw(data_->allEdits_); //signal per MainWindow
   data_->pointPosition_ = 0;
   data_->shapePosition_ = -1;
  }
  if(data_->shapePosition_ != -1)
  {
   data_->mEndPoint_ = mev->pos();
   data_->shapeMoving_ = false; //fine
   onLineDraw(data_->allEdits_); //signal per MainWindow
   data_->mStartPoint_ = QPoint();
   data_->mEndPoint_ = QPoint();
   data_->shapePosition_ = -1;
  }
  update();
 }
}

//metodo per gestione del movimento del mouse e la posizione del puntatore sull'immagine
void DisplayImage_Scene_Item::mouseMoveEvent(QMouseEvent *mouseEvent)
{
// QGraphicsView* v = qobject_cast<QGraphicsView*>(parent());
// v->mouseMoveEvent(mouseEvent);

 if(data_->pan_mode)
 {
  mouseEvent->ignore();
  return;
 }



// return;
 //this_proxy_widget_->graphicsItem()->mouseMoveEvent(mouseEvent);

 //v->mouseM
 //this->QGraphicsProxyWidget::mouseMoveEvent(mouseEvent);

 //ogni volta che l'utente inizia un processo, attiver�  questo metodo che permetter�  a paintEvent
 //di visualizzare la posizione finale del mouse (in quel momento) e fare i calcoli necessari con esso
 //fino alla fine del processo
 if(data_->isMoving_ || data_->shapeMoving_)
 {
  data_->mEndPoint_ = mouseEvent->pos();
  update();
 }
 //questo metodo assega a mTempPoint un valore che poi attiver�  il metodo per la stampa di un bordo grigio
 //intorno ad un quadratino, presente in paintEvent
 if(!data_->allEdits_.isEmpty() && !data_->isMoving_ && data_->checked_ && !data_->shapeMoving_)
 {
  for(int i=0; i < data_->allEdits_.size(); ++i)
  {
   for(int j=0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
   {
    if(mouseEvent->pos().x() >= data_->allEdits_[i].shapePoints[j].x() - data_->radius_ &&
       mouseEvent->pos().x() <= data_->allEdits_[i].shapePoints[j].x() + data_->radius_ &&
       mouseEvent->pos().y() >= data_->allEdits_[i].shapePoints[j].y() - data_->radius_ &&
       mouseEvent->pos().y() <= data_->allEdits_[i].shapePoints[j].y() + data_->radius_)
         data_->mTempPoint_ = data_->allEdits_.at(i).shapePoints.at(j);
    update();
   }
  }
 }
 //questo metodo assega a mTempPoint un valore che poi attiver�  il metodo per la stampa di un bordo grigio
 //intorno ad un quadratino, presente in paintEvent, in particolare al primo punto di un polygono durante la sua costruzione
 if(data_->drawingPolygonEnabled_ && data_->points_.size() >= 3)
 {
  if(mouseEvent->pos().x() >= data_->points_.first().x() - data_->radius_ &&
     mouseEvent->pos().x() <= data_->points_.first().x() + data_->radius_ &&
     mouseEvent->pos().y() >= data_->points_.first().y() - data_->radius_ &&
     mouseEvent->pos().y() <= data_->points_.first().y() + data_->radius_)
  {
   data_->mTempPoint_ = data_->points_.first();
   update();
  }
 }
}

//metodo per la gestione del doppio click dell'utente
void DisplayImage_Scene_Item::mouseDoubleClickEvent(QMouseEvent *mouseEvent)
{

 if(data_->pan_mode)
 {
  mouseEvent->ignore();
  return;
 }


 //questo evento serve unicamente per terminare il processo di creazione di un poligono
 //un doppio click casuale non attiver�  il codice per le condizioni necessarie
 if(mouseEvent->button() == Qt::LeftButton)
 {
  if(data_->drawingPolygonEnabled_ && data_->points_.size() >= 3)
  {
   data_->isMoving_ = false;
   DisplayImage_Data::shape another;
   another.form = polygon;
   another.shapePoints = data_->points_;
   data_->allEdits_ << another;
   onLineDraw(data_->allEdits_);
   data_->mStartPoint_ = QPoint();
   data_->mEndPoint_ = QPoint();
   data_->points_.clear();
   update();
  }
 }
}






