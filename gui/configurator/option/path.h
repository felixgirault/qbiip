#ifndef PATH_CONFIGURATOR_OPTION_H
#define PATH_CONFIGURATOR_OPTION_H

#include "../option.h"



/**
 *
 */

class PathConfiguratorOption : public ConfiguratorOption {

	public:

		PathConfiguratorOption( );

		QVariant value( ) const;

};

#endif // PATH_CONFIGURATOR_OPTION_H
