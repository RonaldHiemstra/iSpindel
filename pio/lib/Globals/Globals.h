/**************************************************************

    "iSpindel"
    All rights reserverd by S.Lang <universam@web.de>

 **************************************************************/


#ifndef _GLOBALS_H
#define _GLOBALS_H

#pragma once
//#define USE_DMP false
#include <Arduino.h>
#include <Hash.h>

// #ifdef USE_DMP
// #include "MPU6050_6Axis_MotionApps20.h"
// // #include "I2Cdev.h"
// #else
#include <Ticker.h>

#include <I2Cdev.h>
#include <MPU6050.h>
extern Ticker flasher;
// #include <stdint.h>

// defines go here
#define FIRMWAREVERSION "5.5.4"


#define API_FHEM true
#define API_UBIDOTS true
#define API_GENERIC true
#define API_TCONTROL true

#ifndef DEBUG
#define DEBUG 1 // uncomment this line to enable serial diagnostic messages
#endif
#define PORTALTIMEOUT 300

#define ADCDIVISOR 191.8
#define ONE_WIRE_BUS D6  // DS18B20 on ESP pin12
#define RESOLUTION 12 // 12bit resolution == 750ms update rate
#define OWinterval (800 / (1 << (12 - RESOLUTION))) 
#define CFGFILE "/config.json"
#define TKIDSIZE 35
#define MEDIANROUNDS 7
#define ACCINTERVAL 200
#define MEDIANAVRG 3

#define CBP_ENDPOINT "/api/hydrometer/v1/data"

#define DTUbiDots 0
#define DTThingspeak 1
#define DTCraftbeepPi 2
#define DTHTTP 3
#define DTTcontrol 4
#define DTFHEM  5
#define DTTCP  6
#define DTiSPINDELde 7

// Number of seconds after reset during which a 
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 1
// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

#define WIFIENADDR 1
#define RTCVALIDFLAG 0xCAFEBABE

// sleep management
#define RTCSLEEPADDR 5
#define MAXSLEEPTIME 3600 //TODO
#define EMERGENCYSLEEP (my_sleeptime*3 < MAXSLEEPTIME ? MAXSLEEPTIME : my_sleeptime*3)
#define LOWBATT 3.3

#define UNINIT 0

extern int16_t ax, ay, az;
extern float Volt, Temperatur, Tilt, Gravity;
extern int16_t my_aX, my_aY, my_aZ;

extern MPU6050_Base accelgyro;
extern bool saveConfig();

#endif