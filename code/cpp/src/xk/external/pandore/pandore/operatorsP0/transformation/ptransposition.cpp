/* -*- c-basic-offset: 3; mode: c++ -*-
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
 * @author R�gis Clouard - 2001-08-01
 * @author R�gis Clouard - 2004-07-30 (type completion)
 */

#include <pandore.h>
using namespace pandore;

/**
 * @file ptransposition.cpp
 * @brief Transpose an image where row becomes columns, etc.
 */












Errc PTransposition( const Img2duc &ims, Img2duc &imd, int /*direction */) {
   Point2d p;
   
   imd.New(ims.Width(), ims.Height());

   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(p.x, p.y) = ims[p];
      }
   return SUCCESS;
}

Errc PTransposition( const Img2dsl &ims, Img2dsl &imd, int /*direction */) {
   Point2d p;
   
   imd.New(ims.Width(), ims.Height());

   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(p.x, p.y) = ims[p];
      }
   return SUCCESS;
}

Errc PTransposition( const Img2dsf &ims, Img2dsf &imd, int /*direction */) {
   Point2d p;
   
   imd.New(ims.Width(), ims.Height());

   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(p.x, p.y) = ims[p];
      }
   return SUCCESS;
}

Errc PTransposition( const Img3duc &ims, Img3duc &imd, int direction ) {
  Point3d p;
  
  switch(direction ) {
  case 0 :
   imd.New(ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.z, p.x, p.y) = ims[p];
     }
     break;
  case 1 :
   imd.New(ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.x, p.y, p.z) = ims[p];
     }
     break;
  case 2 :
   imd.New(ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.y, p.z, p.x) = ims[p];
     }
     break;
  default: return FAILURE;
  }
  
  return SUCCESS;
}

Errc PTransposition( const Img3dsl &ims, Img3dsl &imd, int direction ) {
  Point3d p;
  
  switch(direction ) {
  case 0 :
   imd.New(ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.z, p.x, p.y) = ims[p];
     }
     break;
  case 1 :
   imd.New(ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.x, p.y, p.z) = ims[p];
     }
     break;
  case 2 :
   imd.New(ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.y, p.z, p.x) = ims[p];
     }
     break;
  default: return FAILURE;
  }
  
  return SUCCESS;
}

Errc PTransposition( const Img3dsf &ims, Img3dsf &imd, int direction ) {
  Point3d p;
  
  switch(direction ) {
  case 0 :
   imd.New(ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.z, p.x, p.y) = ims[p];
     }
     break;
  case 1 :
   imd.New(ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.x, p.y, p.z) = ims[p];
     }
     break;
  case 2 :
   imd.New(ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
     {
	imd(p.y, p.z, p.x) = ims[p];
     }
     break;
  default: return FAILURE;
  }
  
  return SUCCESS;
}


Errc PTransposition( const Imc2duc &ims, Imc2duc &imd, int /* direction */ ) {
   Point2d p;
   
   imd.ColorSpace(ims.ColorSpace());
   imd.New(ims.Width(), ims.Height());
   
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.x, p.y) = ims(0, p);
	 imd(1, p.x, p.y) = ims(1, p);
	 imd(2, p.x, p.y) = ims(2, p);
      }

   return SUCCESS;
}

Errc PTransposition( const Imc2dsl &ims, Imc2dsl &imd, int /* direction */ ) {
   Point2d p;
   
   imd.ColorSpace(ims.ColorSpace());
   imd.New(ims.Width(), ims.Height());
   
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.x, p.y) = ims(0, p);
	 imd(1, p.x, p.y) = ims(1, p);
	 imd(2, p.x, p.y) = ims(2, p);
      }

   return SUCCESS;
}

Errc PTransposition( const Imc2dsf &ims, Imc2dsf &imd, int /* direction */ ) {
   Point2d p;
   
   imd.ColorSpace(ims.ColorSpace());
   imd.New(ims.Width(), ims.Height());
   
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.x, p.y) = ims(0, p);
	 imd(1, p.x, p.y) = ims(1, p);
	 imd(2, p.x, p.y) = ims(2, p);
      }

   return SUCCESS;
}

