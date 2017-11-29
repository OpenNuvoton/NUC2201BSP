/**************************************************************************//**
 * @file     ps2_reg.h
 * @version  V1.00
 * @brief    PS2 register definition header file
 *
 * @copyright (C) 2017 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __PS2_REG_H__
#define __PS2_REG_H__


/*------------------------------ PS2 Controller ------------------------------*/
/** @addtogroup PS2 PS2 Serial Interface(PS2)
  Memory Mapped Structure for PS2 Serial Interface Controller
  @{
 */


typedef struct
{


/**
 * @var PS2_T::PS2CON
 * Offset: 0x00  PS/2 Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |PS2EN     |Enable PS/2 Device
 * |        |          |Enable PS/2 device controller
 * |        |          |0 = Disabled.
 * |        |          |1 = Enabled.
 * |[1]     |TXINTEN   |Enable Transmit Interrupt
 * |        |          |0 = Data transmit complete interrupt Disabled.
 * |        |          |1 = Data transmit complete interrupt Enabled.
 * |[2]     |RXINTEN   |Enable Receive Interrupt
 * |        |          |0 = Data receive complete interrupt Disabled.
 * |        |          |1 = Data receive complete interrupt Enabled.
 * |[6:3]   |TXFIFO_DEPTH|Transmit Data FIFO Depth
 * |        |          |There are 16 bytes buffer for data transmit.
 * |        |          |Software can define the FIFO depth from 1 to 16 bytes depends on application needs.
 * |        |          |0 = 1 byte.
 * |        |          |1 = 2 bytes.
 * |        |          |...
 * |        |          |14 = 15 bytes.
 * |        |          |15 = 16 bytes.
 * |[7]     |ACK       |Acknowledge Enable
 * |        |          |0 = Always send acknowledge to host at 12th clock for host to device communication.
 * |        |          |1 = If parity bit error or stop bit is not received correctly, acknowledge bit will not be sent
 * |        |          |to host at 12th clock.
 * |[8]     |CLRFIFO   |Clear TX FIFO
 * |        |          |Write 1 to this bit to terminate device to host transmission.
 * |        |          |The TXEMPTY(PS2STATUS[7]) bit will be set to 1 and pointer BYTEIDEX(PS2STATUS[11:8]) is reset to
 * |        |          |0 regardless there is residue data in buffer or not.
 * |        |          |The buffer content is not been cleared.
 * |        |          |0 = Not active.
 * |        |          |1 = Clear FIFO.
 * |[9]     |OVERRIDE  |Software Override PS/2 CLK/DATA Pin State
 * |        |          |0 = PS2_CLK and PS2_DATA pins are controlled by internal state machine.
 * |        |          |1 = PS2_CLK and PS2_DATA pins are controlled by software.
 * |[10]    |FPS2CLK   |Force PS2CLK Line
 * |        |          |It forces PS2_CLK line high or low regardless of the internal state of the device controller if
 * |        |          |OVERRIDE(PS2CON[9]) is set to 1.
 * |        |          |0 = Force PS2_CLK line low.
 * |        |          |1 = Force PS2_CLK line high.
 * |[11]    |FPS2DAT   |Force PS2DATA Line
 * |        |          |It forces PS2_DATA high or low regardless of the internal state of the device controller if
 * |        |          |OVERRIDE (PS2CON[9]) is set to 1.
 * |        |          |0 = Force PS2_DATA low.
 * |        |          |1 = Force PS2_DATA high.
 * @var PS2_T::PS2TXDATA0
 * Offset: 0x04  PS/2 Transmit Data Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |PS2TXDATAx|Transmit Data
 * |        |          |Writing data to this register starts in device to host communication if bus is in IDLE state.
 * |        |          |Software must enable PS2EN(PS2CON[0]) before writing data to TX buffer.
 * @var PS2_T::PS2TXDATA1
 * Offset: 0x08  PS/2 Transmit Data Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |PS2TXDATAx|Transmit Data
 * |        |          |Writing data to this register starts in device to host communication if bus is in IDLE state.
 * |        |          |Software must enable PS2EN(PS2CON[0]) before writing data to TX buffer.
 * @var PS2_T::PS2TXDATA2
 * Offset: 0x0C  PS/2 Transmit Data Register 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |PS2TXDATAx|Transmit Data
 * |        |          |Writing data to this register starts in device to host communication if bus is in IDLE state.
 * |        |          |Software must enable PS2EN(PS2CON[0]) before writing data to TX buffer.
 * @var PS2_T::PS2TXDATA3
 * Offset: 0x10  PS/2 Transmit Data Register 3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |PS2TXDATAx|Transmit Data
 * |        |          |Writing data to this register starts in device to host communication if bus is in IDLE state.
 * |        |          |Software must enable PS2EN(PS2CON[0]) before writing data to TX buffer.
 * @var PS2_T::PS2RXDATA
 * Offset: 0x14  PS/2 Receive Data Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |RXDATA    |Received Data
 * |        |          |For host to device communication, after acknowledge bit is sent, the received data is copied
 * |        |          |from receive shift register to PS2RXDATA register.
 * |        |          |CPU must read this register before next byte reception complete, otherwise the data will be
 * |        |          |overwritten and RXOVF(PS2STATUS[6]) bit will be set to 1.
 * @var PS2_T::PS2STATUS
 * Offset: 0x18  PS/2 Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |PS2CLK    |CLK Pin State
 * |        |          |This bit reflects the status of the PS2_CLK line after synchronizing.
 * |[1]     |PS2DATA   |DATA Pin State
 * |        |          |This bit reflects the status of the PS2_DATA line after synchronizing and sampling.
 * |[2]     |FRAMERR   |Frame Error
 * |        |          |For host to device communication, this bit sets to 1 if STOP bit (logic 1) is not received.
 * |        |          |If frame error occurs, the PS/2_DATA line may keep at low state after 12th clock.
 * |        |          |At this moment, software overrides PS2_CLK to send clock till PS2_DATA release to high state.
 * |        |          |After that, device sends a "Resend" command to host.
 * |        |          |0 = No frame error.
 * |        |          |1 = Frame error occur.
 * |        |          |Write 1 to clear this bit.
 * |[3]     |RXPARITY  |Received Parity
 * |        |          |This bit reflects the parity bit for the last received data byte (odd parity).
 * |        |          |This bit is read only.
 * |[4]     |RXBUSY    |Receive Busy
 * |        |          |This bit indicates that the PS/2 device is currently receiving data.
 * |        |          |0 = Idle.
 * |        |          |1 = Currently receiving data.
 * |        |          |This bit is read only.
 * |[5]     |TXBUSY    |Transmit Busy
 * |        |          |This bit indicates that the PS/2 device is currently sending data.
 * |        |          |0 = Idle.
 * |        |          |1 = Currently sending data.
 * |        |          |This bit is read only.
 * |[6]     |RXOVF     |RX Buffer Overwrite
 * |        |          |0 = No overwrite.
 * |        |          |1 = Data in PS2RXDATA register is overwritten by new received data.
 * |        |          |Write 1 to clear this bit.
 * |[7]     |TXEMPTY   |TX FIFO Empty
 * |        |          |When software writes data to PS2TXDATA0-3, the TXEMPTY bit is cleared to 0 immediately if
 * |        |          |PS2EN(PS2CON[0]) is enabled.
 * |        |          |When transmitted data byte number is equal to FIFODEPTH(PS2CON[6:3]) then TXEMPTY bit is set to
 * |        |          |1.
 * |        |          |0 = There is data to be transmitted.
 * |        |          |1 = FIFO is empty.
 * |        |          |This bit is read only.
 * |[11:8]  |BYTEIDX   |Byte Index
 * |        |          |It indicates which data byte in transmit data shift register.
 * |        |          |When all data in FIFO is transmitted and it will be cleared to 0.
 * |        |          |This bit is read only.
 * |        |          |BYTEIDX,    DATA Transmit , BYTEIDX,    DATA Transmit
 * |        |          |0000   , PS2TXDATA0[ 7: 0], 1000   , PS2TXDATA2[ 7: 0],
 * |        |          |0001   , PS2TXDATA0[15: 8], 1001   , PS2TXDATA2[15: 8],
 * |        |          |0010   , PS2TXDATA0[23:16], 1010   , PS2TXDATA2[23:16],
 * |        |          |0011   , PS2TXDATA0[31:24], 1011   , PS2TXDATA2[31:24],
 * |        |          |0100   , PS2TXDATA1[ 7: 0], 1100   , PS2TXDATA3[ 7: 0],
 * |        |          |0101   , PS2TXDATA1[15: 8], 1101   , PS2TXDATA3[15: 8],
 * |        |          |0110   , PS2TXDATA1[23:16], 1110   , PS2TXDATA3[23:16],
 * |        |          |0111   , PS2TXDATA1[31:24], 1111   , PS2TXDATA3[31:24],
 * @var PS2_T::PS2INTID
 * Offset: 0x1C  PS/2 Interrupt Identification Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |RXINT     |Receive Interrupt
 * |        |          |This bit is set to 1 when acknowledge bit is sent for Host to device communication.
 * |        |          |Interrupt occurs if RXINTEN(PS2CON[2]) bit is set to 1.
 * |        |          |0 = No interrupt.
 * |        |          |1 = Receive interrupt occurs.
 * |        |          |Write 1 to clear this bit to 0.
 * |[1]     |TXINT     |Transmit Interrupt
 * |        |          |This bit is set to 1 after STOP bit is transmitted.
 * |        |          |Interrupt occur if TXINTEN(PS2CON[1]) bit is set to 1.
 * |        |          |0 = No interrupt.
 * |        |          |1 = Transmit interrupt occurs.
 * |        |          |Write 1 to clear this bit to 0.
 */

    __IO uint32_t PS2CON;        /* Offset: 0x00  PS/2 Control Register                                              */
    __IO uint32_t PS2TXDATA0;    /* Offset: 0x04  PS/2 Transmit Data Register 0                                      */
    __IO uint32_t PS2TXDATA1;    /* Offset: 0x08  PS/2 Transmit Data Register 1                                      */
    __IO uint32_t PS2TXDATA2;    /* Offset: 0x0C  PS/2 Transmit Data Register 2                                      */
    __IO uint32_t PS2TXDATA3;    /* Offset: 0x10  PS/2 Transmit Data Register 3                                      */
    __IO uint32_t PS2RXDATA;     /* Offset: 0x14  PS/2 Receive Data Register                                         */
    __IO uint32_t PS2STATUS;     /* Offset: 0x18  PS/2 Status Register                                               */
    __IO uint32_t PS2INTID;      /* Offset: 0x1C  PS/2 Interrupt Identification Register                             */

} PS2_T;



