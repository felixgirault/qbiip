#ifndef CONSOLEPLAYER_H
#define CONSOLEPLAYER_H

#include "player.h"



/**
 *	The ConsolePlayer class
 */

class ConsolePlayer : public Player {

	public slots:

		void play( const Note& note );

};

#endif // CONSOLEPLAYER_H
