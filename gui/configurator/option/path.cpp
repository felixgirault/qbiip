#include <QLineEdit>

#include "path.h"



/**
 *
 */

PathConfiguratorOption::PathConfiguratorOption( ) :
	ConfiguratorOption( new QLineEdit( )) {

}



/**
 *
 */

QVariant PathConfiguratorOption::value( ) const {

	QLineEdit* input = qobject_cast< QLineEdit* >( _widget );
	return QVariant( input->text( ));
}
