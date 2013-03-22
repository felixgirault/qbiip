#ifndef BIIP_H
#define BIIP_H

#include <QCoreApplication>
#include <QObject>

#include "factory.h"

class Input;
class Output;



/**
 *	The Biip class.
 */

class Biip : public QCoreApplication {

	Q_OBJECT

	public:

		Biip( int argc, char* argv[ ]);

	public slots:

		int exec( );

	private:

		QVariantMap parseArguments( ) const;

		void printInformations( const QString& type, const Informations& infos ) const;

	private:

		Input* _input;
		Output* _output;

};

#endif // BIIP_H
