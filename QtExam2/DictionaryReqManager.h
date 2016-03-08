#pragma once

#include <string.h>

#include <qobject.h>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkrequest.h>
#include <QtNetwork/qnetworkreply.h>

class DictionaryReqManager : public QObject
{
Q_OBJECT
private:
	QNetworkAccessManager *mp_manager;
	//QNetworkReply *reply;
	char *m_url_str;
	char *m_find_word;
public:
	DictionaryReqManager(QObject *parent = 0);
	DictionaryReqManager(QObject *parent, char *parm_url);
	DictionaryReqManager(QObject *parent, char *parm_url, char *parm_find_word);
	~DictionaryReqManager();
	void request_url(char *parm_req_url = NULL);
public slots:
	void replyFinished(QNetworkReply*);
	void slotFinished();
};