/**
    @addtogroup PS2_CONST PS2 Bit Field Definition
    Constant Definitions for PS2 Controller
@{ */


/* PS2 PS2CON Bit Field Definitions */
#define PS2_PS2CON_PS2EN_Pos                       0                                        /*!< PS2_T::PS2CON: PS2EN Position */
#define PS2_PS2CON_PS2EN_Msk                       (1ul << PS2_PS2CON_PS2EN_Pos)            /*!< PS2_T::PS2CON: PS2EN Mask */

#define PS2_PS2CON_TXINTEN_Pos                     1                                        /*!< PS2_T::PS2CON: TXINTEN Position */
#define PS2_PS2CON_TXINTEN_Msk                     (1ul << PS2_PS2CON_TXINTEN_Pos)          /*!< PS2_T::PS2CON: TXINTEN Mask */

#define PS2_PS2CON_RXINTEN_Pos                     2                                        /*!< PS2_T::PS2CON: RXINTEN Position */
#define PS2_PS2CON_RXINTEN_Msk                     (1ul << PS2_PS2CON_RXINTEN_Pos)          /*!< PS2_T::PS2CON: RXINTEN Mask */

#define PS2_PS2CON_TXFIFO_DEPTH_Pos                3                                        /*!< PS2_T::PS2CON: TXFIFO_DEPTH Position */
#define PS2_PS2CON_TXFIFO_DEPTH_Msk                (0xFul << PS2_PS2CON_TXFIFO_DEPTH_Pos)   /*!< PS2_T::PS2CON: TXFIFO_DEPTH Mask */

