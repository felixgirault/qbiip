#ifndef NETWORK_OUTPUT_H
#define NETWORK_OUTPUT_H

#define NETWORK_OUTPUT_DEFAULT_PORT 8119

#include "../output.h"

class QUdpSocket;



/**
 *	The NetworkOutput class.
 */

class NetworkOutput : public Output
{
	public:

		NetworkOutput( QObject* parent = 0 );

		OptionList options( ) const;

	public slots:

		void play( const Note& note );

	private:

		int _port;	//<!
		QUdpSocket* _socket;	//!<

};

#endif // NETWORK_OUTPUT_H
