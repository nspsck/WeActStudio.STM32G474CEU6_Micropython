#define MICROPY_HW_BOARD_NAME               "WeAct-STM32G474"
#define MICROPY_HW_MCU_NAME                 "STM32G474CE"
#define MICROPY_PY_SYS_PLATFORM             "STM32G474CEU6"

#define MICROPY_HW_ENABLE_RTC               (1)
#define MICROPY_HW_ENABLE_RNG               (1)
#define MICROPY_HW_ENABLE_ADC               (1)
#define MICROPY_HW_ENABLE_DAC               (1) // A4, A5
#define MICROPY_HW_ENABLE_TIMER             (1)
#define MICROPY_HW_ENABLE_SERVO             (1)
#define MICROPY_HW_ENABLE_USB               (1) // PA11/PA12
#define MICROPY_HW_HAS_SWITCH               (1)
#define MICROPY_HW_HAS_FLASH                (1)

// Various things you can disbale.
// #define MICROPY_PY_ASYNCIO          (0)
// #define MICROPY_PY_DEFLATE          (0)
// #define MICROPY_PY_BINASCII         (0)
// #define MICROPY_PY_HASHLIB          (0)
// #define MICROPY_PY_JSON             (0)
// #define MICROPY_PY_RE               (0)
// #define MICROPY_PY_FRAMEBUF         (0)
// #define MICROPY_PY_SOCKET           (0)
// #define MICROPY_PY_NETWORK          (0)

// Flash storage config
#define MICROPY_HW_SPIFLASH_ENABLE_CACHE            (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE    (0)

#if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE
// QSPI flash for storage
#define MICROPY_HW_SPIFLASH_SIZE_BITS       (64 * 1024 * 1024)
#define MICROPY_HW_QSPI_PRESCALER           (2) // 100MHz
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (26)
#define MICROPY_HW_QSPIFLASH_CS             (pin_B11)
#define MICROPY_HW_QSPIFLASH_SCK            (pin_B10)
#define MICROPY_HW_QSPIFLASH_IO0            (pin_B1)
#define MICROPY_HW_QSPIFLASH_IO1            (pin_B0)
#define MICROPY_HW_QSPIFLASH_IO2            (pin_A7)
#define MICROPY_HW_QSPIFLASH_IO3            (pin_A6)

// SPI flash #1, block device config
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;
#define MICROPY_HW_BDEV_SPIFLASH            (&spi_bdev)
#define MICROPY_HW_BDEV_SPIFLASH_CONFIG     (&spiflash_config)
#define MICROPY_HW_BDEV_SPIFLASH_SIZE_BYTES (MICROPY_HW_SPIFLASH_SIZE_BITS / 8)
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED   (&spi_bdev)
#endif

// The board has an 8MHz HSE, the following gives 170MHz CPU speed
#define MICROPY_HW_CLK_PLLM         (2)
#define MICROPY_HW_CLK_PLLN         (85)
#define MICROPY_HW_CLK_PLLP         (2)
#define MICROPY_HW_CLK_PLLQ         (8)
#define MICROPY_HW_CLK_PLLR         (2)
//#define MICROPY_HW_CLK_LAST_FREQ    (1)

// The board has an external 32kHz crystal attached
#define MICROPY_HW_RTC_USE_LSE              (1)
#define MICROPY_HW_RTC_USE_US               (0)
#define MICROPY_HW_RTC_USE_CALOUT           (1)
#define MICROPY_HW_CLK_USE_HSI48            (1)
#define MICROPY_HW_RCC_USB_CLKSOURCE        (RCC_USBCLKSOURCE_HSI48)
#define MICROPY_HW_RCC_RNG_CLKSOURCE        (RCC_RNGCLKSOURCE_HSI48)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_4

