# WeActStudio.STM32G474CEU6_Micropython

This is a untested WIP, I am still waiting for my board to be shipped.
However, this could serve as a base line if you got your board faster and want to start rightaway.

## Required tweaks for QSPI-Flash to work (untested)

You can follow this thread: [https://github.com/micropython/micropython/pull/12512](https://github.com/micropython/micropython/pull/12512).
Basically you add `STM32G4` to the `#if defined()` list in the `ports/stm32/mpu.h` file like below:

```C
#if (defined(STM32F4) && defined(MICROPY_HW_ETH_MDC)) || defined(STM32F7) || defined(STM32H7) || defined(STM32G4)
```
