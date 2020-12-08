////////////////////////////////////////////////////////////
// $Id: mctetras.cpp 1863 2010-08-31 20:40:15Z spanel $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// includes

#include <VectorEntity/mctetras.h>
#include <VectorEntity/mctri.h>
#include <VectorEntity/mcedge.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

MCTetra * MCTetraS::New(MCVertex * _u0, MCVertex * _u1, MCVertex * _u2, MCVertex * _u3)
{
    MCTetra				    * new_tetra;          // ukazatel na nove tetra

    assert((_u0 != NULL) && (_u1 != NULL) && (_u2 != NULL) && (_u3 != NULL));

    // test existence Tetra danych uzlu
    if ((new_tetra = TestExistence(_u0, _u1, _u2, _u3)) == NULL)
    {
        // vytvoreni noveho objektu Tetra
        new_tetra = new MCTetra(_u0, _u1, _u2, _u3);
        // vlozeni noveho Tetra do retezu
        AddNode(new_tetra);
        // registrace noveho Tetra u jejich uzlu
        new_tetra->Registration();
    }

    return new_tetra;
}

////////////////////////////////////////////////////////////
//

MCTetra * MCTetraS::New2(MCVertex * _u0, MCVertex * _u1, MCVertex * _u2, MCVertex * _u3)
{
    assert((_u0 != NULL) && (_u1 != NULL) && (_u2 != NULL) && (_u3 != NULL));

    // vytvoreni noveho objektu Tetra
    MCTetra *new_tetra = new MCTetra(_u0, _u1, _u2, _u3);
    // vlozeni noveho Tetra do retezu
    AddNode(new_tetra);
    // registrace noveho Tetra u jejich uzlu
    new_tetra->Registration();

    return new_tetra;
}

////////////////////////////////////////////////////////////
//

void MCTetraS::Erase( MCTetra * del_ent)
{
    assert(del_ent != NULL);

    // vyhozeni entity z retezce
    EraseNode(del_ent);

    // uvolneni vazeb entity u jejich node
    del_ent->DeRegistration();

    // zruseni objektu dane entity
    delete(del_ent);
}

////////////////////////////////////////////////////////////
//

