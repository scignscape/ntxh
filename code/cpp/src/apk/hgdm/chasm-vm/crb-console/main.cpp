
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

int main(int argc, char *argv[])
{
 Chasm_Runtime csr;
 Chasm_Runtime_Bridge crb(&csr);
// Chasm_VM cvm(&crb);


 crb.new_call_package();
 crb.add_new_channel("lambda");

 QVariant a1 = 103;
 r8 a2 = .12345;
 u2 a3 = 12345;

 crb.push_carrier_queue();
 crb.load_type_QString();
 crb.gen_carrier();
}

