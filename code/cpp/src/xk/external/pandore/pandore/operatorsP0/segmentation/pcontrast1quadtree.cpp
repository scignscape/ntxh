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
 * @author Laurent Quesnel - 2002-06-10
 */

#include <pandore.h>
using namespace pandore;

/**
 * @file pcontrast1quadtree.cpp
 * On regarde si un bloc a un contraste inferieur � un certain threshold.
 * Si cette condition est non verifi�e alors on divise le bloc en
 * quatre autres blocs d'egales dimensions
 */

/*
 * La structure de donnees bloc2d
 */
struct Bloc2d {
  Point2d origine;
  Dimension2d dimension;

  Bloc2d(Point2d o, Dimension2d d):origine(o), dimension(d) { }
  Bloc2d(Long y, Long x, Long h, Long w):origine(y, x), dimension(h, w) { }
};

/*
 * La structure de donnees bloc3d
 */
struct Bloc3d {
  Point3d origine;
  Dimension3d dimension;

  Bloc3d(Point3d o, Dimension3d d):origine(o), dimension(d) { } 
  Bloc3d(Long z, Long y, Long x, Long d, Long h, Long w):origine(z, y, x), dimension(d, h, w) { }
};



/**
 * Le Bloc respecte-il le critere ?
 *
 * Dans cette fonction on calcule le contraste.
 * Si celui-ci est sup�rieur au threshold
 * alors on renvoie faux
 */ 
bool critere_contraste( const Img2duc &ims, Bloc2d bloc, Img2duc::ValueType threshold ) {
   Img2duc::ValueType m;
   double sum=0.0;
   int nb=0;
   
   for (int y = bloc.origine.y+1; y < bloc.origine.y+bloc.dimension.h-1; y++)
      for (int x = bloc.origine.x+1; x < bloc.origine.x+bloc.dimension.w-1; x++) {
	 m=0;
	 for (int v=0; v<8; v++) {
	    Img2duc::ValueType inter = ABS(ims[y][x]-ims[y+v8y[v]][x+v8x[v]]);
	    m = MAX(m, inter);
	 }
	 nb++;
	 sum += (double) m;
      }
   if (nb==0) return true;
   return ( (sum/nb) <= (double)threshold);
}

Errc PContrast1Quadtree( const Img2duc &ims, Reg2d &rgd, Img2duc::ValueType threshold ) {
   Fifo<Bloc2d> liste;
   Bloc2d bloc(Point2d(0, 0), ims.Size());
   Long nbre = 0;
   
   liste.Push(bloc);
   // Il y a deux phases dans cet algorithme :
   // 1- La decomposition en blocs si le bloc ne repond pas au critere
   // 2- L'etiquetage du bloc
   while (!liste.Empty()) {
      bloc = liste.Pop();
      // Conditions d'arret du decoupage : soit la taille est 1*1, 
      // soit le critere est verifie
      if (bloc.dimension == Dimension2d(1, 1) || critere_contraste(ims, bloc, threshold)) {
	nbre++;
	for (int y = bloc.origine.y; y < bloc.origine.y+bloc.dimension.h; y++)
	    for (int x = bloc.origine.x; x < bloc.origine.x+bloc.dimension.w; x++)
		rgd[y][x] = (Reg2d::ValueType)nbre;
      } else {
	  // Decomposition en 4 blocs
	  Long w = bloc.dimension.w, h =  bloc.dimension.h, x = bloc.origine.x, y = bloc.origine.y;
	  Long w2=(w<2)? 1:w/2; Long h2=(h<2)? 1: h/2;
	  liste.Push(Bloc2d(y, x, h2, w2));
	  liste.Push(Bloc2d(y, x+w2, h2, w-w2));
	  liste.Push(Bloc2d(y+h2, x, h-h2, w2));
	  liste.Push(Bloc2d(y+h2, x+w2, h-h2, w-w2));
      }
   }
   
   // On enregistre le nombre de regions differentes
   return rgd.Labels(nbre);
}

/**
 * Le Bloc respecte-il le critere ?
 *
 * Dans cette fonction on calcule le contraste.
 * Si celui-ci est sup�rieur au threshold
 * alors on renvoie faux
 */ 
bool critere_contraste( const Img2dsl &ims, Bloc2d bloc, Img2dsl::ValueType threshold ) {
   Img2dsl::ValueType m;
   double sum=0.0;
   int nb=0;
   
   for (int y = bloc.origine.y+1; y < bloc.origine.y+bloc.dimension.h-1; y++)
      for (int x = bloc.origine.x+1; x < bloc.origine.x+bloc.dimension.w-1; x++) {
	 m=0;
	 for (int v=0; v<8; v++) {
	    Img2dsl::ValueType inter = ABS(ims[y][x]-ims[y+v8y[v]][x+v8x[v]]);
	    m = MAX(m, inter);
	 }
	 nb++;
	 sum += (double) m;
      }
   if (nb==0) return true;
   return ( (sum/nb) <= (double)threshold);
}

