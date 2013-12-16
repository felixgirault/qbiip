#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <QWidget>

class QFormLayout;
class Configurable;



/**
 *	The Configurator class
 */

class Configurator : public QWidget
{
	Q_OBJECT

	public:

		Configurator( Configurable* configurable, QWidget* parent = 0 );
		
	private:

		void setup( );
		void setupIntegerOption( const Configurable::Option& option );
		void setupStringOption( const Configurable::Option& option );
		void setupPathOption( const Configurable::Option& option );
		
	private:

		QFormLayout* _layout;

		Configurable* _configurable;
		
};

#endif // CONFIGURATOR_H
