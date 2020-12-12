

//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gh-block-writer.h"

#include "gh-block-standard-8bit.h"

GH_Block_Writer::GH_Block_Writer()
 :  current_main_text_block_(nullptr),
    current_tag_command_name_block_(nullptr),
    current_mandatory_argument_block_(nullptr),
    current_optional_argument_block_(nullptr)
{

}

GH_Block_Base* GH_Block_Writer::write_mandatory_argument(QString text, QPair<u4, u4>& result)
{
 current_mandatory_argument_block_->write(text, result);
 return current_mandatory_argument_block_;
}

GH_Block_Base* GH_Block_Writer::write_optional_argument(QString text, QPair<u4, u4>& result)
{
 current_optional_argument_block_->write(text, result);
 return current_optional_argument_block_;
}


GH_Block_Base* GH_Block_Writer::write_tag_command_name(QString name, QPair<u4, u4>& result)
{
 current_tag_command_name_block_->check_cached(name, result);
 if(result == QPair<u4, u4>{0, 0})
 {
  current_tag_command_name_block_->write(name, result);
 }
 return current_tag_command_name_block_;
}

GH_Block_Base* GH_Block_Writer::write_tile(QString text,
  QPair<u4, u4>& result, QVector<u4>* special_flag_marks)
{
 current_main_text_block_->write(text, result, special_flag_marks);
 return current_main_text_block_;
}


void GH_Block_Writer::init_standard_8bit()
{
 current_tag_command_name_block_ = new GH_Block_Standard_8bit;
 current_tag_command_name_block_->activate_cache();
 current_blocks_[Block_Roles::Tag_Command_Name] = current_tag_command_name_block_;

 current_mandatory_argument_block_ = new GH_Block_Standard_8bit;
 current_optional_argument_block_ = new GH_Block_Standard_8bit;

 current_blocks_[Block_Roles::Mandatory]= current_mandatory_argument_block_;
 current_blocks_[Block_Roles::Optional] = current_optional_argument_block_;

 current_main_text_block_ = new GH_Block_Standard_8bit;
 current_main_text_block_->activate_inserts();
 current_blocks_[Block_Roles::Main_Text] = current_main_text_block_;
}

