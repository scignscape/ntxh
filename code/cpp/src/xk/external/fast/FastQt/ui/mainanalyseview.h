#ifndef MAINANALYSEVIEW_H
#define MAINANALYSEVIEW_H
#include <QTableView>
#include <QtWidgets>
#include <QtConcurrent>
#include "mainanalysemodel.h"
#include "mainanalysewidget.h"

class MainAnalyseView;
class MainAnalyseDelegate;


class MainAnalyseDelegate : public QStyledItemDelegate
{
public:
void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

//================================================

class MainAnalyseView : public QTableView
{
    Q_OBJECT
public:
    MainAnalyseView(QWidget * parent = nullptr);
    ~MainAnalyseView();
    void addFile(const QString& filename);


public Q_SLOTS:
    void removeSelection();
    void stopSelection();
    void clearAll();
    void showAnalysis(const QModelIndex& index);
    void exportSelection(const QString& path);



protected:
    void dragEnterEvent(QDragEnterEvent * event);
    void dragMoveEvent(QDragMoveEvent * event);
    void dropEvent(QDropEvent * event);
    bool checkFile(const QString& path);


private:
    MainAnalyseModel * mModel;
    MainAnalyseDelegate * mDelegate;
    // pointer runner as unique key index. Avoid open same result widget
    QHash<AnalysisRunner*, MainAnalyseWidget*> mAnalysisWidgets;
    QProgressDialog * mExportDialog;
};

#endif // MAINANALYSEVIEW_H
