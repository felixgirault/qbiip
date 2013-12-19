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
	_socket( new QUdpSocket( this )) {

}



/**
 *
 */

NetworkOutput::OptionList NetworkOutput::options( ) const {

	OptionList options;
	options.append(
		Option(
			Option::Integer,
			"Port",
			"The port on which to listen to.",
			NETWORK_OUTPUT_DEFAULT_PORT
		)
	);

	return options;
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
		option< int >( "port", NETWORK_OUTPUT_DEFAULT_PORT )
	);
}
