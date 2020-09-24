#ifndef DISPLAYIMAGE_H
#define DISPLAYIMAGE_H

#include <QWidget>
#include <QtGui>

class DisplayImage : public QWidget{
    Q_OBJECT

private:
    bool isMoving; //se vero, il programma sta catturando la posizione del mouse sull'immagine
    bool isPressed; //se vero, il programma è entrato nella fase di disegno di una shape
    bool isDoublePressed; //se vero, il programma riconosce che l'utente ha terminato di disegnare un poligono
    bool shapeMoving; //se vero, il programma riconosce che l'utente sta spostando una shape
    bool checked; //se vero, l'utente ha attivo la funzione highlight
    bool editing; //se vero, il programma riconosce che l'utente sta modificando le coordinate di un punto di una shape
    bool nameSelected; //se vero, l'utente ha selezionato un valore nella colonna Object ed un valore nella colonna Instance
    bool drawingSquareEnabled; //se vero, la prossima shape sarà quadrata/rettangolare
    bool drawingEllipseEnabled; //se vero, la prossima shape sarà circolare
    bool drawingPolygonEnabled; //se vero, la prossima shape sarà un poligono
    int pointPosition; //indica la posizione nel vettore del punto di quella shape che l'utente sta modificando
    int shapePosition; //indica la posizione nel vettore della shape che l'utente sta modificando/spostando
    int radius; //dimensione dei quadrati corrispondenti ai punti da cui, insieme alle linee, è formata la shape
    int thickness; //spessore delle linee da cui, insieme ai punti, è formata la shape
    int myRed; //valore del colore rosso delle shape non selezionate
    int myGreen; //valore del colore verde delle shape non selezionate
    int myBlue; //valore del colore blu delle shape non selezionate
    int sqRed; //valore del colore rosso dei quadratini
    int sqGreen; //valore del colore verde dei quadratini
    int sqBlue; //valore del colore blu dei quadratini
    int shapeRed; //valore del colore rosso della shape selezionata
    int shapeGreen; //valore del colore verde della shape selezionata
    int shapeBlue; //valore del colore blu della shape selezionata
    QImage m_background; //copia dell'immagine su cui si faranno le annotazioni
    QPoint mStartPoint; //coordinate iniziali del punto per il disegno di una shape e per modifica/spostamento
    QPoint mEndPoint; //coordinate finali del punto per il disegno di una shape e per modifica/spostamento
    QPoint mTempPoint; //coordinate temporanee del punto per il disegno di una shape, l'evidenziazione di un quadratino e per modifica/spostamento
    QList<QPoint> points; //variabile dove verranno salvati i punti della shape che l'utente sta disegnando in quel momento
    QString shapeID; //l'id della shape che l'utente ha selezionato in quel momento

    enum shapes{square, ellipse, polygon}; //le tre forme che può avere una shape, enumerate per evitare confusione

public:
    struct shape{ //cosa caratterizza una shape
        QString id; //il suo id: object+instance+number
        int form; //la sua forma quadrata, circolare, poligonale
        QList<QPoint> shapePoints; //i punti che formano la shape
    };

private:
    QList<shape> allEdits; //lista di tutte le shape che si stanno disegnando sull'immagine
    void defaultColorsThickness(); //metodo privato che assegna i valori di default da "radius" a "shapeBlu"

public:
    explicit DisplayImage(QWidget *parent = 0); //costruttore
    //metodo per assegnare i valori da "radius" a "shapeBlu" indicati dall'utente, invocato da MainWondow
    void setColorsThickness(int in_radius, int in_thickness, int in_myRed, int in_myGreen, int in_MyBlue, int in_sqRed, int in_sqGreen, int in_sqBlue, int in_shapeRed, int in_shapeGreen, int in_shapeBlue);
    void setView(QImage image); //assegna l'immagine su cui l'utente sta lavorando, invocato da MainWindow
    void enableSquareDraw(); //modifica il valore di verità di drawingSquareEnabled, invocato da MainWindow
    void enableEllipseDraw(); //modifica il valore di verità di drawingEllipseEnabled, invocato da MainWindow
    void enablePolygonDraw(); //modifica il valore di verità di drawingPolygonEnabled, invocato da MainWindow
    void enableHighlight(bool enable); //modifica il valore di verità di checked, invocato da MainWindow
    void setNameSelected(bool enable); //modifica il valore di verità di nameSelected, invocato da MainWindow
    void setShapeSelected(QString in_shapeID); //assegna l'id della shape selezionata dall'utente, invocato da MainWindow
    void setEdits(QList<shape> inputEdits); //assegna l'elenco delle shape disegnate sull'immagine, invocato da MainWindow
    void resizeEdits(int resize); //esegue il resize delle shape in base al resize applicato in quel momento sull'immagine, invocato da MainWindow
    void clear_image(); //rimuove tutti i dati temporanei e quelli relativi all'immagine su cui si stava lavorando, annotazioni comprese. Invocato da MainWindow
    void reset(); //rimuove tutti i dati temporanei, invocato da MainWindow
    void clearLastEdits(); //rimuove l'ultima annotazione effettutata, invocato da MainWindow

signals:
    void onLineDraw(QList<DisplayImage::shape>); //signals per la classe MainWindow. Spedisce la lista di tutte le annotazioni sull'immagine
    void setTuple(QString); //signals per la classe MainWindow. Speidisce l'id della shape selezionata dall'utente in caso di modifica/spostamento o aggiunta

protected:
    void paintEvent(QPaintEvent *); //metodo per la stampa su schermo di tutte le annotazioni e le varie operazioni effettuate dall'utente
    void mousePressEvent(QMouseEvent *mouseEvent); //metodo per la gestione del click da parte dell'utente
    void mouseReleaseEvent(QMouseEvent *mouseEvent); //metodo per la gestione del rilascio del tasto premuto dall'utente
    void mouseMoveEvent(QMouseEvent *mouseEvent); //metodo per gestione del movimento del mouse e la posizione del puntatore sull'immagine
    void mouseDoubleClickEvent(QMouseEvent *mouseEvent); //metodo per la gestione del doppio click dell'utente
};

#endif // DISPLAYIMAGE_H
