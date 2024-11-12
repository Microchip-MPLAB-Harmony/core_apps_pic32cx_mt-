/*
 * Component description for RTT
 *
 * Copyright (c) 2023 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2023-12-19T08:59:03Z */
#ifndef _PIC32CXMTC_RTT_COMPONENT_H_
#define _PIC32CXMTC_RTT_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR RTT                                          */
/* ************************************************************************** */

/* -------- RTT_MR : (RTT Offset: 0x00) (R/W 32) Mode Register -------- */
#define RTT_MR_RTPRES_Pos                     _UINT32_(0)                                          /* (RTT_MR) Real-time Timer Prescaler Value Position */
#define RTT_MR_RTPRES_Msk                     (_UINT32_(0xFFFF) << RTT_MR_RTPRES_Pos)              /* (RTT_MR) Real-time Timer Prescaler Value Mask */
#define RTT_MR_RTPRES(value)                  (RTT_MR_RTPRES_Msk & (_UINT32_(value) << RTT_MR_RTPRES_Pos)) /* Assigment of value for RTPRES in the RTT_MR register */
#define RTT_MR_ALMIEN_Pos                     _UINT32_(16)                                         /* (RTT_MR) Alarm Interrupt Enable Position */
#define RTT_MR_ALMIEN_Msk                     (_UINT32_(0x1) << RTT_MR_ALMIEN_Pos)                 /* (RTT_MR) Alarm Interrupt Enable Mask */
#define RTT_MR_ALMIEN(value)                  (RTT_MR_ALMIEN_Msk & (_UINT32_(value) << RTT_MR_ALMIEN_Pos)) /* Assigment of value for ALMIEN in the RTT_MR register */
#define RTT_MR_RTTINCIEN_Pos                  _UINT32_(17)                                         /* (RTT_MR) Real-time Timer Increment Interrupt Enable Position */
#define RTT_MR_RTTINCIEN_Msk                  (_UINT32_(0x1) << RTT_MR_RTTINCIEN_Pos)              /* (RTT_MR) Real-time Timer Increment Interrupt Enable Mask */
#define RTT_MR_RTTINCIEN(value)               (RTT_MR_RTTINCIEN_Msk & (_UINT32_(value) << RTT_MR_RTTINCIEN_Pos)) /* Assigment of value for RTTINCIEN in the RTT_MR register */
#define RTT_MR_RTTRST_Pos                     _UINT32_(18)                                         /* (RTT_MR) Real-time Timer Restart Position */
#define RTT_MR_RTTRST_Msk                     (_UINT32_(0x1) << RTT_MR_RTTRST_Pos)                 /* (RTT_MR) Real-time Timer Restart Mask */
#define RTT_MR_RTTRST(value)                  (RTT_MR_RTTRST_Msk & (_UINT32_(value) << RTT_MR_RTTRST_Pos)) /* Assigment of value for RTTRST in the RTT_MR register */
#define RTT_MR_RTTDIS_Pos                     _UINT32_(20)                                         /* (RTT_MR) Real-time Timer Disable Position */
#define RTT_MR_RTTDIS_Msk                     (_UINT32_(0x1) << RTT_MR_RTTDIS_Pos)                 /* (RTT_MR) Real-time Timer Disable Mask */
#define RTT_MR_RTTDIS(value)                  (RTT_MR_RTTDIS_Msk & (_UINT32_(value) << RTT_MR_RTTDIS_Pos)) /* Assigment of value for RTTDIS in the RTT_MR register */
#define RTT_MR_INC2AEN_Pos                    _UINT32_(21)                                         /* (RTT_MR) RTTINC2 Alarm and Interrupt Enable Position */
#define RTT_MR_INC2AEN_Msk                    (_UINT32_(0x1) << RTT_MR_INC2AEN_Pos)                /* (RTT_MR) RTTINC2 Alarm and Interrupt Enable Mask */
#define RTT_MR_INC2AEN(value)                 (RTT_MR_INC2AEN_Msk & (_UINT32_(value) << RTT_MR_INC2AEN_Pos)) /* Assigment of value for INC2AEN in the RTT_MR register */
#define RTT_MR_RTC1HZ_Pos                     _UINT32_(24)                                         /* (RTT_MR) Real-Time Clock 1Hz Clock Selection Position */
#define RTT_MR_RTC1HZ_Msk                     (_UINT32_(0x1) << RTT_MR_RTC1HZ_Pos)                 /* (RTT_MR) Real-Time Clock 1Hz Clock Selection Mask */
#define RTT_MR_RTC1HZ(value)                  (RTT_MR_RTC1HZ_Msk & (_UINT32_(value) << RTT_MR_RTC1HZ_Pos)) /* Assigment of value for RTC1HZ in the RTT_MR register */
#define RTT_MR_Msk                            _UINT32_(0x0137FFFF)                                 /* (RTT_MR) Register Mask  */


