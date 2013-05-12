/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : DA1.h
**     Project   : ProcessorExpert
**     Processor : MK60DN512ZVMD10
**     Component : DAC_LDD
**     Version   : Component 01.015, Driver 01.03, CPU db: 3.00.003
**     Compiler  : CodeWarrior ARM C Compiler
**     Date/Time : 2011-11-24, 16:34, # CodeGen: 1
**     Abstract  :
**         This component implements an internal D/A converter of the MCU.
**         It contains settings for converting various format of a values
**         to supported format of the D/A converter.
**
**     Settings  :
**          Component name                                 : DA1
**          D/A converter                                  : DAC0
**          Interrupt service/event                        : Enabled
**            D/A interrupt                                : INT_DAC0
**            D/A interrupt priority                       : 9
**          Output pin                                     : yes
**            D/A channel (pin)                            : DAC0_OUT
**            D/A channel (pin) signal                     : 
**          Init value                                     : 0
**          D/A resolution                                 : Autoselect
**          Data mode                                      : unsigned 16 bits, right justified
**          Low power mode                                 : Disabled
**          Voltage reference source                       : external
**          Data buffer                                    : Enabled
**            Hardware trigger                             : Disabled
**            Work mode                                    : Normal
**            Watermark                                    : level 4
**            Buffer size                                  : 16
**              Data register 0                            : 0
**              Data register 1                            : 0
**              Data register 2                            : 0
**              Data register 3                            : 0
**              Data register 4                            : 0
**              Data register 5                            : 0
**              Data register 6                            : 0
**              Data register 7                            : 0
**              Data register 8                            : 0
**              Data register 9                            : 0
**              Data register 10                           : 0
**              Data register 11                           : 0
**              Data register 12                           : 0
**              Data register 13                           : 0
**              Data register 14                           : 0
**              Data register 15                           : 0
**          DMA                                            : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : no
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnBufferWatermark                          : Enabled
**              OnBufferEnd                                : Enabled
**              OnBufferStart                              : Disabled
**              OnComplete                                 : Disabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**     Contents  :
**         Init                 - LDD_TDeviceData* DA1_Init(LDD_TUserData *UserDataPtr);
**         Deinit               - void DA1_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         Enable               - LDD_TError DA1_Enable(LDD_TDeviceData *DeviceDataPtr);
**         Disable              - LDD_TError DA1_Disable(LDD_TDeviceData *DeviceDataPtr);
**         SetEventMask         - LDD_TError DA1_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask...
**         GetEventMask         - LDD_TEventMask DA1_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
**         SetBuffer            - LDD_TError DA1_SetBuffer(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**         ForceSwTrigger       - LDD_TError DA1_ForceSwTrigger(LDD_TDeviceData *DeviceDataPtr);
**         SetBufferMode        - LDD_TError DA1_SetBufferMode(LDD_TDeviceData *DeviceDataPtr,...
**         SetBufferSize        - LDD_TError DA1_SetBufferSize(LDD_TDeviceData *DeviceDataPtr, uint8_t Size);
**         SetBufferWatermark   - LDD_TError DA1_SetBufferWatermark(LDD_TDeviceData *DeviceDataPtr,...
**         SetBufferReadPointer - LDD_TError DA1_SetBufferReadPointer(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**         GetBufferReadPointer - byte DA1_GetBufferReadPointer(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2011 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __DA1_H
#define __DA1_H

/* MODULE DA1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "Cpu.h"

#include "DAC_PDD.h"
#include "PE_LDD.h"

/*  This constant contains mask of all events generated by Processor Expert */
#define DA1_AVAILABLE_EVENTS_MASK (LDD_DAC_ON_BUFFER_START | LDD_DAC_ON_BUFFER_WATERMARK | LDD_DAC_ON_BUFFER_END)
/* This constant contains minimal buffer size available on selected device. */
#define DA1_BUFFER_MIN_SIZE 0x01U
/* This constant contains maximal buffer size available on selected device. */
#define DA1_BUFFER_MAX_SIZE 0x10U

LDD_TDeviceData* DA1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  DA1_Init (component DAC_LDD)
**
**     Description :
**         Initializes the device according to design-time
**         configuration properties. Allocates memory for the device
**         data structure. 
**         If the <Enable in init. code> is set to "yes" then the
**         device is also enabled (see the description of the Enable
**         method).
**         This method can be called only once. Before the second call
**         of Init the Deinit method must be called first. If DMA
**         service is enabled this method also initializes inherited
**         DMA Transfer component.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an events or callback parameter.
**     Returns     :
**         ---             - Device data structure pointer.
** ===================================================================
*/

void DA1_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DA1_Deinit (component DAC_LDD)
**
**     Description :
**         Disables the device and frees the device data structure
**         memory. If DMA service is enabled this method also
**         deinitializes inherited DMA Transfer component.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/

LDD_TError DA1_Enable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DA1_Enable (component DAC_LDD)
**
**     Description :
**         Enables DAC device. If possible, this method switches on
**         digital-to-analog converter device, voltage reference, etc.
**         This method is intended to be used together with Disable
**         method to temporary switch On/Off the device after the
**         device is initialized.
**         This method is required if the <Enable in init. code>
**         property is set to "no" value.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
** ===================================================================
*/

LDD_TError DA1_Disable(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DA1_Disable (component DAC_LDD)
**
**     Description :
**         Disables the DAC device. If possible, this method switches
**         off digital-to-analog converter device, voltage reference,
**         etc. When the device is disabled, some component methods
**         should not be called. If so, error ERR_DISABLED is reported.
**         This method is intended to be used together with Enable
**         method to temporary switch On/Off the device after the
**         device is initialized.
**         This method is not required. The Deinit method can be used
**         to switch off and uninstall the device.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
** ===================================================================
*/

LDD_TError DA1_SetEventMask(LDD_TDeviceData *DeviceDataPtr, LDD_TEventMask EventMask);
/*
** ===================================================================
**     Method      :  DA1_SetEventMask (component DAC_LDD)
**
**     Description :
**         Enables/disables event(s). This method is available if the
**         <Interrupt service/event> property is enabled and at least
**         one event is enabled. Pair method to GetEventMask. If DMA
**         service is enabled this method is maintaining DMA Transfer
**         events.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         EventMask       - Mask of events to enable.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_PARAM_MASK - Invalid event mask
**                           parameter.
** ===================================================================
*/

LDD_TEventMask DA1_GetEventMask(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DA1_GetEventMask (component DAC_LDD)
**
**     Description :
**         Returns current events mask. This method is available if the
**         <Interrupt service/event> property is enabled and at least
**         one event is enabled. Pair method to SetEventMask. If DMA
**         service is enabled this method is maintaining DMA Transfer
**         events.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Current EventMask.
** ===================================================================
*/

LDD_TError DA1_SetBuffer(LDD_TDeviceData *DeviceDataPtr, LDD_TData *DataArrayPtr, uint8_t DataArrayLength, uint8_t FirstRegisterIndex);
/*
** ===================================================================
**     Method      :  DA1_SetBuffer (component DAC_LDD)
**
**     Description :
**         Writes an array of data words to the data buffer registers.
**         Array is defined by pointer to start address and by it's
**         length. First written data buffer register is defined by
**         index.
**         If the length of array exceeds number of registers between
**         the first written register and the last one at the end of
**         the buffer then an ERR_PARAM_RANGE is returned and no data
**         are written. It is possible to write all register available
**         in hardware - no checking for current upper limit value of
**         buffer is done.
**         DataArrayPtr has fixed data type regardless of current
**         hardware or design time configuration and must be always
**         used. Real type of user data is specified in <Data mode>
**         property.
**         If the DMA service is enabled then this methods can be used
**         to prepare DMA transfer via channel handled by DMA Transfer
**         inherited component. 
**         _/Note: This method is available only if DAC device is
**         supporting data buffer and Data buffer is enabled./_
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * DataArrayPtr    - Pointer to array
**                           containing user data.
**         DataArrayLength - Length of user
**                           data array which should be written to data
**                           buffer.
**         FirstRegisterIndex - Index of
**                           first written data buffer register.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_PARAM_RANGE - Index of last written
**                           buffer register would be out of buffer
**                           range.
** ===================================================================
*/

LDD_TError DA1_ForceSwTrigger(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DA1_ForceSwTrigger (component DAC_LDD)
**
**     Description :
**         Triggers data buffer read pointer if software trigger is
**         selected.
**         _/Note: This method is available only if DAC device is
**         supporting data buffer and Data buffer is enabled with
**         Hardware trigger disabled./_
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
** ===================================================================
*/

LDD_TError DA1_SetBufferMode(LDD_TDeviceData *DeviceDataPtr, LDD_DAC_TBufferMode Mode);
/*
** ===================================================================
**     Method      :  DA1_SetBufferMode (component DAC_LDD)
**
**     Description :
**         Selects buffer work mode. 
**         _/Note: This method is available only if DAC device is
**         supporting data buffer and Data buffer is enabled./_
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Mode            - Buffer work mode.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_PARAM_MODE - Invalid mode parameter.
** ===================================================================
*/

LDD_TError DA1_SetBufferSize(LDD_TDeviceData *DeviceDataPtr, uint8_t Size);
/*
** ===================================================================
**     Method      :  DA1_SetBufferSize (component DAC_LDD)
**
**     Description :
**         Sets data buffer size. If requested buffer size exceeds
**         hardware capacity then ERR_PARAM_SIZE is returned.
**         _/Note: This method is available only if DAC device is
**         supporting data buffer and Data buffer is enabled./_
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Size            - Number of data buffer registers.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_PARAM_SIZE - Invalid size parameter.
** ===================================================================
*/

LDD_TError DA1_SetBufferWatermark(LDD_TDeviceData *DeviceDataPtr, LDD_DAC_TBufferWatermark WatermarkValue);
/*
** ===================================================================
**     Method      :  DA1_SetBufferWatermark (component DAC_LDD)
**
**     Description :
**         Selects watermark words number. If requested watermark value
**         is not available then ERR_PARAM_VALUE is returned.
**         _/Note: This method is available only if DAC device is
**         supporting data buffer and Data buffer is enabled./_
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         WatermarkValue  - Words number between
**                           the read pointer and upper address.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_PARAM_VALUE - Invalid value parameter.
** ===================================================================
*/

LDD_TError DA1_SetBufferReadPointer(LDD_TDeviceData *DeviceDataPtr, uint8_t PointerValue);
/*
** ===================================================================
**     Method      :  DA1_SetBufferReadPointer (component DAC_LDD)
**
**     Description :
**         Sets the data buffer read pointer value. If requested
**         pointer value is greater than buffer size defined by buffer
**         upper limit value then ERR_PARAM_VALUE is returned.
**         _/Note: This method is available only if DAC device is
**         supporting data buffer and Data buffer is enabled./_
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         PointerValue    - New read pointer value.
**     Returns     :
**         ---             - Error code, possible codes:
**                           - ERR_OK - OK.
**                           - ERR_SPEED - This device does not work in
**                           the active clock configuration.
**                           - ERR_DISABLED - Component or device is
**                           disabled.
**                           - ERR_PARAM_VALUE - Invalid value parameter.
** ===================================================================
*/

uint8_t DA1_GetBufferReadPointer(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  DA1_GetBufferReadPointer (component DAC_LDD)
**
**     Description :
**         Returns the data buffer read pointer value.
**         _/Note: This method is available only if DAC device is
**         supporting data buffer and Data buffer is enabled./_
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Buffer read pointer value.
** ===================================================================
*/

/* {MQX RTOS Adapter} ISR function prototype */
void DA1_BufferInterrupt(LDD_RTOS_TISRParameter _isrParameter);
/*
** ===================================================================
**     Method      :  DA1_BufferInterrupt (component DAC_LDD)
**
**     Description :
**         DAC Buffer interrupt handler.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void DA1_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration);
/*
** ===================================================================
**     Method      :  DA1_SetClockConfiguration (component DAC_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END DA1. */

#endif
/* ifndef __DA1_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 5.2 [04.49]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
