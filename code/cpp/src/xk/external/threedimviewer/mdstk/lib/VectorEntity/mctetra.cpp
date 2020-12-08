////////////////////////////////////////////////////////////
// $Id: mctetra.cpp 1863 2010-08-31 20:40:15Z spanel $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// includes

#include <VectorEntity/mctetra.h>
#include <VectorEntity/mctri.h>
#include <VectorEntity/mcedge.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

void MCTetra::DeRegistration()
{
    MCTetra         * aktual, * predchozi;      // ukazatel na aktualni a predchozi entitu

    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // cyklus uzlu
    for (int i = 0; i < 4; ++i )
    {
        // ulozeni prvniho souseda i-teho uzlu jako aktual
        aktual = u[i]->GetRegisteredTetra();

        // kontrola nenulovosti prvniho souseda i-teho uzlu
        assert(aktual != NULL);

        // test, neni-li aktualni soused this
        if (aktual == this)
            // vlozeni souseda pro i-ty uzel do i-teho uzlu
            u[i]->SetRegisteredTetra(s[i]);
        else
        {
            // cyklus sousedu pro i-ty uzel
            while(aktual != this)
            {
                // ulozeni aktualniho souseda do predchoziho
                predchozi = aktual;
                // ziskani dalsiho souseda registrovaneho u i-teho uzlu
                aktual = aktual->GetVertexTetra(u[i]);
                // kontrola dosazeni konce retezce registrovanych sousedu
                assert(aktual != NULL);
            }
            // preklenuti sousedu z predchoziho na souseda i-teho uzlu
            predchozi->SetVertexTetra(u[i], s[i]);
        }

        // vynulovani odkazu na souseda pro i-ty uzel
        s[i] = NULL;
    }

    // deregistrace sousedu
    NeighboursDeRegistration();
}

////////////////////////////////////////////////////////////
//

MCVertex * MCTetra::GetRestVertex( MCVertex * _u0, MCVertex * _u1, MCVertex * _u2 )
{
    int           index_u0, index_u1, index_u2;     // indexy danych uzlu podle pozice v tetra


    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // test existence ukazatelu danych uzlu
    assert((_u0 != NULL) && (_u1 != NULL) && (_u2 != NULL) && (_u0 != _u1) && (_u0 != _u2) && (_u1 != _u2));

    // zjisteni indexu danych uzlu podle pozice v tri
    index_u0 = IsVertex(_u0);
    index_u1 = IsVertex(_u1);
    index_u2 = IsVertex(_u2);

    // kontrola hodnot indexu uzlu
    if ( index_u0 < 0 || index_u1 < 0 || index_u2 < 0 )
        return NULL;

    // prevod na binarni kod
    int index = 0xf ^ ((1 << index_u0) | (1 << index_u1) | (1 << index_u2));

    // urceni uzlu tetra, ktery je proti danemu tri
    switch( index )
    {
    case 1:
        return u[0];
    case 2:
        return u[1];
    case 4:
        return u[2];
    case 8:
        return u[3];
    default:
        return NULL;
    }
}

////////////////////////////////////////////////////////////
//

double MCTetra::GetMaxEdgeLength()
{
    double      delka, max_delka;


    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // vypocet a nalezeni max delky
    max_delka = MCPoint3D::SquareDistance(*u[0], *u[1]);

    delka = MCPoint3D::SquareDistance(*u[0], *u[2]);
    max_delka = (delka > max_delka) ? delka : max_delka ;

    delka = MCPoint3D::SquareDistance(*u[0], *u[3]);
    max_delka = (delka > max_delka) ? delka : max_delka ;

    delka = MCPoint3D::SquareDistance(*u[1], *u[2]);
    max_delka = (delka > max_delka) ? delka : max_delka ;

    delka = MCPoint3D::SquareDistance(*u[1], *u[3]);
    max_delka = (delka > max_delka) ? delka : max_delka ;

    delka = MCPoint3D::SquareDistance(*u[2], *u[3]);
    max_delka = (delka > max_delka) ? delka : max_delka ;

    // vraceni maximalni delky
    return sqrt(max_delka);
}

////////////////////////////////////////////////////////////
//