Errc PContrast1Quadtree( const Img2dsl &ims, Reg2d &rgd, Img2dsl::ValueType threshold ) {
   Fifo<Bloc2d> liste;
   Bloc2d bloc(Point2d(0, 0), ims.Size());
   Long nbre = 0;
   
   liste.Push(bloc);
   // Il y a deux phases dans cet algorithme :
   // 1- La decomposition en blocs si le bloc ne repond pas au critere
   // 2- L'etiquetage du bloc
   while (!liste.Empty()) {
      bloc = liste.Pop();
      // Conditions d'arret du decoupage : soit la taille est 1*1, 
      // soit le critere est verifie
      if (bloc.dimension == Dimension2d(1, 1) || critere_contraste(ims, bloc, threshold)) {
	nbre++;
	for (int y = bloc.origine.y; y < bloc.origine.y+bloc.dimension.h; y++)
	    for (int x = bloc.origine.x; x < bloc.origine.x+bloc.dimension.w; x++)
		rgd[y][x] = (Reg2d::ValueType)nbre;
      } else {
	  // Decomposition en 4 blocs
	  Long w = bloc.dimension.w, h =  bloc.dimension.h, x = bloc.origine.x, y = bloc.origine.y;
	  Long w2=(w<2)? 1:w/2; Long h2=(h<2)? 1: h/2;
	  liste.Push(Bloc2d(y, x, h2, w2));
	  liste.Push(Bloc2d(y, x+w2, h2, w-w2));
	  liste.Push(Bloc2d(y+h2, x, h-h2, w2));
	  liste.Push(Bloc2d(y+h2, x+w2, h-h2, w-w2));
      }
   }
   
   // On enregistre le nombre de regions differentes
   return rgd.Labels(nbre);
}

/**
 * Le Bloc respecte-il le critere ?
 *
 * Dans cette fonction on calcule le contraste.
 * Si celui-ci est sup�rieur au threshold
 * alors on renvoie faux
 */ 
bool critere_contraste( const Img2dsf &ims, Bloc2d bloc, Img2dsf::ValueType threshold ) {
   Img2dsf::ValueType m;
   double sum=0.0;
   int nb=0;
   
   for (int y = bloc.origine.y+1; y < bloc.origine.y+bloc.dimension.h-1; y++)
      for (int x = bloc.origine.x+1; x < bloc.origine.x+bloc.dimension.w-1; x++) {
	 m=0;
	 for (int v=0; v<8; v++) {
	    Img2dsf::ValueType inter = ABS(ims[y][x]-ims[y+v8y[v]][x+v8x[v]]);
	    m = MAX(m, inter);
	 }
	 nb++;
	 sum += (double) m;
      }
   if (nb==0) return true;
   return ( (sum/nb) <= (double)threshold);
}

Errc PContrast1Quadtree( const Img2dsf &ims, Reg2d &rgd, Img2dsf::ValueType threshold ) {
   Fifo<Bloc2d> liste;
   Bloc2d bloc(Point2d(0, 0), ims.Size());
   Long nbre = 0;
   
   liste.Push(bloc);
   // Il y a deux phases dans cet algorithme :
   // 1- La decomposition en blocs si le bloc ne repond pas au critere
   // 2- L'etiquetage du bloc
   while (!liste.Empty()) {
      bloc = liste.Pop();
      // Conditions d'arret du decoupage : soit la taille est 1*1, 
      // soit le critere est verifie
      if (bloc.dimension == Dimension2d(1, 1) || critere_contraste(ims, bloc, threshold)) {
	nbre++;
	for (int y = bloc.origine.y; y < bloc.origine.y+bloc.dimension.h; y++)
	    for (int x = bloc.origine.x; x < bloc.origine.x+bloc.dimension.w; x++)
		rgd[y][x] = (Reg2d::ValueType)nbre;
      } else {
	  // Decomposition en 4 blocs
	  Long w = bloc.dimension.w, h =  bloc.dimension.h, x = bloc.origine.x, y = bloc.origine.y;
	  Long w2=(w<2)? 1:w/2; Long h2=(h<2)? 1: h/2;
	  liste.Push(Bloc2d(y, x, h2, w2));
	  liste.Push(Bloc2d(y, x+w2, h2, w-w2));
	  liste.Push(Bloc2d(y+h2, x, h-h2, w2));
	  liste.Push(Bloc2d(y+h2, x+w2, h-h2, w-w2));
      }
   }
   
   // On enregistre le nombre de regions differentes
   return rgd.Labels(nbre);
}

