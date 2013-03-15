#include "networkoutputter.h"
#include "server.h"



/**
 *
 */

NetworkOutputter::NetworkOutputter( Server* server ) :
	_server( server ) {

}



/**
 *
 */

void NetworkOutputter::output( const Note& note ) {

	_server->broadcast( note );
}
