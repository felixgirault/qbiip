#ifndef SPEAKER_OUTPUT_H
#define SPEAKER_OUTPUT_H

#define TICK 1193180

#include "../output.h"



/**
 *	The SpeakerOutput class.
 */

class SpeakerOutput : public Output {

	Q_OBJECT

	public:

		SpeakerOutput( QObject* parent = 0 );
		~SpeakerOutput( );

	public slots:

		void play( const Note& note );

	private:

#ifdef Q_OS_UNIX
		int _console;	//!<
#endif

};

#endif // SPEAKER_OUTPUT_H