/**
 * Le Bloc respecte-il le critere ?
 *
 * Dans cette fonction on calcule le contraste.
 * Si celui-ci est sup�rieur au threshold
 * alors on renvoie faux
 */ 
bool critere_contraste( const Img3duc &ims, Bloc3d bloc, Img3duc::ValueType threshold ) {
   Img3duc::ValueType m;
   double sum=0;
   int nb=0;
   
   for (int z = bloc.origine.z+1; z < bloc.origine.z+bloc.dimension.d-1; z++)
      for (int y = bloc.origine.y+1; y < bloc.origine.y+bloc.dimension.h-1; y++)
	 for (int x = bloc.origine.x+1; x < bloc.origine.x+bloc.dimension.w-1; x++) {
	    m=Limits<Img3duc::ValueType>::min();
	    for (int v=0; v<26; v++) {
	       Img3duc::ValueType inter = (Img3duc::ValueType) ABS(ims[z][y][x]-ims[z+v26z[v]][y+v26y[v]][x+v26x[v]]);
	       m = MAX(m, inter);
	    }
	    nb++;
	    sum += (double) m;
	 }
   
   return ((sum/nb) <= (double)threshold);
}

Errc PContrast1Quadtree( const Img3duc &ims, Reg3d &rgd, Img3duc::ValueType threshold ) {
   Fifo<Bloc3d> liste;
   Bloc3d bloc(Point3d(0, 0, 0), ims.Size());
   Long nbre = 0;
   
   liste.Push(bloc);
   // Il y a deux phases dans cet algorithme :
   // 1- La decomposition en blocs si le bloc ne repond pas au critere
   // 2- L'etiquetage du bloc
   while (!liste.Empty()) {
      bloc = liste.Pop();
      // Conditions d'arret du decoupage : soit la taille est 1*1*1, 
      // soit le critere est verifie
      if (bloc.dimension == Dimension3d(1, 1, 1) || critere_contraste(ims, bloc, threshold)) {
	 nbre++;
	 for (int z = bloc.origine.z; z < bloc.origine.z+bloc.dimension.d; z++) {
	    for (int y = bloc.origine.y; y < bloc.origine.y+bloc.dimension.h; y++) {
	       for (int x = bloc.origine.x; x < bloc.origine.x+bloc.dimension.w; x++) {
		  rgd[z][y][x] = nbre;
	       }
	    }
	 }
      } else {
	 // Decomposition en 8 blocs
	 Long d=bloc.dimension.d, w=bloc.dimension.w, h=bloc.dimension.h, x=bloc.origine.x, y=bloc.origine.y, z=bloc.origine.z;
	 Long w2=(w<2)? 1:w/2; Long h2=(h<2)? 1: h/2; Long d2=(d<2)?1:d/2;
	 liste.Push(Bloc3d(z, y, x, d2, h2, w2));
	 liste.Push(Bloc3d(z, y+h2, x, d2, h-h2, w2));
	 liste.Push(Bloc3d(z, y, x+w2, d2, h2, w-w2));
	 liste.Push(Bloc3d(z, y+h2, x+w2, d2, h-h2, w-w2));
	 liste.Push(Bloc3d(z+d2, y, x, d-d2, h2, w2));
	 liste.Push(Bloc3d(z+d2, y, x+w2, d-d2, h2, w-w2));
	 liste.Push(Bloc3d(z+d2, y+h2, x, d-d2, h-h2, w2));
	 liste.Push(Bloc3d(z+d2, y+h2, x+w2, d-d2, h-h2, w-w2));
      }
   }
   // On enregistre le nombre de regions differentes
   return rgd.Labels(nbre);
}

/**
 * Le Bloc respecte-il le critere ?
 *
 * Dans cette fonction on calcule le contraste.
 * Si celui-ci est sup�rieur au threshold
 * alors on renvoie faux
 */ 
