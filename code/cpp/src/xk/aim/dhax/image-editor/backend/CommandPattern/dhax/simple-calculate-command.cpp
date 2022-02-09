

#include "simple-calculate-command.h"

#include "../../utils.h"

#include "global-types.h"

#include <QPainter>


Simple_Calculate_Command::Simple_Calculate_Command(Image& image,
  QColor foreground, QColor new_foreground, QColor background,
  QList<int> threshold)
 : image_(image), pixel_buffer_(image.getPixelBuffer()),
    foreground_(foreground), new_foreground_(new_foreground), background_(background),
    threshold_(threshold)
{
 backup_pixel_buffer_ = pixel_buffer_;
}

void Simple_Calculate_Command::execute()
{
 proceed();
}

void Simple_Calculate_Command::undo()
{
 pixel_buffer_ = backup_pixel_buffer_;
}

void Simple_Calculate_Command::redo()
{
 execute();
}

void Simple_Calculate_Command::proceed()
{
}

void Simple_Calculate_Command::proceed(std::vector<Pixel>& pixel_buffer,
  u2 w, u2 h)
{
}
