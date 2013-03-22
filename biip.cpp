#include <QString>
#include <QStringList>

#include <iostream>
#include <iomanip>
#include <string>

#include "biip.h"
#include "input.h"
#include "output.h"
#include "exception.h"



/**
 *
 */

Biip::Biip( int argc, char* argv[ ]) :
	QCoreApplication( argc, argv ) {

}



/**
 *
 */

int Biip::exec( ) {

	QVariantMap options = parseArguments( );
	Informations inputInfos = Factory< Input >::informations( );
	Informations outputInfos = Factory< Output >::informations( );

	if ( options.contains( "help" )) {
		printInformations( "inputs", inputInfos );
		printInformations( "outputs", outputInfos );
		return 1;
	}

	if ( !options.contains( "input" )) {
		std::cerr << "Please choose an input (-input option)." << std::endl;
		printInformations( "inputs", inputInfos );
		return 1;
	}

	QString inputName = options.value( "input" ).toString( );
	_input = Factory< Input >::create( inputName );

	if ( !_input ) {
		std::cerr << "Please choose a valid input." << std::endl;
		printInformations( "inputs", inputInfos );
		return 1;
	}

	try {
		_input->configure( options );
	} catch ( const Exception& e ) {
		std::cerr << e.message( ).toStdString( ) << std::endl;
		return 1;
	}

	if ( !options.contains( "output" )) {
		std::cerr << "Please choose an output (-output option)." << std::endl;
		printInformations( "outputs", outputInfos );
		return 1;
	}

	QString outputName = options.value( "output" ).toString( );
	_output = Factory< Output >::create( outputName );

	if ( !_output ) {
		std::cerr << "Please choose a valid output." << std::endl;
		printInformations( "outputs", outputInfos );
		return 1;
	}

	try {
		_output->configure( options );
	} catch ( const Exception& e ) {
		std::cerr << e.message( ).toStdString( ) << std::endl;
		return 1;
	}

	connect( _input, &Input::played, _output, &Output::play );

	_input->play( );
}



/**
 *
 */

QVariantMap Biip::parseArguments( ) const {

	QStringList arguments = qApp->arguments( );
	QString currentSwitch;
	QVariantMap parsed;

	foreach( const QString& argument, arguments ) {
		if ( argument.startsWith( "-" )) {
			currentSwitch = argument.right( argument.size( ) - 1 );
		} else if ( !currentSwitch.isEmpty( )) {
			parsed.insert( currentSwitch, argument );
		}
	}

	return parsed;
}



/**
 *
 */

void Biip::printInformations( const QString& type, const Informations& infos ) const {

	std::cout << "Available " << type.toStdString( ) << ":" << std::endl;

	QMapIterator< QString, QString > it( infos );

	while ( it.hasNext( )) {
		it.next( );

		std::cout
			<< " "
			<< it.key( ).toStdString( )
			<< " - "
			<< it.value( ).toStdString( )
			<< std::endl;
	}
}
