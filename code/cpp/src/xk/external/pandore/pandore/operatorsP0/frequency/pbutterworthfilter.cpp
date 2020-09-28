/* -*- c-basic-offset: 3; mode:c++ -*-
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

/*
 * @author R�gis Clouard - 2006-01-23
 */

#include <math.h>
#include <pandore.h>
using namespace pandore;

/**
 * @file pbutterworthfilter.cpp
 * Constructs a frequency filter (lowpass or highpass, bandpass or bandreject).
 * lowpass: Hlp(u, v) =             1
 *                     --------------------
 *                     1 + [ D(u, v)/D0]<sup>2n</sup>
 *
 * @param ncol the number of column of the output image
 * @param nrow the number of row of the output image
 * @param highpass  if highpass=0 -> low pass and band reject, highpass=1 -> highpass and bandpass.
 * @param cutin  the cutin frequency of the filter 0 - 0.5 (for band reject and band pass)
 * @param cutoff the cutoff frequency of the filter 0 - 0.5 (for all filter types)
 * @param order the order of the filter, the higher n is the sharper
 *              the transition is. (n must be an integer >= 1).
 *              (always even???)
 * Ref: R.C. Gonzalez, R. E. Woods, "Digital Image Prcoessing", Prentice hall, 2002, p.173.
 */
Errc PButterworthFilter( Img2dsf &imd, int nrow, int ncol, int highpass, float cutin, float cutoff, int order) {
   if (ncol < 1 || nrow < 1) {
      std::cerr << "Error pbutterworthfilter: Bad image size" << std::endl;
      return FAILURE;
   }
   if (cutoff <= 0) {
      std::cerr << "Error pbutterworthfilter: bad parameter value for cutoff frequency:" << cutoff << std::endl;
      return FAILURE;
   }
   if (cutin < 0 || cutin > cutoff) {
      std::cerr << "Error pbutterworthfilter: bad parameter value for cutin frequency [0..cutoff]:" << cutin << std::endl;
      return FAILURE;
   }
   
   imd.New(nrow, ncol);
   Point2d p;
   
   const double n = order << 1; // 2*n
   if (cutin == 0) {
      if (highpass == 0) {
#ifdef DEBUG
	 fprintf(stderr, "lowpass filter\n");
#endif
	 // lowpass filter
	 for (p.y = 0; p.y < imd.Height() >> 1 ; p.y++)
	    for (p.x = 0; p.x < imd.Width() >> 1; p.x++) {
	       double radius = sqrt((double)p.x * p.x + p.y * p.y);
	       double temp  =pow( (radius / cutoff) , n);
	       float d = (float)(1.0 / (1.0 + temp));
	       imd[p] = d;
	       imd[p.y][imd.Width() - 1 - p.x] = d;
	       imd[imd.Height() - 1 - p.y][p.x] = d;
	       imd[imd.Height() - 1 - p.y][imd.Width() - 1 - p.x] = d;
	    }
      } else {
#ifdef DEBUG
	 fprintf(stderr, "highpass filter\n");
#endif
	 // highpass filter
	 for (p.y = 0; p.y < imd.Height() >> 1; p.y++) {
	    for (p.x = 0; p.x < imd.Width() >> 1; p.x++) {
	       double radius = sqrt((double)p.x*p.x + p.y*p.y);
	       double temp = pow( (radius / cutoff) , n);
	       float d = (float)(1.0 / (1.0 + temp));
	       imd[p] = 1.0F - d;
	       imd[p.y][imd.Width() - 1 - p.x] = 1.0F - d;
	       imd[imd.Height() - 1 - p.y][p.x] = 1.0F - d;
	       imd[imd.Height() - 1 - p.y][imd.Width() - 1 - p.x] = 1.0F - d;
	    }
	 }
      }
   } else {
      const float W = cutoff-cutin; // Band width
      const float D0 = (cutoff+cutin) / 2; 
      if (highpass == 0) {
#ifdef DEBUG
	 fprintf(stderr, "bandreject filter\n");
#endif
	 // Bandreject filter
	 for (p.y = 0; p.y < imd.Height() >> 1; p.y++) {
	    for (p.x = 0; p.x < imd.Width() >> 1; p.x++) {
	       double radius2 = (double)p.x * p.x + p.y * p.y;
	       double temp = (sqrt(radius2) * W)/ (radius2 - (D0 * D0));
	       float d =(float)(1.0 / (1.0 + pow(temp, n)));
	       imd[p] = d;
	       imd[p.y][imd.Width() - 1 - p.x] = d;
	       imd[imd.Height() - 1 - p.y][p.x] = d;
	       imd[imd.Height() - 1 - p.y][imd.Width() - 1 - p.x] = d;
	    }
	 }
      } else {
#ifdef DEBUG
	 fprintf(stderr, "bandpass filter\n");
#endif
	 // Bandpass filter.
	 for (p.y = 0; p.y < imd.Height() >> 1; p.y++) {
	    for (p.x = 0; p.x < imd.Width() >> 1; p.x++) {
	       double radius2 = (double)p.x * p.x + p.y * p.y;
	       double temp = (sqrt(radius2) * W) / (radius2 - (D0 * D0));
	       float d = (float)(1.0 / (1.0 + pow(temp, n)));
	       imd[p] = 1.0F - d;
	       imd[p.y][imd.Width() - 1 - p.x] = 1.0F - d;
	       imd[imd.Height() - 1 - p.y][p.x] = 1.0F - d;
	       imd[imd.Height() - 1 - p.y][imd.Width()-1-p.x] = 1.0F - d;
	    }
	 }
      }
   }
   return SUCCESS;
}