Errc PTransposition( const Imc3duc &ims, Imc3duc &imd, int direction ) {
   Point3d p;
  
   imd.ColorSpace(ims.ColorSpace());
   switch(direction ) {
   case 0 :
   imd.New(ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.z, p.x, p.y) = ims(0, p);
	 imd(1, p.z, p.x, p.y) = ims(1, p);
	 imd(2, p.z, p.x, p.y) = ims(2, p);
      }
      break;
   case 1 :
   imd.New(ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.x, p.y, p.z) = ims(0, p);
	 imd(1, p.x, p.y, p.z) = ims(1, p);
	 imd(2, p.x, p.y, p.z) = ims(2, p);	 
      }
      break;
   case 2 :
      imd.New(ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.y, p.z, p.x) = ims(0, p);
	 imd(1, p.y, p.z, p.x) = ims(1, p);
	 imd(2, p.y, p.z, p.x) = ims(2, p);
      }
      break;
   default: return FAILURE;
   }
   
   return SUCCESS;
}

Errc PTransposition( const Imc3dsl &ims, Imc3dsl &imd, int direction ) {
   Point3d p;
  
   imd.ColorSpace(ims.ColorSpace());
   switch(direction ) {
   case 0 :
   imd.New(ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.z, p.x, p.y) = ims(0, p);
	 imd(1, p.z, p.x, p.y) = ims(1, p);
	 imd(2, p.z, p.x, p.y) = ims(2, p);
      }
      break;
   case 1 :
   imd.New(ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.x, p.y, p.z) = ims(0, p);
	 imd(1, p.x, p.y, p.z) = ims(1, p);
	 imd(2, p.x, p.y, p.z) = ims(2, p);	 
      }
      break;
   case 2 :
      imd.New(ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.y, p.z, p.x) = ims(0, p);
	 imd(1, p.y, p.z, p.x) = ims(1, p);
	 imd(2, p.y, p.z, p.x) = ims(2, p);
      }
      break;
   default: return FAILURE;
   }
   
   return SUCCESS;
}

Errc PTransposition( const Imc3dsf &ims, Imc3dsf &imd, int direction ) {
   Point3d p;
  
   imd.ColorSpace(ims.ColorSpace());
   switch(direction ) {
   case 0 :
   imd.New(ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.z, p.x, p.y) = ims(0, p);
	 imd(1, p.z, p.x, p.y) = ims(1, p);
	 imd(2, p.z, p.x, p.y) = ims(2, p);
      }
      break;
   case 1 :
   imd.New(ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.x, p.y, p.z) = ims(0, p);
	 imd(1, p.x, p.y, p.z) = ims(1, p);
	 imd(2, p.x, p.y, p.z) = ims(2, p);	 
      }
      break;
   case 2 :
      imd.New(ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 imd(0, p.y, p.z, p.x) = ims(0, p);
	 imd(1, p.y, p.z, p.x) = ims(1, p);
	 imd(2, p.y, p.z, p.x) = ims(2, p);
      }
      break;
   default: return FAILURE;
   }
   
   return SUCCESS;
}


Errc PTransposition( const Imx2duc &ims, Imx2duc &imd, int /* direction*/ ) {
   Point2d p;
   
   imd.New(ims.Bands(), ims.Width(), ims.Height());
   
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      for (int b = 0; b < ims.Bands(); b++) {
	 imd(b, p.x, p.y) = ims(b, p.y, p.x);
      }
   }
   
   return SUCCESS;
}

Errc PTransposition( const Imx2dsl &ims, Imx2dsl &imd, int /* direction*/ ) {
   Point2d p;
   
   imd.New(ims.Bands(), ims.Width(), ims.Height());
   
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      for (int b = 0; b < ims.Bands(); b++) {
	 imd(b, p.x, p.y) = ims(b, p.y, p.x);
      }
   }
   
   return SUCCESS;
}

Errc PTransposition( const Imx2dsf &ims, Imx2dsf &imd, int /* direction*/ ) {
   Point2d p;
   
   imd.New(ims.Bands(), ims.Width(), ims.Height());
   
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      for (int b = 0; b < ims.Bands(); b++) {
	 imd(b, p.x, p.y) = ims(b, p.y, p.x);
      }
   }
   
   return SUCCESS;
}

