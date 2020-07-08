/*
 * main.c
 *
 *  Created on: 8 июля 2020 г.
 *      Author: komarkov.v
 */


#include <sysreg.h>
#include <hal_1967VN044.h>

int main(void)
{
	HAL_SYS_FlagEnable(); // Основной цикл
	while(1) {
		__builtin_sysreg_write(__FLAGREGST, 0x01); // зажигаем светодиод FLAG0
		HAL_SYS_WaitMs(500);
		__builtin_sysreg_write(__FLAGREGCL, 0x00); // гасим светодиод FLAG0

		__builtin_sysreg_write(__FLAGREGST, 0x02); // зажигаем светодиод FLAG1
		HAL_SYS_WaitMs(500);
		__builtin_sysreg_write(__FLAGREGCL, 0x00);

		__builtin_sysreg_write(__FLAGREGST, 0x04); // зажигаем светодиод FLAG2
		HAL_SYS_WaitMs(500);
		__builtin_sysreg_write(__FLAGREGCL, 0x00);

		__builtin_sysreg_write(__FLAGREGST, 0x08); // зажигаем светодиод FLAG3
		HAL_SYS_WaitMs(500);
		__builtin_sysreg_write(__FLAGREGCL, 0x00);
	}
}

