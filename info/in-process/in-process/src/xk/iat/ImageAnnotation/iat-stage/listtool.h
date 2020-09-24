#ifndef LISTTOOL_H
#define LISTTOOL_H

#include <QDialog>

namespace Ui {
class ListTool;
}

class ListTool : public QDialog
{
    Q_OBJECT

public:
    explicit ListTool(QWidget *parent = 0);
    ~ListTool();

private slots:
    void on_textObject_textChanged();

    void on_textInstance_textChanged();

    void on_AddLine_clicked();

    void on_Save_clicked();

    void on_Cancel_clicked();

private:
    Ui::ListTool *ui;
};

#endif // LISTTOOL_H
