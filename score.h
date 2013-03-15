#ifndef SCORE_H
#define SCORE_H

#include <QObject>

#include "note.h"



/**
 *	The Score class.
 */

class Score : public QObject {

	Q_OBJECT

	public:

		Score( );

		void load( const QString& fileName );

		void play( );

	signals:

		void note( const Note& note );

	private:



};

#endif // SCORE_H
