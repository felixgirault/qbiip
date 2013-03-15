#include "networkplayer.h"
#include "server.h"



/**
 *
 */

NetworkPlayer::NetworkPlayer( Server* server ) :
	_server( server ) {

}



/**
 *
 */

void NetworkPlayer::play( const Note& note ) {

	_server->broadcast( note );
}
