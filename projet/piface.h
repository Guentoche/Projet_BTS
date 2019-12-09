/**
* piface.h
* functions for accessing the PiFace add-on for the Raspberry Pi
*/
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <linux/types.h>
#include <sys/ioctl.h>
#include <stdint.h>
int pfio_init(void);
int pfio_deinit(void);
uint8_t pfio_digital_read(uint8_t pin_number);
void pfio_digital_write(uint8_t pin_number, uint8_t value);
uint8_t pfio_read_input(void);
uint8_t pfio_read_output(void);
void pfio_write_output(uint8_t value);
uint8_t pfio_get_pin_bit_mask(uint8_t pin_number);
uint8_t pfio_get_pin_number(uint8_t bit_mask);
#ifdef __cplusplus
}
#endif


