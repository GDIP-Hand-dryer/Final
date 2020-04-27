/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
uint16 on;
uint16 off;


int main(void)
{
    on = 255;
    off = 0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    for(;;){
        I2C_1_Start();
        I2C_1_MasterSendRestart(0x40, 0);
        I2C_1_MasterSendStop();    
        I2C_1_MasterSendStart(0x40, 0);
        I2C_1_MasterWriteByte(0x06);
        I2C_1_MasterWriteByte(0x00);
        I2C_1_MasterWriteByte(on);
        I2C_1_MasterWriteByte(0x00);
        I2C_1_MasterWriteByte(off);
        I2C_1_MasterSendStop();
        CyDelay(500);
        I2C_1_MasterSendStart(0x40, 0);
        I2C_1_MasterWriteByte(0x06);
        I2C_1_MasterWriteByte(0x00);
        I2C_1_MasterWriteByte(off);
        I2C_1_MasterWriteByte(0x00);
        I2C_1_MasterWriteByte(off);
        I2C_1_MasterSendStop();
        CyDelay(500);
    }
}

/* [] END OF FILE */
