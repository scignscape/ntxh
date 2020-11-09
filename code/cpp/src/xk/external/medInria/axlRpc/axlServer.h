/* axlServer.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2014 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */
#ifndef AXLSERVER_H
#define AXLSERVER_H

#include "axlRpcExport.h"

class axlService;
class axlInspector;
class axlAbstractView;
class QJsonRpcLocalServer;

//This server should be the same for every clients.
class AXLRPC_EXPORT axlServer
{
public :
    axlServer();
    ~axlServer();

    void setView(axlAbstractView *v);
    void setInspector(axlInspector *insp);

private :
    axlService *service;
    QJsonRpcLocalServer *rpcServer;

};


#endif // AXLSERVER_H
