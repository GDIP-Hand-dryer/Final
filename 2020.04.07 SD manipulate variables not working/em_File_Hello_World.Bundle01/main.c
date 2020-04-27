/*******************************************************************************
* File Name: main.c
*
* Version: 1.10
*
* Description:
*  The example project consists of 5 simple steps. Each of the steps performs 
*  single File System operation. 
*  Step#1: Gets SD card name and displays it on the LCD.
*  Step#2: Performs Format SD operation and displays the status of the format 
*  operation execution.
*  Step#3: Creates directory with the name - "Dir" and displays a status of 
*  directory creation operation.
*  Step#4: Creates a file - "File.txt" in the root directory and writes the 
*  following string to the file -"123456789". Displays a status of operations 
*  execution.
*  Step#5: Copies newly created file ("File.txt") to directory "Dir" with the 
*  name - "File1.txt". 
*
********************************************************************************
* Copyright 2011-2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>
#include <FS.h>
#include <string.h>
#include <Global.h>
#include <stdlib.h>

char sdFile[9] = "File.csv";
char sdFile2[14] = "Dir\\File2.csv";
char sdFile3[10] = "File3.csv";
char Int1;

int main()
{
    char sdVolName[10];     /* Buffer that will hold SD card Volume name */
    int SDNum[3][2];
    uint16 SDNumNew[10][10];
    
    FS_FILE * pFile;
    
    /* Initialize file system */
    FS_Init();
    
    /* Get volume name of SD card #0 */
    if(0 != FS_GetVolumeName(0u, &sdVolName[0], 9u))
    {
        /* Getting volume name succeeded so prompt it on the LCD */
    }
    else
    {
        /* Operation Failed - indicate this */

    }
    
    /* Need some delay to indicate output on the LCD */
    CyDelay(10u);
    
    if(0 == FS_FormatSD(sdVolName))
    {
       
    }
    else
    {

    }
    
    /* Need some delay to indicate output on the LCD */
    CyDelay(10u);

    /* This will create directory "Dir" on SD card */
    if(0 == FS_MkDir("Dir"))
    {
        /* Display successful directory creation message */

    }
    else
    {
        /* Display failure message */

    }
    
    CyDelay(10u);
   
    /* Create first file for modification */
    pFile = FS_FOpen(sdFile, "w");
    
    /* Check if file was created */
    if(pFile)
    {
        /* Indicate successful file creation message */

        CyDelay(10u);


        
        CyDelay(10u);
        
        if(0 == FS_FClose(pFile))
        {
            
        }
        else
        {
         
        }
    }
    else
    {
      
    }
    
    CyDelay(10u);
    
    /* Opens first file for reading*/
    pFile = FS_FOpen(sdFile, "r");

    if(0 != FS_Read(pFile, SDNum, 31u)) 
    {
        /* Inditate that data was written to a file */
 
    }
    else
    {

    }    
    
    
    /* Closes file */
    if(0 == FS_FClose(pFile))
    {
        
    }
    else
    {
    
    }

    if(0 == FS_FOpen(sdFile2, "w"))
    {
        
    }
    else
    {
      
    }
    
    if(pFile)
    {
        /* Indicate successful file creation message */

        CyDelay(10u);
        
        if(0 != FS_Write(pFile, SDNum, 31u)) 
        {
            /* Inditate that data was written to a file */
 
        }
        else
        {

        }
        
        /* Need some delay to indicate output on the LCD */
        CyDelay(10u);
        
        if(0 == FS_FClose(pFile))
        {
            
        }
        else
        {
         
        }
    }
    else
    {

    }

    
    /* Create first file for modification */
    pFile = FS_FOpen(sdFile3, "w");
    
    /* Check if file was created */
    if(pFile)
    {
        /* Indicate successful file creation message */

        CyDelay(10u);
        
        if(0 != FS_Write(pFile, SDNum, 31u)) 
        {
            /* Inditate that data was written to a file */
 
        }
        else
        {

        }
        
        CyDelay(10u);
        
        if(0 == FS_FClose(pFile))
        {
            
        }
        else
        {
         
        }
    }
    else
    {
      
    }
    
    CyDelay(10u);
}
/* [] END OF FILE */

