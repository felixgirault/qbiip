#ifndef SPEAKERPLAYER_H
#define SPEAKERPLAYER_H

#include "player.h"

#define TICK 1193180



/**
 *	The SpeakerPlayer class.
 */

class SpeakerPlayer : public Player {

	Q_OBJECT

	public:

		SpeakerPlayer( );
		~SpeakerPlayer( );

	public slots:

		void play( const Note& note );

#ifdef Q_OS_UNIX
	private:

		int _console;	//!<
#endif

};

#endif // SPEAKERPLAYER_H