void MCTetraS::DeRegistrationAll()
{
    MCTetra        * aktual = GetFirst();      // ukazatel na aktualni entitu


    // zruseni vsech existujicich entit s uvolnovanim vazeb
    while (aktual != NULL)
    {
        // odregistrovani aktualniho Tetra z jeho vrcholu
        aktual->DeRegistration();
        // ziskani nasledujici entity
        aktual = aktual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCTetraS::GetTetraEdge( MCVertex * _u0, MCVertex * _u1, std::vector<MCTetra *> & tetra_pole )
{
    assert((_u0 != NULL) && (_u1 != NULL));

    MCTetra				* aktual = _u0->GetRegisteredTetra();

    // vyprazdneni daneho pole
    tetra_pole.clear();

    // cyklus tetra retezce sousednich tetra pro node _u0
    while (aktual != NULL)
    {
        // test obsahu node _u1 v aktual
        if (aktual->IsVertexBool(_u1))
            tetra_pole.push_back(aktual);			// pridani aktual tetra do pole tetra

        // ziskani dalsi tetra retezce tetra
        aktual = aktual->GetVertexTetra(_u0);
    }
}

////////////////////////////////////////////////////////////
//

int MCTetraS::GetTetraEdgeNumber( MCVertex * _u0, MCVertex * _u1 )
{
    assert((_u0 != NULL) && (_u1 != NULL));

    MCTetra    * actual = _u0->GetRegisteredTetra();      // ukazatel na aktualni tetra kolem prvniho uzlu hrany
    int        poc_tetra = 0;                            // pocet tetra hrany


    // cyklus tetra kolem prvniho uzlu dane hrany
    while (actual != NULL)
    {
        // test aktual, jestli obsahuje druhy uzel hrany
        if (actual->IsVertexBool(_u1))
            poc_tetra++;

        // ziskani dalsiho tetra podilejiciho se na prvnim uzlu dane hrany
        actual = actual->GetVertexTetra(_u0);
    }

    return poc_tetra;
}

////////////////////////////////////////////////////////////
//

bool MCTetraS::TestTriExistence( MCVertex * _u0, MCVertex * _u1, MCVertex * _u2 )
{
    assert((_u0 != NULL) && (_u1 != NULL) && (_u2 != NULL));

    MCTetra			* soused = _u0->GetRegisteredTetra();


    // cyklus dalsich tetra kolem prvniho uzlu steny
    while (soused != NULL)
    {
        // test souseda, jestli obsahuje ostatni uzly steny
        if ( (soused->IsVertexBool(_u1)) && (soused->IsVertexBool(_u2)) )
            return true;

        // ziskani dalsiho tetra podilejiciho se na prvnim uzlu steny
        soused = soused->GetVertexTetra(_u0);
    }

    return false;
}

////////////////////////////////////////////////////////////
//

bool MCTetraS::TestEdgeExistence( MCVertex * _u0, MCVertex * _u1 )
{
    assert((_u0 != NULL) && (_u1 != NULL));

    MCTetra			* soused = _u0->GetRegisteredTetra();


    // cyklus dalsich tetra kolem prvniho uzlu steny
    while (soused != NULL)
    {
        // test souseda, jestli obsahuje ostatni uzly dane hrany
        if (soused->IsVertexBool(_u1))
            return true;

        // ziskani dalsiho tetra podilejiciho se na prvnim uzlu dane hrany
        soused = soused->GetVertexTetra(_u0);
    }

    return false;
}

////////////////////////////////////////////////////////////
//

MCTetra * MCTetraS::TestExistence(MCVertex * _u0, MCVertex * _u1, MCVertex * _u2, MCVertex * _u3)
{
    assert((_u0 != NULL) && (_u1 != NULL) && (_u2 != NULL) && (_u3 != NULL));

    MCTetra      * aktual = _u0->GetRegisteredTetra();            // ukazatel na tetra zdilejici prvni uzel hrany


    // cyklus tri kolem prvniho uzlu dane hrany
    while (aktual != NULL)
    {
        // test jestli aktualni tri obsahuje druhy a treti uzel daneho tri
        if (aktual->IsVertexBool(_u1) && aktual->IsVertexBool(_u2) && aktual->IsVertexBool(_u3))
            return aktual;                // tri existuje

        // ziskani dalsiho tri podilejiciho se na prvnim uzlu dane hrany
        aktual = aktual->GetVertexTetra(_u0);
    }

    // tri neexistuje
    return NULL;
}

////////////////////////////////////////////////////////////
//

void MCTetraS::MakeAllTetrasEdges()
{
    MCTetra      * actual = GetFirst();            // ukazatel na aktualni tetra site


    // cyklus tri site
    while (actual != NULL)
    {
        // vytvoreni hran aktualniho tetra
        MakeTetraEdges(actual);
        // ziskani nasledujiciho tetra
        actual = actual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCTetraS::MakeTetraEdges(MCTetra * _tetra)
{
    // test existence daneho tetra
    assert(_tetra != NULL);

    // vytvoreni hran daneho tetra
    edges->New(_tetra->GetVertex(0), _tetra->GetVertex(1));
    edges->New(_tetra->GetVertex(1), _tetra->GetVertex(2));
    edges->New(_tetra->GetVertex(2), _tetra->GetVertex(0));
    edges->New(_tetra->GetVertex(0), _tetra->GetVertex(3));
    edges->New(_tetra->GetVertex(1), _tetra->GetVertex(3));
    edges->New(_tetra->GetVertex(2), _tetra->GetVertex(3));
}

////////////////////////////////////////////////////////////
//

void MCTetraS::EraseVerticesNoTetras()
{
    MCVertex          * actual = vertices->GetFirst();
    MCVertex          * to_erase;                                    // ukazatel na vrchol urceny k vymazani


    // cyklus vrcholu site
    while (actual != NULL)
    {
        // test zda je pro vrchol registrovan nejaky tetra
        if (!actual->GetRegisteredTetra())
        {
            // ulozeni ukazatel na vrchol urceny k vymazani
            to_erase = actual;
            // ziskani nasledujiciho vrcholu retezce
            actual = actual->GetNext();
            // vymazani vrcholu
            vertices->Erase(to_erase);
        }
        else
            // ziskani nasledujiciho vrcholu retezce
            actual = actual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCTetraS::EraseEdgesNoTetras()
{
    MCEdge          * actual = edges->GetFirst();
    MCEdge          * to_erase;                                    // ukazatel na hranu urcenou k vymazani


    // cyklus hran site
    while (actual != NULL)
    {
        // ziskani a test poctu tetra aktualni hrany
        if (GetTetraEdgeNumber(actual->GetVertex(0), actual->GetVertex(1)) == 0)
        {
            // ulozeni ukazatel na hranu urcenou k vymazani
            to_erase = actual;
            // ziskani nasledujici hrany retezce
            actual = actual->GetNext();
            // vymazani hrany retezce, ktera nezdili zadne tetra
            edges->Erase(to_erase);
        }
        else
            // ziskani nasledujici hrany retezce
            actual = actual->GetNext();
    }
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
