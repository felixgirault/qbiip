#ifndef NOTE_H
#define NOTE_H

#include <QDataStream>
#include <QDebug>
#include <ostream>



/**
 *	The Note class.
 */
class Note {

	public:

		Note();
		Note(const QString& track, float frequency, quint64 duration);

	public:

		QString track;	//!<
		float frequency;	//!<
		quint64 duration;	//!<

};



/**
 *
 */
QDataStream& operator<<(QDataStream& stream, const Note& note);
QDataStream& operator>>(QDataStream& stream, Note& note);



/**
 *
 */
QDebug operator<<(QDebug stream, const Note& note);



/**
 *
 */
std::ostream& operator<<(std::ostream& stream, const Note& note);

#endif // NOTE_H
