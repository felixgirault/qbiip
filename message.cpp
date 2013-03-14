#include "message.h"



/**
 *
 */

Message::Message( int channel ) :
	_channel( channel ) {

}



/**
 *
 */

int Message::channel( ) const {

	return _channel;
}



/**
 *
 */

QByteArray Message::datagram( ) const {

	QByteArray datagram;
	datagram += _channel;

	return datagram;
}
