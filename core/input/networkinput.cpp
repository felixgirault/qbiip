#include <QUdpSocket>

#include "networkinput.h"
#include "../exception.h"
#include "../factory.h"



/**
 *
 */
REGISTER_PRODUCT(
	Input,
	NetworkInput,
	"network",
	"Sends notes over the network."
)



/**
 *
 */
NetworkInput::NetworkInput(QObject* parent) :
	Input(parent),
	_port(0),
	_socket(new QUdpSocket(this)) {

	connect(
		_socket, &QUdpSocket::readyRead,
		this, &NetworkInput::processPendingDatagrams
	);
}



/**
 *
 */
NetworkInput::OptionList NetworkInput::options() const {
	OptionList options;
	options.append(
		Option(
			"port",
			"The port to listen to.",
			Option::Integer
		)
	);
	options.append(
		Option(
			"track",
			"The track to listen to.",
			Option::String
		)
	);

	return options;
}



/**
 *
 */
void NetworkInput::configure(const QVariantMap& options) {
	bool ok = false;
	_port = options.value("port").toInt(&ok);

	if (!ok) {
		_port = NETWORK_INPUT_DEFAULT_PORT;
	}

	_track = options.value("track").toString();

	if (_track.isEmpty()) {
		throw Exception(
			"Please provide a track name (-track trackName)."
		);
	}
}



/**
 *
 */
void NetworkInput::play() {
	_socket->bind(_port, QUdpSocket::ShareAddress);
}



/**
 *
 */
void NetworkInput::stop() {}



/**
 *
 */
void NetworkInput::processPendingDatagrams() {
	while (_socket->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(_socket->pendingDatagramSize());

		_socket->readDatagram(datagram.data(), datagram.size());

		QDataStream stream(datagram);
		Note note;

		stream >> note;

		if (note.track == _track) {
			emit played(note);
		}
	}
}
