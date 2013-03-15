#include <QUdpSocket>

#include "server.h"



/**
 *
 */

Server::Server( short port ) :
	_port( port ),
	_socket( new QUdpSocket( this )) {


}



/**
 *
 */

void Server::broadcast( const Note& note ) {

	QByteArray datagram;
	QDataStream stream( &datagram, QIODevice::WriteOnly );

	stream << note;

	_socket->writeDatagram(
		datagram,
		QHostAddress::Broadcast,
		_port
	);
}
