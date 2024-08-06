/*
 * platform_types.h
 *
 *  Created on: Aug 6, 2024
 *      Author: AbdoHamdy
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef unsigned char      uint8_t;
typedef signed char        sint8_t;
typedef volatile uint8_t   vuint8_t;
typedef volatile sint8_t   vsint8_t;

typedef unsigned short     uint16_t;
typedef signed short       sint16_t;
typedef volatile uint16_t  vuint16_t;
typedef volatile sint16_t  vSint16_t;

typedef unsigned long int  uint32_t;
typedef signed long int    sint32_t;
typedef volatile uint32_t  vuint32_t;
typedef volatile sint32_t  vsint32_t;

typedef unsigned long long uint64_t;
typedef signed long long   sint64_t;
typedef volatile uint64_t  vuint64_t;
typedef volatile sint64_t  vsint64_t;

typedef float              f32_t;
typedef double             f64_t;


#endif /* PLATFORM_TYPES_H_ */
