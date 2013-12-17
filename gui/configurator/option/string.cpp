#include <QLineEdit>

#include "string.h"



/**
 *
 */

StringConfiguratorOption::StringConfiguratorOption( ) :
	ConfiguratorOption( new QLineEdit( )) {

}



/**
 *
 */

QVariant StringConfiguratorOption::value( ) const {

	QLineEdit* input = qobject_cast< QLineEdit* >( _widget );
	return QVariant( input->text( ));
}
