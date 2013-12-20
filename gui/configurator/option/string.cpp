#include "string.h"



/**
 *
 */

StringConfiguratorOption::StringConfiguratorOption( ) :
	ConfiguratorOption( ),
	_input( new QLineEdit( )) {

	_layout->addWidget( _input );
}



/**
 *
 */

QVariant StringConfiguratorOption::value( ) const {

	return QVariant( _input->text( ));
}
