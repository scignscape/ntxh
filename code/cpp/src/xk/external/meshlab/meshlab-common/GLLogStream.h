/****************************************************************************
* VCGLib                                                            o o     *
* Visual and Computer Graphics Library                            o     o   *
*                                                                _   O  _   *
* Copyright(C) 2004
\/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#ifndef GLLOGSTREAM_H
#define GLLOGSTREAM_H

#include <list>
#include <utility>
#include <QMultiMap>
#include <QPair>
#include <QString>
#include <QObject>
/**
This is the logging class.
One for each document. Responsible of getting an history of the logging message printed out by filters.
*/
class GLLogStream : public QObject
{
	Q_OBJECT
public:
	enum Levels
	{
		SYSTEM = 0,
		WARNING = 1,
		FILTER = 2,
		DEBUG = 3
	};

	static constexpr std::size_t buf_size = 4096;

	GLLogStream();
	~GLLogStream() {}
	void print(QStringList &list) const;		// Fills a QStringList with the log entries
	void Save(int Level, const char *filename);
	void Clear();

	template <typename... Ts>
	void Logf(int Level, const char * f, Ts&&... ts )
	{
		char buf[buf_size];
		int chars_written = snprintf(buf, buf_size, f, std::forward<Ts>(ts)...);
		Log(Level, buf);

		if(chars_written >= static_cast<int>(buf_size)){
			Log(Level, "Log message truncated.");
		}
	}

	void Log(int Level, const char * buf);
	void Log(int Level, const std::string& logMessage);
	void Log(int Level, const QString& logMessage);
	void SetBookmark();
	void ClearBookmark();
	void BackToBookmark();
	const QList<std::pair<int, QString> >& logStringList() const;

	const QMultiMap<QString, QPair<QString, QString> >& realTimeLogMultiMap() const;
	void clearRealTimeLog();

	template <typename... Ts>
	void RealTimeLogf(const QString& Id, const QString &meshName, const char * f, Ts&&... ts )
	{
		char buf[buf_size];
		int chars_written = snprintf(buf, buf_size, f, std::forward<Ts>(ts)...);   
		RealTimeLog(Id, meshName, buf);

		if(chars_written >= static_cast<int>(buf_size)){
			RealTimeLog(Id, meshName, "Log message truncated.");
		}
	}	
	void RealTimeLog(const QString& Id, const QString &meshName, const QString& text);

signals:
	void logUpdated();

private:
	int bookmark; /// this field is used to place a bookmark for restoring the log. Useful for previeweing
	QList<std::pair<int, QString> > S;

	// The list of strings used in realtime display of info over the mesh.
	// Each box is identified by the title, name of the mesh and text.
	// the name of the mesh is shown only if two or more box with the same title are shown.
	QMultiMap<QString, QPair<QString, QString> > RealTimeLogText;
};

#endif //GLLOGSTREAM_H

