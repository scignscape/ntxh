#ifndef P_PREDICATE_H
#define P_PREDICATE_H

#include <QString>
#include <iostream>
#include <QVariant>
#include <stdlib.h>
#include <functional>


#define c_str toStdString().c_str

template<typename T>
T QVariant_cast(QVariant qvar);

template<>
int64_t QVariant_cast(QVariant qvar)
{
 return qvar.toLongLong();
}

template<>
uint64_t QVariant_cast(QVariant qvar)
{
 return qvar.toULongLong();
}

template<>
Vertex* QVariant_cast(QVariant qvar)
{
 return (Vertex*) qvar.value<void*>();
}

template<>
Edge* QVariant_cast(QVariant qvar)
{
 return (Edge*) qvar.value<void*>();
}

template<>
QString QVariant_cast(QVariant qvar)
{
 return qvar.value<QString>();
}



/**
    Equivalent of P in Java-Gremlin.
**/
template<typename T>
class P {
	public:
  static std::function<bool(QVariant)> eq(T b) {
			#ifdef VERBOSE
			std::cout << "generic method selected\n";
			#endif
   return [b](QVariant a) {
				return false;
			};
		}
};

template<>
class P<uint64_t> {
	public:
  static std::function<bool(QVariant)> eq(uint64_t b) {
   return [b](QVariant a) {
				#ifdef VERBOSE
				std::cout << "uint64_t method selected\n";	
				#endif
    return QVariant_cast<uint64_t>(a) == b;
			};
		}
};

template<>
class P<int64_t> {
	public:
  static std::function<bool(QVariant)> eq(uint64_t b) {
   return [b](QVariant a) {
				#ifdef VERBOSE
				std::cout << "int64_t method selected\n";
				#endif
    return QVariant_cast<int64_t>(a) == b;
			};
		}
};

template<>
class P<double> {
	public:
  static std::function<bool(QVariant)> eq(double b) {
   return [b](QVariant a) {
				#ifdef VERBOSE
				std::cout << "double method selected\n";
				#endif
    return QVariant_cast<double>(a) == b;
			};
		}
};

template<>
class P<QString> {
	public:
  static std::function<bool(QVariant)> eq(QString b) {
   return [b](QVariant a) {
				#ifdef VERBOSE
				std::cout << "string method selected\n";
				#endif
    return QVariant_cast<QString>(a).compare(b) == 0;
			};
		}
};

template<>
class P<char*> {
	public:
  static std::function<bool(QVariant)> eq(char* b) {
   return [b](QVariant a) {
				#ifdef VERBOSE
				std::cout << "char array method selected\n";
				#endif
    QString a_str = QVariant_cast<QString>(a);
				return strncmp(a_str.c_str(), b, a_str.length()) == 0;
			};
		}
};

#endif
