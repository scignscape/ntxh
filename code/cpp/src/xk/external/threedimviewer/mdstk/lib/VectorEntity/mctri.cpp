////////////////////////////////////////////////////////////
// $Id: mctri.cpp 1863 2010-08-31 20:40:15Z spanel $
////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
// includes

#include <VectorEntity/mctri.h>
#include <VectorEntity/mcedge.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

void MCTri::DeRegistration()
{
    MCTri         * aktual, * predchozi;      // ukazatel na aktualni a predchozi entitu


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // cyklus uzlu
    for (int i = 0; i < 3; i++ )
    {
        // ulozeni prvniho souseda i-teho uzlu jako aktual
        aktual = u[i]->GetRegisteredTri();

        // kontrola nenulovosti prvniho souseda i-teho uzlu
        assert(aktual != NULL);

        // test, neni-li aktualni soused this
        if (aktual == this)
            // vlozeni souseda pro i-ty uzel do i-teho uzlu
            u[i]->SetRegisteredTri(s[i]);
        else
        {
            // cyklus sousedu pro i-ty uzel
            while(aktual != this)
            {
                // ulozeni aktualniho souseda do predchoziho
                predchozi = aktual;
                // ziskani dalsiho souseda registrovaneho u i-teho uzlu
                aktual = aktual->GetVertexTri(u[i]);
                // kontrola dosazeni konce retezce registrovanych sousedu
                assert(aktual != NULL);
            }
            // preklenuti sousedu z predchoziho na souseda i-teho uzlu
            predchozi->SetVertexTri(u[i], s[i]);
        }

        // vynulovani odkazu na souseda pro i-ty uzel
        s[i] = NULL;
    }
}

////////////////////////////////////////////////////////////
//

void MCTri::GetRestEdge( MCVertex * _uzel, MCVertex ** _u0, MCVertex ** _u1 )
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // test existence ukazatelu danych uzlu
    assert((_uzel != NULL) && (_u0 != NULL) && (_u1 != NULL));

    // kontrola existence uzlu v tri
    assert(IsVertexBool(_uzel) == true);

    // urceni uzlu tri, proti kteremu lezi pozadovana hrana
    if (_uzel == u[0])
    {
        *_u0 = u[1];        // ulozeni uzlu hrany do daneho pole
        *_u1 = u[2];
    }
    else if (_uzel == u[1])
    {
        *_u0 = u[2];
        *_u1 = u[0];
    }
    else if (_uzel == u[2])
    {
        *_u0 = u[0];
        *_u1 = u[1];
    }
    else
    {
        _u0 = NULL;
        _u1 = NULL;
    }
}

////////////////////////////////////////////////////////////
//

MCVertex * MCTri::GetRestVertex( MCVertex * _u0, MCVertex * _u1 )
{
    int           index_u0, index_u1;             // indexy danych uzlu podle pozice v tri


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // test existence ukazatelu danych uzlu
    assert((_u0 != NULL) && (_u1 != NULL) && (_u0 != _u1));

    // zjisteni indexu danych uzlu podle pozice v tri
    index_u0 = IsVertex(_u0);
    index_u1 = IsVertex(_u1);

    // kontrola hodnot indexu uzlu
    assert((index_u0 >= 0) && (index_u0 <= 2));
    assert((index_u1 >= 0) && (index_u1 <= 2));

    // urceni uzlu tri, ktery je proti dane hrane
    if ( ((index_u0 == 0) && (index_u1 == 1)) || ((index_u0 == 1) && (index_u1 == 0)) )
        return u[2];
    else if ( ((index_u0 == 2) && (index_u1 == 0)) || ((index_u0 == 0) && (index_u1 == 2)) )
        return u[1];
    else if ( ((index_u0 == 1) && (index_u1 == 2)) || ((index_u0 == 2) && (index_u1 == 1)) )
        return u[0];
    else
        return NULL;
}

////////////////////////////////////////////////////////////
//

