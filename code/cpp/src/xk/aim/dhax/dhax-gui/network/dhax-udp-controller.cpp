
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-udp-controller.h"

#include "dhax-signal-generator.h"

DHAX_UDP_Controller::DHAX_UDP_Controller()
  :  udp_outgoing_socket_(nullptr), signal_generator_(nullptr)
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

void DHAX_UDP_Controller::send_datagram(const QByteArray& qba)
{
 check_init_outgoing_socket();
 udp_outgoing_socket_->writeDatagram(qba, QHostAddress::LocalHost, 1235);
}

void DHAX_UDP_Controller::check_init_outgoing_socket()
{
 if(udp_outgoing_socket_)
  return;

 int host = 1235;
 udp_outgoing_socket_ = new QUdpSocket;
 qDebug() << "Outgoing socket bound to host " << host;
 udp_outgoing_socket_->bind(QHostAddress::LocalHost, host);
}

void DHAX_UDP_Controller::wrap_and_send_datagram(QByteArray& qba, u1 msg_flags)
{
 wrap_udp(qba, msg_flags);
 send_datagram(qba);
}


void DHAX_UDP_Controller::wrap_udp(QByteArray& qba, u1 msg_flags)
{
 u2 sz = qba.size();
 u1 sz0 = sz & 255;
 u1 sz1 = sz >> 8;

 sz1 |= (msg_flags << 2);

 qba.prepend(sz0);
 qba.prepend(sz1);
}
