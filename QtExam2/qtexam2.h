#ifndef QTEXAM2_H
#define QTEXAM2_H

#define APP_NAME "TranDic"

#define DIC_RU		0
#define DIC_POL		1
#define DIC_ROM		2
#define	DIC_CZE		3
#define DIC_GRE		4
#define DIC_TUR		5
#define DIC_CHI		6
#define DIC_JAP		7
#define DIC_KOR		8
#define DIC_ARA		9

static int g_dic_max_count = 10;
static char g_dic_short_name_str[10][10] = {
	"enru",
	"enpl",
	"enro",
	"encz",
	"engr",
	"estr",
	"enzh",
	"enja",
	"enko",
	"enar"
};

static char g_dic_name_str[10][25] = {
	"WR English-Russian",
	"WR English-Polish",
	"WR English-Romanian",
	"WR English-Czech",
	"WR English-Greek",
	"WR English-Turkish",
	"WR English-Chinese",
	"WR English-Japanese",
	"WR English-Korean",
	"WR English-Arabic"
};

static int g_sel_word_idx = -1;
static bool g_sel_active = 1;

#include <qstring.h>
#include <qdebug.h>
#include <qclipboard.h>
#include <qmimedata.h>
#include <qdir.h>
#include <qevent.h>
#include <qlocale.h>
#include <qsharedmemory.h>
#include <qimagereader.h>
#include <qpixmap.h>
#include <qlabel.h>

#include <QtWidgets/qlabel.h>
#include <QtWidgets/qtextedit.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qmenu.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/qsystemtrayicon.h>

#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkrequest.h>
#include <QtNetwork/qnetworkreply.h>



//#include "DictionaryReqManager.h"
#include "ui_qtexam2.h"


class InfoDlg : public QWidget
{
Q_OBJECT
private:
	QTextEdit info_edit;
	QString content_str;
	QVBoxLayout main_layout;
	QLabel word_img_label;
	
	
public:
	InfoDlg(QObject *parent=NULL);
	virtual void closeEvent(QCloseEvent *event);
};


class SettingDlg : public QWidget
{
Q_OBJECT
private:
	QListWidget listbox;
	QLabel dic_label;
	QLabel status_label;
	QVBoxLayout main_layout;
	QHBoxLayout btn_layout;
	QHBoxLayout status_layout;

	QRadioButton active_btn;
	QRadioButton disable_btn;


	QPushButton ok_btn;
	QPushButton cancel_btn;
	QPushButton set_btn;
	QObject *mp_parent;

public:
	SettingDlg(QObject *parent = NULL);
	void set_dic_item();
	virtual void closeEvent(QCloseEvent *event);
	void setting_show();
	void set_setting_data();

private slots:
	void ok_clicked(bool checked = false);
	void cancel_clicked(bool checked = false);
	void set_clicked(bool checked = false);
};

class RightMenu : public QMenu
{
Q_OBJECT
public:
	explicit RightMenu(QWidget * parent = 0);
	void make_tray_menu();
	void set_dic_data();

	char **get_dic_str_list();
	char **get_dic_short_list();
	
	~RightMenu();
private:
	QAction info_act;
	QAction exit_act;
	QAction setting_act;
	QIcon info_icon;
	QIcon exit_icon;
	QIcon setting_icon;

	char mp_dic_str_list[10][20];
	char mp_dic_short_str_list[10][10];
private slots:
	void exit_triggered();
	void info_triggered();
	void setting_triggered();
};




class QtExam2 : public QMainWindow
{
Q_OBJECT
private:
	Ui::QtExam2Class ui;
	QNetworkAccessManager *manager;
	QString html_str;
	QString find_reg_pattern;
	QStringList find_reg_str_list;

	QClipboard *clip_board;
	QSystemTrayIcon tray;

	QString url_str;
	QString file_path;

	QIcon tray_icon;
	RightMenu *right_menu;

	InfoDlg info_widget;
	SettingDlg setting_widget;
	QSharedMemory shared_mem;

	int m_max_dic_count;
public:
	explicit QtExam2(QWidget *parent = 0);
	void make_voca_data_tree(int find_start_idx);
	void make_indexof_find_str();
	bool Send_Http_requset(QString parm_url);
	int http_regexp_parse();

	void set_reg_pattern(char *parm_find_regexp);
	void set_url_link(char *parm_url_link);

	void req_send_tray_message();

	void make_tray_icon();
	void start_tray_msg();

	void start_sys_tray();

	void show_info_widget();
	void show_setting_widget();

	void set_dic_info();
	~QtExam2();
	char mp_dic_name_str[10][25];
	char mp_dic_short_name_str[10][10];

	int get_default_local_idx();
	bool is_overlapped_execute();

private slots:
	void replyFinished(QNetworkReply*);
	void changedSlot(QClipboard::Mode);
};


#endif // QTEXAM2_H
