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
 * @author R�gis Clouard - 1996-02-19
 * @author Francois Angot - 1996-08-05
 * @author Olivier Lezoray - 1996-09-30
 * @author Regis Clouard - 2003-05-22 (new algorithm)
 * @author Regis Clouard - Jun 19, 2011 (new algorithm)
 * @author Alexis Fran�ois - Nov 03, 2012 (speed up for square structuring element).
 */

#define _USE_MATH_DEFINES
#include <math.h>
#include <pandore.h>
using namespace pandore;
#include "morphology/structelt.h"

/**
 * @file perosion.cpp
 * Morphological erosion.
 * numSE: Structuring Element index between
 * halfsize : halfsize of the structuring element.
 */

template < typename T>
Errc PErosionGeneral( const Imx2d < T> &ims, Imx2d < T> &imd, int numSE, int halfsize ) {
   if (numSE > 9 || numSE < 0) {
      std::cerr << "Error perosion: bad structuring element type: " << numSE << std::endl;
      return FAILURE;
   }
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   StructuringElement2d *se = new StructuringElement2d(numSE, halfsize);

   Point2d p, p1;
   for (int b = 0; b < ims.Bands(); b++) {
      for (p.y = 0; p.y < ims.Height(); p.y++) {
	 for (p.x = 0; p.x < ims.Width(); p.x++) {
	    T min=Limits < T>::max(), val;
	    for (int i = 0; i < se->length; i++) {
 	       p1 = p;
 	       se->Move(i, p1);

	       if (ims.Hold(p1) && ((val = ims[b][p1]) < min)) {
		  min = val;
	       }
	    }
	    imd[b][p] = min;
	 }
      }
   }
   delete se;
   return SUCCESS;
}

////// Alexis extension
template < typename T>
void dxFastErosionVertical( const pandore::Imx2d < T>& ims, pandore::Imx2d < T>& imd, int halfsize ) {
    const Long height_1 = ims.Height() - 1;
    const Long width = ims.Width();
    
    // Using structuring element 1x2 :
    // X
    // X
    const Imx2d < T> *ims_ptr = reinterpret_cast<const pandore::Imx2d < T>*>(&ims);
    Imx2d < T> imt;
    bool write = false;

    for (int b = 0; b < ims.Bands(); b++) {
       for (int hs = 0; hs < halfsize; ++hs ) {
	  for (int x=0;  x < width; ++x) {
	     T p2 = (*ims_ptr)(b, 0, x);
	     for (int y = 0; y < height_1; ++y) {
                T p1 = p2;
                p2 = (*ims_ptr)(b, y + 1, x);
                if (p1 != p2) { // If they are different, set the lower value to the higher pixel
		   if (p1 < p2) {
		      imd(b, y + 1, x) = p1;
		      write = true;
		   } else {
		      if (write) { // If the pixel have already been set
			 if (p2 < imd(b, y, x)) { // Test if the new value is higher
			    imd(b, y, x) = p2; // Set the pixel with the new value
			 }
			 write = false;
		      } else { // If the pixel is not set
			 imd(b, y, x) = p2;
		      }
		   }
                }
	     }
	  }
	  if (hs != halfsize - 1) {
	     imt = imd;
	     ims_ptr = &imt;
	  }
       }
    }
}

template < typename T>
void dxFastErosionHorizontal( const pandore::Imx2d < T>& ims, pandore::Imx2d < T>& imd, int halfsize ) {
    const Long height = ims.Height();
    const Long width_1 = ims.Width() - 1;

    // Using structuring element 2x1 :
    // X X
    const Imx2d < T> *ims_ptr = reinterpret_cast<const pandore::Imx2d < T>*>(&ims);
    Imx2d < T> imt;
    bool write = false;
    
    for (int b = 0; b < ims.Bands(); b++) {
       for (int hs = 0; hs < halfsize; ++hs ) {
	  for (int y = 0; y < height; ++y) {
	     T p2 = (*ims_ptr)(b, y, 0);
	     for (int x = 0; x < width_1; ++x) {
                T p1 = p2;
                p2 = (*ims_ptr)(b, y, x + 1);
                if (p1 != p2) {
		   if (p1 < p2) {
		      imd(b, y, x + 1) = p1;
		      write = true;
		   } else {
		      if (write) {
			 if (p2 < imd(b, y, x)) { // Test if the new value is highter
			    imd(b, y, x) = p2; // Set the pixel with the new value
			 }
			 write = false;
		      } else {
			 imd(b, y, x) = p2;
		      }
		   }
                }
	     }
	  }
	  if (hs != halfsize - 1) {
	     imt = imd;
	     ims_ptr = &imt;
	  }
       }
    }
}

