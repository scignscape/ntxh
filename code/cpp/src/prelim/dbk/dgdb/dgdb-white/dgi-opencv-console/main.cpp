
#include <QImage>
#include <QLabel>

#include <QApplication>
#include <QMainWindow>

#include <QMap>

#include "dgi-opencv/dgi-image.h"

#include "dgi-opencv/dgi-demo-frame.h"


USING_KANS(DGI)


int main1(int argc, char *argv[])
{
// DGI_Image dgi(DEFAULT_DGI_FOLDER "/img.jpg");
 DGI_Image dgi(DEFAULT_DGI_FOLDER "/testdia.png");

 dgi.test();

 return 0;
}

int main(int argc, char *argv[])
{

 QApplication qapp(argc, argv);

// DGI_Image dgi(DEFAULT_DGI_FOLDER "/img.jpg");
 DGI_Image dgi(DEFAULT_DGI_FOLDER "/testdia.png");

// DGI_Image dgi(DEFAULT_DGI_FOLDER "/img1.jpg");

// DGI_Image dgi(DEFAULT_DGI_FOLDER "/AT20-0131A111.png");

 dgi.load();

 Demo_Transform_Group dtg(&dgi);
 dgi.init_demo_transform_group(dtg);

 dgi.to_csv(DEFAULT_DGI_FOLDER "/csv.csv");

 QMainWindow* mw = new QMainWindow;
 DGI_Demo_Frame* fr = new DGI_Demo_Frame(dtg, 200, 800, 300);

 mw->setCentralWidget(fr);

 mw->show();
 return qapp.exec();

// cv::Mat src = cv::imread("../mask/img.jpg");

// QLabel* l1 = _imshow(src, "l1");

 //l1->show();

}
