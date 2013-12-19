#include <QUdpSocket>

#include "networkinput.h"
#include "../exception.h"
#include "../factory.h"



/**
 *
 */

REGISTER_PRODUCT(
	Input,
	NetworkInput,
	"network",
	"Sends notes over the network."
)



/**
 *
 */

NetworkInput::NetworkInput( QObject* parent ) :
	Input( parent ),
	_socket( new QUdpSocket( this )) {

	connect(
		_socket, &QUdpSocket::readyRead,
		this, &NetworkInput::processPendingDatagrams
	);
}



/**
 *
 */

NetworkInput::OptionList NetworkInput::options( ) const {

	OptionList options;
	options.append(
		Option(
			Option::Integer,
			"Port",
			"The port to listen to.",
			8119
		)
	);
	options.append(
		Option(
			Option::String,
			"Track",
			"The track to listen to."
		)
	);

	return options;
}



/**
 *
 */

void NetworkInput::start( ) {

	_track = option< QString >( "track" );

	if ( _track.isEmpty( )) {
		throw new Exception( "" );
	}

	_socket->bind(
		option< int >( "port", NETWORK_INPUT_DEFAULT_PORT ),
		QUdpSocket::ShareAddress
	);
}



/**
 *
 */

void NetworkInput::stop( ) {


}



/**
 *
 */

void NetworkInput::processPendingDatagrams( ) {

	while ( _socket->hasPendingDatagrams( )) {
		QByteArray datagram;
		datagram.resize( _socket->pendingDatagramSize( ));

		_socket->readDatagram( datagram.data( ), datagram.size( ));

		QDataStream stream( datagram );
		Note note;

		stream >> note;

		if ( note.track == _track ) {
			emit played( note );
		}
	}
}
