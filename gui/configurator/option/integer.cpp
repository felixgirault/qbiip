#include <QSpinBox>

#include "integer.h"



/**
 *
 */

IntegerConfiguratorOption::IntegerConfiguratorOption( ) :
	ConfiguratorOption( new QSpinBox( )) {

}



/**
 *
 */

QVariant IntegerConfiguratorOption::value( ) const {

	QSpinBox* input = qobject_cast< QSpinBox* >( _widget );
	return QVariant( input->value( ));
}
