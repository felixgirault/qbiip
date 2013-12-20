#ifndef CONFIGURATOR_OPTION_H
#define CONFIGURATOR_OPTION_H

#include <QObject>
#include <QList>
#include <QVariant>

class QWidget;



/**
 *
 */

class ConfiguratorOption : public QObject {

	public:

		ConfiguratorOption( QWidget* widget = 0 );
		virtual ~ConfiguratorOption( );

		QWidget* widget( ) const;
		virtual QVariant value( ) const = 0;

	protected:

		QWidget* _widget;

};

#endif // CONFIGURATOR_OPTION_H
