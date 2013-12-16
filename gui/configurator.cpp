#include <QFormLayout>

#include "configurator.h"
#include "../core/configurable.h"



/**
 * @brief Configurator::Configurator
 * @param parent
 */

Configurator::Configurator( Configurable* configurable, QWidget* parent ) :
	QWidget( parent ),
	_layout( new QFormLayout( this )),
	_configurable( configurable ) {

	setup( );
}



/**
 *
 */

void Configurator::setup( ) {



	foreach ( const Configurable::Option& option, _configurable->options( )) {
		switch ( option.type ) {
			case Configurable::Option::Integer:
				setupIntegerOption( option );
				break;

			case Configurable::Option::String:
				setupStringOption( option );
				break;

			case Configurable::Option::Path:
				setupPathOption( option );
				break;
		}
	}
}



/**
 *
 */

void Configurator::setupIntegerOption( const Configurable::Option& option ) {


	_layout->addRow( option.name,  );
}



/**
 *
 */

void Configurator::setupStringOption( const Configurable::Option& option ) {


}



/**
 *
 */

void Configurator::setupPathOption( const Configurable::Option& option ) {


}