Errc PButterworthFilter( Img3dsf &imd, int ndep, int nrow, int ncol, int highpass, float cutin, float cutoff, int order) {
   if (ncol < 1 || nrow < 1) {
      std::cerr << "Error pbutterworthfilter: Bad image size" << std::endl;
      return FAILURE;
   }
   if (cutoff <= 0) {
      std::cerr << "Error pbutterworthfilter: bad parameter value for cutoff frequency:" << cutoff << std::endl;
      return FAILURE;
   }
   if (cutin < 0 || cutin > cutoff) {
      std::cerr << "Error pbutterworthfilter: bad parameter value for cutin frequency [0..cutoff]:" << cutin << std::endl;
      return FAILURE;
   }
   
   imd.New(ndep, nrow, ncol);
   Point3d p;
   
   const double n = order << 1; // 2*n
   if (cutin == 0) {
      if (highpass == 0) {
#ifdef DEBUG
	 fprintf(stderr, "lowpass filter\n");
#endif
	 // lowpass filter
	 for (p.z = 0; p.z < imd.Depth() >> 1 ; p.z++) {
	    for (p.y = 0; p.y < imd.Height() >> 1; p.y++) {
	       for (p.x = 0; p.x < imd.Width() >> 1; p.x++) {
		  double radius = sqrt((double)p.x * p.x + p.y * p.y + p.z * p.z);
		  double temp = pow( (radius / cutoff), n);
		  float d = (float)(1.0 / (1.0 + temp));
		  imd[p] = d;
		  imd[p.z][p.y][imd.Width() - 1 - p.x] = d;
		  imd[p.z][imd.Height()-1-p.y][p.x] = d;
		  imd[p.z][imd.Height()-1-p.y][imd.Width() - 1 - p.x] = d;

		  imd[imd.Depth()-1-p.z][p.y][p.x] = d;
		  imd[imd.Depth()-1-p.z][p.y][imd.Width() - 1 - p.x] = d;
		  imd[imd.Depth()-1-p.z][imd.Height()-1-p.y][p.x] = d;
		  imd[imd.Depth()-1-p.z][imd.Height()-1-p.y][imd.Width() - 1 - p.x] = d;
	       }
	    }
	 }
      } else {
#ifdef DEBUG
	 fprintf(stderr, "highpass filter\n");
#endif
	 // highpass filter
	 for (p.z = 0; p.z < imd.Depth() >> 1; p.z++) {
	    for (p.y = 0; p.y < imd.Height() >> 1; p.y++) {
	       for (p.x = 0; p.x < imd.Width() >> 1; p.x++) {
		  double radius = sqrt((double)p.x * p.x + p.y * p.y);
		  double temp  =pow( (radius / cutoff) , n);
		  float d = (float)(1.0 / (1.0 + temp));
		  imd[p] = 1.0F - d;
		  imd[p.z][p.y][imd.Width() - 1 - p.x] = 1.0F - d;
		  imd[p.z][imd.Height() - 1 - p.y][p.x] = 1.0F - d;
		  imd[p.z][imd.Height() - 1 - p.y][imd.Width() - 1 - p.x] = 1.0F - d;
		  imd[imd.Depth() - 1 - p.z][p.y][p.x] = 1.0F - d;
		  imd[imd.Depth() - 1 - p.z][p.y][imd.Width() - 1 - p.x] = 1.0F - d;
		  imd[imd.Depth() - 1 - p.z][imd.Height() - 1 - p.y][p.x] = 1.0F - d;
		  imd[imd.Depth() - 1 - p.z][imd.Height() - 1 - p.y][imd.Width() - 1 - p.x] = 1.0F - d;
	       }
	    }
	 }
      }
   } else {
      const float W = cutoff - cutin; // Band width
      const float D0 = (cutoff+cutin) / 2; 
      if (highpass == 0) {
#ifdef DEBUG
	 fprintf(stderr, "bandreject filter\n");
#endif
	 // Bandreject filter
	 for (p.z = 0; p.z < imd.Depth() >> 1; p.z++) {
	    for (p.y = 0; p.y < imd.Height() >> 1; p.y++) {
	       for (p.x = 0; p.x < imd.Width() >> 1; p.x++) {
		  double radius2 = (double)p.x * p.x + p.y * p.y + p.z * p.z;
		  double temp = (sqrt(radius2) * W)/ (radius2 - (D0 * D0));
		  float d = (float)(1.0 / (1.0 + pow(temp, n)));
		  imd[p] = d;
		  imd[p.z][p.y][imd.Width() - 1 - p.x] = d;
		  imd[p.z][imd.Height()-1-p.y][p.x] = d;
		  imd[p.z][imd.Height()-1-p.y][imd.Width() - 1 - p.x] = d;
		  
		  imd[imd.Depth() - 1 - p.z][p.y][p.x] = d;
		  imd[imd.Depth() - 1 - p.z][p.y][imd.Width() - 1 - p.x] = d;
		  imd[imd.Depth() - 1 - p.z][imd.Height() - 1 - p.y][p.x] = d;
		  imd[imd.Depth() - 1 - p.z][imd.Height() - 1 - p.y][imd.Width() - 1 - p.x] = d;
	       }
	    }
	 }
      } else {
#ifdef DEBUG
	 fprintf(stderr, "bandpass filter\n");
#endif
	 // Bandpass filter.
	 for (p.z=0;p.z<imd.Depth()>>1;p.z++) {
	    for (p.y=0;p.y<imd.Height()>>1;p.y++) {
	       for (p.x=0;p.x<imd.Width()>>1;p.x++) {
		  double radius2 = (double)p.x*p.x + p.y*p.y +p.z*p.z;
		  double temp = (sqrt(radius2) * W)/ (radius2  -(D0 * D0));
		  float d = (float)(1.0 / (1.0 + pow(temp, n)));
		  imd[p] = 1.0F - d;
		  imd[p.z][p.y][imd.Width() - 1 - p.x] = 1.0F - d;
		  imd[p.z][imd.Height() - 1 - p.y][p.x] = 1.0F - d;
		  imd[p.z][imd.Height() - 1 - p.y][imd.Width() - 1 - p.x] = 1.0F - d;
		  imd[imd.Depth() - 1 - p.z][p.y][p.x] = 1.0F-d;
		  imd[imd.Depth() - 1 - p.z][p.y][imd.Width() - 1 - p.x] = 1.0F - d;
		  imd[imd.Depth() - 1 - p.z][imd.Height() - 1 - p.y][p.x] = 1.0F - d;
		  imd[imd.Depth() - 1 - p.z][imd.Height() - 1 - p.y][imd.Width() - 1 - p.x] = 1.0F - d;
	       }
	    }
	 }
      }
   }
   
   return SUCCESS;
}

