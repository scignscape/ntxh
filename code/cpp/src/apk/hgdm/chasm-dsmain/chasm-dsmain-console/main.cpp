
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include "textio.h"
USING_KANS(TextIO)


#include "chasm/chasm-runtime.h"
//#include "chasm-lib/chasm/chasm-call-package.h"

#include "chasm-vm/chasm-vm.h"
#include "chasm-runtime-bridge/chasm-runtime-bridge.h"

#include "chasm-dsmain/chasm-dsmain.h"
#include "chasm-dsmain-model/chasm-dsmain-model.h"


int main(int argc, char *argv[])
{
 Chasm_Runtime csr;
 Chasm_Runtime_Bridge crb(&csr);
 Chasm_Procedure_Table cpt(&csr);

 Chasm_DSMain_Model cdm(&cpt);
 cdm.register_procedures();

 //crb.

// Chasm_DSMain cdsm;
// csm.gen_source_proc_name();
// csm.load_program(DEMO_CSM_FOLDER "/demo/t1.csm");
// csm.run_current_source_proc_name();
}


