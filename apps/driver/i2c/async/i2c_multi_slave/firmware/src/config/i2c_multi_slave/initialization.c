/*******************************************************************************
  System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "configuration.h"
#include "definitions.h"
#include "device.h"


// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************
#pragma config SECURITY_BIT = CLEAR
#pragma config BOOT_MODE = 0x3
#pragma config PLANE_SELECTION = CLEAR
#pragma config ERASE_FUNCTION_LOCK = 0x0




// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
/* Following MISRA-C rules are deviated in the below code block */
/* MISRA C-2012 Rule 7.2 - Deviation record ID - H3_MISRAC_2012_R_7_2_DR_1 */
/* MISRA C-2012 Rule 11.1 - Deviation record ID - H3_MISRAC_2012_R_11_1_DR_1 */
/* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
/* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */
// <editor-fold defaultstate="collapsed" desc="DRV_I2C Instance 0 Initialization Data">

/* I2C Client Objects Pool */
static DRV_I2C_CLIENT_OBJ drvI2C0ClientObjPool[DRV_I2C_CLIENTS_NUMBER_IDX0];

/* I2C Transfer Objects Pool */
static DRV_I2C_TRANSFER_OBJ drvI2C0TransferObj[DRV_I2C_QUEUE_SIZE_IDX0];

/* I2C PLib Interface Initialization */
static const DRV_I2C_PLIB_INTERFACE drvI2C0PLibAPI = {

    /* I2C PLib Transfer Read Add function */
    .read_t = (DRV_I2C_PLIB_READ)FLEXCOM3_TWI_Read,

    /* I2C PLib Transfer Write Add function */
    .write_t = (DRV_I2C_PLIB_WRITE)FLEXCOM3_TWI_Write,


    /* I2C PLib Transfer Write Read Add function */
    .writeRead = (DRV_I2C_PLIB_WRITE_READ)FLEXCOM3_TWI_WriteRead,

    /*I2C PLib Transfer Abort function */
    .transferAbort = (DRV_I2C_PLIB_TRANSFER_ABORT)FLEXCOM3_TWI_TransferAbort,

    /* I2C PLib Transfer Status function */
    .errorGet = (DRV_I2C_PLIB_ERROR_GET)FLEXCOM3_TWI_ErrorGet,

    /* I2C PLib Transfer Setup function */
    .transferSetup = (DRV_I2C_PLIB_TRANSFER_SETUP)FLEXCOM3_TWI_TransferSetup,

    /* I2C PLib Callback Register */
    .callbackRegister = (DRV_I2C_PLIB_CALLBACK_REGISTER)FLEXCOM3_TWI_CallbackRegister,
};


static const DRV_I2C_INTERRUPT_SOURCES drvI2C0InterruptSources =
{
    /* Peripheral has single interrupt vector */
    .isSingleIntSrc                        = true,

    /* Peripheral interrupt line */
    .intSources.i2cInterrupt             = (int32_t)FLEXCOM3_IRQn,
};

/* I2C Driver Initialization Data */
static const DRV_I2C_INIT drvI2C0InitData =
{
    /* I2C PLib API */
    .i2cPlib = &drvI2C0PLibAPI,

    /* I2C Number of clients */
    .numClients = DRV_I2C_CLIENTS_NUMBER_IDX0,

    /* I2C Client Objects Pool */
    .clientObjPool = (uintptr_t)&drvI2C0ClientObjPool[0],

    /* I2C TWI Queue Size */
    .transferObjPoolSize = DRV_I2C_QUEUE_SIZE_IDX0,

    /* I2C Transfer Objects */
    .transferObjPool = (uintptr_t)&drvI2C0TransferObj[0],

    /* I2C interrupt sources */
    .interruptSources = &drvI2C0InterruptSources,

    /* I2C Clock Speed */
    .clockSpeed = DRV_I2C_CLOCK_SPEED_IDX0,
};
// </editor-fold>




// *****************************************************************************
// *****************************************************************************
// Section: System Data
// *****************************************************************************
// *****************************************************************************
/* Structure to hold the object handles for the modules in the system. */
SYSTEM_OBJECTS sysObj;