/* -------- RTT_AR : (RTT Offset: 0x04) (R/W 32) Alarm Register -------- */
#define RTT_AR_ALMV_Pos                       _UINT32_(0)                                          /* (RTT_AR) Alarm Value Position */
#define RTT_AR_ALMV_Msk                       (_UINT32_(0xFFFFFFFF) << RTT_AR_ALMV_Pos)            /* (RTT_AR) Alarm Value Mask */
#define RTT_AR_ALMV(value)                    (RTT_AR_ALMV_Msk & (_UINT32_(value) << RTT_AR_ALMV_Pos)) /* Assigment of value for ALMV in the RTT_AR register */
#define RTT_AR_Msk                            _UINT32_(0xFFFFFFFF)                                 /* (RTT_AR) Register Mask  */


/* -------- RTT_VR : (RTT Offset: 0x08) ( R/ 32) Value Register -------- */
#define RTT_VR_CRTV_Pos                       _UINT32_(0)                                          /* (RTT_VR) Current Real-time Value Position */
#define RTT_VR_CRTV_Msk                       (_UINT32_(0xFFFFFFFF) << RTT_VR_CRTV_Pos)            /* (RTT_VR) Current Real-time Value Mask */
#define RTT_VR_CRTV(value)                    (RTT_VR_CRTV_Msk & (_UINT32_(value) << RTT_VR_CRTV_Pos)) /* Assigment of value for CRTV in the RTT_VR register */
#define RTT_VR_Msk                            _UINT32_(0xFFFFFFFF)                                 /* (RTT_VR) Register Mask  */


/* -------- RTT_SR : (RTT Offset: 0x0C) ( R/ 32) Status Register -------- */
#define RTT_SR_ALMS_Pos                       _UINT32_(0)                                          /* (RTT_SR) Real-time Alarm Status (cleared on read) Position */
#define RTT_SR_ALMS_Msk                       (_UINT32_(0x1) << RTT_SR_ALMS_Pos)                   /* (RTT_SR) Real-time Alarm Status (cleared on read) Mask */
#define RTT_SR_ALMS(value)                    (RTT_SR_ALMS_Msk & (_UINT32_(value) << RTT_SR_ALMS_Pos)) /* Assigment of value for ALMS in the RTT_SR register */
#define RTT_SR_RTTINC_Pos                     _UINT32_(1)                                          /* (RTT_SR) Prescaler Roll-over Status (cleared on read) Position */
#define RTT_SR_RTTINC_Msk                     (_UINT32_(0x1) << RTT_SR_RTTINC_Pos)                 /* (RTT_SR) Prescaler Roll-over Status (cleared on read) Mask */
#define RTT_SR_RTTINC(value)                  (RTT_SR_RTTINC_Msk & (_UINT32_(value) << RTT_SR_RTTINC_Pos)) /* Assigment of value for RTTINC in the RTT_SR register */
#define RTT_SR_RTTINC2_Pos                    _UINT32_(2)                                          /* (RTT_SR) Predefined Number of Prescaler Roll-overs Status (cleared on read) Position */
#define RTT_SR_RTTINC2_Msk                    (_UINT32_(0x1) << RTT_SR_RTTINC2_Pos)                /* (RTT_SR) Predefined Number of Prescaler Roll-overs Status (cleared on read) Mask */
#define RTT_SR_RTTINC2(value)                 (RTT_SR_RTTINC2_Msk & (_UINT32_(value) << RTT_SR_RTTINC2_Pos)) /* Assigment of value for RTTINC2 in the RTT_SR register */
#define RTT_SR_Msk                            _UINT32_(0x00000007)                                 /* (RTT_SR) Register Mask  */


