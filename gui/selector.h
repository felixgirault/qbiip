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
					addTab( configurator, it.key( ));
					_configurators.append( configurator );
				} catch ( ... ) {
					//
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
