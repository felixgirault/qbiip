#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>

#include "frequencies.h"
#include "exception.h"



/**
 *
 */

Frequencies::Frequencies( ) {

	_frequencies.insert( "C2", 65.4064 );
	_frequencies.insert( "C#2", 69.2957 );
	_frequencies.insert( "Db2", 69.2957 );
	_frequencies.insert( "D2", 73.4162 );
	_frequencies.insert( "D#2", 77.7817 );
	_frequencies.insert( "Eb2", 77.7817 );
	_frequencies.insert( "E2", 82.4069 );
	_frequencies.insert( "F2", 87.3071 );
	_frequencies.insert( "F#2", 92.4986 );
	_frequencies.insert( "Gb2", 92.4986 );
	_frequencies.insert( "G2", 97.9989 );
	_frequencies.insert( "G#2", 103.826 );
	_frequencies.insert( "Ab2", 103.826 );
	_frequencies.insert( "A2", 110.000 );
	_frequencies.insert( "A#2", 116.541 );
	_frequencies.insert( "Bb2", 116.541 );
	_frequencies.insert( "B2", 123.471 );

	_frequencies.insert( "C3", 130.813 );
	_frequencies.insert( "C#3", 138.591 );
	_frequencies.insert( "Db3", 138.591 );
	_frequencies.insert( "D3", 146.832 );
	_frequencies.insert( "D#3", 155.563 );
	_frequencies.insert( "Eb3", 155.563 );
	_frequencies.insert( "E3", 164.814 );
	_frequencies.insert( "F3", 174.614 );
	_frequencies.insert( "F#3", 184.997 );
	_frequencies.insert( "Gb3", 184.997 );
	_frequencies.insert( "G3", 195.998 );
	_frequencies.insert( "G#3", 207.652 );
	_frequencies.insert( "Ab3", 207.652 );
	_frequencies.insert( "A3", 220.000 );
	_frequencies.insert( "A#3", 233.082 );
	_frequencies.insert( "Bb3", 233.082 );
	_frequencies.insert( "B3", 246.942 );

	_frequencies.insert( "C4", 261.626 );
	_frequencies.insert( "C#4", 277.183 );
	_frequencies.insert( "Db4", 277.183 );
	_frequencies.insert( "D4", 293.665 );
	_frequencies.insert( "D#4", 311.127 );
	_frequencies.insert( "Eb4", 311.127 );
	_frequencies.insert( "E4", 329.628 );
	_frequencies.insert( "F4", 349.228 );
	_frequencies.insert( "F#4", 369.994 );
	_frequencies.insert( "Gb4", 369.994 );
	_frequencies.insert( "G4", 391.995 );
	_frequencies.insert( "G#4", 415.305 );
	_frequencies.insert( "Ab4", 415.305 );
	_frequencies.insert( "A4", 440.000 );
	_frequencies.insert( "A#4", 466.164 );
	_frequencies.insert( "Bb4", 466.164 );
	_frequencies.insert( "B4", 493.883 );

	_frequencies.insert( "C5", 523.251 );
	_frequencies.insert( "C#5", 554.365 );
	_frequencies.insert( "Db5", 554.365 );
	_frequencies.insert( "D5", 587.330 );
	_frequencies.insert( "D#5", 622.254 );
	_frequencies.insert( "Eb5", 622.254 );
	_frequencies.insert( "E5", 659.255 );
	_frequencies.insert( "F5", 698.456 );
	_frequencies.insert( "F#5", 739.989 );
	_frequencies.insert( "Gb5", 739.989 );
	_frequencies.insert( "G5", 783.991 );
	_frequencies.insert( "G#5", 830.609 );
	_frequencies.insert( "Ab5", 830.609 );
	_frequencies.insert( "A5", 880.000 );
	_frequencies.insert( "A#5", 932.328 );
	_frequencies.insert( "Bb5", 932.328 );
	_frequencies.insert( "B5", 987.767 );

	_frequencies.insert( "C6", 1046.50 );
	_frequencies.insert( "C#6", 1108.73 );
	_frequencies.insert( "Db6", 1108.73 );
	_frequencies.insert( "D6", 1174.66 );
	_frequencies.insert( "D#6", 1244.51 );
	_frequencies.insert( "Eb6", 1244.51 );
	_frequencies.insert( "E6", 1318.51 );
	_frequencies.insert( "F6", 1396.91 );
	_frequencies.insert( "F#6", 1479.98 );
	_frequencies.insert( "Gb6", 1479.98 );
	_frequencies.insert( "G6", 1567.98 );
	_frequencies.insert( "G#6", 1661.22 );
	_frequencies.insert( "Ab6", 1661.22 );
	_frequencies.insert( "A6", 1760.00 );
	_frequencies.insert( "A#6", 1864.66 );
	_frequencies.insert( "Bb6", 1864.66 );
	_frequencies.insert( "B6", 1975.53 );
}



/**
 *
 */

float Frequencies::frequency( const QString& key ) const {

	if ( !_frequencies.contains( key )) {
		throw Exception(
			QString( "No frequency named '%1'" ).arg( key )
		);
	}

	return _frequencies.value( key );
}