/* -------- RTT_MODR : (RTT Offset: 0x10) (R/W 32) Modulo Selection Register -------- */
#define RTT_MODR_SELINC2_Pos                  _UINT32_(0)                                          /* (RTT_MODR) Selection of the 32-bit Counter Modulo to generate RTTINC2 Flag Position */
#define RTT_MODR_SELINC2_Msk                  (_UINT32_(0x7) << RTT_MODR_SELINC2_Pos)              /* (RTT_MODR) Selection of the 32-bit Counter Modulo to generate RTTINC2 Flag Mask */
#define RTT_MODR_SELINC2(value)               (RTT_MODR_SELINC2_Msk & (_UINT32_(value) << RTT_MODR_SELINC2_Pos)) /* Assigment of value for SELINC2 in the RTT_MODR register */
#define   RTT_MODR_SELINC2_NO_RTTINC2_Val     _UINT32_(0x0)                                        /* (RTT_MODR) The RTTINC2 flag never rises  */
#define   RTT_MODR_SELINC2_MOD64_Val          _UINT32_(0x1)                                        /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 64 equals 0  */
#define   RTT_MODR_SELINC2_MOD128_Val         _UINT32_(0x2)                                        /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 128 equals 0  */
#define   RTT_MODR_SELINC2_MOD256_Val         _UINT32_(0x3)                                        /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 256 equals 0  */
#define   RTT_MODR_SELINC2_MOD512_Val         _UINT32_(0x4)                                        /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 512 equals 0  */
#define   RTT_MODR_SELINC2_MOD1024_Val        _UINT32_(0x5)                                        /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 1024 equals 0. Example: If RTPRES=32 then RTTINC2 flag rises once per second if the slow clock is 32.768 kHz.  */
#define   RTT_MODR_SELINC2_MOD2048_Val        _UINT32_(0x6)                                        /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 2048 equals 0  */
#define   RTT_MODR_SELINC2_MOD4096_Val        _UINT32_(0x7)                                        /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 4096 equals 0  */
#define RTT_MODR_SELINC2_NO_RTTINC2           (RTT_MODR_SELINC2_NO_RTTINC2_Val << RTT_MODR_SELINC2_Pos) /* (RTT_MODR) The RTTINC2 flag never rises Position  */
#define RTT_MODR_SELINC2_MOD64                (RTT_MODR_SELINC2_MOD64_Val << RTT_MODR_SELINC2_Pos) /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 64 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD128               (RTT_MODR_SELINC2_MOD128_Val << RTT_MODR_SELINC2_Pos) /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 128 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD256               (RTT_MODR_SELINC2_MOD256_Val << RTT_MODR_SELINC2_Pos) /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 256 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD512               (RTT_MODR_SELINC2_MOD512_Val << RTT_MODR_SELINC2_Pos) /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 512 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD1024              (RTT_MODR_SELINC2_MOD1024_Val << RTT_MODR_SELINC2_Pos) /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 1024 equals 0. Example: If RTPRES=32 then RTTINC2 flag rises once per second if the slow clock is 32.768 kHz. Position  */
#define RTT_MODR_SELINC2_MOD2048              (RTT_MODR_SELINC2_MOD2048_Val << RTT_MODR_SELINC2_Pos) /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 2048 equals 0 Position  */
#define RTT_MODR_SELINC2_MOD4096              (RTT_MODR_SELINC2_MOD4096_Val << RTT_MODR_SELINC2_Pos) /* (RTT_MODR) The RTTINC2 flag is set when CRTV modulo 4096 equals 0 Position  */
#define RTT_MODR_Msk                          _UINT32_(0x00000007)                                 /* (RTT_MODR) Register Mask  */


/** \brief RTT register offsets definitions */
#define RTT_MR_REG_OFST                _UINT32_(0x00)      /* (RTT_MR) Mode Register Offset */
#define RTT_AR_REG_OFST                _UINT32_(0x04)      /* (RTT_AR) Alarm Register Offset */
#define RTT_VR_REG_OFST                _UINT32_(0x08)      /* (RTT_VR) Value Register Offset */
#define RTT_SR_REG_OFST                _UINT32_(0x0C)      /* (RTT_SR) Status Register Offset */
#define RTT_MODR_REG_OFST              _UINT32_(0x10)      /* (RTT_MODR) Modulo Selection Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief RTT register API structure */
typedef struct
{
  __IO  uint32_t                       RTT_MR;             /**< Offset: 0x00 (R/W  32) Mode Register */
  __IO  uint32_t                       RTT_AR;             /**< Offset: 0x04 (R/W  32) Alarm Register */
  __I   uint32_t                       RTT_VR;             /**< Offset: 0x08 (R/   32) Value Register */
  __I   uint32_t                       RTT_SR;             /**< Offset: 0x0C (R/   32) Status Register */
  __IO  uint32_t                       RTT_MODR;           /**< Offset: 0x10 (R/W  32) Modulo Selection Register */
} rtt_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CXMTC_RTT_COMPONENT_H_ */
