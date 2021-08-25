#ifndef DISPLAYIMAGE_H
#define DISPLAYIMAGE_H

#include <QWidget>
#include <QtGui>


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <QVBoxLayout>

#include "global-types.h"

#include "accessors.h"

#include "display-drawn-shape.h"

class AXFI_Annotation;


//class Special_Graphics_Scene : public QGraphicsScene
//{

//public:

// Special_Graphics_Scene(QWidget* parent);

// void drawForeground() Q_DECL_OVERRIDE;

//};


class DisplayImage_Scene_Item;
class DisplayImage_Data;

class MainWindow;

class DisplayImage : public QWidget
{
 Q_OBJECT

  QPixmap* scrolled_image_pixmap_;

 // QPixmap* original_scrolled_image_pixmap_;
 // QMap<int, QPixmap*> pixmaps_by_contrast_measure_;


  //QGraphicsScene *scene
  QGraphicsView* scrolled_image_view_;
  QGraphicsScene* scrolled_image_scene_;

  //QGraphicsPixmapItem* scrolled_image_pixmap_item_;
  QGraphicsProxyWidget* scrolled_image_pixmap_item_;

  QGraphicsRectItem* background_rectangle_;

  int background_rectangle_center_x_;
  int background_rectangle_center_y_;

  QVBoxLayout* main_layout_;

  DisplayImage_Scene_Item* image_scene_item_;

  DisplayImage_Data* display_image_data_;

  MainWindow* main_window_;

  void recenter_image();

public:

 enum shapes{ square, ellipse, polygon }; //le tre forme che può avere una shape, enumerate per evitare confusione

 ACCESSORS__GET(DisplayImage_Scene_Item* ,image_scene_item)
 ACCESSORS__GET(DisplayImage_Data* ,display_image_data)
 ACCESSORS(MainWindow* ,main_window)

 void recenter_scroll_center();
 void recenter_scroll_top_left();

 explicit DisplayImage(QWidget *parent = nullptr); //costruttore

 void load_image(QString file_path);
 void reset_scale(r8 factor);


};

class DisplayImage_Data
{
 friend class DisplayImage_Scene_Item;

 bool pan_mode;

 bool multi_draw;

 bool isMoving_; //se vero, il programma sta catturando la posizione del mouse sull'immagine
 bool isPressed_; //se vero, il programma  entrato nella fase di disegno di una shape
 bool isDoublePressed_; //se vero, il programma riconosce che l'utente ha terminato di disegnare un poligono
 bool shapeMoving_; //se vero, il programma riconosce che l'utente sta spostando una shape
 bool checked_; //se vero, l'utente ha attivo la funzione highlight
 bool editing_; //se vero, il programma riconosce che l'utente sta modificando le coordinate di un punto di una shape
 bool nameSelected_; //se vero, l'utente ha selezionato un valore nella colonna Object ed un valore nella colonna Instance
 bool drawingSquareEnabled_; //se vero, la prossima shape sar quadrata/rettangolare
 bool drawingEllipseEnabled_; //se vero, la prossima shape sar circolare
 bool drawingPolygonEnabled_; //se vero, la prossima shape sar un poligono

 int pointPosition_; //indica la posizione nel vettore del punto di quella shape che l'utente sta modificando
 int shapePosition_; //indica la posizione nel vettore della shape che l'utente sta modificando/spostando
 int radius_; //dimensione dei quadrati corrispondenti ai punti da cui, insieme alle linee,  formata la shape
 int thickness_; //spessore delle linee da cui, insieme ai punti,  formata la shape
 int myRed_; //valore del colore rosso delle shape non selezionate
 int myGreen_; //valore del colore verde delle shape non selezionate
 int myBlue_; //valore del colore blu delle shape non selezionate
 int sqRed_; //valore del colore rosso dei quadratini
 int sqGreen_; //valore del colore verde dei quadratini
 int sqBlue_; //valore del colore blu dei quadratini
 int shapeRed_; //valore del colore rosso della shape selezionata
 int shapeGreen_; //valore del colore verde della shape selezionata
 int shapeBlue_; //valore del colore blu della shape selezionata

 QImage m_background_; //copia dell'immagine su cui si faranno le annotazioni
 QPoint mStartPoint_; //coordinate iniziali del punto per il disegno di una shape e per modifica/spostamento
 QPoint mEndPoint_; //coordinate finali del punto per il disegno di una shape e per modifica/spostamento
 QPoint mTempPoint_; //coordinate temporanee del punto per il disegno di una shape, l'evidenziazione di un quadratino e per modifica/spostamento
 QList<QPoint> points_; //variabile dove verranno salvati i punti della shape che l'utente sta disegnando in quel momento
 QString shapeID_; //l'id della shape che l'utente ha selezionato in quel momento

 QVector<QPair<QPoint, QPoint>> point_pairs_;

public:

