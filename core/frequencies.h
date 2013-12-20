#ifndef FREQUENCIES_H
#define FREQUENCIES_H

#include <QHash>



/**
 *	The Frequencies class.
 */

class Frequencies {

	public:

		Frequencies( );

		float frequency( const QString& key ) const;

	private:

		QHash< QString, float > _frequencies;

};

#endif // FREQUENCIES_H
