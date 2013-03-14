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

void Biip::wait( ) {

	std::string line;
	std::getline( std::cin, line);

	QStringList tokens = QString( line.c_str( )).split( " ", QString::SkipEmptyParts );
	QString command = tokens.takeFirst( );

	if ( command == "note" ) {

	}
}
