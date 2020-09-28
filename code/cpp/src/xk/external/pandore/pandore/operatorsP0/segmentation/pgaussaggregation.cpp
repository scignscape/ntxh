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
 * @author Regis Clouard - 2002-07-25
 */

#include <math.h>
#include <pandore.h>
using namespace pandore;

/**
 * @file pgaussaggregation.cpp
 * On affecte un point a une region si sa valeur est dans l'intervalle
 * [m(R)-alpha*s(R), m(R)+alpha*s(R)]; m(R) : moyenne et s(R) : ecart-type.
 * La guassienne n'est pas recalculee pour eviter de trop s'eloigner de la
 * situation initiale.
 */

struct tgauss {
   double somme;
   double moment2;
   Long taille;
};

/**
 * Ajoute un point � la region.
 */
void AffecteCritere( tgauss &m, double val ) {
   m.somme += val;
   m.moment2 += val*val;
   m.taille++;
}

/**
 * ritere bas = [m(r)-alpha*s(R)]
 */
double ValeurCritereBas( tgauss m, float alpha ) {
   double moyenne = m.somme / m.taille;
   double ecart_type = sqrt(m.moment2/m.taille - SQR(moyenne));
   return moyenne - alpha * (ecart_type);
}

/**
 * ritere bas = [m(r)-alpha*s(R)]
 */
double ValeurCritereHaut( tgauss m, float alpha ) {
   double moyenne = m.somme / m.taille;
   double ecart_type = sqrt(m.moment2/m.taille - SQR(moyenne));
   return moyenne + alpha * (ecart_type);
}


