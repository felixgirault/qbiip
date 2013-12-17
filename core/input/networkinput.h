#ifndef NETWORK_INPUT_H
#define NETWORK_INPUT_H

#define NETWORK_INPUT_DEFAULT_PORT 8119

#include "../input.h"

class QUdpSocket;



/**
 *	The NetworkInput class.
 */

class NetworkInput : public Input {

	Q_OBJECT

	public:

		NetworkInput( QObject* parent = 0 );

		OptionList options( ) const;
		void start( const QVariantMap& options );
		void stop( );

	private slots:

		void processPendingDatagrams( );

	private:

		int _port;
		QUdpSocket* _socket;	//!<

		QString _track;

};

#endif // NETWORK_INPUT_H
