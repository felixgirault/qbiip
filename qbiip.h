#ifndef Q_BIIP_H
#define Q_BIIP_H

#include <QObject>
#include <QStringList>
#include <QVariantMap>

#include "factory.h"

class Input;
class Output;



/**
 *	The QBiip class.
 */

class QBiip : public QObject {

	Q_OBJECT

	public:

		QBiip( const QStringList& arguments, QObject* parent = 0 );

	public slots:

		void exec( );

	private:

		void parseArguments( const QStringList& arguments );
		void printInformations( const QString& type, const Informations& infos ) const;

	private:

		QVariantMap _options;

		Input* _input;
		Output* _output;

};

#endif // Q_BIIP_H
