/****************************************************************************
** Form interface generated from reading ui file 'msgDialog.ui'
**
** Created: Fri Nov 24 14:48:36 2000
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef MSGDIALOG_H
#define MSGDIALOG_H

#include "ui/ui_msgdialog.h"

class msgDialog : public QDialog
{ 
    Q_OBJECT

public:
    msgDialog( QWidget* parent = 0, Qt::WFlags fl = 0 );
    ~msgDialog();
	Ui::msgDialog ui;

};

#endif // MSGDIALOG_H
