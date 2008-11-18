//
// C++ Interface: Global
//
// Description:
//
//
// Author: hooey <hephooey@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef QTERMGLOBAL_H
#define QTERMGLOBAL_H

#include "qtermparam.h"

#include <QtCore/QMutex>
#include <QtCore/QString>

namespace QTerm
{
class Config;
class Global
{
public:
    enum Codec {
        GBK,
        Big5
    };
    enum Status {
        INIT_OK,
        INIT_ERROR
    };
    struct Pref {
        Codec  nXIM;
        int  nWordWrap;
        bool bWheel;
        bool bWarn;
        bool bBlinkTab;
        QString strHttp;
        int  nBeep;
        QString strWave;
        QString strPlayer;
        bool bUrl;
        bool bAutoCopy;
        bool bAA;
        bool bTray;
        bool bClearPool;
        QString strZmPath;
        QString strPoolPath;
        QString strImageViewer;
    };
    static Global * instance();
    Config * fileCfg();
    Config * addrCfg();
    const QString & pathLib();
    const QString & pathPic();
    const QString & pathCfg();
    void clearDir(const QString & path);
    QStringList loadNameList();
    bool loadAddress(int n, Param & param);
    void saveAddress(int n, const Param & param);
    QString getOpenFileName(const QString & filter, QWidget * widget);
    QString getSaveFileName(const QString & filename, QWidget * widget);
    bool isOK();
    Pref m_pref;
    void loadPrefence();
    enum Position {Hide, Left, Right};
    bool isBossColor() const;
    const QString & escapeString() const;
    Codec clipCodec() const;
    bool showStatusBar() const;
    Position scrollPosition() const;
    bool isFullScreen() const;
    bool showSwitchBar() const;

    void setClipCodec(Codec codecId);
    void setEscapeString(const QString & escapeString);
    void setScrollPosition(Position position);
    void setStatusBar(bool isShow); //Better name?
    void setBossColor(bool isBossColor);
    void setFullScreen(bool isFullscreen);
    void setSwitchBar(bool isShow);

private:
    Global();
    static Global* m_Instance;
    bool iniWorkingDir(QString param);
    bool iniSettings();
    bool isPathExist(const QString & path);
    bool createLocalFile(const QString & dst, const QString & src);
    QString m_fileCfg;
    QString m_addrCfg;
    QString m_pathLib;
    QString m_pathPic;
    QString m_pathCfg;
    Config * m_config;
    Config * m_address;
    Status m_status;
    bool m_bossColor;
    QString m_escape;
    Codec m_clipCodec;
    bool m_statusBar;
    Position m_scrollPos;
    bool m_fullScreen;
    bool m_switchBar;

};

} // namespace QTerm
#endif // GLOBAL_H
