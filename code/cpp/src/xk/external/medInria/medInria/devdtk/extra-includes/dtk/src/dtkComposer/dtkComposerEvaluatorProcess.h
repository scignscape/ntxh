/* dtkComposerEvaluatorProcess.h ---
 *
 * Author: Nicolas Niclausse
 * Copyright (C) 2012 - Nicolas Niclausse, Inria.
 * Created: 2013/10/07 10:23:58
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include <dtkComposerExport.h>

#include <QtCore>

class dtkComposerNodeComposite;
class dtkDistributedCommunicator;
class dtkComposerEvaluatorProcessPrivate;

class DTKCOMPOSER_EXPORT dtkComposerEvaluatorProcess : public QRunnable
{

public:
    dtkComposerEvaluatorProcess(void);
    ~dtkComposerEvaluatorProcess(void);

public:
    void setApplication(QString app);
    void setComposition(QString composition);
    void setCommunicator(dtkDistributedCommunicator *communicator);
    void setContainer(QVariant var_container);
    void setOutputContainer(QVariant var_container);
    void setParent(dtkComposerNodeComposite *parent);

public:
    void run(void);
    int exec(void);

private:
    dtkComposerEvaluatorProcessPrivate *d;
};