/**
 * Fast erosion for square structuring element
 */
template < typename T>
void dxFastErosion8( const Imx2d < T>& ims, Imx2d < T>& imd, int halfsize ) {
    Imx2d < T> imt(ims);
    dxFastErosionVertical(ims, imt, halfsize);
    imd = imt;
    dxFastErosionHorizontal(imt, imd, halfsize);
}

template < typename T>
void dxFastErosionVertical( const pandore::Imx3d < T>& ims, pandore::Imx3d < T>& imd, int halfsize ) {
    const Long height_1 = ims.Height() - 1;
    const Long width = ims.Width();
    const Long depth = ims.Depth();

    bool write = false;    
    Imx3d < T> imt;
    const Imx3d < T> *ims_ptr = reinterpret_cast<const pandore::Imx3d < T>*>(&ims);

    for (int b = 0; b < ims.Bands(); b++) {
       for (int hs = 0; hs < halfsize; ++hs ) {
	  for (int z = 0; z < depth; ++z) {
	     for (int x = 0; x < width; ++x) {
		T p2 = (*ims_ptr)(b, z, 0, x);
		for (int y = 0; y < height_1; ++y) {
		   T p1 = p2;
		   p2 = (*ims_ptr)(b, z, y + 1, x);
		   if (p1 != p2) { // If they are different, set the lower value to the higher pixel
		      if (p1 < p2) {
			 imd(b, z, y + 1, x) = p1;
			 write = true;
		      } else {
			 if (write) { // If the pixel have already been set
			    if (p2 < imd(b, z, y, x)) { // Test if the new value is higher
			       imd(b, z, y, x) = p2; // Set the pixel with the new value
			    }
			    write = false;
			 } else { // If the pixel is not set
			    imd(b, z, y, x) = p2;
			 }
		      }
		   }
		}
	     }
	  }
	  if (hs != halfsize - 1) {
	     imt = imd;
	     ims_ptr = &imt;
	  }
       }
    }
}

template < typename T>
void dxFastErosionHorizontal( const pandore::Imx3d < T>& ims, pandore::Imx3d < T>& imd, int halfsize ) {
    const Long depth = ims.Depth();
    const Long height = ims.Height();
    const Long width_1 = ims.Width() - 1;

    bool write = false;
    const Imx3d < T> *ims_ptr = reinterpret_cast<const pandore::Imx3d < T>*>(&ims);
    Imx3d < T> imt;
    
    for (int b = 0; b < ims.Bands(); b++) {
       for (int hs = 0; hs < halfsize; ++hs ) {
	  for (int z = 0; z < depth; ++z) {
	     for (int y = 0; y < height; ++y) {
		T p2 = (*ims_ptr)(b, z, y, 0);
		for (int x = 0; x < width_1; ++x) {
		   T p1 = p2;
		   p2 = (*ims_ptr)(b, z, y, x + 1);
		   if (p1 != p2) {
		      if (p1 < p2) {
			 imd(b, z, y, x + 1) = p1;
			 write = true;
		      } else {
			 if (write) {
			    if (p2 < imd(b, z, y, x)) { // Test if the new value is highter
			       imd(b, z, y, x) = p2; // Set the pixel with the new value
			    }
			    write = false;
			 } else {
			    imd(b, z, y, x) = p2;
			 }
		      }
		   }
		}
	     }
	  }
	  if (hs != halfsize - 1) {
	     imt = imd;
	     ims_ptr = &imt;
	  }
       }
    }
}

