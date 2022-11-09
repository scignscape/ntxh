
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef HEURISTIC_COLOR_MASK_COMMAND__H
#define HEURISTIC_COLOR_MASK_COMMAND__H

#include "../ICommand.h"
#include "../../Image.h"

#include "global-types.h"

class Heuristic_Color_Mask_Command : public ICommand
{
private:

 Image& image_;
 std::vector<Pixel>& pixel_buffer_;
 std::vector<Pixel> backup_pixel_buffer_;

 QColor foreground_;
 QColor background_;
 u1 offset_;
 u1 metric_code_;

 void proceed();

public:

 Heuristic_Color_Mask_Command(Image& image,
   QColor foreground, QColor background, u1 offset, u1 metric_code);

 Heuristic_Color_Mask_Command(Image& image,
   QColor foreground, QColor background, u1 offset, QString metric_code);

 enum class Metric_Codes {
  N_A = 0, Max_Difference = 1, Sum_Difference = 2, Vector_Difference = 3,
  Weighted_Max_Difference = 4, Weighted_Sum_Difference = 5, Weighted_Vector_Difference = 6,
  Exact_Match = 7
 };

 void proceed(std::vector<Pixel>& pixel_buffer,
   u2 w, u2 h, Metric_Codes mc);

 void execute() override;

 void undo() override;

 void redo() override;

};


#endif
