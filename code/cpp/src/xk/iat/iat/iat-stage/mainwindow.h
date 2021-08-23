#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <displayimage.h>
#include <projectwizard.h>
#include <options.h>
#include <listtool.h>
#include <QMainWindow>
#include <QScrollArea>

#include <QVector>

#include "global-types.h"

//namespace Ui
//{
// class MainWindow;
//}

class AXFI_Annotation;
class AXFI_Annotation_Group;

class Shape_Select_Frame;
class Zoom_and_Navigate_Frame;

class WebGL_View_Dialog;
class QUdpSocket;


class MainWindow : public QMainWindow
{
 Q_OBJECT

public:

 explicit  MainWindow(QWidget* parent = 0);  //costruttore

 ~MainWindow(); //ditruttore

private:

 WebGL_View_Dialog* current_wgl_dialog_;


 QUdpSocket* meshlab_out_socket_;
 QUdpSocket* meshlab_in_socket_;


 QAction* action_view_360;

 QAction* action_view_3d;

 QAction* actionAnnotate_Single_Image;
 QAction* action_load_annotations;
 QAction* action_view_contours;

 QAction* actionQuit;
 QAction* actionInstructions;
 QAction* actionOptions;


 QMenu* file_menu_;
 QMenu* help_menu_;
 QMenu* tools_menu_;

 QString save_area_folder_;

 DisplayImage* display_image_; //istanza della classe DisplayImage, dove viene gestita tutta la parte grafica

 DisplayImage_Scene_Item* display_scene_item_; //istanza della classe DisplayImage, dove viene gestita tutta la parte grafica
 DisplayImage_Data* display_image_data_; //istanza della classe DisplayImage, dove viene gestita tutta la parte grafica


 ProjectWizard pwizard_; //istanza della classe ProjectWizard, dove viene iniziato il processo per le annotazioni di più immagini
 Options optionsDialog_; //istanza della classe Options, dove l'utente potrà cambiare alcune impostazioni
 ListTool listToolDialog_; //istanza della classe ListTool, dove l'utente potrà creare liste personalizzate (WIP)

 int autogen_index_;

 QFrame* main_frame_;

 Shape_Select_Frame* shape_select_frame_;
 Zoom_and_Navigate_Frame* zoom_frame_;

 QHBoxLayout* top_layout_;
 QVBoxLayout* main_layout_;


 QString workspace_; //percorso che contiene il path di dove è stato aperta l'ultima immagine o l'ultimo file di annotazione
 QString image_filename_path_; //il path completo dell'immagine scelta dall'utente
 QString list_filename_path_; //il path completo del file che contiene la lista delle categorie, scelto dall'utente
 QString txt_filename_path_; //il path completo del file di annotazione (sempre generato dal programma) scelto dall'utente
 QString project_filename_path_; //il path completo della cartella dove verranno messi alcuni file durante il progetto per le annotazioni di più immagini
 QString shapeID_; //l'ID della shape selezionata dall'utente

 QList<QString> imageSequence_; //sequenza delle immagini annotate dall'utente durante il progetto per l'annotazione di più immagini

 QMultiMap<QString,QString> mapObjectInstance_; //mappa interna per il salvataggio di coppie Object+Instance
 QMultiMap<QString,QString> mapInstanceNumber_; //mappa interna per il salvataggio di coppie Object:Instance+Number

 QImage background_; //l'immagine sulla quale si lavorerà

 enum shapes{square, ellipse, polygon}; //le tre forme che può avere una shape, enumerate per evitare confusione

 QList<DisplayImage_Data::shape> scaledEdits_; //lista di tutte le shape che si stanno disegnando sull'imagine
 AXFI_Annotation_Group* axfi_annotation_group_;

 void check_init_axfi_annotation_group();
 //QVector<AXFI_Annotation*> axfi_annotations_;


 int sizeh_; //altezza dell'immagine
 int sizew_; //larghezza dell'immagine
 int resize_factor_; //valore dello slider
 bool ctrlIsPressed_; //se vero, significa che l'utente sta premendo il tasto ctrl, per le shrotcut da tastiera
 bool shiftIsPressed_; //se vero, significa che l'utente sta premendo il tasto shift, per le shortcut da tastiera

 struct backUp
 {
  //struttura che conterrà i dati sensibili della classe MainWindow utilizzata per il backup ed il ripristino dei dati
  QString workspace;
  QString image_filename_path;
  QString list_filename_path;
  QString txt_filename_path;
  QString project_filename_path;
  QString ShapeID;
  QString title;
  QMultiMap<QString,QString> mapObjectInstance;
  QMultiMap<QString,QString> mapInstanceNumber;
  QImage background;
  QList<DisplayImage_Data::shape> scaledEdits;
  int sizeh;
  int sizew;
  int resize_factor;
 };

 backUp backUpHere_; //istanza dove salvare i dati sensibili

 //? Ui::MainWindow *ui; //puntatore all'interfaccia grafica

