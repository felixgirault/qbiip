#ifndef SERVER_H
#define SERVER_H

#include <QObject>

#include "note.h"

class QUdpSocket;



/**
 *	The Server class.
 */

class Server : public QObject {

	Q_OBJECT

	public:

		Server( short port = 8119 );

		void broadcast( const Note& note );

	private:

		short _port;	//!<
		QUdpSocket* _socket;	//!<

};

#endif // SERVER_H
