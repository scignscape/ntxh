#ifndef TRAVERSER_H
#define TRAVERSER_H

#include <list>
#include <map>
#include <string.h>
#include <QVariant>

class Traverser {
	private:
		QVariant my_data;
		std::list<QVariant> path;
		std::map<QString, QVariant> side_effects;

	public:
		Traverser(QVariant t) {
			my_data = QVariant(t);
		}

		virtual QVariant get() {
			return my_data;
		}

		virtual void replace_data(QVariant t) {
			my_data = t;
		}
};

typedef QVector<Traverser*> TraverserSet;

#endif