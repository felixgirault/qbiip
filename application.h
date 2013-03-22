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

class Application : public QCoreApplication {

	Q_OBJECT

	public:

		Application( int argc, char* argv[ ]);

	public slots:

		int exec( );

	private:

		void parseArguments( );
		void printInformations( const QString& type, const Informations& infos ) const;

		void setupInput( );
		void setupOutput( );

	private:

		QVariantMap _options;

		Input* _input;
		Output* _output;

};

#endif // Q_BIIP_H
