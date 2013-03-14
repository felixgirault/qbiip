#ifndef CONSOLE_H
#define CONSOLE_H

#include "outputter.h"



/**
 * @brief The Console class
 */

class Console : public Outputter {

	public slots:

		/**
		 * @brief output
		 * @param note
		 */

		void output( const Note& note );

};

#endif // CONSOLE_H
