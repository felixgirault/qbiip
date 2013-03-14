#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class QUdpSocket;



/**
 *	The Client class.
 */

class Client : public QObject {

	Q_OBJECT

	public:

		/**
		 * @brief Client
		 * @param port
		 */

		Client( short port = 8119 );

	private slots:

		/**
		 * @brief processPendingDatagrams
		 */

		void processPendingDatagrams( );

	private:

		QUdpSocket* _socket;	//!<

};

#endif // CLIENT_H
