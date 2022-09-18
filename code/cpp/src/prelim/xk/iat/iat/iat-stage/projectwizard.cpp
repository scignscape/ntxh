#include "projectwizard.h"

ProjectWizard::ProjectWizard(QWidget *parent) : QWizard(parent) {
    setWizardStyle(ClassicStyle);
    addPage(new IntroPage);
    addPage(new ProjectInfoPage);
    setPixmap(QWizard::LogoPixmap, QPixmap(QCoreApplication::applicationDirPath()+"/images/unimib.png"));
    setWindowTitle(tr("New Project"));
}

void ProjectWizard::accept(){
    createProjectData();
    QDialog::accept();
}

int ProjectWizard::exec(){
    restart();
    return QDialog::exec();
}

void ProjectWizard::createProjectData(){
    projectName = field("projectName").toString();
    projectpath = field("ProjectPathLocation").toString();
}

IntroPage::IntroPage(QWidget *parent):QWizardPage(parent){
    setTitle(tr("Introduction"));
    label = new QLabel(tr("This is a manual tool for image annotation"));
    label->setWordWrap(true);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

ProjectInfoPage::ProjectInfoPage(QWidget *parent):QWizardPage(parent){
    setTitle(tr("Project Information"));
    setSubTitle(tr("Specify basic information about the project."));
    projectLabel = new QLabel();
    projectLabel->setWordWrap(true);
    projectNameLabel = new QLabel(tr("&Project name:"));
    projectNameLineEdit = new QLineEdit;
    projectNameLabel->setBuddy (projectNameLineEdit);
    ProjectPathLocationLabel = new QLabel(tr("&Project location:"));
    ProjectPathLocationLineEdit = new QLineEdit;
    ProjectPathLocationLabel->setBuddy(ProjectPathLocationLineEdit);
    ProjectPathLocationToolButton = new QToolButton;
    ProjectPathLocationToolButton->setText("Browse");
    ProjectPathLocationLineEdit->setReadOnly(true);
    connect(ProjectPathLocationToolButton,SIGNAL(clicked()),this,SLOT(chooseProjectPathLocation()));
    registerField("projectName*", projectNameLineEdit);
    registerField("ProjectPathLocation*", ProjectPathLocationLineEdit);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(projectNameLabel, 0, 0);
    layout->addWidget(projectNameLineEdit, 0, 1);
    layout->addWidget(projectLabel,0,2);
    layout->addWidget(ProjectPathLocationLabel, 1, 0);
    layout->addWidget(ProjectPathLocationLineEdit, 1, 1);
    layout->addWidget(ProjectPathLocationToolButton, 1, 2);
    setLayout(layout);
}


void ProjectInfoPage::chooseProjectPathLocation() {
    QString dir = QFileDialog::getExistingDirectory(this,tr("Open Directory"));
    if (dir!="") ProjectPathLocationLineEdit->setText(dir);
}