Errc PGaussAggregation( const Reg2d &rgs, const Img2duc &ims, Reg2d &rgd, int connexite, float alpha ) {
   int v, w;
   Reg2d::ValueType r;
   tgauss* gauss;
   Point2d p, p1, pt;
   Fifo< Point2d > F;
   Ulong nbpix=0;
   
   rgd.Labels(rgs.Labels());
   
   // Allocation et initialisation du tableau des gausss.
   if (!(gauss=(tgauss*)calloc(rgs.Labels()+1, sizeof(tgauss)))) {
      std::cerr << "Error pgraussaggregation: Not enough memory." <<  std::endl;
      return FAILURE;
   }
   
   // Initialisation : recopie des regions d'entr�e (rgs) vers la sortie (rgd) 
   // et calcul des taille et somme des niveaux de gris des r�gions. Les pixels
   // � 0 dans rgs sont consid�r�s comme non trait�s, ceux qui appartiennent �
   // une r�gion garderont le m�me label.
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      r = rgd[p] = rgs[p];  // Les points de r�gions sont marqu�s comme trait�s 
      if (r) {          // On ne fait pas la variance de la r�gion 0
	 AffecteCritere(gauss[r], (double)ims[p]);
      } else {
	 // p est un point � 0 donc pas encore trait�
	 // On va empiler p SI dans son voisinage IL Y A une r�gion
	 if (connexite == 4) {
	    for (v=0;v<4;v++) {
	       p1=p+v4[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
	 if (connexite == 8) {
	    for (v=0;v<8;v++) {
	       p1=p+v8[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
      }
   } // Fin du balayage initial de l'image rgs
   
   // A ce stade tous les pixels voisins d'au moins une r�gion sont empil�s...
   
   // Nouveau mode de croissance
   // On d�pile un point et on regarde si on peut l'attribuer � une r�gion 
   // voisine en comparant son niveau de gris � la variance de la r�gion 
   // (la diff�rence doit �tre plus petite qu'un certain threshold pour que le
   // point soit aggr�g�, sinon il dispara�t d�finitivement de la pile).
   while (!F.Empty()) {
      p = F.Pop();      // On d�pile un point p.
      
      if (connexite == 4) {
	 for (v=0;v<4;v++) {
	    p1=p+v4[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img2duc::ValueType l, u;
		  l=(Img2duc::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img2duc::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<4;w++) {
			   pt=p+v4[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	 }
      } else if (connexite == 8) {
	 for (v=0;v<8;v++) {
	    p1=p+v8[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img2duc::ValueType l, u;
		  l=(Img2duc::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img2duc::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<8;w++) {
			   pt=p+v8[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	    }
      }
   }
   free(gauss);   
   return nbpix;
}

Errc PGaussAggregation( const Reg2d &rgs, const Img2dsl &ims, Reg2d &rgd, int connexite, float alpha ) {
   int v, w;
   Reg2d::ValueType r;
   tgauss* gauss;
   Point2d p, p1, pt;
   Fifo< Point2d > F;
   Ulong nbpix=0;
   
   rgd.Labels(rgs.Labels());
   
   // Allocation et initialisation du tableau des gausss.
   if (!(gauss=(tgauss*)calloc(rgs.Labels()+1, sizeof(tgauss)))) {
      std::cerr << "Error pgraussaggregation: Not enough memory." <<  std::endl;
      return FAILURE;
   }
   
   // Initialisation : recopie des regions d'entr�e (rgs) vers la sortie (rgd) 
   // et calcul des taille et somme des niveaux de gris des r�gions. Les pixels
   // � 0 dans rgs sont consid�r�s comme non trait�s, ceux qui appartiennent �
   // une r�gion garderont le m�me label.
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      r = rgd[p] = rgs[p];  // Les points de r�gions sont marqu�s comme trait�s 
      if (r) {          // On ne fait pas la variance de la r�gion 0
	 AffecteCritere(gauss[r], (double)ims[p]);
      } else {
	 // p est un point � 0 donc pas encore trait�
	 // On va empiler p SI dans son voisinage IL Y A une r�gion
	 if (connexite == 4) {
	    for (v=0;v<4;v++) {
	       p1=p+v4[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
	 if (connexite == 8) {
	    for (v=0;v<8;v++) {
	       p1=p+v8[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
      }
   } // Fin du balayage initial de l'image rgs
   
   // A ce stade tous les pixels voisins d'au moins une r�gion sont empil�s...
   
   // Nouveau mode de croissance
   // On d�pile un point et on regarde si on peut l'attribuer � une r�gion 
   // voisine en comparant son niveau de gris � la variance de la r�gion 
   // (la diff�rence doit �tre plus petite qu'un certain threshold pour que le
   // point soit aggr�g�, sinon il dispara�t d�finitivement de la pile).
   while (!F.Empty()) {
      p = F.Pop();      // On d�pile un point p.
      
      if (connexite == 4) {
	 for (v=0;v<4;v++) {
	    p1=p+v4[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img2dsl::ValueType l, u;
		  l=(Img2dsl::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img2dsl::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<4;w++) {
			   pt=p+v4[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	 }
      } else if (connexite == 8) {
	 for (v=0;v<8;v++) {
	    p1=p+v8[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img2dsl::ValueType l, u;
		  l=(Img2dsl::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img2dsl::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<8;w++) {
			   pt=p+v8[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	    }
      }
   }
   free(gauss);   
   return nbpix;
}

Errc PGaussAggregation( const Reg2d &rgs, const Img2dsf &ims, Reg2d &rgd, int connexite, float alpha ) {
   int v, w;
   Reg2d::ValueType r;
   tgauss* gauss;
   Point2d p, p1, pt;
   Fifo< Point2d > F;
   Ulong nbpix=0;
   
   rgd.Labels(rgs.Labels());
   
   // Allocation et initialisation du tableau des gausss.
   if (!(gauss=(tgauss*)calloc(rgs.Labels()+1, sizeof(tgauss)))) {
      std::cerr << "Error pgraussaggregation: Not enough memory." <<  std::endl;
      return FAILURE;
   }
   
   // Initialisation : recopie des regions d'entr�e (rgs) vers la sortie (rgd) 
   // et calcul des taille et somme des niveaux de gris des r�gions. Les pixels
   // � 0 dans rgs sont consid�r�s comme non trait�s, ceux qui appartiennent �
   // une r�gion garderont le m�me label.
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      r = rgd[p] = rgs[p];  // Les points de r�gions sont marqu�s comme trait�s 
      if (r) {          // On ne fait pas la variance de la r�gion 0
	 AffecteCritere(gauss[r], (double)ims[p]);
      } else {
	 // p est un point � 0 donc pas encore trait�
	 // On va empiler p SI dans son voisinage IL Y A une r�gion
	 if (connexite == 4) {
	    for (v=0;v<4;v++) {
	       p1=p+v4[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
	 if (connexite == 8) {
	    for (v=0;v<8;v++) {
	       p1=p+v8[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
      }
   } // Fin du balayage initial de l'image rgs
   
   // A ce stade tous les pixels voisins d'au moins une r�gion sont empil�s...
   
   // Nouveau mode de croissance
   // On d�pile un point et on regarde si on peut l'attribuer � une r�gion 
   // voisine en comparant son niveau de gris � la variance de la r�gion 
   // (la diff�rence doit �tre plus petite qu'un certain threshold pour que le
   // point soit aggr�g�, sinon il dispara�t d�finitivement de la pile).
   while (!F.Empty()) {
      p = F.Pop();      // On d�pile un point p.
      
      if (connexite == 4) {
	 for (v=0;v<4;v++) {
	    p1=p+v4[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img2dsf::ValueType l, u;
		  l=(Img2dsf::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img2dsf::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<4;w++) {
			   pt=p+v4[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	 }
      } else if (connexite == 8) {
	 for (v=0;v<8;v++) {
	    p1=p+v8[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img2dsf::ValueType l, u;
		  l=(Img2dsf::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img2dsf::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<8;w++) {
			   pt=p+v8[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	    }
      }
   }
   free(gauss);   
   return nbpix;
}

Errc PGaussAggregation( const Reg3d &rgs, const Img3duc &ims, Reg3d &rgd, int connexite, float alpha ) {
   int v, w;
   Reg3d::ValueType r;
   tgauss* gauss;
   Point3d p, p1, pt;
   Fifo< Point3d > F;
   Ulong nbpix=0;
   
   rgd.Labels(rgs.Labels());
   
   // Allocation et initialisation du tableau des gausss.
   if (!(gauss=(tgauss*)calloc(rgs.Labels()+1, sizeof(tgauss)))) {
      std::cerr << "Error pgraussaggregation: Not enough memory." <<  std::endl;
      return FAILURE;
   }
   
   // Initialisation : recopie des regions d'entr�e (rgs) vers la sortie (rgd) 
   // et calcul des taille et somme des niveaux de gris des r�gions. Les pixels
   // � 0 dans rgs sont consid�r�s comme non trait�s, ceux qui appartiennent �
   // une r�gion garderont le m�me label.
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      r = rgd[p] = rgs[p];  // Les points de r�gions sont marqu�s comme trait�s 
      if (r) {          // On ne fait pas la variance de la r�gion 0
	 AffecteCritere(gauss[r], (double)ims[p]);
      } else {
	 // p est un point � 0 donc pas encore trait�
	 // On va empiler p SI dans son voisinage IL Y A une r�gion
	 if (connexite == 6) {
	    for (v=0;v<6;v++) {
	       p1=p+v6[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
	 if (connexite == 26) {
	    for (v=0;v<26;v++) {
	       p1=p+v26[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
      }
   } // Fin du balayage initial de l'image rgs
   
   // A ce stade tous les pixels voisins d'au moins une r�gion sont empil�s...
   
   // Nouveau mode de croissance
   // On d�pile un point et on regarde si on peut l'attribuer � une r�gion 
   // voisine en comparant son niveau de gris � la variance de la r�gion 
   // (la diff�rence doit �tre plus petite qu'un certain threshold pour que le
   // point soit aggr�g�, sinon il dispara�t d�finitivement de la pile).
   while (!F.Empty()) {
      p = F.Pop();      // On d�pile un point p.
      
      if (connexite == 6) {
	 for (v=0;v<6;v++) {
	    p1=p+v6[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img3duc::ValueType l, u;
		  l=(Img3duc::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img3duc::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<6;w++) {
			   pt=p+v6[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	 }
      } else if (connexite == 26) {
	 for (v=0;v<26;v++) {
	    p1=p+v26[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img3duc::ValueType l, u;
		  l=(Img3duc::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img3duc::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<26;w++) {
			   pt=p+v26[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	    }
      }
   }
   free(gauss);   
   return nbpix;
}

Errc PGaussAggregation( const Reg3d &rgs, const Img3dsl &ims, Reg3d &rgd, int connexite, float alpha ) {
   int v, w;
   Reg3d::ValueType r;
   tgauss* gauss;
   Point3d p, p1, pt;
   Fifo< Point3d > F;
   Ulong nbpix=0;
   
   rgd.Labels(rgs.Labels());
   
   // Allocation et initialisation du tableau des gausss.
   if (!(gauss=(tgauss*)calloc(rgs.Labels()+1, sizeof(tgauss)))) {
      std::cerr << "Error pgraussaggregation: Not enough memory." <<  std::endl;
      return FAILURE;
   }
   
   // Initialisation : recopie des regions d'entr�e (rgs) vers la sortie (rgd) 
   // et calcul des taille et somme des niveaux de gris des r�gions. Les pixels
   // � 0 dans rgs sont consid�r�s comme non trait�s, ceux qui appartiennent �
   // une r�gion garderont le m�me label.
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      r = rgd[p] = rgs[p];  // Les points de r�gions sont marqu�s comme trait�s 
      if (r) {          // On ne fait pas la variance de la r�gion 0
	 AffecteCritere(gauss[r], (double)ims[p]);
      } else {
	 // p est un point � 0 donc pas encore trait�
	 // On va empiler p SI dans son voisinage IL Y A une r�gion
	 if (connexite == 6) {
	    for (v=0;v<6;v++) {
	       p1=p+v6[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
	 if (connexite == 26) {
	    for (v=0;v<26;v++) {
	       p1=p+v26[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
      }
   } // Fin du balayage initial de l'image rgs
   
   // A ce stade tous les pixels voisins d'au moins une r�gion sont empil�s...
   
   // Nouveau mode de croissance
   // On d�pile un point et on regarde si on peut l'attribuer � une r�gion 
   // voisine en comparant son niveau de gris � la variance de la r�gion 
   // (la diff�rence doit �tre plus petite qu'un certain threshold pour que le
   // point soit aggr�g�, sinon il dispara�t d�finitivement de la pile).
   while (!F.Empty()) {
      p = F.Pop();      // On d�pile un point p.
      
      if (connexite == 6) {
	 for (v=0;v<6;v++) {
	    p1=p+v6[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img3dsl::ValueType l, u;
		  l=(Img3dsl::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img3dsl::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<6;w++) {
			   pt=p+v6[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	 }
      } else if (connexite == 26) {
	 for (v=0;v<26;v++) {
	    p1=p+v26[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img3dsl::ValueType l, u;
		  l=(Img3dsl::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img3dsl::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<26;w++) {
			   pt=p+v26[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	    }
      }
   }
   free(gauss);   
   return nbpix;
}

Errc PGaussAggregation( const Reg3d &rgs, const Img3dsf &ims, Reg3d &rgd, int connexite, float alpha ) {
   int v, w;
   Reg3d::ValueType r;
   tgauss* gauss;
   Point3d p, p1, pt;
   Fifo< Point3d > F;
   Ulong nbpix=0;
   
   rgd.Labels(rgs.Labels());
   
   // Allocation et initialisation du tableau des gausss.
   if (!(gauss=(tgauss*)calloc(rgs.Labels()+1, sizeof(tgauss)))) {
      std::cerr << "Error pgraussaggregation: Not enough memory." <<  std::endl;
      return FAILURE;
   }
   
   // Initialisation : recopie des regions d'entr�e (rgs) vers la sortie (rgd) 
   // et calcul des taille et somme des niveaux de gris des r�gions. Les pixels
   // � 0 dans rgs sont consid�r�s comme non trait�s, ceux qui appartiennent �
   // une r�gion garderont le m�me label.
   for (p.z = 0; p.z < ims.Depth(); p.z++)
   for (p.y = 0; p.y < ims.Height(); p.y++)
   for (p.x = 0; p.x < ims.Width(); p.x++)
   {
      r = rgd[p] = rgs[p];  // Les points de r�gions sont marqu�s comme trait�s 
      if (r) {          // On ne fait pas la variance de la r�gion 0
	 AffecteCritere(gauss[r], (double)ims[p]);
      } else {
	 // p est un point � 0 donc pas encore trait�
	 // On va empiler p SI dans son voisinage IL Y A une r�gion
	 if (connexite == 6) {
	    for (v=0;v<6;v++) {
	       p1=p+v6[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
	 if (connexite == 26) {
	    for (v=0;v<26;v++) {
	       p1=p+v26[v];
	       if (rgs.Hold(p1) && rgs[p1]) {
		  F.Push(p); // On empile le point qui n'est pas encore trait�
		  break ;    // Ce n'est pas la peine de voir les autres voisins
	       }
	    }
	 }
      }
   } // Fin du balayage initial de l'image rgs
   
   // A ce stade tous les pixels voisins d'au moins une r�gion sont empil�s...
   
   // Nouveau mode de croissance
   // On d�pile un point et on regarde si on peut l'attribuer � une r�gion 
   // voisine en comparant son niveau de gris � la variance de la r�gion 
   // (la diff�rence doit �tre plus petite qu'un certain threshold pour que le
   // point soit aggr�g�, sinon il dispara�t d�finitivement de la pile).
   while (!F.Empty()) {
      p = F.Pop();      // On d�pile un point p.
      
      if (connexite == 6) {
	 for (v=0;v<6;v++) {
	    p1=p+v6[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img3dsf::ValueType l, u;
		  l=(Img3dsf::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img3dsf::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<6;w++) {
			   pt=p+v6[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	 }
      } else if (connexite == 26) {
	 for (v=0;v<26;v++) {
	    p1=p+v26[v];
	    if (rgd.Hold(p1)) {
	       if ((r=rgd[p1])) {          // Info lue dans la DESTINATION
		  Img3dsf::ValueType l, u;
		  l=(Img3dsf::ValueType)ValeurCritereBas(gauss[r], alpha);
		  u=(Img3dsf::ValueType)ValeurCritereHaut(gauss[r], alpha);
		  
		  if (ims[p]>=l && ims[p]<=u) {
		     if (!rgd[p]) {  // il n'a pas �t� aggr�g� depuis son empilement
			rgd[p]=r;     // il re�oit le label de sa r�gion voisine
			nbpix++;
			// On empile alors tous ses voisins non encore trait�s 
			// (ceux � 0 dans rgd)
			for (w=0;w<26;w++) {
			   pt=p+v26[w];
			   if (rgd.Hold(pt)) {
			      if (!rgd[pt]) {
				 F.Push(pt);
			      }
			   }
			}
		     }
		  }
	       }
	    }
	    }
      }
   }
   free(gauss);   
   return nbpix;
}


#ifdef MAIN
#define USAGE   "usage: %s connexity alpha [-m mask] [rg_in|-] [im_in|-] [rg_out|-]"
#define PARC    2
#define FINC    2
#define FOUTC   1
#define MASK    0

int main( int argc, char *argv[] ) {
   Errc result;                // The result code of the execution.
   Pobject* mask;              // The region map.
   Pobject* objin[FINC + 1];   // The input objects.
   Pobject* objs[FINC + 1];    // The source objects masked.
   Pobject* objout[FOUTC + 1]; // The output object.
   Pobject* objd[FOUTC + 1];   // The result object of the execution.
   char* parv[PARC + 1];       // The input parameters.

   ReadArgs(argc, argv, PARC, FINC, FOUTC, &mask, objin, objs, objout, objd, parv, USAGE, MASK); 
   if ((objs[0]->Type() == Po_Reg2d) && (objs[1]->Type() == Po_Img2duc)) {
      Reg2d* const rgs=(Reg2d*)objs[0];
      Img2duc* const ims=(Img2duc*)objs[1];
      objd[0]=new Reg2d(rgs->Size());
      Reg2d* const rgd=(Reg2d*)objd[0];
      
      result=PGaussAggregation(*rgs, *ims, *rgd, atoi(parv[0]), (float)atof(parv[1]));
      goto end;
   }

   if ((objs[0]->Type() == Po_Reg2d) && (objs[1]->Type() == Po_Img2dsl)) {
      Reg2d* const rgs=(Reg2d*)objs[0];
      Img2dsl* const ims=(Img2dsl*)objs[1];
      objd[0]=new Reg2d(rgs->Size());
      Reg2d* const rgd=(Reg2d*)objd[0];
      
      result=PGaussAggregation(*rgs, *ims, *rgd, atoi(parv[0]), (float)atof(parv[1]));
      goto end;
   }

   if ((objs[0]->Type() == Po_Reg2d) && (objs[1]->Type() == Po_Img2dsf)) {
      Reg2d* const rgs=(Reg2d*)objs[0];
      Img2dsf* const ims=(Img2dsf*)objs[1];
      objd[0]=new Reg2d(rgs->Size());
      Reg2d* const rgd=(Reg2d*)objd[0];
      
      result=PGaussAggregation(*rgs, *ims, *rgd, atoi(parv[0]), (float)atof(parv[1]));
      goto end;
   }

   if ((objs[0]->Type() == Po_Reg3d) && (objs[1]->Type() == Po_Img3duc)) {
      Reg3d* const rgs=(Reg3d*)objs[0];
      Img3duc* const ims=(Img3duc*)objs[1];
      objd[0]=new Reg3d(rgs->Size());
      Reg3d* const rgd=(Reg3d*)objd[0];
      
      result=PGaussAggregation(*rgs, *ims, *rgd, atoi(parv[0]), (float)atof(parv[1]));
      goto end;
   }

   if ((objs[0]->Type() == Po_Reg3d) && (objs[1]->Type() == Po_Img3dsl)) {
      Reg3d* const rgs=(Reg3d*)objs[0];
      Img3dsl* const ims=(Img3dsl*)objs[1];
      objd[0]=new Reg3d(rgs->Size());
      Reg3d* const rgd=(Reg3d*)objd[0];
      
      result=PGaussAggregation(*rgs, *ims, *rgd, atoi(parv[0]), (float)atof(parv[1]));
      goto end;
   }

   if ((objs[0]->Type() == Po_Reg3d) && (objs[1]->Type() == Po_Img3dsf)) {
      Reg3d* const rgs=(Reg3d*)objs[0];
      Img3dsf* const ims=(Img3dsf*)objs[1];
      objd[0]=new Reg3d(rgs->Size());
      Reg3d* const rgd=(Reg3d*)objd[0];
      
      result=PGaussAggregation(*rgs, *ims, *rgd, atoi(parv[0]), (float)atof(parv[1]));
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
