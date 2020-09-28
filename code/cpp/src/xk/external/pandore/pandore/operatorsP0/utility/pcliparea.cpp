/* -*- mode: c++; c-basic-offset: 3 -*-
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
 * R�gis Clouard - 2006-12-04
 */

#include <math.h>
#include <pandore.h>
using namespace pandore; 

//#define DEBUG 

/**
 * @file pcliparea.cpp
 * Clip the image area specified by the cordinates.
 * It consists in a masking operation of the values outside
 * the clip area.
 */

/**
 * @param zmin, ymin, xmin, , zmax, ymax, xmax defines the cordinates the clip rectangle.
 */
template <typename T>
Errc PClipArea( const Imx3d<T> &ims, Imx3d<T> &imd, const int zclip, const int yclip, const int xclip, int dclip, int hclip, int wclip) {
   
#ifdef DEBUG  
   printf("cordinates = (x=%d,y=%d,z=%d) et size = (w=%d,h=%d,d=%d)\n",xclip,yclip,zclip, wclip,hclip,dclip);
#endif
   
   if (zclip<0 || yclip<0 || xclip<0 ) {
      fprintf(stderr,"Error pcliparea: Bad parameter values %d %d %d %d %d %d\n", xclip, yclip, zclip, wclip, hclip, dclip) ;
      return FAILURE;
   }

   int zend = zclip+dclip;
   int yend = yclip+hclip;
   int xend = xclip+wclip;

   if (dclip < 1 || zend>ims.Depth()) zend = ims.Depth();
   if (hclip < 1 || yend>ims.Height()) yend = ims.Height();
   if (wclip < 1 || xend>ims.Width()) xend = ims.Width();
   
   imd=0;
#ifdef DEBUG  
   printf("z : %d -> %d\n",zclip,zend);
   printf("y : %d -> %d\n",yclip,yend);
   printf("x : %d -> %d\n",xclip,xend);
#endif
   for (int b=0;b<ims.Bands(); b++)
      for (int z=zclip; z<zend; z++)
	 for (int y=yclip; y<yend; y++)
	    for (int x=xclip; x<xend; x++) {
	       imd[b][z][y][x] = ims[b][z][y][x];
	    }
   return SUCCESS;
}



#ifdef MAIN
#define	USAGE	"usage: %s x y z width height depth [im_in|-] [im_out|-]"
#define	PARC	6
#define	FINC	1
#define	FOUTC	1
#define	MASK	0

int main( int argc, char *argv[] ) {
   Errc result;                // The result code of the execution.
   Pobject* mask;              // The region map.
   Pobject* objin[FINC + 1];   // The input objects.
   Pobject* objs[FINC + 1];    // The source objects masked.
   Pobject* objout[FOUTC + 1]; // The output object.
   Pobject* objd[FOUTC + 1];   // The result object of the execution.
   char* parv[PARC + 1];       // The input parameters.

   ReadArgs(argc, argv, PARC, FINC, FOUTC, &mask, objin, objs, objout, objd, parv, USAGE, MASK); 
   if (objs[0]->Type() == Po_Img2duc) {
      Img2duc* const ims=(Img2duc*)objs[0];
      objd[0]=new Img2duc(ims->Props());
      Img2duc* const imd=(Img2duc*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Img2dsl) {
      Img2dsl* const ims=(Img2dsl*)objs[0];
      objd[0]=new Img2dsl(ims->Props());
      Img2dsl* const imd=(Img2dsl*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Img2dsf) {
      Img2dsf* const ims=(Img2dsf*)objs[0];
      objd[0]=new Img2dsf(ims->Props());
      Img2dsf* const imd=(Img2dsf*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Img3duc) {
      Img3duc* const ims=(Img3duc*)objs[0];
      objd[0]=new Img3duc(ims->Props());
      Img3duc* const imd=(Img3duc*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Img3dsl) {
      Img3dsl* const ims=(Img3dsl*)objs[0];
      objd[0]=new Img3dsl(ims->Props());
      Img3dsl* const imd=(Img3dsl*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Img3dsf) {
      Img3dsf* const ims=(Img3dsf*)objs[0];
      objd[0]=new Img3dsf(ims->Props());
      Img3dsf* const imd=(Img3dsf*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imc2duc) {
      Imc2duc* const ims=(Imc2duc*)objs[0];
      objd[0]=new Imc2duc(ims->Props());
      Imc2duc* const imd=(Imc2duc*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imc2dsl) {
      Imc2dsl* const ims=(Imc2dsl*)objs[0];
      objd[0]=new Imc2dsl(ims->Props());
      Imc2dsl* const imd=(Imc2dsl*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imc2dsf) {
      Imc2dsf* const ims=(Imc2dsf*)objs[0];
      objd[0]=new Imc2dsf(ims->Props());
      Imc2dsf* const imd=(Imc2dsf*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imc3duc) {
      Imc3duc* const ims=(Imc3duc*)objs[0];
      objd[0]=new Imc3duc(ims->Props());
      Imc3duc* const imd=(Imc3duc*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imc3dsl) {
      Imc3dsl* const ims=(Imc3dsl*)objs[0];
      objd[0]=new Imc3dsl(ims->Props());
      Imc3dsl* const imd=(Imc3dsl*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imc3dsf) {
      Imc3dsf* const ims=(Imc3dsf*)objs[0];
      objd[0]=new Imc3dsf(ims->Props());
      Imc3dsf* const imd=(Imc3dsf*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imx2duc) {
      Imx2duc* const ims=(Imx2duc*)objs[0];
      objd[0]=new Imx2duc(ims->Props());
      Imx2duc* const imd=(Imx2duc*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imx2dsl) {
      Imx2dsl* const ims=(Imx2dsl*)objs[0];
      objd[0]=new Imx2dsl(ims->Props());
      Imx2dsl* const imd=(Imx2dsl*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imx2dsf) {
      Imx2dsf* const ims=(Imx2dsf*)objs[0];
      objd[0]=new Imx2dsf(ims->Props());
      Imx2dsf* const imd=(Imx2dsf*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imx3duc) {
      Imx3duc* const ims=(Imx3duc*)objs[0];
      objd[0]=new Imx3duc(ims->Props());
      Imx3duc* const imd=(Imx3duc*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imx3dsl) {
      Imx3dsl* const ims=(Imx3dsl*)objs[0];
      objd[0]=new Imx3dsl(ims->Props());
      Imx3dsl* const imd=(Imx3dsl*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
      goto end;
   }

   if (objs[0]->Type() == Po_Imx3dsf) {
      Imx3dsf* const ims=(Imx3dsf*)objs[0];
      objd[0]=new Imx3dsf(ims->Props());
      Imx3dsf* const imd=(Imx3dsf*)objd[0];

      result=PClipArea(*ims,*imd,
		       atoi(parv[2]),atoi(parv[1]),atoi(parv[0]),
		       atoi(parv[5]),atoi(parv[4]),atoi(parv[3]));
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
