#include "qtexam2.h"


SettingDlg::SettingDlg(QObject *parent) : ok_btn("ok"), cancel_btn("cancel"), set_btn("set"), active_btn("active"), disable_btn("disable"), mp_parent(parent)
{

	dic_label.setText("Choose Dictionary");
	status_label.setText("Status(eg: Clipboard Captured!");

	main_layout.addWidget(&dic_label);
	main_layout.addWidget(&listbox);
	main_layout.addWidget(&status_label);
	
	status_layout.addWidget(&active_btn);
	status_layout.addWidget(&disable_btn);

	btn_layout.addWidget(&ok_btn);
	btn_layout.addWidget(&cancel_btn);
	btn_layout.addWidget(&set_btn);

	main_layout.addLayout(&status_layout);
	main_layout.addLayout(&btn_layout);
	setLayout(&main_layout);

	set_dic_item();

	connect(&ok_btn, SIGNAL(clicked(bool)), this, SLOT(ok_clicked(bool)));
	connect(&cancel_btn, SIGNAL(clicked(bool)), this, SLOT(cancel_clicked(bool)));
	connect(&set_btn, SIGNAL(clicked(bool)), this, SLOT(set_clicked(bool)));
	
}


void SettingDlg::closeEvent(QCloseEvent *event){
	qDebug() << "closeEvent";
	event->ignore();
	hide();
}

void SettingDlg::setting_show()
{
	listbox.item(g_sel_word_idx)->setSelected(true);
	if (g_sel_active == 1) active_btn.setChecked(true);
	else disable_btn.setChecked(true);
	show();
}

//http://www.wordreference.com/tools/Chrome-search-shortcut.aspx
void SettingDlg::set_dic_item()
{
	for (int i = 0; i < g_dic_max_count; i++) {
		listbox.addItem(g_dic_name_str[i]);
	}
}

void SettingDlg::set_setting_data()
{
	int sel_idx = g_sel_word_idx;
	bool is_sel_active = g_sel_active;

	for (int i = 0; i < g_dic_max_count; i++) {
		if (listbox.item(i)->isSelected() == 1)
			sel_idx = i;
	}

	if (active_btn.isChecked() == true) is_sel_active = 1;
	else is_sel_active = 0;
	
	g_sel_word_idx = sel_idx;
	g_sel_active = is_sel_active;
}

void SettingDlg::ok_clicked(bool checked)
{
	set_setting_data();
	hide();
}


void SettingDlg::cancel_clicked(bool checked)
{
	hide();
}


void SettingDlg::set_clicked(bool checked)
{
	set_setting_data();
}



InfoDlg::InfoDlg(QObject *parent)
{
	content_str = "Dic Tranlate Application ver0.1\n";
	content_str = "This Application is a program that shows the results by searching the contents of the clipboard in the dictionary\n";
	content_str += "Referenced by \'www.wordreference.com\'\n";
	content_str += "Developed : c1219abc@naver.com\n";
	
	info_edit.setStyleSheet("border:0px");
	info_edit.setText(content_str);
	info_edit.setDisabled(1);
	info_edit.setAlignment(Qt::AlignCenter);

	word_img_label.setPixmap(QPixmap(".\\Logo_wordreference.jpg"));
	
	main_layout.addWidget(&info_edit);
	main_layout.addWidget(&word_img_label);
	setLayout(&main_layout);

	setFixedSize(this->width()/2, this->height()/2);
}

void InfoDlg::closeEvent(QCloseEvent *event) {
	qDebug() << "closeEvent";
	event->ignore();
	hide();
}

QtExam2::QtExam2(QWidget *parent) : QMainWindow(parent), info_widget(this), setting_widget(this), shared_mem("Tran-Dic")
{
	ui.setupUi(this);


	clip_board = QApplication::clipboard();
	connect(clip_board, SIGNAL(changed(QClipboard::Mode)), this, SLOT(changedSlot(QClipboard::Mode)));

	make_tray_icon();
	start_sys_tray();
	tray.setToolTip("Capture clipboard Translate");
	
	right_menu = new RightMenu(this);
	tray.setContextMenu(right_menu);

	manager = new QNetworkAccessManager(this);
	connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));

	g_sel_word_idx = get_default_local_idx();
	//m_dic_short_str = g_dic_short_name_str[g_sel_word_idx];
	

}


