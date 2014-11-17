#ifndef STREAMS_H
#define STREAMS_H

#include <iostream>
#include <QString>



/**
 *
 */
std::ostream& operator<<(std::ostream& stream, const QString& string);
std::istream& operator>>(std::istream& stream, QString& string);

#endif // STREAMS_H
