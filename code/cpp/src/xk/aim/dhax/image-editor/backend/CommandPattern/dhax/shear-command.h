
#ifndef SHEAR_COMMAND__H
#define SHEAR_COMMAND__H

#include "../ICommand.h"
#include "../../Image.h"

#include "global-types.h"

class Shear_Command : public ICommand
{
private:

 Image& image_;
 std::vector<Pixel>& pixel_buffer_;
 std::vector<Pixel> backup_pixel_buffer_;

 r8 x_shear_;
 r8 x_shear_c_;
 r8 y_shear_;
 r8 y_shear_c_;

 r8 x_rotate_;
 r8 y_rotate_;
 r8 rotate_;

 void proceed();

public:
 explicit Shear_Command(Image& image, r8 x_shear, r8 x_shear_c, r8 y_shear, r8 y_shear_c,
    r8 x_rotate, r8 y_rotate, r8 rotate);

 void execute() override;

 void undo() override;

 void redo() override;

};


#endif
