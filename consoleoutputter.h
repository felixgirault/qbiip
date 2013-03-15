#ifndef CONSOLEOUTPUTTER_H
#define CONSOLEOUTPUTTER_H

#include "outputter.h"



/**
 *	The ConsoleOutputter class
 */

class ConsoleOutputter : public Outputter {

	public slots:

		/**
		 *
		 */

		void output( const Note& note );

};

#endif // CONSOLEOUTPUTTER_H
