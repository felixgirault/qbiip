#ifndef NOTE_H
#define NOTE_H

#include <QDataStream>



/**
 *	The Note class.
 */

class Note {

	public:

		/**
		 *
		 */

		Note( );



		/**
		 *
		 */

		Note( float frequency, quint64 duration );

	public:

		float frequency;	//!<
		quint64 duration;	//!<

};



/**
 *
 */

QDataStream& operator<<( QDataStream& stream, const Note& note );
QDataStream& operator>>( QDataStream& stream, Note& note );

#endif // NOTE_H
