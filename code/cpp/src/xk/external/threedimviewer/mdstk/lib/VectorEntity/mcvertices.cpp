////////////////////////////////////////////////////////////
// $Id: mcvertices.cpp 1547 2009-12-15 17:01:26Z krsek $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// includes

#include <VectorEntity/mcvertices.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

MCVertex * MCVerticeS::New( MCPoint3D & new_bod )
{
    MCVertex          * new_node;


    // vetveni podle provadeni testovani existence vrcholu
    if (test_existence)       // provadi se testovani existence
    {
        // nastaveni parametru vytvareneho uzlu do pracovniho uzlu
        work_node.SetPoint3D(new_bod);
        // vypocet hash kodu pro souradnice noveho bodu
        work_node.MakeHashCode();

        // test existence pracovniho uzlu
        if ((new_node = TestExistence(&work_node)) == NULL)
        {
            // vytvoreni noveho objektu uzlu
            new_node = new MCVertex(work_node);
            // ulozeni hash kodu pracovniho vrcholu
            new_node->SetHashCode(work_node);
            // vlozeni noveho uzlu do retezu
            AddNode(new_node);
            // vlozeni noveho uzlu do fronty existence
            exist_fronta.Sort(new_node->GetHashCode(), new_node);
        }
    }
    else                      // neprovadi se testovani existence
    {
        // vytvoreni noveho objektu uzlu
        new_node = new MCVertex(new_bod);
        // vlozeni noveho uzlu do retezu
        AddNode(new_node);
    }

    return new_node;
}

////////////////////////////////////////////////////////////
//

MCVertex * MCVerticeS::New( double new_x, double new_y, double new_z )
{
    MCVertex          * new_node;


    // vetveni podle provadeni testovani existence vrcholu
    if (test_existence)       // provadi se testovani existence
    {
        // nastaveni parametru vytvareneho uzlu do pracovniho uzlu
        work_node.SetXYZ(new_x, new_y, new_z);
        // vypocet hash kodu pro souradnice noveho bodu
        work_node.MakeHashCode();

        // test existence pracovniho uzlu
        if ((new_node = TestExistence(&work_node)) == NULL)
        {
            // vytvoreni noveho objektu uzlu
            new_node = new MCVertex(new_x, new_y, new_z);
            // ulozeni hash kodu pracovniho vrcholu
            new_node->SetHashCode(work_node);
            // vlozeni noveho uzlu do retezu
            AddNode(new_node);
            // vlozeni noveho uzlu do fronty existence
            exist_fronta.Sort(new_node->GetHashCode(), new_node);
        }
    }
    else                      // neprovadi se testovani existence
    {
        // vytvoreni noveho objektu uzlu
        new_node = new MCVertex(new_x, new_y, new_z);
        // vlozeni noveho uzlu do retezu
        AddNode(new_node);
    }

    return new_node;
}

////////////////////////////////////////////////////////////
//

MCVertex * MCVerticeS::NewFromWorkNode()
{
    MCVertex          * new_node;


    // vetveni podle provadeni testovani existence vrcholu
    if (test_existence)       // provadi se testovani existence
    {
        // vypocet hash kodu pro souradnice noveho bodu
        work_node.MakeHashCode();

        // test existence pracovniho uzlu
        if ((new_node = TestExistence(&work_node)) == NULL)
        {
            // vytvoreni noveho objektu uzlu
            new_node = new MCVertex(work_node);
            // ulozeni hash kodu pracovniho vrcholu
            new_node->SetHashCode(work_node);
            // vlozeni noveho uzlu do retezu
            AddNode(new_node);
            // vlozeni noveho uzlu do fronty existence
            exist_fronta.Sort(new_node->GetHashCode(), new_node);
        }
    }
    else                      // neprovadi se testovani existence
    {
        // vytvoreni noveho objektu uzlu
        new_node = new MCVertex(work_node);
        // vlozeni noveho uzlu do retezu
        AddNode(new_node);
    }

    return new_node;
}

////////////////////////////////////////////////////////////
//

void MCVerticeS::Erase( MCVertex * del_ent)
{
    assert(del_ent != NULL);

    // zruseni node z exist fronty
    exist_fronta.UnSort(del_ent->GetHashCode(), del_ent);

    // zruseni node z retezu
    EraseNode(del_ent);

    // uvolneni pameti pro objekt node
    delete(del_ent);
}

