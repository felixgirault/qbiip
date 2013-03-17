#ifndef BIIP_H
#define BIIP_H

#include <QObject>

#include "factory.h"

class Input;
class Output;



/**
 *	The Biip class.
 */

class Biip : public QObject {

	public:

		Biip( QObject* parent = 0 );

		void exec( );

	private:

		QVariantMap parseArguments( ) const;

		void printInformations( const QString& type, const Informations& infos ) const;

	private:

		Input* _input;
		Output* _output;

};

#endif // BIIP_H
