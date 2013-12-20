#include <QFormLayout>
#include <QLabel>

#include "configurator.h"
#include "configurator/option.h"
#include "configurator/option/integer.h"
#include "configurator/option/string.h"
#include "configurator/option/path.h"
#include "../core/stream.h"



/**
 *
 */

Configurator::Configurator( Stream* stream, QWidget* parent ) :
	QWidget( parent ),
	_layout( new QFormLayout( this )),
	_stream( stream ) {

	setup( );
}



/**
 *
 */

Configurator::~Configurator( ) {

	qDeleteAll( _options );
}



/**
 *
 */

void Configurator::start( ) {

	_stream->start( );
}



/**
 *
 */

void Configurator::stop( ) {

	_stream->stop( );
}



/**
 *
 */

void Configurator::setup( ) {

	Stream::OptionList options = _stream->options( );

	if ( options.isEmpty( )) {
		_layout->addRow( "No options available.", ( QWidget* )0 );
	} else {
		foreach ( const Stream::Option& o, _stream->options( )) {
			ConfiguratorOption* option = 0;

			switch ( o.type ) {
				case Stream::Option::Integer:
					option = new IntegerConfiguratorOption( );
					break;

				case Stream::Option::String:
					option = new StringConfiguratorOption( );
					break;

				case Stream::Option::Path:
					option = new PathConfiguratorOption( );
					break;

				default:
					continue;
			}

			_layout->addRow( o.name, option );
			_options.append( option );
		}
	}
}
