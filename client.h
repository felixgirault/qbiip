#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

#include "note.h"

class QUdpSocket;



/**
 *	The Client class.
 */

class Client : public QObject {

	Q_OBJECT

	public:

		Client( short port = 8119 );

	signals:

		void noteReceived( const Note& note );

	private slots:

		void processPendingDatagrams( );

	private:

		QUdpSocket* _socket;	//!<

};

#endif // CLIENT_H
