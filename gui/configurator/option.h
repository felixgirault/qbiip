#ifndef CONFIGURATOR_OPTION_H
#define CONFIGURATOR_OPTION_H

#include <QList>
#include <QVariant>

class QWidget;



/**
 *
 */

class ConfiguratorOption {

	public:

		ConfiguratorOption( QWidget* widget );
		virtual ~ConfiguratorOption( );

		QWidget* widget( ) const;
		virtual QVariant value( ) const = 0;

	protected:

		QWidget* _widget;

};

#endif // CONFIGURATOR_OPTION_H
