#ifndef PROJECTWIZARD_H
#define PROJECTWIZARD_H

#include <QtGui>
#include <QWizard>
#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QVBoxLayout>
#include <QFileDialog>

class ProjectWizard : public QWizard {
    Q_OBJECT

public:
    ProjectWizard(QWidget *parent = 0);
    QString projectName;
    QString projectpath;
    void createProjectData();
    void accept();

public slots:
    int exec();
};

class IntroPage : public QWizardPage {
    Q_OBJECT

public:
    IntroPage(QWidget *parent = 0);

private:
    QLabel *label;
};

class ProjectInfoPage : public QWizardPage {
    Q_OBJECT

public:
    ProjectInfoPage(QWidget *parent = 0);

private slots:
    void chooseProjectPathLocation();

private:
    QLabel *projectNameLabel;
    QLabel *ProjectPathLocationLabel;
    QLineEdit *projectNameLineEdit;
    QLineEdit *ProjectPathLocationLineEdit;
    QToolButton *ProjectPathLocationToolButton;
    QLabel *projectLabel;
};
#endif // PROJECTWIZARD_H
