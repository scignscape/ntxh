
#include "image-editor/frontend/MainWindow.h"

#include "image-editor/frontend/main-window-dialog.h"

#include "QApplication"

int main(int argc, char *argv[])
{
 QApplication a(argc, argv);

 //    MainWindow w;
 //    w.show();

 Main_Window_Dialog dlg;

 dlg.set_default_image_folder(DHAX_IMAGE_FOLDER);

 dlg.show();
 return a.exec();
}
