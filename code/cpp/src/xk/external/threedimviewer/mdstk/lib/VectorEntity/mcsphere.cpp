////////////////////////////////////////////////////////////
// $Id: mcsphere.cpp 1863 2010-08-31 20:40:15Z spanel $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// includes

#include <VectorEntity/mcsphere.h>
#include <VectorEntity/mcvertex.h>
#include <VectorEntity/mcvector3d.h>

#include <stdexcept>

using namespace vctl;

////////////////////////////////////////////////////////////
//

/*void MCSphere::MakeSphereTetra(MCVertex * n1, MCVertex * n2, MCVertex * n3, MCVertex * n4)
{
    double					M[12];

    assert((n1 != NULL) && (n2 != NULL) && (n3 != NULL) && (n4 != NULL));

    // urceni parametru prvni roviny
    M[0] = n2->GetX() - n1->GetX();
    M[1] = n2->GetY() - n1->GetY();
    M[2] = n2->GetZ() - n1->GetZ();
    M[3] = (M[0] * ((n1->GetX() + n2->GetX())*0.5) ) + (M[1] * ((n1->GetY() + n2->GetY())/2) ) + (M[2] * ((n1->GetZ() + n2->GetZ())*0.5));

    // urceni parametru druhe roviny
    M[4] = n3->GetX() - n1->GetX();
    M[5] = n3->GetY() - n1->GetY();
    M[6]= n3->GetZ() - n1->GetZ();
    M[7] = (M[4] * ((n1->GetX() + n3->GetX())*0.5) ) + (M[5] * ((n1->GetY() + n3->GetY())/2) ) + (M[6] * ((n1->GetZ() + n3->GetZ())*0.5));

    // urceni parametru ctvrte roviny
    M[8] = n4->GetX() - n1->GetX();
    M[9] = n4->GetY() - n1->GetY();
    M[10] = n4->GetZ() - n1->GetZ();
    M[11] = (M[8] * ((n1->GetX() + n4->GetX())*0.5) ) + (M[9] * ((n1->GetY() + n4->GetY())/2) ) + (M[10] * ((n1->GetZ() + n4->GetZ())*0.5));

    // vypocteni stredu koule, reseni soustavy matice
    if (GausElimin(M, stred))
        throw std::logic_error("Chyba reseni soustavy pro vypocet koule Tetra");

    // vypocet kontrolnich polomeru koule
    radius = stred.Distance(*n1);
}*/

////////////////////////////////////////////////////////////
//

void MCSphere::MakeSphereTetra(MCVertex * n1, MCVertex * n2, MCVertex * n3, MCVertex * n4)
{
    assert((n1 != NULL) && (n2 != NULL) && (n3 != NULL) && (n4 != NULL));

    // pomocne vektory
    MCVector3D v12(n1, n2);
    MCVector3D v13(n1, n3);
    MCVector3D v14(n1, n4);

    // velikosti vektoru
    double s12 = v12.SquareLength();
    double s13 = v13.SquareLength();
    double s14 = v14.SquareLength();

    // dalsi pomocne vektory
    MCVector3D w1314, w1412, w1213;
    w1314.VectorProduct(v13, v14);
    w1412.VectorProduct(v14, v12);
    w1213.VectorProduct(v12, v13);

    // vypocet jmenovatele
    double jmen = 2.0 * MCVector3D::DotProduct(v12, w1314);
//    if( fabs(jmen) < 0.000001 )
    if( fabs(jmen) < 0.001 )
        throw std::logic_error("Chyba vypoctu koule Tetra");
    double inv_jmen = 1.0 / jmen;

    // nasobeni vektoru skalarem
    w1213 *= s14;
    w1412 *= s13;
    w1314 *= s12;

    // vypocet citatele
    MCVector3D cit(w1213);
    cit += w1412;
    cit += w1314;

    // stred koule
    stred.SetX(cit.GetX() * inv_jmen + n1->GetX());
    stred.SetY(cit.GetY() * inv_jmen + n1->GetY());
    stred.SetZ(cit.GetZ() * inv_jmen + n1->GetZ());

    // polomer koule
//    radius = fabs(cit.Length() * inv_jmen);
    radius = stred.Distance(*n1);
}

////////////////////////////////////////////////////////////
//

void MCSphere::MakeSphereTri(MCVertex * n1, MCVertex * n2, MCVertex * n3)
{
    double					M[12];
    MCPoint3D				n;
    MCVector3D				u(n1, n2), v(n1, n3), normala;


    assert((n1 == NULL) && (n2 == NULL) && (n3 == NULL));

    // ziskani normaly tri
    normala = u % v;
    normala.Normalization();

    // urceni parametru prvni roviny
    M[0] = n2->GetX() - n1->GetX();
    M[1] = n2->GetY() - n1->GetY();
    M[2] = n2->GetZ() - n1->GetZ();
    M[3] = (M[0] * ((n1->GetX() + n2->GetX())/2) ) + (M[1] * ((n1->GetY() + n2->GetY())/2) ) + (M[2] * ((n1->GetZ() + n2->GetZ())/2) );

    // urceni parametru druhe roviny
    M[4] = n3->GetX() - n1->GetX();
    M[5] = n3->GetY() - n1->GetY();
    M[6]= n3->GetZ() - n1->GetZ();
    M[7] = (M[4] * ((n1->GetX() + n3->GetX())/2) ) + (M[5] * ((n1->GetY() + n3->GetY())/2) ) + (M[6] * ((n1->GetZ() + n3->GetZ())/2) );

    // urceni parametru roviny tri
    M[8] = normala.GetX();
    M[9] = normala.GetY();
    M[10] = normala.GetZ();
    M[11] = (M[8]*n1->GetX()) + (M[9]*n1->GetY()) + (M[10]*n1->GetZ());

    // vypocteni stredu koule, reseni soustavy matice
    if (GausElimin(M, stred))
        throw std::logic_error("Chyba reseni soustavy pro vypocet koule Tri");

    // vypocet kontrolnich polomeru koule
    radius = stred.Distance(*n1);
}

