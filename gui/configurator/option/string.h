#ifndef STRING_CONFIGURATOR_OPTION_H
#define STRING_CONFIGURATOR_OPTION_H

#include <QLineEdit>

#include "../option.h"



/**
 *
 */

class StringConfiguratorOption : public ConfiguratorOption {

	public:

		StringConfiguratorOption( );

		QVariant value( ) const;

	private:

		QLineEdit* _input;

};

#endif // STRING_CONFIGURATOR_OPTION_H
