#ifndef CONFIGURATOR_OPTION_H
#define CONFIGURATOR_OPTION_H

#include <QWidget>
#include <QVariant>
#include <QHBoxLayout>



/**
 *
 */

class ConfiguratorOption : public QWidget {

	public:

		ConfiguratorOption( QWidget* parent = 0 );
		virtual ~ConfiguratorOption( );

		virtual QVariant value( ) const = 0;

	protected:

		QHBoxLayout* _layout;

};

#endif // CONFIGURATOR_OPTION_H
