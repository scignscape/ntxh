
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

MPF_Package_HGDM* the_pkg(MPF_Package* mpf = nullptr)
{
 static MPF_Package_HGDM* result = nullptr;
 if(!result)
 {
  if(mpf)
    result = new MPF_Package_HGDM(*mpf);
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
 qDebug() << hqv.value();
}

int main()
{
 AS_Runner asr;
// ([] (asIScriptEngine* e)
// {
//  //engine = e;
//  //int r = engine->RegisterGlobalFunction("void test_hgdm(uint64)", asFUNCTION(test_hgdm), asCALL_CDECL);
// });
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



 MPF_Package* mpf = new MPF_Package;
 MPF_Package_HGDM* hg = the_pkg(mpf);

// test_hgdm( (n8) hg);


// asIScriptEngine* engine = asr.engine();

// int r = engine->RegisterGlobalFunction("void test_hgdm(uint64)", asFUNCTION(test_hgdm),
//   asCALL_CDECL); //assert( r >= 0 );

// r = engine->RegisterGlobalFunction("void ttpr(const string &in)", asFUNCTION(ttpr), asCALL_CDECL);

 QVector_Matrix_R8* matrix = new QVector_Matrix_R8(4, 3);

 for(u1 r = 1; r <= 4; ++r )
 {
  for(u1 c = 1; c <= 3; ++c )
  {
   (*matrix)[r][c] = (10 * r) + c;
  }
 }

 mpf->set_matrix(matrix);

 asr.run_script(AS_ROOT_DIR "/hgdm/t1.as");

// hg->selto("column-count");

// u1 nc = hg->read().toInt();

// u1 nr = hg->selto("row-count").read().toInt();

// qDebug() << QString("Rows = %1, Cols = %2").arg(nr).arg(nc);

 qDebug() << "OK";

 return 0;
}

