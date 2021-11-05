
#include "dhax-signal-generator.h"


DHAX_Signal_Generator::DHAX_Signal_Generator()
{

}


void DHAX_Signal_Generator::emit_received_datagram(QByteArray qba)
{
 Q_EMIT received_datagram(qba);
}


void DHAX_Signal_Generator::emit_take_screenshot_requested()
{
 Q_EMIT take_screenshot_requested();
}

void DHAX_Signal_Generator::emit_load_image_requested()
{
 Q_EMIT load_image_requested();
}