int QtExam2::get_default_local_idx()
{
	QLocale local;
	int res;
	if (local.language() == QLocale::Russian) res = DIC_RU;
	else if (local.language() == QLocale::Polish) res = DIC_POL;
	else if (local.language() == QLocale::Romansh) res = DIC_ROM;
	else if (local.language() == QLocale::Czech) res = DIC_CZE;
	else if (local.language() == QLocale::Greek) res = DIC_GRE;
	else if (local.language() == QLocale::Turkish) res = DIC_TUR;
	else if (local.language() == QLocale::Chinese) res = DIC_CHI;
	else if (local.language() == QLocale::Japanese) res = DIC_JAP;
	else if (local.language() == QLocale::Korean) res = DIC_KOR;
	else if (local.language() == QLocale::Arabic) res = DIC_ARA;
	else res = DIC_ARA;
	return res;
}


void QtExam2::show_info_widget()
{
	info_widget.show();
}


void QtExam2::show_setting_widget()
{
	setting_widget.setting_show();
}

void QtExam2::set_dic_info()
{	
}


QtExam2::~QtExam2()
{
	if (manager != NULL) delete manager;
	if (right_menu != NULL) delete right_menu;
	
}


bool QtExam2::Send_Http_requset(QString parm_url)
{
	parm_url = parm_url.toLower();
	manager->get(QNetworkRequest(QUrl(parm_url)));

	return 0;
}


//https://regex101.com/
//reg exp : \>(.*)\<e
//using Qt std alogrithm with RegExp
//QString find_str = "<td class='ToWrd' >";
//<td class='ToWrd' >결코 ~하지 않다 <em class='POS2'>부</em><
//Regexp's parser has Two method(greedy, lazy)
int QtExam2::http_regexp_parse()
{
	int pos = 0;
	find_reg_str_list.clear();
	QRegExp reg_exp(find_reg_pattern);
	//use lazy regexp;
	reg_exp.setMinimal(true);

	while ((pos = reg_exp.indexIn(html_str, pos)) != -1) {
		find_reg_str_list.append(reg_exp.cap(1));
		pos += reg_exp.matchedLength();
	}

	req_send_tray_message();
	return find_reg_str_list.size();
}


void QtExam2::replyFinished(QNetworkReply *reply)
{
	if (reply->error() == QNetworkReply::NoError){
		html_str = reply->readAll();
		http_regexp_parse();
	}else {
		qDebug() << "has error";
	}

}


void QtExam2::set_reg_pattern(char *parm_find_regexp)
{
	if (parm_find_regexp == NULL) return;

	find_reg_pattern.clear();
	find_reg_pattern  = parm_find_regexp;
}

void QtExam2::set_url_link(char *parm_url_link)
{
	if (parm_url_link == NULL) return;

	url_str.clear();
	url_str = parm_url_link;
}

//old alorithm(No use)
void QtExam2::make_voca_data_tree(int find_start_idx)
{	
	QChar *cur_pos = html_str.data() + find_start_idx;
	if (find_start_idx > 0) {
		while (1) {
			if (*cur_pos == L'<' && *(cur_pos + 1) == L'/' && *(cur_pos + 2) == L't'){
				int a = 0;
				if (*(cur_pos + 3) == L'd') {
					//"</td>"
					qDebug() << "Search";
					cur_pos = cur_pos + strlen("</td>");
					continue;
				}
				else if (*(cur_pos + 3) == L'a') {
					int ab = 3;
					break;
				}
			}
		cur_pos++;
		}
	}
}


