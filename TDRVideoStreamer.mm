//
//  TDRVideoStreamer.m
//  QGroundControl
//
//  Created by Lauren on 12/19/18.
//

#import <Foundation/Foundation.h>

#include <QUdpSocket>
#include "TDRVideoStreamer.h"
#include "TDRVideoReceiver.h"

#include "TaisyncHandler.h"

#define TDR_VIDEO_UDP_PORT      5601

@interface TDRVideoStreamer ()

//private:
//    QUdpSocket*     _udpVideoSocket     = nullptr;
//};
@end

@implementation TDRVideoStreamer

QUdpSocket*     _udpVideoSocket     = nullptr;
TDRVideoReceiver*   _tdrVideo       = nullptr;
QTcpSocket*     _tcpVideoSocket     = nullptr;

- (instancetype)init {
    if (self = [super init]) {

    }
    return self;
}


- (void) writeVideoData:(NSData *) h264Data {
//    if (_tdrVideo == nil) {
//        QObject* qo = new QObject();
//        _tdrVideo = new TDRVideoReceiver(qo);
//        _tdrVideo->start();
//    }
    
//    if (_udpVideoSocket == nil) {
//        _udpVideoSocket = new QUdpSocket();
//        //emit connected();
//    }
    
    if (_tcpVideoSocket == nil) {
        _tcpVideoSocket = new QTcpSocket();
        QHostAddress hostAddress = QHostAddress(QString("127.0.0.1"));
        _tcpVideoSocket->connectToHost(hostAddress, TDR_VIDEO_UDP_PORT);
        _tcpVideoSocket->waitForConnected();
        //emit connected();
    }
    if (_tcpVideoSocket->state() != QAbstractSocket::ConnectedState) {
        NSLog(@"writeVideoData, _tcpVideoSocket->state() error");
    }
    
    
    /*
    // we first need to get the length of our hexstring
    // data.lenght returns the lenght in bytes, so we *2 to get as hexstring
    NSUInteger capacity = h264Data.length * 2;
    // Create a new NSMutableString with the correct lenght
    NSMutableString *mutableString = [NSMutableString stringWithCapacity:capacity];
    // get the bytes of data to be able to loop through it
    const unsigned char *buf = (const unsigned char*) [h264Data bytes];

    NSInteger t;
    for (t=0; t<h264Data.length; ++t) {
//        NSLog(@"GLYPH at t : %c", buf[t]);
//        NSLog(@"DECIMAL at t  : %lu", (NSUInteger)buf[t]);
        // "%02X" will append a 0 if the value is less than 2 digits (i.e. 4 becomes 04)
        [mutableString appendFormat:@"%02X", (NSUInteger)buf[t]];
    }
//    NSLog(@"Hexstring: %@", mutableString);
    // save as NSString
    NSString * dataString =mutableString;


//    NSString *dataString = [[NSString alloc] initWithData:h264Data encoding: NSUTF8StringEncoding];
    //NSString *dataString = [[NSString alloc] initWithBytes:h264Data length:[h264Data length] encoding: NSUTF8StringEncoding];
    const char *dataChars = [dataString UTF8String];
    size_t size = strlen(dataChars);
    int intLen = (size <= INT_MAX) ? (int)((ssize_t)size) : -1;
    */
    
//    const char *dataBytes = (char *)[h264Data bytes];
//    int len = h264Data.length;
//    QByteArray bytesIn = QByteArray(dataBytes, len);
//    if (_udpVideoSocket != nil && bytesIn != nil) {
//        NSLog(@"TDRVideoStreamer writeVideoData");
//        //QHostAddress hostAddress = QHostAddress(QString("192.168.42.1"));
//        QHostAddress hostAddress = QHostAddress(QString("127.0.0.1"));
//        _udpVideoSocket->writeDatagram(bytesIn, hostAddress, TDR_VIDEO_UDP_PORT);
//        //_udpVideoSocket->writeDatagram(bytesIn, QHostAddress::LocalHost, TAISYNC_VIDEO_UDP_PORT);
//    }
    
    const char *dataBytes = (char *)[h264Data bytes];
    int len = h264Data.length;
    QByteArray bytesIn = QByteArray(dataBytes, len);
    if (_tcpVideoSocket != nil && bytesIn != nil) {
        NSLog(@"TDRVideoStreamer _tcpVideoSocket writeVideoData");
        //QHostAddress hostAddress = QHostAddress(QString("192.168.42.1"));
        QHostAddress hostAddress = QHostAddress(QString("127.0.0.1"));
        _tcpVideoSocket->write(bytesIn);
        //_tcpVideoSocket->writeDatagram(bytesIn, hostAddress, TDR_VIDEO_UDP_PORT);
        //_udpVideoSocket->writeDatagram(bytesIn, QHostAddress::LocalHost, TAISYNC_VIDEO_UDP_PORT);
    }
}

@end
