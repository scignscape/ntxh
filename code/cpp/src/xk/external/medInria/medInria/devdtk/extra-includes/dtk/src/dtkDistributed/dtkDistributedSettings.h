// Version: $Id: 6bcb6ea40d8723f64c82e27c3246fb4f2fb7ead9 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#pragma once

#include <dtkDistributedExport.h>

#include <QtCore>

class DTKDISTRIBUTED_EXPORT dtkDistributedSettings : public QSettings
{
public:
    dtkDistributedSettings(void);
    ~dtkDistributedSettings(void);

public:
    QString        path(const QUrl server);
    QString server_type(const QUrl server);
    bool use_ssh_tunnel(const QUrl server);
};

//
// dtkDistributedSettings.h ends here
