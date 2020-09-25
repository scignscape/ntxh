
#ifndef GTAGML_PARSER__H
#define GTAGML_PARSER__H

#include "relae-graph/relae-node-ptr.h"
#include "relae-graph/relae-parser.h"

#include "kernel/gtagml-dominion.h"

#include "kans.h"

KANS_(GTagML)


class GTagML_Parser : public Relae_Parser<GTagML_Galaxy>
{
public:
 GTagML_Parser(caon_ptr<GTagML_Graph> g);
};

_KANS(GTagML)

#endif
