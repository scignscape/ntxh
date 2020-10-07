
// nc_license

#include <QDebug>


#include "cytolib/MemCytoFrame.hpp"

#include "facs-bridge/qvector-matrix-r8.h"

#include "facs-bridge/mpf-package.h"

#include "global-types.h"

#include "kans.h"
USING_KANS(MPF)


#include "get-cmdl.h"
USING_KANS(Util)


#include "cbicaCmdParser.h"

#include <string>


int main(int argc, char* argv[])
{
 cbica::CmdParser parser = cbica::CmdParser(argc, argv);

 parser.addOptionalParameter("f", "fcs-file", cbica::Parameter::FILE, "FCS File", "FCS file to convert");

 parser.addOptionalParameter("xshift", "xshift", cbica::Parameter::INTEGER, "x Shift",
                             "x axis displacement");
 parser.addOptionalParameter("xskew", "xskew", cbica::Parameter::INTEGER, "x Skew",
                             "x axis rescaling");
 parser.addOptionalParameter("xcolumn", "xcolumn", cbica::Parameter::INTEGER, "y Shift",
                             "x column");

 parser.addOptionalParameter("yshift", "yshift", cbica::Parameter::INTEGER, "y Shift",
                             "y axis displacement");
 parser.addOptionalParameter("yskew", "yskew", cbica::Parameter::INTEGER, "y Skew",
                             "y axis rescaling");
 parser.addOptionalParameter("ycolumn", "ycolumn", cbica::Parameter::INTEGER, "y Shift",
                             "y column");


 QString fcs_file;

 // //  If we want to use a single string for the dim params ...
  // QString dim_params;
  // get_cmdl(parser, {
  //  { {&fcs_file, "f"}, DEMO_FCS_FOLDER "/Live_cells.fcs" },
  //  { {&dim_params, "d"}, {}}
  //  });

// parser.addOptionalParameter("d", "dim-info", cbica::Parameter::STRING, "Dimension Info",
//                             "Dimension Selection and Transforms (encoded as string)");


 s4 xshift = 0, yshift = 0, xskew = 0, yskew = 0;
 u1 xcolumn = 0, ycolumn = 0;


 get_cmdl(parser, {
   { {&fcs_file, "f"}, {DEMO_FCS_FOLDER "/Live_cells.fcs"} },
   { {&xshift, "s4:xshift"}, {"25"} },
   { {&xskew, "s4:xskew"}, {"100"} },
   { {&yshift, "s4:yshift"}, {"25"} },
   { {&yskew, "s4:yskew"}, {"10"} },
   { {&xcolumn, "u1:xcolumn"}, {"1"} },
   { {&ycolumn, "u1:ycolumn"}, {"2"} },
  });


 cytolib::FCS_READ_HEADER_PARAM hp;
 cytolib::FCS_READ_DATA_PARAM dp;
 cytolib::FCS_READ_PARAM rp;


  // // maybe check for relative paths ...
 QString file_name = fcs_file;

 cytolib::MemCytoFrame mcf(file_name.toStdString(), rp);

 mcf.read_fcs();

//? QVector_Matrix_R8* qvm = mcf.data_to_qvmatrix();
 MPF_Package* mpf = new MPF_Package(2);

//? mpf->set_matrix(qvm);

 mpf->dimension_skews()[0] = xskew;
 mpf->dimension_skews()[1] = yskew;

 mpf->dimension_shifts()[0] = xshift;
 mpf->dimension_shifts()[1] = yshift;

 mpf->columns()[0] = xcolumn;
 mpf->columns()[1] = ycolumn;

 mpf->set_data_file_path(file_name + ".mpf.txt");
 mpf->set_fcs_file_path(file_name);

// mpf->dimension_shifts() = {5, 5};
// mpf->dimension_skews() = {10, 100};

 mpf->save_to_file(file_name + ".mpf.txt");
 
 qDebug() << "Saved: " << file_name + ".mpf.txt";

 // // double-check
  // MPF_Package* mpf1 = new MPF_Package(2);
  // mpf1->load_from_file(file_name + ".mpf.txt");

 return 0;
}

//#endif //def HIDE
