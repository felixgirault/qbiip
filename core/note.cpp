#include "note.h"



/**
 *
 */
Note::Note() :
	track("main"),
	frequency(0),
	duration(0)
{}



/**
 *
 */
Note::Note(const QString& track, float frequency, quint64 duration) :
	track(track),
	frequency(frequency),
	duration(duration)
{}



/**
 *
 */
QDataStream& operator<<(QDataStream& stream, const Note& note) {
	stream << note.track << note.frequency << note.duration;
	return stream;
}



/**
 *
 */
QDataStream& operator>>(QDataStream& stream, Note& note) {
	stream >> note.track >> note.frequency >> note.duration;
	return stream;
}



/**
 *
 */
QDebug operator<<(QDebug stream, const Note& note) {
	stream << note.track << ":" << note.frequency << "/" << note.duration;
	return stream;
}



/**
 *
 */
std::ostream& operator<<(std::ostream& stream, const Note& note) {
	stream << note.track.toStdString() << ":" << note.frequency << "/" << note.duration;
	return stream;
}
