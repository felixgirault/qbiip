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
					addTab( new Configurator( object ), it.key( ));
				} catch ( ... ) {
					//
				}
			}
		}

};

#endif // SELECTOR_H
