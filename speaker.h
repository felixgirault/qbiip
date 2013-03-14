#ifndef SPEAKER_H
#define SPEAKER_H

#include "outputter.h"

#define TICK 1193180



/**
 *	The Speaker class.
 */

class Speaker : public Outputter {

	Q_OBJECT

	public:

		/**
		 *
		 */

		Speaker( );



		/**
		 *
		 */

		~Speaker( );

	public slots:

		/**
		 *
		 */

		void output( const Note& note );

#ifdef Q_OS_UNIX
	private:

		int _console;	//!<
#endif

};

#endif // SPEAKER_H