bool critere_contraste( const Img3dsl &ims, Bloc3d bloc, Img3dsl::ValueType threshold ) {
   Img3dsl::ValueType m;
   double sum=0;
   int nb=0;
   
   for (int z = bloc.origine.z+1; z < bloc.origine.z+bloc.dimension.d-1; z++)
      for (int y = bloc.origine.y+1; y < bloc.origine.y+bloc.dimension.h-1; y++)
	 for (int x = bloc.origine.x+1; x < bloc.origine.x+bloc.dimension.w-1; x++) {
	    m=Limits<Img3dsl::ValueType>::min();
	    for (int v=0; v<26; v++) {
	       Img3dsl::ValueType inter = (Img3dsl::ValueType) ABS(ims[z][y][x]-ims[z+v26z[v]][y+v26y[v]][x+v26x[v]]);
	       m = MAX(m, inter);
	    }
	    nb++;
	    sum += (double) m;
	 }
   
   return ((sum/nb) <= (double)threshold);
}

Errc PContrast1Quadtree( const Img3dsl &ims, Reg3d &rgd, Img3dsl::ValueType threshold ) {
   Fifo<Bloc3d> liste;
   Bloc3d bloc(Point3d(0, 0, 0), ims.Size());
   Long nbre = 0;
   
   liste.Push(bloc);
   // Il y a deux phases dans cet algorithme :
   // 1- La decomposition en blocs si le bloc ne repond pas au critere
   // 2- L'etiquetage du bloc
   while (!liste.Empty()) {
      bloc = liste.Pop();
      // Conditions d'arret du decoupage : soit la taille est 1*1*1, 
      // soit le critere est verifie
      if (bloc.dimension == Dimension3d(1, 1, 1) || critere_contraste(ims, bloc, threshold)) {
	 nbre++;
	 for (int z = bloc.origine.z; z < bloc.origine.z+bloc.dimension.d; z++) {
	    for (int y = bloc.origine.y; y < bloc.origine.y+bloc.dimension.h; y++) {
	       for (int x = bloc.origine.x; x < bloc.origine.x+bloc.dimension.w; x++) {
		  rgd[z][y][x] = nbre;
	       }
	    }
	 }
      } else {
	 // Decomposition en 8 blocs
	 Long d=bloc.dimension.d, w=bloc.dimension.w, h=bloc.dimension.h, x=bloc.origine.x, y=bloc.origine.y, z=bloc.origine.z;
	 Long w2=(w<2)? 1:w/2; Long h2=(h<2)? 1: h/2; Long d2=(d<2)?1:d/2;
	 liste.Push(Bloc3d(z, y, x, d2, h2, w2));
	 liste.Push(Bloc3d(z, y+h2, x, d2, h-h2, w2));
	 liste.Push(Bloc3d(z, y, x+w2, d2, h2, w-w2));
	 liste.Push(Bloc3d(z, y+h2, x+w2, d2, h-h2, w-w2));
	 liste.Push(Bloc3d(z+d2, y, x, d-d2, h2, w2));
	 liste.Push(Bloc3d(z+d2, y, x+w2, d-d2, h2, w-w2));
	 liste.Push(Bloc3d(z+d2, y+h2, x, d-d2, h-h2, w2));
	 liste.Push(Bloc3d(z+d2, y+h2, x+w2, d-d2, h-h2, w-w2));
      }
   }
   // On enregistre le nombre de regions differentes
   return rgd.Labels(nbre);
}

/**
 * Le Bloc respecte-il le critere ?
 *
 * Dans cette fonction on calcule le contraste.
 * Si celui-ci est sup�rieur au threshold
 * alors on renvoie faux
 */ 
bool critere_contraste( const Img3dsf &ims, Bloc3d bloc, Img3dsf::ValueType threshold ) {
   Img3dsf::ValueType m;
   double sum=0;
   int nb=0;
   
   for (int z = bloc.origine.z+1; z < bloc.origine.z+bloc.dimension.d-1; z++)
      for (int y = bloc.origine.y+1; y < bloc.origine.y+bloc.dimension.h-1; y++)
	 for (int x = bloc.origine.x+1; x < bloc.origine.x+bloc.dimension.w-1; x++) {
	    m=Limits<Img3dsf::ValueType>::min();
	    for (int v=0; v<26; v++) {
	       Img3dsf::ValueType inter = (Img3dsf::ValueType) ABS(ims[z][y][x]-ims[z+v26z[v]][y+v26y[v]][x+v26x[v]]);
	       m = MAX(m, inter);
	    }
	    nb++;
	    sum += (double) m;
	 }
   
   return ((sum/nb) <= (double)threshold);
}

