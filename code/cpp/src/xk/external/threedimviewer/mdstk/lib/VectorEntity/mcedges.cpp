////////////////////////////////////////////////////////////
// $Id: mcedges.cpp 1520 2009-11-12 18:20:20Z krsek $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// includes

#include <VectorEntity/mcedges.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

MCEdge * MCEdgeS::New( MCVertex * _u0, MCVertex * _u1 )
{
    MCEdge * new_hrana;          // ukazatel na novou hranu

    assert((_u0 != NULL) && (_u1 != NULL));

    // test existence pracovniho hrany
    if ((new_hrana = TestExistence(_u0, _u1)) == NULL)
    {
        // vytvoreni noveho objektu hrany
        new_hrana = new MCEdge(_u0, _u1);
        // vlozeni nove hrany do retezu
        AddNode(new_hrana);
        // registrace nove hrany u jejich uzlu
        new_hrana->Registration();
    }

    return new_hrana;
}


////////////////////////////////////////////////////////////
//

MCEdge * MCEdgeS::NewNoTestExistence( MCVertex * _u0, MCVertex * _u1 )
{
    MCEdge           * new_hrana;          // ukazatel na novou hranu

    assert((_u0 != NULL) && (_u1 != NULL));

    // vytvoreni noveho objektu hrany
    new_hrana = new MCEdge(_u0, _u1);
    // vlozeni nove hrany do retezu
    AddNode(new_hrana);
    // registrace nove hrany u jejich uzlu
    new_hrana->Registration();

    return new_hrana;
}

////////////////////////////////////////////////////////////
//

void MCEdgeS::Erase(MCEdge * del_ent)
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

void MCEdgeS::DeRegistrationAll()
{
    MCEdge        * aktual = GetFirst();      // ukazatel na aktualni entitu

    // zruseni vsech existujicich entit s uvolnovanim vazeb
    while (aktual != NULL)
    {
        // odregistrovani aktualniho Edge z jeho vrcholu
        aktual->DeRegistration();
        // ziskani nasledujici entity
        aktual = aktual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

MCEdge * MCEdgeS::TestExistence(MCVertex * _u0, MCVertex * _u1)
{
    assert((_u0 != NULL) && (_u1 != NULL));

    MCEdge       * aktual = _u0->GetRegisteredEdge();    // ukazatel na hranu zdilejici prvni uzel dane hrany

    // cyklus hran kolem prvniho uzlu dane hrany
    while (aktual != NULL)
    {
        // test jestli aktualni hrana obsahuje druhy uzel dane hrany
        if (aktual->IsVertexBool(_u1))
            return aktual;                // hrana existuje

        // ziskani dalsiho tri podilejiciho se na prvnim uzlu dane hrany
        aktual = aktual->GetVertexEdge(_u0);
    }

    // hrana neexistuje
    return NULL;
}

////////////////////////////////////////////////////////////
//

void MCEdgeS::ClearAll()
{
    // call ClearAll() from MCEntitieS
    MCEntitieS<MCEdge>::ClearAll();

	// get pointer on first vertex of the container
	MCVertex	* actual_vertex = (GetVerticeS())->GetFirst();

	// cycle of all vertices of the container
	while (actual_vertex != NULL)
	{
        // remove pointer on edge from actual vortex
        actual_vertex->SetRegisteredEdge(NULL);

		// take next vertex of the container
		actual_vertex = actual_vertex->GetNext();
	}
}

////////////////////////////////////////////////////////////
//

//void MCEdgeS::()
//{
//}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
