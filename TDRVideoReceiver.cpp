//
//  TDRVideoReceiver.cpp
//  QGroundControl
//
//  Created by Lauren on 12/21/18.
//

#include "TDRVideoReceiver.h"

#define TDR_VIDEO_UDP_PORT      5601

//QGC_LOGGING_CATEGORY(TaisyncVideoReceiverLog, "TaisyncVideoReceiverLog")

//-----------------------------------------------------------------------------
TDRVideoReceiver::TDRVideoReceiver(QObject* parent)
: TaisyncHandler(parent)
{
}

//-----------------------------------------------------------------------------
void
TDRVideoReceiver::close()
{
    TaisyncHandler::close();
    //qCDebug(TaisyncVideoReceiverLog) << "Close Taisync Video Receiver";
    if(_udpVideoSocket) {
        _udpVideoSocket->close();
        _udpVideoSocket->deleteLater();
        _udpVideoSocket = nullptr;
    }
}

//-----------------------------------------------------------------------------
bool
TDRVideoReceiver::start()
{
    //qCDebug(TaisyncVideoReceiverLog) << "Start Taisync Video Receiver";
    _udpVideoSocket = new QUdpSocket(this);
    return _start(TDR_VIDEO_UDP_PORT);
}

//-----------------------------------------------------------------------------
void
TDRVideoReceiver::_readBytes()
{
    QByteArray bytesIn = _tcpSocket->read(_tcpSocket->bytesAvailable());
    QHostAddress hostAddress = QHostAddress(QString("127.0.0.1"));
    _udpVideoSocket->writeDatagram(bytesIn, hostAddress, TDR_VIDEO_UDP_PORT);
    //_udpVideoSocket->writeDatagram(bytesIn, QHostAddress::LocalHost, TDR_VIDEO_UDP_PORT);
}

//-----------------------------------------------------------------------------
//void
//TDRVideoReceiver::_writeBytes(QByteArray bytesIn)
//{
//    //QByteArray bytesIn = _tcpSocket->read(_tcpSocket->bytesAvailable());
//    _udpVideoSocket->writeDatagram(bytesIn, QHostAddress::LocalHost, TDR_VIDEO_UDP_PORT);
//}
