#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>

template<typename T>
class Property {
	public:		
		QString key();

		T value();
};

#endif