template < typename T>
void dxFastErosionDepth( const pandore::Imx3d < T>& ims, pandore::Imx3d < T>& imd, int halfsize ) {
    const Long depth_1 = ims.Depth() - 1;
    const Long height = ims.Height();
    const Long width = ims.Width();

    bool write = false;
    Imx3d < T> imt;
    const Imx3d < T> *ims_ptr = reinterpret_cast<const pandore::Imx2d < T>*>(&ims);
    
    for (int b = 0; b < ims.Bands(); b++) {
       for (int hs = 0; hs < halfsize; ++hs ) {
	  for (int y = 0; y < height; ++y) {
	     for (int x = 0; x < width; ++x) {
		T p2 = (*ims_ptr)(b, 0, y, x);
		for (int z = 0; z < depth_1; ++z) {
		   T p1 = p2;
		   p2 = (*ims_ptr)(b, z + 1, y, x);
		   if (p1 != p2) {
		      if (p1 < p2) {
			 imd(b, z + 1, y, x) = p1;
			 write = true;
		      } else {
			 if (write) {
			    if (p2 < imd(b, z, y, x)) { // Test if the new value is highter
			       imd(b, z, y, x) = p2; // Set the pixel with the new value
			    }
			    write = false;
			 } else {
			    imd(b, z, y, x) = p2;
			 }
		      }
		   }
		}
	     }
	  }
	  if (hs != halfsize - 1) {
	     imt = imd;
	     ims_ptr = &imt;
	  }
       }
    }
}

/**
 * Fast erosion for square structuring element.
 */
template < typename T>
void dxFastErosion26( const Imx3d < T>& ims, Imx3d < T>& imd, int halfsize ) {
   imd = ims;
   dxFastErosionVertical(ims, imd, halfsize);
   Imx3d < T> imt(imd);
   dxFastErosionHorizontal(imd, imt, halfsize);
   imd = imt;
   dxFastErosionDepth(imt, imd, halfsize);
}
/////////

template < typename T>
Errc PErosion( const Imx2d < T> &ims, Imx2d < T> &imd, int numSE, int halfsize ) {
   if (numSE == 1) {
      dxFastErosion8(ims, imd, halfsize);
      return SUCCESS;
   }
   return PErosionGeneral(ims, imd, numSE, halfsize);
}


template < typename T>
Errc PErosion( const Imx3d < T> &ims, Imx3d < T> &imd, int numSE, int halfsize ) {
   if (numSE > 12 || numSE < 0) {
      std::cerr << "Error perosion: bad structuring element type: " << numSE << std::endl;
      return FAILURE;
   }
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   if (numSE == 1) {
      dxFastErosion26(ims, imd, halfsize);
      return SUCCESS;
   }

   StructuringElement3d *se = new StructuringElement3d(numSE, halfsize);

   Point3d p, p1;
   for (int b = 0; b < ims.Bands(); b++) {
      for (p.z = 0; p.z < ims.Depth(); p.z++) {
	 for (p.y = 0; p.y < ims.Height(); p.y++) {
	    for (p.x = 0; p.x < ims.Width(); p.x++) {
	       T min = Limits < T>::max(), val;
	       for (int i = 0; i < se->length; i++) {
 	          p1 = p;
 	          se->Move(i, p1);
		  if (ims.Hold(p1) && ((val = ims(b, p1)) < min)) {
		     min = val;
		  }
	       }
	       imd(b, p) = min;
	    }
	 }
      }
   }
   
   delete se;
   return SUCCESS;
}


#ifndef __LOWER_H__
#define __LOWER_H__
/*
 * Lexicographic order between 2 colors (cx, cy, cz) and (cx1, cy1, cz1)
 */
template < typename T>
static bool Lower( T cx1, T cy1, T cz1, T cx, T cy, T cz ) {
    if (cx1 < cx) {
       return true;
    } else if (cx1 > cx) {
	return false;
    }
    if (cy1 < cy) {
	return true;
    } else if (cy1 > cy) {
	return false;
    }
    if (cz1 < cz) {
       return true;
    } else if (cz1 > cz) {
	return false;
    } else {
	return false;
    }
}

#endif

