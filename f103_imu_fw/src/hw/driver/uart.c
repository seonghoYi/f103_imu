#include "uart.h"
#include "qbuffer.h"

#ifdef _USE_HW_UART



#define UART_RX_BUF_SIZE    512

typedef struct
{
  bool is_init;
  uint32_t baud;

} uart_tbl_t;


uart_tbl_t uart_tbl[UART_MAX_CH];

static uint8_t rx_buf[UART_MAX_CH][UART_RX_BUF_SIZE];
static qbuffer_t qbuffer[UART_MAX_CH];


UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;


bool uartInit(void)
{
  bool ret = true;
  for (int i = 0; i < UART_MAX_CH; i++)
  {
    uart_tbl[i].is_init = false;
    uart_tbl[i].baud = 38400;
  }
  return ret;
}


bool uartOpen(uint8_t ch, uint32_t baud)
{
  bool ret = false;
  
  //uart_tbl_t *p_uart = &uart_tbl[ch];


  switch (ch)
  {
  case _DEF_UART1:
    huart2.Instance = USART2;
    huart2.Init.BaudRate = baud;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;


    HAL_UART_DeInit(&huart2);

    qbufferCreate(&qbuffer[ch], (uint8_t *)&rx_buf[ch][0], 256);

    __HAL_RCC_DMA1_CLK_ENABLE();
    HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);

    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
      Error_Handler();
    }
    else
    {
    	ret = true;
    	uart_tbl[ch].is_init = true;

    	if (HAL_UART_Receive_DMA(&huart2, (uint8_t *)&rx_buf[ch][0], 256) != HAL_OK)
    	{
    		ret = false;
    		uart_tbl[ch].is_init = false;
    	}

    	qbuffer[ch].in  = qbuffer[ch].len - hdma_usart2_rx.Instance->CNDTR;
    	qbuffer[ch].out = qbuffer[ch].in;
    }
    break;
  case _DEF_UART2:



    break;
  }

  return ret;
}

uint32_t uartAvailable(uint8_t ch)
{
  uint32_t ret = 0;

  switch (ch)
  {
  case _DEF_UART1:
  	qbuffer[ch].in = qbuffer[ch].len - hdma_usart2_rx.Instance->CNDTR;
  	ret = qbufferAvailable(&qbuffer[ch]);
    break;
  case _DEF_UART2:
    break;
  }
  return ret;
}

uint8_t uartRead(uint8_t ch)
{
  uint32_t ret = 0;

  switch (ch)
  {
  case _DEF_UART1:
  	qbufferRead(&qbuffer[ch], (uint8_t *)&ret, 1);
    break;
  case _DEF_UART2:
    
    break;
  }
  return ret;
}

uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
  uint32_t ret = 0;
  HAL_StatusTypeDef status;

  switch (ch)
  {
  case _DEF_UART1:
  	status = HAL_UART_Transmit(&huart2, p_data, length, 100);
		if (status == HAL_OK)
		{
			ret = length;
		}
    break;
  case _DEF_UART2:
    
    
    break;
  }
  return ret;
}

uint32_t uartPrintf(uint8_t ch, char *fmt, ...)
{
  char buf[256];
	va_list args;
	int len;
	uint32_t ret;

	va_start(args, fmt);
	len = vsnprintf(&buf[0], 256, fmt, args);

	ret = uartWrite(ch, (uint8_t *)&buf[0], len);

	va_end(args);
	return ret;
}

uint32_t uartGetBaud(uint8_t ch)
{
  uint32_t ret = 0;

  switch (ch)
  {
  case _DEF_UART1:
    ret = uart_tbl[ch].baud;
    break;
  case _DEF_UART2:
    
    break;
  }
  return ret;
}

bool uartFlush(uint8_t ch)
{
  bool ret = true;

  while(uartAvailable(ch))
  {
    uartRead(ch);
  }
  
  return ret;
}


void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspInit 0 */

  /* USER CODE END USART2_MspInit 0 */
    /* USART2 clock enable */
    __HAL_RCC_USART2_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USART2 DMA Init */
    /* USART2_RX Init */
    hdma_usart2_rx.Instance = DMA1_Channel6;
    hdma_usart2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_usart2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_usart2_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_usart2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_usart2_rx.Init.Mode = DMA_CIRCULAR;
    hdma_usart2_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_usart2_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(uartHandle,hdmarx,hdma_usart2_rx);

    /* USART2 interrupt Init */
    HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspInit 1 */

  /* USER CODE END USART2_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART2)
  {
  /* USER CODE BEGIN USART2_MspDeInit 0 */

  /* USER CODE END USART2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART2_CLK_DISABLE();

    /**USART2 GPIO Configuration
    PA2     ------> USART2_TX
    PA3     ------> USART2_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_2|GPIO_PIN_3);

    /* USART2 DMA DeInit */
    HAL_DMA_DeInit(uartHandle->hdmarx);

    /* USART2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART2_IRQn);
  /* USER CODE BEGIN USART2_MspDeInit 1 */

  /* USER CODE END USART2_MspDeInit 1 */
  }
}


#endif