#define PS2_PS2CON_ACK_Pos                         7                                        /*!< PS2_T::PS2CON: ACK Position */
#define PS2_PS2CON_ACK_Msk                         (1ul << PS2_PS2CON_ACK_Pos)              /*!< PS2_T::PS2CON: ACK Mask */

#define PS2_PS2CON_CLRFIFO_Pos                     8                                        /*!< PS2_T::PS2CON: CLRFIFO Position */
#define PS2_PS2CON_CLRFIFO_Msk                     (1ul << PS2_PS2CON_CLRFIFO_Pos)          /*!< PS2_T::PS2CON: CLRFIFO Mask */

#define PS2_PS2CON_OVERRIDE_Pos                    9                                        /*!< PS2_T::PS2CON: OVERRIDE Position */
#define PS2_PS2CON_OVERRIDE_Msk                    (1ul << PS2_PS2CON_OVERRIDE_Pos)         /*!< PS2_T::PS2CON: OVERRIDE Mask */

#define PS2_PS2CON_FPS2CLK_Pos                     10                                       /*!< PS2_T::PS2CON: FPS2CLK Position */
#define PS2_PS2CON_FPS2CLK_Msk                     (1ul << PS2_PS2CON_FPS2CLK_Pos)          /*!< PS2_T::PS2CON: FPS2CLK Mask */

#define PS2_PS2CON_FPS2DAT_Pos                     11                                       /*!< PS2_T::PS2CON: FPS2DAT Position */
#define PS2_PS2CON_FPS2DAT_Msk                     (1ul << PS2_PS2CON_FPS2DAT_Pos)          /*!< PS2_T::PS2CON: FPS2DAT Mask */