template < typename T>
Errc PErosion( const Imc2d < T> &ims, Imc2d < T> &imd, int numSE, int halfsize ) {
   if (numSE > 9 || numSE < 0) {
      std::cerr << "Error perosion: bad structuring element type: " << numSE << std::endl;
      return FAILURE;
   }
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   StructuringElement2d *se = new StructuringElement2d(numSE, halfsize);
   Point2d p, p1;
   for (p.y = 0; p.y < ims.Height(); p.y++) {
      for (p.x = 0; p.x < ims.Width(); p.x++) {
 	 T minX = Limits < T>::max();
 	 T minY = Limits < T>::max();
 	 T minZ = Limits < T>::max();
	 for (int i = 0; i < se->length; i++) {
 	    p1 = p;
 	    se->Move(i, p1);
	    if (ims.Hold(p1) && Lower(ims.X[p1], ims.Y[p1], ims.Z[p1], minX, minY, minZ)) {
	       minX = ims.X[p1];
	       minY = ims.Y[p1];
	       minZ = ims.Z[p1];
	    }
	 }
	 imd.X[p] = minX;
	 imd.Y[p] = minY;
	 imd.Z[p] = minZ;
      }
   }

   delete se;
   return SUCCESS;
}


template < typename T>
Errc PErosion( const Imc3d < T> &ims, Imc3d < T> &imd, int numSE, int halfsize ) {
   if (numSE > 12 || numSE < 0) {
      std::cerr << "Error perosion: bad structuring element type: " << numSE << std::endl;
      return FAILURE;
   }
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   StructuringElement3d *se = new StructuringElement3d(numSE, halfsize);

   Point3d p, p1;
   for (p.z = 0; p.z < ims.Depth(); p.z++) {
      for (p.y = 0; p.y < ims.Height(); p.y++) {
	 for (p.x = 0; p.x < ims.Width(); p.x++) {
	    T minX=Limits < T>::max();
	    T minY=Limits < T>::max();
	    T minZ=Limits < T>::max();
	    for (int i = 0; i < se->length; i++) {
 	       p1 = p;
 	       se->Move(i, p1);
	       if (ims.Hold(p1) && Lower(ims.X[p1], ims.Y[p1], ims.Z[p1], minX, minY, minZ)) {
		  minX = ims.X[p1];
		  minY = ims.Y[p1];
		  minZ = ims.Z[p1];
	       }
	    }
	    imd.X[p] = minX;
	    imd.Y[p] = minY;
	    imd.Z[p] = minZ;
	 }
      }
   }

   delete se;
   return SUCCESS;
}


Errc PErosion( const Reg2d &ims, Reg2d &imd, int numSE, int halfsize ) {
   if (numSE > 9 || numSE < 0) {
      std::cerr << "Error perosion: bad structuring element type: " << numSE << std::endl;
      return FAILURE;
   }
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   StructuringElement2d *se = new StructuringElement2d(numSE, halfsize);

   Point2d p, p1;
   for (p.y = 0; p.y < ims.Height(); p.y++) {
      for (p.x = 0; p.x < ims.Width(); p.x++) {
 	 Reg2d::ValueType val = ims[p];
	 for (int i = 0; i < se->length; i++) {
	    p1 = p;
	    se->Move(i, p1);
	    if (ims.Hold(p1) && ((ims[p1]) < ims[p])) {
	       val = 0;
	    }
	 }
	 imd[p] = val;
      }
   }
   delete se;
   imd.Labels(ims.Labels());
   return SUCCESS;
}


Errc PErosion( const Reg3d &ims, Reg3d &imd, int numSE, int halfsize ) {
   if (numSE > 12 || numSE < 0) {
      std::cerr << "Error perosion: bad structuring element type: " << numSE << std::endl;
      return FAILURE;
   }
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   StructuringElement3d *se = new StructuringElement3d(numSE, halfsize);

   Point3d p, p1;
   for (p.z = 0; p.z < ims.Depth(); p.z++) {
      for (p.y = 0; p.y < ims.Height(); p.y++) {
	 for (p.x = 0; p.x < ims.Width(); p.x++) {
	    Reg3d::ValueType val = ims[p];
	    for (int i = 0; i < se->length; i++) {
 	       p1 = p;
 	       se->Move(i, p1);
	       if (ims.Hold(p1) && ((ims[p1]) < ims[p])) {
		  val = 0;
	       }
	    }
	    imd[p] = val;
	 }
      }
   }

   imd.Labels(ims.Labels());
   delete se;
   return SUCCESS;
}



