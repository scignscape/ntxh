
// licence_h

#ifndef GH_PRENODE__H
#define GH_PRENODE__H

#include "global-types.h"

#include "accessors.h"


#include <QPair>
#include <QString>

#include "kans.h"

class GH_Block_Base;


KANS_(GTagML)


class GH_Prenode
{
 QPair<u4, u4> range_;

 union { QString* raw_text_; GH_Block_Base* block_;};

public:

 GH_Prenode();
 GH_Prenode(QString text);
 GH_Prenode(GH_Block_Base* block, u4 enter, u4 leave);

 ACCESSORS(MACRO_PASTE(QPair<u4, u4>) ,range)

 GH_Block_Base* get_block();

 QString get_string_content();


};


_KANS(GTagML)


#endif // GH_PRENODE__H


