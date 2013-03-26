#include <QUdpSocket>

#include "networkoutput.h"
#include "../factory.h"



/**
 *
 */

REGISTER_PRODUCT(
	Output,
	NetworkOutput,
	"network",
	"Plays notes received from the network."
)



/**
 *
 */

NetworkOutput::NetworkOutput( QObject* parent ) :
	Output( parent ),
	_port( 0 ),
	_socket( new QUdpSocket( this )) {

}



/**
 *
 */

NetworkOutput::OptionList NetworkOutput::options( ) const {

	OptionList options;
	options.append(
		Option(
			"port",
			"The port on which to listen to.",
			QMetaType::Int
		)
	);

	return options;
}



/**
 *
 */

void NetworkOutput::configure( const QVariantMap& options ) {

	bool ok = false;
	_port = options.value( "port" ).toInt( &ok );

	if ( !ok ) {
		_port = NETWORK_OUTPUT_DEFAULT_PORT;
	}
}



/**
 *
 */

void NetworkOutput::play( const Note& note ) {

	QByteArray datagram;
	QDataStream stream( &datagram, QIODevice::WriteOnly );

	stream << note;

	_socket->writeDatagram(
		datagram,
		QHostAddress::Broadcast,
		_port
	);
}
