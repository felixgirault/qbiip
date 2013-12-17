#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>
#include <iostream>

#include "scoreinput.h"
#include "../exception.h"
#include "../factory.h"



/**
 *
 */

REGISTER_PRODUCT(
	Input,
	ScoreInput,
	"score",
	"Plays notes from a biip score."
)



/**
 *
 */

ScoreInput::ScoreInput( QObject* parent ) :
	Input( parent ),
	_unit( 0 ),
	_current( 0 ),
	_timer( new QTimer( this )) {

	connect( _timer, &QTimer::timeout, this, &ScoreInput::check );
}



/**
 *
 */

ScoreInput::OptionList ScoreInput::options( ) const {

	OptionList options;
	options.append(
		Option(
			Option::String,
			"Score file",
			"The path to the score to play."
		)
	);

	return options;
}



/**
 *	@todo Add a -repeat [times] option.
 */

void ScoreInput::configure( const QString& name, const QVariant& value ) {

	if ( name == "score" ) {
		QString fileName = value.toString( );

		if ( fileName.isEmpty( )) {
			throw Exception(
				"Please provide a score (-score fileName)."
			);
		}

		load( fileName );
	}
}



/**
 *
 */

void ScoreInput::load( const QString& fileName ) {

	_notes.clear( );
	_current = 0;

	QFile file( fileName );

	if ( !file.open( QFile::ReadOnly | QFile::Text )) {
		throw Exception(
			QString( "Unable to open '%1' : %2" ).arg(
				fileName,
				file.errorString( )
			)
		);
	}

	QTextStream stream( &file );
	QString text = stream.readAll( );

	QJsonDocument document = QJsonDocument::fromJson( text.toUtf8( ));
	QJsonObject documentObject = document.object( );
	QJsonValue unitValue = documentObject.value( "unit" );

	if ( unitValue.isUndefined( ) || !unitValue.isDouble( )) {
		throw Exception(
			"The 'unit' element is either missing or malformed"
		);
	}

	_unit = unitValue.toDouble( );

	QJsonValue tracksValue = documentObject.value( "tracks" );

	if ( tracksValue.isUndefined( ) || !tracksValue.isObject( )) {
		throw Exception(
			"The 'tracks' element is either missing or malformed"
		);
	}

	QJsonObject tracksObject = tracksValue.toObject( );
	QStringList trackNames = tracksObject.keys( );

	foreach ( const QString& trackName, trackNames ) {
		QJsonValue trackValue = tracksObject.value( trackName );

		if ( trackValue.isUndefined( ) || !trackValue.isObject( )) {
			continue;
		}

		QJsonObject trackObject = trackValue.toObject( );
		QStringList noteNames = trackObject.keys( );

		foreach ( const QString& noteName, noteNames ) {
			float frequency;

			try {
				frequency = _frequencies.frequency( noteName );
			} catch ( const Exception& e ) {
				std::cerr << e.message( ).toStdString( ) << std::endl;
				continue;
			}

			QJsonValue noteLineValue = trackObject.value( noteName );

			if ( noteLineValue.isUndefined( ) || !noteLineValue.isString( )) {
				continue;
			}

			QString noteLine = noteLineValue.toString( );
			int noteLineSize = noteLine.size( );
			int position = 0;

			if ( _notes.size( ) < noteLineSize ) {
				_notes.resize( noteLineSize );
			}

			foreach ( const QChar& c, noteLine ) {
				if ( c.isNumber( )) {
					bool ok = false;
					uint units = QString( c ).toUInt( &ok );

					if ( ok ) {
						_notes[ position ].append(
							Note( trackName, frequency, _unit * units )
						);
					}
				}

				++position;
			}
		}
	}
}



/**
 *
 */

void ScoreInput::start( const QVariantMap& options ) {

	_timer->start( _unit );
}



/**
 *
 */

void ScoreInput::stop( ) {

	_timer->stop( );
	_current = 0;
}



/**
 *
 */

void ScoreInput::check( ) {

	const QList< Note >& notes = _notes.at( _current );

	foreach ( const Note& note, notes ) {
		emit played( note );
	}

	++_current;

	if ( _current >= _notes.size( )) {
		stop( );
	}
}
