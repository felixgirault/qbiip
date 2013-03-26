#ifndef OUTPUT_H
#define OUTPUT_H

#include "configurable.h"
#include "note.h"



/**
 *	The Output class.
 */

class Output : public Configurable {

	Q_OBJECT

	public:

		Output( QObject* parent = 0 );
		virtual ~Output( );

	public slots:

		virtual void play( const Note& note ) = 0;

};

#endif // OUTPUT_H
