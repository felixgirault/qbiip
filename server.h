#ifndef SERVER_H
#define SERVER_H

#include <QObject>

#include "message.h"

class QUdpSocket;



/**
 *	The Server class.
 */

class Server : public QObject {

	Q_OBJECT

	public:

		/**
		 * @brief Server
		 * @param port
		 */

		Server( short port = 8119 );



		/**
		 * @brief broadcast
		 * @param message
		 */

		void broadcast( Message& message );

	private:

		short _port;	//!<
		QUdpSocket* _socket;	//!<

};

#endif // SERVER_H