double MCTri::GetMaxEdge( MCVertex ** _u0, MCVertex ** _u1 )
{
    double      d[3];                 // pole delek hran
    int           max_index;          // index nalezene max hrany


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // test existence ukazatelu na vrcholy
    assert((_u0 != NULL) && (_u1 != NULL) && (_u0 != _u1));

    // vypocet delek hran tri
    d[0] = MCPoint3D::Distance(*u[0], *u[1]);
    d[1] = MCPoint3D::Distance(*u[1], *u[2]);
    d[2] = MCPoint3D::Distance(*u[2], *u[0]);

    // nalezeni indexu max hrany
    max_index = (d[0] > d[1]) ? ((d[0] > d[2]) ? 0 : 2) : ((d[1] > d[2]) ? 1 : 2);

    // nastaveni ukazatelu na uzly nalezene max hrany
    *_u0 = u[max_index];
    *_u1 = (max_index < 2) ? u[max_index + 1] : u[0];

    // vraceni maximalni delky
    return d[max_index];
}

////////////////////////////////////////////////////////////
//

double MCTri::GetMaxEdge( MCEdge ** max_hrana )
{
    MCEdge      * reg_hrana;                // ukazatel na registrovanou hranu pro dany uzel
    double      max_delka;                  // delka maximalni hrany
    MCVertex    * h_u0, * h_u1;             // ukazatele na uzly max hrany


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // test existence ukazatele na max hranu
    assert(max_hrana != NULL);

    // inicializace ukazatele na max hranu
    *max_hrana = NULL;

    // ziskani max hrany tri danou uzly
    max_delka = GetMaxEdge(&h_u0, &h_u1);

    // nalezeni objektu hrany podle ziskanych uzlu
    // inicializace prvni hrany kolem node
    reg_hrana = h_u0->GetRegisteredEdge();

    // cyklus dalsich hran kolem prvniho uzlu tri
    while (reg_hrana != NULL)
    {
        // test hrany, jestli obsahuje druhy uzel dane hrany
        if (reg_hrana->IsVertexBool(h_u1))
            *max_hrana = reg_hrana;
        // ziskani dalsiho hran podilejiciho se na prvnim uzlu tri
        reg_hrana = reg_hrana->GetVertexEdge(h_u0);
    }

    // vraceni maximalni delky
    return max_delka;
}

////////////////////////////////////////////////////////////
//

int MCTri::GetMaxEdge()
{
    double      d[3];


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // vypocet delek hran tri
    d[0] = MCPoint3D::Distance(*u[0], *u[1]);
    d[1] = MCPoint3D::Distance(*u[1], *u[2]);
    d[2] = MCPoint3D::Distance(*u[2], *u[0]);

    // nalezeni max hrany
    return ( (d[0] > d[1]) ? ((d[0] > d[2]) ? 0 : 2) : ((d[1] > d[2]) ? 1 : 2) );
}

////////////////////////////////////////////////////////////
//

double MCTri::GetMaxEdgeLength()
{
    double      delka, max_delka = -1;


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // vypocet a nalezeni max delky
    delka = MCPoint3D::Distance(*u[0], *u[1]);
    max_delka = (delka > max_delka) ? delka : max_delka ;

    delka = MCPoint3D::Distance(*u[1], *u[2]);
    max_delka = (delka > max_delka) ? delka : max_delka ;

    delka = MCPoint3D::Distance(*u[2], *u[0]);
    max_delka = (delka > max_delka) ? delka : max_delka ;

    // vraceni maximalni delky
    return max_delka;
}

////////////////////////////////////////////////////////////
//

double MCTri::GetMinEdgeLength()
{
    double      delka, min_delka = 1000000000;


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // vypocet a nalezeni max delky
    delka = MCPoint3D::Distance(*u[0], *u[1]);
    min_delka = (delka < min_delka) ? delka : min_delka;

    delka = MCPoint3D::Distance(*u[1], *u[2]);
    min_delka = (delka < min_delka) ? delka : min_delka;

    delka = MCPoint3D::Distance(*u[2], *u[0]);
    min_delka = (delka < min_delka) ? delka : min_delka;

    // vraceni minimalni delky
    return min_delka;
}

////////////////////////////////////////////////////////////
//

double MCTri::GetCircuit()
{
    double      obvod;


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // vypocet obvodu
    obvod = MCPoint3D::Distance(*u[0], *u[1]);
    obvod += MCPoint3D::Distance(*u[1], *u[2]);
    obvod += MCPoint3D::Distance(*u[2], *u[0]);

    // vraceni obvodu tri
    return obvod;
}

////////////////////////////////////////////////////////////
//

