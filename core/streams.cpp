#include "streams.h"



/**
 *
 */
std::ostream& operator<<(std::ostream& stream, const QString& string) {
	stream << string.toStdString();
	return stream;
}



/**
 *
 */
std::istream& operator>>(std::istream& stream, QString& string) {
	std::string buffer;
	stream >> buffer;

	string = QString::fromStdString(buffer);
	return stream;
}