////////////////////////////////////////////////////////////
//

void MCVerticeS::RegenExistence(  )
{
    MCVertex        * aktual = GetFirst();


    // nulobani exist fronty
    exist_fronta.Clear();

    // cyklus entit retezce
    while(aktual != NULL)
    {
        // vypocet hash kodu pro souradnice aktualniho vrcholu
        aktual->MakeHashCode();
        // zatrideni aktualniho node do exist fronty
        exist_fronta.Sort(aktual->GetHashCode(), aktual);
        // ziskani nasledujici entity
        aktual = aktual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCVerticeS::MakeIndexVector( std::vector<MCVertex *> & pole_node )
{
    int           index = 0;                               // poradove cislo uzlu
    MCVertex      * aktual = GetFirst();                   // ukazatel na aktualni uzel


    // rezervace velikosti vektoru pro node
    pole_node.resize(GetNumber());

    // cyklus entit retezce
    while(aktual != NULL)
    {
        // ulozeni ukazatele na aktual na pozici v poli podle indexu
        pole_node[index] = aktual;
        // inkrementace indexu
        index++;
        // ziskani nasledujici entity
        aktual = aktual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCVerticeS::Indexing()
{
    int         index = 0;                 // poradove cislo uzlu
    MCVertex    * aktual = GetFirst();     // ukazatel na aktualni uzel`


    // cyklus entit retezce
    while(aktual != NULL)
    {
        // nastaveni cisla node
        aktual->SetIndex(index);
        // inkrementace indexu
        index++;
        // ziskani nasledujici entity
        aktual = aktual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCVerticeS::GetRange( MCPoint3D & bod_min, MCPoint3D & bod_max )
{
    MCPoint3D      bod;
    MCVertex       * aktual = GetFirst();


    // inicializace max a min hodnot
    bod_min.SetX(1000000000);
    bod_max.SetX(-1000000000);
    bod_min.SetY(1000000000);
    bod_max.SetY(-1000000000);
    bod_min.SetZ(1000000000);
    bod_max.SetZ(-1000000000);

    // cyklus entit retezce
    while(aktual != NULL)
    {
        // ziskani souradnic aktualniho node
        aktual->GetPoint3D(bod);
        // porovnani souradnic s mezemi
        bod_min.SetX( (bod_min.GetX() > aktual->GetX()) ? aktual->GetX() : bod_min.GetX() );
        bod_max.SetX( (bod_max.GetX() < aktual->GetX()) ? aktual->GetX() : bod_max.GetX() );
        bod_min.SetY( (bod_min.GetY() > aktual->GetY()) ? aktual->GetY() : bod_min.GetY() );
        bod_max.SetY( (bod_max.GetY() < aktual->GetY()) ? aktual->GetY() : bod_max.GetY() );
        bod_min.SetZ( (bod_min.GetZ() > aktual->GetZ()) ? aktual->GetZ() : bod_min.GetZ() );
        bod_max.SetZ( (bod_max.GetZ() < aktual->GetZ()) ? aktual->GetZ() : bod_max.GetZ() );
        // ziskani nasledujici entity
        aktual = aktual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCVerticeS::Transformation(MCTransformMatrix & matrix)
 {
	// get pointer on first vertex of the container
	MCVertex	* actual_vertex = GetFirst();

	// cycle of all vertices of the container
	while (actual_vertex != NULL)
	{
        // transform actual vertex
        matrix.preMult2(*actual_vertex, 1.0);

		// take next vertex of the container
		actual_vertex = actual_vertex->GetNext();
	}
 }

////////////////////////////////////////////////////////////
//

void MCVerticeS::EraseFreeVertices()
{
    // get first vertex of the mesh
    MCVertex        * actual_vertex = GetFirst();
    MCVertex        * tested_vertex;        //  pointer of tested vertex


    // cycle of all vertices of the mesh
    while (actual_vertex != NULL)
    {
        // save pointer of tested vertex to be potentialy deleted
        tested_vertex = actual_vertex;

		// take next vertex of the mesh
		actual_vertex = actual_vertex->GetNext();

        // test registered tri of actual vertex, if it is free from other entities
        if ( (tested_vertex->GetRegisteredEdge() == NULL) && (tested_vertex->GetRegisteredTri() == NULL) && (tested_vertex->GetRegisteredTetra() == NULL) )
        {
            // erase free vertex
            Erase(tested_vertex);
        }
    }

}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
