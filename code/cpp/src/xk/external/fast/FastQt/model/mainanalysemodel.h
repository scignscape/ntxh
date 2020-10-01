#ifndef MAINANALYSEMODEL_H
#define MAINANALYSEMODEL_H

#include <QAbstractListModel>
#include <QSignalMapper>

#include "qfonticon.h"
#include "analysisrunner.h"

class MainAnalyseModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum {
        NameColumn = 0,
        StatusColumn,
        SizeColumn,
        ProgressColumn,
        ReadsColumn,
        TimeColumn
    };
    MainAnalyseModel(QObject * parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;


    void remove(const QList<int>& index);


    void addFile(const QString& filename);
    AnalysisRunner * runner(const QModelIndex& index);

protected Q_SLOTS:
    void timeUpdated();


private:
    QList<AnalysisRunner*> mRunners;
    QSignalMapper *mSignalMapper;
    QTimer * mTimer;


};

#endif // MAINANALYSEMODEL_H
