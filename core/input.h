#ifndef INPUT_H
#define INPUT_H

#include "stream.h"
#include "note.h"



/**
 *	The Input class.
 */

class Input : public Stream {

	Q_OBJECT

	public:

		Input( QObject* parent = 0 );
		virtual ~Input( );

	signals:

		void played( const Note& note );

};

#endif // INPUT_H