Errc PTransposition( const Imx3duc &ims, Imx3duc &imd, int direction ) {
   Point3d p;
  
   switch(direction ) {
   case 0 :
   imd.New(ims.Bands(), ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.z, p.x, p.y) = ims(b, p);
	 }
      }
      break;
   case 1 :
   imd.New(ims.Bands(), ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.x, p.y, p.z) = ims(b, p);
	 }
      }
      break;
   case 2 :
   imd.New(ims.Bands(), ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.y, p.z, p.x) = ims(b, p);
	 }
      }
      break;
   default: return FAILURE;
   }
   
   return SUCCESS;
}

Errc PTransposition( const Imx3dsl &ims, Imx3dsl &imd, int direction ) {
   Point3d p;
  
   switch(direction ) {
   case 0 :
   imd.New(ims.Bands(), ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.z, p.x, p.y) = ims(b, p);
	 }
      }
      break;
   case 1 :
   imd.New(ims.Bands(), ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.x, p.y, p.z) = ims(b, p);
	 }
      }
      break;
   case 2 :
   imd.New(ims.Bands(), ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.y, p.z, p.x) = ims(b, p);
	 }
      }
      break;
   default: return FAILURE;
   }
   
   return SUCCESS;
}

Errc PTransposition( const Imx3dsf &ims, Imx3dsf &imd, int direction ) {
   Point3d p;
  
   switch(direction ) {
   case 0 :
   imd.New(ims.Bands(), ims.Depth(), ims.Width(), ims.Height());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.z, p.x, p.y) = ims(b, p);
	 }
      }
      break;
   case 1 :
   imd.New(ims.Bands(), ims.Width(), ims.Height(), ims.Depth());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.x, p.y, p.z) = ims(b, p);
	 }
      }
      break;
   case 2 :
   imd.New(ims.Bands(), ims.Height(), ims.Depth(), ims.Width());
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
      {
	 for (int b = 0; b < ims.Bands(); b++) {
	    imd(b, p.y, p.z, p.x) = ims(b, p);
	 }
      }
      break;
   default: return FAILURE;
   }
   
   return SUCCESS;
}


Errc PTransposition( const Reg2d &rgs, Reg2d &rgd, int /* direction */ ) {
   Point2d p;
   
   rgd.New(rgs.Width(), rgs.Height());
   rgd.Labels(rgs.Labels());

   for (p.y = 0; p.y < rgs.Height(); p.y++)
   for (p.x = 0; p.x < rgs.Width(); p.x++)
      {
	 rgd(p.x, p.y) = rgs(p.y, p.x);
      }
   return SUCCESS;
}

Errc PTransposition( const Reg3d &rgs, Reg3d &rgd, int direction ) {
  Point3d p;
  
  switch(direction) {
  case 0 :
   rgd.New(rgs.Depth(), rgs.Width(), rgs.Height());
   for (p.z = 0; p.z < rgs.Depth(); p.z++)
   for (p.y = 0; p.y < rgs.Height(); p.y++)
   for (p.x = 0; p.x < rgs.Width(); p.x++)
     {
	rgd(p.z, p.x, p.y) = rgs[p];
     }
     break;
  case 1 :
   rgd.New(rgs.Width(), rgs.Height(), rgs.Depth());
   for (p.z = 0; p.z < rgs.Depth(); p.z++)
   for (p.y = 0; p.y < rgs.Height(); p.y++)
   for (p.x = 0; p.x < rgs.Width(); p.x++)
     {
	rgd(p.x, p.y, p.z) = rgs[p];
     }
     break;
  case 2 :
   rgd.New(rgs.Height(), rgs.Depth(), rgs.Width());
   for (p.z = 0; p.z < rgs.Depth(); p.z++)
   for (p.y = 0; p.y < rgs.Height(); p.y++)
   for (p.x = 0; p.x < rgs.Width(); p.x++)
     {
	rgd(p.y, p.z, p.x) = rgs[p];
     }
     break;
  default: return FAILURE;
  }
  rgd.Labels(rgs.Labels());

  return SUCCESS;
}


