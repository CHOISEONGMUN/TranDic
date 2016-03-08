#include "qtexam2.h"
#include <QtWidgets/QApplication>

#include <stdlib.h>
#include <qmessagebox.h>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtExam2 w;
	
	bool res = w.is_overlapped_execute();
	if (res == false) {
		QMessageBox(QMessageBox::Warning, APP_NAME, "Already Running This Process").exec();
		exit(1);
	}
	w.set_reg_pattern("<td class='ToWrd' >(.+)<em");
	//w.set_url_link("http://www.wordreference.com/enko/");
	w.set_url_link("http://www.wordreference.com/");
	w.hide();
	w.setVisible(false);
	return a.exec();
}
