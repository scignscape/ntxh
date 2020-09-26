
// licence_cpp

#include "gh-block-base.h"

GH_Block_Base::GH_Block_Base()
 : cache_(nullptr), inserts_(nullptr)
{

}


void GH_Block_Base::check_cached(QString key, QPair<u4, u4>& result)
{
 if(cache_)
   result = cache_->value(key, {0,0});
 else result = {0,0};
}

void GH_Block_Base::activate_inserts()
{
 inserts_ = new QMap<QPair<u4, u4>, QList<QPair<u8, QString>>>;
}

void GH_Block_Base::activate_cache()
{
 cache_ = new QMap<QString, QPair<u4, u4>>;
}

