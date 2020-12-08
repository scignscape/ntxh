////////////////////////////////////////////////////////////
// $Id: mcedge.cpp 1863 2010-08-31 20:40:15Z spanel $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// include

#include <VectorEntity/mcedge.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

void MCEdge::DeRegistration()
{
    MCEdge * aktual, * predchozi;			// ukazatel na aktualni a predchozi entitu

    // test existence uzlu tri
    assert((u[0] != NULL) && (u[1] != NULL));

    // cyklus uzlu
    for (int i = 0; i < 2; i++ )
    {
        // ulozeni prvniho souseda i-teho uzlu jako aktual
        aktual = u[i]->GetRegisteredEdge();

        // kontrola nenulovosti prvniho souseda i-teho uzlu
        assert(aktual != NULL);

        // test, neni-li aktualni soused this
        if (aktual == this)
            // vlozeni souseda pro i-ty uzel do i-teho uzlu
            u[i]->SetRegisteredEdge(s[i]);
        else
        {
            // cyklus sousedu pro i-ty uzel
            while(aktual != this)
            {
                // ulozeni aktualniho souseda do predchoziho
                predchozi = aktual;
                // ziskani dalsiho souseda registrovaneho u i-teho uzlu
                aktual = aktual->GetVertexEdge(u[i]);
                // kontrola dosazeni konce retezce registrovanych sousedu
                assert(aktual != NULL);
            }
            // preklenuti sousedu z predchoziho na souseda i-teho uzlu
            predchozi->SetVertexEdge(u[i], s[i]);
        }

        // vynulovani odkazu na souseda pro i-ty uzel
        s[i] = NULL;
    }
}

////////////////////////////////////////////////////////////
//

//void MCEdge::()
//{
//}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
