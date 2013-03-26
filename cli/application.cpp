#include <QString>
#include <QStringList>

#include <iostream>
#include <iomanip>
#include <string>

#include "application.h"
#include "../core/input.h"
#include "../core/output.h"
#include "../core/streams.h"
#include "../core/exception.h"



/**
 *
 */

Application::Application( int argc, char* argv[ ]) :
	QCoreApplication( argc, argv ) {

	parseArguments( );
}



/**
 *
 */

int Application::exec( ) {

	if ( _options.contains( "help" )) {
		printInformations( "inputs", Factory< Input >::informations( ));
		printInformations( "outputs", Factory< Output >::informations( ));
		return 0;
	}

	try {
		setupInput( );
		setupOutput( );
	} catch ( const Exception& e ) {
		std::cerr << e.message( ) << std::endl;
		return 1;
	}

	connect( _input, &Input::played, _output, &Output::play );
	_input->play( );

	return QCoreApplication::exec( );
}



/**
 *
 */

void Application::parseArguments( ) {

	QString currentSwitch;

	foreach( const QString& argument, arguments( )) {
		if ( argument.startsWith( "-" )) {
			currentSwitch = argument.right( argument.size( ) - 1 );
		} else if ( !currentSwitch.isEmpty( )) {
			_options.insert( currentSwitch, argument );
		}
	}
}



/**
 *
 */

void Application::printInformations( const QString& type, const Informations& infos ) const {

	QMapIterator< QString, QString > it( infos );
	std::cout << "Available " << type.toStdString( ) << ":" << std::endl;

	while ( it.hasNext( )) {
		it.next( );
		std::cout << " " << it.key( ) << " - " << it.value( ) << std::endl;
	}
}



/**
 *
 */

void Application::setupInput( ) {

	if ( !_options.contains( "input" )) {
		throw Exception( "Please choose an input device (-input option)." );
	}

	QString inputName = _options.value( "input" ).toString( );
	_input = Factory< Input >::create( inputName );

	if ( !_input ) {
		throw Exception( "Please choose a valid input device (-help for a list)." );
	}

	_input->configure( _options );
}



/**
 *
 */

void Application::setupOutput( ) {

	if ( !_options.contains( "output" )) {
		throw Exception( "Please choose an output device (-output option)." );
	}

	QString outputName = _options.value( "output" ).toString( );
	_output = Factory< Output >::create( outputName );

	if ( !_output ) {
		throw Exception( "Please choose a valid output device (-help for a list)." );
	}

	_output->configure( _options );
}