Errc PContrast1Quadtree( const Img3dsf &ims, Reg3d &rgd, Img3dsf::ValueType threshold ) {
   Fifo<Bloc3d> liste;
   Bloc3d bloc(Point3d(0, 0, 0), ims.Size());
   Long nbre = 0;
   
   liste.Push(bloc);
   // Il y a deux phases dans cet algorithme :
   // 1- La decomposition en blocs si le bloc ne repond pas au critere
   // 2- L'etiquetage du bloc
   while (!liste.Empty()) {
      bloc = liste.Pop();
      // Conditions d'arret du decoupage : soit la taille est 1*1*1, 
      // soit le critere est verifie
      if (bloc.dimension == Dimension3d(1, 1, 1) || critere_contraste(ims, bloc, threshold)) {
	 nbre++;
	 for (int z = bloc.origine.z; z < bloc.origine.z+bloc.dimension.d; z++) {
	    for (int y = bloc.origine.y; y < bloc.origine.y+bloc.dimension.h; y++) {
	       for (int x = bloc.origine.x; x < bloc.origine.x+bloc.dimension.w; x++) {
		  rgd[z][y][x] = nbre;
	       }
	    }
	 }
      } else {
	 // Decomposition en 8 blocs
	 Long d=bloc.dimension.d, w=bloc.dimension.w, h=bloc.dimension.h, x=bloc.origine.x, y=bloc.origine.y, z=bloc.origine.z;
	 Long w2=(w<2)? 1:w/2; Long h2=(h<2)? 1: h/2; Long d2=(d<2)?1:d/2;
	 liste.Push(Bloc3d(z, y, x, d2, h2, w2));
	 liste.Push(Bloc3d(z, y+h2, x, d2, h-h2, w2));
	 liste.Push(Bloc3d(z, y, x+w2, d2, h2, w-w2));
	 liste.Push(Bloc3d(z, y+h2, x+w2, d2, h-h2, w-w2));
	 liste.Push(Bloc3d(z+d2, y, x, d-d2, h2, w2));
	 liste.Push(Bloc3d(z+d2, y, x+w2, d-d2, h2, w-w2));
	 liste.Push(Bloc3d(z+d2, y+h2, x, d-d2, h-h2, w2));
	 liste.Push(Bloc3d(z+d2, y+h2, x+w2, d-d2, h-h2, w-w2));
      }
   }
   // On enregistre le nombre de regions differentes
   return rgd.Labels(nbre);
}


#ifdef MAIN

/*
 * Modify only the following constants, and the operator switches.
 */
#define	USAGE	"usage: %s threshold [-m mask] [im_in|-] [im_out|-]"
#define	PARC	1  // Number of parameters
#define	FINC	1  // Number of input images
#define	FOUTC	1  // Number of output images
#define	MASK	2  // Masking

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
     	objd[0]=new Reg2d(ims->Size());
      	Reg2d* const rgd=(Reg2d*)objd[0];
    
      	result = PContrast1Quadtree(*ims, *rgd, (Img2duc::ValueType)atof(parv[0]));
      	goto end;
   	}
if (objs[0]->Type() == Po_Img2dsl) {
	Img2dsl* const ims=(Img2dsl*)objs[0];
     	objd[0]=new Reg2d(ims->Size());
      	Reg2d* const rgd=(Reg2d*)objd[0];
    
      	result = PContrast1Quadtree(*ims, *rgd, (Img2dsl::ValueType)atof(parv[0]));
      	goto end;
   	}
if (objs[0]->Type() == Po_Img2dsf) {
	Img2dsf* const ims=(Img2dsf*)objs[0];
     	objd[0]=new Reg2d(ims->Size());
      	Reg2d* const rgd=(Reg2d*)objd[0];
    
      	result = PContrast1Quadtree(*ims, *rgd, (Img2dsf::ValueType)atof(parv[0]));
      	goto end;
   	}
   if (objs[0]->Type() == Po_Img3duc) {
      Img3duc* const ims=(Img3duc*)objs[0];
      objd[0]=new Reg3d(ims->Size());
      Reg3d* const rgd=(Reg3d*)objd[0];
      
      result = PContrast1Quadtree(*ims, *rgd, (Img3duc::ValueType)atof(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img3dsl) {
      Img3dsl* const ims=(Img3dsl*)objs[0];
      objd[0]=new Reg3d(ims->Size());
      Reg3d* const rgd=(Reg3d*)objd[0];
      
      result = PContrast1Quadtree(*ims, *rgd, (Img3dsl::ValueType)atof(parv[0]));
      goto end;
   }
   if (objs[0]->Type() == Po_Img3dsf) {
      Img3dsf* const ims=(Img3dsf*)objs[0];
      objd[0]=new Reg3d(ims->Size());
      Reg3d* const rgd=(Reg3d*)objd[0];
      
      result = PContrast1Quadtree(*ims, *rgd, (Img3dsf::ValueType)atof(parv[0]));
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
