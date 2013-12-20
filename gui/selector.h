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

			typename Factory< Type >::MetaProductList types = Factory< Type >::types( );

			foreach ( const typename Factory< Type >::MetaProduct& type, types ) {
				Type* object = Factory< Type >::create( type.name( ));

				if ( object ) {
					Configurator* configurator = new Configurator( object );
					addTab( configurator, type.name( ));
					_configurators.append( configurator );
				}
			}

			_configurators.size( );
		}



		/**
		 *
		 */

		void start( ) {

			for ( int i = 0; i < _configurators.size( ); ++i ) {
				_configurators.at( i )->start( );
			}
		}



		/**
		 *
		 */

		void stop( ) {


		}

	private:

		QList< Configurator* > _configurators;

};

#endif // SELECTOR_H
