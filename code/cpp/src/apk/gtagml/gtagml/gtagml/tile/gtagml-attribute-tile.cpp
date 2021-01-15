
#include "gtagml-attribute-tile.h"

#include "kans.h"

USING_KANS(GTagML)


GTagML_Attribute_Tile::GTagML_Attribute_Tile(QString key, QString value)
 : key_(key), value_(value)
{

}


QString GTagML_Attribute_Tile::thumbnail()
{
 return key_ + "=...";
}


