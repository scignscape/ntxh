/*
 * Copyright (C) 2012-2013 Matt Broadstone
 * Contact: http://bitbucket.org/devonit/qjsonrpc
 *
 * This file is part of the QJsonRpc Library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */
#ifndef QJSONRPCHTTPSERVER_H
#define QJSONRPCHTTPSERVER_H

#include "qjsonrpctcpserver.h"

class QJsonRpcHttpServerPrivate;
class QJSONRPC_EXPORT QJsonRpcHttpServer : public QJsonRpcTcpServer
{
    Q_OBJECT
public:
    explicit QJsonRpcHttpServer(QObject *parent = 0);
    virtual ~QJsonRpcHttpServer();

protected:
    Q_DECLARE_PRIVATE(QJsonRpcHttpServer)
    Q_DISABLE_COPY(QJsonRpcHttpServer)
    Q_PRIVATE_SLOT(d_func(), void _q_processIncomingConnection())
    Q_PRIVATE_SLOT(d_func(), void _q_clientDisconnected())

};

#endif
