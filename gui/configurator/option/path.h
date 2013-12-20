#ifndef PATH_CONFIGURATOR_OPTION_H
#define PATH_CONFIGURATOR_OPTION_H

#include "../option.h"

class QLineEdit;
class QPushButton;



/**
 *
 */

class PathConfiguratorOption : public ConfiguratorOption {

	public:

		PathConfiguratorOption( );

		QVariant value( ) const;

	private slots:

		void browse( );

	private:

		QLineEdit* _path;
		QPushButton* _browse;

};

#endif // PATH_CONFIGURATOR_OPTION_H
