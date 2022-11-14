#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QCloseEvent>
#include "../backend/Image.h"
#include "../backend/CommandPattern/Commands.h"

#include "accessors.h"
#include "global-types.h"

#include "main-window-dialog.h"

#include <QDialog>

//namespace Ui {
//class MainWindow;
//}

class MainWindow : public QMainWindow
{
 Q_OBJECT

 QString default_image_folder_;

 QAction* set_scene_background_color_action_;
 QAction* open_action_;
 QAction* save_action_;
 QAction* save_as_action_;
 QAction* undo_action_;
 QAction* redo_action_;
 QAction* zoom_inc_action_;
 QAction* zoom_dec_action_;
 QAction* zoom_adapt_action_;
 QAction* grayscale_action_;
 QAction* contrast_action_;
 QAction* brightness_action_;
 QAction* color_mask_action_;
 QAction* blur_action_;
 QAction* sharpen_action_;
 QAction* emboss_action_;
 QAction* edge_detect_action_;
 QAction* heuristic_mask_action_;
 QAction* extend_mod_3_action_;
 QAction* quantize_3x3_action_;
 QAction* quantize_9x9_action_;
 QAction* quantize_27x27_action_;
 QAction* xshear_action_;
 QAction* yshear_action_;
 QAction* xskew_action_;
 QAction* yskew_action_;
 QAction* rotate_action_;
 QAction* skew_shear_action_;
 QAction* heuristic_color_mask_action_;
 QAction* calculate_action_;


 QWidget* central_widget_;

 QStatusBar* status_bar_;
 QToolBar* tool_bar_;

 QVBoxLayout* main_layout_;
 QGraphicsView* graphics_view_;
 QGraphicsPixmapItem* pixmap_item_;
 QGraphicsScene* scene_;

 std::unique_ptr<Image> active_image_;
 CommandManager command_manager_;

 bool pending_save_modifications_;

 QList<double> zoom_list_;

 QLabel* image_name_;
 QLabel* image_size_;

 std::vector<Pixel> secondary_pixel_buffer_;
 std::vector<Pixel> tertiary_pixel_buffer_;

 QPixmap current_pixmap_;

 QImage* alt_data_image_;

 enum class Skew_Shear_Rotate {
   N_A, XSkew, YSkew, XShear, YShear, Rotate, Generic
 };

protected:

 void closeEvent(QCloseEvent *event) override;
 void updateStatusBar();

 void resizeEvent(QResizeEvent* rev) Q_DECL_OVERRIDE;

 QVector<Command_or_String> predefined_transforms_;


public:

 explicit MainWindow(QWidget *parent = nullptr);
 ~MainWindow();

 ACCESSORS(QString ,default_image_folder)

 Image& get_active_image()
 {
  return *active_image_;
 }

 void open_image_file(QString path);

 void fit_image_in_view();
 void reset_scene_rectangle();

 void adjust_window_size(QSize& sz);

 void load_predefined_transforms(QVector<Command_or_String> cmds)
 {
  predefined_transforms_ = cmds;
 }

 void run_predefined_transforms(QString file_path_pattern = {},
   QVector<QColor> colors = {}, u1 overlay_cut = 1);

 void run_quantize_27x27();
 void run_internal_command(QString fn, QImage* ref);
 void run_feature_measurements(QImage* ref);

 void show_alpha_codes(QVector<QColor> colors, QString save_path);


private slots:

 void handle_heuristic_mask();
 void handle_extend_mod_3();
 void handle_quantize_3x3();
 void handle_quantize_9x9();
 void handle_quantize_27x27();
 void handle_shear_transform(Skew_Shear_Rotate ssr);
 void handle_heuristic_color_mask();
 void handle_calculate_action();

 void merge_heuristic_bins();

 void handle_set_scene_background_color();

 void handle_heuristic_color_mask(QColor c, u1 offset, QColor background,
   u1 background_opacity, u1 metric_code);

 void on_actionOpen_triggered();

 void on_actionSave_triggered();

 void on_actionZoom_Adapt_triggered();

 void on_actionZoomInc_triggered();

 void on_actionZoomDec_triggered();

 void on_actionRotate_Clockwise_triggered();

 void on_actionRotate_anticlockwise_triggered();

 void on_actionFlip_x_triggered();

 void on_actionFlip_y_triggered();

 void on_actionUndo_triggered();

 void on_actionRedo_triggered();

 void on_actionGrayscale_triggered();

 void on_actionBlur_triggered();

 void on_actionSharpen_triggered();

 void on_actionEmboss_triggered();

 void on_actionEdge_detect_triggered();

 void on_actionExit_triggered();

 void on_actionSave_as_triggered();

 void on_actionAbout_Image_Editor_triggered();

 void on_actionAbout_Qt_triggered();

 void on_actionContrast_triggered();

 void on_actionBrightness_triggered();

 void on_actionColormask_triggered();

 void on_actionScale_triggered();

protected slots:
 //    void resizeEvent(QResizeEvent *event) override;
 void zoomUpdate(bool increment);

};



#endif // MAINWINDOW_H
