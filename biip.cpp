#include <QString>
#include <QStringList>

#include <iostream>
#include <string>

#include "biip.h"



/**
 *
 */

Biip::Biip( ) {


}



/**
 *
 */

void Biip::exec( ) {

	std::string line;
	QString command;
	QStringList tokens;

	do {
		std::getline( std::cin, line );

		tokens = QString( line.c_str( )).split( " ", QString::SkipEmptyParts );
		command = tokens.takeFirst( );

		if ( command == "note" ) {

		}

	} while ( command != "quit" );
}

