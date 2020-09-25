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
DisplayImage::DisplayImage(QWidget *parent) : QWidget(parent){
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Window);
    setAcceptDrops(true);
    setMouseTracking(true);
    isMoving=false;
    isPressed=false;
    isDoublePressed=false;
    shapeMoving=false;
    checked=false;
    editing=false;
    nameSelected=false;
    drawingSquareEnabled=false;
    drawingEllipseEnabled=false;
    drawingPolygonEnabled=false;
    pointPosition=0;
    shapePosition=-1;
    shapeID.clear();
    defaultColorsThickness();
}

//metodo privato che assegna i valori di default
void DisplayImage::defaultColorsThickness(){
    //in decimale, la presenza di uno dei tre colori fondamentali, andr√  da un minimo di zero ad un massimo di 255
    radius=6;
    thickness=3;
    myRed=255;
    myGreen=0;
    myBlue=0;
    sqRed=255;
    sqGreen=255;
    sqBlue=255;
    shapeRed=0;
    shapeGreen=255;
    shapeBlue=0;
}

//metodo per assegnare i valori indicati dall'utente, invocato da MainWondow
void DisplayImage::setColorsThickness(int in_radius, int in_thickness, int in_myRed, int in_myGreen, int in_MyBlue, int in_sqRed, int in_sqGreen, int in_sqBlue, int in_shapeRed, int in_shapeGreen, int in_shapeBlue){
    //tutti questi valori verranno poi creati da una classe appostia: la classe Options
    radius=in_radius;
    thickness=in_thickness;
    myRed=in_myRed;
    myGreen=in_myGreen;
    myBlue=in_MyBlue;
    sqRed=in_sqRed;
    sqGreen=in_sqGreen;
    sqBlue=in_sqBlue;
    shapeRed=in_shapeRed;
    shapeGreen=in_shapeGreen;
    shapeBlue=in_shapeBlue;
    update();
}

//assegna l'immagine su cui l'utente st√  lavorando, invocato da MainWindow
void DisplayImage::setView(QImage image){
    //image √® l'immagine scelta dall'utente e che poi verr√  stampata in background
    m_background=image;
    update();
}

//modifica il valore di verit√  di drawingSquareEnabled, invocato da MainWindow
void DisplayImage::enableSquareDraw(){
    //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
    drawingSquareEnabled=true;
    drawingEllipseEnabled=false;
    drawingPolygonEnabled=false;
}

//modifica il valore di verit√  di drawingEllipseEnabled, invocato da MainWindow
void DisplayImage::enableEllipseDraw(){
    //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
    drawingEllipseEnabled=true;
    drawingSquareEnabled=false;
    drawingPolygonEnabled=false;
}

//modifica il valore di verit√  di drawingPolygonEnabled, invocato da MainWindow
void DisplayImage::enablePolygonDraw(){
    //se l'utente sceglie un tipo di forma, automaticamente gli altri tipi verranno disattivati
    drawingPolygonEnabled=true;
    drawingSquareEnabled=false;
    drawingEllipseEnabled=false;
}

//modifica il valore di verit√  di checked, invocato da MainWindow
void DisplayImage::enableHighlight(bool enable){
    //il valore di enable √® calcolato sulla presenza o meno della spunta nel relativo bottone nell'interfaccia grafica del programma
    checked=enable;
}

//modifica il valore di verit√  di nameSelected, invocato da MainWindow
void DisplayImage::setNameSelected(bool enable){
    nameSelected=enable;
}

//assegna l'id della shape selezionata dall'utente, invocato da MainWindow
void DisplayImage::setShapeSelected(QString in_shapeID){
    //quando un utente seleziona una shape, cliccando su un valore (se presente) nella terza colonna allora MainWindow
    //aggiorner√  la shapeID di DisplayImage per visualizzare (con colore diverso) la shape selezionata
    shapeID=in_shapeID;
    update();
}

//assegna l'elenco delle shape disegnate sull'immagine, invocato da MainWindow
void DisplayImage::setEdits(QList<shape> inputEdits){
    //la natura di inputEdist pu√≤ essere diversa
    //l'invocazione, per√≤, viene fatta per permettere alla classe di lavorare sulla copia originale dei dati
    if(!inputEdits.isEmpty()) allEdits=inputEdits;
    else allEdits.clear();
}

