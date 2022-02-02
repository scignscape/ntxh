
#ifndef EXTEND_MOD_3_COMMAND__H
#define EXTEND_MOD_3_COMMAND__H

#include "../ICommand.h"
#include "../../Image.h"

class Extend_Mod_3_Command : public ICommand
{
private:
    Image &image;
    std::vector<Pixel>& pixelBuffer;
    std::vector<Pixel> backupPixelBuffer;

    void proceed();

public:
    explicit Extend_Mod_3_Command(Image &image);

    void execute() override;

    void undo() override;

    void redo() override;
};


#endif