Errc PErosion( const Img1duc &ims, Img1duc &imd, int numSE, int halfsize ) {
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   StructuringElement1d *se = new StructuringElement1d(numSE, halfsize);
   Point1d p, p1;
   for (p.x = 0; p.x < ims.Width(); p.x++) {
      Img1duc::ValueType min = Limits < Img1duc::ValueType>::max(), val;
      for (int i = 0; i < se->length; i++) {
  	 p1 = p;
 	 se->Move(i, p1);

	 if (ims.Hold(p1) && ((val = ims[p1]) < min)) {
	    min = val;
	 }
      }
      imd[p] = min;
   }

   delete se;
   return SUCCESS;
}

Errc PErosion( const Img1dsl &ims, Img1dsl &imd, int numSE, int halfsize ) {
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   StructuringElement1d *se = new StructuringElement1d(numSE, halfsize);
   Point1d p, p1;
   for (p.x = 0; p.x < ims.Width(); p.x++) {
      Img1dsl::ValueType min = Limits < Img1dsl::ValueType>::max(), val;
      for (int i = 0; i < se->length; i++) {
  	 p1 = p;
 	 se->Move(i, p1);

	 if (ims.Hold(p1) && ((val = ims[p1]) < min)) {
	    min = val;
	 }
      }
      imd[p] = min;
   }

   delete se;
   return SUCCESS;
}

Errc PErosion( const Img1dsf &ims, Img1dsf &imd, int numSE, int halfsize ) {
   if (halfsize < 1) {
      std::cerr << "Error perosion: bad structuring element size: " << halfsize << std::endl;
      return FAILURE;
   }

   StructuringElement1d *se = new StructuringElement1d(numSE, halfsize);
   Point1d p, p1;
   for (p.x = 0; p.x < ims.Width(); p.x++) {
      Img1dsf::ValueType min = Limits < Img1dsf::ValueType>::max(), val;
      for (int i = 0; i < se->length; i++) {
  	 p1 = p;
 	 se->Move(i, p1);

	 if (ims.Hold(p1) && ((val = ims[p1]) < min)) {
	    min = val;
	 }
      }
      imd[p] = min;
   }

   delete se;
   return SUCCESS;
}

Errc PErosion( const Graph2d &grs, Graph2d &grd ) {
   grd = grs;
   
   for (int i = 1; i < grd.Size(); i++) {
      if (grs[i]) {
	 for (GEdge* ptr = grs[i]->Neighbours(); ptr != NULL; ptr = ptr->Next()) {
	    if (grs[ptr->Node()]->value < grd[i]->value) {
	       grd[i]->value = grs[ptr->Node()]->value;
	    }
	 }
      }
   }
   
   return SUCCESS;
}

Errc PErosion( const Graph3d &grs, Graph3d &grd ) {
   grd = grs;
   
   for (int i = 1; i < grd.Size(); i++) {
      if (grs[i]) {
	 for (GEdge* ptr = grs[i]->Neighbours(); ptr != NULL; ptr = ptr->Next()) {
	    if (grs[ptr->Node()]->value < grd[i]->value) {
	       grd[i]->value = grs[ptr->Node()]->value;
	    }
	 }
      }
   }
   
   return SUCCESS;
}