//esegue il resize delle shape in base al resize applicato in quel momento sull'immagine, invocato da MainWindow
void DisplayImage::resizeEdits(int resize){
    //invocato dopo setEdits(), permette alla classe di calcolare la nuova posizione dei punti sui valori originali che saranno sempre in scala 1:1
    if(!allEdits.isEmpty()){
        for(int i=0; i<allEdits.size(); ++i){
            for(int j=0; j<allEdits.at(i).shapePoints.size(); ++j){
                allEdits[i].shapePoints[j].rx()/=(100.0/(190-resize*18));
                allEdits[i].shapePoints[j].ry()/=(100.0/(190-resize*18));
            }
        }
    }
}

//rimuove tutti i dati temporanei e quelli relativi all'immagine su cui si stava lavorando, annotazioni comprese. Invocato da MainWindow
void DisplayImage::clear_image(){
    //fa quello che farebbe reset, ma in pi√π cancella tutte le annotazioni
    //invocato esplicitamente anche per cancellare tutte le annotazioni
    if(!allEdits.isEmpty()) allEdits.clear();
    reset();
}

//rimuove tutti i dati temporanei, invocato da MainWindow
void DisplayImage::reset(){
    isMoving=false;
    isPressed=false;
    isDoublePressed=false;
    shapeMoving=false;
    editing=false;
    points.clear();
    mStartPoint=QPoint();
    mEndPoint=QPoint();
    mTempPoint=QPoint();
    pointPosition=0;
    shapePosition=-1;
    update();
}

//rimuove l'ultima annotazione effettutata, invocato da MainWindow
void DisplayImage::clearLastEdits(){
    if(!allEdits.isEmpty()) allEdits.removeLast();
    update();
}

