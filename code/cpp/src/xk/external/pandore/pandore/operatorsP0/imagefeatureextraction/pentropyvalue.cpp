/* -*- c-basic-offset: 3 ; mode: c++ -*-
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
 * @author Fran�ois Angot - 1995-02-08
 * @author R�gis Clouard - 1997-07-23
 * @author R�gis Clouard - 2005-12-05 (uses map instead of array for histogram)
 * @author R�gis Clouard - May 30, 2010 (add output vector).
 */

#include <math.h>
#include <pandore.h>
using namespace pandore;

/**
 * @file pentropyvalue.cpp
 *
 * Calculates the value of the total entropy of the image.
 * Entropy = SUM(Pi * log(Pi)) / log(2)
 * Pi=histo[i]/N;
 */
template <typename T>
Float PEntropyValue( const Imx3d<T> &ims, Collection &col_out ) {
   std::map<T,float> histo;
   Float *t = new Float[ims.Bands()];

   for (int b=0; b<ims.Bands(); b++ ) {
      T *ps=ims.Vector(b);
      const T *pf=ims.Vector(b)+ims.VectorSize();

      histo.clear();
      // Histogram
      for ( ; ps<pf ; ) {
	 histo[*(ps++)]++;
      }
      
      // Entropy
      Double sum=0.0;
      typename std::map<T,float>::const_iterator h;
      for (h=histo.begin() ; h != histo.end() ; h++) {
	 Double Pi= (double)h->second/ims.VectorSize();
	 sum += Pi * log(Pi);
      }
      t[b] = (Float)(-sum / log(2.0));
      col_out.SETARRAY("internal_array", Float, t, ims.Bands());
   }
   return t[0];
}



Double PEntropyValue( const Graph2d &grs, Collection &col_out ) {
   Float *t = new Float[1];
   int i,j;
   double sum,Pi;
   long nb, nbn;
   Long *histo;
   Double *node;

   sum=0.0;
   
   histo= new Long[grs.Size()];
   node= new Double[grs.Size()];
   for (i = 0; i < grs.Size(); histo[i++] = 0) ;

   // Histogram
   for (i=0, nbn=0, nb=0;i<grs.Size();i++) {
      if ((grs[i])) {
	 nbn++;
	 for (j=0; j<nb; j++) {
	    if (node[j]==grs[i]->value) {
	       break;
	    }
	 }
	 if (j==nb) {
	    nb++;
	 }
	 node[j]=grs[i]->value;
	 histo[j]++;
      }
   }
   for (j=0; j< nb; j++) {
      if (histo[j] > 0) {
	 Pi= (double)histo[j]/nbn;
	 sum += Pi * log(Pi);
      }
   }

   delete [] histo;
   delete [] node;

   t[0] = (Float)(-sum / log(2.0));
   col_out.SETARRAY("internal_array", Float, t, 1);

   return t[0];
}

Double PEntropyValue( const Graph3d &grs, Collection &col_out ) {
   Float *t = new Float[1];
   int i,j;
   double sum,Pi;
   long nb, nbn;
   Long *histo;
   Double *node;

   sum=0.0;
   
   histo= new Long[grs.Size()];
   node= new Double[grs.Size()];
   for (i = 0; i < grs.Size(); histo[i++] = 0) ;

   // Histogram
   for (i=0, nbn=0, nb=0;i<grs.Size();i++) {
      if ((grs[i])) {
	 nbn++;
	 for (j=0; j<nb; j++) {
	    if (node[j]==grs[i]->value) {
	       break;
	    }
	 }
	 if (j==nb) {
	    nb++;
	 }
	 node[j]=grs[i]->value;
	 histo[j]++;
      }
   }
   for (j=0; j< nb; j++) {
      if (histo[j] > 0) {
	 Pi= (double)histo[j]/nbn;
	 sum += Pi * log(Pi);
      }
   }

   delete [] histo;
   delete [] node;

   t[0] = (Float)(-sum / log(2.0));
   col_out.SETARRAY("internal_array", Float, t, 1);

   return t[0];
}


#ifdef MAIN
#define USAGE	"usage: %s [im_in|-] [col_out|-]"
#define PARC	0
#define FINC	1
#define FOUTC	1
#define MASK	0

int main( int argc, char *argv[] ) {
   Errc result;                // The result code of the execution.
   Pobject* mask;              // The region map.
   Pobject* objin[FINC + 1];   // The input objects.
   Pobject* objs[FINC + 1];    // The source objects masked.
   Pobject* objout[FOUTC + 1]; // The output object.
   Pobject* objd[FOUTC + 1];   // The result object of the execution.
   char* parv[PARC + 1];       // The input parameters.

   ReadArgs(argc, argv, PARC, FINC, FOUTC, &mask, objin, objs, objout, objd, parv, USAGE, MASK); 
   if (objs[0]->Type() == Po_Img1duc) {
      Img1duc* const ims=(Img1duc*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Img1dsl) {
      Img1dsl* const ims=(Img1dsl*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Img1dsf) {
      Img1dsf* const ims=(Img1dsf*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Img2duc) {
      Img2duc* const ims=(Img2duc*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Img2dsl) {
      Img2dsl* const ims=(Img2dsl*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Img2dsf) {
      Img2dsf* const ims=(Img2dsf*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Img3duc) {
      Img3duc* const ims=(Img3duc*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Img3dsl) {
      Img3dsl* const ims=(Img3dsl*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Img3dsf) {
      Img3dsf* const ims=(Img3dsf*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2duc) {
      Imc2duc* const ims=(Imc2duc*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2dsl) {
      Imc2dsl* const ims=(Imc2dsl*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2dsf) {
      Imc2dsf* const ims=(Imc2dsf*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3duc) {
      Imc3duc* const ims=(Imc3duc*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3dsl) {
      Imc3dsl* const ims=(Imc3dsl*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3dsf) {
      Imc3dsf* const ims=(Imc3dsf*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx1duc) {
      Imx1duc* const ims=(Imx1duc*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx1dsl) {
      Imx1dsl* const ims=(Imx1dsl*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx1dsf) {
      Imx1dsf* const ims=(Imx1dsf*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2duc) {
      Imx2duc* const ims=(Imx2duc*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2dsl) {
      Imx2dsl* const ims=(Imx2dsl*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2dsf) {
      Imx2dsf* const ims=(Imx2dsf*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3duc) {
      Imx3duc* const ims=(Imx3duc*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3dsl) {
      Imx3dsl* const ims=(Imx3dsl*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3dsf) {
      Imx3dsf* const ims=(Imx3dsf*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*ims, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Graph2d) {
      Graph2d* const grs=(Graph2d*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*grs, *cold);
      goto end;
   }
   if (objs[0]->Type() == Po_Graph3d) {
      Graph3d* const grs=(Graph3d*)objs[0];
      objd[0]=new Collection;
      Collection* const cold=(Collection*)objd[0];
      
      result= PEntropyValue(*grs, *cold);
      goto end;
   }
  {
     PrintErrorFormat(objin, FINC, argv); 
     result = FAILURE; 
  }	

end:
  if (result) {
	WriteArgs(argc, argv, PARC, FINC, FOUTC, &mask, objin, objs, objout, objd, MASK); 
  }
  Exit(result); 
  return 0; 
}
#endif
