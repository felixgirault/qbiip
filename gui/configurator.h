#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <QWidget>

class QFormLayout;
class Stream;
class ConfiguratorOption;



/**
 *	The Configurator class
 */

class Configurator : public QWidget
{
	Q_OBJECT

	public:

		Configurator( Stream* stream, QWidget* parent = 0 );
		~Configurator( );

	private:

		void setup( );

	private:

		QFormLayout* _layout;

		Stream* _stream;
		QList< ConfiguratorOption* > _options;

};

#endif // CONFIGURATOR_H