/* PS/2 PS2RXDATA Bit Field Definitions */
#define PS2_PS2RXDATA_RXDATA_Pos                   0                                        /*!< PS2_T::PS2RXDATA: RXDATA Position */
#define PS2_PS2RXDATA_RXDATA_Msk                   (0xFFul << PS2_PS2RXDATA_RXDATA_Pos)     /*!< PS2_T::PS2RXDATA: RXDATA Mask */

/* PS/2 PS2STATUS Bit Field Definitions */
#define PS2_PS2STATUS_PS2CLK_Pos                   0                                        /*!< PS2_T::PS2STATUS: PS2CLK Position */
#define PS2_PS2STATUS_PS2CLK_Msk                   (1ul << PS2_PS2STATUS_PS2CLK_Pos)        /*!< PS2_T::PS2STATUS: PS2CLK Mask */

#define PS2_PS2STATUS_PS2DATA_Pos                  1                                        /*!< PS2_T::PS2STATUS: PS2DATA Position */
#define PS2_PS2STATUS_PS2DATA_Msk                  (1ul << PS2_PS2STATUS_PS2DATA_Pos)       /*!< PS2_T::PS2STATUS: PS2DATA Mask */

#define PS2_PS2STATUS_FRAMERR_Pos                  2                                        /*!< PS2_T::PS2STATUS: FRAMERR Position */
#define PS2_PS2STATUS_FRAMERR_Msk                  (1ul << PS2_PS2STATUS_FRAMERR_Pos)       /*!< PS2_T::PS2STATUS: FRAMERR Mask */

#define PS2_PS2STATUS_RXPARITY_Pos                 3                                        /*!< PS2_T::PS2STATUS: RXPARITY Position */
#define PS2_PS2STATUS_RXPARITY_Msk                 (1ul << PS2_PS2STATUS_RXPARITY_Pos)      /*!< PS2_T::PS2STATUS: RXPARITY Mask */

#define PS2_PS2STATUS_RXBUSY_Pos                   4                                        /*!< PS2_T::PS2STATUS: RXBUSY Position */
#define PS2_PS2STATUS_RXBUSY_Msk                   (1ul << PS2_PS2STATUS_RXBUSY_Pos)        /*!< PS2_T::PS2STATUS: RXBUSY Mask */

#define PS2_PS2STATUS_TXBUSY_Pos                   5                                        /*!< PS2_T::PS2STATUS: TXBUSY Position */
#define PS2_PS2STATUS_TXBUSY_Msk                   (1ul << PS2_PS2STATUS_TXBUSY_Pos)        /*!< PS2_T::PS2STATUS: TXBUSY Mask */

#define PS2_PS2STATUS_RXOVF_Pos                    6                                        /*!< PS2_T::PS2STATUS: RXOVF Position */
#define PS2_PS2STATUS_RXOVF_Msk                    (1ul << PS2_PS2STATUS_RXOVF_Pos)         /*!< PS2_T::PS2STATUS: RXOVF Mask */

#define PS2_PS2STATUS_TXEMPTY_Pos                  7                                        /*!< PS2_T::PS2STATUS: TXEMPTY Position */
#define PS2_PS2STATUS_TXEMPTY_Msk                  (1ul << PS2_PS2STATUS_TXEMPTY_Pos)       /*!< PS2_T::PS2STATUS: TXEMPTY Mask */

#define PS2_PS2STATUS_BYTEIDX_Pos                  8                                        /*!< PS2_T::PS2STATUS: BYTEIDX Position */
#define PS2_PS2STATUS_BYTEIDX_Msk                  (0xFul << PS2_PS2STATUS_BYTEIDX_Pos)     /*!< PS2_T::PS2STATUS: BYTEIDX Mask */

/* PS/2 PS2INTID Bit Field Definitions */
#define PS2_PS2INTID_RXINT_Pos                     0                                        /*!< PS2_T::PS2INTID: RXINT Position */
#define PS2_PS2INTID_RXINT_Msk                     (1ul << PS2_PS2INTID_RXINT_Pos)          /*!< PS2_T::PS2INTID: RXINT Mask */

#define PS2_PS2INTID_TXINT_Pos                     1                                        /*!< PS2_T::PS2INTID: TXINT Position */
#define PS2_PS2INTID_TXINT_Msk                     (1ul << PS2_PS2INTID_TXINT_Pos)          /*!< PS2_T::PS2INTID: TXINT Mask */
/*@}*/ /* end of group PS2_CONST */
/*@}*/ /* end of group PS2 */


#endif /* __PS2_REG_H__ */
