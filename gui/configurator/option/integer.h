#ifndef INTEGER_CONFIGURATOR_OPTION_H
#define INTEGER_CONFIGURATOR_OPTION_H

#include <QSpinBox>

#include "../option.h"



/**
 *
 */

class IntegerConfiguratorOption : public ConfiguratorOption {

	public:

		IntegerConfiguratorOption( );

		QVariant value( ) const;

	private:

		QSpinBox* _input;

};

#endif // INTEGER_H
