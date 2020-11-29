
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "facs-bridge-hgdm/mpf-package-hgdm.h"
#include "facs-bridge-hgdm/hgdm-angel-runtime-context.h"

#include "facs-bridge/qvector-matrix-r8.h"

#include "facs-bridge-hgdm/hQVariant.h"

#include "facs-bridge/mpf-package.h"

#include "as-runner/as-runner.h"

#include <QFile>
#include <QDebug>

#include "kans.h"

USING_KANS(MPF)

#include "cbicaCmdParser.h"
#include <string>

#include "get-cmdl.h"
USING_KANS(Util)



void _test_hgdm(HGDM_Traverser* ht)
{
 ht->selto("?");
}

void test_hgdm(n8 nn)
{
 static HGDM_Traverser* the_traverser = nullptr;
 if(nn)
   the_traverser = (HGDM_Traverser*) nn;
 else
   _test_hgdm( the_traverser );
}

MPF_Package_HGDM* the_pkg(MPF_Package* mpfp = nullptr)
{
 static MPF_Package_HGDM* result = nullptr;
 if(!result)
 {
  if(mpfp)
    result = new MPF_Package_HGDM(*mpfp);
 }
 return result;
}

HGDM_Angel_Runtime_Context* new_rt_context()
{
 MPF_Package_HGDM* hg = the_pkg();
 HGDM_Angel_Runtime_Context* result =
   new HGDM_Angel_Runtime_Context;
 result->set_pkg(hg);
 return result;
}

void hQDebug(hQVariant& hqv)
{
 QVariant qv = hqv.value();
 qDebug() << qv;

 QString ty = QString::fromLatin1(qv.typeName());

 if(ty == "QVector<uchar>")
 {
  qDebug() << qv.value<QVector<u1>>();
 }
 
}

int main(int argc, char* argv[])
{
 cbica::CmdParser parser = cbica::CmdParser(argc, argv);

 parser.addOptionalParameter("f", "asfile", cbica::Parameter::FILE, "AngelScript File", "Script query file");

 parser.addOptionalParameter("m", "mpffile", cbica::Parameter::FILE, "MPF File", "MPF serialization file");

 parser.ignoreArgc1();


 QString as_file;
 QString mpf_file;

 get_cmdl(parser, {
   { {&as_file, "f"}, {AS_ROOT_DIR "/hgdm/t1.as"} },
   { {&mpf_file, "m"}, QStringList{} },
  });

 qDebug() << "AS File: " << as_file;
 qDebug() << "AS File: " << mpf_file;

 AS_Runner asr;

 asIScriptEngine* engine = asr.engine();
 int r = engine->RegisterGlobalFunction("void test_hgdm(uint64)", asFUNCTION(test_hgdm), asCALL_CDECL);

 // init stuff ...
 r = engine->RegisterObjectType("HGDM_Angel_Runtime_Context", 0, asOBJ_REF); //assert( r >= 0 );

 r = engine->RegisterObjectBehaviour("HGDM_Angel_Runtime_Context", asBEHAVE_ADDREF, "void f()",
   asMETHOD(HGDM_Angel_Runtime_Context,add_ref), asCALL_THISCALL); //assert( r >= 0 );

 r = engine->RegisterObjectBehaviour("HGDM_Angel_Runtime_Context", asBEHAVE_RELEASE, "void f()",
   asMETHOD(HGDM_Angel_Runtime_Context,release), asCALL_THISCALL); //assert( r >= 0 );

 r = engine->RegisterGlobalFunction("HGDM_Angel_Runtime_Context@ new_rt_context()",
   asFUNCTION(new_rt_context), asCALL_CDECL);
// assert( r >= 0 );

 r = engine->RegisterObjectMethod("HGDM_Angel_Runtime_Context", "HGDM_Angel_Runtime_Context@ selto(const string &in)", asMETHOD(HGDM_Angel_Runtime_Context,selto_ss), asCALL_THISCALL);
 //assert( r >= 0 );

 r = engine->RegisterObjectMethod("HGDM_Angel_Runtime_Context", "HGDM_Angel_Runtime_Context@ init2()", asMETHOD(HGDM_Angel_Runtime_Context,init2), asCALL_THISCALL);
 //assert( r >= 0 );

 r = engine->RegisterObjectMethod("HGDM_Angel_Runtime_Context", "HGDM_Angel_Runtime_Context@ pval()", asMETHOD(HGDM_Angel_Runtime_Context,pval), asCALL_THISCALL);
 //assert( r >= 0 );

 r = engine->RegisterObjectType("hQVariant", 0, asOBJ_REF); //assert( r >= 0 );

 r = engine->RegisterObjectBehaviour("hQVariant", asBEHAVE_ADDREF, "void f()",
   asMETHOD(HGDM_Angel_Runtime_Context,add_ref), asCALL_THISCALL); //assert( r >= 0 );

 r = engine->RegisterObjectBehaviour("hQVariant", asBEHAVE_RELEASE, "void f()",
   asMETHOD(HGDM_Angel_Runtime_Context,release), asCALL_THISCALL); //assert( r >= 0 );

 r = engine->RegisterObjectMethod("HGDM_Angel_Runtime_Context", "hQVariant@ read()",
   asMETHOD(HGDM_Angel_Runtime_Context,read_hqv), asCALL_THISCALL);
 //assert( r >= 0 );

 r = engine->RegisterGlobalFunction("void hQDebug(hQVariant&)", asFUNCTION(hQDebug), asCALL_CDECL);

 MPF_Package* mpfp = new MPF_Package;
 MPF_Package_HGDM* hg = the_pkg(mpfp);

 if(mpf_file.isEmpty())
 {
  QVector_Matrix_R8* matrix = new QVector_Matrix_R8(4, 3);

  for(u1 r = 1; r <= 4; ++r )
  {
   for(u1 c = 1; c <= 3; ++c )
   {
    (*matrix)[r][c] = (10 * r) + c;
   }
  }

  mpfp->set_matrix(matrix);
 }
 else
 {
  mpfp->load_from_file(mpf_file);
 }

 asr.run_script(as_file);

// hg->selto("column-count");

// u1 nc = hg->read().toInt();

// u1 nr = hg->selto("row-count").read().toInt();

// qDebug() << QString("Rows = %1, Cols = %2").arg(nr).arg(nc);

// qDebug() << "OK";

 return 0;
}

