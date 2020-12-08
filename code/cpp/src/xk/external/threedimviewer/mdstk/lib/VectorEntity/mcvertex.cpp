////////////////////////////////////////////////////////////
// $Id: mcvertex.cpp 1863 2010-08-31 20:40:15Z spanel $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// include soubory

#include <VectorEntity/mcvertex.h>
#include <VectorEntity/mcedge.h>
#include <VectorEntity/mctri.h>
#include <VectorEntity/mctetra.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

void MCVertex::GetRegisteredEdgeList(std::vector<MCEdge *> & _edge_list)
{
    MCEdge				* aktual = edge_list;				// ukazatel na aktualni prvek


    // vyprazdneni daneho pole
    _edge_list.clear();

    // cyklus entit registrovanych pro vrchol
    while(aktual != NULL)
    {
        // pridani aktualni hrany do seznamu
        _edge_list.push_back(aktual);
        // ziskani dalsi entity registrovane pro vrchol
        aktual = aktual->GetVertexEdge(this);
    }
}

////////////////////////////////////////////////////////////
//

void MCVertex::GetRegisteredTriList(std::vector<MCTri *> & _tri_list)
{
    MCTri				* aktual = tri_list;					// ukazatel na aktualni prvek


    // vyprazdneni daneho pole
    _tri_list.clear();

    // cyklus entit registrovanych pro vrchol
    while(aktual != NULL)
    {
        // pridani aktualniho tri do seznamu
        _tri_list.push_back(aktual);
        // ziskani dalsi entity registrovane pro vrchol
        aktual = aktual->GetVertexTri(this);
    }
}

////////////////////////////////////////////////////////////
//

void MCVertex::GetRegisteredTriListExclude(std::vector<MCTri *> & _tri_list, MCVertex * exclude_vertex)
{
    MCTri				* actual = tri_list;					// pointer on actual entity


    // clear input entity vector
    _tri_list.clear();

    // cycle of registered entity for this vertex
    while(actual != NULL)
    {
        // test for input exclude vertex
        if ( ! actual->IsVertexBool(exclude_vertex))
        {
            // add actual tri into input vector of registered tris
            _tri_list.push_back(actual);
        }

        // Take next registered entity for this vertex
        actual = actual->GetVertexTri(this);
    }
}

////////////////////////////////////////////////////////////
//

void MCVertex::GetRegisteredTetraList(std::vector<MCTetra *> & _tetra_list)
{
    MCTetra				* aktual = tetra_list;				// ukazatel na aktualni prvek


    // vyprazdneni daneho pole
    _tetra_list.clear();

    // cyklus entit registrovanych pro vrchol
    while(aktual != NULL)
    {
        // pridani aktualniho tetra do seznamu
        _tetra_list.push_back(aktual);
        // ziskani dalsi entity registrovane pro vrchol
        aktual = aktual->GetVertexTetra(this);
    }
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
