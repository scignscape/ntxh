#include "displayimage.h"
#include <QMessageBox>

//Questa classe gestisce tutto il livello di interazione tra:
//Le annotazioni, visualizzate su un'immagine di background, e
//le azioni dell'utente che interagir√  tramite puntatore sulle annotazioni.
//Gestendo quindi le seguenti operazioni:
//Visualizzazione, continua, delle shape prodotte
//La creazione di una nuova shape
//Lo spostamento di una shape
//Lo spostamento di un punto appartenente ad una shape
//Cambiare colore alla shape selezionata
//Per quanto riguarda l'eliminazione di una shape, la sua gestione √® lasciata alla classe parent.

//Costruttore della classe
//La classe parent √® la classe MainWindow
DisplayImage::DisplayImage(QWidget *parent) : QWidget(parent)
{
 setAutoFillBackground(true);
 setBackgroundRole(QPalette::Window);
 setAcceptDrops(true);
 setMouseTracking(true);
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
void DisplayImage::defaultColorsThickness()
{
 //in decimale, la presenza di uno dei tre colori fondamentali, andr√  da un minimo di zero ad un massimo di 255
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
void DisplayImage::setColorsThickness(int in_radius, int in_thickness, int in_myRed, int in_myGreen, int in_MyBlue,
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
 update();
}

//assegna l'immagine su cui l'utente st√  lavorando, invocato da MainWindow
void DisplayImage::setView(QImage image)
{
 //image √® l'immagine scelta dall'utente e che poi verr√  stampata in background
 m_background_ = image;
 update();
}

//modifica il valore di verit√  di drawingSquareEnabled, invocato da MainWindow
void DisplayImage::enableSquareDraw()
{
 //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
 drawingSquareEnabled_ = true;
 drawingEllipseEnabled_ = false;
 drawingPolygonEnabled_ = false;
}

//modifica il valore di verit√  di drawingEllipseEnabled, invocato da MainWindow
void DisplayImage::enableEllipseDraw()
{
 //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
 drawingEllipseEnabled_ = true;
 drawingSquareEnabled_ = false;
 drawingPolygonEnabled_ = false;
}

//modifica il valore di verit√  di drawingPolygonEnabled, invocato da MainWindow
void DisplayImage::enablePolygonDraw()
{
 //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
 drawingPolygonEnabled_ = true;
 drawingSquareEnabled_ = false;
 drawingEllipseEnabled_ = false;
}

//modifica il valore di verit√  di checked, invocato da MainWindow
void DisplayImage::enableHighlight(bool enable){
 //il valore di enable √® calcolato sulla presenza o meno della spunta nel relativo bottone nell'interfaccia grafica del programma
 checked_ = enable;
}

//modifica il valore di verit√  di nameSelected, invocato da MainWindow
void DisplayImage::setNameSelected(bool enable)
{
 nameSelected_ = enable;
}

//assegna l'id della shape selezionata dall'utente, invocato da MainWindow
void DisplayImage::setShapeSelected(QString in_shapeID)
{
 //quando un utente seleziona una shape, cliccando su un valore (se presente) nella terza colonna allora MainWindow
 //aggiorner√  la shapeID di DisplayImage per visualizzare (con colore diverso) la shape selezionata
 shapeID_ = in_shapeID;
 update();
}

//assegna l'elenco delle shape disegnate sull'immagine, invocato da MainWindow
void DisplayImage::setEdits(QList<shape> inputEdits)
{
 //la natura di inputEdist pu√≤ essere diversa
 //l'invocazione, per√≤, viene fatta per permettere alla classe di lavorare sulla copia originale dei dati
 if(!inputEdits.isEmpty())
   allEdits_ = inputEdits;
 else
   allEdits_.clear();
}

//esegue il resize delle shape in base al resize applicato in quel momento sull'immagine, invocato da MainWindow
void DisplayImage::resizeEdits(int resize)
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
void DisplayImage::clear_image(){
 //fa quello che farebbe reset, ma in pi√π cancella tutte le annotazioni
 //invocato esplicitamente anche per cancellare tutte le annotazioni
 if(!allEdits_.isEmpty())
   allEdits_.clear();
 reset();
}

//rimuove tutti i dati temporanei, invocato da MainWindow
void DisplayImage::reset(){
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
 update();
}

//rimuove l'ultima annotazione effettutata, invocato da MainWindow
void DisplayImage::clearLastEdits()
{
 if(!allEdits_.isEmpty())
   allEdits_.removeLast();
 update();
}

//metodo per la stampa su schermo di tutte le annotazioni e le varie operazioni effettuate dall'utente
void DisplayImage::paintEvent(QPaintEvent*){
 //si definiscono due tipi di pen
 QPainter painter(this);
 QPen myPen(QColor(myRed_,myGreen_,myBlue_), thickness_, Qt::SolidLine); //myPen √® per tutte le shape
 QPen shapePen(QColor(shapeRed_, shapeGreen_, shapeBlue_), thickness_, Qt::SolidLine); //shapePen e per la shape selezionata dall'utente
 myPen.setCapStyle(Qt::RoundCap);
 shapePen.setCapStyle(Qt::RoundCap);
 painter.setPen(shapePen);
 painter.setBrush(QBrush(QColor(shapeRed_, shapeGreen_, shapeBlue_),Qt::Dense6Pattern)); //permette a painter di creare shape traslucide
 if(!m_background_.isNull()) painter.drawImage(0, 0, m_background_); //riempe lo sfonfo con l'immagine scelta dall'utente

 if(!editing_)
 { //il valore di verit√  di editing viene calcolato dai metodi che gestiscono il mouse
  //viene visualizzato su schermo la costruzione della shape
  if(drawingSquareEnabled_ && isMoving_)
  { //il valore di verit√  di isMoving viene calcolato dai metodi che gesticono il mouse
   //viene visualizzato su schermo la costruzione della shape rettangolare
   //per essere costruita, la shape, richiede un punto di inizio ed un punto di fine, che sar√  letto come il suo opposto
   //questi due punti permettono di ricavare gli altri due che inisieme formano una shape rettangolare
   points_.clear();
   points_ << mStartPoint_ << QPoint(mStartPoint_.rx(),mEndPoint_.ry())
           << mEndPoint_ << QPoint(mEndPoint_.rx(), mStartPoint_.ry());

   QRect square(mStartPoint_.rx(), mStartPoint_.ry(),
     (mEndPoint_.rx() - mStartPoint_.rx()), (mEndPoint_.ry()-mStartPoint_.ry()));
   painter.drawRect(square);
   for(int i=0; i < points_.size(); ++i)
   {
    QRect rect(points_[i].rx() - radius_, points_[i].ry() - radius_, radius_*2, radius_*2);
    painter.fillRect(rect, QColor(sqRed_, sqGreen_, sqBlue_));
   }
  }
  if(drawingEllipseEnabled_ && isMoving_)
  {
   //viene visualizzato su schermo la costruzione della shape circolare
   //per essere costruita, la shape, richiede un punto di inizio ed un punto di fine, che sar√  letto come il suo opposto
   //questi due punti permettono di ricavare gli altri due che inisieme formano una shape rettangolare
   points_.clear();
   points_ << mStartPoint_ << QPoint(mStartPoint_.rx(), mEndPoint_.ry())
     << mEndPoint_ << QPoint(mEndPoint_.rx(), mStartPoint_.ry());
   QRect ellipse(mStartPoint_.rx(), mStartPoint_.ry(),
     (mEndPoint_.rx() - mStartPoint_.rx()), (mEndPoint_.ry() - mStartPoint_.ry()));
   painter.drawEllipse(ellipse);
   for(int i=0; i<points_.size(); ++i)
   {
    QRect rect(points_[i].rx() - radius_, points_[i].ry() - radius_, radius_*2, radius_*2);
    painter.fillRect(rect, QColor(sqRed_, sqGreen_, sqBlue_));
   }
  }
  if(drawingPolygonEnabled_ && isMoving_)
  {
   //viene visualizzato su schermo la costruzione della shape poligonale
   //i vari punti formeranno una linea spezzata e solo all'ultimo passaggio (quello di chiusira)
   //si avr√  la shape come vera superficie poligonale
   for(int i=0; i < points_.size()-1; ++i)
   {
    painter.drawLine(points_.at(i), points_.at(i+1));
    QRect rect(points_[i].rx()- radius_, points_[i].ry() - radius_, radius_ * 2, radius_ * 2);
    painter.fillRect(rect, QColor(sqRed_, sqGreen_, sqBlue_));
   }
   painter.drawLine(points_.last(), mEndPoint_);
   QRect rect1(points_.last().rx()-radius_, points_.last().ry() - radius_, radius_ * 2, radius_ * 2); //solo per far si che la linea non vada sopra al quadratino
   painter.fillRect(rect1, QColor(sqRed_,sqGreen_, sqBlue_));
   QRect rect2(mEndPoint_.rx() - radius_, mEndPoint_.ry()-radius_, radius_ * 2, radius_ * 2);
   painter.fillRect(rect2, Qt::yellow);
  }
  if(shapeMoving_)
  { //il valore di verit√  di shapeMoving viene calcolato dai metodi che gesticono il mouse
   //viene gestito lo spostamento di un'intera shape e di tutti i suo punti
   int diffx = (mEndPoint_.rx() - mStartPoint_.rx());
   int diffy = (mEndPoint_.ry() - mStartPoint_.ry());

   //versione che permette ai punti di spostarsi se si esce
   for(int i=0; i < allEdits_[shapePosition_].shapePoints.size();++i)
   {
    int coox = allEdits_[shapePosition_].shapePoints[i].rx()+diffx;
    if(coox<0)
      coox=0;
    if(coox>this->size().width())
      coox=this->size().width();

    int cooy = allEdits_[shapePosition_].shapePoints[i].ry()+diffy;
    if(cooy<0)
      cooy=0;
    if(cooy > this->size().height())
      cooy=this->size().height();
    allEdits_[shapePosition_].shapePoints.replace(i,QPoint(coox,cooy));
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
   mStartPoint_ = mEndPoint_;
  }
 }
 else
 {
  //qui si passa alla modifica dei singoli punti
  //nel caso si stia modificando il punto di un poligono basta sostituire il valore
  allEdits_[shapePosition_].shapePoints.replace(pointPosition_, mEndPoint_);

  if(allEdits_[shapePosition_].form==square || allEdits_[shapePosition_].form==ellipse)
  {
   //altrimenti dal punto selezionato si calcola il suo opposto e con questi due nuovi punti
   //si visualizza la costruzione della nuova shape
   if(pointPosition_ == 0)
   {
    mStartPoint_= allEdits_[shapePosition_].shapePoints.at(2);
    allEdits_[shapePosition_].shapePoints.replace(1,QPoint(mEndPoint_.rx(),mStartPoint_.ry()));
    allEdits_[shapePosition_].shapePoints.replace(3,QPoint(mStartPoint_.rx(),mEndPoint_.ry()));
   }
   if(pointPosition_ == 1)
   {
    mStartPoint_ = allEdits_[shapePosition_].shapePoints.at(3);
    allEdits_[shapePosition_].shapePoints.replace(0, QPoint(mEndPoint_.rx(), mStartPoint_.ry()));
    allEdits_[shapePosition_].shapePoints.replace(2, QPoint(mStartPoint_.rx(), mEndPoint_.ry()));
   }
   if(pointPosition_ == 2)
   {
    mStartPoint_ = allEdits_[shapePosition_].shapePoints.at(0);
    allEdits_[shapePosition_].shapePoints.replace(3, QPoint(mEndPoint_.rx(),mStartPoint_.ry()));
    allEdits_[shapePosition_].shapePoints.replace(1, QPoint(mStartPoint_.rx(),mEndPoint_.ry()));
   }
   if(pointPosition_ == 3)
   {
    mStartPoint_ = allEdits_[shapePosition_].shapePoints.at(1);
    allEdits_[shapePosition_].shapePoints.replace(2, QPoint(mEndPoint_.rx(), mStartPoint_.ry()));
    allEdits_[shapePosition_].shapePoints.replace(0, QPoint(mStartPoint_.rx(), mEndPoint_.ry()));
   }
  }
  mStartPoint_ = QPoint();
  mEndPoint_ = QPoint();
 }
 if(!allEdits_.isEmpty())
 {
  //qui vengono visualizzate su schermo tutte le shape terminate
  for(int i = 0; i < allEdits_.size(); ++i)
  {
   if(!(allEdits_.at(i).id.isNull()))
   {
    //qui si controlla se c'√® una shape selezionata, quella selezionata avr√  un colore diverso per distinguerla dalle altre
    if(allEdits_.at(i).id == shapeID_)
    {
     painter.setPen(shapePen);
     painter.setBrush(QBrush(QColor(shapeRed_, shapeGreen_, shapeBlue_), Qt::Dense6Pattern));
    }
    else
    {
     painter.setPen(myPen);
     painter.setBrush(QBrush(QColor(myRed_, myGreen_, myBlue_), Qt::Dense6Pattern));
    }
    painter.drawText(QPoint(allEdits_[i].shapePoints.first().rx()+5,
      allEdits_[i].shapePoints.first().ry()-3), allEdits_.at(i).id);
   }
   else
   {
    painter.setPen(shapePen);
    painter.setBrush(QBrush(QColor(shapeRed_, shapeGreen_, shapeBlue_),Qt::Dense6Pattern));
   }
   //il metodo di stampa viene deciso a seconda del valore contenuto in form (una propriet√  della shape)
   if(allEdits_.at(i).form==square)
   {
    QPoint temp = allEdits_.at(i).shapePoints.at(2);
    QRect square(allEdits_[i].shapePoints.first().rx(),allEdits_[i].shapePoints.first().ry(),
                 (temp.rx() - allEdits_[i].shapePoints.first().rx()),
                 (temp.ry() - allEdits_[i].shapePoints.first().ry()));
    painter.drawRect(square);
    for(int j = 0; j < allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(allEdits_[i].shapePoints[j].rx() - radius_,
                allEdits_[i].shapePoints[j].ry()- radius_ , radius_ * 2, radius_ * 2);
     painter.fillRect(rect, QColor(sqRed_, sqGreen_, sqBlue_));
    }
   }
   if(allEdits_.at(i).form==ellipse)
   {
    QPoint temp = allEdits_.at(i).shapePoints.at(2);
    QRect ellipse(allEdits_[i].shapePoints.first().rx(), allEdits_[i].shapePoints.first().ry(),
                  (temp.rx() - allEdits_[i].shapePoints.first().rx()),
                  (temp.ry() - allEdits_[i].shapePoints.first().ry()));
    painter.drawEllipse(ellipse);
    for(int j=0; j < allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(allEdits_[i].shapePoints[j].rx() - radius_,
                allEdits_[i].shapePoints[j].ry() - radius_, radius_ * 2,radius_ * 2);
     painter.fillRect(rect, QColor(sqRed_, sqGreen_, sqBlue_));
    }
   }
   if(allEdits_.at(i).form==polygon)
   {
    QVector<QPoint> vect;
    for(int j = 0; j < allEdits_.at(i).shapePoints.size(); ++j)
    {
     vect.append(allEdits_.at(i).shapePoints.at(j));
    }
    QPolygon poly(vect);
    painter.drawPolygon(poly);
    for(int j = 0; j < allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(allEdits_[i].shapePoints[j].rx() - radius_,
                allEdits_[i].shapePoints[j].ry() - radius_,
                radius_ * 2, radius_ * 2);
     painter.fillRect(rect, QColor(sqRed_,sqGreen_,sqBlue_));
    }
   }
  }
 }
 //questo codice ha il compito di stampare un contorno grigio intorno al quadratino sul quale si sofferma il mouse
 //se le condizioni lo richiedono e permettono
 if(!mTempPoint_.isNull())
 {
  QRect highlightEx(mTempPoint_.rx() - (radius_ + 3), mTempPoint_.ry()- (radius_ + 3),
                    (radius_ + 3) * 2, (radius_ + 3) * 2);
  painter.fillRect(highlightEx, Qt::gray);
  QRect highlightIn(mTempPoint_.rx() - radius_, mTempPoint_.ry() - radius_, radius_ * 2, radius_ * 2);
  painter.fillRect(highlightIn, QColor(sqRed_, sqGreen_, sqBlue_));
  mTempPoint_ = QPoint();
 }
}

//metodo per la gestione del click da parte dell'utente
void DisplayImage::mousePressEvent(QMouseEvent *mouseEvent){
 //qui viene gestito il tasto destro ed il tasto sinistro del mouse
 //con il tasto sinistro si creano le annotazioni
 if(mouseEvent->button() == Qt::LeftButton && !editing_ && !shapeMoving_)
 {
  //Se nameSelected √® falso, allora non si potranno aggiungere nuove shape
  if(!drawingSquareEnabled_ && !drawingEllipseEnabled_ && !drawingPolygonEnabled_) QMessageBox::warning(this,"Warning!","Please select the shape's form");
  else
  {
   if(!nameSelected_)
    nameSelected_ = true;
   if(!nameSelected_)
    QMessageBox::warning(this,"Warning!","Please select an instance name");
   else
   {
    shapeID_.clear();
    //qui verranno gestite le condizione di inizio e di fine durante la creazione delle annotazioni
    if(drawingSquareEnabled_)
    {
     if(mStartPoint_.isNull())
     { //primo click
      mStartPoint_ = mouseEvent->pos();
      mEndPoint_ = mouseEvent->pos();
      isMoving_ = true; //inizio
      update();
     }
     else
     { //secondo click
      points_.clear();
      points_ << mStartPoint_ << QPoint(mEndPoint_.rx(), mStartPoint_.ry())
              << mEndPoint_ << QPoint(mStartPoint_.rx(), mEndPoint_.ry());
      isMoving_ = false; //fine
      shape another;
      another.form=square;
      another.shapePoints = points_;
      allEdits_ << another; //aggiunta della shape
      onLineDraw(allEdits_); //signal per MainWindow
      mStartPoint_ = QPoint();
      mEndPoint_ = QPoint();
      points_.clear();
      update();
     }
    }
    if(drawingEllipseEnabled_)
    {
     if(mStartPoint_.isNull())
     { //primo click
      mStartPoint_ = mouseEvent->pos();
      mEndPoint_ = mouseEvent->pos();
      isMoving_ = true; //inizio
      update();
     }
     else
     { //secondo click
      points_.clear();
      points_ << mStartPoint_ << QPoint(mEndPoint_.rx(), mStartPoint_.ry())
             << mEndPoint_ <<QPoint(mStartPoint_.rx(), mEndPoint_.ry());
      isMoving_ = false; //fine
      shape another;
      another.form = ellipse;
      another.shapePoints = points_;
      allEdits_ << another; //aggiunta della shape
      onLineDraw(allEdits_); //signal per MainWindow
      mStartPoint_ = QPoint();
      mEndPoint_ = QPoint();
      points_.clear();
      update();
     }
    }
    if(drawingPolygonEnabled_)
    {
     if(mStartPoint_.isNull())
     { //primo click
      mStartPoint_ = mouseEvent->pos();
      mEndPoint_ = mouseEvent->pos();
      points_ << mStartPoint_;
      isMoving_ = true; //inizio
      update();
     }
     else
     {
      if(points_.last()!=mouseEvent->pos())
      { //aggiunta di un punto per il poligono con click successivi
       if(!(mouseEvent->pos().x() >= points_.first().x() - radius_ &&
            mouseEvent->pos().x() <= points_.first().x() + radius_ &&
            mouseEvent->pos().y() >= points_.first().y() - radius_ &&
            mouseEvent->pos().y() <= points_.first().y() + radius_))
        points_ << mouseEvent->pos();
      }
     }
     //la parte terminale viene interamente gestita dal metodo per la gestione del doppio-click
    }
   }
  }
 }
 //con il tasto destro si modificano le annotazioni
 if(mouseEvent->button() == Qt::RightButton && !isMoving_)
 {
  if(!allEdits_.isEmpty())
  {
   //questo controllo vuole verificare se il click √® stato fatto in prossimit√  di un quadratino
   //se dovesse essere vero allora l'utente st√  spostando un punto e verr√  reso noto tramite editing
   for(int i = 0; i < allEdits_.size(); ++i)
   {
    for(int j=0; j < allEdits_.at(i).shapePoints.size(); ++j)
    {
     if(mouseEvent->pos().x() >= allEdits_[i].shapePoints[j].x()-radius_ &&
        mouseEvent->pos().x() <= allEdits_[i].shapePoints[j].x()+radius_ &&
        mouseEvent->pos().y() >= allEdits_[i].shapePoints[j].y()-radius_ &&
        mouseEvent->pos().y() <= allEdits_[i].shapePoints[j].y()+radius_)
     {
      editing_ = true;
      pointPosition_ = j;
      shapePosition_ = i;
     }
    }
   }
   if(editing_)
   {
    shapeID_ = allEdits_.at(shapePosition_).id;
    setTuple(shapeID_);
    mEndPoint_ = mouseEvent->pos();
    isMoving_ = true; //inizio
    update();
   }
   else{
    //se il click non non √® in prossimit√  di un quadratino si controlla se √® allinterno di una shape
    for(int i=0; i<allEdits_.size(); ++i)
    {
     bool inside=false;
     for(int j=0,k=allEdits_.at(i).shapePoints.size() - 1; j < allEdits_.at(i).shapePoints.size(); k = j++)
     {
      //questa condizione, reperibile su internet, verifica se il mouse √® all'interno di tutti i punti di un poligono
      //anche molto complesso, con molta precisione.
      //se dovesse essere vero allora l'utente st√  spostando un'intera shape e verr√  reso noto tramite shapeMoving

      //?
      if(((allEdits_[i].shapePoints[j].y() >= mouseEvent->pos().y())
        != (allEdits_[i].shapePoints[k].y() >= mouseEvent->pos().y())) &&
        (mouseEvent->pos().x() <= (allEdits_[i].shapePoints[k].rx() - allEdits_[i].shapePoints[j].rx())*
        (mouseEvent->pos().y() - allEdits_[i].shapePoints[j].ry())/
        (allEdits_[i].shapePoints[k].ry() - allEdits_[i].shapePoints[j].ry()) + allEdits_[i].shapePoints[j].rx()))
          inside = !inside;
     }
     if(inside) shapePosition_=i;
    }
    if(shapePosition_!=-1)
    {
     if(mStartPoint_.isNull())
     {
      mStartPoint_ = mouseEvent->pos();
      mEndPoint_ = mouseEvent->pos();
      shapeID_ = allEdits_.at(shapePosition_).id;
      setTuple(shapeID_);
      shapeMoving_ = true;
      update();
     }
    }
   }
  }
 }
}

//metodo per la gestione del rilascio del tasto premuto dall'utente
void DisplayImage::mouseReleaseEvent(QMouseEvent *mouseEvent){
 //questo controllo costinge l'utente a mantenere il tasto destro premuto
 //nel caso di rilascio all'ora l'utente ha terminato la modifica e i valori
 //vengono riportati allo stato precedente conservando eventuali modifiche
 //quindi se l'utente premesse a caso il programma non varierebbe stato
 if(mouseEvent->button() == Qt::RightButton && (editing_ || shapePosition_ != -1))
 {
  if(editing_)
  {
   isMoving_ = false;
   editing_ = false; //fine
   onLineDraw(allEdits_); //signal per MainWindow
   pointPosition_ = 0;
   shapePosition_ = -1;
  }
  if(shapePosition_ != -1)
  {
   mEndPoint_ = mouseEvent->pos();
   shapeMoving_ = false; //fine
   onLineDraw(allEdits_); //signal per MainWindow
   mStartPoint_ = QPoint();
   mEndPoint_ = QPoint();
   shapePosition_ = -1;
  }
  update();
 }
}

//metodo per gestione del movimento del mouse e la posizione del puntatore sull'immagine
void DisplayImage::mouseMoveEvent(QMouseEvent *mouseEvent)
{
 //ogni volta che l'utente inizia un processo, attiver√  questo metodo che permetter√  a paintEvent
 //di visualizzare la posizione finale del mouse (in quel momento) e fare i calcoli necessari con esso
 //fino alla fine del processo
 if(isMoving_ || shapeMoving_)
 {
  mEndPoint_ = mouseEvent->pos();
  update();
 }
 //questo metodo assega a mTempPoint un valore che poi attiver√  il metodo per la stampa di un bordo grigio
 //intorno ad un quadratino, presente in paintEvent
 if(!allEdits_.isEmpty() && !isMoving_ && checked_ && !shapeMoving_)
 {
  for(int i=0; i < allEdits_.size(); ++i)
  {
   for(int j=0; j < allEdits_.at(i).shapePoints.size(); ++j)
   {
    if(mouseEvent->pos().x() >= allEdits_[i].shapePoints[j].x() - radius_ &&
       mouseEvent->pos().x() <= allEdits_[i].shapePoints[j].x() + radius_ &&
       mouseEvent->pos().y() >= allEdits_[i].shapePoints[j].y() - radius_ &&
       mouseEvent->pos().y() <= allEdits_[i].shapePoints[j].y() + radius_)
         mTempPoint_ = allEdits_.at(i).shapePoints.at(j);
    update();
   }
  }
 }
 //questo metodo assega a mTempPoint un valore che poi attiver√  il metodo per la stampa di un bordo grigio
 //intorno ad un quadratino, presente in paintEvent, in particolare al primo punto di un polygono durante la sua costruzione
 if(drawingPolygonEnabled_ && points_.size() >= 3)
 {
  if(mouseEvent->pos().x() >= points_.first().x() - radius_ &&
     mouseEvent->pos().x() <= points_.first().x() + radius_ &&
     mouseEvent->pos().y() >= points_.first().y() - radius_ &&
     mouseEvent->pos().y() <= points_.first().y() + radius_)
  {
   mTempPoint_ = points_.first();
   update();
  }
 }
}

//metodo per la gestione del doppio click dell'utente
void DisplayImage::mouseDoubleClickEvent(QMouseEvent *mouseEvent){
 //questo evento serve unicamente per terminare il processo di creazione di un poligono
 //un doppio click casuale non attiver√  il codice per le condizioni necessarie
 if(mouseEvent->button() == Qt::LeftButton)
 {
  if(drawingPolygonEnabled_ && points_.size() >= 3)
  {
   isMoving_ = false;
   shape another;
   another.form = polygon;
   another.shapePoints = points_;
   allEdits_ << another;
   onLineDraw(allEdits_);
   mStartPoint_ = QPoint();
   mEndPoint_ = QPoint();
   points_.clear();
   update();
  }
 }
}