double MCTetra::GetMinEdgeLength()
{
    double      delka, min_delka;


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // vypocet a nalezeni max delky
    min_delka = MCPoint3D::SquareDistance(*u[0], *u[1]);

    delka = MCPoint3D::SquareDistance(*u[0], *u[2]);
    min_delka = (delka < min_delka) ? delka : min_delka;

    delka = MCPoint3D::SquareDistance(*u[0], *u[3]);
    min_delka = (delka < min_delka) ? delka : min_delka;

    delka = MCPoint3D::SquareDistance(*u[1], *u[2]);
    min_delka = (delka < min_delka) ? delka : min_delka;

    delka = MCPoint3D::SquareDistance(*u[1], *u[3]);
    min_delka = (delka < min_delka) ? delka : min_delka;

    delka = MCPoint3D::SquareDistance(*u[2], *u[3]);
    min_delka = (delka < min_delka) ? delka : min_delka;

    // vraceni minimalni delky
    return sqrt(min_delka);
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetMaxEdge( MCVertex ** _u0, MCVertex ** _u1 )
{
    double      delka, max_delka;


    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // nalezeni max hrany
    max_delka = MCPoint3D::SquareDistance(*u[0], *u[1]);
    *_u0 = u[0];
    *_u1 = u[1];

    delka = MCPoint3D::SquareDistance(*u[0], *u[2]);
    if (delka > max_delka)
    {
        max_delka = delka;
        *_u0 = u[0];
        *_u1 = u[2];
    }

    delka = MCPoint3D::SquareDistance(*u[0], *u[3]);
    if (delka > max_delka)
    {
        max_delka = delka;
        *_u0 = u[0];
        *_u1 = u[3];
    }

    delka = MCPoint3D::SquareDistance(*u[1], *u[2]);
    if (delka > max_delka)
    {
        max_delka = delka;
        *_u0 = u[1];
        *_u1 = u[2];
    }

    delka = MCPoint3D::SquareDistance(*u[1], *u[3]);
    if (delka > max_delka)
    {
        max_delka = delka;
        *_u0 = u[1];
        *_u1 = u[3];
    }

    delka = MCPoint3D::SquareDistance(*u[2], *u[3]);
    if (delka > max_delka)
    {
        max_delka = delka;
        *_u0 = u[2];
        *_u1 = u[3];
    }
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetMinEdge( MCVertex ** _u0, MCVertex ** _u1 )
{
    double      delka, min_delka;


    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // nalezeni max hrany
    min_delka = MCPoint3D::SquareDistance(*u[0], *u[1]);
    *_u0 = u[0];
    *_u1 = u[1];

    delka = MCPoint3D::SquareDistance(*u[0], *u[2]);
    if (delka < min_delka)
    {
        min_delka = delka;
        *_u0 = u[0];
        *_u1 = u[2];
    }

    delka = MCPoint3D::SquareDistance(*u[0], *u[3]);
    if (delka < min_delka)
    {
        min_delka = delka;
        *_u0 = u[0];
        *_u1 = u[3];
    }

    delka = MCPoint3D::SquareDistance(*u[1], *u[2]);
    if (delka < min_delka)
    {
        min_delka = delka;
        *_u0 = u[1];
        *_u1 = u[2];
    }

    delka = MCPoint3D::SquareDistance(*u[1], *u[3]);
    if (delka < min_delka)
    {
        min_delka = delka;
        *_u0 = u[1];
        *_u1 = u[3];
    }

    delka = MCPoint3D::SquareDistance(*u[2], *u[3]);
    if (delka < min_delka)
    {
        min_delka = delka;
        *_u0 = u[2];
        *_u1 = u[3];
    }
}

////////////////////////////////////////////////////////////
//

MCVertex * MCTetra::GetRestVertex( int index )
{
    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // steny tetra s normalou smerujici do stredu
    switch (index)
    {
    case 0:
        return u[3];
    case 1:
        return u[2];
    case 2:
        return u[0];
    case 3:
        return u[1];
    default:
        // neexistujici stena tetra
        assert(false);
        return NULL;
    }
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetTri(int index, MCVertex ** _u0, MCVertex ** _u1, MCVertex ** _u2) const
{
    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // steny tetra s normalou smerujici do stredu
    switch (index)
    {
    case 0:
        *_u0 = u[0];
        *_u1 = u[1];
        *_u2 = u[2];
        break;

    case 1:
        *_u0 = u[0];
        *_u1 = u[3];
        *_u2 = u[1];
        break;

    case 2:
        *_u0 = u[1];
        *_u1 = u[3];
        *_u2 = u[2];
        break;

    case 3:
        *_u0 = u[2];
        *_u1 = u[3];
        *_u2 = u[0];
        break;

    default:
        // neexistujici stena tetra
        assert(false);
        break;
    }
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetTri(int index, int * _u0, int * _u1, int * _u2) const
{
    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // steny tetra s normalou smerujici do stredu
    switch (index)
    {
    case 0:
        *_u0 = 0;
        *_u1 = 1;
        *_u2 = 2;
        break;

    case 1:
        *_u0 = 0;
        *_u1 = 3;
        *_u2 = 1;
        break;

    case 2:
        *_u0 = 1;
        *_u1 = 3;
        *_u2 = 2;
        break;

    case 3:
        *_u0 = 2;
        *_u1 = 3;
        *_u2 = 0;
        break;

    default:
        // neexistujici stena tetra
        assert(false);
        break;
    }
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetRestTri( int index, MCVertex ** _u0, MCVertex ** _u1, MCVertex ** _u2 ) const
{
    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // steny tetra s normalou smerujici do stredu
    switch (index)
    {
    case 0:
        *_u0 = u[1];
        *_u1 = u[2];
        *_u2 = u[3];
        break;

    case 1:
        *_u0 = u[0];
        *_u1 = u[2];
        *_u2 = u[3];
        break;

    case 2:
        *_u0 = u[0];
        *_u1 = u[1];
        *_u2 = u[3];
        break;

    case 3:
        *_u0 = u[0];
        *_u1 = u[1];
        *_u2 = u[2];
        break;

    default:
        // neexistujici stena tetra
        assert(false);
        break;
    }
}


////////////////////////////////////////////////////////////
//

double MCTetra::GetArea()
{
    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    MCTri t1(u[0], u[1], u[2]),
    t2(u[0], u[3], u[1]),
    t3(u[1], u[3], u[2]),
    t4(u[2], u[3], u[0]);

    // vraceni plochy tetra
    return (t1.GetArea() + t2.GetArea() + t3.GetArea() + t4.GetArea());
}

////////////////////////////////////////////////////////////
//

double MCTetra::GetVolume()
{
    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    MCVector3D _u(u[0], u[1]), _v(u[0], u[2]), _w(u[0], u[3]), vs;

    // vypocet vektoroveho soucinu vektoru podstavy
    vs = _u % _v;

    // vypocet objemu jako 1/6 skalarniho soucinu normaly postavy s vektorem k vrcholu
    return ( (vs * _w) * 0.1666667 );
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetCenter(MCPoint3D & _center)
{
    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // pomocna konstanta
    static const double quarter = 0.25;

    // vypocet stredu tri
    _center.SetX( (u[0]->GetX() + u[1]->GetX() + u[2]->GetX() + u[3]->GetX()) * quarter );
    _center.SetY( (u[0]->GetY() + u[1]->GetY() + u[2]->GetY() + u[3]->GetY()) * quarter );
    _center.SetZ( (u[0]->GetZ() + u[1]->GetZ() + u[2]->GetZ() + u[3]->GetZ()) * quarter );
}

////////////////////////////////////////////////////////////
//

MCVector3D MCTetra::GetNormal(int index) const
{
    MCVertex        * temp[3];
    MCVector3D      normal;

    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // vrcholy tri
    GetTri(index, temp, temp + 1, temp + 2);

    // vektory
    MCVector3D v01(temp[0], temp[1]), v02(temp[0], temp[2]);

    // vypocet normaly
    normal.VectorProduct(v01, v02);

    // normalizace normaly
    normal.Normalization();

    return normal;
}

////////////////////////////////////////////////////////////
//

MCVector3D MCTetra::GetNormal2(int index) const
{
    MCVertex        * temp[3];
    MCVector3D      normal;

    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // vrcholy tri
    GetTri(index, temp, temp + 1, temp + 2);

    // vektory
    MCVector3D v01(temp[0], temp[1]), v02(temp[0], temp[2]);

    // vypocet normaly
    normal.VectorProduct(v01, v02);

    return normal;
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetNormal(int index, MCVector3D & normal) const
{
    MCVertex        * temp[3];

    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // vrcholy tri
    GetTri(index, temp, temp + 1, temp + 2);

    // vektory
    MCVector3D v01(temp[0], temp[1]), v02(temp[0], temp[2]);

    // vypocet normaly
    normal.VectorProduct(v01, v02);

    // normalizace normaly
    normal.Normalization();
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetNormal2(int index, MCVector3D & normal) const
{
    MCVertex        * temp[3];

    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // vrcholy tri
    GetTri(index, temp, temp + 1, temp + 2);

    // vektory
    MCVector3D v01(temp[0], temp[1]), v02(temp[0], temp[2]);

    // vypocet normaly
    normal.VectorProduct(v01, v02);
}

////////////////////////////////////////////////////////////
//

void MCTetra::GetNeighboursByVertices( MCTetra * sousedi[4] )
{
    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    MCTetra       * soused = u[0]->GetRegisteredTetra();

    // nulovani navratoveho pole
    sousedi[0] = NULL;
    sousedi[1] = NULL;
    sousedi[2] = NULL;
    sousedi[3] = NULL;

    // cyklus dalsich tetra kolem prvniho uzlu tetra
    while (soused != NULL)
    {
        // test neni-li soused totozny s this, pro jeho vylouceni
        if (soused != this)
        {
            // test souseda, jestli obsahuje ostatni uzly sten
            if ( soused->IsVertexBool(u[1]) && soused->IsVertexBool(u[2]) )
                sousedi[0] = soused;
            if ( soused->IsVertexBool(u[3]) && soused->IsVertexBool(u[1]) )
                sousedi[1] = soused;
            if ( soused->IsVertexBool(u[2]) && soused->IsVertexBool(u[3]) )
                sousedi[3] = soused;
        }
        // ziskani dalsiho tetra podilejiciho se na prvnim uzlu steny
        soused = soused->GetVertexTetra(u[0]);
    }

    // ziskani prvniho tetra kolem uzlu 1 tetra
    soused = u[1]->GetRegisteredTetra();

    // cyklus dalsich tetra kolem uzlu 1 tetra
    while (soused != NULL)
    {
        // test souseda, jestli obsahuje ostatni uzly steny 1 a zaroven jestli neni this
        if ( soused->IsVertexBool(u[3]) && soused->IsVertexBool(u[2]) && (soused != this) )
        {
            sousedi[2] = soused;
            return;
        }
        // ziskani dalsiho tetra podilejiciho se na prvnim uzlu steny
        soused = soused->GetVertexTetra(u[1]);
    }
}

////////////////////////////////////////////////////////////
//

MCTetra * MCTetra::GetNeighbourByVertices( int _index )
{
    MCVertex      * temp[3];
    MCTetra       * soused;                       // ukazatel na sousedni tetra


    // test existence uzlu tetra
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // vrcholy tri
    GetTri(_index, temp, temp + 1, temp + 2);

    // ziskani ukazatele na prvni uzel kolem prvniho uzlu
    soused = temp[0]->GetRegisteredTetra();

    // cyklus dalsich tri kolem prvniho uzlu hrany
    while (soused != NULL)
    {
        // test souseda, jestli obsahuje ostatni uzly tri a neni to this
        if ( (soused->IsVertexBool(temp[1])) && (soused->IsVertexBool(temp[2])) && (soused != this) )
            return soused;
        // ziskani dalsiho tri podilejiciho se na prvnim uzlu tri
        soused = soused->GetVertexTetra(temp[0]);
    }

    return NULL;
}

////////////////////////////////////////////////////////////
//

void MCTetra::InverseOrientation()
{
    MCVertex        * uzel_pom;      // pomocny ukazatel na vrchol
    MCTetra         * sous_pom;      // pomocny ukazatel na tetra

    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL) && (u[3] != NULL));

    // vymena 1. a 2. ukazatele na vrcholy tri
    uzel_pom = u[2];
    u[2] = u[1];
    u[1] = uzel_pom;

    // vymena 1. a 2. ukazatele na asociovane tetra
    sous_pom = s[2];
    s[2] = s[1];
    s[1] = sous_pom;

    // vymena 1. a 3. ukazatele na sousedy
    sous_pom = n[3];
    n[3] = n[1];
    n[1] = sous_pom;
}

////////////////////////////////////////////////////////////
//

void MCTetra::NeighboursRegistration()
{
  // the tetra neighbours actualization
  NeighboursActualization();

  // neighbours actualization for the tetra neighbour index 0
  if (n[0] != NULL)     n[0]->NeighboursActualization();
  // neighbours actualization for the tetra neighbour index 1
  if (n[1] != NULL)     n[1]->NeighboursActualization();
  // neighbours actualization for the tetra neighbour index 2
  if (n[2] != NULL)     n[2]->NeighboursActualization();
  // neighbours actualization for the tetra neighbour index 3
  if (n[3] != NULL)     n[3]->NeighboursActualization();
}

////////////////////////////////////////////////////////////
//

void MCTetra::NeighboursDeRegistration()
{
  // neighbours actualization for the tetra neighbour index 0
  if (n[0] != NULL)     n[0]->NeighboursActualization();
  // neighbours actualization for the tetra neighbour index 1
  if (n[1] != NULL)     n[1]->NeighboursActualization();
  // neighbours actualization for the tetra neighbour index 2
  if (n[2] != NULL)     n[2]->NeighboursActualization();
  // neighbours actualization for the tetra neighbour index 3
  if (n[3] != NULL)     n[3]->NeighboursActualization();

  // set direct neighbours pointers on NULL
  n[0] = n[1] = n[2] = n[3] = NULL;
}

////////////////////////////////////////////////////////////
//

//void MCTetra::()
//{
//
//}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
