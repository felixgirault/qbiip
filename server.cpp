#include <QUdpSocket>

#include "server.h"



/**
 *
 */

Server::Server( short port ) :
	_port( port ),
	_socket( new QUdpSocket( this ))
{ }



/**
 *
 */

void Server::broadcast( Message& message ) {

	QByteArray datagram = message.datagram( );

	_socket->writeDatagram(
		datagram.data( ),
		datagram.size( ),
		QHostAddress::Broadcast,
		_port
	);
}
