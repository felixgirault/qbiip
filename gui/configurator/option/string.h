#ifndef STRING_CONFIGURATOR_OPTION_H
#define STRING_CONFIGURATOR_OPTION_H

#include "../option.h"



/**
 *
 */

class StringConfiguratorOption : public ConfiguratorOption {

	public:

		StringConfiguratorOption( );

		QVariant value( ) const;

};

#endif // STRING_CONFIGURATOR_OPTION_H
