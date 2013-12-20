#include "integer.h"



/**
 *
 */

IntegerConfiguratorOption::IntegerConfiguratorOption( ) :
	ConfiguratorOption( ),
	_input( new QSpinBox( )) {

	_layout->addWidget( _input );
}



/**
 *
 */

QVariant IntegerConfiguratorOption::value( ) const {

	return QVariant( _input->value( ));
}
