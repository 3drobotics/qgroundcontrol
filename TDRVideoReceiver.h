//
//  TDRVideoReceiver.h
//  QGroundControl
//
//  Created by Lauren on 12/21/18.
//

#pragma once

#include "TaisyncHandler.h"
#include <QUdpSocket>

Q_DECLARE_LOGGING_CATEGORY(TaisyncVideoReceiverLog)

class TDRVideoReceiver : public TaisyncHandler
{
    Q_OBJECT
public:
    
    explicit TDRVideoReceiver       (QObject* parent = nullptr);
    bool start                          () override;
    void close                          () override;
    
    private slots:
    void    _readBytes                  () override;
    //void    _writeBytes             (QByteArray bytesIn);
    
private:
    QUdpSocket*     _udpVideoSocket     = nullptr;
};
