#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "selector.h"

class QGridLayout;
class QPushButton;
class Input;
class Output;



/**
 *	The MainWindow class
 */

class MainWindow : public QMainWindow {

	Q_OBJECT

	public:

		MainWindow( QWidget* parent = 0 );

	public slots:

		void start( );

	private:

		void setup( );

	private:

		QGridLayout* _layout;
		QPushButton* _start;

		Selector< Input >* _inputSelector;
		Selector< Output >* _outputSelector;

};

#endif // MAINWINDOW_H
