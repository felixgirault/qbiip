#ifndef MESSAGE_H
#define MESSAGE_H

#include <QByteArray>



/**
 *	The Message class.
 */

class Message
{
	public:

		/**
		 * @brief Message
		 * @param channel
		 */

		Message( int channel = 0 );



		/**
		 * @brief channel
		 * @return
		 */

		int channel( ) const;



		/**
		 * @brief datagram
		 * @return
		 */

		QByteArray datagram( ) const;

	private:

		int _channel;	//!<

};

#endif // MESSAGE_H