 void set_initial_gui(); //metodo che setterà l'interfaccia grafica all'avvio
 void makeBackUp(); //metodo che esegue il backUp dei dati
 void load_image(); //metodo che prepara la finestra a stampare la nuova immagine
 void load_list(); //metodo che processa la lista scelta dall'utente e la carica
 bool load_annotation(); //metodo che processa il file di annotazione scelto dall'utente
 void doBackUp(); //metodo che esegue il ripristino dei dati
 void cleanWindow(); //metodo che resetta il programma preparandolo ad un nuovo processo
 void defaultView(); //metodo che porta il programma ad una situazione standard
 bool resizeMethod(int value); //metodo che processa l'immagine, fa il resize se necessario e la stampa
 QPoint coordinate_scaling(QPoint init_point); //metodo che calcola il resize dei punti apparteneti alle shape


 void load_image(QString file_path);

 void setup_shape_rectangle();
 void setup_shape_polygon();
 void setup_shape_ellipse();
 void setup_highlight(bool checked);

 void _handle_clear_selected(); //metodo legato al bottone rettangolare con il nome Clear Selected
 void _handle_clear_last(); //metodo legato al bottone rettangolare con il nome Clear Last
 void _handle_clear_all(); //metodo legato al bottone rettangolare con il nome Clear All

 void _handle_save();
 void _handle_save_requested();

public:

 void init_display_scene_item(DisplayImage_Scene_Item* si);


private Q_SLOTS:

 void on_actionOptions_triggered(); //metodo legato al comando Options
 //metodo attivato dal signal colorsThickness presente in Options
 void getColorsThickness(int radius, int thickness, int myRed, int myGreen, int MyBlue, int sqRed, int sqGreen, int sqBlue, int shapeRed, int shapeGreen, int shapeBlue);
 void on_actionAnnotate_Single_Image_triggered(); //metodo legato al comando Annotate Single Image
 void on_actionAnnotate_Multiple_Image_triggered(); //metodo legato al comando Annotate Multiple Image

 void on_action_load_annotations_triggered(); //metodo legato al comando Load Annotation
 void on_action_view_360_triggered();
 void on_action_view_contours_triggered();
 void on_action_view_3d_triggered();


 void on_actionCreate_List_triggered(); //metodo legato al comando Create List (WIP)
 void on_actionInstructions_triggered(); //metodo legato al comando Instructions
 void on_ResizeSlider_sliderMoved(int position); //metodo legato allo slider che gestisce lo zoom
 void getTuple(QString shapeID); //metodo attivato dal signal setTuple presente in DisplayImage
 void on_ObjectListView_clicked(); //metodo legato alla prima colonna
 void on_InstanceListView_clicked(); //metodo legato alla seconda colonna
 void on_NumberListView_clicked(); //metodo legato alla terza colonnna


 void handle_zoom_factor_changed(r8 factor);
 void handle_save_notation_requested();

 void handle_complete_polygon_requested();

 void handle_polygon_complete_and_save_notation_requested();
 void handle_polygon_save_notation_requested();
 //?
 //    void on_Square_clicked(); //metodo legato al bottone circolare con a fianco il testo Square
 //    void on_Ellipse_clicked(); //metodo legato al bottone circolare con a fianco il testo Ellipse
 //    void on_Polygon_clicked(); //metodo legato al bottone circolare con a fianco il testo Polygon
 //    void on_Highlight_clicked(bool checked); //metodo legato al bottone quadrato con a fianco il testo Highlight


 void onDrawLine(QList<DisplayImage_Data::shape> edits); //metodo attivato dal signal onLineDraw presente in DisplayImage

 //?
 //    void on_ClearSelected_clicked(); //metodo legato al bottone rettangolare con il nome Clear Selected
 //    void on_ClearLast_clicked(); //metodo legato al bottone rettangolare con il nome Clear Last
 //    void on_ClearAll_clicked(); //metodo legato al bottone rettangolare con il nome Clear All

 void handle_clear_selected(); //metodo legato al bottone rettangolare con il nome Clear Selected
 void handle_clear_last(); //metodo legato al bottone rettangolare con il nome Clear Last
 void handle_clear_all(); //metodo legato al bottone rettangolare con il nome Clear All

 void on_EndProject_clicked(); //metodo legato al bottone rettangolare con il nome End Project
 void on_LoadNext_clicked(); //metodo legato al bottone rettangolare con il nome Load Next
 void on_LoadPrevious_clicked(); //metodo legato al bottone rettangolare con il nome Load Previous
 void on_Save_clicked(); //metodo legato al bottone rettangolare con il nome Save
 void on_actionQuit_triggered(); //metodo legato al comando Quit

 void handle_save_requested(bool);

protected:
 void closeEvent(QCloseEvent *event); //metodo per la gestione della chiusura della finestra
 void resizeEvent(QResizeEvent *event); //metodo per la gestione del resize della finestra
 void keyPressEvent(QKeyEvent *event); //metodo per la gestione della pressione di determinati tasti mentre è attiva la finestra
 void keyReleaseEvent(QKeyEvent *event); //metodo per la gestione del rilascio di determinati tasti mentre è attiva la finestra
 void wheelEvent(QWheelEvent *event); //metodo per la gestione del movimento della rotella mentre è attiva la finestra
};
#endif // MAINWINDOW_H
