
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-udp-controller.h"

#include "dhax-signal-generator.h"

#include <QLocalSocket>


DHAX_UDP_Controller::DHAX_UDP_Controller()
  :  udp_outgoing_socket_(nullptr), signal_generator_(nullptr)
{
 //socket_server_.listen("/home/nlevisrael/gits/osm/inner-system/socket-files/qt-test/renderd.sock");

#ifdef HIDE
 socket_server_.listen("/home/nlevisrael/gits/osm/inner-system/run/renderd/renderd.sock");


 socket_server_.connect(&socket_server_, &QLocalServer::newConnection,
     [this]()
 {
//  QString result = QString::fromLatin1(tcp_incoming_socket_.readAll());
//  qDebug() << "Incoming Local " << result;

  qDebug() << "New Local connection ";
  QLocalSocket* clientConnection = socket_server_.nextPendingConnection();
  //?QObject::connect(clientConnection, &QAbstractSocket::disconnected,
  //?  clientConnection, &QObject::deleteLater);
  clientConnection->write("AOK");
  QObject::connect(clientConnection, &QTcpSocket::readyRead, [clientConnection, this]
  {
   QString result = QString::fromLatin1(clientConnection->readAll());
   qDebug() << "Incoming Local " << result;

   clientConnection->write(R"(HTTP/1.1 200 OK
                           Content-Length: 13
                           Content-Type: text/plain; charset=utf-8

                           Hello World!)"
                           );
   clientConnection->flush();
   //?clientConnection->disconnectFromHost();
   clientConnection->close();

//   QByteArray received;
//   while(clientConnection->bytesAvailable())
//   {
//    received.append(clientConnection->readAll());
//   }
  });

 });
#endif

 int tcp_shost = 1237;


 qDebug() << "Incoming server bound to host " << tcp_shost;
 bool ok  = tcp_server_.listen(QHostAddress::LocalHost, tcp_shost);
 if(!ok)
    qDebug() << "listen failed";


 tcp_server_.connect(&tcp_server_, &QTcpServer::newConnection,
     [this]()
 {
  qDebug() << "New connection ";
  QTcpSocket* clientConnection = tcp_server_.nextPendingConnection();
  QObject::connect(clientConnection, &QAbstractSocket::disconnected,
    clientConnection, &QObject::deleteLater);
  clientConnection->write("AOK");
  QObject::connect(clientConnection, &QTcpSocket::readyRead, [clientConnection, this]
  {
   QString result = QString::fromLatin1(clientConnection->readAll());
   qDebug() << "Incoming TCP " << result;

   clientConnection->write(R"(HTTP/1.1 200 OK
                           Content-Length: 13
                           Content-Type: text/plain; charset=utf-8

                           Hello World=)"
                           );
   clientConnection->flush();
   clientConnection->disconnectFromHost();
   clientConnection->close();

//   QByteArray received;
//   while(clientConnection->bytesAvailable())
//   {
//    received.append(clientConnection->readAll());
//   }
  });

//    QByteArray qba(512, ' ');
//    tcp_incoming_socket_.read(qba.data(), 512);

//    qDebug() << "Incoming TCP " << qba;

    //signal_generator_->emit_received_datagram(qba);
    //read_udp_socket(qba);
 });



 int tcp_host = 1357;

 qDebug() << "Incoming socket bound to host " << tcp_host;
 bool bok  = tcp_incoming_socket_.bind(QHostAddress::LocalHost, tcp_host);
 if(!bok)
    qDebug() << "bind failed";

 tcp_incoming_socket_.connect(&tcp_incoming_socket_, &QTcpSocket::readyRead,
     [this]()
 {
  QString result = QString::fromLatin1(tcp_incoming_socket_.readAll());
  qDebug() << "Incoming TCP " << result;
//    QByteArray qba(512, ' ');
//    tcp_incoming_socket_.read(qba.data(), 512);

//    qDebug() << "Incoming TCP " << qba;

    //signal_generator_->emit_received_datagram(qba);
    //read_udp_socket(qba);
 });

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
