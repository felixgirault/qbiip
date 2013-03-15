#ifndef NETWORKPLAYER_H
#define NETWORKPLAYER_H

#include "player.h"

class Server;



/**
 *	The NetworkPlayer class.
 */

class NetworkPlayer : public Player
{
	public:

		/**
		 *
		 */

		NetworkPlayer( Server* server );

	public slots:

		/**
		 *
		 */

		void play( const Note& note );

	private:

		Server* _server;

};

#endif // NETWORKPLAYER_H
