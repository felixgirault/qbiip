#ifndef SCORE_INPUT_H
#define SCORE_INPUT_H

#include <QVector>
#include <QList>

#include "input.h"
#include "frequencies.h"

class QTimer;


/**
 *	The ScoreInput class.
 */

class ScoreInput : public Input {

	Q_OBJECT

	public:

		ScoreInput( QObject* parent = 0 );

		void configure( const QVariantMap& options );
		void load( const QString& fileName );

		void play( );
		void stop( );

	private slots:

		void check( );

	private:

		int _unit;
		int _current;
		QTimer* _timer;
		Frequencies _frequencies;
		QVector< QList< Note > > _notes;

};

#endif // SCORE_INPUT_H
