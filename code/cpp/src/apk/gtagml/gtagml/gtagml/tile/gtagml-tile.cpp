
#include "gtagml-tile.h"

#include "gh/gh-prenode.h"

#include "kans.h"

USING_KANS(GTagML)


GTagML_Tile::GTagML_Tile(QString raw_text)
  :  raw_text_(raw_text), 
     prenode_(nullptr), length_adjustment_(0)
{

}

GH_Prenode* GTagML_Tile::init_prenode(GH_Block_Base* block, u4 enter, u4 leave)
{
 prenode_ = new GH_Prenode(block, enter, leave);
 return prenode_;
}


u4 GTagML_Tile::effective_length()
{
 return raw_text_.size() - length_adjustment_;
}

QString GTagML_Tile::thumbnail(int max_characters)
{
 QString result;
 if(raw_text_.size() > max_characters)
 {
  result += raw_text_.left(max_characters - 3) + "...";
 }
 else
 {
  result += raw_text_;
 }
 return result;
}

QString GTagML_Tile::to_string()
{
 QString result = raw_text_;
 return result;
}


