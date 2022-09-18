
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include <QDebug>


#include <QCoreApplication>

#include <QDataStream>

#include "global-types.h"

#include "withs.h"

#include <QMap>
#include <QStringList>

#include <QProcess>

#include "base32.h"

#include "textio.h"

#include "npy/cnpy.h"

USING_KANS(TextIO)

QString convert(QString dir, QString ndir, QString file, QString py_file)
{
 QString py = QString(R"(
import numpy
a = numpy.load("%1/%2.npy", allow_pickle=True, encoding='latin1')
numpy.save("%3/%2.2.npy", a, fix_imports=True))").arg(dir).arg(file).arg(ndir);

 save_file(py_file, py);

 QProcess proc;
 QString cmd = QString("python3 %1").arg(py_file);
 proc.execute(cmd);

 return QString("%1/%2.2.npy").arg(ndir).arg(file);
}

void phconvert (QString sp, QString f, QString phdir, QString clname)
{
 QFileInfo qfi(f);
 std::string filename = f.toStdString();


 QString bn = qfi.completeBaseName();
 if(bn.endsWith(".2"))
   bn.chop(2);

 QString ph_file = QString("%1/ph-%2.ntxh").arg(phdir).arg(bn);

 cnpy::NpyArray arr = cnpy::npy_load(filename);
 std::vector<double> ds = arr.as_vec<double>();

 int nfs = arr.shape[0];
 int dim = arr.shape[1];

 int c = 0;

 QString contents;

 QTextStream qts(&contents);

 qts << QString(R"(
!/ %1

$sp: %2
$n: %3
$d: %4
$s.
)").arg(clname).arg(sp).arg(nfs).arg(dim);

 for(int i = 0; i < nfs; ++i)
 {
  for(int j = 0; j < dim; ++j)
  {
   double d = ds[c];
   ++c;
   qts << d << "\n";
  }
  qts << "\n";
 }
 qts << "\n.\n";

 qts << "\n\n/!\n";
 save_file(ph_file, contents);

}


int main(int argc, char *argv[])
{
 QMap<QString, QStringList> args;
// QString enc;
 QStringRef enc;

 QString arg1;

 if(argc > 1)
   arg1 = QString::fromLatin1(argv[1]);

 if(arg1.startsWith("qmap="))
 {
  enc = arg1.midRef(5);
 }


 if(!enc.isEmpty())
 {
  QByteArray qba;
  base32_decode_qstringref(enc, qba);
  QDataStream qds(qba);
  qds >> args;

  qDebug() << args;
 }

 QString pytemp = QT_REPROZIP_BIN_FOLDER "/temp.py";
 qDebug() << pytemp;

 QString sp = args["abbr"].first();
 QString root = args["root"].first();
 QString filename = args["name"].first();
 QString phfolder = args["phf"].first();
 QString ext = args["ext"].first();
 QString bn;
 QString clname;
 QString dir;
 QString ndir;

 if(ext == "mfcc")
 {
  clname = "MFCC_Coefficients";
  dir = root + "/mfcc";
  ndir = root + "/mfcc-py2";
  bn = filename + ".mfcc";
 }
 else
 {
  clname = "LOG_Coefficients";
  dir = root + "/logmelspec";
  ndir = root + "/log-py2";
  bn = filename + ".logmelspec";
 }

 QString c = convert(dir, ndir, bn, pytemp);

 phconvert(sp, c, phfolder, clname);

 return 0;
}