double MCTri::GetArea()
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    MCVector3D        v01(u[0], u[1]), v02(u[0], u[2]);

    // vypocet a vraceni plochy tri
    return ( (v01 % v02).Length() / 2 );
}

////////////////////////////////////////////////////////////
//

void MCTri::GetCenter(MCPoint3D & _center)
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // pomocna konstanta
    static const double third = 0.333333333333333;

    // vypocet stredu tri
    _center.SetX( (u[0]->GetX() + u[1]->GetX() + u[2]->GetX()) * third );
    _center.SetY( (u[0]->GetY() + u[1]->GetY() + u[2]->GetY()) * third );
    _center.SetZ( (u[0]->GetZ() + u[1]->GetZ() + u[2]->GetZ()) * third );
}

////////////////////////////////////////////////////////////
//

MCVector3D MCTri::GetNormal()
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    MCVector3D      v01(u[0], u[1]), v02(u[0], u[2]), normala;

    // vypocet normaly
    normala.VectorProduct(v01, v02);

    // normalizace normaly
    normala.Normalization();

    return normala;
}

////////////////////////////////////////////////////////////
//

void MCTri::GetNormal(MCVector3D & normala)
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    MCVector3D      v01(u[0], u[1]), v02(u[0], u[2]);

    // vypocet normaly
    normala.VectorProduct(v01, v02);

    // normalizace normaly
    normala.Normalization();
}

////////////////////////////////////////////////////////////
//

void MCTri::GetPlane( double & A, double & B, double & C, double & D )
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    MCVector3D            normala;

    // ziskani normaly roviny tri
    normala = GetNormal();

    // prirazeni prvnich tri parametru roviny
    A = normala.GetX();
    B = normala.GetY();
    C = normala.GetZ();

    // vypocet parametru D rovnice roviny
    D = -1*( A * u[0]->GetX() + B * u[0]->GetY() + C * u[0]->GetZ() );
}

////////////////////////////////////////////////////////////
//

void MCTri::GetNeighbours( MCTri * sousedi[3] )
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    MCTri       * soused = u[0]->GetRegisteredTri();

    // nulovani navratoveho pole
    sousedi[0] = NULL;
    sousedi[1] = NULL;
    sousedi[2] = NULL;

    // cyklus dalsich tri kolem prvniho uzlu tri
    while (soused != NULL)
    {
        // test neni-li soused totozny s this, pro jeho vylouceni
        if (soused != this)
        {
            // test souseda, jestli obsahuje ostatni uzly hran 0, 2
            if ( soused->IsVertexBool(u[1]) )
                sousedi[0] = soused;
            if ( soused->IsVertexBool(u[2]) )
                sousedi[2] = soused;
        }
        // ziskani dalsiho tri podilejiciho se na prvnim uzlu hrany
        soused = soused->GetVertexTri(u[0]);
    }

    // ziskani prvniho tri kolem uzlu 1 tri
    soused = u[1]->GetRegisteredTri();

    // cyklus dalsich tri kolem uzly 1 tri
    while (soused != NULL)
    {
        // test souseda, jestli obsahuje ostatni uzly steny 1 a zaroven jestli neni this
        if ( (soused->IsVertexBool(u[2])) && (soused != this) )
        {
            sousedi[1] = soused;
            return;
        }
        // ziskani dalsiho tri podilejiciho se na prvnim uzlu hrany
        soused = soused->GetVertexTri(u[1]);
    }
}

////////////////////////////////////////////////////////////
//

MCTri * MCTri::GetNeighbour( int _index )
{
    MCTri         * soused;                       // ukazatel na sousedni tri
    int           index_u0 = _index, index_u1;    // indexy uzlu pro dany index souseda


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // inicializace indexu uzlu pro dany index hrany
    index_u1 = ((_index + 1) > 2) ? 0 : (_index + 1);

    // ziskani ukazatele na prvni uzel kolem prvniho uzlu
    soused = u[index_u0]->GetRegisteredTri();

    // cyklus dalsich tri kolem prvniho uzlu hrany
    while (soused != NULL)
    {
        // test souseda, jestli obsahuje ostatni uzly hrany a neni to this
        if ( (soused->IsVertexBool(u[index_u1])) && (soused != this) )
            return soused;
        // ziskani dalsiho tri podilejiciho se na prvnim uzlu hrany
        soused = soused->GetVertexTri(u[index_u0]);
    }

    return NULL;
}

