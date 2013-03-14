#include <QUdpSocket>

#include "client.h"



/**
 *
 */

Client::Client( short port ) :
	_socket( new QUdpSocket( this )) {

	_socket->bind( port, QUdpSocket::ShareAddress );

	connect(
		_socket, SIGNAL( readyRead( )),
		this, SLOT( processPendingDatagrams( ))
	);
}



/**
 *
 */

void Client::processPendingDatagrams( ) {

	while ( _socket->hasPendingDatagrams( )) {
		QByteArray datagram;
		datagram.resize( _socket->pendingDatagramSize( ));

		_socket->readDatagram( datagram.data( ), datagram.size( ));
	}
}
