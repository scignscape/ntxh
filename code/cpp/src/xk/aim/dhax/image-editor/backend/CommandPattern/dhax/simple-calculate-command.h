
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
 QList<int> threshold_;

 void proceed();

public:

 explicit Simple_Calculate_Command(Image& image,
   QColor foreground, QColor new_foreground, QColor background, QList<int> threshold);

 void proceed(std::vector<Pixel>& pixel_buffer,
   u2 w, u2 h);

 void execute() override;

 void undo() override;

 void redo() override;

};


#endif
