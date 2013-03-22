#ifndef Q_BIIP_H
#define Q_BIIP_H

#include <QCoreApplication>
#include <QStringList>
#include <QVariantMap>

#include "factory.h"

class Input;
class Output;



/**
 *	The QBiip class.
 */

class QBiip : public QCoreApplication {

	Q_OBJECT

	public:

		QBiip( int argc, char* argv[ ]);

	public slots:

		int exec( );

	private:

		void parseArguments( );
		void printInformations( const QString& type, const Informations& infos ) const;

	private:

		QVariantMap _options;

		Input* _input;
		Output* _output;

};

#endif // Q_BIIP_H
