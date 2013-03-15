#ifndef SPEAKER_OUTPUTTER_H
#define SPEAKER_OUTPUTTER_H

#include "outputter.h"

#define TICK 1193180



/**
 *	The Speaker class.
 */

class SpeakerOutputter : public Outputter {

	Q_OBJECT

	public:

		/**
		 *
		 */

		SpeakerOutputter( );



		/**
		 *
		 */

		~SpeakerOutputter( );

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

#endif // SPEAKER_OUTPUTTER_H
