
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-udp-controller.h"

#include "dhax-signal-generator.h"

DHAX_UDP_Controller::DHAX_UDP_Controller()
  :  signal_generator_(nullptr)
{
 int host = 1234;
 qDebug() << "Incoming socket bound to host " << host;
 udp_incoming_socket_.bind(QHostAddress::LocalHost, host);

 udp_incoming_socket_.connect(&udp_incoming_socket_, &QUdpSocket::readyRead,
   [this]()
 {
  QByteArray qba(512, ' ');
  udp_incoming_socket_.readDatagram(qba.data(), 512);

  qDebug() << "Incoming " << qba;

  signal_generator_->emit_received_datagram(qba);
  //read_udp_socket(qba);
 });

}

