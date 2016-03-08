#include "DictionaryReqManager.h"



DictionaryReqManager::DictionaryReqManager(QObject *parent) : QObject(parent)
{
	//mp_manager = NULL;
	m_url_str = NULL;
	m_find_word = NULL;	

}


DictionaryReqManager::DictionaryReqManager(QObject *parent, char *parm_url)
{
	int len = 0;
	if (parm_url != NULL) {
		len = strlen(parm_url);
		m_url_str = new char[len + 1];
		strncpy(m_url_str, parm_url, len);
		m_url_str[len] = 0;
		DictionaryReqManager(parent);
	}
}


DictionaryReqManager::DictionaryReqManager(QObject *parent, char *parm_url, char *parm_find_word)
{
	int len = 0;
	if (parm_find_word != NULL) {
		len = strlen(parm_find_word);
		m_find_word = new char[len + 1];
		strncpy(m_find_word, parm_find_word, len);
		m_find_word[len] = 0;
		DictionaryReqManager(parent, parm_url);
	}
}


void DictionaryReqManager::request_url(char *parm_req_url)
{
	mp_manager = new QNetworkAccessManager(this);

	QNetworkReply *reply = mp_manager->get(QNetworkRequest(QUrl(parm_req_url)));
	connect(reply, SIGNAL(finished()), this, SLOT(slotFinished));
	}

void DictionaryReqManager::slotFinished()
{
	int a = 0;
}


void DictionaryReqManager::replyFinished(QNetworkReply *reply)
{
	if (reply->error() == QNetworkReply::NoError) {
		//html_str = reply->readAll();
		//http_regexp_parse();
		qDebug() << "No error";
	}
	else {
		qDebug() << "has error";
	}
}



DictionaryReqManager::~DictionaryReqManager()
{
	//if (mp_manager != NULL) delete mp_manager;
	if (m_url_str != NULL) delete[] m_url_str;
	if (m_find_word != NULL) delete[] m_find_word;
}