 struct shape
 {
  //cosa caratterizza una shape
  QString id; //il suo id: object+instance+number
  int form; //la sua forma quadrata, circolare, poligonale
  QList<QPoint> shapePoints; //i punti che formano la shape

  AXFI_Annotation* axfi_annotation;
 };

public:

 void setView(QImage image); //assegna l'immagine su cui l'utente sta lavorando, invocato da MainWindow

 Display_Drawn_Shape::Shape_Kinds current_enabled_shape_kind()
 {
  if(drawingSquareEnabled_)
    return Display_Drawn_Shape::Shape_Kinds::Rectangle;
  if(drawingEllipseEnabled_)
    return Display_Drawn_Shape::Shape_Kinds::Ellipse;
  if(drawingPolygonEnabled_)
    return Display_Drawn_Shape::Shape_Kinds::Polygon;

  return Display_Drawn_Shape::Shape_Kinds::N_A;
 }

 void set_pan_mode()
 {
  pan_mode = true;
 }

 void unset_pan_mode()
 {
  pan_mode = false;
 }

 void set_multi_draw()
 {
  multi_draw = true;
 }

 void unset_multi_draw()
 {
  multi_draw = false;
 }


private:

 QList<shape> allEdits_; //lista di tutte le shape che si stanno disegnando sull'immagine

 Display_Drawn_Shape* current_drawn_shape_;

 QStack<Display_Drawn_Shape*> held_drawn_shapes_;

 QList<Display_Drawn_Shape*> last_canceled_drawn_shapes_;

public:

 ACCESSORS(Display_Drawn_Shape* ,current_drawn_shape)

 ACCESSORS__RGET(QStack<Display_Drawn_Shape*> ,held_drawn_shapes)
 ACCESSORS__RGET(QList<Display_Drawn_Shape*> ,last_canceled_drawn_shapes)

 Display_Drawn_Shape* get_current_drawn_shape();

 void reset_drawn_shapes();

 void complete_polygon();

 void check_clear_last_canceled_drawn_shapes()
 {
  while(!last_canceled_drawn_shapes_.isEmpty())
  {
   Display_Drawn_Shape* dds = last_canceled_drawn_shapes_.takeLast();
   delete dds;
  }
 }

 Display_Drawn_Shape* check_current_drawn_shape(Display_Drawn_Shape::Shape_Kinds sk)
 {
  if(!current_drawn_shape_)
    current_drawn_shape_ = new Display_Drawn_Shape(sk);
  else
    current_drawn_shape_->set_shape_kind(sk);
  return current_drawn_shape_;
 }

 Display_Drawn_Shape* check_current_drawn_shape()
 {
  return check_current_drawn_shape(current_enabled_shape_kind());
 }

 void cancel_current_drawn_shape()
 {
  last_canceled_drawn_shapes_.push_back(current_drawn_shape_);
  current_drawn_shape_ = nullptr;
  points_.clear();
 }

 void check_hold_drawn_shape()
 {
  if(current_drawn_shape_)
    held_drawn_shapes_.push(current_drawn_shape_);
  current_drawn_shape_ = nullptr;
 }

 Display_Drawn_Shape* check_reset_drawn_shape()
 {
  if(current_drawn_shape_)
  {
   current_drawn_shape_->reset_all();
   return current_drawn_shape_;
  }
  return nullptr;
 }



 void defaultColorsThickness(); //metodo privato che assegna i valori di default da "radius" a "shapeBlu"

 //metodo per assegnare i valori da "radius" a "shapeBlu" indicati dall'utente, invocato da MainWondow
 void setColorsThickness(int in_radius, int in_thickness, int in_myRed, int in_myGreen, int in_MyBlue, int in_sqRed, int in_sqGreen, int in_sqBlue, int in_shapeRed, int in_shapeGreen, int in_shapeBlue);
 void enableSquareDraw(); //modifica il valore di verit di drawingSquareEnabled, invocato da MainWindow
 void enableEllipseDraw(); //modifica il valore di verit di drawingEllipseEnabled, invocato da MainWindow
 void enablePolygonDraw(); //modifica il valore di verit di drawingPolygonEnabled, invocato da MainWindow
 void enableHighlight(bool enable); //modifica il valore di verit di checked, invocato da MainWindow
 void setNameSelected(bool enable); //modifica il valore di verit di nameSelected, invocato da MainWindow
 void setShapeSelected(QString in_shapeID); //assegna l'id della shape selezionata dall'utente, invocato da MainWindow
 void setEdits(QList<shape> inputEdits); //assegna l'elenco delle shape disegnate sull'immagine, invocato da MainWindow
 void resizeEdits(int resize); //esegue il resize delle shape in base al resize applicato in quel momento sull'immagine, invocato da MainWindow
 void clear_image(); //rimuove tutti i dati temporanei e quelli relativi all'immagine su cui si stava lavorando, annotazioni comprese. Invocato da MainWindow
 void reset(); //rimuove tutti i dati temporanei, invocato da MainWindow
 void clearLastEdits(); //rimuove l'ultima annotazione effettutata, invocato da MainWindow

public:

