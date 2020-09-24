
// licence_h

#ifndef GH_BLOCK_WRITER__H
#define GH_BLOCK_WRITER__H

#include "global-types.h"

#include "accessors.h"

#include <QPair>
#include <QString>
 
class GH_Block_Base;

class GH_Block_Writer
{
 enum class Block_Roles { Tag_Command_Name, Mandatory, Optional, Main_Text, Custom };


 QMap<QString, QPair<Block_Roles, GH_Block_Base*>> current_named_blocks_;
 QMap<Block_Roles, GH_Block_Base*> current_blocks_;

 GH_Block_Base* current_main_text_block_;
 GH_Block_Base* current_tag_command_name_block_;

 GH_Block_Base* current_mandatory_argument_block_;
 GH_Block_Base* current_optional_argument_block_;

public:

 GH_Block_Writer();

 ACCESSORS(GH_Block_Base* ,current_main_text_block)
 ACCESSORS(GH_Block_Base* ,current_tag_command_name_block)


 void init_standard_8bit();
 GH_Block_Base* write_tag_command_name(QString name, QPair<u4, u4>& result);
 GH_Block_Base* write_tile(QString name, QPair<u4, u4>& result);
 GH_Block_Base* write_mandatory_argument(QString name, QPair<u4, u4>& result);
 GH_Block_Base* write_optional_argument(QString name, QPair<u4, u4>& result);



};


#endif // GH_BLOCK_WRITER__H