////////////////////////////////////////////////////////////
//

void MCTri::GetEdges(MCEdge * hrany_tri[3])
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    MCEdge      * hrana = u[0]->GetRegisteredEdge();

    // inicializace vystupniho pole hran tri
    hrany_tri[0] = NULL;
    hrany_tri[1] = NULL;
    hrany_tri[2] = NULL;

    // cyklus dalsich hran kolem prvniho uzlu tri
    while (hrana != NULL)
    {
        // test hrany, jestli obsahuje ostatni uzly tri
        if (hrana->IsVertexBool(u[1]))
            hrany_tri[0] = hrana;
        if (hrana->IsVertexBool(u[2]))
            hrany_tri[2] = hrana;
        // ziskani dalsiho hran podilejiciho se na prvnim uzlu tri
        hrana = hrana->GetVertexEdge(u[0]);
    }

    // ziskani prvni hrany posledniho uzlu tri
    hrana = u[2]->GetRegisteredEdge();

    // cyklus dalsich hran kolem posledniho uzlu tri
    while (hrana != NULL)
    {
        // test hrany, jestli obsahuje ostatni uzly tri
        if (hrana->IsVertexBool(u[1]))
            hrany_tri[1] = hrana;
        // ziskani dalsiho hran podilejiciho se na prvnim uzlu tri
        hrana = hrana->GetVertexEdge(u[2]);
    }
}

////////////////////////////////////////////////////////////
//

MCEdge * MCTri::GetEdge(int index)
{
    MCEdge      * hrana;                        // ukazatel na prohledavane hrany
    int         index_u0 = index, index_u1;     // indexy uzlu pro dany index hrany


    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // inicializace indexu uzlu pro dany index hrany
    index_u1 = ((index + 1) > 2) ? 0 : (index + 1);

    // ziskani ukazatele na prvni uzel kolem prvniho uzlu
    hrana = u[index_u0]->GetRegisteredEdge();

    // cyklus dalsich hran kolem prvniho uzlu tri
    while (hrana != NULL)
    {
        // test hrany, jestli obsahuje druhy uzel dane hrany
        if (hrana->IsVertexBool(u[index_u1]))
            return hrana;
        // ziskani dalsiho hran podilejiciho se na prvnim uzlu tri
        hrana = hrana->GetVertexEdge(u[index_u0]);
    }

    return NULL;
}

////////////////////////////////////////////////////////////
//

void MCTri::GetEdge(int _index, MCVertex ** _u0, MCVertex ** _u1)
{
    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // kontrola indexu hrany
    assert((_index >= 0) && (_index < 3));
    // test existence ukazatelu na vrcholy
    assert((_u0 != NULL) && (_u1 != NULL));

    // nastaveni ukazatelu na uzly nalezene max hrany
    *_u0 = u[_index];
    *_u1 = (_index < 2) ? u[_index + 1] : u[0];
}

////////////////////////////////////////////////////////////
//

void MCTri::InverseOrientation()
{
    MCVertex        * uzel_pom;      // pomocny ukazatel na vrchol
    MCTri             * sous_pom;      // pomocny ukazatel na tri

    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL) && (u[2] != NULL));

    // vymena 1. a 2. ukazatele na vrcholy tri
    uzel_pom = u[2];
    u[2] = u[1];
    u[1] = uzel_pom;

    // vymena 1. a 2. ukazatele na asociovane tri
    sous_pom = s[2];
    s[2] = s[1];
    s[1] = sous_pom;
}

////////////////////////////////////////////////////////////
//

int MCTri::CompareTriOrientation(MCTri * test_tri)
{
    MCVector3D        n1, n2;      // pomocne vektory normal tri
    double            soucin;      // vysledek skalarniho soucinu vektoru


    assert(test_tri != NULL);

    // ziskani normaly obou tri
    n1 = GetNormal();
    n2 = test_tri->GetNormal();

    // skalarni soucin normal
    soucin = n1 * n2;

    // vyhodnoceni vzajemne orientace obou tri
    return ((soucin < 0) ? -1 : ((soucin > 0) ? 1 : 0));
}

////////////////////////////////////////////////////////////
//

//int MCTri::()
//{
//
//}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
