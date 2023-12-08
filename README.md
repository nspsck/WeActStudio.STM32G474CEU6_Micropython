# WeActStudio.STM32G474CEU6_Micropython

## Status
What works:
- Everything except changing frequency using `freq()` provided either by `machine` or `pyb` module.

Weird behavior:
- Floating points and integer arithmetics seems to be slower than the F4 series on the same clock by a huge margin.

## Required tweaks for QSPI-Flash to work (untested)

You can follow this thread: [https://github.com/micropython/micropython/pull/12512](https://github.com/micropython/micropython/pull/12512).
Basically you add `STM32G4` to the `#if defined()` list in the `ports/stm32/mpu.h` file like below:

```C
#if (defined(STM32F4) && defined(MICROPY_HW_ETH_MDC)) || defined(STM32F7) || defined(STM32H7) || defined(STM32G4)
```
