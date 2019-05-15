/*
 * main.cpp
 *
 *  Created on: 2019 May 14 13:08:09
 *  Author: Iacob Marian
 */
#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

#include "Dave/Generated/FREERTOS/task.h"
#include "Dave/Generated/FREERTOS/queue.h"
#include "SM_LED/LedController.h"

#include<string>

const unsigned long LIGHT_UP_TASK_PRIORITY = tskIDLE_PRIORITY + 1;
const unsigned long LIGHT_DOWN_TASK_PRIORITY = tskIDLE_PRIORITY + 1;

static void vTaskLightUp( void *pvParameters );
static void vTaskLightDown( void *pvParameters );

static void ErrorHandler(std::string);

static led_controller::LedController Led_Controller;

/*
 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */
int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */
  if(status != DAVE_STATUS_SUCCESS)
  {
	  ErrorHandler("DAVE APPs initialization failed\n");
  }

  BaseType_t xReturned = xTaskCreate( vTaskLightUp, ( const char * const ) "Light Up", configMINIMAL_STACK_SIZE, NULL, LIGHT_UP_TASK_PRIORITY, NULL );
  if(xReturned != pdPASS)
  {
	  ErrorHandler("Error creating Light Up task\n");
  }

  xReturned =  xTaskCreate( vTaskLightDown, ( const char * const ) "Light Down", configMINIMAL_STACK_SIZE, NULL, LIGHT_DOWN_TASK_PRIORITY, NULL );
  if(xReturned != pdPASS)
  {
	  ErrorHandler("Error creating Light Down task\n");
  }

  vTaskStartScheduler();

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
  }
}

static void ErrorHandler(std::string error)
{
	XMC_DEBUG(error);
	for(;;)
	{

	}
}
static void vTaskLightUp( void *pvParameters )
{
	//configASSERT( ((uint32_t) pvParameters) == 1);

	for(;;)
	{
		if(DIGITAL_IO_GetInput(&LightUpButton) == 0)
		{
			vTaskDelay(pdMS_TO_TICKS(500));
			Led_Controller.LightUp(500U);
		}
	}
}

static void vTaskLightDown( void *pvParameters )
{
	//configASSERT( ((uint32_t) pvParameters) == 1);

	for(;;)
	{
		if(DIGITAL_IO_GetInput(&LightDownButton) == 0)
		{
			vTaskDelay(pdMS_TO_TICKS(500));
			Led_Controller.LightDown(500U);
		}
	}
}