////////////////////////////////////////////////////////////
//

void MCSphere::MakeSphereEdge(MCVertex * n1, MCVertex * n2)
{
    assert((n1 == NULL) && (n2 == NULL));

    // vypocet stredu koule
    stred.SetX( (n1->GetX() + n2->GetX()) / 2 );
    stred.SetY( (n1->GetY() + n2->GetY()) / 2 );
    stred.SetZ( (n1->GetZ() + n2->GetZ()) / 2 );

    // vypocet polomeru koule
    radius = stred.Distance(*n1);
}

////////////////////////////////////////////////////////////
//

int MCSphere::TestPoint(MCPoint3D & _point)
{
    // vypocet prirustku
    double dx = fabs(_point.GetX() - stred.GetX());
    double dy = fabs(_point.GetY() - stred.GetY());
    double dz = fabs(_point.GetZ() - stred.GetZ());

    // porovnani rozsahu
    if ( (radius < dx) || (radius < dy) || (radius < dz) ) return -1;

    // vypocet vzdalenosti od stredu
    double d = (dx * dx) + (dy * dy) + (dz * dz);

    //	porovnani vzdalenosti od stredu s polomerem
    double rr = radius * radius;
/*	if (d > rr)
    		return -1;
    	else if (d == rr)
    		return 0;*/
    if (fabs(d - rr) < DOUBLE_MIN)
        return 0;
    else if (d > rr)
        return -1;

    return 1;
}

////////////////////////////////////////////////////////////
//

int MCSphere::GausElimin(double * matice, MCPoint3D & vysledek)
{
    double					pom;
    double					pom_radek[4];


    // prehozeni radku pro posun max hodnoty na prvni pozici matice
    if (fabs(*(matice+4)) > fabs(*matice))
    {
        memcpy(pom_radek, (matice+0), sizeof(double)*4);
        memcpy((matice+0), (matice+4), sizeof(double)*4);
        memcpy((matice+4), pom_radek, sizeof(double)*4);
    }
    if (fabs(*(matice+8)) > fabs(*matice))
    {
        memcpy(pom_radek, (matice+0), sizeof(double)*4);
        memcpy((matice+0), (matice+8), sizeof(double)*4);
        memcpy((matice+8), pom_radek, sizeof(double)*4);
    }

    // eliminace matice na trojuhelnikovou
    if (*(matice+4) != 0.0)
    {
        pom = *matice / *(matice+4);
        *(matice+4) = 0.0;
        *(matice+5) = *(matice+1) - *(matice+5)*pom;
        *(matice+6) = *(matice+2) - *(matice+6)*pom;
        *(matice+7) = *(matice+3) - *(matice+7)*pom;
    }

    if (*(matice+8) != 0.0)
    {
        pom = *matice / *(matice+8);
        *(matice+8)  = 0.0;
        *(matice+9)  = *(matice+1) - *(matice+9)*pom;
        *(matice+10) = *(matice+2) - *(matice+10)*pom;
        *(matice+11) = *(matice+3) - *(matice+11)*pom;
    }

    // prehozeni radku pro posun max hodnoty na prvni pozici matice
    if (fabs(*(matice+9)) > fabs(*(matice+5)))
    {
        memcpy(pom_radek, (matice+5), sizeof(double)*3);
        memcpy((matice+5), (matice+9), sizeof(double)*3);
        memcpy((matice+9), pom_radek, sizeof(double)*3);
    }

    if (*(matice+9) != 0.0)
    {
        pom = *(matice+5) / *(matice+9);
        *(matice+9)  = 0.0;
        *(matice+10) = *(matice+6) - *(matice+10)*pom;
        *(matice+11) = *(matice+7) - *(matice+11)*pom;
    }

    // kontrola nulovosti diagonalnich prvku kvuli deleni nulou, neresitelna matice
    if ((*(matice+10) == 0.0) || (*(matice+5) == 0.0) || (*matice == 0.0))
        return -1;

    // vypocet vyslednych hodnot souradnic stredu koule
    vysledek.SetZ( *(matice+11) / *(matice+10) );
    vysledek.SetY( (*(matice+7) - *(matice+6)*vysledek.GetZ()) / *(matice+5) );
    vysledek.SetX( (*(matice+3) - *(matice+2)*vysledek.GetZ()  - *(matice+1)*vysledek.GetY()) / *matice );

    return 0;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

