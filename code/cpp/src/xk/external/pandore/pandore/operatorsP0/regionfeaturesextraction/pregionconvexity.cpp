/* -*- c-basic-offset: 3 -*-
 *
 * Copyright (c), GREYC.
 * All rights reserved
 *
 * You may use this file under the terms of the BSD license as follows:
 *
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of the GREYC, nor the name of its
 *     contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 *
 * 
 * For more information, refer to:
 * https://clouard.users.greyc.fr/Pandore
 */

/**
 * @author Alexandre Duret-Lutz - 1999-11-19
 * @author Regis Clouard - 2003-06-20 (fix bug on for (...; r<=rgs.Labels()..)
 */

#include <pandore.h>
using namespace pandore;

/**
 * @file pregionconvexity.cpp
 * Calcule les surfaces des regions d'une carte de regions, 
 * puis sauvegarde dans une collection le tableau resultant.
 */

#ifdef MAIN
#undef MAIN
#include "region/pconvexityselection.cpp"
#define MAIN
#else
#include "region/pconvexityselection.cpp"
#endif

Errc PRegionConvexity( const Reg2d &rgs, Collection &cold, const std::string &s ) {
   struct attrs_convexite *regions;
   
   regions = (struct attrs_convexite*)calloc(rgs.Labels() + 1, sizeof(struct attrs_convexite));
   if (Convexite(rgs, regions) == FAILURE) {
      return FAILURE;
   }
   
   Float* conv = new Float[rgs.Labels() + 1];
   for (Ulong r = 1; r <= rgs.Labels(); r++) {
      conv[r] = regions[r].convexite;
   }
   cold.SETARRAY(s, Float, conv + 1, rgs.Labels()); // Do not free conv...
   free(regions);
   
   return SUCCESS;
}

#ifdef MAIN

/*
 * Modify only the following constants, and the function call.
 */
#define USAGE	"usage: %s name [-m mask] [rg_in|-] [col_out|-]"
#define PARC	1
#define FINC	1
#define FOUTC	1
#define MASK	2

int main( int argc, char *argv[] ) {
   Errc result;              // The result code of the execution.
   Pobject* mask;            // The region mask.
   Pobject* objin[FINC+1];   // The input objects.
   Pobject* objs[FINC+1];    // The source objects masked by the mask.
   Pobject* objout[FOUTC+1]; // The output object.
   Pobject* objd[FOUTC+1];   // The result object of the execution.
   char* parv[PARC+1];       // The input parameters.
   
   ReadArgs(argc, argv, PARC, FINC, FOUTC, &mask, objin, objs, objout, objd, parv, USAGE, MASK);
   
   switch(objs[0]->Type()) {
   case Po_Reg2d : {
      Reg2d* const rgs = (Reg2d*)objs[0];
      objd[0] = new Collection();
      Collection* const cold = (Collection*)objd[0];
      
      result = PRegionConvexity(*rgs, *cold, argv[1]);
   } break;
   default :
      PrintErrorFormat(objin, FINC);
      result = FAILURE;
   }
   
   if (result) {
      WriteArgs(argc, argv, PARC, FINC, FOUTC, &mask, objin, objs, objout, objd, MASK);
   }
   
   Exit(result);
   return 0;
}

#endif