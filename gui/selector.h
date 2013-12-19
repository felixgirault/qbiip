#ifndef SELECTOR_H
#define SELECTOR_H

#include <QTabWidget>

#include "configurator.h"
#include "../core/factory.h"
#include "../core/configurable.h"
#include "../core/input.h"
#include "../core/output.h"

class QVBoxLayout;
class QComboBox;



/**
 *
 */

template< class Type >
class Selector : public QTabWidget {

	public:

		/**
		 *
		 */

		Selector( QWidget* parent = 0 ) :
			QTabWidget( parent ) {

			Informations informations = Factory< Type >::informations( );
			InformationsIterator it( informations );

			while ( it.hasNext( )) {
				it.next( );

				try {
					Type* object = Factory< Type >::create( it.key( ));
					Configurator* configurator = new Configurator( object );
					_configurators.append( configurator );
					addTab( configurator, it.key( ));
				} catch ( ... ) {
					//
				}
			}
		}



		/**
		 *
		 */

		void start( ) {

			foreach ( Configurator* configurator, _configurators ) {
				configurator->start( );
			}
		}



		/**
		 *
		 */

		void stop( ) {

			foreach ( Configurator* configurator, _configurators ) {
				configurator->stop( );
			}
		}

	private:

		QList< Configurator* > _configurators;

};

#endif // SELECTOR_H
