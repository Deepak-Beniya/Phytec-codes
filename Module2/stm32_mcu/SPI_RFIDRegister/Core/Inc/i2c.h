/**

 * original author: Husamuldeen <https://github.com/hussamaldean>

   ----------------------------------------------------------------------
   	Copyright (C) husamuldeen, 2020

    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.
     
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   ----------------------------------------------------------------------
 */



#ifndef __i2c_H
#define __i2c_H

#include "delay.h"
#include <stdint.h>
void i2c_init(void);
int8_t i2c_readByte(uint8_t saddr,uint8_t maddr,uint8_t *data);
int8_t i2c_writeByte(uint8_t saddr,uint8_t maddr,uint8_t data);
int8_t i2c_WriteMulti(uint8_t saddr,uint8_t maddr,uint8_t *buffer, uint8_t length);
int8_t i2c_ReadMulti(uint8_t saddr,uint8_t maddr, uint8_t n, uint8_t* data);
void i2c_bus_scan(void);
#endif

