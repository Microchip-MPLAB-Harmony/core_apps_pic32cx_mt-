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
// <editor-fold defaultstate="collapsed" desc="DRV_AT25 Initialization Data">

/* SPI PLIB Interface Initialization for AT25 Driver */
static const DRV_AT25_PLIB_INTERFACE drvAT25PlibAPI = {

    /* SPI PLIB WriteRead function */
    .writeRead = (DRV_AT25_PLIB_WRITE_READ)FLEXCOM1_SPI_WriteRead,

    /* SPI PLIB Write function */
    .writeData = (DRV_AT25_PLIB_WRITE)FLEXCOM1_SPI_Write,

    /* SPI PLIB Read function */
    .readData = (DRV_AT25_PLIB_READ)FLEXCOM1_SPI_Read,

    /* SPI PLIB Transfer Status function */
    .isBusy = (DRV_AT25_PLIB_IS_BUSY)FLEXCOM1_SPI_IsBusy,

    /* SPI PLIB Callback Register */
    .callbackRegister = (DRV_AT25_PLIB_CALLBACK_REGISTER)FLEXCOM1_SPI_CallbackRegister,
};

/* AT25 Driver Initialization Data */
static const DRV_AT25_INIT drvAT25InitData =
{
    /* SPI PLIB API  interface*/
    .spiPlib = &drvAT25PlibAPI,

    /* AT25 Number of clients */
    .numClients = DRV_AT25_CLIENTS_NUMBER_IDX,

    /* EEPROM Page Size in bytes */
    .pageSize = DRV_AT25_EEPROM_PAGE_SIZE,

    /* Total size of the EEPROM in bytes */
    .flashSize = DRV_AT25_EEPROM_FLASH_SIZE,

    .blockStartAddress =    0x0,

    .chipSelectPin    = DRV_AT25_CHIP_SELECT_PIN_IDX,

    .holdPin    = DRV_AT25_HOLD_PIN_IDX,

    .writeProtectPin    = DRV_AT25_WP_PIN_IDX,
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




	BSP_Initialize();
    FLEXCOM1_SPI_Initialize();


    /* MISRAC 2012 deviation block start */
    /* Following MISRA-C rules deviated in this block  */
    /* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    /* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */

    sysObj.drvAT25 = DRV_AT25_Initialize(DRV_AT25_INDEX, (SYS_MODULE_INIT *)&drvAT25InitData);




    /* MISRAC 2012 deviation block end */
    APP_Initialize();


    NVIC_Initialize();


    /* MISRAC 2012 deviation block end */
}

/*******************************************************************************
 End of File
*/
