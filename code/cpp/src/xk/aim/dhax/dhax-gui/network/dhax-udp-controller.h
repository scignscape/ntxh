
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_UDP_CONTROLLER__H
#define DHAX_UDP_CONTROLLER__H

#include <QUdpSocket>

#include "accessors.h"


class DHAX_Signal_Generator;

class DHAX_UDP_Controller
{
 QUdpSocket udp_outgoing_socket_;
 QUdpSocket udp_incoming_socket_;

 DHAX_Signal_Generator* signal_generator_;

public:

 DHAX_UDP_Controller();

 ACCESSORS__CONST_RGET(QUdpSocket ,udp_incoming_socket)
 ACCESSORS__CONST_RGET(QUdpSocket ,udp_outgoing_socket)

 ACCESSORS(DHAX_Signal_Generator* ,signal_generator)

};

#endif //  DHAX_UDP_CONTROLLER__H




