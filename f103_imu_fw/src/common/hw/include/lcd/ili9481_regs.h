#ifndef SRC_COMMON_HW_INCLUDE_LCD_ILI9481_REGS_H_
#define SRC_COMMON_HW_INCLUDE_LCD_ILI9481_REGS_H_



#define ILI9481_COM_NOP																		0x00U
#define ILI9481_COM_SOFT_RESET														0x01U
#define ILI9481_COM_GET_POWER_MODE												0x0AU
#define ILI9481_COM_GET_ADDRESS_MODE											0x0BU
#define ILI9481_COM_GET_PIXEL_FORMAT											0x0CU
#define ILI9481_COM_GET_DISPLAY_MODE											0x0DU
#define ILI9481_COM_GET_SIGNAL_MODE												0x0EU
#define ILI9481_COM_GET_DIAGNOSTIC_RESULT									0x0FU
#define ILI9481_COM_ENTER_SLEEP_MODE											0x10U
#define ILI9481_COM_EXIT_SLEEP_MODE												0x11U
#define ILI9481_COM_ENTER_PARTIAL_MODE										0x12U
#define ILI9481_COM_ENTER_NORMAL_MODE											0x13U
#define ILI9481_COM_EXIT_INVERT_MODE											0x20U
#define ILI9481_COM_ENTER_INVERT_MODE											0x21U
#define ILI9481_COM_SET_GAMMA_CURVE												0x26U
#define ILI9481_COM_SET_DISPLAY_OFF												0x28U
#define ILI9481_COM_SET_DISPLAY_ON												0x29U
#define ILI9481_COM_SET_COLUMN_ADDRESS										0x2AU
#define ILI9481_COM_SET_PAGE_ADDRESS											0x2BU
#define ILI9481_COM_WRITE_MEMORY_START										0x2CU
#define ILI9481_COM_WRITE_LUT															0x2DU
#define ILI9481_COM_READ_MEMORY_START											0x2EU
#define ILI9481_COM_SET_PARTIAL_AREA											0x30U
#define ILI9481_COM_SET_SCROLL_AREA												0x33U
#define ILI9481_COM_SET_TEAR_OFF													0x34U
#define ILI9481_COM_SET_TEAR_ON														0x35U
#define ILI9481_COM_SET_ADDRESS_MODE											0x36U
#define ILI9481_COM_SET_SCROLL_START											0x37U
#define ILI9481_COM_EXIT_IDLE_MODE												0x38U
#define ILI9481_COM_ENTER_IDLE_MODE												0x39U
#define ILI9481_COM_SET_PIXEL_FORMAT											0x3AU
#define ILI9481_COM_WRITE_MEMORY_CONTINUE									0x3CU
#define ILI9481_COM_READ_MEMORY_CONTINUE									0x3EU
#define ILI9481_COM_SET_TEAR_SCANLINE											0x44U
#define ILI9481_COM_GET_SCANLINE													0x45U
#define ILI9481_COM_READ_DDB_START												0xA1U
#define ILI9481_COM_READ_DDB_CONTINUE											0xA8U
#define ILI9481_COM_COMMAND_ACCESS_PROTECT								0xB0U
#define ILI9481_COM_LOW_POWER_MODE_CONTROL								0xB1U
#define ILI9481_COM_FRAME_MEM_ACS_AND_IF_SET							0xB3U
#define ILI9481_COM_DISP_MOD_AND_FRAME_MEM_WR_MOD_SET			0xB4U
#define ILI9481_COM_DEVICE_CODE_READ											0xBFU
#define ILI9481_COM_PANEL_DRIVING_SETTING									0xC0U
#define ILI9481_COM_DISP_TIMING_FOR_NORMAL_MODE						0xC1U
#define ILI9481_COM_DISP_TIMING_FOR_PARTIAL_MODE					0xC2U
#define ILI9481_COM_DISP_TIMING_FOR_IDLE_MODE							0xC3U
#define ILI9481_COM_FRAME_RATE_INVERSION_CONTROL					0xC5U
#define ILI9481_COM_INTERFACE_CONTROL											0xC6U
#define ILI9481_COM_GAMMA_SETTING													0xC8U
#define ILI9481_COM_POWER_SETTING													0xD0U
#define ILI9481_COM_VCOM_CONTROL													0xD1U
#define ILI9481_COM_POWER_SET_FOR_NORMAL_MODE							0xD2U
#define ILI9481_COM_POWER_SET_FOR_PARTIAL_MODE						0xD3U
#define ILI9481_COM_POWER_SET_FOR_IDLE_MODE								0xD4U
#define ILI9481_COM_NV_MEM_WR															0xE0U
#define ILI9481_COM_NV_MEM_CONTROL												0xE1U
#define ILI9481_COM_NV_MEM_STATUS													0xE2U
#define ILI9481_COM_NV_MEM_PROTECTION											0xE3U



#endif /* SRC_COMMON_HW_INCLUDE_LCD_ILI9481_REGS_H_ */
