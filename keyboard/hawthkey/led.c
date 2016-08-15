/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdint.h"
#include "led.h"

#include <avr/io.h>

void led_set(uint8_t usb_led)
{
}

void hook_layer_change(uint32_t layer_state) {
	DDRC &= ~0xc0;
	DDRF &= ~0x80;

	uint32_t state = layer_state;
	DDRC |= (state << 6) & 0xc0;
	DDRF |= (state << 5) & 0x80;

	PORTC &= ~0xc0;
	PORTF &= ~0x80;
}
