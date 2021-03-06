//
// Created by pikachu on 17-8-18.
//

#ifndef SHADOWSOCKS_CLIENT_UPDATESERVICE_H
#define SHADOWSOCKS_CLIENT_UPDATESERVICE_H

#include "common/common.h"

/**
 * 负责处理更新方面的事情
 */
class UpdateService : public QObject {
Q_OBJECT
public:
    explicit UpdateService(QObject *parent) : QObject(parent) {}

    /**
     * 检查更新
     */
    virtual void checkUpdate()= 0;

    /**
     * 启动时是否检查更新
     * @param b
     */
    virtual void setCheckForUpdatesAtStartup(bool b)= 0;

    virtual bool isCheckForUpdatesAtStartup()= 0;
    /**
     * 是否检查测试版更新
     * @param b
     */
    virtual void setCheckPrereleaseVersion(bool b)= 0;

    virtual bool isCheckPrereleaseVersion()= 0;
    /**
     * 从GFWList更新本地pac文件
     */
    virtual void updateLocalPacFromGFWList()= 0;

signals:

    void finishUpdate(const QString &title, const QString &msg,
                      QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int msecs = 10000);
};

#endif //SHADOWSOCKS_CLIENT_UPDATESERVICE_H
