
#include "dhax-signal-generator.h"


DHAX_Signal_Generator::DHAX_Signal_Generator()
{

}


void DHAX_Signal_Generator::emit_take_screenshot_requested()
{
 Q_EMIT take_screenshot_requested();
}