#ifdef MAIN
#define	USAGE	"usage: %s direction [im_in|-] [im_out|-]"
#define	PARC	1
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
      Img2duc* const ims = (Img2duc*)objs[0];
      objd[0] = new Img2duc;
      Img2duc* const imd = (Img2duc*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img2dsl) {
      Img2dsl* const ims = (Img2dsl*)objs[0];
      objd[0] = new Img2dsl;
      Img2dsl* const imd = (Img2dsl*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img2dsf) {
      Img2dsf* const ims = (Img2dsf*)objs[0];
      objd[0] = new Img2dsf;
      Img2dsf* const imd = (Img2dsf*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img3duc) {
      Img3duc* const ims = (Img3duc*)objs[0];
      objd[0] = new Img3duc;
      Img3duc* const imd = (Img3duc*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img3dsl) {
      Img3dsl* const ims = (Img3dsl*)objs[0];
      objd[0] = new Img3dsl;
      Img3dsl* const imd = (Img3dsl*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img3dsf) {
      Img3dsf* const ims = (Img3dsf*)objs[0];
      objd[0] = new Img3dsf;
      Img3dsf* const imd = (Img3dsf*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2duc) {
      Imc2duc* const ims = (Imc2duc*)objs[0];
      objd[0] = new Imc2duc;
      Imc2duc* const imd = (Imc2duc*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2dsl) {
      Imc2dsl* const ims = (Imc2dsl*)objs[0];
      objd[0] = new Imc2dsl;
      Imc2dsl* const imd = (Imc2dsl*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2dsf) {
      Imc2dsf* const ims = (Imc2dsf*)objs[0];
      objd[0] = new Imc2dsf;
      Imc2dsf* const imd = (Imc2dsf*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3duc) {
      Imc3duc* const ims = (Imc3duc*)objs[0];
      objd[0] = new Imc3duc;
      Imc3duc* const imd = (Imc3duc*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3dsl) {
      Imc3dsl* const ims = (Imc3dsl*)objs[0];
      objd[0] = new Imc3dsl;
      Imc3dsl* const imd = (Imc3dsl*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3dsf) {
      Imc3dsf* const ims = (Imc3dsf*)objs[0];
      objd[0] = new Imc3dsf;
      Imc3dsf* const imd = (Imc3dsf*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2duc) {
      Imx2duc* const ims = (Imx2duc*)objs[0];
      objd[0] = new Imx2duc;
      Imx2duc* const imd = (Imx2duc*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2dsl) {
      Imx2dsl* const ims = (Imx2dsl*)objs[0];
      objd[0] = new Imx2dsl;
      Imx2dsl* const imd = (Imx2dsl*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2dsf) {
      Imx2dsf* const ims = (Imx2dsf*)objs[0];
      objd[0] = new Imx2dsf;
      Imx2dsf* const imd = (Imx2dsf*)objd[0];
      
      result = PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3duc) {
      Imx3duc* const ims = (Imx3duc*)objs[0];
      objd[0] = new Imx3duc;
      Imx3duc* const imd = (Imx3duc*)objd[0];
      
      result=PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3dsl) {
      Imx3dsl* const ims = (Imx3dsl*)objs[0];
      objd[0] = new Imx3dsl;
      Imx3dsl* const imd = (Imx3dsl*)objd[0];
      
      result=PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3dsf) {
      Imx3dsf* const ims = (Imx3dsf*)objs[0];
      objd[0] = new Imx3dsf;
      Imx3dsf* const imd = (Imx3dsf*)objd[0];
      
      result=PTransposition(*ims, *imd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Reg2d) {
      Reg2d* const rgs = (Reg2d*)objs[0];
      objd[0] = new Reg2d;
      Reg2d* const rgd = (Reg2d*)objd[0];
      
      result = PTransposition(*rgs, *rgd, (Uchar)atoi(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Reg3d) {
      Reg3d* const rgs = (Reg3d*)objs[0];
      objd[0] = new Reg3d;
      Reg3d* const rgd = (Reg3d*)objd[0];
      
      result = PTransposition(*rgs, *rgd, (Uchar)atoi(parv[0]));
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
