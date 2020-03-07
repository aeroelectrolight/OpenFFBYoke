/*
  Force Feedback Joystick
  USB HID descriptors for a force feedback joystick.
  Copyright 2012  Tero Loimuneva (tloimu [at] gmail [dot] com)
  Copyright 2016  Jaka Simonic (telesimke [at] gmail [dot] com)
  Copyright 2019  Hoan Tran (tranvanhoan206 [at] gmail [dot] com)
  MIT License.
  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.
  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

#ifndef FFBHANDLER_h
#define FFBHANDLER_h

#include <Arduino.h>
#include "HIDReportType.h"

class FfbReportHandler {
  public:
    FfbReportHandler();
    ~FfbReportHandler();
    // Effect management
    volatile uint8_t nextEID;  // FFP effect indexes starts from 1
    volatile TEffectState  gEffectStates[MAX_EFFECTS + 1];
    volatile uint8_t devicePaused;
    //variables for storing previous values
    volatile int32_t inertiaT = 0;
    volatile int16_t oldSpeed = 0;
    volatile int16_t oldAxisPosition = 0;
    volatile USB_FFBReport_PIDStatus_Input_Data_t pidState = {2, 30, 0};
    volatile USB_FFBReport_PIDBlockLoad_Feature_Data_t pidBlockLoad;
    volatile USB_FFBReport_PIDPool_Feature_Data_t pidPoolReport;
    volatile USB_FFBReport_DeviceGain_Output_Data_t deviceGain;

    //ffb state structures
    uint8_t GetNextFreeEffect(void);
    void StartEffect(uint8_t id);
    void StopEffect(uint8_t id);
    void StopAllEffects(void);
    void FreeEffect(uint8_t id);
    void FreeAllEffects(void);

    //handle output report
    void FfbHandle_EffectOperation(USB_FFBReport_EffectOperation_Output_Data_t* data);
    void FfbHandle_BlockFree(USB_FFBReport_BlockFree_Output_Data_t* data);
    void FfbHandle_DeviceControl(USB_FFBReport_DeviceControl_Output_Data_t* data);
    void FfbHandle_DeviceGain(USB_FFBReport_DeviceGain_Output_Data_t* data);
    void FfbHandle_SetCustomForceData(USB_FFBReport_SetCustomForceData_Output_Data_t* data);
    void FfbHandle_SetDownloadForceSample(USB_FFBReport_SetDownloadForceSample_Output_Data_t* data);
    void FfbHandle_SetCustomForce(USB_FFBReport_SetCustomForce_Output_Data_t* data);
    void FfbHandle_SetEffect(USB_FFBReport_SetEffect_Output_Data_t* data);
    void SetEnvelope(USB_FFBReport_SetEnvelope_Output_Data_t* data, volatile TEffectState* effect);
    void SetCondition(USB_FFBReport_SetCondition_Output_Data_t* data, volatile TEffectState* effect);
    void SetPeriodic(USB_FFBReport_SetPeriodic_Output_Data_t* data, volatile TEffectState* effect);
    void SetConstantForce(USB_FFBReport_SetConstantForce_Output_Data_t* data, volatile TEffectState* effect);
    void SetRampForce(USB_FFBReport_SetRampForce_Output_Data_t* data, volatile TEffectState* effect);

    // Handle incoming data from USB
    void FfbOnCreateNewEffect(USB_FFBReport_CreateNewEffect_Feature_Data_t* inData);
    void FfbOnUsbData(uint8_t* data, uint16_t len);
    uint8_t* FfbOnPIDPool();
    uint8_t* FfbOnPIDBlockLoad();
    uint8_t* FfbOnPIDStatus();


};

extern FfbReportHandler ffbReportHandler;

#endif
