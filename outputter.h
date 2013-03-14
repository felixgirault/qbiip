#ifndef OUTPUTTER_H
#define OUTPUTTER_H

#include <QObject>

#include "note.h"



/**
 *
 */

class Outputter : public QObject {

	Q_OBJECT

	public:

		/**
		 *
		 */

		Outputter( ) { }



		/**
		 *
		 */

		virtual ~Outputter( ) { }

	public slots:

		/**
		 *
		 */

		virtual void output( const Note& note ) = 0;

};

#endif // OUTPUTTER_H
