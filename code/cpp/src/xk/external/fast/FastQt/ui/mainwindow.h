/*
Copyright Copyright 2016-17 Sacha Schutz

    This file is part of FastQt.

    Foobar is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Foobar is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

    @author : Pierre Lindenbaum from FastQC <http://www.bioinformatics.babraham.ac.uk/projects/fastqc/>
    @author : Sacha Schutz <sacha@labsquare.org>
    @author : Pierre Marijon <pierre@marijon.fr>
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtCore>
#include "mainanalysewidget.h"
#include "aboutdialog.h"
#include "mainanalyseview.h"
/*!
 * \class MainWindow
 * \brief Main Widget Application for FastQt
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public Q_SLOTS:
    void run();
    void addFiles();
    void remFiles();
    void stopFiles();
    void clearFiles();
    void showAnalysis();
    void about();
    void exportSelection();


protected:
    void setupActions();
    void addRecent(const QString& path);
    QStringList loadRecent();
    void updateRecentMenu();

private:
    void printEasterEggs();

private:
    QTabWidget * mTabWidget;
    QList<MainAnalyseWidget*> mMainList;
    MainAnalyseView * mView;
    QFuture<void> mRunFuture;
    QStatusBar * mStatusBar;
    QMenu * mRecentMenu;
    static const int MAX_RECENT=10;
};

#endif // MAINWINDOW_H