// USART
#define MICROPY_HW_LPUART1_TX       (pin_A2)  // A2, B11
#define MICROPY_HW_LPUART1_RX       (pin_A3)  // A3, B10
#define MICROPY_HW_UART1_TX         (pin_A9)  // A9, B6, C4
#define MICROPY_HW_UART1_RX         (pin_A10)  // A10, B7
// #define MICROPY_HW_UART2_TX       (pin_A2)  // A14, B3
// #define MICROPY_HW_UART2_RX       (pin_A3)  // A15, B4
// #define MICROPY_HW_UART2_RTS      (pin_A1)
// #define MICROPY_HW_UART2_CTS      (pin_A0)
#define MICROPY_HW_UART3_TX         (pin_C10) // B9, B10, C10, D8
#define MICROPY_HW_UART3_RX         (pin_C11) // B8 = boot0, B11, C11, D9, E15
// #define MICROPY_HW_UART3_RTS      (pin_B14) //
// #define MICROPY_HW_UART3_CTS      (pin_B13) // A13

#define MICROPY_HW_UART_REPL                PYB_UART_1
#define MICROPY_HW_UART_REPL_BAUD           115200

// I2C buses
#define MICROPY_HW_I2C1_SCL         (pin_B8) // A13, A15, B8 (=boot0)
#define MICROPY_HW_I2C1_SDA         (pin_B9) // A14, B7, B9
#define MICROPY_HW_I2C2_SCL         (pin_C4)   // A9, C4
#define MICROPY_HW_I2C2_SDA         (pin_A8)   // A8, F0
// #define MICROPY_HW_I2C3_SCL       (pin_)   // A8
// #define MICROPY_HW_I2C3_SDA       (pin_)   // B5, C11
// Not supported by Micropython yet.
// #define MICROPY_HW_I2C4_SCL         (pin_A13)   // A13
// #define MICROPY_HW_I2C4_SDA         (pin_B7)   // B7

// SPI buses
#define MICROPY_HW_SPI1_NSS         (pin_A15) // A4, A15
#define MICROPY_HW_SPI1_SCK         (pin_B3) // A5, B3
#define MICROPY_HW_SPI1_MISO        (pin_B4) // A6, B4
#define MICROPY_HW_SPI1_MOSI        (pin_B5) // A7, B5
#define MICROPY_HW_SPI2_NSS         (pin_B12)   // B12, F0
#define MICROPY_HW_SPI2_SCK         (pin_B13)   // B13, F1
#define MICROPY_HW_SPI2_MISO        (pin_B14)   // A10, B14
#define MICROPY_HW_SPI2_MOSI        (pin_B15)   // A11, B15
// #define MICROPY_HW_SPI3_NSS       (pin_)   // A4, A15
// #define MICROPY_HW_SPI3_SCK       (pin_)   // B3, C10
// #define MICROPY_HW_SPI3_MISO      (pin_)   // B4, C11
// #define MICROPY_HW_SPI3_MOSI      (pin_)   // B5

// FDCAN bus
// Interferes with USB.
// #define MICROPY_HW_CAN1_TX          (pin_A12) // A12, B9
// #define MICROPY_HW_CAN1_RX          (pin_A11) // A11, B8
// #define MICROPY_HW_CAN2_TX          (pin_) // 
// #define MICROPY_HW_CAN2_RX          (pin_) // 
// #define MICROPY_HW_CAN3_TX          (pin_) // 
// #define MICROPY_HW_CAN3_RX          (pin_) // 

// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN                (pin_C13)
#define MICROPY_HW_USRSW_PULL               (GPIO_PULLDOWN)
#define MICROPY_HW_USRSW_EXTI_MODE          (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED            (1)

// LEDs
#define MICROPY_HW_LED1                     (pin_C6)    // blue
#define MICROPY_HW_LED_ON(pin)              (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)             (mp_hal_pin_low(pin))

// USB config
#define MICROPY_HW_USB_FS                   (1)
#define MICROPY_HW_FLASH_FS_LABEL           "STM32G474CE"

#define MICROPY_HW_USB_MANUFACTURER_STRING      "WeActStudio"
#define MICROPY_HW_USB_PRODUCT_FS_STRING        "STM32G474CE Comm Port (FS Mode)"
#define MICROPY_HW_USB_CONFIGURATION_FS_STRING  "USB Config"
#define MICROPY_HW_USB_INTERFACE_FS_STRING      "USB Interface"
// This is to save a tiny little space taken by strings.
#define MICROPY_HW_USB_PRODUCT_HS_STRING        ""
#define MICROPY_HW_USB_CONFIGURATION_HS_STRING  ""
#define MICROPY_HW_USB_INTERFACE_HS_STRING      ""
