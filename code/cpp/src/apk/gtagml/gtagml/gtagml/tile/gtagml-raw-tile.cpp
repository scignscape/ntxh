
#include "gtagml-raw-tile.h"

#include "kans.h"

USING_KANS(GTagML)


GTagML_Raw_Tile::GTagML_Raw_Tile(QString format, QString text)
 : format_(format), text_(text)
{

}


QString GTagML_Raw_Tile::thumbnail()
{
 return format_ + "<raw>";
}