//metodo per la stampa su schermo di tutte le annotazioni e le varie operazioni effettuate dall'utente
void DisplayImage::paintEvent(QPaintEvent*){
    //si definiscono due tipi di pen
    QPainter painter(this);
    QPen myPen(QColor(myRed,myGreen,myBlue), thickness, Qt::SolidLine); //myPen √® per tutte le shape
    QPen shapePen(QColor(shapeRed,shapeGreen,shapeBlue), thickness, Qt::SolidLine); //shapePen e per la shape selezionata dall'utente
    myPen.setCapStyle(Qt::RoundCap);
    shapePen.setCapStyle(Qt::RoundCap);
    painter.setPen(shapePen);
    painter.setBrush(QBrush(QColor(shapeRed,shapeGreen,shapeBlue),Qt::Dense6Pattern)); //permette a painter di creare shape traslucide
    if(!m_background.isNull()) painter.drawImage(0,0,m_background); //riempe lo sfonfo con l'immagine scelta dall'utente

    if(!editing){ //il valore di verit√  di editing viene calcolato dai metodi che gestiscono il mouse
        //viene visualizzato su schermo la costruzione della shape
        if(drawingSquareEnabled&&isMoving){ //il valore di verit√  di isMoving viene calcolato dai metodi che gesticono il mouse
            //viene visualizzato su schermo la costruzione della shape rettangolare
            //per essere costruita, la shape, richiede un punto di inizio ed un punto di fine, che sar√  letto come il suo opposto
            //questi due punti permettono di ricavare gli altri due che inisieme formano una shape rettangolare
            points.clear();
            points<<mStartPoint<<QPoint(mStartPoint.rx(),mEndPoint.ry())<<mEndPoint<<QPoint(mEndPoint.rx(),mStartPoint.ry());
            QRect square(mStartPoint.rx(),mStartPoint.ry(),(mEndPoint.rx()-mStartPoint.rx()),(mEndPoint.ry()-mStartPoint.ry()));
            painter.drawRect(square);
            for(int i=0; i<points.size(); ++i){
                QRect rect(points[i].rx()-radius,points[i].ry()-radius,radius*2,radius*2);
                painter.fillRect(rect, QColor(sqRed,sqGreen,sqBlue));
            }
        }
        if(drawingEllipseEnabled&&isMoving){
            //viene visualizzato su schermo la costruzione della shape circolare
            //per essere costruita, la shape, richiede un punto di inizio ed un punto di fine, che sar√  letto come il suo opposto
            //questi due punti permettono di ricavare gli altri due che inisieme formano una shape rettangolare
            points.clear();
            points<<mStartPoint<<QPoint(mStartPoint.rx(),mEndPoint.ry())<<mEndPoint<<QPoint(mEndPoint.rx(),mStartPoint.ry());
            QRect ellipse(mStartPoint.rx(),mStartPoint.ry(),(mEndPoint.rx()-mStartPoint.rx()),(mEndPoint.ry()-mStartPoint.ry()));
            painter.drawEllipse(ellipse);
            for(int i=0; i<points.size(); ++i){
                QRect rect(points[i].rx()-radius,points[i].ry()-radius,radius*2,radius*2);
                painter.fillRect(rect, QColor(sqRed,sqGreen,sqBlue));
            }
        }
        if(drawingPolygonEnabled&&isMoving){
            //viene visualizzato su schermo la costruzione della shape poligonale
            //i vari punti formeranno una linea spezzata e solo all'ultimo passaggio (quello di chiusira)
            //si avr√  la shape come vera superficie poligonale
            for(int i=0; i<points.size()-1; ++i){
                painter.drawLine(points.at(i), points.at(i+1));
                QRect rect(points[i].rx()-radius,points[i].ry()-radius,radius*2,radius*2);
                painter.fillRect(rect, QColor(sqRed,sqGreen,sqBlue));
            }
            painter.drawLine(points.last(), mEndPoint);
            QRect rect1(points.last().rx()-radius,points.last().ry()-radius,radius*2,radius*2); //solo per far si che la linea non vada sopra al quadratino
            painter.fillRect(rect1, QColor(sqRed,sqGreen,sqBlue));
            QRect rect2(mEndPoint.rx()-radius,mEndPoint.ry()-radius,radius*2,radius*2);
            painter.fillRect(rect2, Qt::yellow);
        }
        if(shapeMoving){ //il valore di verit√  di shapeMoving viene calcolato dai metodi che gesticono il mouse
            //viene gestito lo spostamento di un'intera shape e di tutti i suo punti
            int diffx = (mEndPoint.rx()-mStartPoint.rx());
            int diffy = (mEndPoint.ry()-mStartPoint.ry());

            //versione che permette ai punti di spostarsi se si esce
            for(int i=0;i<allEdits[shapePosition].shapePoints.size();++i){
                int coox=allEdits[shapePosition].shapePoints[i].rx()+diffx;
                if(coox<0) coox=0;
                if(coox>this->size().width()) coox=this->size().width();
                int cooy=allEdits[shapePosition].shapePoints[i].ry()+diffy;
                if(cooy<0) cooy=0;
                if(cooy>this->size().height()) cooy=this->size().height();
                allEdits[shapePosition].shapePoints.replace(i,QPoint(coox,cooy));
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
            mStartPoint=mEndPoint;
        }
    }
    else{
        //qui si passa alla modifica dei singoli punti
        //nel caso si stia modificando il punto di un poligono basta sostituire il valore
        allEdits[shapePosition].shapePoints.replace(pointPosition,mEndPoint);
        if(allEdits[shapePosition].form==square || allEdits[shapePosition].form==ellipse){
            //altrimenti dal punto selezionato si calcola il suo opposto e con questi due nuovi punti
            //si visualizza la costruzione della nuova shape
            if(pointPosition==0){
                mStartPoint=allEdits[shapePosition].shapePoints.at(2);
                allEdits[shapePosition].shapePoints.replace(1,QPoint(mEndPoint.rx(),mStartPoint.ry()));
                allEdits[shapePosition].shapePoints.replace(3,QPoint(mStartPoint.rx(),mEndPoint.ry()));
            }
            if(pointPosition==1){
                mStartPoint=allEdits[shapePosition].shapePoints.at(3);
                allEdits[shapePosition].shapePoints.replace(0,QPoint(mEndPoint.rx(),mStartPoint.ry()));
                allEdits[shapePosition].shapePoints.replace(2,QPoint(mStartPoint.rx(),mEndPoint.ry()));
            }
            if(pointPosition==2){
                mStartPoint=allEdits[shapePosition].shapePoints.at(0);
                allEdits[shapePosition].shapePoints.replace(3,QPoint(mEndPoint.rx(),mStartPoint.ry()));
                allEdits[shapePosition].shapePoints.replace(1,QPoint(mStartPoint.rx(),mEndPoint.ry()));
            }
            if(pointPosition==3){
                mStartPoint=allEdits[shapePosition].shapePoints.at(1);
                allEdits[shapePosition].shapePoints.replace(2,QPoint(mEndPoint.rx(),mStartPoint.ry()));
                allEdits[shapePosition].shapePoints.replace(0,QPoint(mStartPoint.rx(),mEndPoint.ry()));
            }
        }
        mStartPoint=QPoint();
        mEndPoint=QPoint();
    }
    if(!allEdits.isEmpty()){
        //qui vengono visualizzate su schermo tutte le shape terminate
        for(int i=0; i<allEdits.size(); ++i){
            if(!(allEdits.at(i).id.isNull())){
                //qui si controlla se c'√® una shape selezionata, quella selezionata avr√  un colore diverso per distinguerla dalle altre
                if(allEdits.at(i).id==shapeID){
                    painter.setPen(shapePen);
                    painter.setBrush(QBrush(QColor(shapeRed,shapeGreen,shapeBlue),Qt::Dense6Pattern));
                }
                else{
                    painter.setPen(myPen);
                    painter.setBrush(QBrush(QColor(myRed,myGreen,myBlue),Qt::Dense6Pattern));
                }
                painter.drawText(QPoint(allEdits[i].shapePoints.first().rx()+5,allEdits[i].shapePoints.first().ry()-3),allEdits.at(i).id);
            }
            else{
                painter.setPen(shapePen);
                painter.setBrush(QBrush(QColor(shapeRed,shapeGreen,shapeBlue),Qt::Dense6Pattern));
            }
            //il metodo di stampa viene deciso a seconda del valore contenuto in form (una propriet√  della shape)
            if(allEdits.at(i).form==square){
                QPoint temp=allEdits.at(i).shapePoints.at(2);
                QRect square(allEdits[i].shapePoints.first().rx(),allEdits[i].shapePoints.first().ry(),(temp.rx()-allEdits[i].shapePoints.first().rx()),(temp.ry()-allEdits[i].shapePoints.first().ry()));
                painter.drawRect(square);
                for(int j=0; j<allEdits.at(i).shapePoints.size(); ++j){
                    QRect rect(allEdits[i].shapePoints[j].rx()-radius,allEdits[i].shapePoints[j].ry()-radius,radius*2,radius*2);
                    painter.fillRect(rect, QColor(sqRed,sqGreen,sqBlue));
                }
            }
            if(allEdits.at(i).form==ellipse){
                QPoint temp=allEdits.at(i).shapePoints.at(2);
                QRect ellipse(allEdits[i].shapePoints.first().rx(),allEdits[i].shapePoints.first().ry(),(temp.rx()-allEdits[i].shapePoints.first().rx()),(temp.ry()-allEdits[i].shapePoints.first().ry()));
                painter.drawEllipse(ellipse);
                for(int j=0; j<allEdits.at(i).shapePoints.size(); ++j){
                    QRect rect(allEdits[i].shapePoints[j].rx()-radius,allEdits[i].shapePoints[j].ry()-radius,radius*2,radius*2);
                    painter.fillRect(rect, QColor(sqRed,sqGreen,sqBlue));
                }
            }
            if(allEdits.at(i).form==polygon){
                QVector<QPoint> vect;
                for(int j=0; j<allEdits.at(i).shapePoints.size(); ++j){
                    vect.append(allEdits.at(i).shapePoints.at(j));
                }
                QPolygon poly(vect);
                painter.drawPolygon(poly);
                for(int j=0; j<allEdits.at(i).shapePoints.size(); ++j){
                    QRect rect(allEdits[i].shapePoints[j].rx()-radius,allEdits[i].shapePoints[j].ry()-radius,radius*2,radius*2);
                    painter.fillRect(rect, QColor(sqRed,sqGreen,sqBlue));
                }
            }
        }
    }
    //questo codice ha il compito di stampare un contorno grigio intorno al quadratino sul quale si sofferma il mouse
    //se le condizioni lo richiedono e permettono
    if(!mTempPoint.isNull()){
        QRect highlightEx(mTempPoint.rx()-(radius+3),mTempPoint.ry()-(radius+3),(radius+3)*2,(radius+3)*2);
        painter.fillRect(highlightEx, Qt::gray);
        QRect highlightIn(mTempPoint.rx()-radius,mTempPoint.ry()-radius,radius*2,radius*2);
        painter.fillRect(highlightIn, QColor(sqRed,sqGreen,sqBlue));
        mTempPoint=QPoint();
    }
}

//metodo per la gestione del click da parte dell'utente
void DisplayImage::mousePressEvent(QMouseEvent *mouseEvent){
    //qui viene gestito il tasto destro ed il tasto sinistro del mouse
    //con il tasto sinistro si creano le annotazioni
    if(mouseEvent->button() == Qt::LeftButton && !editing && !shapeMoving){
        //Se nameSelected √® falso, allora non si potranno aggiungere nuove shape
        if(!drawingSquareEnabled && !drawingEllipseEnabled && !drawingPolygonEnabled) QMessageBox::warning(this,"Warning!","Please select the shape's form");
        else{
            if(!nameSelected) QMessageBox::warning(this,"Warning!","Please select an instance name");
            else{
                shapeID.clear();
                //qui verranno gestite le condizione di inizio e di fine durante la creazione delle annotazioni
                if(drawingSquareEnabled){
                    if(mStartPoint.isNull()){ //primo click
                        mStartPoint = mouseEvent->pos();
                        mEndPoint = mouseEvent->pos();
                        isMoving=true; //inizio
                        update();
                    }
                    else{ //secondo click
                        points.clear();
                        points<<mStartPoint<<QPoint(mEndPoint.rx(),mStartPoint.ry())<<mEndPoint<<QPoint(mStartPoint.rx(),mEndPoint.ry());
                        isMoving=false; //fine
                        shape another;
                        another.form=square;
                        another.shapePoints=points;
                        allEdits<<another; //aggiunta della shape
                        onLineDraw(allEdits); //signal per MainWindow
                        mStartPoint=QPoint();
                        mEndPoint=QPoint();
                        points.clear();
                        update();
                    }
                }
                if(drawingEllipseEnabled){
                    if(mStartPoint.isNull()){ //primo click
                        mStartPoint = mouseEvent->pos();
                        mEndPoint = mouseEvent->pos();
                        isMoving=true; //inizio
                        update();
                    }
                    else{ //secondo click
                        points.clear();
                        points<<mStartPoint<<QPoint(mEndPoint.rx(),mStartPoint.ry())<<mEndPoint<<QPoint(mStartPoint.rx(),mEndPoint.ry());
                        isMoving=false; //fine
                        shape another;
                        another.form=ellipse;
                        another.shapePoints=points;
                        allEdits<<another; //aggiunta della shape
                        onLineDraw(allEdits); //signal per MainWindow
                        mStartPoint=QPoint();
                        mEndPoint=QPoint();
                        points.clear();
                        update();
                    }
                }
                if(drawingPolygonEnabled){
                    if(mStartPoint.isNull()){ //primo click
                        mStartPoint=mouseEvent->pos();
                        mEndPoint=mouseEvent->pos();
                        points<<mStartPoint;
                        isMoving=true; //inizio
                        update();
                    }
                    else{
                        if(points.last()!=mouseEvent->pos()){ //aggiunta di un punto per il poligono con click successivi
                            if(!(mouseEvent->pos().x()>=points.first().x()-radius &&
                                 mouseEvent->pos().x()<=points.first().x()+radius &&
                                 mouseEvent->pos().y()>=points.first().y()-radius &&
                                 mouseEvent->pos().y()<=points.first().y()+radius)) points<<mouseEvent->pos();
                        }
                    }
                    //la parte terminale viene interamente gestita dal metodo per la gestione del doppio-click
                }
            }
        }
    }
    //con il tasto destro si modificano le annotazioni
    if(mouseEvent->button() == Qt::RightButton && !isMoving){
        if(!allEdits.isEmpty()){
            //questo controllo vuole verificare se il click √® stato fatto in prossimit√  di un quadratino
            //se dovesse essere vero allora l'utente st√  spostando un punto e verr√  reso noto tramite editing
            for(int i=0; i<allEdits.size(); ++i){
                for(int j=0; j<allEdits.at(i).shapePoints.size(); ++j){
                    if(mouseEvent->pos().x()>=allEdits[i].shapePoints[j].x()-radius &&
                        mouseEvent->pos().x()<=allEdits[i].shapePoints[j].x()+radius &&
                        mouseEvent->pos().y()>=allEdits[i].shapePoints[j].y()-radius &&
                        mouseEvent->pos().y()<=allEdits[i].shapePoints[j].y()+radius){
                        editing=true;
                        pointPosition=j;
                        shapePosition=i;
                    }
                }
            }
            if(editing){
                shapeID=allEdits.at(shapePosition).id;
                setTuple(shapeID);
                mEndPoint=mouseEvent->pos();
                isMoving=true; //inizio
                update();
            }
            else{
                //se il click non non √® in prossimit√  di un quadratino si controlla se √® allinterno di una shape
                for(int i=0; i<allEdits.size(); ++i){
                    bool inside=false;
                    for(int j=0,k=allEdits.at(i).shapePoints.size()-1; j<allEdits.at(i).shapePoints.size(); k=j++){
                        //questa condizione, reperibile su internet, verifica se il mouse √® all'interno di tutti i punti di un poligono
                        //anche molto complesso, con molta precisione.
                        //se dovesse essere vero allora l'utente st√  spostando un'intera shape e verr√  reso noto tramite shapeMoving
                        if(((allEdits[i].shapePoints[j].y()>=mouseEvent->pos().y())!=(allEdits[i].shapePoints[k].y()>=mouseEvent->pos().y()))&&
                            (mouseEvent->pos().x()<=(allEdits[i].shapePoints[k].rx() - allEdits[i].shapePoints[j].rx())*
                            (mouseEvent->pos().y()-allEdits[i].shapePoints[j].ry())/
                            (allEdits[i].shapePoints[k].ry()-allEdits[i].shapePoints[j].ry())+allEdits[i].shapePoints[j].rx())) inside = !inside;
                    }
                    if(inside) shapePosition=i;
                }
                if(shapePosition!=-1){
                    if(mStartPoint.isNull()){
                        mStartPoint=mouseEvent->pos();
                        mEndPoint=mouseEvent->pos();
                        shapeID=allEdits.at(shapePosition).id;
                        setTuple(shapeID);
                        shapeMoving=true;
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
    if(mouseEvent->button() == Qt::RightButton && (editing||shapePosition!=-1)){
        if(editing){
            isMoving=false;
            editing=false; //fine
            onLineDraw(allEdits); //signal per MainWindow
            pointPosition=0;
            shapePosition=-1;
        }
        if(shapePosition!=-1){
            mEndPoint=mouseEvent->pos();
            shapeMoving=false; //fine
            onLineDraw(allEdits); //signal per MainWindow
            mStartPoint=QPoint();
            mEndPoint=QPoint();
            shapePosition=-1;
        }
        update();
    }
}

//metodo per gestione del movimento del mouse e la posizione del puntatore sull'immagine
void DisplayImage::mouseMoveEvent(QMouseEvent *mouseEvent){
    //ogni volta che l'utente inizia un processo, attiver√  questo metodo che permetter√  a paintEvent
    //di visualizzare la posizione finale del mouse (in quel momento) e fare i calcoli necessari con esso
    //fino alla fine del processo
    if(isMoving||shapeMoving){
        mEndPoint = mouseEvent->pos();
        update();
    }
    //questo metodo assega a mTempPoint un valore che poi attiver√  il metodo per la stampa di un bordo grigio
    //intorno ad un quadratino, presente in paintEvent
    if(!allEdits.isEmpty() && !isMoving && checked && !shapeMoving){
        for(int i=0; i<allEdits.size(); ++i){
            for(int j=0; j<allEdits.at(i).shapePoints.size(); ++j){
                if(mouseEvent->pos().x()>=allEdits[i].shapePoints[j].x()-radius &&
                   mouseEvent->pos().x()<=allEdits[i].shapePoints[j].x()+radius &&
                   mouseEvent->pos().y()>=allEdits[i].shapePoints[j].y()-radius &&
                   mouseEvent->pos().y()<=allEdits[i].shapePoints[j].y()+radius) mTempPoint=allEdits.at(i).shapePoints.at(j);
                update();
            }
        }
    }
    //questo metodo assega a mTempPoint un valore che poi attiver√  il metodo per la stampa di un bordo grigio
    //intorno ad un quadratino, presente in paintEvent, in particolare al primo punto di un polygono durante la sua costruzione
    if(drawingPolygonEnabled&&points.size()>=3){
        if(mouseEvent->pos().x()>=points.first().x()-radius &&
           mouseEvent->pos().x()<=points.first().x()+radius &&
           mouseEvent->pos().y()>=points.first().y()-radius &&
           mouseEvent->pos().y()<=points.first().y()+radius)
        {
            mTempPoint=points.first();
            update();
        }
    }
}

//metodo per la gestione del doppio click dell'utente
void DisplayImage::mouseDoubleClickEvent(QMouseEvent *mouseEvent){
    //questo evento serve unicamente per terminare il processo di creazione di un poligono
    //un doppio click casuale non attiver√  il codice per le condizioni necessarie
    if(mouseEvent->button() == Qt::LeftButton){
        if(drawingPolygonEnabled&&points.size()>=3){
            isMoving=false;
            shape another;
            another.form=polygon;
            another.shapePoints=points;
            allEdits<<another;
            onLineDraw(allEdits);
            mStartPoint=QPoint();
            mEndPoint=QPoint();
            points.clear();
            update();
        }
    }
}






