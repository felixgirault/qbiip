#ifndef FREQUENCIES_H
#define FREQUENCIES_H

#include <QMap>



/**
 *	The Frequencies class.
 */

class Frequencies {

	public:

		Frequencies( );

		float frequency( const QString& key ) const;

	private:

		QMap< QString, float > _frequencies;

};

#endif // FREQUENCIES_H
