#ifndef INTEGER_CONFIGURATOR_OPTION_H
#define INTEGER_CONFIGURATOR_OPTION_H

#include "../option.h"



/**
 *
 */

class IntegerConfiguratorOption : public ConfiguratorOption {

	public:

		IntegerConfiguratorOption( );

		QVariant value( ) const;

};

#endif // INTEGER_H
