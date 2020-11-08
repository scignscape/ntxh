/* dtkComposerEvaluator.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Mon Jan 30 11:30:36 2012 (+0100)
 * Version: $Id: ef587bf4c522d37a9eefef83784e234657c66039 $
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSEREVALUATOR_H
#define DTKCOMPOSEREVALUATOR_H

#include <dtkComposerSupportExport.h>

#include <QtCore/QObject>

class dtkComposerGraph;
class dtkComposerGraphNode;
class dtkComposerEvaluatorPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerEvaluator : public QObject
{
    Q_OBJECT

public:
    dtkComposerEvaluator(QObject *parent = 0);
    ~dtkComposerEvaluator(void);

signals:
    void evaluationStarted(void);
    void evaluationStopped(void);

signals:
    void runMainThread(void);

public:
    void  setGraph(dtkComposerGraph *graph);
    void  setStartNode(dtkComposerGraphNode *node);
    void  setNotify(bool notify);
    void  setProfiling(bool profiling);
    void  printProfiling(qlonglong level = 0);

public slots:
    void  run(bool run_concurrent = false);
    void  run_static(bool run_concurrent = false);
    void  reset(void);

public:
    void cont(bool run_concurrent = false);
    bool step(bool run_concurrent = false);
    void next(bool run_concurrent = false);
    void stop(void);

public:
    void  logStack(void);

protected:
    void  run_static_rec(bool run_concurrent = false);

private:
    dtkComposerEvaluatorPrivate *d;
};

#endif
