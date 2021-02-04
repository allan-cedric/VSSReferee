#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QString>
#include <QFile>

#include <src/utils/text/text.h>

class Constants
{
public:
    Constants(QString fileName);

    // Entities constants getters
    int threadFrequency();

    // Referee constants getters
    QString refereeAddress();
    quint16 refereePort();
    float transitionTime();
    float ballRadius();
    float robotLength();
    float halfTime();
    float ballMinSpeedForStuck();
    float stuckedBallTime();

    // Vision constants getters
    QString visionAddress();
    quint16 visionPort();

    // Replacer constants getters

    // Teams constants getters
    int qtPlayers();
    QString blueTeamName();
    QString yellowTeamName();
    bool blueIsLeftSide();
    void swapSides();

protected:
    QVariantMap documentMap() { return _documentMap; }

private:
    // Internal file management
    QString _fileName;
    QString _fileBuffer;
    QFile _file;

    // Internal json parse vars
    QJsonDocument _document;
    QVariantMap _documentMap;

    // Entities constants
    int _threadFrequency;
    void readEntityConstants();

    // Referee
    QString _refereeAddress;
    quint16 _refereePort;
    float _transitionTime;
    float _ballRadius;
    float _robotLength;
    float _halfTime;
    float _ballMinSpeedForStuck;
    float _stuckedBallTime;
    void readRefereeConstants();

    // Vision constants
    QString _visionAddress;
    quint16 _visionPort;
    void readVisionConstants();

    // Replacer constants
    void readReplacerConstants();

    // Teams constants
    int _qtPlayers;
    QString _blueTeamName;
    QString _yellowTeamName;
    bool _blueIsLeftSide;
    void readTeamConstants();
};

#endif // CONSTANTS_H