#ifdef MAIN
#define USAGE "usage: %s ncol nrow ndep highpass cutin cutoff order [im_out|-]"
#define PARC  7 // Number of parameters.
#define FINC  0 // Number of input images.
#define FOUTC 1 // Number of output images.
#define MASK  0 // No masking allowed.

int main( int argc, char *argv[] ) {
   Errc result;                // The result code of the execution.
   Pobject* mask;              // The region map.
   Pobject* objin[FINC + 1];   // The input objects.
   Pobject* objs[FINC + 1];    // The source objects masked.
   Pobject* objout[FOUTC + 1]; // The output object.
   Pobject* objd[FOUTC + 1];   // The result object of the execution.
   char* parv[PARC + 1];       // The input parameters.
   
   ReadArgs(argc, argv, PARC, FINC, FOUTC, &mask, objin, objs, objout, objd, parv, USAGE, MASK);
   
   if (atoi(parv[2]) < 0) {
      std::cerr << "Error pbutterworthfilter: Bad parameter value: ndep="<<atoi(parv[2])<<std::endl;
   } else if (atoi(parv[2]) < 2) {
      objd[0] = new Img2dsf();
      Img2dsf* imd = (Img2dsf*)objd[0];
      
      result = PButterworthFilter(*imd, atoi(parv[1]), atoi(parv[0]), atoi(parv[3]), (float)atof(parv[4]), (float)atof(parv[5]), atoi(parv[6]));

   } else {
      objd[0] = new Img3dsf();
      Img3dsf* imd = (Img3dsf*)objd[0];

      result = PButterworthFilter(*imd, atoi(parv[2]), atoi(parv[1]), atoi(parv[0]), atoi(parv[3]), (float)atof(parv[4]), (float)atof(parv[5]), atoi(parv[6]));
   }
   
   if (result) {
      WriteArgs(argc, argv, PARC, FINC, FOUTC, &mask, objin, objs, objout, objd, MASK);
   }
   Exit(result);
   return 0;
}

#endif
