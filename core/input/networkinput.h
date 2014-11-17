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

		NetworkInput(QObject* parent = 0);

		OptionList options() const;
		void configure(const QVariantMap& options);

		void play();
		void stop();

	private slots:

		void processPendingDatagrams();

	private:

		int _port;
		QUdpSocket* _socket;	//!<

		QString _track;

};

#endif // NETWORK_INPUT_H
