
#ifndef QUANTIZE_3x3_COMMAND__H
#define QUANTIZE_3x3_COMMAND__H

#include "../ICommand.h"
#include "../../Image.h"

#include "global-types.h"

#include "accessors.h"


class Quantize_3x3_Command : public ICommand
{
private:

 Image& image_;
 std::vector<Pixel>& pixel_buffer_;
 std::vector<Pixel> backup_pixel_buffer_;
 std::vector<Pixel> sample_compress_pixel_buffer_;

 u2 sample_compress_width_;
 u2 sample_compress_height_;

 u1 range_;

 void proceed(u1 range);
 void reset_sample_compress_pixel_buffer(u2 pre_compress_width, u2 pre_compress_height);

public:
 explicit Quantize_3x3_Command(Image& image, u1 range = 3);

 ACCESSORS__RGET(std::vector<Pixel> ,sample_compress_pixel_buffer)

 ACCESSORS(u2 ,sample_compress_width)
 ACCESSORS(u2 ,sample_compress_height)

 static void re_extend(std::vector<Pixel>& source, std::vector<Pixel>& target,
    u2 source_width, u2 source_height, u1 factor);

 static void proceed(u2 w, u2 h,
   std::vector<Pixel>& pixel_buffer, std::vector<Pixel>& sample_compress_pixel_buffer, u1 range = 3);


 static void reset_sample_compress_pixel_buffer(std::vector<Pixel>& pixel_buffer,
   u2 pre_compress_width, u2 pre_compress_height);

 void execute() override;

 void undo() override;

 void redo() override;
};


#endif
