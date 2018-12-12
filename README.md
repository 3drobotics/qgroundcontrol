# QGroundControl Ground Control Station

[![Releases](https://img.shields.io/github/release/mavlink/QGroundControl.svg)](https://github.com/mavlink/QGroundControl/releases)
[![Travis Build Status](https://travis-ci.org/mavlink/qgroundcontrol.svg?branch=master)](https://travis-ci.org/mavlink/qgroundcontrol)
[![Appveyor Build Status](https://ci.appveyor.com/api/projects/status/crxcm4qayejuvh6c/branch/master?svg=true)](https://ci.appveyor.com/project/mavlink/qgroundcontrol)

[![Gitter](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/mavlink/qgroundcontrol?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

*Development Setup*
1. Create QGC folder
2. Clone Dronecode QGroundControl repo: git clone https://github.com/mavlink/qgroundcontrol.git --recursive
3. cd qgroundcontrol/
4. git submodule update
5. Open qgroundcontrol.pro, this will launch Qt Creator
6. Select the Qt for iOS project, Build item
7. Build it, Hammer button on bottom left
8. In Finder, open the "build-qgroundcontrol-Qt_x_yy_zz_for_iOS-Debug" folder
9. Select QGroundControl.xcodeproj to open up the project in Xcode
10. Build and run the app

*Camera and Video*
https://github.com/mavlink/qgroundcontrol/blob/master/src/VideoStreaming/README.md

*Strip Frameworks*
This build requires the strip-frameworks.sh file to be placed in the AFNetworking.framework folder
* bash "${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/AFNetworking.framework/strip-frameworks.sh"

*App Settings For Yuneec ST10C and Mantis RC*
*MFi Setup Comm: Add Comm Link for listening port = 14540
* Video streaming: Settings>General>Video Source = RTSP, RTSP URL = rtsp://192.168.42.1/live, Aspect Ratio=1.5

*QGroundControl* (QGC) is an intuitive and powerful ground control station (GCS) for UAVs.

The primary goal of QGC is ease of use for both first time and professional users. 
It provides full flight control and mission planning for any MAVLink enabled drone, and vehicle setup for both PX4 and ArduPilot powered UAVs. Instructions for *using QGroundControl* are provided in the [User Manual](https://docs.qgroundcontrol.com/en/) (you may not need them because the UI is very intuitive!)

All the code is open-source, so you can contribute and evolve it as you want. 
The [Developer Guide](https://dev.qgroundcontrol.com/en/) explains how to [build](https://dev.qgroundcontrol.com/en/getting_started/) and extend QGC.


Key Links: 
* [Website](http://qgroundcontrol.com) (qgroundcontrol.com)
* [User Manual](https://docs.qgroundcontrol.com/en/)
* [Developer Guide](https://dev.qgroundcontrol.com/en/)
* [Discussion/Support](https://docs.qgroundcontrol.com/en/Support/Support.html)
* [Contributing](https://dev.qgroundcontrol.com/en/contribute/)
* [License](https://github.com/mavlink/qgroundcontrol/blob/master/COPYING.md)
