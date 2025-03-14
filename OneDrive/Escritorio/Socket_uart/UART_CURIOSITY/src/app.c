/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

 void APP_Initialize ( void )
 {
     appData.state = APP_STATE_INIT;
 
     // Initialize UART
     appData.uartHandle = DRV_UART_Open(DRV_UART_INDEX_0, DRV_IO_INTENT_READWRITE);
     if (appData.uartHandle == DRV_HANDLE_INVALID)
     {
         // Handle error
     }
 
     // Configure UART settings if necessary
     DRV_UART_SetBaudRate(appData.uartHandle, 9600); // Set baud rate to 9600
     DRV_UART_SetDataBits(appData.uartHandle, 8);   // Set data bits to 8
     DRV_UART_SetParity(appData.uartHandle, DRV_UART_PARITY_NONE); // No parity
     DRV_UART_SetStopBits(appData.uartHandle, 1);   // 1 stop bit
 }

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
void USART_SendData(const char* data, size_t length)
{
    if (appData.uartHandle != DRV_HANDLE_INVALID)
    {
        DRV_UART_Write(appData.uartHandle, data, length);
    }
}

void USART_ReceiveData(char* buffer, size_t length)
{
    if (appData.uartHandle != DRV_HANDLE_INVALID)
    {
        DRV_UART_Read(appData.uartHandle, buffer, length);
    }
}

void APP_Tasks ( void )
{
    switch ( appData.state )
    {
        case APP_STATE_INIT:
        {
            bool appInitialized = true;

            if (appInitialized)
            {
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            // Example: Send a message
            const char* message = "Hello from Curiosity!";
            USART_SendData(message, strlen(message));

            // Example: Receive data
            char buffer[100];
            USART_ReceiveData(buffer, sizeof(buffer));

            // Process received data (add your logic here)

            break;
        }

        default:
        {
            // Handle error in application's state machine.
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */
