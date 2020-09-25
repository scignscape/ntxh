
// licence_cpp

#include "gh-prenode.h"


USING_KANS(GTagML)


GH_Prenode::GH_Prenode()
 : range_({0, 0}), raw_text_(nullptr)
{

}

GH_Prenode::GH_Prenode(QString text)
 : range_({1, 1}), raw_text_(new QString(text))
{

}

GH_Block_Base* GH_Prenode::get_block()
{
 static QPair<u4, u4> signal = {1,1};
 if(range_ != signal)
   return block_;
}

QString GH_Prenode::get_string_content()
{
 return *raw_text_;
}


GH_Prenode::GH_Prenode(GH_Block_Base* block, u4 enter, u4 leave)
 : range_({enter, leave}), block_(block)
{

}