//less than old algorithm(No use)	
void QtExam2::make_indexof_find_str()
{
	int idx = 0;
	
	QStringList list;
	QString find_str = "<td class='ToWrd' >";
	QStringRef ref_str;

	idx = html_str.lastIndexOf("<table class='WRD' onclick");
	ref_str = html_str.midRef(idx);

	while (idx > 0) {
		idx = ref_str.indexOf(find_str);
		if (idx > 0) {
			qDebug() << ref_str.mid(idx, 100);
			//list.append(ref_str.split())
			ref_str = ref_str.mid(idx + 100);
		}
	}
}

void QtExam2::make_tray_icon()
{
	file_path = QDir::currentPath();
	char *icon_fn = "Dictionary-icon.png";

	file_path = file_path + "/" + icon_fn;
	tray_icon.addFile(file_path);
	tray.setIcon(tray_icon);
}


void QtExam2::start_sys_tray()
{
	tray.show();
	tray.showMessage("Translate Dictionary", "Started Program!",QSystemTrayIcon::Information, 100);
}


void QtExam2::changedSlot(QClipboard::Mode)
{
	if (g_sel_active == 0) return;

	if (QApplication::clipboard()->mimeData()->hasText())
	{
		qDebug() << "Msg";
		//정규식을 이옹하여, 띄어쓰기나, 특수문자 유무를 걸러 내야함.

		QRegExp reg("[#\&\\+\-%@=\/\\\:;,\.\'\"\^`~\_|\!\/\?\*$#<>()\[\]\{\}]");
		reg.setMinimal(1);
		int res = reg.indexIn(clip_board->text());

		if(res == -1) Send_Http_requset(url_str + g_dic_short_name_str[g_sel_word_idx] + '/' + clip_board->text());
		else tray.showMessage("Translate Dictionary", "ClipBoard Text has a Special Character", QSystemTrayIcon::Information, 100);
	}
}

void QtExam2::req_send_tray_message()
{
	//Make show Messate Data
	QString message;

	int size = find_reg_str_list.size();
	if (size > 0) {
		for (int i = 0; i < size; i++) {
			message = message + find_reg_str_list.at(i) + "\n";

			if (i > 3) break;
		}
		tray.showMessage(clip_board->text(), message);
	} else {
		tray.showMessage("Translate Dictionary", "Not Found");
	}
}

bool QtExam2::is_overlapped_execute()
{
	bool res;

	if (!shared_mem.isAttached()) {
		res = shared_mem.create(512, QSharedMemory::ReadWrite);
	}
	else {
		res = false;
	}
	return res;
}



RightMenu::RightMenu(QWidget * parent) : QMenu(parent), exit_act(this), info_act(this), setting_act(this)
{
	make_tray_menu();
	set_dic_data();

	connect(&info_act, SIGNAL(triggered()), this, SLOT(info_triggered()));
	connect(&exit_act, SIGNAL(triggered()), this, SLOT(exit_triggered()));
	connect(&setting_act, SIGNAL(triggered()), this, SLOT(setting_triggered()));
}

char **RightMenu::get_dic_str_list()
{
	return (char **)mp_dic_str_list;
}


char **RightMenu::get_dic_short_list()
{
	return NULL;
}

RightMenu::~RightMenu()
{
	qDebug() << "~RightMenu()";
}

void RightMenu::make_tray_menu()
{
	info_icon.addFile("information.png");
	exit_icon.addFile("exit.png");
	setting_icon.addFile("settings.png");


	info_act.setIcon(info_icon);
	info_act.setText("info");

	exit_act.setIcon(exit_icon);
	exit_act.setText("exit");

	setting_act.setIcon(setting_icon);
	setting_act.setText("settings");

	addAction(&setting_act);
	addAction(&info_act);
	addAction(&exit_act);
}

void RightMenu::set_dic_data()
{
}


void RightMenu::exit_triggered()
{
	QtExam2 *exam = (QtExam2 *)parent();
	exam->close();
}


void RightMenu::info_triggered()
{	
	qDebug() << "info_triggered()";
	QtExam2 *exam = (QtExam2 *)parent();
	exam->show_info_widget();
}


void RightMenu::setting_triggered()
{
	qDebug() << "setting_triggered()";
	QtExam2 *exam = (QtExam2 *)parent();
	exam->show_setting_widget();
}
