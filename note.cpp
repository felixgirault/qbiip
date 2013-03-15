#include "note.h"



/**
 *
 */

Note::Note( ) :
	frequency( 0 ),
	duration( 0 )
{ }



/**
 *
 */

Note::Note( float frequency, quint64 duration ) :
	frequency( frequency ),
	duration( duration )
{ }



/**
 *
 */

QDataStream& operator<<( QDataStream& stream, const Note& note ) {

	stream << note.frequency;
	stream << note.duration;

	return stream;
}



/**
 *
 */

QDataStream& operator>>( QDataStream& stream, Note& note ) {

	stream >> note.frequency;
	stream >> note.duration;

	return stream;
}
