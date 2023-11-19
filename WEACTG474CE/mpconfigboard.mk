# MCU settings
MCU_SERIES = g4
CMSIS_MCU = STM32G474xx
AF_FILE = boards/WEACTG474CE/stm32g474_af.csv
LD_FILES = boards/WEACTG474CE/stm32g474.ld boards/common_basic.ld

# Micropython settings.
MICROPY_VFS_LFS2 ?= 1

# Provide different variants for the downloads page.
ifeq ($(BOARD_VARIANT),DP)
MICROPY_FLOAT_IMPL=double
endif

ifeq ($(BOARD_VARIANT),THREAD)
CFLAGS += -DMICROPY_PY_THREAD=1
endif

ifeq ($(BOARD_VARIANT),DP_THREAD)
MICROPY_FLOAT_IMPL=double
CFLAGS += -DMICROPY_PY_THREAD=1
endif

ifeq ($(BOARD_VARIANT),NETWORK)
MICROPY_PY_NETWORK_WIZNET5K=5200
endif