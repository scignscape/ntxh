
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef EXTEND_MOD_3_COMMAND__H
#define EXTEND_MOD_3_COMMAND__H

#include "../ICommand.h"
#include "../../Image.h"

#include "global-types.h"

class Extend_Mod_3_Command : public ICommand
{
private:

 Image& image_;
 std::vector<Pixel>& pixel_buffer_;
 std::vector<Pixel> backup_pixel_buffer_;

 void proceed();

public:
 explicit Extend_Mod_3_Command(Image &image_);

 void execute() override;

 void undo() override;

 void redo() override;

 static void proceed(Image& image, std::vector<Pixel>& pixel_buffer);

 static void proceed(u2 w, u2 h, std::vector<Pixel>& pixel_buffer,
   u2& setW, u2& setH);

};


#endif
