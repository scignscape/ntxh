/*
 *  OpenSCAD (www.openscad.org)
 *  Copyright (C) 2009-2019 Clifford Wolf <clifford@clifford.at> and
 *                          Marius Kintel <marius@kintel.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  As a special exception, you have permission to link this program
 *  with the CGAL library and distribute executables, as long as you
 *  follow the requirements of the GNU GPL in regard to all of the
 *  software in the executable aside from CGAL.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <QMenu>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QRegularExpression>

#include "Console.h"
#include "printutils.h"
#include "UIUtils.h"

Console::Console(QWidget *parent) : QPlainTextEdit(parent)
{
	setupUi(this);
	connect(this->actionClear, SIGNAL(triggered()), this, SLOT(actionClearConsole_triggered()));
	connect(this->actionSaveAs, SIGNAL(triggered()), this, SLOT(actionSaveAs_triggered()));
	connect(this, SIGNAL(linkActivated(QString)), this, SLOT(hyperlinkClicked(const QString&)));
}

Console::~Console()
{
}

void Console::actionClearConsole_triggered()
{
	this->document()->clear();
}

void Console::actionSaveAs_triggered()
{
	const auto& text = this->document()->toPlainText();
	const auto fileName = QFileDialog::getSaveFileName(this, _("Save console content"));
	QFile file(fileName);
	if (file.open(QIODevice::ReadWrite)) {
		QTextStream stream(&file);
		stream << text;
		stream.flush();
		LOG(message_group::None,Location::NONE,"","Console content saved to '%1$s'.",fileName.toStdString());
	}
}

void Console::contextMenuEvent(QContextMenuEvent *event)
{
	// Clear leaves characterCount() at 1, not 0
	const bool hasContent = this->document()->characterCount() > 1;
	this->actionClear->setEnabled(hasContent);
	this->actionSaveAs->setEnabled(hasContent);
	QMenu *menu = createStandardContextMenu();
	menu->insertAction(menu->actions().at(0), this->actionClear);
	menu->addSeparator();
	menu->addAction(this->actionSaveAs);
    menu->exec(event->globalPos());
	delete menu;
}

void Console::hyperlinkClicked(const QString& url)
{
	if (url.startsWith("http://") || url.startsWith("https://")) {
		UIUtils::openURL(url);
		return;
	}

	const QRegularExpression regEx("^(\\d+),(.*)$");
	const auto match = regEx.match(url);
	if (match.hasMatch()) {
		const auto line = match.captured(1).toInt();
		const auto file = match.captured(2);
		const auto info = QFileInfo(file);
		if (info.isFile()) {
			if (info.isReadable()) {
				emit openFile(file, line - 1);
			}
		} else {
			openFile(QString(), line - 1);
		}
	}
}