 DisplayImage_Data();

};

class DisplayImage_Scene_Item : public QWidget
{
 Q_OBJECT

private:


// QPixmap* scrolled_image_pixmap_;

//// QPixmap* original_scrolled_image_pixmap_;
//// QMap<int, QPixmap*> pixmaps_by_contrast_measure_;


// //QGraphicsScene *scene
// QGraphicsView* scrolled_image_view_;
// QGraphicsScene* scrolled_image_scene_;
// QGraphicsPixmapItem* scrolled_image_pixmap_item_;

// QGraphicsRectItem* background_rectangle_;

// int background_rectangle_center_x_;
// int background_rectangle_center_y_;

// QVBoxLayout* main_layout_;

// void recenter_image();

 DisplayImage_Data* data_;

 QGraphicsProxyWidget* this_proxy_widget_;

 QGraphicsItem* background_item_;

 QGraphicsView* containing_image_view_;

 QPointF original_position_;

 u4* meshlab_import_count_;

 QVector<QPair<AXFI_Annotation*, r8>> saved_axfi_annotations_;

// QGraphics

 enum class Mouse_Event_Modes { N_A, Left_Edit, Left_Move,
   Left_Init, Right_Edit, Right_Move, Right_Init,
   Left_Move_Release, Left_Edit_Release,
   Right_Click_Iso   };

 template<Mouse_Event_Modes mem>
 void handle_mouse_event(QMouseEvent* mev);

 void _handle_mouse_event(QMouseEvent* mev, Mouse_Event_Modes mem);

 void paintEvent_draw_point_pairs(QVector<QPair<QPoint, QPoint>>& pairs, QPainter& painter,
   QPen& pen, QPen& shape_pen);

 void paintEvent_draw_drawn_shape(Display_Drawn_Shape* dds, QString text,
   QPainter& painter, QPen& pen, QPen& shape_pen);

 void paintEvent_draw_drawn_shape(Display_Drawn_Shape* dds,
   QPainter& painter, QPen& pen, QPen& shape_pen)
 {
  paintEvent_draw_drawn_shape(dds, {}, painter, pen, shape_pen);
 }

 void paintEvent_draw_annotation(AXFI_Annotation& axa, QPainter& painter,
   QPen& pen, QPen& shape_pen, r8 resize_factor);

 void paintEvent_draw_vertex_handles(const QVector<const QPoint*>& points, QPainter& painter);

public:

 enum shapes{ square, ellipse, polygon }; //le tre forme che può avere una shape, enumerate per evitare confusione

// void recenter_scroll_center();
// void recenter_scroll_top_left();

 ACCESSORS(DisplayImage_Data* ,data)
 ACCESSORS(QGraphicsProxyWidget* ,this_proxy_widget)
 ACCESSORS(QPointF ,original_position)
 ACCESSORS(QGraphicsItem* ,background_item)
 ACCESSORS(QGraphicsView* ,containing_image_view)
 ACCESSORS(u4* ,meshlab_import_count)

public:

 explicit DisplayImage_Scene_Item(QWidget *parent = 0);

 void reset_background_to_original_position();

 void add_axfi_annotation(AXFI_Annotation* axa, r8 resize_factor)
 {
  saved_axfi_annotations_.push_back({axa, resize_factor});
 }

 ACCESSORS(MACRO_PASTE(QVector<QPair<AXFI_Annotation*, r8>>) ,saved_axfi_annotations)

Q_SIGNALS:

 void onLineDraw(QList<DisplayImage_Data::shape>); //signals per la classe MainWindow. Spedisce la lista di tutte le annotazioni sull'immagine
 void setTuple(QString); //signals per la classe MainWindow. Speidisce l'id della shape selezionata dall'utente in caso di modifica/spostamento o aggiunta

 void save_notation_requested(bool);
 void polygon_complete_and_save_notation_requested();
 void polygon_save_notation_requested();
 void complete_polygon_requested();
 void meshlab_import_info_requested();


protected:
 void paintEvent(QPaintEvent *); //metodo per la stampa su schermo di tutte le annotazioni e le varie operazioni effettuate dall'utente
 void mousePressEvent(QMouseEvent *mouseEvent); //metodo per la gestione del click da parte dell'utente
 void mouseReleaseEvent(QMouseEvent *mouseEvent); //metodo per la gestione del rilascio del tasto premuto dall'utente
 void mouseMoveEvent(QMouseEvent *mouseEvent); //metodo per gestione del movimento del mouse e la posizione del puntatore sull'immagine
 void mouseDoubleClickEvent(QMouseEvent *mouseEvent); //metodo per la gestione del doppio click dell'utente
};

#endif // DISPLAYIMAGE_H
