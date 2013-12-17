#include <QWidget>

#include "option.h"



/**
 *
 */

ConfiguratorOption::ConfiguratorOption( QWidget* widget ) :
	_widget( widget ) {

}



/**
 *
 */

ConfiguratorOption::~ConfiguratorOption( ) {

}



/**
 *
 */

QWidget* ConfiguratorOption::widget( ) const {

	return _widget;
}