#ifdef MAIN
#define	USAGE	"usage: %s se halfsize [-m mask] [im_in|-] [im_out|-]"
#define	PARC	2
#define	FINC	1
#define	FOUTC	1
#define	MASK	1

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
      Img1duc* const ims = (Img1duc*)objs[0];
      objd[0] = new Img1duc(ims->Props());
      Img1duc* const imd = (Img1duc*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img1dsl) {
      Img1dsl* const ims = (Img1dsl*)objs[0];
      objd[0] = new Img1dsl(ims->Props());
      Img1dsl* const imd = (Img1dsl*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img1dsf) {
      Img1dsf* const ims = (Img1dsf*)objs[0];
      objd[0] = new Img1dsf(ims->Props());
      Img1dsf* const imd = (Img1dsf*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img2duc) {
      Img2duc* const ims = (Img2duc*)objs[0];
      objd[0] = new Img2duc(ims->Props());
      Img2duc* const imd = (Img2duc*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img2dsl) {
      Img2dsl* const ims = (Img2dsl*)objs[0];
      objd[0] = new Img2dsl(ims->Props());
      Img2dsl* const imd = (Img2dsl*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img2dsf) {
      Img2dsf* const ims = (Img2dsf*)objs[0];
      objd[0] = new Img2dsf(ims->Props());
      Img2dsf* const imd = (Img2dsf*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2duc) {
      Imx2duc* const ims = (Imx2duc*)objs[0];
      objd[0] = new Imx2duc(ims->Props());
      Imx2duc* const imd = (Imx2duc*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2dsl) {
      Imx2dsl* const ims = (Imx2dsl*)objs[0];
      objd[0] = new Imx2dsl(ims->Props());
      Imx2dsl* const imd = (Imx2dsl*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx2dsf) {
      Imx2dsf* const ims = (Imx2dsf*)objs[0];
      objd[0] = new Imx2dsf(ims->Props());
      Imx2dsf* const imd = (Imx2dsf*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Reg2d) {
      Reg2d* const ims = (Reg2d*)objs[0];
      objd[0] = new Reg2d(ims->Props());
      Reg2d* const imd = (Reg2d*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2duc) {
      Imc2duc* const ims = (Imc2duc*)objs[0];
      objd[0] = new Imc2duc(ims->Props());
      Imc2duc* const imd = (Imc2duc*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2dsl) {
      Imc2dsl* const ims = (Imc2dsl*)objs[0];
      objd[0] = new Imc2dsl(ims->Props());
      Imc2dsl* const imd = (Imc2dsl*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc2dsf) {
      Imc2dsf* const ims = (Imc2dsf*)objs[0];
      objd[0] = new Imc2dsf(ims->Props());
      Imc2dsf* const imd = (Imc2dsf*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3duc) {
      Imc3duc* const ims = (Imc3duc*)objs[0];
      objd[0] = new Imc3duc(ims->Props());
      Imc3duc* const imd = (Imc3duc*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3dsl) {
      Imc3dsl* const ims = (Imc3dsl*)objs[0];
      objd[0] = new Imc3dsl(ims->Props());
      Imc3dsl* const imd = (Imc3dsl*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imc3dsf) {
      Imc3dsf* const ims = (Imc3dsf*)objs[0];
      objd[0] = new Imc3dsf(ims->Props());
      Imc3dsf* const imd = (Imc3dsf*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img3duc) {
      Img3duc* const ims = (Img3duc*)objs[0];
      objd[0] = new Img3duc(ims->Props());
      Img3duc* const imd = (Img3duc*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img3dsl) {
      Img3dsl* const ims = (Img3dsl*)objs[0];
      objd[0] = new Img3dsl(ims->Props());
      Img3dsl* const imd = (Img3dsl*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img3dsf) {
      Img3dsf* const ims = (Img3dsf*)objs[0];
      objd[0] = new Img3dsf(ims->Props());
      Img3dsf* const imd = (Img3dsf*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3duc) {
      Imx3duc* const ims = (Imx3duc*)objs[0];
      objd[0] = new Imx3duc(ims->Props());
      Imx3duc* const imd = (Imx3duc*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3dsl) {
      Imx3dsl* const ims = (Imx3dsl*)objs[0];
      objd[0] = new Imx3dsl(ims->Props());
      Imx3dsl* const imd = (Imx3dsl*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Imx3dsf) {
      Imx3dsf* const ims = (Imx3dsf*)objs[0];
      objd[0] = new Imx3dsf(ims->Props());
      Imx3dsf* const imd = (Imx3dsf*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Reg3d) {
      Reg3d* const ims = (Reg3d*)objs[0];
      objd[0] = new Reg3d(ims->Props());
      Reg3d* const imd = (Reg3d*)objd[0];
      
      result = PErosion(*ims, *imd, atoi(parv[0]), atoi(parv[1]));
      goto end;
   }
   if (objs[0]->Type() == Po_Graph2d) {
      Graph2d* const grs = (Graph2d*)objs[0];
      objd[0] = new Graph2d(grs->Props());
      Graph2d * const grd = (Graph2d*)objd[0];
      
      result = PErosion(*grs, *grd);
      goto end;
   }
   if (objs[0]->Type() == Po_Graph3d) {
      Graph3d* const grs = (Graph3d*)objs[0];
      objd[0] = new Graph3d(grs->Props());
      Graph3d * const grd = (Graph3d*)objd[0];
      
      result = PErosion(*grs, *grd);
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
