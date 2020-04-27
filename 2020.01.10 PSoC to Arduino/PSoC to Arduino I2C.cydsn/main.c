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
uint8 x = 0;
#define I2C_SLAVE_ADDR      (0x08u)
#define I2C_SLAVE_ADDR_W    (I2C_SLAVE_ADDR x)

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    I2C_1_Start();
    x = 0;
    for(;;)
        {
        I2C_1_MasterSendStart(I2C_SLAVE_ADDR, 0);
        I2C_1_MasterWriteByte(x);
        I2C_1_MasterSendStop();
        CyDelay(500);
        x++;
        }
}

/* [] END OF FILE */
