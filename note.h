#ifndef NOTE_H
#define NOTE_H

#include <QtGlobal>



/**
 *	The Note class.
 */

class Note {

	public:

		/**
		 * @brief Note
		 * @param frequency
		 * @param duration
		 */

		Note( float frequency, quint64 duration );

	public:

		float frequency;	//!<
		quint64 duration;	//!<

};

#endif // NOTE_H
