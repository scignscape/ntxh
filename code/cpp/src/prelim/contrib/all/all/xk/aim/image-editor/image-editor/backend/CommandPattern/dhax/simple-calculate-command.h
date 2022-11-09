
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef SIMPLE_CALCULATE_COMMAND__H
#define SIMPLE_CALCULATE_COMMAND__H

#include "../ICommand.h"
#include "../../Image.h"

#include "global-types.h"

class Simple_Calculate_Command : public ICommand
{
private:

 Image& image_;
 std::vector<Pixel>& pixel_buffer_;
 std::vector<Pixel> backup_pixel_buffer_;

 QColor foreground_;
 QColor new_foreground_;
 QColor background_;

 u1 length_threshold_;
 u1 minor_threshold_;
 u1 major_threshold_;

 u2 reduction_scale_;

 u4 length_count_;


 void proceed();

public:

 explicit Simple_Calculate_Command(Image& image,
   QColor foreground, QColor new_foreground, QColor background,
   u2 reduction_scale,
   QList<int> threshold);

// void proceed(std::vector<Pixel>& pixel_buffer,
//   u2 w, u2 h);

 void proceed(Image::Reduction& ir, std::vector<Pixel>& result);

 void execute() override;

 void undo() override;

 void redo() override;

};


#endif