// *****************************************************************************
// *****************************************************************************
// Section: Library/Stack Initialization Data
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="SYS_TIME Initialization Data">

static const SYS_TIME_PLIB_INTERFACE sysTimePlibAPI = {
    .timerCallbackSet = (SYS_TIME_PLIB_CALLBACK_REGISTER)RTT_CallbackRegister,
    .timerStart = (SYS_TIME_PLIB_START)RTT_Enable,
    .timerStop = (SYS_TIME_PLIB_STOP)RTT_Disable,
    .timerFrequencyGet = (SYS_TIME_PLIB_FREQUENCY_GET)RTT_FrequencyGet,
    .timerPeriodSet = (SYS_TIME_PLIB_PERIOD_SET)NULL,
    .timerCompareSet = (SYS_TIME_PLIB_COMPARE_SET)RTT_AlarmValueSet,
    .timerCounterGet = (SYS_TIME_PLIB_COUNTER_GET)RTT_TimerValueGet,
};

static const SYS_TIME_INIT sysTimeInitData =
{
    .timePlib = &sysTimePlibAPI,
    .hwTimerIntNum = RTT_IRQn,
};

// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="SYS_CONSOLE Instance 0 Initialization Data">


static const SYS_CONSOLE_UART_PLIB_INTERFACE sysConsole0UARTPlibAPI =
{
    .read_t = (SYS_CONSOLE_UART_PLIB_READ)FLEXCOM0_USART_Read,
    .readCountGet = (SYS_CONSOLE_UART_PLIB_READ_COUNT_GET)FLEXCOM0_USART_ReadCountGet,
    .readFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_READ_FREE_BUFFFER_COUNT_GET)FLEXCOM0_USART_ReadFreeBufferCountGet,
    .write_t = (SYS_CONSOLE_UART_PLIB_WRITE)FLEXCOM0_USART_Write,
    .writeCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_COUNT_GET)FLEXCOM0_USART_WriteCountGet,
    .writeFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_FREE_BUFFER_COUNT_GET)FLEXCOM0_USART_WriteFreeBufferCountGet,
};

static const SYS_CONSOLE_UART_INIT_DATA sysConsole0UARTInitData =
{
    .uartPLIB = &sysConsole0UARTPlibAPI,
};

static const SYS_CONSOLE_INIT sysConsole0Init =
{
    .deviceInitData = (const void*)&sysConsole0UARTInitData,
    .consDevDesc = &sysConsoleUARTDevDesc,
    .deviceIndex = 0,
};



// </editor-fold>




// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************

/* MISRAC 2012 deviation block end */

/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{

    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 2.2 deviated in this file.  Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1 */


    SEFC0_Initialize();

    SEFC1_Initialize();
  
    DWDT_Initialize();
    CLK_Initialize();
    RSTC_Initialize();

    PIO_Initialize();
    SUPC_Initialize();




    FLEXCOM3_TWI_Initialize();

    FLEXCOM0_USART_Initialize();

	BSP_Initialize();
	RTT_Initialize();


    /* MISRAC 2012 deviation block start */
    /* Following MISRA-C rules deviated in this block  */
    /* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    /* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */

    /* Initialize I2C0 Driver Instance */
    sysObj.drvI2C0 = DRV_I2C_Initialize(DRV_I2C_INDEX_0, (SYS_MODULE_INIT *)&drvI2C0InitData);


    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
    H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        
    sysObj.sysTime = SYS_TIME_Initialize(SYS_TIME_INDEX_0, (SYS_MODULE_INIT *)&sysTimeInitData);
    
    /* MISRAC 2012 deviation block end */
    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
     H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        sysObj.sysConsole0 = SYS_CONSOLE_Initialize(SYS_CONSOLE_INDEX_0, (SYS_MODULE_INIT *)&sysConsole0Init);
   /* MISRAC 2012 deviation block end */


    /* MISRAC 2012 deviation block end */
    APP_I2C_EEPROM_Initialize();
    APP_I2C_TEMP_SENSOR_Initialize();


    NVIC_Initialize();


    /* MISRAC 2012 deviation block end */
}

/*******************************************************************************
 End of File
*/
