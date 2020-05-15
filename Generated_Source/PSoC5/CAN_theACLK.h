/*******************************************************************************
* File Name: CAN_theACLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CAN_theACLK_H)
#define CY_CLOCK_CAN_theACLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void CAN_theACLK_Start(void) ;
void CAN_theACLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void CAN_theACLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void CAN_theACLK_StandbyPower(uint8 state) ;
void CAN_theACLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 CAN_theACLK_GetDividerRegister(void) ;
void CAN_theACLK_SetModeRegister(uint8 modeBitMask) ;
void CAN_theACLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 CAN_theACLK_GetModeRegister(void) ;
void CAN_theACLK_SetSourceRegister(uint8 clkSource) ;
uint8 CAN_theACLK_GetSourceRegister(void) ;
#if defined(CAN_theACLK__CFG3)
void CAN_theACLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 CAN_theACLK_GetPhaseRegister(void) ;
#endif /* defined(CAN_theACLK__CFG3) */

#define CAN_theACLK_Enable()                       CAN_theACLK_Start()
#define CAN_theACLK_Disable()                      CAN_theACLK_Stop()
#define CAN_theACLK_SetDivider(clkDivider)         CAN_theACLK_SetDividerRegister(clkDivider, 1u)
#define CAN_theACLK_SetDividerValue(clkDivider)    CAN_theACLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define CAN_theACLK_SetMode(clkMode)               CAN_theACLK_SetModeRegister(clkMode)
#define CAN_theACLK_SetSource(clkSource)           CAN_theACLK_SetSourceRegister(clkSource)
#if defined(CAN_theACLK__CFG3)
#define CAN_theACLK_SetPhase(clkPhase)             CAN_theACLK_SetPhaseRegister(clkPhase)
#define CAN_theACLK_SetPhaseValue(clkPhase)        CAN_theACLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(CAN_theACLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define CAN_theACLK_CLKEN              (* (reg8 *) CAN_theACLK__PM_ACT_CFG)
#define CAN_theACLK_CLKEN_PTR          ((reg8 *) CAN_theACLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define CAN_theACLK_CLKSTBY            (* (reg8 *) CAN_theACLK__PM_STBY_CFG)
#define CAN_theACLK_CLKSTBY_PTR        ((reg8 *) CAN_theACLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define CAN_theACLK_DIV_LSB            (* (reg8 *) CAN_theACLK__CFG0)
#define CAN_theACLK_DIV_LSB_PTR        ((reg8 *) CAN_theACLK__CFG0)
#define CAN_theACLK_DIV_PTR            ((reg16 *) CAN_theACLK__CFG0)

/* Clock MSB divider configuration register. */
#define CAN_theACLK_DIV_MSB            (* (reg8 *) CAN_theACLK__CFG1)
#define CAN_theACLK_DIV_MSB_PTR        ((reg8 *) CAN_theACLK__CFG1)

/* Mode and source configuration register */
#define CAN_theACLK_MOD_SRC            (* (reg8 *) CAN_theACLK__CFG2)
#define CAN_theACLK_MOD_SRC_PTR        ((reg8 *) CAN_theACLK__CFG2)

#if defined(CAN_theACLK__CFG3)
/* Analog clock phase configuration register */
#define CAN_theACLK_PHASE              (* (reg8 *) CAN_theACLK__CFG3)
#define CAN_theACLK_PHASE_PTR          ((reg8 *) CAN_theACLK__CFG3)
#endif /* defined(CAN_theACLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define CAN_theACLK_CLKEN_MASK         CAN_theACLK__PM_ACT_MSK
#define CAN_theACLK_CLKSTBY_MASK       CAN_theACLK__PM_STBY_MSK

/* CFG2 field masks */
#define CAN_theACLK_SRC_SEL_MSK        CAN_theACLK__CFG2_SRC_SEL_MASK
#define CAN_theACLK_MODE_MASK          (~(CAN_theACLK_SRC_SEL_MSK))

#if defined(CAN_theACLK__CFG3)
/* CFG3 phase mask */
#define CAN_theACLK_PHASE_MASK         CAN_theACLK__CFG3_PHASE_DLY_MASK
#endif /* defined(CAN_theACLK__CFG3) */

#endif /* CY_CLOCK_CAN_theACLK_H */


/* [] END OF FILE */
