/**
  ******************************************************************************
  * @file    stm32l5xx_ll_rtc.h
  * @author  MCD Application Team
  * @brief   Header file of RTC LL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32L5xx_LL_RTC_H
#define STM32L5xx_LL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l5xx.h"

/** @addtogroup STM32L5xx_LL_Driver
  * @{
  */

#if defined(RTC)

/** @defgroup RTC_LL RTC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup RTC_LL_Private_Constants RTC Private Constants
  * @{
  */
/* Masks Definition */
#define RTC_LL_INIT_MASK              0xFFFFFFFFU
#define RTC_LL_RSF_MASK               0xFFFFFF5FU

/* Write protection defines */
#define RTC_WRITE_PROTECTION_DISABLE  (uint8_t)0xFF
#define RTC_WRITE_PROTECTION_ENABLE_1 (uint8_t)0xCA
#define RTC_WRITE_PROTECTION_ENABLE_2 (uint8_t)0x53

/* Defines used to combine date & time */
#define RTC_OFFSET_WEEKDAY            24U
#define RTC_OFFSET_DAY                16U
#define RTC_OFFSET_MONTH              8U
#define RTC_OFFSET_HOUR               16U
#define RTC_OFFSET_MINUTE             8U

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RTC_LL_Private_Macros RTC Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

#if !defined (UNUSED)
#define UNUSED(x) ((void)(x))
#endif

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RTC_LL_ES_INIT RTC Exported Init structure
  * @{
  */

/**
  * @brief  RTC Init structures definition
  */
typedef struct
{
  uint32_t HourFormat;   /*!< Specifies the RTC Hours Format.
                              This parameter can be a value of @ref RTC_LL_EC_HOURFORMAT

                              This feature can be modified afterwards using unitary function
                              @ref LL_RTC_SetHourFormat(). */

  uint32_t AsynchPrescaler; /*!< Specifies the RTC Asynchronous Predivider value.
                              This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7F

                              This feature can be modified afterwards using unitary function
                              @ref LL_RTC_SetAsynchPrescaler(). */

  uint32_t SynchPrescaler;  /*!< Specifies the RTC Synchronous Predivider value.
                              This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7FFF

                              This feature can be modified afterwards using unitary function
                              @ref LL_RTC_SetSynchPrescaler(). */
} LL_RTC_InitTypeDef;

/**
  * @brief  RTC Time structure definition
  */
typedef struct
{
  uint32_t TimeFormat; /*!< Specifies the RTC AM/PM Time.
                            This parameter can be a value of @ref RTC_LL_EC_TIME_FORMAT

                            This feature can be modified afterwards using unitary function @ref LL_RTC_TIME_SetFormat(). */

  uint8_t Hours;       /*!< Specifies the RTC Time Hours.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 12 if the @ref LL_RTC_TIME_FORMAT_PM is selected.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 23 if the @ref LL_RTC_TIME_FORMAT_AM_OR_24 is selected.

                            This feature can be modified afterwards using unitary function @ref LL_RTC_TIME_SetHour(). */

  uint8_t Minutes;     /*!< Specifies the RTC Time Minutes.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 59

                            This feature can be modified afterwards using unitary function @ref LL_RTC_TIME_SetMinute(). */

  uint8_t Seconds;     /*!< Specifies the RTC Time Seconds.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 59

                            This feature can be modified afterwards using unitary function @ref LL_RTC_TIME_SetSecond(). */
} LL_RTC_TimeTypeDef;

/**
  * @brief  RTC Date structure definition
  */
typedef struct
{
  uint8_t WeekDay;  /*!< Specifies the RTC Date WeekDay.
                         This parameter can be a value of @ref RTC_LL_EC_WEEKDAY

                         This feature can be modified afterwards using unitary function @ref LL_RTC_DATE_SetWeekDay(). */

  uint8_t Month;    /*!< Specifies the RTC Date Month.
                         This parameter can be a value of @ref RTC_LL_EC_MONTH

                         This feature can be modified afterwards using unitary function @ref LL_RTC_DATE_SetMonth(). */

  uint8_t Day;      /*!< Specifies the RTC Date Day.
                         This parameter must be a number between Min_Data = 1 and Max_Data = 31

                         This feature can be modified afterwards using unitary function @ref LL_RTC_DATE_SetDay(). */

  uint8_t Year;     /*!< Specifies the RTC Date Year.
                         This parameter must be a number between Min_Data = 0 and Max_Data = 99

                         This feature can be modified afterwards using unitary function @ref LL_RTC_DATE_SetYear(). */
} LL_RTC_DateTypeDef;

/**
  * @brief  RTC Alarm structure definition
  */
typedef struct
{
  LL_RTC_TimeTypeDef AlarmTime;  /*!< Specifies the RTC Alarm Time members. */

  uint32_t AlarmMask;            /*!< Specifies the RTC Alarm Masks.
                                      This parameter can be a value of @ref RTC_LL_EC_ALMA_MASK for ALARM A or @ref RTC_LL_EC_ALMB_MASK for ALARM B.

                                      This feature can be modified afterwards using unitary function @ref LL_RTC_ALMA_SetMask() for ALARM A
                                      or @ref LL_RTC_ALMB_SetMask() for ALARM B
                                 */

  uint32_t AlarmDateWeekDaySel;  /*!< Specifies the RTC Alarm is on day or WeekDay.
                                      This parameter can be a value of @ref RTC_LL_EC_ALMA_WEEKDAY_SELECTION for ALARM A or @ref RTC_LL_EC_ALMB_WEEKDAY_SELECTION for ALARM B

                                      This feature can be modified afterwards using unitary function @ref LL_RTC_ALMA_EnableWeekday() or @ref LL_RTC_ALMA_DisableWeekday()
                                      for ALARM A or @ref LL_RTC_ALMB_EnableWeekday() or @ref LL_RTC_ALMB_DisableWeekday() for ALARM B
                                 */

  uint8_t AlarmDateWeekDay;      /*!< Specifies the RTC Alarm Day/WeekDay.
                                      If AlarmDateWeekDaySel set to day, this parameter  must be a number between Min_Data = 1 and Max_Data = 31.

                                      This feature can be modified afterwards using unitary function @ref LL_RTC_ALMA_SetDay()
                                      for ALARM A or @ref LL_RTC_ALMB_SetDay() for ALARM B.

                                      If AlarmDateWeekDaySel set to Weekday, this parameter can be a value of @ref RTC_LL_EC_WEEKDAY.

                                      This feature can be modified afterwards using unitary function @ref LL_RTC_ALMA_SetWeekDay()
                                      for ALARM A or @ref LL_RTC_ALMB_SetWeekDay() for ALARM B.
                                 */
} LL_RTC_AlarmTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Constants RTC Exported Constants
  * @{
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RTC_LL_EC_FORMAT FORMAT
  * @{
  */
#define LL_RTC_FORMAT_BIN                  0x00000000U /*!< Binary data format */
#define LL_RTC_FORMAT_BCD                  0x00000001U /*!< BCD data format */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALMA_WEEKDAY_SELECTION RTC Alarm A Date WeekDay
  * @{
  */
#define LL_RTC_ALMA_DATEWEEKDAYSEL_DATE    0x00000000U             /*!< Alarm A Date is selected */
#define LL_RTC_ALMA_DATEWEEKDAYSEL_WEEKDAY RTC_ALRMAR_WDSEL        /*!< Alarm A WeekDay is selected */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALMB_WEEKDAY_SELECTION RTC Alarm B Date WeekDay
  * @{
  */
#define LL_RTC_ALMB_DATEWEEKDAYSEL_DATE    0x00000000U             /*!< Alarm B Date is selected */
#define LL_RTC_ALMB_DATEWEEKDAYSEL_WEEKDAY RTC_ALRMBR_WDSEL        /*!< Alarm B WeekDay is selected */
/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/** @defgroup RTC_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_RTC_ReadReg function
  * @{
  */
#define LL_RTC_SCR_ITSF                    RTC_SCR_CITSF
#define LL_RTC_SCR_TSOVF                   RTC_SCR_CTSOVF
#define LL_RTC_SCR_TSF                     RTC_SCR_CTSF
#define LL_RTC_SCR_WUTF                    RTC_SCR_CWUTF
#define LL_RTC_SCR_ALRBF                   RTC_SCR_CALRBF
#define LL_RTC_SCR_ALRAF                   RTC_SCR_CALRAF

#define LL_RTC_ICSR_RECALPF                RTC_ICSR_RECALPF
#define LL_RTC_ICSR_INITF                  RTC_ICSR_INITF
#define LL_RTC_ICSR_RSF                    RTC_ICSR_RSF
#define LL_RTC_ICSR_INITS                  RTC_ICSR_INITS
#define LL_RTC_ICSR_SHPF                   RTC_ICSR_SHPF
#define LL_RTC_ICSR_WUTWF                  RTC_ICSR_WUTWF
/**
  * @}
  */

/** @defgroup RTC_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_RTC_ReadReg and  LL_RTC_WriteReg functions
  * @{
  */
#define LL_RTC_CR_TSIE                     RTC_CR_TSIE
#define LL_RTC_CR_WUTIE                    RTC_CR_WUTIE
#define LL_RTC_CR_ALRBIE                   RTC_CR_ALRBIE
#define LL_RTC_CR_ALRAIE                   RTC_CR_ALRAIE
/**
  * @}
  */

/** @defgroup RTC_LL_EC_WEEKDAY  WEEK DAY
  * @{
  */
#define LL_RTC_WEEKDAY_MONDAY              (uint8_t)0x01 /*!< Monday    */
#define LL_RTC_WEEKDAY_TUESDAY             (uint8_t)0x02 /*!< Tuesday   */
#define LL_RTC_WEEKDAY_WEDNESDAY           (uint8_t)0x03 /*!< Wednesday */
#define LL_RTC_WEEKDAY_THURSDAY            (uint8_t)0x04 /*!< Thrusday  */
#define LL_RTC_WEEKDAY_FRIDAY              (uint8_t)0x05 /*!< Friday    */
#define LL_RTC_WEEKDAY_SATURDAY            (uint8_t)0x06 /*!< Saturday  */
#define LL_RTC_WEEKDAY_SUNDAY              (uint8_t)0x07 /*!< Sunday    */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_MONTH  MONTH
  * @{
  */
#define LL_RTC_MONTH_JANUARY               (uint8_t)0x01  /*!< January   */
#define LL_RTC_MONTH_FEBRUARY              (uint8_t)0x02  /*!< February  */
#define LL_RTC_MONTH_MARCH                 (uint8_t)0x03  /*!< March     */
#define LL_RTC_MONTH_APRIL                 (uint8_t)0x04  /*!< April     */
#define LL_RTC_MONTH_MAY                   (uint8_t)0x05  /*!< May       */
#define LL_RTC_MONTH_JUNE                  (uint8_t)0x06  /*!< June      */
#define LL_RTC_MONTH_JULY                  (uint8_t)0x07  /*!< July      */
#define LL_RTC_MONTH_AUGUST                (uint8_t)0x08  /*!< August    */
#define LL_RTC_MONTH_SEPTEMBER             (uint8_t)0x09  /*!< September */
#define LL_RTC_MONTH_OCTOBER               (uint8_t)0x10  /*!< October   */
#define LL_RTC_MONTH_NOVEMBER              (uint8_t)0x11  /*!< November  */
#define LL_RTC_MONTH_DECEMBER              (uint8_t)0x12  /*!< December  */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_HOURFORMAT  HOUR FORMAT
  * @{
  */
#define LL_RTC_HOURFORMAT_24HOUR           0x00000000U    /*!< 24 hour/day format */
#define LL_RTC_HOURFORMAT_AMPM             RTC_CR_FMT     /*!< AM/PM hour format */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALARMOUT  ALARM OUTPUT
  * @{
  */
#define LL_RTC_ALARMOUT_DISABLE            0x00000000U             /*!< Output disabled */
#define LL_RTC_ALARMOUT_ALMA               RTC_CR_OSEL_0           /*!< Alarm A output enabled */
#define LL_RTC_ALARMOUT_ALMB               RTC_CR_OSEL_1           /*!< Alarm B output enabled */
#define LL_RTC_ALARMOUT_WAKEUP             RTC_CR_OSEL             /*!< Wakeup output enabled */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALARM_OUTPUTTYPE  ALARM OUTPUT TYPE
  * @{
  */
#define LL_RTC_ALARM_OUTPUTTYPE_OPENDRAIN  RTC_CR_TAMPALRM_TYPE   /*!< RTC_ALARM is open-drain output */
#define LL_RTC_ALARM_OUTPUTTYPE_PUSHPULL   0x00000000U            /*!< RTC_ALARM is push-pull output */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_OUTPUTPOLARITY_PIN  OUTPUT POLARITY PIN
  * @{
  */
#define LL_RTC_OUTPUTPOLARITY_PIN_HIGH     0x00000000U           /*!< Pin is high when ALRAF/ALRBF/WUTF is asserted (depending on OSEL)*/
#define LL_RTC_OUTPUTPOLARITY_PIN_LOW      RTC_CR_POL            /*!< Pin is low when ALRAF/ALRBF/WUTF is asserted (depending on OSEL) */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TIME_FORMAT TIME FORMAT
  * @{
  */
#define LL_RTC_TIME_FORMAT_AM_OR_24        0x00000000U           /*!< AM or 24-hour format */
#define LL_RTC_TIME_FORMAT_PM              RTC_TR_PM             /*!< PM */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_SHIFT_SECOND  SHIFT SECOND
  * @{
  */
#define LL_RTC_SHIFT_SECOND_DELAY          0x00000000U           /* Delay (seconds) = SUBFS / (PREDIV_S + 1) */
#define LL_RTC_SHIFT_SECOND_ADVANCE        RTC_SHIFTR_ADD1S      /* Advance (seconds) = (1 - (SUBFS / (PREDIV_S + 1))) */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALMA_MASK  ALARMA MASK
  * @{
  */
#define LL_RTC_ALMA_MASK_NONE              0x00000000U             /*!< No masks applied on Alarm A*/
#define LL_RTC_ALMA_MASK_DATEWEEKDAY       RTC_ALRMAR_MSK4         /*!< Date/day do not care in Alarm A comparison */
#define LL_RTC_ALMA_MASK_HOURS             RTC_ALRMAR_MSK3         /*!< Hours do not care in Alarm A comparison */
#define LL_RTC_ALMA_MASK_MINUTES           RTC_ALRMAR_MSK2         /*!< Minutes do not care in Alarm A comparison */
#define LL_RTC_ALMA_MASK_SECONDS           RTC_ALRMAR_MSK1         /*!< Seconds do not care in Alarm A comparison */
#define LL_RTC_ALMA_MASK_ALL               (RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1) /*!< Masks all */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALMA_TIME_FORMAT  ALARMA TIME FORMAT
  * @{
  */
#define LL_RTC_ALMA_TIME_FORMAT_AM         0x00000000U           /*!< AM or 24-hour format */
#define LL_RTC_ALMA_TIME_FORMAT_PM         RTC_ALRMAR_PM         /*!< PM */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALMB_MASK  ALARMB MASK
  * @{
  */
#define LL_RTC_ALMB_MASK_NONE              0x00000000U             /*!< No masks applied on Alarm B*/
#define LL_RTC_ALMB_MASK_DATEWEEKDAY       RTC_ALRMBR_MSK4         /*!< Date/day do not care in Alarm B comparison */
#define LL_RTC_ALMB_MASK_HOURS             RTC_ALRMBR_MSK3         /*!< Hours do not care in Alarm B comparison */
#define LL_RTC_ALMB_MASK_MINUTES           RTC_ALRMBR_MSK2         /*!< Minutes do not care in Alarm B comparison */
#define LL_RTC_ALMB_MASK_SECONDS           RTC_ALRMBR_MSK1         /*!< Seconds do not care in Alarm B comparison */
#define LL_RTC_ALMB_MASK_ALL               (RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1) /*!< Masks all */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALMB_TIME_FORMAT  ALARMB TIME FORMAT
  * @{
  */
#define LL_RTC_ALMB_TIME_FORMAT_AM         0x00000000U           /*!< AM or 24-hour format */
#define LL_RTC_ALMB_TIME_FORMAT_PM         RTC_ALRMBR_PM         /*!< PM */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TIMESTAMP_EDGE  TIMESTAMP EDGE
  * @{
  */
#define LL_RTC_TIMESTAMP_EDGE_RISING       0x00000000U           /*!< RTC_TS input rising edge generates a time-stamp event */
#define LL_RTC_TIMESTAMP_EDGE_FALLING      RTC_CR_TSEDGE         /*!< RTC_TS input falling edge generates a time-stamp even */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TS_TIME_FORMAT  TIMESTAMP TIME FORMAT
  * @{
  */
#define LL_RTC_TS_TIME_FORMAT_AM           0x00000000U           /*!< AM or 24-hour format */
#define LL_RTC_TS_TIME_FORMAT_PM           RTC_TSTR_PM           /*!< PM */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TAMPER  TAMPER
  * @{
  */
#define LL_RTC_TAMPER_1                    TAMP_CR1_TAMP1E /*!< Tamper 1 input detection */
#define LL_RTC_TAMPER_2                    TAMP_CR1_TAMP2E /*!< Tamper 2 input detection */
#define LL_RTC_TAMPER_3                    TAMP_CR1_TAMP3E /*!< Tamper 3  input detection */
#define LL_RTC_TAMPER_4                    TAMP_CR1_TAMP4E /*!< Tamper 4  input detection */
#define LL_RTC_TAMPER_5                    TAMP_CR1_TAMP5E /*!< Tamper 5  input detection */
#define LL_RTC_TAMPER_6                    TAMP_CR1_TAMP6E /*!< Tamper 6  input detection */
#define LL_RTC_TAMPER_7                    TAMP_CR1_TAMP7E /*!< Tamper 7  input detection */
#define LL_RTC_TAMPER_8                    TAMP_CR1_TAMP8E /*!< Tamper 8  input detection */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TAMPER_MASK  TAMPER MASK
  * @{
  */
#define LL_RTC_TAMPER_MASK_TAMPER1         TAMP_CR2_TAMP1MSK /*!< Tamper 1 event generates a trigger event. TAMP1F is masked and internally cleared by hardware.The backup registers are not erased */
#define LL_RTC_TAMPER_MASK_TAMPER2         TAMP_CR2_TAMP2MSK /*!< Tamper 2 event generates a trigger event. TAMP2F is masked and internally cleared by hardware. The backup registers are not erased. */
#define LL_RTC_TAMPER_MASK_TAMPER3         TAMP_CR2_TAMP3MSK /*!< Tamper 3 event generates a trigger event. TAMP2F is masked and internally cleared by hardware. The backup registers are not erased. */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TAMPER_NOERASE  TAMPER NO ERASE
  * @{
  */
#define LL_RTC_TAMPER_NOERASE_TAMPER1      TAMP_CR2_TAMP1NOERASE /*!< Tamper 1 event does not erase the backup registers. */
#define LL_RTC_TAMPER_NOERASE_TAMPER2      TAMP_CR2_TAMP2NOERASE /*!< Tamper 2 event does not erase the backup registers. */
#define LL_RTC_TAMPER_NOERASE_TAMPER3      TAMP_CR2_TAMP3NOERASE /*!< Tamper 3 event does not erase the backup registers. */
#define LL_RTC_TAMPER_NOERASE_TAMPER4      TAMP_CR2_TAMP4NOERASE /*!< Tamper 4 event does not erase the backup registers. */
#define LL_RTC_TAMPER_NOERASE_TAMPER5      TAMP_CR2_TAMP5NOERASE /*!< Tamper 5 event does not erase the backup registers. */
#define LL_RTC_TAMPER_NOERASE_TAMPER6      TAMP_CR2_TAMP6NOERASE /*!< Tamper 6 event does not erase the backup registers. */
#define LL_RTC_TAMPER_NOERASE_TAMPER7      TAMP_CR2_TAMP7NOERASE /*!< Tamper 7 event does not erase the backup registers. */
#define LL_RTC_TAMPER_NOERASE_TAMPER8      TAMP_CR2_TAMP8NOERASE /*!< Tamper 8 event does not erase the backup registers. */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TAMPER_DURATION  TAMPER DURATION
  * @{
  */
#define LL_RTC_TAMPER_DURATION_1RTCCLK     0x00000000U            /*!< Tamper pins are pre-charged before sampling during 1 RTCCLK cycle  */
#define LL_RTC_TAMPER_DURATION_2RTCCLK     TAMP_FLTCR_TAMPPRCH_0  /*!< Tamper pins are pre-charged before sampling during 2 RTCCLK cycles */
#define LL_RTC_TAMPER_DURATION_4RTCCLK     TAMP_FLTCR_TAMPPRCH_1  /*!< Tamper pins are pre-charged before sampling during 4 RTCCLK cycles */
#define LL_RTC_TAMPER_DURATION_8RTCCLK     TAMP_FLTCR_TAMPPRCH    /*!< Tamper pins are pre-charged before sampling during 8 RTCCLK cycles */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TAMPER_FILTER  TAMPER FILTER
  * @{
  */
#define LL_RTC_TAMPER_FILTER_DISABLE       0x00000000U             /*!< Tamper filter is disabled */
#define LL_RTC_TAMPER_FILTER_2SAMPLE       TAMP_FLTCR_TAMPFLT_0    /*!< Tamper is activated after 2 consecutive samples at the active level */
#define LL_RTC_TAMPER_FILTER_4SAMPLE       TAMP_FLTCR_TAMPFLT_1    /*!< Tamper is activated after 4 consecutive samples at the active level */
#define LL_RTC_TAMPER_FILTER_8SAMPLE       TAMP_FLTCR_TAMPFLT      /*!< Tamper is activated after 8 consecutive samples at the active level. */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TAMPER_SAMPLFREQDIV  TAMPER SAMPLING FREQUENCY DIVIDER
  * @{
  */
#define LL_RTC_TAMPER_SAMPLFREQDIV_32768   0x00000000U                                     /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 32768 */
#define LL_RTC_TAMPER_SAMPLFREQDIV_16384   TAMP_FLTCR_TAMPFREQ_0                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 16384 */
#define LL_RTC_TAMPER_SAMPLFREQDIV_8192    TAMP_FLTCR_TAMPFREQ_1                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 8192 */
#define LL_RTC_TAMPER_SAMPLFREQDIV_4096    (TAMP_FLTCR_TAMPFREQ_1 | TAMP_FLTCR_TAMPFREQ_0) /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 4096 */
#define LL_RTC_TAMPER_SAMPLFREQDIV_2048    TAMP_FLTCR_TAMPFREQ_2                           /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 2048 */
#define LL_RTC_TAMPER_SAMPLFREQDIV_1024    (TAMP_FLTCR_TAMPFREQ_2 | TAMP_FLTCR_TAMPFREQ_0) /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 1024 */
#define LL_RTC_TAMPER_SAMPLFREQDIV_512     (TAMP_FLTCR_TAMPFREQ_2 | TAMP_FLTCR_TAMPFREQ_1) /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 512 */
#define LL_RTC_TAMPER_SAMPLFREQDIV_256     TAMP_FLTCR_TAMPFREQ                             /*!< Each of the tamper inputs are sampled with a frequency =  RTCCLK / 256 */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TAMPER_ACTIVELEVEL  TAMPER ACTIVE LEVEL
  * @{
  */
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP1    TAMP_CR2_TAMP1TRG /*!< Tamper 1 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP2    TAMP_CR2_TAMP2TRG /*!< Tamper 2 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP3    TAMP_CR2_TAMP3TRG /*!< Tamper 3 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP4    TAMP_CR2_TAMP4TRG /*!< Tamper 4 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP5    TAMP_CR2_TAMP5TRG /*!< Tamper 5 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP6    TAMP_CR2_TAMP6TRG /*!< Tamper 6 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP7    TAMP_CR2_TAMP7TRG /*!< Tamper 7 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP8    TAMP_CR2_TAMP8TRG /*!< Tamper 8 input falling edge (if TAMPFLT = 00) or staying high (if TAMPFLT != 00) triggers a tamper detection event */
/**
  * @}
  */


/** @defgroup RTC_LL_EC_INTERNAL  INTERNAL TAMPER
  * @{
  */
#define LL_RTC_TAMPER_ITAMP1               TAMP_CR1_ITAMP1E /*!< Internal tamper 1: RTC supply voltage monitoring */
#define LL_RTC_TAMPER_ITAMP2               TAMP_CR1_ITAMP2E /*!< Internal tamper 2: Temperature monitoring */
#define LL_RTC_TAMPER_ITAMP3               TAMP_CR1_ITAMP3E /*!< Internal tamper 3: LSE monitoring */
#define LL_RTC_TAMPER_ITAMP5               TAMP_CR1_ITAMP5E /*!< Internal tamper 5: RTC calendar overflow */
#define LL_RTC_TAMPER_ITAMP8               TAMP_CR1_ITAMP8E /*!< Internal tamper 8: Monotonic counter overflow */
/**
  * @}
  */


/** @defgroup RTC_LL_EC_ACTIVE_MODE   ACTIVE TAMPER MODE
  * @{
  */
#define LL_RTC_TAMPER_ATAMP_TAMP1AM               TAMP_ATCR1_TAMP1AM /*!< tamper 1 is active */
#define LL_RTC_TAMPER_ATAMP_TAMP2AM               TAMP_ATCR1_TAMP2AM /*!< tamper 2 is active */
#define LL_RTC_TAMPER_ATAMP_TAMP3AM               TAMP_ATCR1_TAMP3AM /*!< tamper 3 is active */
#define LL_RTC_TAMPER_ATAMP_TAMP4AM               TAMP_ATCR1_TAMP4AM /*!< tamper 4 is active */
#define LL_RTC_TAMPER_ATAMP_TAMP5AM               TAMP_ATCR1_TAMP5AM /*!< tamper 5 is active */
#define LL_RTC_TAMPER_ATAMP_TAMP6AM               TAMP_ATCR1_TAMP6AM /*!< tamper 6 is active */
#define LL_RTC_TAMPER_ATAMP_TAMP7AM               TAMP_ATCR1_TAMP7AM /*!< tamper 7 is active */
#define LL_RTC_TAMPER_ATAMP_TAMP8AM               TAMP_ATCR1_TAMP8AM /*!< tamper 8 is active */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ACTIVE_ASYNC_PRESCALER   ACTIVE TAMPER ASYNCHRONOUS PRESCALER CLOCK
  * @{
  */
#define LL_RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK      0u                                                                      /*!< RTCCLK */
#define LL_RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_2    TAMP_ATCR1_ATCKSEL_0                                                    /*!< RTCCLK/2 */
#define LL_RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_4    TAMP_ATCR1_ATCKSEL_1                                                    /*!< RTCCLK/4 */
#define LL_RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_8    (TAMP_ATCR1_ATCKSEL_1 | TAMP_ATCR1_ATCKSEL_0)                           /*!< RTCCLK/8 */
#define LL_RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_16   TAMP_ATCR1_ATCKSEL_2                                                    /*!< RTCCLK/16 */
#define LL_RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_32   (TAMP_ATCR1_ATCKSEL_2 | TAMP_ATCR1_ATCKSEL_0)                           /*!< RTCCLK/32 */
#define LL_RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_64   (TAMP_ATCR1_ATCKSEL_2 | TAMP_ATCR1_ATCKSEL_1)                           /*!< RTCCLK/64 */
#define LL_RTC_TAMPER_ATAMP_ASYNCPRES_RTCCLK_128  (TAMP_ATCR1_ATCKSEL_2 | TAMP_ATCR1_ATCKSEL_1 | TAMP_ATCR1_ATCKSEL_0)    /*!< RTCCLK/128 */
/**
  * @}
  */


/** @defgroup RTC_LL_EC_ACTIVE_OUTPUT_SELECTION   ACTIVE TAMPER OUTPUT SELECTION
  * @{
  */
#define LL_RTC_TAMPER_ATAMP1IN_ATAMP1OUT  (0u << TAMP_ATCR2_ATOSEL1_Pos)
#define LL_RTC_TAMPER_ATAMP1IN_ATAMP2OUT  (1u << TAMP_ATCR2_ATOSEL1_Pos)
#define LL_RTC_TAMPER_ATAMP1IN_ATAMP3OUT  (2u << TAMP_ATCR2_ATOSEL1_Pos)
#define LL_RTC_TAMPER_ATAMP1IN_ATAMP4OUT  (3u << TAMP_ATCR2_ATOSEL1_Pos)
#define LL_RTC_TAMPER_ATAMP1IN_ATAMP5OUT  (4u << TAMP_ATCR2_ATOSEL1_Pos)
#define LL_RTC_TAMPER_ATAMP1IN_ATAMP6OUT  (5u << TAMP_ATCR2_ATOSEL1_Pos)
#define LL_RTC_TAMPER_ATAMP1IN_ATAMP7OUT  (6u << TAMP_ATCR2_ATOSEL1_Pos)
#define LL_RTC_TAMPER_ATAMP1IN_ATAMP8OUT  (7u << TAMP_ATCR2_ATOSEL1_Pos)

#define LL_RTC_TAMPER_ATAMP2IN_ATAMP1OUT  (0u << TAMP_ATCR2_ATOSEL2_Pos)
#define LL_RTC_TAMPER_ATAMP2IN_ATAMP2OUT  (1u << TAMP_ATCR2_ATOSEL2_Pos)
#define LL_RTC_TAMPER_ATAMP2IN_ATAMP3OUT  (2u << TAMP_ATCR2_ATOSEL2_Pos)
#define LL_RTC_TAMPER_ATAMP2IN_ATAMP4OUT  (3u << TAMP_ATCR2_ATOSEL2_Pos)
#define LL_RTC_TAMPER_ATAMP2IN_ATAMP5OUT  (4u << TAMP_ATCR2_ATOSEL2_Pos)
#define LL_RTC_TAMPER_ATAMP2IN_ATAMP6OUT  (5u << TAMP_ATCR2_ATOSEL2_Pos)
#define LL_RTC_TAMPER_ATAMP2IN_ATAMP7OUT  (6u << TAMP_ATCR2_ATOSEL2_Pos)
#define LL_RTC_TAMPER_ATAMP2IN_ATAMP8OUT  (7u << TAMP_ATCR2_ATOSEL2_Pos)

#define LL_RTC_TAMPER_ATAMP3IN_ATAMP1OUT  (0u << TAMP_ATCR2_ATOSEL3_Pos)
#define LL_RTC_TAMPER_ATAMP3IN_ATAMP2OUT  (1u << TAMP_ATCR2_ATOSEL3_Pos)
#define LL_RTC_TAMPER_ATAMP3IN_ATAMP3OUT  (2u << TAMP_ATCR2_ATOSEL3_Pos)
#define LL_RTC_TAMPER_ATAMP3IN_ATAMP4OUT  (3u << TAMP_ATCR2_ATOSEL3_Pos)
#define LL_RTC_TAMPER_ATAMP3IN_ATAMP5OUT  (4u << TAMP_ATCR2_ATOSEL3_Pos)
#define LL_RTC_TAMPER_ATAMP3IN_ATAMP6OUT  (5u << TAMP_ATCR2_ATOSEL3_Pos)
#define LL_RTC_TAMPER_ATAMP3IN_ATAMP7OUT  (6u << TAMP_ATCR2_ATOSEL3_Pos)
#define LL_RTC_TAMPER_ATAMP3IN_ATAMP8OUT  (7u << TAMP_ATCR2_ATOSEL3_Pos)

#define LL_RTC_TAMPER_ATAMP4IN_ATAMP1OUT  (0u << TAMP_ATCR2_ATOSEL4_Pos)
#define LL_RTC_TAMPER_ATAMP4IN_ATAMP2OUT  (1u << TAMP_ATCR2_ATOSEL4_Pos)
#define LL_RTC_TAMPER_ATAMP4IN_ATAMP3OUT  (2u << TAMP_ATCR2_ATOSEL4_Pos)
#define LL_RTC_TAMPER_ATAMP4IN_ATAMP4OUT  (3u << TAMP_ATCR2_ATOSEL4_Pos)
#define LL_RTC_TAMPER_ATAMP4IN_ATAMP5OUT  (4u << TAMP_ATCR2_ATOSEL4_Pos)
#define LL_RTC_TAMPER_ATAMP4IN_ATAMP6OUT  (5u << TAMP_ATCR2_ATOSEL4_Pos)
#define LL_RTC_TAMPER_ATAMP4IN_ATAMP7OUT  (6u << TAMP_ATCR2_ATOSEL4_Pos)
#define LL_RTC_TAMPER_ATAMP4IN_ATAMP8OUT  (7u << TAMP_ATCR2_ATOSEL4_Pos)

#define LL_RTC_TAMPER_ATAMP5IN_ATAMP1OUT  (0u << TAMP_ATCR2_ATOSEL5_Pos)
#define LL_RTC_TAMPER_ATAMP5IN_ATAMP2OUT  (1u << TAMP_ATCR2_ATOSEL5_Pos)
#define LL_RTC_TAMPER_ATAMP5IN_ATAMP3OUT  (2u << TAMP_ATCR2_ATOSEL5_Pos)
#define LL_RTC_TAMPER_ATAMP5IN_ATAMP4OUT  (3u << TAMP_ATCR2_ATOSEL5_Pos)
#define LL_RTC_TAMPER_ATAMP5IN_ATAMP5OUT  (4u << TAMP_ATCR2_ATOSEL5_Pos)
#define LL_RTC_TAMPER_ATAMP5IN_ATAMP6OUT  (5u << TAMP_ATCR2_ATOSEL5_Pos)
#define LL_RTC_TAMPER_ATAMP5IN_ATAMP7OUT  (6u << TAMP_ATCR2_ATOSEL5_Pos)
#define LL_RTC_TAMPER_ATAMP5IN_ATAMP8OUT  (7u << TAMP_ATCR2_ATOSEL5_Pos)

#define LL_RTC_TAMPER_ATAMP6IN_ATAMP1OUT  (0u << TAMP_ATCR2_ATOSEL6_Pos)
#define LL_RTC_TAMPER_ATAMP6IN_ATAMP2OUT  (1u << TAMP_ATCR2_ATOSEL6_Pos)
#define LL_RTC_TAMPER_ATAMP6IN_ATAMP3OUT  (2u << TAMP_ATCR2_ATOSEL6_Pos)
#define LL_RTC_TAMPER_ATAMP6IN_ATAMP4OUT  (3u << TAMP_ATCR2_ATOSEL6_Pos)
#define LL_RTC_TAMPER_ATAMP6IN_ATAMP5OUT  (4u << TAMP_ATCR2_ATOSEL6_Pos)
#define LL_RTC_TAMPER_ATAMP6IN_ATAMP6OUT  (5u << TAMP_ATCR2_ATOSEL6_Pos)
#define LL_RTC_TAMPER_ATAMP6IN_ATAMP7OUT  (6u << TAMP_ATCR2_ATOSEL6_Pos)
#define LL_RTC_TAMPER_ATAMP6IN_ATAMP8OUT  (7u << TAMP_ATCR2_ATOSEL6_Pos)

#define LL_RTC_TAMPER_ATAMP7IN_ATAMP1OUT  (0u << TAMP_ATCR2_ATOSEL7_Pos)
#define LL_RTC_TAMPER_ATAMP7IN_ATAMP2OUT  (1u << TAMP_ATCR2_ATOSEL7_Pos)
#define LL_RTC_TAMPER_ATAMP7IN_ATAMP3OUT  (2u << TAMP_ATCR2_ATOSEL7_Pos)
#define LL_RTC_TAMPER_ATAMP7IN_ATAMP4OUT  (3u << TAMP_ATCR2_ATOSEL7_Pos)
#define LL_RTC_TAMPER_ATAMP7IN_ATAMP5OUT  (4u << TAMP_ATCR2_ATOSEL7_Pos)
#define LL_RTC_TAMPER_ATAMP7IN_ATAMP6OUT  (5u << TAMP_ATCR2_ATOSEL7_Pos)
#define LL_RTC_TAMPER_ATAMP7IN_ATAMP7OUT  (6u << TAMP_ATCR2_ATOSEL7_Pos)
#define LL_RTC_TAMPER_ATAMP7IN_ATAMP8OUT  (7u << TAMP_ATCR2_ATOSEL7_Pos)

#define LL_RTC_TAMPER_ATAMP8IN_ATAMP1OUT  (0u << TAMP_ATCR2_ATOSEL8_Pos)
#define LL_RTC_TAMPER_ATAMP8IN_ATAMP2OUT  (1u << TAMP_ATCR2_ATOSEL8_Pos)
#define LL_RTC_TAMPER_ATAMP8IN_ATAMP3OUT  (2u << TAMP_ATCR2_ATOSEL8_Pos)
#define LL_RTC_TAMPER_ATAMP8IN_ATAMP4OUT  (3u << TAMP_ATCR2_ATOSEL8_Pos)
#define LL_RTC_TAMPER_ATAMP8IN_ATAMP5OUT  (4u << TAMP_ATCR2_ATOSEL8_Pos)
#define LL_RTC_TAMPER_ATAMP8IN_ATAMP6OUT  (5u << TAMP_ATCR2_ATOSEL8_Pos)
#define LL_RTC_TAMPER_ATAMP8IN_ATAMP7OUT  (6u << TAMP_ATCR2_ATOSEL8_Pos)
#define LL_RTC_TAMPER_ATAMP8IN_ATAMP8OUT  (7u << TAMP_ATCR2_ATOSEL8_Pos)
/**
  * @}
  */

/** @defgroup RTC_LL_EC_BKP  BACKUP
  * @{
  */
#define LL_RTC_BKP_NUMBER                  RTC_BACKUP_NB
#define LL_RTC_BKP_DR0                     0U
#define LL_RTC_BKP_DR1                     1U
#define LL_RTC_BKP_DR2                     2U
#define LL_RTC_BKP_DR3                     3U
#define LL_RTC_BKP_DR4                     4U
#define LL_RTC_BKP_DR5                     5U
#define LL_RTC_BKP_DR6                     6U
#define LL_RTC_BKP_DR7                     7U
#define LL_RTC_BKP_DR8                     8U
#define LL_RTC_BKP_DR9                     9U
#define LL_RTC_BKP_DR10                    10U
#define LL_RTC_BKP_DR11                    11U
#define LL_RTC_BKP_DR12                    12U
#define LL_RTC_BKP_DR13                    13U
#define LL_RTC_BKP_DR14                    14U
#define LL_RTC_BKP_DR15                    15U
#define LL_RTC_BKP_DR16                    16U
#define LL_RTC_BKP_DR17                    17U
#define LL_RTC_BKP_DR18                    18U
#define LL_RTC_BKP_DR19                    19U
#define LL_RTC_BKP_DR20                    20U
#define LL_RTC_BKP_DR21                    21U
#define LL_RTC_BKP_DR22                    22U
#define LL_RTC_BKP_DR23                    23U
#define LL_RTC_BKP_DR24                    24U
#define LL_RTC_BKP_DR25                    25U
#define LL_RTC_BKP_DR26                    26U
#define LL_RTC_BKP_DR27                    27U
#define LL_RTC_BKP_DR28                    28U
#define LL_RTC_BKP_DR29                    29U
#define LL_RTC_BKP_DR30                    30U
#define LL_RTC_BKP_DR31                    31U
/**
  * @}
  */

/** @defgroup RTC_LL_EC_WAKEUPCLOCK_DIV  WAKEUP CLOCK DIV
  * @{
  */
#define LL_RTC_WAKEUPCLOCK_DIV_16          0x00000000U                           /*!< RTC/16 clock is selected */
#define LL_RTC_WAKEUPCLOCK_DIV_8           RTC_CR_WUCKSEL_0                      /*!< RTC/8 clock is selected */
#define LL_RTC_WAKEUPCLOCK_DIV_4           RTC_CR_WUCKSEL_1                      /*!< RTC/4 clock is selected */
#define LL_RTC_WAKEUPCLOCK_DIV_2           (RTC_CR_WUCKSEL_1 | RTC_CR_WUCKSEL_0) /*!< RTC/2 clock is selected */
#define LL_RTC_WAKEUPCLOCK_CKSPRE          RTC_CR_WUCKSEL_2                      /*!< ck_spre (usually 1 Hz) clock is selected */
#define LL_RTC_WAKEUPCLOCK_CKSPRE_WUT      (RTC_CR_WUCKSEL_2 | RTC_CR_WUCKSEL_1) /*!< ck_spre (usually 1 Hz) clock is selected and 2exp16 is added to the WUT counter value*/
/**
  * @}
  */

/** @defgroup RTC_LL_EC_CALIB_OUTPUT  Calibration output
  * @{
  */
#define LL_RTC_CALIB_OUTPUT_NONE           0x00000000U                 /*!< Calibration output disabled */
#define LL_RTC_CALIB_OUTPUT_1HZ            (RTC_CR_COE | RTC_CR_COSEL) /*!< Calibration output is 1 Hz */
#define LL_RTC_CALIB_OUTPUT_512HZ          RTC_CR_COE                 /*!< Calibration output is 512 Hz */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_CALIB_INSERTPULSE  Calibration pulse insertion
  * @{
  */
#define LL_RTC_CALIB_INSERTPULSE_NONE      0x00000000U           /*!< No RTCCLK pulses are added */
#define LL_RTC_CALIB_INSERTPULSE_SET       RTC_CALR_CALP         /*!< One RTCCLK pulse is effectively inserted every 2exp11 pulses (frequency increased by 488.5 ppm) */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_CALIB_PERIOD  Calibration period
  * @{
  */
#define LL_RTC_CALIB_PERIOD_32SEC          0x00000000U           /*!< Use a 32-second calibration cycle period */
#define LL_RTC_CALIB_PERIOD_16SEC          RTC_CALR_CALW16       /*!< Use a 16-second calibration cycle period */
#define LL_RTC_CALIB_PERIOD_8SEC           RTC_CALR_CALW8        /*!< Use a 8-second calibration cycle period */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_CALIB_LOWPOWER  Calibration low power
  * @{
  */
#define LL_RTC_CALIB_LOWPOWER_NONE         0x00000000U           /*!< High conso mode */
#define LL_RTC_CALIB_LOWPOWER_SET          RTC_CALR_LPCAL        /*!< low power mode */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_SECURE_RTC_FULL  Secure full rtc
  * @{
  */
#define LL_RTC_SECURE_FULL_YES             0U                    /*!< RTC full secure */
#define LL_RTC_SECURE_FULL_NO              RTC_SMCR_DECPROT      /*!< RTC is not full secure, features can be unsecure. See RTC_LL_EC_UNSECURE_RTC_FEATURE */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_UNSECURE_RTC_FEATURE  UnSecure features rtc in case of LL_RTC_SECURE_FULL_NO.
  * @{
  */
#define LL_RTC_UNSECURE_FEATURE_INIT       RTC_SMCR_INITDPROT    /*!< Initialization feature is not secure */
#define LL_RTC_UNSECURE_FEATURE_CAL        RTC_SMCR_CALDPROT     /*!< Calibration feature is not secure */
#define LL_RTC_UNSECURE_FEATURE_TS         RTC_SMCR_TSDPROT      /*!< Time stamp feature is not secure */
#define LL_RTC_UNSECURE_FEATURE_WUT        RTC_SMCR_WUTDPROT     /*!< Wake up timer feature is not secure */
#define LL_RTC_UNSECURE_FEATURE_ALRA       RTC_SMCR_ALRADPROT    /*!< Alarm A feature is not secure */
#define LL_RTC_UNSECURE_FEATURE_ALRB       RTC_SMCR_ALRBDPROT    /*!< Alarm B feature is not secure */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_SECURE_TAMP  Secure tamp
  * @{
  */
#define LL_TAMP_SECURE_FULL_YES            0U                   /*!< TAMP full secure */
#define LL_TAMP_SECURE_FULL_NO             TAMP_SMCR_TAMPDPROT  /*!< TAMP is not secure */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_PRIVILEGE_RTC_FULL  Privilege full rtc
  * @{
  */
#define LL_RTC_PRIVILEGE_FULL_YES          RTC_PRIVCR_PRIV      /*!< RTC full privilege */
#define LL_RTC_PRIVILEGE_FULL_NO           0U                   /*!< RTC is not full privilege, features can be unprivilege. See RTC_LL_EC_UNPRIVILEGE_RTC_FEATURE */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_PRIVILEGE_RTC_FEATURE  Privilege rtc features in case of LL_RTC_PRIVILEGE_FULL_NO.
  * @{
  */
#define LL_RTC_PRIVILEGE_FEATURE_INIT      RTC_PRIVCR_INITPRIV  /*!< Initialization feature is privilege*/
#define LL_RTC_PRIVILEGE_FEATURE_CAL       RTC_PRIVCR_CALPRIV   /*!< Calibration feature is privilege */
#define LL_RTC_PRIVILEGE_FEATURE_TS        RTC_PRIVCR_TSPRIV    /*!< Time stamp feature is privilege */
#define LL_RTC_PRIVILEGE_FEATURE_WUT       RTC_PRIVCR_WUTPRIV   /*!< Wake up timer feature is privilege */
#define LL_RTC_PRIVILEGE_FEATURE_ALRA      RTC_PRIVCR_ALRAPRIV  /*!< Alarm A feature is privilege */
#define LL_RTC_PRIVILEGE_FEATURE_ALRB      RTC_PRIVCR_ALRBPRIV  /*!< Alarm B feature is privilege */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_PRIVILEGE_TAMP_FULL  Privilege full tamp
  * @{
  */
#define LL_TAMP_PRIVILEGE_FULL_YES         TAMP_PRIVCR_TAMPPRIV /*!< TAMP full privilege */
#define LL_TAMP_PRIVILEGE_FULL_NO          0U                   /*!< TAMP is not privilege */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_PRIVILEGE_BACKUP_REG_ZONE  Privilege Backup register privilege zone
  * @{
  */
#define LL_RTC_PRIVILEGE_BKUP_ZONE_NONE    0U
#define LL_RTC_PRIVILEGE_BKUP_ZONE_1       TAMP_PRIVCR_BKPRWPRIV
#define LL_RTC_PRIVILEGE_BKUP_ZONE_2       TAMP_PRIVCR_BKPWPRIV
#define LL_RTC_PRIVILEGE_BKUP_ZONE_ALL     (LL_RTC_PRIVILEGE_BKUP_ZONE_1 |  LL_RTC_PRIVILEGE_BKUP_ZONE_2)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Macros RTC Exported Macros
  * @{
  */

/** @defgroup RTC_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in RTC register
  * @param  __INSTANCE__ RTC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_RTC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in RTC register
  * @param  __INSTANCE__ RTC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_RTC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup RTC_LL_EM_Convert Convert helper Macros
  * @{
  */

/**
  * @brief  Helper macro to convert a value from 2 digit decimal format to BCD format
  * @param  __VALUE__ Byte to be converted
  * @retval Converted byte
  */
#define __LL_RTC_CONVERT_BIN2BCD(__VALUE__) ((uint8_t)((((__VALUE__) / 10U) << 4U) | ((__VALUE__) % 10U)))

/**
  * @brief  Helper macro to convert a value from BCD format to 2 digit decimal format
  * @param  __VALUE__ BCD value to be converted
  * @retval Converted byte
  */
#define __LL_RTC_CONVERT_BCD2BIN(__VALUE__) ((uint8_t)((((uint8_t)((__VALUE__) & (uint8_t)0xF0U) >> (uint8_t)0x4U) * 10U) + ((__VALUE__) & (uint8_t)0x0FU)))

/**
  * @}
  */

/** @defgroup RTC_LL_EM_Date Date helper Macros
  * @{
  */

/**
  * @brief  Helper macro to retrieve weekday.
  * @param  __RTC_DATE__ Date returned by @ref  LL_RTC_DATE_Get function.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
#define __LL_RTC_GET_WEEKDAY(__RTC_DATE__) (((__RTC_DATE__) >> RTC_OFFSET_WEEKDAY) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve Year in BCD format
  * @param  __RTC_DATE__ Value returned by @ref  LL_RTC_DATE_Get
  * @retval Year in BCD format (0x00 . . . 0x99)
  */
#define __LL_RTC_GET_YEAR(__RTC_DATE__) ((__RTC_DATE__) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve Month in BCD format
  * @param  __RTC_DATE__ Value returned by @ref  LL_RTC_DATE_Get
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  */
#define __LL_RTC_GET_MONTH(__RTC_DATE__) (((__RTC_DATE__) >>RTC_OFFSET_MONTH) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve Day in BCD format
  * @param  __RTC_DATE__ Value returned by @ref  LL_RTC_DATE_Get
  * @retval Day in BCD format (0x01 . . . 0x31)
  */
#define __LL_RTC_GET_DAY(__RTC_DATE__) (((__RTC_DATE__) >>RTC_OFFSET_DAY) & 0x000000FFU)

/**
  * @}
  */

/** @defgroup RTC_LL_EM_Time Time helper Macros
  * @{
  */

/**
  * @brief  Helper macro to retrieve hour in BCD format
  * @param  __RTC_TIME__ RTC time returned by @ref LL_RTC_TIME_Get function
  * @retval Hours in BCD format (0x01. . .0x12 or between Min_Data=0x00 and Max_Data=0x23)
  */
#define __LL_RTC_GET_HOUR(__RTC_TIME__) (((__RTC_TIME__) >> RTC_OFFSET_HOUR) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve minute in BCD format
  * @param  __RTC_TIME__ RTC time returned by @ref LL_RTC_TIME_Get function
  * @retval Minutes in BCD format (0x00. . .0x59)
  */
#define __LL_RTC_GET_MINUTE(__RTC_TIME__) (((__RTC_TIME__) >> RTC_OFFSET_MINUTE) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve second in BCD format
  * @param  __RTC_TIME__ RTC time returned by @ref LL_RTC_TIME_Get function
  * @retval Seconds in  format (0x00. . .0x59)
  */
#define __LL_RTC_GET_SECOND(__RTC_TIME__) ((__RTC_TIME__) & 0x000000FFU)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Functions RTC Exported Functions
  * @{
  */

/** @defgroup RTC_LL_EF_Configuration Configuration
  * @{
  */

/**
  * @brief  Set Hours format (24 hour/day or AM/PM hour format)
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   It can be written in initialization mode only (@ref LL_RTC_EnableInitMode function)
  * @rmtoll RTC_CR           FMT           LL_RTC_SetHourFormat
  * @param  RTCx RTC Instance
  * @param  HourFormat This parameter can be one of the following values:
  *         @arg @ref LL_RTC_HOURFORMAT_24HOUR
  *         @arg @ref LL_RTC_HOURFORMAT_AMPM
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetHourFormat(RTC_TypeDef *RTCx, uint32_t HourFormat)
{
  MODIFY_REG(RTCx->CR, RTC_CR_FMT, HourFormat);
}

/**
  * @brief  Get Hours format (24 hour/day or AM/PM hour format)
  * @rmtoll RTC_CR           FMT           LL_RTC_GetHourFormat
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_HOURFORMAT_24HOUR
  *         @arg @ref LL_RTC_HOURFORMAT_AMPM
  */
__STATIC_INLINE uint32_t LL_RTC_GetHourFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_FMT));
}

/**
  * @brief  Select the flag to be routed to RTC_ALARM output
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           OSEL          LL_RTC_SetAlarmOutEvent
  * @param  RTCx RTC Instance
  * @param  AlarmOutput This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALARMOUT_DISABLE
  *         @arg @ref LL_RTC_ALARMOUT_ALMA
  *         @arg @ref LL_RTC_ALARMOUT_ALMB
  *         @arg @ref LL_RTC_ALARMOUT_WAKEUP
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetAlarmOutEvent(RTC_TypeDef *RTCx, uint32_t AlarmOutput)
{
  MODIFY_REG(RTCx->CR, RTC_CR_OSEL, AlarmOutput);
}

/**
  * @brief  Get the flag to be routed to RTC_ALARM output
  * @rmtoll RTC_CR           OSEL          LL_RTC_GetAlarmOutEvent
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_ALARMOUT_DISABLE
  *         @arg @ref LL_RTC_ALARMOUT_ALMA
  *         @arg @ref LL_RTC_ALARMOUT_ALMB
  *         @arg @ref LL_RTC_ALARMOUT_WAKEUP
  */
__STATIC_INLINE uint32_t LL_RTC_GetAlarmOutEvent(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_OSEL));
}

/**
  * @brief  Set RTC_ALARM output type (ALARM in push-pull or open-drain output)
  * @rmtoll RTC_CR           TAMPALRM_TYPE          LL_RTC_SetAlarmOutputType
  * @param  RTCx RTC Instance
  * @param  Output This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALARM_OUTPUTTYPE_OPENDRAIN
  *         @arg @ref LL_RTC_ALARM_OUTPUTTYPE_PUSHPULL
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetAlarmOutputType(RTC_TypeDef *RTCx, uint32_t Output)
{
  MODIFY_REG(RTCx->CR, RTC_CR_TAMPALRM_TYPE, Output);
}

/**
  * @brief  Get RTC_ALARM output type (ALARM in push-pull or open-drain output)
  * @rmtoll RTC_CR           TAMPALRM_TYPE          LL_RTC_SetAlarmOutputType
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_ALARM_OUTPUTTYPE_OPENDRAIN
  *         @arg @ref LL_RTC_ALARM_OUTPUTTYPE_PUSHPULL
  */
__STATIC_INLINE uint32_t LL_RTC_GetAlarmOutputType(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_TAMPALRM_TYPE));
}

/**
  * @brief  Enable initialization mode
  * @note   Initialization mode is used to program time and date register (RTC_TR and RTC_DR)
  *         and prescaler register (RTC_PRER).
  *         Counters are stopped and start counting from the new value when INIT is reset.
  * @rmtoll RTC_ICSR          INIT          LL_RTC_EnableInitMode
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableInitMode(RTC_TypeDef *RTCx)
{
  /* Set the Initialization mode */
  SET_BIT(RTCx->ICSR, RTC_ICSR_INIT);
}

/**
  * @brief  Disable initialization mode (Free running mode)
  * @rmtoll RTC_ICSR          INIT          LL_RTC_DisableInitMode
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableInitMode(RTC_TypeDef *RTCx)
{
  /* Exit Initialization mode */
  CLEAR_BIT(RTCx->ICSR, RTC_ICSR_INIT);

}

/**
  * @brief  Set Output polarity (pin is low when ALRAF/ALRBF/WUTF is asserted)
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           POL           LL_RTC_SetOutputPolarity
  * @param  RTCx RTC Instance
  * @param  Polarity This parameter can be one of the following values:
  *         @arg @ref LL_RTC_OUTPUTPOLARITY_PIN_HIGH
  *         @arg @ref LL_RTC_OUTPUTPOLARITY_PIN_LOW
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetOutputPolarity(RTC_TypeDef *RTCx, uint32_t Polarity)
{
  MODIFY_REG(RTCx->CR, RTC_CR_POL, Polarity);
}

/**
  * @brief  Get Output polarity
  * @rmtoll RTC_CR           POL           LL_RTC_GetOutputPolarity
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_OUTPUTPOLARITY_PIN_HIGH
  *         @arg @ref LL_RTC_OUTPUTPOLARITY_PIN_LOW
  */
__STATIC_INLINE uint32_t LL_RTC_GetOutputPolarity(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_POL));
}

/**
  * @brief  Enable Bypass the shadow registers
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           BYPSHAD       LL_RTC_EnableShadowRegBypass
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableShadowRegBypass(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_BYPSHAD);
}

/**
  * @brief  Disable Bypass the shadow registers
  * @rmtoll RTC_CR           BYPSHAD       LL_RTC_DisableShadowRegBypass
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableShadowRegBypass(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_BYPSHAD);
}

/**
  * @brief  Check if Shadow registers bypass is enabled or not.
  * @rmtoll RTC_CR           BYPSHAD       LL_RTC_IsShadowRegBypassEnabled
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsShadowRegBypassEnabled(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_BYPSHAD) == (RTC_CR_BYPSHAD)) ? 1U : 0U);
}

/**
  * @brief  Enable RTC_REFIN reference clock detection (50 or 60 Hz)
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   It can be written in initialization mode only (@ref LL_RTC_EnableInitMode function)
  * @rmtoll RTC_CR           REFCKON       LL_RTC_EnableRefClock
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableRefClock(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_REFCKON);
}

/**
  * @brief  Disable RTC_REFIN reference clock detection (50 or 60 Hz)
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   It can be written in initialization mode only (@ref LL_RTC_EnableInitMode function)
  * @rmtoll RTC_CR           REFCKON       LL_RTC_DisableRefClock
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableRefClock(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_REFCKON);
}

/**
  * @brief  Set Asynchronous prescaler factor
  * @rmtoll RTC_PRER         PREDIV_A      LL_RTC_SetAsynchPrescaler
  * @param  RTCx RTC Instance
  * @param  AsynchPrescaler Value between Min_Data = 0 and Max_Data = 0x7F
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetAsynchPrescaler(RTC_TypeDef *RTCx, uint32_t AsynchPrescaler)
{
  MODIFY_REG(RTCx->PRER, RTC_PRER_PREDIV_A, AsynchPrescaler << RTC_PRER_PREDIV_A_Pos);
}

/**
  * @brief  Set Synchronous prescaler factor
  * @rmtoll RTC_PRER         PREDIV_S      LL_RTC_SetSynchPrescaler
  * @param  RTCx RTC Instance
  * @param  SynchPrescaler Value between Min_Data = 0 and Max_Data = 0x7FFF
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetSynchPrescaler(RTC_TypeDef *RTCx, uint32_t SynchPrescaler)
{
  MODIFY_REG(RTCx->PRER, RTC_PRER_PREDIV_S, SynchPrescaler);
}

/**
  * @brief  Get Asynchronous prescaler factor
  * @rmtoll RTC_PRER         PREDIV_A      LL_RTC_GetAsynchPrescaler
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data = 0 and Max_Data = 0x7F
  */
__STATIC_INLINE uint32_t LL_RTC_GetAsynchPrescaler(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->PRER, RTC_PRER_PREDIV_A) >> RTC_PRER_PREDIV_A_Pos);
}

/**
  * @brief  Get Synchronous prescaler factor
  * @rmtoll RTC_PRER         PREDIV_S      LL_RTC_GetSynchPrescaler
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data = 0 and Max_Data = 0x7FFF
  */
__STATIC_INLINE uint32_t LL_RTC_GetSynchPrescaler(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->PRER, RTC_PRER_PREDIV_S));
}

/**
  * @brief  Enable the write protection for RTC registers.
  * @rmtoll RTC_WPR          KEY           LL_RTC_EnableWriteProtection
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableWriteProtection(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->WPR, RTC_WRITE_PROTECTION_DISABLE);
}

/**
  * @brief  Disable the write protection for RTC registers.
  * @rmtoll RTC_WPR          KEY           LL_RTC_DisableWriteProtection
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableWriteProtection(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->WPR, RTC_WRITE_PROTECTION_ENABLE_1);
  WRITE_REG(RTCx->WPR, RTC_WRITE_PROTECTION_ENABLE_2);
}

/**
  * @brief  Enable tamper output.
  * @note When the tamper output is enabled, all external and internal tamper flags
  *       are ORed and routed to the TAMPALRM output.
  * @rmtoll RTC_CR           TAMPOE       LL_RTC_EnableTamperOutput
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableTamperOutput(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TAMPOE);
}

/**
  * @brief  Disable tamper output.
  * @rmtoll RTC_CR           TAMPOE       LL_RTC_DisableTamperOutput
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableTamperOutput(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TAMPOE);
}

/**
  * @brief  Check if tamper output is enabled or not.
  * @rmtoll RTC_CR           TAMPOE       LL_RTC_IsTamperOutputEnabled
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsTamperOutputEnabled(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_TAMPOE) == (RTC_CR_TAMPOE)) ? 1U : 0U);
}

/**
  * @brief  Enable internal pull-up in output mode.
  * @rmtoll RTC_CR           TAMPALRM_PU       LL_RTC_EnableAlarmPullUp
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableAlarmPullUp(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TAMPALRM_PU);
}

/**
  * @brief  Disable internal pull-up in output mode.
  * @rmtoll RTC_CR           TAMPALRM_PU       LL_RTC_EnableAlarmPullUp
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableAlarmPullUp(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TAMPALRM_PU);
}

/**
  * @brief  Check if internal pull-up in output mode is enabled or not.
  * @rmtoll RTC_CR           TAMPALRM_PU       LL_RTC_IsAlarmPullUpEnabled
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsAlarmPullUpEnabled(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_TAMPALRM_PU) == (RTC_CR_TAMPALRM_PU)) ? 1U : 0U);
}

/**
  * @brief  Enable RTC_OUT2 output
  * @note RTC_OUT2 mapping depends on both OSEL (@ref LL_RTC_SetAlarmOutEvent)
  *       and COE (@ref LL_RTC_CAL_SetOutputFreq) settings.
  * @note RTC_OUT2 is not available ins VBAT mode.
  * @rmtoll RTC_CR           OUT2EN       LL_RTC_EnableOutput2
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableOutput2(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_OUT2EN);
}

/**
  * @brief  Disable RTC_OUT2 output
  * @rmtoll RTC_CR           OUT2EN       LL_RTC_DisableOutput2
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableOutput2(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_OUT2EN);
}

/**
  * @brief  Check if RTC_OUT2 output is enabled or not.
  * @rmtoll RTC_CR           OUT2EN       LL_RTC_IsOutput2Enabled
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsOutput2Enabled(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_OUT2EN) == (RTC_CR_OUT2EN)) ? 1U : 0U);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Time Time
  * @{
  */

/**
  * @brief  Set time format (AM/24-hour or PM notation)
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   It can be written in initialization mode only (@ref LL_RTC_EnableInitMode function)
  * @rmtoll RTC_TR           PM            LL_RTC_TIME_SetFormat
  * @param  RTCx RTC Instance
  * @param  TimeFormat This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TIME_FORMAT_AM_OR_24
  *         @arg @ref LL_RTC_TIME_FORMAT_PM
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_SetFormat(RTC_TypeDef *RTCx, uint32_t TimeFormat)
{
  MODIFY_REG(RTCx->TR, RTC_TR_PM, TimeFormat);
}

/**
  * @brief  Get time format (AM or PM notation)
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
  *       shadow registers until RTC_DR is read (LL_RTC_ReadReg(RTC, DR)).
  * @rmtoll RTC_TR           PM            LL_RTC_TIME_GetFormat
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_TIME_FORMAT_AM_OR_24
  *         @arg @ref LL_RTC_TIME_FORMAT_PM
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TR, RTC_TR_PM));
}

/**
  * @brief  Set Hours in BCD format
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   It can be written in initialization mode only (@ref LL_RTC_EnableInitMode function)
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert hour from binary to BCD format
  * @rmtoll RTC_TR           HT            LL_RTC_TIME_SetHour\n
  *         RTC_TR           HU            LL_RTC_TIME_SetHour
  * @param  RTCx RTC Instance
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_SetHour(RTC_TypeDef *RTCx, uint32_t Hours)
{
  MODIFY_REG(RTCx->TR, (RTC_TR_HT | RTC_TR_HU),
             (((Hours & 0xF0U) << (RTC_TR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_TR_HU_Pos)));
}

/**
  * @brief  Get Hours in BCD format
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
  *       shadow registers until RTC_DR is read (LL_RTC_ReadReg(RTC, DR)).
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert hour from BCD to
  *       Binary format
  * @rmtoll RTC_TR           HT            LL_RTC_TIME_GetHour\n
  *         RTC_TR           HU            LL_RTC_TIME_GetHour
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetHour(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->TR, (RTC_TR_HT | RTC_TR_HU))) >> RTC_TR_HU_Pos);
}

/**
  * @brief  Set Minutes in BCD format
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   It can be written in initialization mode only (@ref LL_RTC_EnableInitMode function)
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Minutes from binary to BCD format
  * @rmtoll RTC_TR           MNT           LL_RTC_TIME_SetMinute\n
  *         RTC_TR           MNU           LL_RTC_TIME_SetMinute
  * @param  RTCx RTC Instance
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_SetMinute(RTC_TypeDef *RTCx, uint32_t Minutes)
{
  MODIFY_REG(RTCx->TR, (RTC_TR_MNT | RTC_TR_MNU),
             (((Minutes & 0xF0U) << (RTC_TR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_TR_MNU_Pos)));
}

/**
  * @brief  Get Minutes in BCD format
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
  *       shadow registers until RTC_DR is read (LL_RTC_ReadReg(RTC, DR)).
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert minute from BCD
  *       to Binary format
  * @rmtoll RTC_TR           MNT           LL_RTC_TIME_GetMinute\n
  *         RTC_TR           MNU           LL_RTC_TIME_GetMinute
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetMinute(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TR, (RTC_TR_MNT | RTC_TR_MNU)) >> RTC_TR_MNU_Pos);
}

/**
  * @brief  Set Seconds in BCD format
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   It can be written in initialization mode only (@ref LL_RTC_EnableInitMode function)
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Seconds from binary to BCD format
  * @rmtoll RTC_TR           ST            LL_RTC_TIME_SetSecond\n
  *         RTC_TR           SU            LL_RTC_TIME_SetSecond
  * @param  RTCx RTC Instance
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_SetSecond(RTC_TypeDef *RTCx, uint32_t Seconds)
{
  MODIFY_REG(RTCx->TR, (RTC_TR_ST | RTC_TR_SU),
             (((Seconds & 0xF0U) << (RTC_TR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_TR_SU_Pos)));
}

/**
  * @brief  Get Seconds in BCD format
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
  *       shadow registers until RTC_DR is read (LL_RTC_ReadReg(RTC, DR)).
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Seconds from BCD
  *       to Binary format
  * @rmtoll RTC_TR           ST            LL_RTC_TIME_GetSecond\n
  *         RTC_TR           SU            LL_RTC_TIME_GetSecond
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TR, (RTC_TR_ST | RTC_TR_SU)) >> RTC_TR_SU_Pos);
}

/**
  * @brief  Set time (hour, minute and second) in BCD format
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   It can be written in initialization mode only (@ref LL_RTC_EnableInitMode function)
  * @note TimeFormat and Hours should follow the same format
  * @rmtoll RTC_TR           PM            LL_RTC_TIME_Config\n
  *         RTC_TR           HT            LL_RTC_TIME_Config\n
  *         RTC_TR           HU            LL_RTC_TIME_Config\n
  *         RTC_TR           MNT           LL_RTC_TIME_Config\n
  *         RTC_TR           MNU           LL_RTC_TIME_Config\n
  *         RTC_TR           ST            LL_RTC_TIME_Config\n
  *         RTC_TR           SU            LL_RTC_TIME_Config
  * @param  RTCx RTC Instance
  * @param  Format12_24 This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TIME_FORMAT_AM_OR_24
  *         @arg @ref LL_RTC_TIME_FORMAT_PM
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_Config(RTC_TypeDef *RTCx, uint32_t Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
{
  uint32_t temp;

  temp = Format12_24                                                                                    | \
         (((Hours & 0xF0U) << (RTC_TR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_TR_HU_Pos))     | \
         (((Minutes & 0xF0U) << (RTC_TR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_TR_MNU_Pos)) | \
         (((Seconds & 0xF0U) << (RTC_TR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_TR_SU_Pos));
  MODIFY_REG(RTCx->TR, (RTC_TR_PM | RTC_TR_HT | RTC_TR_HU | RTC_TR_MNT | RTC_TR_MNU | RTC_TR_ST | RTC_TR_SU), temp);
}

/**
  * @brief  Get time (hour, minute and second) in BCD format
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note Read either RTC_SSR or RTC_TR locks the values in the higher-order calendar
  *       shadow registers until RTC_DR is read (LL_RTC_ReadReg(RTC, DR)).
  * @note helper macros __LL_RTC_GET_HOUR, __LL_RTC_GET_MINUTE and __LL_RTC_GET_SECOND
  *       are available to get independently each parameter.
  * @rmtoll RTC_TR           HT            LL_RTC_TIME_Get\n
  *         RTC_TR           HU            LL_RTC_TIME_Get\n
  *         RTC_TR           MNT           LL_RTC_TIME_Get\n
  *         RTC_TR           MNU           LL_RTC_TIME_Get\n
  *         RTC_TR           ST            LL_RTC_TIME_Get\n
  *         RTC_TR           SU            LL_RTC_TIME_Get
  * @param  RTCx RTC Instance
  * @retval Combination of hours, minutes and seconds (Format: 0x00HHMMSS).
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_Get(RTC_TypeDef *RTCx)
{
  uint32_t temp;

  temp = READ_BIT(RTCx->TR, (RTC_TR_HT | RTC_TR_HU | RTC_TR_MNT | RTC_TR_MNU | RTC_TR_ST | RTC_TR_SU));
  return (uint32_t)((((((temp & RTC_TR_HT) >> RTC_TR_HT_Pos) << 4U) | ((temp & RTC_TR_HU) >> RTC_TR_HU_Pos)) << RTC_OFFSET_HOUR)       |  \
                    (((((temp & RTC_TR_MNT) >> RTC_TR_MNT_Pos) << 4U) | ((temp & RTC_TR_MNU) >> RTC_TR_MNU_Pos)) << RTC_OFFSET_MINUTE) | \
                    ((((temp & RTC_TR_ST) >> RTC_TR_ST_Pos) << 4U) | ((temp & RTC_TR_SU) >> RTC_TR_SU_Pos)));
}

/**
  * @brief  Memorize whether the daylight saving time change has been performed
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           BKP           LL_RTC_TIME_EnableDayLightStore
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_EnableDayLightStore(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_BKP);
}

/**
  * @brief  Disable memorization whether the daylight saving time change has been performed.
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           BKP           LL_RTC_TIME_DisableDayLightStore
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_DisableDayLightStore(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_BKP);
}

/**
  * @brief  Check if RTC Day Light Saving stored operation has been enabled or not
  * @rmtoll RTC_CR           BKP           LL_RTC_TIME_IsDayLightStoreEnabled
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_IsDayLightStoreEnabled(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_BKP) == (RTC_CR_BKP)) ? 1U : 0U);
}

/**
  * @brief  Subtract 1 hour (winter time change)
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           SUB1H         LL_RTC_TIME_DecHour
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_DecHour(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_SUB1H);
}

/**
  * @brief  Add 1 hour (summer time change)
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ADD1H         LL_RTC_TIME_IncHour
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_IncHour(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ADD1H);
}

/**
  * @brief  Get Sub second value in the synchronous prescaler counter.
  * @note  You can use both SubSeconds value and SecondFraction (PREDIV_S through
  *        LL_RTC_GetSynchPrescaler function) terms returned to convert Calendar
  *        SubSeconds value in second fraction ratio with time unit following
  *        generic formula:
  *          ==> Seconds fraction ratio * time_unit= [(SecondFraction-SubSeconds)/(SecondFraction+1)] * time_unit
  *        This conversion can be performed only if no shift operation is pending
  *        (ie. SHFP=0) when PREDIV_S >= SS.
  * @rmtoll RTC_SSR          SS            LL_RTC_TIME_GetSubSecond
  * @param  RTCx RTC Instance
  * @retval Sub second value (number between 0 and 65535)
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->SSR, RTC_SSR_SS));
}

/**
  * @brief  Synchronize to a remote clock with a high degree of precision.
  * @note   This operation effectively subtracts from (delays) or advance the clock of a fraction of a second.
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   When REFCKON is set, firmware must not write to Shift control register.
  * @rmtoll RTC_SHIFTR       ADD1S         LL_RTC_TIME_Synchronize\n
  *         RTC_SHIFTR       SUBFS         LL_RTC_TIME_Synchronize
  * @param  RTCx RTC Instance
  * @param  ShiftSecond This parameter can be one of the following values:
  *         @arg @ref LL_RTC_SHIFT_SECOND_DELAY
  *         @arg @ref LL_RTC_SHIFT_SECOND_ADVANCE
  * @param  Fraction Number of Seconds Fractions (any value from 0 to 0x7FFF)
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TIME_Synchronize(RTC_TypeDef *RTCx, uint32_t ShiftSecond, uint32_t Fraction)
{
  WRITE_REG(RTCx->SHIFTR, ShiftSecond | Fraction);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Date Date
  * @{
  */

/**
  * @brief  Set Year in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Year from binary to BCD format
  * @rmtoll RTC_DR           YT            LL_RTC_DATE_SetYear\n
  *         RTC_DR           YU            LL_RTC_DATE_SetYear
  * @param  RTCx RTC Instance
  * @param  Year Value between Min_Data=0x00 and Max_Data=0x99
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DATE_SetYear(RTC_TypeDef *RTCx, uint32_t Year)
{
  MODIFY_REG(RTCx->DR, (RTC_DR_YT | RTC_DR_YU),
             (((Year & 0xF0U) << (RTC_DR_YT_Pos - 4U)) | ((Year & 0x0FU) << RTC_DR_YU_Pos)));
}

/**
  * @brief  Get Year in BCD format
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Year from BCD to Binary format
  * @rmtoll RTC_DR           YT            LL_RTC_DATE_GetYear\n
  *         RTC_DR           YU            LL_RTC_DATE_GetYear
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x99
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_GetYear(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->DR, (RTC_DR_YT | RTC_DR_YU))) >> RTC_DR_YU_Pos);
}

/**
  * @brief  Set Week day
  * @rmtoll RTC_DR           WDU           LL_RTC_DATE_SetWeekDay
  * @param  RTCx RTC Instance
  * @param  WeekDay This parameter can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DATE_SetWeekDay(RTC_TypeDef *RTCx, uint32_t WeekDay)
{
  MODIFY_REG(RTCx->DR, RTC_DR_WDU, WeekDay << RTC_DR_WDU_Pos);
}

/**
  * @brief  Get Week day
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @rmtoll RTC_DR           WDU           LL_RTC_DATE_GetWeekDay
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_GetWeekDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->DR, RTC_DR_WDU) >> RTC_DR_WDU_Pos);
}

/**
  * @brief  Set Month in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Month from binary to BCD format
  * @rmtoll RTC_DR           MT            LL_RTC_DATE_SetMonth\n
  *         RTC_DR           MU            LL_RTC_DATE_SetMonth
  * @param  RTCx RTC Instance
  * @param  Month This parameter can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DATE_SetMonth(RTC_TypeDef *RTCx, uint32_t Month)
{
  MODIFY_REG(RTCx->DR, (RTC_DR_MT | RTC_DR_MU),
             (((Month & 0xF0U) << (RTC_DR_MT_Pos - 4U)) | ((Month & 0x0FU) << RTC_DR_MU_Pos)));
}

/**
  * @brief  Get Month in BCD format
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Month from BCD to Binary format
  * @rmtoll RTC_DR           MT            LL_RTC_DATE_GetMonth\n
  *         RTC_DR           MU            LL_RTC_DATE_GetMonth
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_GetMonth(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->DR, (RTC_DR_MT | RTC_DR_MU))) >> RTC_DR_MU_Pos);
}

/**
  * @brief  Set Day in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Day from binary to BCD format
  * @rmtoll RTC_DR           DT            LL_RTC_DATE_SetDay\n
  *         RTC_DR           DU            LL_RTC_DATE_SetDay
  * @param  RTCx RTC Instance
  * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DATE_SetDay(RTC_TypeDef *RTCx, uint32_t Day)
{
  MODIFY_REG(RTCx->DR, (RTC_DR_DT | RTC_DR_DU),
             (((Day & 0xF0U) << (RTC_DR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_DR_DU_Pos)));
}

/**
  * @brief  Get Day in BCD format
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Day from BCD to Binary format
  * @rmtoll RTC_DR           DT            LL_RTC_DATE_GetDay\n
  *         RTC_DR           DU            LL_RTC_DATE_GetDay
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x31
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_GetDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->DR, (RTC_DR_DT | RTC_DR_DU))) >> RTC_DR_DU_Pos);
}

/**
  * @brief  Set date (WeekDay, Day, Month and Year) in BCD format
  * @rmtoll RTC_DR           WDU           LL_RTC_DATE_Config\n
  *         RTC_DR           MT            LL_RTC_DATE_Config\n
  *         RTC_DR           MU            LL_RTC_DATE_Config\n
  *         RTC_DR           DT            LL_RTC_DATE_Config\n
  *         RTC_DR           DU            LL_RTC_DATE_Config\n
  *         RTC_DR           YT            LL_RTC_DATE_Config\n
  *         RTC_DR           YU            LL_RTC_DATE_Config
  * @param  RTCx RTC Instance
  * @param  WeekDay This parameter can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
  * @param  Month This parameter can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  * @param  Year Value between Min_Data=0x00 and Max_Data=0x99
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DATE_Config(RTC_TypeDef *RTCx, uint32_t WeekDay, uint32_t Day, uint32_t Month, uint32_t Year)
{
  uint32_t temp;

  temp = (WeekDay << RTC_DR_WDU_Pos)                                                        | \
         (((Year & 0xF0U) << (RTC_DR_YT_Pos - 4U)) | ((Year & 0x0FU) << RTC_DR_YU_Pos))   | \
         (((Month & 0xF0U) << (RTC_DR_MT_Pos - 4U)) | ((Month & 0x0FU) << RTC_DR_MU_Pos)) | \
         (((Day & 0xF0U) << (RTC_DR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_DR_DU_Pos));

  MODIFY_REG(RTCx->DR, (RTC_DR_WDU | RTC_DR_MT | RTC_DR_MU | RTC_DR_DT | RTC_DR_DU | RTC_DR_YT | RTC_DR_YU), temp);
}

/**
  * @brief  Get date (WeekDay, Day, Month and Year) in BCD format
  * @note if shadow mode is disabled (BYPSHAD=0), need to check if RSF flag is set
  *       before reading this bit
  * @note helper macros __LL_RTC_GET_WEEKDAY, __LL_RTC_GET_YEAR, __LL_RTC_GET_MONTH,
  * and __LL_RTC_GET_DAY are available to get independently each parameter.
  * @rmtoll RTC_DR           WDU           LL_RTC_DATE_Get\n
  *         RTC_DR           MT            LL_RTC_DATE_Get\n
  *         RTC_DR           MU            LL_RTC_DATE_Get\n
  *         RTC_DR           DT            LL_RTC_DATE_Get\n
  *         RTC_DR           DU            LL_RTC_DATE_Get\n
  *         RTC_DR           YT            LL_RTC_DATE_Get\n
  *         RTC_DR           YU            LL_RTC_DATE_Get
  * @param  RTCx RTC Instance
  * @retval Combination of WeekDay, Day, Month and Year (Format: 0xWWDDMMYY).
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_Get(RTC_TypeDef *RTCx)
{
  uint32_t temp;

  temp = READ_BIT(RTCx->DR, (RTC_DR_WDU | RTC_DR_MT | RTC_DR_MU | RTC_DR_DT | RTC_DR_DU | RTC_DR_YT | RTC_DR_YU));
  return (uint32_t)((((temp & RTC_DR_WDU) >> RTC_DR_WDU_Pos) << RTC_OFFSET_WEEKDAY) | \
                    (((((temp & RTC_DR_DT) >> RTC_DR_DT_Pos) << 4U) | ((temp & RTC_DR_DU) >> RTC_DR_DU_Pos)) << RTC_OFFSET_DAY)   | \
                    (((((temp & RTC_DR_MT) >> RTC_DR_MT_Pos) << 4U) | ((temp & RTC_DR_MU) >> RTC_DR_MU_Pos)) << RTC_OFFSET_MONTH) | \
                    ((((temp & RTC_DR_YT) >> RTC_DR_YT_Pos) << 4U) | ((temp & RTC_DR_YU) >> RTC_DR_YU_Pos)));
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_ALARMA ALARMA
  * @{
  */

/**
  * @brief  Enable Alarm A
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ALRAE         LL_RTC_ALMA_Enable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRAE);
}

/**
  * @brief  Disable Alarm A
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ALRAE         LL_RTC_ALMA_Disable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRAE);
}

/**
  * @brief  Specify the Alarm A masks.
  * @rmtoll RTC_ALRMAR       MSK4          LL_RTC_ALMA_SetMask\n
  *         RTC_ALRMAR       MSK3          LL_RTC_ALMA_SetMask\n
  *         RTC_ALRMAR       MSK2          LL_RTC_ALMA_SetMask\n
  *         RTC_ALRMAR       MSK1          LL_RTC_ALMA_SetMask
  * @param  RTCx RTC Instance
  * @param  Mask This parameter can be a combination of the following values:
  *         @arg @ref LL_RTC_ALMA_MASK_NONE
  *         @arg @ref LL_RTC_ALMA_MASK_DATEWEEKDAY
  *         @arg @ref LL_RTC_ALMA_MASK_HOURS
  *         @arg @ref LL_RTC_ALMA_MASK_MINUTES
  *         @arg @ref LL_RTC_ALMA_MASK_SECONDS
  *         @arg @ref LL_RTC_ALMA_MASK_ALL
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  MODIFY_REG(RTCx->ALRMAR, RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1, Mask);
}

/**
  * @brief  Get the Alarm A masks.
  * @rmtoll RTC_ALRMAR       MSK4          LL_RTC_ALMA_GetMask\n
  *         RTC_ALRMAR       MSK3          LL_RTC_ALMA_GetMask\n
  *         RTC_ALRMAR       MSK2          LL_RTC_ALMA_GetMask\n
  *         RTC_ALRMAR       MSK1          LL_RTC_ALMA_GetMask
  * @param  RTCx RTC Instance
  * @retval Returned value can be can be a combination of the following values:
  *         @arg @ref LL_RTC_ALMA_MASK_NONE
  *         @arg @ref LL_RTC_ALMA_MASK_DATEWEEKDAY
  *         @arg @ref LL_RTC_ALMA_MASK_HOURS
  *         @arg @ref LL_RTC_ALMA_MASK_MINUTES
  *         @arg @ref LL_RTC_ALMA_MASK_SECONDS
  *         @arg @ref LL_RTC_ALMA_MASK_ALL
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetMask(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMAR, RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1));
}

/**
  * @brief  Enable AlarmA Week day selection (DU[3:0] represents the week day. DT[1:0] is do not care)
  * @rmtoll RTC_ALRMAR       WDSEL         LL_RTC_ALMA_EnableWeekday
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_EnableWeekday(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->ALRMAR, RTC_ALRMAR_WDSEL);
}

/**
  * @brief  Disable AlarmA Week day selection (DU[3:0] represents the date )
  * @rmtoll RTC_ALRMAR       WDSEL         LL_RTC_ALMA_DisableWeekday
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_DisableWeekday(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->ALRMAR, RTC_ALRMAR_WDSEL);
}

/**
  * @brief  Set ALARM A Day in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Day from binary to BCD format
  * @rmtoll RTC_ALRMAR       DT            LL_RTC_ALMA_SetDay\n
  *         RTC_ALRMAR       DU            LL_RTC_ALMA_SetDay
  * @param  RTCx RTC Instance
  * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetDay(RTC_TypeDef *RTCx, uint32_t Day)
{
  MODIFY_REG(RTCx->ALRMAR, (RTC_ALRMAR_DT | RTC_ALRMAR_DU),
             (((Day & 0xF0U) << (RTC_ALRMAR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_ALRMAR_DU_Pos)));
}

/**
  * @brief  Get ALARM A Day in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Day from BCD to Binary format
  * @rmtoll RTC_ALRMAR       DT            LL_RTC_ALMA_GetDay\n
  *         RTC_ALRMAR       DU            LL_RTC_ALMA_GetDay
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x31
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->ALRMAR, (RTC_ALRMAR_DT | RTC_ALRMAR_DU))) >> RTC_ALRMAR_DU_Pos);
}

/**
  * @brief  Set ALARM A Weekday
  * @rmtoll RTC_ALRMAR       DU            LL_RTC_ALMA_SetWeekDay
  * @param  RTCx RTC Instance
  * @param  WeekDay This parameter can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetWeekDay(RTC_TypeDef *RTCx, uint32_t WeekDay)
{
  MODIFY_REG(RTCx->ALRMAR, RTC_ALRMAR_DU, WeekDay << RTC_ALRMAR_DU_Pos);
}

/**
  * @brief  Get ALARM A Weekday
  * @rmtoll RTC_ALRMAR       DU            LL_RTC_ALMA_GetWeekDay
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetWeekDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMAR, RTC_ALRMAR_DU) >> RTC_ALRMAR_DU_Pos);
}

/**
  * @brief  Set Alarm A time format (AM/24-hour or PM notation)
  * @rmtoll RTC_ALRMAR       PM            LL_RTC_ALMA_SetTimeFormat
  * @param  RTCx RTC Instance
  * @param  TimeFormat This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALMA_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALMA_TIME_FORMAT_PM
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetTimeFormat(RTC_TypeDef *RTCx, uint32_t TimeFormat)
{
  MODIFY_REG(RTCx->ALRMAR, RTC_ALRMAR_PM, TimeFormat);
}

/**
  * @brief  Get Alarm A time format (AM or PM notation)
  * @rmtoll RTC_ALRMAR       PM            LL_RTC_ALMA_GetTimeFormat
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_ALMA_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALMA_TIME_FORMAT_PM
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetTimeFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMAR, RTC_ALRMAR_PM));
}

/**
  * @brief  Set ALARM A Hours in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Hours from binary to BCD format
  * @rmtoll RTC_ALRMAR       HT            LL_RTC_ALMA_SetHour\n
  *         RTC_ALRMAR       HU            LL_RTC_ALMA_SetHour
  * @param  RTCx RTC Instance
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetHour(RTC_TypeDef *RTCx, uint32_t Hours)
{
  MODIFY_REG(RTCx->ALRMAR, (RTC_ALRMAR_HT | RTC_ALRMAR_HU),
             (((Hours & 0xF0U) << (RTC_ALRMAR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMAR_HU_Pos)));
}

/**
  * @brief  Get ALARM A Hours in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Hours from BCD to Binary format
  * @rmtoll RTC_ALRMAR       HT            LL_RTC_ALMA_GetHour\n
  *         RTC_ALRMAR       HU            LL_RTC_ALMA_GetHour
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetHour(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->ALRMAR, (RTC_ALRMAR_HT | RTC_ALRMAR_HU))) >> RTC_ALRMAR_HU_Pos);
}

/**
  * @brief  Set ALARM A Minutes in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Minutes from binary to BCD format
  * @rmtoll RTC_ALRMAR       MNT           LL_RTC_ALMA_SetMinute\n
  *         RTC_ALRMAR       MNU           LL_RTC_ALMA_SetMinute
  * @param  RTCx RTC Instance
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetMinute(RTC_TypeDef *RTCx, uint32_t Minutes)
{
  MODIFY_REG(RTCx->ALRMAR, (RTC_ALRMAR_MNT | RTC_ALRMAR_MNU),
             (((Minutes & 0xF0U) << (RTC_ALRMAR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMAR_MNU_Pos)));
}

/**
  * @brief  Get ALARM A Minutes in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Minutes from BCD to Binary format
  * @rmtoll RTC_ALRMAR       MNT           LL_RTC_ALMA_GetMinute\n
  *         RTC_ALRMAR       MNU           LL_RTC_ALMA_GetMinute
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetMinute(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->ALRMAR, (RTC_ALRMAR_MNT | RTC_ALRMAR_MNU))) >> RTC_ALRMAR_MNU_Pos);
}

/**
  * @brief  Set ALARM A Seconds in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Seconds from binary to BCD format
  * @rmtoll RTC_ALRMAR       ST            LL_RTC_ALMA_SetSecond\n
  *         RTC_ALRMAR       SU            LL_RTC_ALMA_SetSecond
  * @param  RTCx RTC Instance
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetSecond(RTC_TypeDef *RTCx, uint32_t Seconds)
{
  MODIFY_REG(RTCx->ALRMAR, (RTC_ALRMAR_ST | RTC_ALRMAR_SU),
             (((Seconds & 0xF0U) << (RTC_ALRMAR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMAR_SU_Pos)));
}

/**
  * @brief  Get ALARM A Seconds in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Seconds from BCD to Binary format
  * @rmtoll RTC_ALRMAR       ST            LL_RTC_ALMA_GetSecond\n
  *         RTC_ALRMAR       SU            LL_RTC_ALMA_GetSecond
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->ALRMAR, (RTC_ALRMAR_ST | RTC_ALRMAR_SU))) >> RTC_ALRMAR_SU_Pos);
}

/**
  * @brief  Set Alarm A Time (hour, minute and second) in BCD format
  * @rmtoll RTC_ALRMAR       PM            LL_RTC_ALMA_ConfigTime\n
  *         RTC_ALRMAR       HT            LL_RTC_ALMA_ConfigTime\n
  *         RTC_ALRMAR       HU            LL_RTC_ALMA_ConfigTime\n
  *         RTC_ALRMAR       MNT           LL_RTC_ALMA_ConfigTime\n
  *         RTC_ALRMAR       MNU           LL_RTC_ALMA_ConfigTime\n
  *         RTC_ALRMAR       ST            LL_RTC_ALMA_ConfigTime\n
  *         RTC_ALRMAR       SU            LL_RTC_ALMA_ConfigTime
  * @param  RTCx RTC Instance
  * @param  Format12_24 This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALMA_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALMA_TIME_FORMAT_PM
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_ConfigTime(RTC_TypeDef *RTCx, uint32_t Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
{
  uint32_t temp;

  temp = Format12_24 | (((Hours & 0xF0U) << (RTC_ALRMAR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMAR_HU_Pos))    | \
         (((Minutes & 0xF0U) << (RTC_ALRMAR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMAR_MNU_Pos)) | \
         (((Seconds & 0xF0U) << (RTC_ALRMAR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMAR_SU_Pos));

  MODIFY_REG(RTCx->ALRMAR, RTC_ALRMAR_PM | RTC_ALRMAR_HT | RTC_ALRMAR_HU | RTC_ALRMAR_MNT | RTC_ALRMAR_MNU | RTC_ALRMAR_ST | RTC_ALRMAR_SU, temp);
}

/**
  * @brief  Get Alarm B Time (hour, minute and second) in BCD format
  * @note helper macros __LL_RTC_GET_HOUR, __LL_RTC_GET_MINUTE and __LL_RTC_GET_SECOND
  * are available to get independently each parameter.
  * @rmtoll RTC_ALRMAR       HT            LL_RTC_ALMA_GetTime\n
  *         RTC_ALRMAR       HU            LL_RTC_ALMA_GetTime\n
  *         RTC_ALRMAR       MNT           LL_RTC_ALMA_GetTime\n
  *         RTC_ALRMAR       MNU           LL_RTC_ALMA_GetTime\n
  *         RTC_ALRMAR       ST            LL_RTC_ALMA_GetTime\n
  *         RTC_ALRMAR       SU            LL_RTC_ALMA_GetTime
  * @param  RTCx RTC Instance
  * @retval Combination of hours, minutes and seconds.
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetTime(RTC_TypeDef *RTCx)
{
  return (uint32_t)((LL_RTC_ALMA_GetHour(RTCx) << RTC_OFFSET_HOUR) | (LL_RTC_ALMA_GetMinute(RTCx) << RTC_OFFSET_MINUTE) | LL_RTC_ALMA_GetSecond(RTCx));
}

/**
  * @brief  Set Alarm A Mask the most-significant bits starting at this bit
  * @note This register can be written only when ALRAE is reset in RTC_CR register,
  *       or in initialization mode.
  * @rmtoll RTC_ALRMASSR     MASKSS        LL_RTC_ALMA_SetSubSecondMask
  * @param  RTCx RTC Instance
  * @param  Mask Value between Min_Data=0x00 and Max_Data=0xF
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetSubSecondMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  MODIFY_REG(RTCx->ALRMASSR, RTC_ALRMASSR_MASKSS, Mask << RTC_ALRMASSR_MASKSS_Pos);
}

/**
  * @brief  Get Alarm A Mask the most-significant bits starting at this bit
  * @rmtoll RTC_ALRMASSR     MASKSS        LL_RTC_ALMA_GetSubSecondMask
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xF
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetSubSecondMask(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMASSR, RTC_ALRMASSR_MASKSS) >> RTC_ALRMASSR_MASKSS_Pos);
}

/**
  * @brief  Set Alarm A Sub seconds value
  * @rmtoll RCT_ALRMASSR     SS            LL_RTC_ALMA_SetSubSecond
  * @param  RTCx RTC Instance
  * @param  Subsecond Value between Min_Data=0x00 and Max_Data=0x7FFF
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMA_SetSubSecond(RTC_TypeDef *RTCx, uint32_t Subsecond)
{
  MODIFY_REG(RTCx->ALRMASSR, RTC_ALRMASSR_SS, Subsecond);
}

/**
  * @brief  Get Alarm A Sub seconds value
  * @rmtoll RCT_ALRMASSR     SS            LL_RTC_ALMA_GetSubSecond
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x7FFF
  */
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMASSR, RTC_ALRMASSR_SS));
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_ALARMB ALARMB
  * @{
  */

/**
  * @brief  Enable Alarm B
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ALRBE         LL_RTC_ALMB_Enable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRBE);
}

/**
  * @brief  Disable Alarm B
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ALRBE         LL_RTC_ALMB_Disable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRBE);
}

/**
  * @brief  Specify the Alarm B masks.
  * @rmtoll RTC_ALRMBR       MSK4          LL_RTC_ALMB_SetMask\n
  *         RTC_ALRMBR       MSK3          LL_RTC_ALMB_SetMask\n
  *         RTC_ALRMBR       MSK2          LL_RTC_ALMB_SetMask\n
  *         RTC_ALRMBR       MSK1          LL_RTC_ALMB_SetMask
  * @param  RTCx RTC Instance
  * @param  Mask This parameter can be a combination of the following values:
  *         @arg @ref LL_RTC_ALMB_MASK_NONE
  *         @arg @ref LL_RTC_ALMB_MASK_DATEWEEKDAY
  *         @arg @ref LL_RTC_ALMB_MASK_HOURS
  *         @arg @ref LL_RTC_ALMB_MASK_MINUTES
  *         @arg @ref LL_RTC_ALMB_MASK_SECONDS
  *         @arg @ref LL_RTC_ALMB_MASK_ALL
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  MODIFY_REG(RTCx->ALRMBR, RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1, Mask);
}

/**
  * @brief  Get the Alarm B masks.
  * @rmtoll RTC_ALRMBR       MSK4          LL_RTC_ALMB_GetMask\n
  *         RTC_ALRMBR       MSK3          LL_RTC_ALMB_GetMask\n
  *         RTC_ALRMBR       MSK2          LL_RTC_ALMB_GetMask\n
  *         RTC_ALRMBR       MSK1          LL_RTC_ALMB_GetMask
  * @param  RTCx RTC Instance
  * @retval Returned value can be can be a combination of the following values:
  *         @arg @ref LL_RTC_ALMB_MASK_NONE
  *         @arg @ref LL_RTC_ALMB_MASK_DATEWEEKDAY
  *         @arg @ref LL_RTC_ALMB_MASK_HOURS
  *         @arg @ref LL_RTC_ALMB_MASK_MINUTES
  *         @arg @ref LL_RTC_ALMB_MASK_SECONDS
  *         @arg @ref LL_RTC_ALMB_MASK_ALL
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetMask(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBR, RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1));
}

/**
  * @brief  Enable AlarmB Week day selection (DU[3:0] represents the week day. DT[1:0] is do not care)
  * @rmtoll RTC_ALRMBR       WDSEL         LL_RTC_ALMB_EnableWeekday
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_EnableWeekday(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->ALRMBR, RTC_ALRMBR_WDSEL);
}

/**
  * @brief  Disable AlarmB Week day selection (DU[3:0] represents the date )
  * @rmtoll RTC_ALRMBR       WDSEL         LL_RTC_ALMB_DisableWeekday
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_DisableWeekday(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->ALRMBR, RTC_ALRMBR_WDSEL);
}

/**
  * @brief  Set ALARM B Day in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Day from binary to BCD format
  * @rmtoll RTC_ALRMBR       DT            LL_RTC_ALMB_SetDay\n
  *         RTC_ALRMBR       DU            LL_RTC_ALMB_SetDay
  * @param  RTCx RTC Instance
  * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetDay(RTC_TypeDef *RTCx, uint32_t Day)
{
  MODIFY_REG(RTCx->ALRMBR, (RTC_ALRMBR_DT | RTC_ALRMBR_DU),
             (((Day & 0xF0U) << (RTC_ALRMBR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_ALRMBR_DU_Pos)));
}

/**
  * @brief  Get ALARM B Day in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Day from BCD to Binary format
  * @rmtoll RTC_ALRMBR       DT            LL_RTC_ALMB_GetDay\n
  *         RTC_ALRMBR       DU            LL_RTC_ALMB_GetDay
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x31
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->ALRMBR, (RTC_ALRMBR_DT | RTC_ALRMBR_DU))) >> RTC_ALRMBR_DU_Pos);
}

/**
  * @brief  Set ALARM B Weekday
  * @rmtoll RTC_ALRMBR       DU            LL_RTC_ALMB_SetWeekDay
  * @param  RTCx RTC Instance
  * @param  WeekDay This parameter can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetWeekDay(RTC_TypeDef *RTCx, uint32_t WeekDay)
{
  MODIFY_REG(RTCx->ALRMBR, RTC_ALRMBR_DU, WeekDay << RTC_ALRMBR_DU_Pos);
}

/**
  * @brief  Get ALARM B Weekday
  * @rmtoll RTC_ALRMBR       DU            LL_RTC_ALMB_GetWeekDay
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetWeekDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBR, RTC_ALRMBR_DU) >> RTC_ALRMBR_DU_Pos);
}

/**
  * @brief  Set ALARM B time format (AM/24-hour or PM notation)
  * @rmtoll RTC_ALRMBR       PM            LL_RTC_ALMB_SetTimeFormat
  * @param  RTCx RTC Instance
  * @param  TimeFormat This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALMB_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALMB_TIME_FORMAT_PM
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetTimeFormat(RTC_TypeDef *RTCx, uint32_t TimeFormat)
{
  MODIFY_REG(RTCx->ALRMBR, RTC_ALRMBR_PM, TimeFormat);
}

/**
  * @brief  Get ALARM B time format (AM or PM notation)
  * @rmtoll RTC_ALRMBR       PM            LL_RTC_ALMB_GetTimeFormat
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_ALMB_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALMB_TIME_FORMAT_PM
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetTimeFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBR, RTC_ALRMBR_PM));
}

/**
  * @brief  Set ALARM B Hours in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Hours from binary to BCD format
  * @rmtoll RTC_ALRMBR       HT            LL_RTC_ALMB_SetHour\n
  *         RTC_ALRMBR       HU            LL_RTC_ALMB_SetHour
  * @param  RTCx RTC Instance
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetHour(RTC_TypeDef *RTCx, uint32_t Hours)
{
  MODIFY_REG(RTCx->ALRMBR, (RTC_ALRMBR_HT | RTC_ALRMBR_HU),
             (((Hours & 0xF0U) << (RTC_ALRMBR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMBR_HU_Pos)));
}

/**
  * @brief  Get ALARM B Hours in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Hours from BCD to Binary format
  * @rmtoll RTC_ALRMBR       HT            LL_RTC_ALMB_GetHour\n
  *         RTC_ALRMBR       HU            LL_RTC_ALMB_GetHour
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetHour(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->ALRMBR, (RTC_ALRMBR_HT | RTC_ALRMBR_HU))) >> RTC_ALRMBR_HU_Pos);
}

/**
  * @brief  Set ALARM B Minutes in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Minutes from binary to BCD format
  * @rmtoll RTC_ALRMBR       MNT           LL_RTC_ALMB_SetMinute\n
  *         RTC_ALRMBR       MNU           LL_RTC_ALMB_SetMinute
  * @param  RTCx RTC Instance
  * @param  Minutes between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetMinute(RTC_TypeDef *RTCx, uint32_t Minutes)
{
  MODIFY_REG(RTCx->ALRMBR, (RTC_ALRMBR_MNT | RTC_ALRMBR_MNU),
             (((Minutes & 0xF0U) << (RTC_ALRMBR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMBR_MNU_Pos)));
}

/**
  * @brief  Get ALARM B Minutes in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Minutes from BCD to Binary format
  * @rmtoll RTC_ALRMBR       MNT           LL_RTC_ALMB_GetMinute\n
  *         RTC_ALRMBR       MNU           LL_RTC_ALMB_GetMinute
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetMinute(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->ALRMBR, (RTC_ALRMBR_MNT | RTC_ALRMBR_MNU))) >> RTC_ALRMBR_MNU_Pos);
}

/**
  * @brief  Set ALARM B Seconds in BCD format
  * @note helper macro __LL_RTC_CONVERT_BIN2BCD is available to convert Seconds from binary to BCD format
  * @rmtoll RTC_ALRMBR       ST            LL_RTC_ALMB_SetSecond\n
  *         RTC_ALRMBR       SU            LL_RTC_ALMB_SetSecond
  * @param  RTCx RTC Instance
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetSecond(RTC_TypeDef *RTCx, uint32_t Seconds)
{
  MODIFY_REG(RTCx->ALRMBR, (RTC_ALRMBR_ST | RTC_ALRMBR_SU),
             (((Seconds & 0xF0U) << (RTC_ALRMBR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMBR_SU_Pos)));
}

/**
  * @brief  Get ALARM B Seconds in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Seconds from BCD to Binary format
  * @rmtoll RTC_ALRMBR       ST            LL_RTC_ALMB_GetSecond\n
  *         RTC_ALRMBR       SU            LL_RTC_ALMB_GetSecond
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->ALRMBR, (RTC_ALRMBR_ST | RTC_ALRMBR_SU))) >> RTC_ALRMBR_SU_Pos);
}

/**
  * @brief  Set Alarm B Time (hour, minute and second) in BCD format
  * @rmtoll RTC_ALRMBR       PM            LL_RTC_ALMB_ConfigTime\n
  *         RTC_ALRMBR       HT            LL_RTC_ALMB_ConfigTime\n
  *         RTC_ALRMBR       HU            LL_RTC_ALMB_ConfigTime\n
  *         RTC_ALRMBR       MNT           LL_RTC_ALMB_ConfigTime\n
  *         RTC_ALRMBR       MNU           LL_RTC_ALMB_ConfigTime\n
  *         RTC_ALRMBR       ST            LL_RTC_ALMB_ConfigTime\n
  *         RTC_ALRMBR       SU            LL_RTC_ALMB_ConfigTime
  * @param  RTCx RTC Instance
  * @param  Format12_24 This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALMB_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALMB_TIME_FORMAT_PM
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_ConfigTime(RTC_TypeDef *RTCx, uint32_t Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
{
  uint32_t temp;

  temp = Format12_24 | (((Hours & 0xF0U) << (RTC_ALRMBR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMBR_HU_Pos))    | \
         (((Minutes & 0xF0U) << (RTC_ALRMBR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMBR_MNU_Pos)) | \
         (((Seconds & 0xF0U) << (RTC_ALRMBR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMBR_SU_Pos));

  MODIFY_REG(RTCx->ALRMBR, RTC_ALRMBR_PM | RTC_ALRMBR_HT | RTC_ALRMBR_HU | RTC_ALRMBR_MNT | RTC_ALRMBR_MNU | RTC_ALRMBR_ST | RTC_ALRMBR_SU, temp);
}

/**
  * @brief  Get Alarm B Time (hour, minute and second) in BCD format
  * @note helper macros __LL_RTC_GET_HOUR, __LL_RTC_GET_MINUTE and __LL_RTC_GET_SECOND
  * are available to get independently each parameter.
  * @rmtoll RTC_ALRMBR       HT            LL_RTC_ALMB_GetTime\n
  *         RTC_ALRMBR       HU            LL_RTC_ALMB_GetTime\n
  *         RTC_ALRMBR       MNT           LL_RTC_ALMB_GetTime\n
  *         RTC_ALRMBR       MNU           LL_RTC_ALMB_GetTime\n
  *         RTC_ALRMBR       ST            LL_RTC_ALMB_GetTime\n
  *         RTC_ALRMBR       SU            LL_RTC_ALMB_GetTime
  * @param  RTCx RTC Instance
  * @retval Combination of hours, minutes and seconds.
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetTime(RTC_TypeDef *RTCx)
{
  return (uint32_t)((LL_RTC_ALMB_GetHour(RTCx) << RTC_OFFSET_HOUR) | (LL_RTC_ALMB_GetMinute(RTCx) << RTC_OFFSET_MINUTE) | LL_RTC_ALMB_GetSecond(RTCx));
}

/**
  * @brief  Set Alarm B Mask the most-significant bits starting at this bit
  * @note This register can be written only when ALRBE is reset in RTC_CR register,
  *       or in initialization mode.
  * @rmtoll RTC_ALRMBSSR     MASKSS        LL_RTC_ALMB_SetSubSecondMask
  * @param  RTCx RTC Instance
  * @param  Mask Value between Min_Data=0x00 and Max_Data=0xF
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetSubSecondMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  MODIFY_REG(RTCx->ALRMBSSR, RTC_ALRMBSSR_MASKSS, Mask << RTC_ALRMBSSR_MASKSS_Pos);
}

/**
  * @brief  Get Alarm B Mask the most-significant bits starting at this bit
  * @rmtoll RTC_ALRMBSSR     MASKSS        LL_RTC_ALMB_GetSubSecondMask
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xF
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetSubSecondMask(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBSSR, RTC_ALRMBSSR_MASKSS)  >> RTC_ALRMBSSR_MASKSS_Pos);
}

/**
  * @brief  Set Alarm B Sub seconds value
  * @rmtoll RTC_ALRMBSSR     SS            LL_RTC_ALMB_SetSubSecond
  * @param  RTCx RTC Instance
  * @param  Subsecond Value between Min_Data=0x00 and Max_Data=0x7FFF
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ALMB_SetSubSecond(RTC_TypeDef *RTCx, uint32_t Subsecond)
{
  MODIFY_REG(RTCx->ALRMBSSR, RTC_ALRMBSSR_SS, Subsecond);
}

/**
  * @brief  Get Alarm B Sub seconds value
  * @rmtoll RTC_ALRMBSSR     SS            LL_RTC_ALMB_GetSubSecond
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x7FFF
  */
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBSSR, RTC_ALRMBSSR_SS));
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Timestamp Timestamp
  * @{
  */

/**
  * @brief  Enable internal event timestamp
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ITSE          LL_RTC_TS_EnableInternalEvent
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TS_EnableInternalEvent(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ITSE);
}

/**
  * @brief  Disable internal event timestamp
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ITSE          LL_RTC_TS_DisableInternalEvent
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TS_DisableInternalEvent(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ITSE);
}

/**
  * @brief  Enable Timestamp
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           TSE           LL_RTC_TS_Enable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TS_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TSE);
}

/**
  * @brief  Disable Timestamp
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           TSE           LL_RTC_TS_Disable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TS_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TSE);
}

/**
  * @brief  Set Time-stamp event active edge
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note TSE must be reset when TSEDGE is changed to avoid unwanted TSF setting
  * @rmtoll RTC_CR           TSEDGE        LL_RTC_TS_SetActiveEdge
  * @param  RTCx RTC Instance
  * @param  Edge This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TIMESTAMP_EDGE_RISING
  *         @arg @ref LL_RTC_TIMESTAMP_EDGE_FALLING
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TS_SetActiveEdge(RTC_TypeDef *RTCx, uint32_t Edge)
{
  MODIFY_REG(RTCx->CR, RTC_CR_TSEDGE, Edge);
}

/**
  * @brief  Get Time-stamp event active edge
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           TSEDGE        LL_RTC_TS_GetActiveEdge
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_TIMESTAMP_EDGE_RISING
  *         @arg @ref LL_RTC_TIMESTAMP_EDGE_FALLING
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetActiveEdge(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_TSEDGE));
}

/**
  * @brief  Get Timestamp AM/PM notation (AM or 24-hour format)
  * @rmtoll RTC_TSTR         PM            LL_RTC_TS_GetTimeFormat
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_TS_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_TS_TIME_FORMAT_PM
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetTimeFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR, RTC_TSTR_PM));
}

/**
  * @brief  Get Timestamp Hours in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Hours from BCD to Binary format
  * @rmtoll RTC_TSTR         HT            LL_RTC_TS_GetHour\n
  *         RTC_TSTR         HU            LL_RTC_TS_GetHour
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetHour(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR, RTC_TSTR_HT | RTC_TSTR_HU) >> RTC_TSTR_HU_Pos);
}

/**
  * @brief  Get Timestamp Minutes in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Minutes from BCD to Binary format
  * @rmtoll RTC_TSTR         MNT           LL_RTC_TS_GetMinute\n
  *         RTC_TSTR         MNU           LL_RTC_TS_GetMinute
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetMinute(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR, RTC_TSTR_MNT | RTC_TSTR_MNU) >> RTC_TSTR_MNU_Pos);
}

/**
  * @brief  Get Timestamp Seconds in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Seconds from BCD to Binary format
  * @rmtoll RTC_TSTR         ST            LL_RTC_TS_GetSecond\n
  *         RTC_TSTR         SU            LL_RTC_TS_GetSecond
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR, RTC_TSTR_ST | RTC_TSTR_SU));
}

/**
  * @brief  Get Timestamp time (hour, minute and second) in BCD format
  * @note helper macros __LL_RTC_GET_HOUR, __LL_RTC_GET_MINUTE and __LL_RTC_GET_SECOND
  * are available to get independently each parameter.
  * @rmtoll RTC_TSTR         HT            LL_RTC_TS_GetTime\n
  *         RTC_TSTR         HU            LL_RTC_TS_GetTime\n
  *         RTC_TSTR         MNT           LL_RTC_TS_GetTime\n
  *         RTC_TSTR         MNU           LL_RTC_TS_GetTime\n
  *         RTC_TSTR         ST            LL_RTC_TS_GetTime\n
  *         RTC_TSTR         SU            LL_RTC_TS_GetTime
  * @param  RTCx RTC Instance
  * @retval Combination of hours, minutes and seconds.
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetTime(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR,
                             RTC_TSTR_HT | RTC_TSTR_HU | RTC_TSTR_MNT | RTC_TSTR_MNU | RTC_TSTR_ST | RTC_TSTR_SU));
}

/**
  * @brief  Get Timestamp Week day
  * @rmtoll RTC_TSDR         WDU           LL_RTC_TS_GetWeekDay
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetWeekDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSDR, RTC_TSDR_WDU) >> RTC_TSDR_WDU_Pos);
}

/**
  * @brief  Get Timestamp Month in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Month from BCD to Binary format
  * @rmtoll RTC_TSDR         MT            LL_RTC_TS_GetMonth\n
  *         RTC_TSDR         MU            LL_RTC_TS_GetMonth
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetMonth(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSDR, RTC_TSDR_MT | RTC_TSDR_MU) >> RTC_TSDR_MU_Pos);
}

/**
  * @brief  Get Timestamp Day in BCD format
  * @note helper macro __LL_RTC_CONVERT_BCD2BIN is available to convert Day from BCD to Binary format
  * @rmtoll RTC_TSDR         DT            LL_RTC_TS_GetDay\n
  *         RTC_TSDR         DU            LL_RTC_TS_GetDay
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x31
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSDR, RTC_TSDR_DT | RTC_TSDR_DU));
}

/**
  * @brief  Get Timestamp date (WeekDay, Day and Month) in BCD format
  * @note helper macros __LL_RTC_GET_WEEKDAY, __LL_RTC_GET_MONTH,
  * and __LL_RTC_GET_DAY are available to get independently each parameter.
  * @rmtoll RTC_TSDR         WDU           LL_RTC_TS_GetDate\n
  *         RTC_TSDR         MT            LL_RTC_TS_GetDate\n
  *         RTC_TSDR         MU            LL_RTC_TS_GetDate\n
  *         RTC_TSDR         DT            LL_RTC_TS_GetDate\n
  *         RTC_TSDR         DU            LL_RTC_TS_GetDate
  * @param  RTCx RTC Instance
  * @retval Combination of Weekday, Day and Month
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetDate(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSDR, RTC_TSDR_WDU | RTC_TSDR_MT | RTC_TSDR_MU | RTC_TSDR_DT | RTC_TSDR_DU));
}

/**
  * @brief  Get time-stamp sub second value
  * @rmtoll RTC_TSSSR         SS            LL_RTC_TS_GetSubSecond
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t LL_RTC_TS_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSSSR, RTC_TSSSR_SS));
}

/**
  * @brief  Activate timestamp on tamper detection event
  * @rmtoll RTC_CR       TAMPTS        LL_RTC_TS_EnableOnTamper
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TS_EnableOnTamper(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TAMPTS);
}

/**
  * @brief  Disable timestamp on tamper detection event
  * @rmtoll RTC_CR       TAMPTS        LL_RTC_TS_DisableOnTamper
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TS_DisableOnTamper(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TAMPTS);
}


/**
  * @}
  */

/** @defgroup RTC_LL_EF_Tamper Tamper
  * @{
  */

/**
  * @brief  Enable TAMPx input detection
  * @rmtoll TAMP_CR1       TAMP1E        LL_RTC_TAMPER_Enable\n
  *         TAMP_CR1       TAMP2E...     LL_RTC_TAMPER_Enable\n
  * @param  RTCx RTC Instance
  * @param  Tamper This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_TAMPER
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_Enable(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->CR1, Tamper);
}

/**
  * @brief  Clear TAMPx input detection
  * @rmtoll TAMP_CR1       TAMP1E         LL_RTC_TAMPER_Disable\n
  *         TAMP_CR1       TAMP2E...      LL_RTC_TAMPER_Disable
  * @param  RTCx RTC Instance
  * @param  Tamper This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_TAMPER
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_Disable(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->CR1, Tamper);
}

/**
  * @brief  Enable Tamper mask flag
  * @note Associated Tamper IT must not enabled when tamper mask is set.
  * @rmtoll TAMP_CR2       TAMP1MF       LL_RTC_TAMPER_EnableMask\n
  *         TAMP_CR2       TAMP2MF...    LL_RTC_TAMPER_EnableMask
  * @param  RTCx RTC Instance
  * @param  Mask This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_TAMPER_MASK
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_EnableMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->CR2, Mask);
}

/**
  * @brief  Disable Tamper mask flag
  * @rmtoll TAMP_CR2       TAMP1MF       LL_RTC_TAMPER_DisableMask\n
  *         TAMP_CR2       TAMP2MF...    LL_RTC_TAMPER_DisableMask
  * @param  RTCx RTC Instance
  * @param  Mask This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_TAMPER_MASK
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_DisableMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->CR2, Mask);
}

/**
  * @brief  Enable backup register erase after Tamper event detection
  * @rmtoll TAMP_CR2       TAMP1NOERASE     LL_RTC_TAMPER_EnableEraseBKP\n
  *         TAMP_CR2       TAMP2NOERASE...  LL_RTC_TAMPER_EnableEraseBKP
  * @param  RTCx RTC Instance
  * @param  Tamper This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_TAMPER_NOERASE
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_EnableEraseBKP(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->CR2, Tamper);
}

/**
  * @brief  Disable backup register erase after Tamper event detection
  * @rmtoll TAMP_CR2       TAMP1NOERASE     LL_RTC_TAMPER_DisableEraseBKP\n
  *         TAMP_CR2       TAMP2NOERASE...  LL_RTC_TAMPER_DisableEraseBKP
  * @param  RTCx RTC Instance
  * @param  Tamper This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_TAMPER_NOERASE
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_DisableEraseBKP(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->CR2, Tamper);
}

/**
  * @brief  Disable RTC_TAMPx pull-up disable (Disable precharge of RTC_TAMPx pins)
  * @rmtoll TAMP_FLTCR       TAMPPUDIS     LL_RTC_TAMPER_DisablePullUp
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_DisablePullUp(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->FLTCR, TAMP_FLTCR_TAMPPUDIS);
}

/**
  * @brief  Enable RTC_TAMPx pull-up disable ( Precharge RTC_TAMPx pins before sampling)
  * @rmtoll TAMP_FLTCR       TAMPPUDIS     LL_RTC_TAMPER_EnablePullUp
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_EnablePullUp(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->FLTCR, TAMP_FLTCR_TAMPPUDIS);
}

/**
  * @brief  Set RTC_TAMPx precharge duration
  * @rmtoll TAMP_FLTCR       TAMPPRCH      LL_RTC_TAMPER_SetPrecharge
  * @param  RTCx RTC Instance
  * @param  Duration This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TAMPER_DURATION_1RTCCLK
  *         @arg @ref LL_RTC_TAMPER_DURATION_2RTCCLK
  *         @arg @ref LL_RTC_TAMPER_DURATION_4RTCCLK
  *         @arg @ref LL_RTC_TAMPER_DURATION_8RTCCLK
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_SetPrecharge(RTC_TypeDef *RTCx, uint32_t Duration)
{
  UNUSED(RTCx);
  MODIFY_REG(TAMP->FLTCR, TAMP_FLTCR_TAMPPRCH, Duration);
}

/**
  * @brief  Get RTC_TAMPx precharge duration
  * @rmtoll TAMP_FLTCR       TAMPPRCH      LL_RTC_TAMPER_GetPrecharge
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_TAMPER_DURATION_1RTCCLK
  *         @arg @ref LL_RTC_TAMPER_DURATION_2RTCCLK
  *         @arg @ref LL_RTC_TAMPER_DURATION_4RTCCLK
  *         @arg @ref LL_RTC_TAMPER_DURATION_8RTCCLK
  */
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetPrecharge(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return (uint32_t)(READ_BIT(TAMP->FLTCR, TAMP_FLTCR_TAMPPRCH));
}

/**
  * @brief  Set RTC_TAMPx filter count
  * @rmtoll TAMP_FLTCR       TAMPFLT       LL_RTC_TAMPER_SetFilterCount
  * @param  RTCx RTC Instance
  * @param  FilterCount This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TAMPER_FILTER_DISABLE
  *         @arg @ref LL_RTC_TAMPER_FILTER_2SAMPLE
  *         @arg @ref LL_RTC_TAMPER_FILTER_4SAMPLE
  *         @arg @ref LL_RTC_TAMPER_FILTER_8SAMPLE
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_SetFilterCount(RTC_TypeDef *RTCx, uint32_t FilterCount)
{
  UNUSED(RTCx);
  MODIFY_REG(TAMP->FLTCR, TAMP_FLTCR_TAMPFLT, FilterCount);
}

/**
  * @brief  Get RTC_TAMPx filter count
  * @rmtoll TAMP_FLTCR       TAMPFLT       LL_RTC_TAMPER_GetFilterCount
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_TAMPER_FILTER_DISABLE
  *         @arg @ref LL_RTC_TAMPER_FILTER_2SAMPLE
  *         @arg @ref LL_RTC_TAMPER_FILTER_4SAMPLE
  *         @arg @ref LL_RTC_TAMPER_FILTER_8SAMPLE
  */
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetFilterCount(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return (uint32_t)(READ_BIT(TAMP->FLTCR, TAMP_FLTCR_TAMPFLT));
}

/**
  * @brief  Set Tamper sampling frequency
  * @rmtoll TAMP_FLTCR       TAMPFREQ      LL_RTC_TAMPER_SetSamplingFreq
  * @param  RTCx RTC Instance
  * @param  SamplingFreq This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_32768
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_16384
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_8192
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_4096
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_2048
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_1024
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_512
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_256
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_SetSamplingFreq(RTC_TypeDef *RTCx, uint32_t SamplingFreq)
{
  UNUSED(RTCx);
  MODIFY_REG(TAMP->FLTCR, TAMP_FLTCR_TAMPFREQ, SamplingFreq);
}

/**
  * @brief  Get Tamper sampling frequency
  * @rmtoll TAMP_FLTCR       TAMPFREQ      LL_RTC_TAMPER_GetSamplingFreq
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_32768
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_16384
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_8192
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_4096
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_2048
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_1024
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_512
  *         @arg @ref LL_RTC_TAMPER_SAMPLFREQDIV_256
  */
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetSamplingFreq(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return (uint32_t)(READ_BIT(TAMP->FLTCR, TAMP_FLTCR_TAMPFREQ));
}

/**
  * @brief  Enable Active level for Tamper input
  * @rmtoll TAMP_CR2       TAMP1TRG       LL_RTC_TAMPER_EnableActiveLevel\n
  *         TAMP_CR2       TAMP2TRG...    LL_RTC_TAMPER_EnableActiveLevel
  * @param  RTCx RTC Instance
  * @param  Tamper This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_TAMPER_ACTIVELEVEL
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_EnableActiveLevel(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->CR2, Tamper);
}

/**
  * @brief  Disable Active level for Tamper input
  * @rmtoll TAMP_CR2       TAMP1TRG      LL_RTC_TAMPER_DisableActiveLevel\n
  *         TAMP_CR2       TAMP2TRG...   LL_RTC_TAMPER_DisableActiveLevel
  * @param  RTCx RTC Instance
  * @param  Tamper This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_TAMPER_ACTIVELEVEL
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_DisableActiveLevel(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->CR2, Tamper);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Internal_Tamper Internal Tamper
  * @{
  */

/**
  * @brief  Enable internal tamper detection.
  * @rmtoll TAMP_CR1       ITAMP1E       LL_RTC_TAMPER_ITAMP_Enable\n
  *         TAMP_CR1       ITAMP2E..       LL_RTC_TAMPER_ITAMP_Enable\n
  * @param  RTCx RTC Instance
  * @param  InternalTamper This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_INTERNAL
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ITAMP_Enable(RTC_TypeDef *RTCx, uint32_t InternalTamper)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->CR1, InternalTamper);
}

/**
  * @brief  Disable internal tamper detection.
  * @rmtoll TAMP_CR1       ITAMP1E       LL_RTC_TAMPER_ITAMP_Disable\n
  *         TAMP_CR1       ITAMP2E       LL_RTC_TAMPER_ITAMP_Disable\n
  *         TAMP_CR1       ITAMP3E       LL_RTC_TAMPER_ITAMP_Disable\n
  *         TAMP_CR1       ITAMP5E       LL_RTC_TAMPER_ITAMP_Disable\n
  *         TAMP_CR1       ITAMP8E       LL_RTC_TAMPER_ITAMP_Disable
  * @param  RTCx RTC Instance
  * @param  InternalTamper This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_INTERNAL
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ITAMP_Disable(RTC_TypeDef *RTCx, uint32_t InternalTamper)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->CR1, InternalTamper);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Active_Tamper Active Tamper
  * @{
  */
/**
  * @brief  Enable tamper active mode.
  * @rmtoll TAMP_ATCR1     TAMP1AM       LL_RTC_TAMPER_ATAMP_EnableActiveMode\n
  * @rmtoll TAMP_ATCR1     TAMP2AM       LL_RTC_TAMPER_ATAMP_EnableActiveMode\n
  * @rmtoll TAMP_ATCR1     TAMPxAM       LL_RTC_TAMPER_ATAMP_EnableActiveMode\n
  * @param  Tamper to configure as active. This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_ACTIVE_MODE
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_EnableActiveMode(uint32_t Tamper)
{
  SET_BIT(TAMP->ATCR1, Tamper);
}

/**
  * @brief  Disable tamper active mode.
  * @rmtoll TAMP_ATCR1     TAMP1AM       LL_RTC_TAMPER_ATAMP_DisableActiveMode\n
  * @rmtoll TAMP_ATCR1     TAMP2AM       LL_RTC_TAMPER_ATAMP_DisableActiveMode\n
  * @rmtoll TAMP_ATCR1     TAMPxAM       LL_RTC_TAMPER_ATAMP_DisableActiveMode\n
  * @param  Tamper to configure as active. This parameter can be a combination of the following values:
  *         @arg @ref RTC_LL_EC_ACTIVE_MODE
  *
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_DisableActiveMode(uint32_t Tamper)
{
  CLEAR_BIT(TAMP->ATCR1, Tamper);
}

/**
  * @brief  Enable active tamper filter.
  * @rmtoll TAMP_ATCR1     FLTEN         LL_RTC_TAMPER_ATAMP_EnableFilter\n
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_EnableFilter(void)
{
  SET_BIT(TAMP->ATCR1, TAMP_ATCR1_FLTEN);
}

/**
  * @brief  Disable active tamper filter.
  * @rmtoll TAMP_ATCR1     FLTEN         LL_RTC_TAMPER_ATAMP_DisableFilter\n
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_DisableFilter(void)
{
  CLEAR_BIT(TAMP->ATCR1, TAMP_ATCR1_FLTEN);
}

/**
  * @brief  Set Active tamper output change period.
  * @rmtoll TAMP_ATCR1     ATPER         LL_RTC_TAMPER_ATAMP_SetOutputChangePeriod\n
  * @param  ActiveOutputChangePeriod This parameter can be a value from 0 to 7
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_SetOutputChangePeriod(uint32_t ActiveOutputChangePeriod)
{
  MODIFY_REG(TAMP->ATCR1, TAMP_ATCR1_ATPER, (ActiveOutputChangePeriod << TAMP_ATCR1_ATPER_Pos));
}

/**
  * @brief  Get Active tamper output change period.
  * @rmtoll TAMP_ATCR1     ATPER         LL_RTC_TAMPER_ATAMP_GetOutputChangePeriod\n
  * @retval Output change period. This parameter can be a value from 0 to 7.
  */
__STATIC_INLINE uint32_t LL_RTC_TAMPER_ATAMP_GetOutputChangePeriod(void)
{
  return (READ_BIT(TAMP->ATCR1, TAMP_ATCR1_ATPER) >> TAMP_ATCR1_ATPER_Pos);
}

/**
  * @brief  Set Active tamper asynchronous prescaler clock selection.
  * @rmtoll TAMP_ATCR1     ATCKSEL       LL_RTC_TAMPER_ATAMP_SetAsyncPrescaler\n
  * @param  ActiveAsynvPrescaler Specifies the Active Tamper asynchronous Prescaler clock.
            This parameter can be a value of the following values:
  *         @arg @ref RTC_LL_EC_ACTIVE_ASYNC_PRESCALER
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_SetAsyncPrescaler(uint32_t ActiveAsynvPrescaler)
{
  MODIFY_REG(TAMP->ATCR1, TAMP_ATCR1_ATCKSEL, ActiveAsynvPrescaler);
}

/**
  * @brief  Get Active tamper asynchronous prescaler clock selection.
  * @rmtoll TAMP_ATCR1     ATCKSEL       LL_RTC_TAMPER_ATAMP_GetAsyncPrescaler\n
  * @retval One of @arg @ref RTC_LL_EC_ACTIVE_ASYNC_PRESCALER
  */
__STATIC_INLINE uint32_t LL_RTC_TAMPER_ATAMP_GetAsyncPrescaler(void)
{
  return (READ_BIT(TAMP->ATCR1, TAMP_ATCR1_ATCKSEL));
}

/**
  * @brief  Enable active tamper output sharing.
  * @rmtoll TAMP_ATCR1     ATOSHARE      LL_RTC_TAMPER_ATAMP_EnableOutputSharing\n
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_EnableOutputSharing(void)
{
  SET_BIT(TAMP->ATCR1, TAMP_ATCR1_ATOSHARE);
}

/**
  * @brief  Disable active tamper output sharing.
  * @rmtoll TAMP_ATCR1     ATOSHARE      LL_RTC_TAMPER_ATAMP_DisableOutputSharing\n
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_DisableOutputSharing(void)
{
  CLEAR_BIT(TAMP->ATCR1, TAMP_ATCR1_ATOSHARE);
}

/**
  * @brief  Set Active tamper output selection.
  * @rmtoll TAMP_ATCR2     ATCKSEL       LL_RTC_TAMPER_ATAMP_SetSharedOuputSelection\n
  * @param  OutputSelection Specifies all the output selection of the Active Tamper.
            This parameter is a combinasation of the following values:
  *         One of @arg @ref RTC_LL_EC_ACTIVE_OUTPUT_SELECTION
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_SetSharedOuputSelection(uint32_t OutputSelection)
{
  MODIFY_REG(TAMP->ATCR2, (TAMP_ATCR2_ATOSEL1 | TAMP_ATCR2_ATOSEL2 | TAMP_ATCR2_ATOSEL3 | TAMP_ATCR2_ATOSEL4 | \
                           TAMP_ATCR2_ATOSEL5 | TAMP_ATCR2_ATOSEL6 | TAMP_ATCR2_ATOSEL7 | TAMP_ATCR2_ATOSEL8), \
             OutputSelection);
}

/**
  * @brief  Get Active tamper asynchronous prescaler clock selection.
  * @rmtoll TAMP_ATCR2     ATCKSEL       LL_RTC_TAMPER_ATAMP_GetAsyncPrescaler\n
  * @retval A combination of @arg @ref RTC_LL_EC_ACTIVE_OUTPUT_SELECTION
  */
__STATIC_INLINE uint32_t LL_RTC_TAMPER_ATAMP_GetSharedOuputSelection(void)
{
  return (READ_BIT(TAMP->ATCR2, (TAMP_ATCR2_ATOSEL1 | TAMP_ATCR2_ATOSEL2 | TAMP_ATCR2_ATOSEL3 | TAMP_ATCR2_ATOSEL4 | \
                                 TAMP_ATCR2_ATOSEL5 | TAMP_ATCR2_ATOSEL6 | TAMP_ATCR2_ATOSEL7 | TAMP_ATCR2_ATOSEL8)));
}

/**
  * @brief  Write active tamper seed.
  * @rmtoll TAMP_ATSEEDR   SEED          LL_RTC_TAMPER_ATAMP_WriteSeed\n
  * @param  Seed
  * @retval None
  */
__STATIC_INLINE void LL_RTC_TAMPER_ATAMP_WriteSeed(uint32_t Seed)
{
  WRITE_REG(TAMP->ATSEEDR, Seed);
}

/**
  * @brief  Get active tamper initialization status flag.
  * @rmtoll TAMP_ATOR      INITS         LL_RTC_IsActiveFlag_ATAMP_INITS
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ATAMP_INITS(void)
{
  return ((READ_BIT(TAMP->ATOR, TAMP_ATOR_INITS) == (TAMP_ATOR_INITS)) ? 1U : 0U);
}

/**
  * @brief  Get active tamper seed running status flag.
  * @rmtoll TAMP_ATOR      INITS         LL_RTC_IsActiveFlag_ATAMP_INITS
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ATAMP_SEEDF(void)
{
  return ((READ_BIT(TAMP->ATOR, TAMP_ATOR_SEEDF) == (TAMP_ATOR_SEEDF)) ? 1U : 0U);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Wakeup Wakeup
  * @{
  */

/**
  * @brief  Enable Wakeup timer
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           WUTE          LL_RTC_WAKEUP_Enable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_WAKEUP_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_WUTE);
}

/**
  * @brief  Disable Wakeup timer
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           WUTE          LL_RTC_WAKEUP_Disable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_WAKEUP_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_WUTE);
}

/**
  * @brief  Check if Wakeup timer is enabled or not
  * @rmtoll RTC_CR           WUTE          LL_RTC_WAKEUP_IsEnabled
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_WAKEUP_IsEnabled(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_WUTE) == (RTC_CR_WUTE)) ? 1U : 0U);
}

/**
  * @brief  Select Wakeup clock
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   Bit can be written only when RTC_CR WUTE bit = 0 and RTC_ICSR WUTWF bit = 1
  * @rmtoll RTC_CR           WUCKSEL       LL_RTC_WAKEUP_SetClock
  * @param  RTCx RTC Instance
  * @param  WakeupClock This parameter can be one of the following values:
  *         @arg @ref LL_RTC_WAKEUPCLOCK_DIV_16
  *         @arg @ref LL_RTC_WAKEUPCLOCK_DIV_8
  *         @arg @ref LL_RTC_WAKEUPCLOCK_DIV_4
  *         @arg @ref LL_RTC_WAKEUPCLOCK_DIV_2
  *         @arg @ref LL_RTC_WAKEUPCLOCK_CKSPRE
  *         @arg @ref LL_RTC_WAKEUPCLOCK_CKSPRE_WUT
  * @retval None
  */
__STATIC_INLINE void LL_RTC_WAKEUP_SetClock(RTC_TypeDef *RTCx, uint32_t WakeupClock)
{
  MODIFY_REG(RTCx->CR, RTC_CR_WUCKSEL, WakeupClock);
}

/**
  * @brief  Get Wakeup clock
  * @rmtoll RTC_CR           WUCKSEL       LL_RTC_WAKEUP_GetClock
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WAKEUPCLOCK_DIV_16
  *         @arg @ref LL_RTC_WAKEUPCLOCK_DIV_8
  *         @arg @ref LL_RTC_WAKEUPCLOCK_DIV_4
  *         @arg @ref LL_RTC_WAKEUPCLOCK_DIV_2
  *         @arg @ref LL_RTC_WAKEUPCLOCK_CKSPRE
  *         @arg @ref LL_RTC_WAKEUPCLOCK_CKSPRE_WUT
  */
__STATIC_INLINE uint32_t LL_RTC_WAKEUP_GetClock(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_WUCKSEL));
}

/**
  * @brief  Set Wakeup auto-reload value
  * @note   Bit can be written only when WUTWF is set to 1 in RTC_ICSR
  * @rmtoll RTC_WUTR         WUT           LL_RTC_WAKEUP_SetAutoReload
  * @param  RTCx RTC Instance
  * @param  Value Value between Min_Data=0x00 and Max_Data=0xFFFF
  * @retval None
  */
__STATIC_INLINE void LL_RTC_WAKEUP_SetAutoReload(RTC_TypeDef *RTCx, uint32_t Value)
{
  MODIFY_REG(RTCx->WUTR, RTC_WUTR_WUT, Value);
}

/**
  * @brief  Get Wakeup auto-reload value
  * @rmtoll RTC_WUTR         WUT           LL_RTC_WAKEUP_GetAutoReload
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t LL_RTC_WAKEUP_GetAutoReload(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->WUTR, RTC_WUTR_WUT));
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Backup_Registers Backup_Registers
  * @{
  */

/**
  * @brief  Writes a data in a specified Backup data register.
  * @rmtoll TAMP_BKPxR        BKP           LL_RTC_BKP_SetRegister
  * @param  RTCx RTC Instance
  * @param  BackupRegister This parameter can be one of the following values:
  *         @arg @ref LL_RTC_BKP_DR0
  *         @arg @ref LL_RTC_BKP_DR1
  *         @arg @ref LL_RTC_BKP_DR2
  *         @arg @ref LL_RTC_BKP_DR3
  *         @arg @ref LL_RTC_BKP_DR4
  *         @arg @ref LL_RTC_BKP_DR5
  *         @arg @ref LL_RTC_BKP_DR6
  *         @arg @ref LL_RTC_BKP_DR7
  *         @arg @ref LL_RTC_BKP_DR8
  *         @arg @ref LL_RTC_BKP_DR9
  *         @arg @ref LL_RTC_BKP_DR10
  *         @arg @ref LL_RTC_BKP_DR11
  *         @arg @ref LL_RTC_BKP_DR12
  *         @arg @ref LL_RTC_BKP_DR13
  *         @arg @ref LL_RTC_BKP_DR14
  *         @arg @ref LL_RTC_BKP_DR15
  *         @arg @ref LL_RTC_BKP_DR16
  *         @arg @ref LL_RTC_BKP_DR17
  *         @arg @ref LL_RTC_BKP_DR18
  *         @arg @ref LL_RTC_BKP_DR19
  *         @arg @ref LL_RTC_BKP_DR20
  *         @arg @ref LL_RTC_BKP_DR21
  *         @arg @ref LL_RTC_BKP_DR22
  *         @arg @ref LL_RTC_BKP_DR23
  *         @arg @ref LL_RTC_BKP_DR24
  *         @arg @ref LL_RTC_BKP_DR25
  *         @arg @ref LL_RTC_BKP_DR26
  *         @arg @ref LL_RTC_BKP_DR27
  *         @arg @ref LL_RTC_BKP_DR28
  *         @arg @ref LL_RTC_BKP_DR29
  *         @arg @ref LL_RTC_BKP_DR30
  *         @arg @ref LL_RTC_BKP_DR31
  * @param  Data Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_RTC_BKP_SetRegister(RTC_TypeDef *RTCx, uint32_t BackupRegister, uint32_t Data)
{
  uint32_t tmp;

  UNUSED(RTCx);

  tmp = (uint32_t)(&(TAMP->BKP0R));
  tmp += (BackupRegister * 4U);

  /* Write the specified register */
  *(__IO uint32_t *)tmp = (uint32_t)Data;
}

/**
  * @brief  Reads data from the specified RTC Backup data Register.
  * @rmtoll TAMP_BKPxR        BKP           LL_RTC_BKP_GetRegister
  * @param  RTCx RTC Instance
  * @param  BackupRegister This parameter can be one of the following values:
  *         @arg @ref LL_RTC_BKP_DR0
  *         @arg @ref LL_RTC_BKP_DR1
  *         @arg @ref LL_RTC_BKP_DR2
  *         @arg @ref LL_RTC_BKP_DR3
  *         @arg @ref LL_RTC_BKP_DR4
  *         @arg @ref LL_RTC_BKP_DR5
  *         @arg @ref LL_RTC_BKP_DR6
  *         @arg @ref LL_RTC_BKP_DR7
  *         @arg @ref LL_RTC_BKP_DR8
  *         @arg @ref LL_RTC_BKP_DR9
  *         @arg @ref LL_RTC_BKP_DR10
  *         @arg @ref LL_RTC_BKP_DR11
  *         @arg @ref LL_RTC_BKP_DR12
  *         @arg @ref LL_RTC_BKP_DR13
  *         @arg @ref LL_RTC_BKP_DR14
  *         @arg @ref LL_RTC_BKP_DR15
  *         @arg @ref LL_RTC_BKP_DR16
  *         @arg @ref LL_RTC_BKP_DR17
  *         @arg @ref LL_RTC_BKP_DR18
  *         @arg @ref LL_RTC_BKP_DR19
  *         @arg @ref LL_RTC_BKP_DR20
  *         @arg @ref LL_RTC_BKP_DR21
  *         @arg @ref LL_RTC_BKP_DR22
  *         @arg @ref LL_RTC_BKP_DR23
  *         @arg @ref LL_RTC_BKP_DR24
  *         @arg @ref LL_RTC_BKP_DR25
  *         @arg @ref LL_RTC_BKP_DR26
  *         @arg @ref LL_RTC_BKP_DR27
  *         @arg @ref LL_RTC_BKP_DR28
  *         @arg @ref LL_RTC_BKP_DR29
  *         @arg @ref LL_RTC_BKP_DR30
  *         @arg @ref LL_RTC_BKP_DR31
  * @retval Value between Min_Data=0x00 and Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RTC_BKP_GetRegister(RTC_TypeDef *RTCx, uint32_t BackupRegister)
{
  uint32_t tmp;

  UNUSED(RTCx);

  tmp = (uint32_t)(&(TAMP->BKP0R));
  tmp += (BackupRegister * 4U);

  /* Read the specified register */
  return (*(__IO uint32_t *)tmp);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_Calibration Calibration
  * @{
  */

/**
  * @brief  Set Calibration output frequency (1 Hz or 512 Hz)
  * @note Bits are write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           COE           LL_RTC_CAL_SetOutputFreq\n
  *         RTC_CR           COSEL         LL_RTC_CAL_SetOutputFreq
  * @param  RTCx RTC Instance
  * @param  Frequency This parameter can be one of the following values:
  *         @arg @ref LL_RTC_CALIB_OUTPUT_NONE
  *         @arg @ref LL_RTC_CALIB_OUTPUT_1HZ
  *         @arg @ref LL_RTC_CALIB_OUTPUT_512HZ
  * @retval None
  */
__STATIC_INLINE void LL_RTC_CAL_SetOutputFreq(RTC_TypeDef *RTCx, uint32_t Frequency)
{
  MODIFY_REG(RTCx->CR, RTC_CR_COE | RTC_CR_COSEL, Frequency);
}

/**
  * @brief  Get Calibration output frequency (1 Hz or 512 Hz)
  * @rmtoll RTC_CR           COE           LL_RTC_CAL_GetOutputFreq\n
  *         RTC_CR           COSEL         LL_RTC_CAL_GetOutputFreq
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_CALIB_OUTPUT_NONE
  *         @arg @ref LL_RTC_CALIB_OUTPUT_1HZ
  *         @arg @ref LL_RTC_CALIB_OUTPUT_512HZ
  */
__STATIC_INLINE uint32_t LL_RTC_CAL_GetOutputFreq(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_COE | RTC_CR_COSEL));
}

/**
  * @brief  Insert or not One RTCCLK pulse every 2exp11 pulses (frequency increased by 488.5 ppm)
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note Bit can be written only when RECALPF is set to 0 in RTC_ICSR
  * @rmtoll RTC_CALR         CALP          LL_RTC_CAL_SetPulse
  * @param  RTCx RTC Instance
  * @param  Pulse This parameter can be one of the following values:
  *         @arg @ref LL_RTC_CALIB_INSERTPULSE_NONE
  *         @arg @ref LL_RTC_CALIB_INSERTPULSE_SET
  * @retval None
  */
__STATIC_INLINE void LL_RTC_CAL_SetPulse(RTC_TypeDef *RTCx, uint32_t Pulse)
{
  MODIFY_REG(RTCx->CALR, RTC_CALR_CALP, Pulse);
}

/**
  * @brief  Check if one RTCCLK has been inserted or not every 2exp11 pulses (frequency increased by 488.5 ppm)
  * @rmtoll RTC_CALR         CALP          LL_RTC_CAL_IsPulseInserted
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_CAL_IsPulseInserted(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CALR, RTC_CALR_CALP) == (RTC_CALR_CALP)) ? 1U : 0U);
}

/**
  * @brief  Set the calibration cycle period
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   Bit can be written only when RECALPF is set to 0 in RTC_ICSR
  * @rmtoll RTC_CALR         CALW8         LL_RTC_CAL_SetPeriod\n
  *         RTC_CALR         CALW16        LL_RTC_CAL_SetPeriod
  * @param  RTCx RTC Instance
  * @param  Period This parameter can be one of the following values:
  *         @arg @ref LL_RTC_CALIB_PERIOD_32SEC
  *         @arg @ref LL_RTC_CALIB_PERIOD_16SEC
  *         @arg @ref LL_RTC_CALIB_PERIOD_8SEC
  * @retval None
  */
__STATIC_INLINE void LL_RTC_CAL_SetPeriod(RTC_TypeDef *RTCx, uint32_t Period)
{
  MODIFY_REG(RTCx->CALR, RTC_CALR_CALW8 | RTC_CALR_CALW16, Period);
}

/**
  * @brief  Get the calibration cycle period
  * @rmtoll RTC_CALR         CALW8         LL_RTC_CAL_GetPeriod\n
  *         RTC_CALR         CALW16        LL_RTC_CAL_GetPeriod
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_CALIB_PERIOD_32SEC
  *         @arg @ref LL_RTC_CALIB_PERIOD_16SEC
  *         @arg @ref LL_RTC_CALIB_PERIOD_8SEC
  */
__STATIC_INLINE uint32_t LL_RTC_CAL_GetPeriod(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CALR, RTC_CALR_CALW8 | RTC_CALR_CALW16));
}

/**
  * @brief  Set Calibration minus
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   Bit can be written only when RECALPF is set to 0 in RTC_ICSR
  * @rmtoll RTC_CALR         CALM          LL_RTC_CAL_SetMinus
  * @param  RTCx RTC Instance
  * @param  CalibMinus Value between Min_Data=0x00 and Max_Data=0x1FF
  * @retval None
  */
__STATIC_INLINE void LL_RTC_CAL_SetMinus(RTC_TypeDef *RTCx, uint32_t CalibMinus)
{
  MODIFY_REG(RTCx->CALR, RTC_CALR_CALM, CalibMinus);
}

/**
  * @brief  Get Calibration minus
  * @rmtoll RTC_CALR         CALM          LL_RTC_CAL_GetMinus
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data= 0x1FF
  */
__STATIC_INLINE uint32_t LL_RTC_CAL_GetMinus(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CALR, RTC_CALR_CALM));
}

/**
  * @brief  Enable Calibration Low Power
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   Bit can be written only when RECALPF is set to 0
  * @rmtoll RTC_CALR         LPCAL          LL_RTC_CAL_LowPower_Enable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_CAL_LowPower_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CALR, RTC_CALR_LPCAL);
}

/**
  * @brief  Disable Calibration Low Power
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @note   Bit can be written only when RECALPF is set to 0
  * @rmtoll RTC_CALR         LPCAL          LL_RTC_CAL_LowPower_Disable
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_CAL_LowPower_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CALR, RTC_CALR_LPCAL);
}

/**
  * @brief  Check if Calibration Low Power is enabled or not
  * @rmtoll RTC_CALR         LPCAL          LL_RTC_CAL_LowPower_IsEnabled
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_CAL_LowPower_IsEnabled(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CALR, RTC_CALR_LPCAL) == (RTC_CALR_LPCAL)) ? 1U : 0U);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Get Internal Time-stamp flag
  * @rmtoll RTC_SR          ITSF          LL_RTC_IsActiveFlag_ITS
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITS(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->SR, RTC_SR_ITSF) == (RTC_SR_ITSF)) ? 1U : 0U);
}

/**
  * @brief  Get Recalibration pending Flag
  * @rmtoll RTC_ICSR          RECALPF       LL_RTC_IsActiveFlag_RECALP
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_RECALP(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ICSR, RTC_ICSR_RECALPF) == (RTC_ICSR_RECALPF)) ? 1U : 0U);
}

/**
  * @brief  Get Time-stamp overflow flag
  * @rmtoll RTC_SR          TSOVF         LL_RTC_IsActiveFlag_TSOV
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TSOV(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->SR, RTC_SR_TSOVF) == (RTC_SR_TSOVF)) ? 1U : 0U);
}

/**
  * @brief  Get Time-stamp flag
  * @rmtoll RTC_SR          TSF           LL_RTC_IsActiveFlag_TS
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TS(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->SR, RTC_SR_TSF) == (RTC_SR_TSF)) ? 1U : 0U);
}

/**
  * @brief  Get Wakeup timer flag
  * @rmtoll RTC_SR          WUTF          LL_RTC_IsActiveFlag_WUT
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_WUT(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->SR, RTC_SR_WUTF) == (RTC_SR_WUTF)) ? 1U : 0U);
}

/**
  * @brief  Get Alarm B flag
  * @rmtoll RTC_SR          ALRBF         LL_RTC_IsActiveFlag_ALRB
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRB(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->SR, RTC_SR_ALRBF) == (RTC_SR_ALRBF)) ? 1U : 0U);
}

/**
  * @brief  Get Alarm A flag
  * @rmtoll RTC_SR          ALRAF         LL_RTC_IsActiveFlag_ALRA
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRA(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->SR, RTC_SR_ALRAF) == (RTC_SR_ALRAF)) ? 1U : 0U);
}

/**
  * @brief  Clear Internal Time-stamp flag
  * @rmtoll RTC_SCR          CITSF          LL_RTC_ClearFlag_ITS
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_ITS(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->SCR, RTC_SCR_CITSF);
}

/**
  * @brief  Clear Time-stamp overflow flag
  * @rmtoll RTC_SCR          CTSOVF         LL_RTC_ClearFlag_TSOV
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TSOV(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->SCR, RTC_SCR_CTSOVF);
}

/**
  * @brief  Clear Time-stamp flag
  * @rmtoll RTC_SCR          CTSF           LL_RTC_ClearFlag_TS
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TS(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->SCR, RTC_SCR_CTSF);
}

/**
  * @brief  Clear Wakeup timer flag
  * @rmtoll RTC_SCR          CWUTF          LL_RTC_ClearFlag_WUT
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_WUT(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->SCR, RTC_SCR_CWUTF);
}

/**
  * @brief  Clear Alarm B flag
  * @rmtoll RTC_SCR          CALRBF         LL_RTC_ClearFlag_ALRB
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_ALRB(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->SCR, RTC_SCR_CALRBF);
}

/**
  * @brief  Clear Alarm A flag
  * @rmtoll RTC_SCR          CALRAF         LL_RTC_ClearFlag_ALRA
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_ALRA(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->SCR, RTC_SCR_CALRAF);
}

/**
  * @brief  Get Initialization flag
  * @rmtoll RTC_ICSR          INITF         LL_RTC_IsActiveFlag_INIT
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_INIT(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ICSR, RTC_ICSR_INITF) == (RTC_ICSR_INITF)) ? 1U : 0U);
}

/**
  * @brief  Get Registers synchronization flag
  * @rmtoll RTC_ICSR          RSF           LL_RTC_IsActiveFlag_RS
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_RS(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ICSR, RTC_ICSR_RSF) == (RTC_ICSR_RSF)) ? 1U : 0U);
}

/**
  * @brief  Clear Registers synchronization flag
  * @rmtoll RTC_ICSR          RSF           LL_RTC_ClearFlag_RS
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_RS(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ICSR, (~((RTC_ICSR_RSF | RTC_ICSR_INIT) & 0x000000FFU) | (RTCx->ICSR & RTC_ICSR_INIT)));
}

/**
  * @brief  Get Initialization status flag
  * @rmtoll RTC_ICSR          INITS         LL_RTC_IsActiveFlag_INITS
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_INITS(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ICSR, RTC_ICSR_INITS) == (RTC_ICSR_INITS)) ? 1U : 0U);
}

/**
  * @brief  Get Shift operation pending flag
  * @rmtoll RTC_ICSR          SHPF          LL_RTC_IsActiveFlag_SHP
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_SHP(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ICSR, RTC_ICSR_SHPF) == (RTC_ICSR_SHPF)) ? 1U : 0U);
}

/**
  * @brief  Get Wakeup timer write flag
  * @rmtoll RTC_ICSR          WUTWF         LL_RTC_IsActiveFlag_WUTW
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_WUTW(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ICSR, RTC_ICSR_WUTWF) == (RTC_ICSR_WUTWF)) ? 1U : 0U);
}

/**
  * @brief  Get Alarm A masked flag.
  * @rmtoll RTC_MISR          ALRAMF        LL_RTC_IsActiveFlag_ALRAM
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRAM(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->MISR, RTC_MISR_ALRAMF) == (RTC_MISR_ALRAMF)) ? 1U : 0U);
}

/**
  * @brief  Get Alarm B masked flag.
  * @rmtoll RTC_MISR          ALRBMF        LL_RTC_IsActiveFlag_ALRBM
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRBM(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->MISR, RTC_MISR_ALRBMF) == (RTC_MISR_ALRBMF)) ? 1U : 0U);
}

/**
  * @brief  Get Wakeup timer masked flag.
  * @rmtoll RTC_MISR          WUTMF        LL_RTC_IsActiveFlag_WUTM
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_WUTM(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->MISR, RTC_MISR_WUTMF) == (RTC_MISR_WUTMF)) ? 1U : 0U);
}

/**
  * @brief  Get Time-stamp masked flag.
  * @rmtoll RTC_MISR          TSMF        LL_RTC_IsActiveFlag_TSM
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TSM(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->MISR, RTC_MISR_TSMF) == (RTC_MISR_TSMF)) ? 1U : 0U);
}

/**
  * @brief  Get Time-stamp overflow masked flag.
  * @rmtoll RTC_MISR          TSOVMF        LL_RTC_IsActiveFlag_TSOVM
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TSOVM(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->MISR, RTC_MISR_TSOVMF) == (RTC_MISR_TSOVMF)) ? 1U : 0U);
}

/**
  * @brief  Get Internal Time-stamp masked flag.
  * @rmtoll RTC_MISR          ITSMF        LL_RTC_IsActiveFlag_ITSM
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITSM(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->MISR, RTC_MISR_ITSMF) == (RTC_MISR_ITSMF)) ? 1U : 0U);
}

/**
  * @brief  Get tamper 1 detection flag.
  * @rmtoll TAMP_SR          TAMP1F        LL_RTC_IsActiveFlag_TAMP1
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_TAMP1F) == (TAMP_SR_TAMP1F)) ? 1U : 0U);
}

/**
  * @brief  Get tamper 2 detection flag.
  * @rmtoll TAMP_SR          TAMP2F        LL_RTC_IsActiveFlag_TAMP2
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_TAMP2F) == (TAMP_SR_TAMP2F)) ? 1U : 0U);
}

/**
  * @brief  Get tamper 3 detection flag.
  * @rmtoll TAMP_SR          TAMP3F        LL_RTC_IsActiveFlag_TAMP3
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_TAMP3F) == (TAMP_SR_TAMP3F)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 4 detection flag.
  * @rmtoll TAMP_SR          TAMP4F        LL_RTC_IsActiveFlag_TAMP4
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP4(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_TAMP4F) == (TAMP_SR_TAMP4F)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 5 detection flag.
  * @rmtoll TAMP_SR          TAMP5F        LL_RTC_IsActiveFlag_TAMP5
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_TAMP5F) == (TAMP_SR_TAMP5F)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 6 detection flag.
  * @rmtoll TAMP_SR          TAMP6F        LL_RTC_IsActiveFlag_TAMP6
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP6(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_TAMP6F) == (TAMP_SR_TAMP6F)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 7 detection flag.
  * @rmtoll TAMP_SR          TAMP7F        LL_RTC_IsActiveFlag_TAMP7
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP7(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_TAMP7F) == (TAMP_SR_TAMP7F)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 8 detection flag.
  * @rmtoll TAMP_SR          TAMP8F        LL_RTC_IsActiveFlag_TAMP8
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_TAMP8F) == (TAMP_SR_TAMP8F)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 1 detection flag.
  * @rmtoll TAMP_SR          ITAMP1F        LL_RTC_IsActiveFlag_ITAMP1
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_ITAMP1F) == (TAMP_SR_ITAMP1F)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 2 detection flag.
  * @rmtoll TAMP_SR          ITAMP2F        LL_RTC_IsActiveFlag_ITAMP2
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_ITAMP2F) == (TAMP_SR_ITAMP2F)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 3 detection flag.
  * @rmtoll TAMP_SR          ITAMP3F        LL_RTC_IsActiveFlag_ITAMP3
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_ITAMP3F) == (TAMP_SR_ITAMP3F)) ? 1U : 0U);
}


/**
  * @brief  Get internal tamper 5 detection flag.
  * @rmtoll TAMP_SR          ITAMP5F        LL_RTC_IsActiveFlag_ITAMP5
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_ITAMP5F) == (TAMP_SR_ITAMP5F)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 8 detection flag.
  * @rmtoll TAMP_SR          ITAMP8F        LL_RTC_IsActiveFlag_ITAMP8
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->SR, TAMP_SR_ITAMP8F) == (TAMP_SR_ITAMP8F)) ? 1U : 0U);
}

/**
  * @brief  Get tamper 1 interrupt masked flag.
  * @rmtoll TAMP_MISR          TAMP1MF        LL_RTC_IsActiveFlag_TAMP1M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP1M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_TAMP1MF) == (TAMP_MISR_TAMP1MF)) ? 1U : 0U);
}

/**
  * @brief  Get tamper 2 interrupt masked flag.
  * @rmtoll TAMP_MISR          TAMP2MF        LL_RTC_IsActiveFlag_TAMP2M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP2M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_TAMP2MF) == (TAMP_MISR_TAMP2MF)) ? 1U : 0U);
}

/**
  * @brief  Get tamper 3 interrupt masked flag.
  * @rmtoll TAMP_MISR          TAMP3MF        LL_RTC_IsActiveFlag_TAMP3M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP3M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_TAMP3MF) == (TAMP_MISR_TAMP3MF)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 4 interrupt masked flag.
  * @rmtoll TAMP_MISR          TAMP4MF        LL_RTC_IsActiveFlag_TAMP4M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP4M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_TAMP4MF) == (TAMP_MISR_TAMP4MF)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 5 interrupt masked flag.
  * @rmtoll TAMP_MISR          TAMP5MF        LL_RTC_IsActiveFlag_TAMP5M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP5M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_TAMP5MF) == (TAMP_MISR_TAMP5MF)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 6 interrupt masked flag.
  * @rmtoll TAMP_MISR          TAMP3MF        LL_RTC_IsActiveFlag_TAMP6M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP6M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_TAMP6MF) == (TAMP_MISR_TAMP6MF)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 7 interrupt masked flag.
  * @rmtoll TAMP_MISR          TAMP7MF        LL_RTC_IsActiveFlag_TAMP7M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP7M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_TAMP7MF) == (TAMP_MISR_TAMP7MF)) ? 1U : 0U);
}
/**
  * @brief  Get tamper 8 interrupt masked flag.
  * @rmtoll TAMP_MISR          TAMP8MF        LL_RTC_IsActiveFlag_TAMP8M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP8M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_TAMP8MF) == (TAMP_MISR_TAMP8MF)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 1 interrupt masked flag.
  * @rmtoll TAMP_MISR          ITAMP1MF        LL_RTC_IsActiveFlag_ITAMP1M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP1M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_ITAMP1MF) == (TAMP_MISR_ITAMP1MF)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 2 interrupt masked flag.
  * @rmtoll TAMP_MISR          ITAMP2MF        LL_RTC_IsActiveFlag_ITAMP2M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP2M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_ITAMP2MF) == (TAMP_MISR_ITAMP2MF)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 3 interrupt masked flag.
  * @rmtoll TAMP_MISR          ITAMP3MF        LL_RTC_IsActiveFlag_ITAMP3M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP3M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_ITAMP3MF) == (TAMP_MISR_ITAMP3MF)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 5 interrupt masked flag.
  * @rmtoll TAMP_MISR          ITAMP5MF        LL_RTC_IsActiveFlag_ITAMP5M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP5M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_ITAMP5MF) == (TAMP_MISR_ITAMP5MF)) ? 1U : 0U);
}

/**
  * @brief  Get internal tamper 8 interrupt masked flag.
  * @rmtoll TAMP_MISR          ITAMP8MF        LL_RTC_IsActiveFlag_ITAMP8M
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITAMP8M(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->MISR, TAMP_MISR_ITAMP8MF) == (TAMP_MISR_ITAMP8MF)) ? 1U : 0U);
}

/**
  * @brief  Clear tamper 1 detection flag.
  * @rmtoll TAMP_SCR          CTAMP1F         LL_RTC_ClearFlag_TAMP1
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CTAMP1F);
}

/**
  * @brief  Clear tamper 2 detection flag.
  * @rmtoll TAMP_SCR          CTAMP2F         LL_RTC_ClearFlag_TAMP2
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CTAMP2F);
}

/**
  * @brief  Clear tamper 3 detection flag.
  * @rmtoll TAMP_SCR          CTAMP3F         LL_RTC_ClearFlag_TAMP3
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CTAMP3F);
}
/**
  * @brief  Clear tamper 4 detection flag.
  * @rmtoll TAMP_SCR          CTAMP3F         LL_RTC_ClearFlag_TAMP4
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP4(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CTAMP4F);
}
/**
  * @brief  Clear tamper 5 detection flag.
  * @rmtoll TAMP_SCR          CTAMP5F         LL_RTC_ClearFlag_TAMP5
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CTAMP5F);
}
/**
  * @brief  Clear tamper 6 detection flag.
  * @rmtoll TAMP_SCR          CTAMP6F         LL_RTC_ClearFlag_TAMP6
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP6(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CTAMP6F);
}
/**
  * @brief  Clear tamper 7 detection flag.
  * @rmtoll TAMP_SCR          CTAMP7F         LL_RTC_ClearFlag_TAMP7
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP7(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CTAMP7F);
}
/**
  * @brief  Clear tamper 8 detection flag.
  * @rmtoll TAMP_SCR          CTAMP8F         LL_RTC_ClearFlag_TAMP8
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CTAMP8F);
}

/**
  * @brief  Clear internal tamper 1 detection flag.
  * @rmtoll TAMP_SCR          CITAMP1F         LL_RTC_ClearFlag_ITAMP1
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_ITAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CITAMP1F);
}

/**
  * @brief  Clear internal tamper 2 detection flag.
  * @rmtoll TAMP_SCR          CITAMP2F         LL_RTC_ClearFlag_ITAMP2
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_ITAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CITAMP2F);
}

/**
  * @brief  Clear internal tamper 3 detection flag.
  * @rmtoll TAMP_SCR          CITAMP3F         LL_RTC_ClearFlag_ITAMP3
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_ITAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CITAMP3F);
}

/**
  * @brief  Clear internal tamper 5 detection flag.
  * @rmtoll TAMP_SCR          CITAMP5F         LL_RTC_ClearFlag_ITAMP5
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_ITAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CITAMP5F);
}

/**
  * @brief  Clear internal tamper 8 detection flag.
  * @rmtoll TAMP_SCR          CITAMP8F         LL_RTC_ClearFlag_ITAMP8
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_ClearFlag_ITAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->SCR, TAMP_SCR_CITAMP8F);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_SECURITY SECURITY_Management
  * @{
  */

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  * @brief  Set RTC secure level.
  * @note   Unsecure features are relevant if LL_RTC_SECURE_FULL_NO.
  * @rmtoll RTC_SMCR           DECPROT           LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           INITPROT          LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           CALDPROT          LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           TSDPROT           LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           WUTDPROT          LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           ALRADPROT         LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           ALRBDPROT         LL_RTC_SetRtcSecure
  * @param  RTCx RTC Instance
  * @param  rtcSecure This parameter can be a combination of the following values:
  *         @arg @ref LL_RTC_SECURE_FULL_YES
  *         @arg @ref LL_RTC_SECURE_FULL_NO
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_INIT
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_CAL
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_TS
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_WUT
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_ALRA
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_ALRB

  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetRtcSecure(RTC_TypeDef *RTCx, uint32_t rtcSecure)
{
  MODIFY_REG(RTCx->SMCR, RTC_SMCR_DECPROT | RTC_SMCR_INITDPROT | RTC_SMCR_CALDPROT | RTC_SMCR_TSDPROT | RTC_SMCR_WUTDPROT | RTC_SMCR_ALRADPROT | RTC_SMCR_ALRBDPROT, rtcSecure);
}
#endif /* #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

/**
  * @brief  Get RTC secure level.
  * @note   Unsecure features is relevant if LL_RTC_SECURE_FULL_NO.
  * @rmtoll RTC_SMCR           DECPROT           LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           INITPROT          LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           CALDPROT          LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           TSDPROT           LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           WUTDPROT          LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           ALRADPROT         LL_RTC_SetRtcSecure
  * @rmtoll RTC_SMCR           ALRBDPROT         LL_RTC_SetRtcSecure
  * @param  RTCx RTC Instance
  * @retval Combination of the following values:
  *         @arg @ref LL_RTC_SECURE_FULL_YES
  *         @arg @ref LL_RTC_SECURE_FULL_NO
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_INIT
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_CAL
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_TS
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_WUT
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_ALRA
  *         @arg @ref LL_RTC_UNSECURE_FEATURE_ALRB
  */
__STATIC_INLINE uint32_t LL_RTC_GetRtcSecure(RTC_TypeDef *RTCx)
{
  return READ_BIT(RTCx->SMCR, RTC_SMCR_DECPROT | RTC_SMCR_INITDPROT | RTC_SMCR_CALDPROT | RTC_SMCR_TSDPROT | RTC_SMCR_WUTDPROT | RTC_SMCR_ALRADPROT | RTC_SMCR_ALRBDPROT);
}

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/**
  * @brief  Set TAMPER secure level.
  * @rmtoll TAMP_SMCR          TAMPDPROT           LL_RTC_SetTampSecure
  * @param  RTCx RTC Instance
  * @param  tampSecure This parameter can be one of the following values:
  *         @arg @ref LL_TAMP_SECURE_FULL_YES
  *         @arg @ref LL_TAMP_SECURE_FULL_NO
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetTampSecure(RTC_TypeDef *RTCx, uint32_t tampSecure)
{
  UNUSED(RTCx);
  MODIFY_REG(TAMP->SMCR, TAMP_SMCR_TAMPDPROT, tampSecure);
}
#endif /* #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U) */

/**
  * @brief  Get TAMPER secure level.
  * @rmtoll TAMP_SMCR          TAMPDPROT           LL_RTC_GetTampSecure
  * @param  RTCx RTC Instance
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_TAMP_SECURE_FULL_YES
  *         @arg @ref LL_TAMP_SECURE_FULL_NO
  */
__STATIC_INLINE uint32_t LL_RTC_GetTampSecure(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return READ_BIT(TAMP->SMCR, TAMP_SMCR_TAMPDPROT);
}

/**
  * @}
  */

/** @defgroup RTC_LL_EF_PRIVILEGE PRIVILEGE_Management
  * @{
  */

/**
  * @brief  Set RTC privilege level.
  * @note   Privilege features are relevant if LL_RTC_PRIVILEGE_FULL_NO.
  * @rmtoll RTC_PRIVCR           PRIV              LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           INITPRIV          LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           CALPRIV           LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           TSPRIV            LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           WUTPRIV           LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           ALRAPRIV          LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           ALRBPRIV          LL_RTC_SetRtcPrivilege
  * @param  RTCx RTC Instance
  * @param  rtcPrivilege This parameter can be a combination of the following values:
  *         @arg @ref LL_RTC_PRIVILEGE_FULL_YES
  *         @arg @ref LL_RTC_PRIVILEGE_FULL_NO
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_INIT
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_CAL
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_TS
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_WUT
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_ALRA
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_ALRB
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetRtcPrivilege(RTC_TypeDef *RTCx, uint32_t rtcPrivilege)
{
  MODIFY_REG(RTCx->PRIVCR, RTC_PRIVCR_PRIV | RTC_PRIVCR_INITPRIV | RTC_PRIVCR_CALPRIV | RTC_PRIVCR_TSPRIV | RTC_PRIVCR_WUTPRIV | RTC_PRIVCR_ALRAPRIV | RTC_PRIVCR_ALRBPRIV, rtcPrivilege);
}

/**
  * @brief  Get RTC privilege level.
  * @note   Privilege features are relevant if LL_RTC_PRIVILEGE_FULL_NO.
  * @rmtoll RTC_PRIVCR           PRIV              LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           INITPRIV          LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           CALPRIV           LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           TSPRIV            LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           WUTPRIV           LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           ALRAPRIV          LL_RTC_SetRtcPrivilege
  * @rmtoll RTC_PRIVCR           ALRBPRIV          LL_RTC_SetRtcPrivilege
  * @param  RTCx RTC Instance
  * @retval Combination of the following values:
  *         @arg @ref LL_RTC_PRIVILEGE_FULL_YES
  *         @arg @ref LL_RTC_PRIVILEGE_FULL_NO
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_INIT
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_CAL
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_TS
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_WUT
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_ALRA
  *         @arg @ref LL_RTC_PRIVILEGE_FEATURE_ALRB
  */
__STATIC_INLINE uint32_t LL_RTC_GetRtcPrivilege(RTC_TypeDef *RTCx)
{
  return READ_BIT(RTCx->PRIVCR, RTC_PRIVCR_PRIV | RTC_PRIVCR_INITPRIV | RTC_PRIVCR_CALPRIV | RTC_PRIVCR_TSPRIV | RTC_PRIVCR_WUTPRIV | RTC_PRIVCR_ALRAPRIV | RTC_PRIVCR_ALRBPRIV);
}

/**
  * @brief  Set TAMPER privilege level.
  * @rmtoll TAMP_SMCR          TAMPPRIV           LL_RTC_SetTampPrivilege
  * @param  RTCx RTC Instance
  * @param  tampPrivilege This parameter can be one of the following values:
  *         @arg @ref LL_TAMP_PRIVILEGE_FULL_YES
  *         @arg @ref LL_TAMP_PRIVILEGE_FULL_NO
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetTampPrivilege(RTC_TypeDef *RTCx, uint32_t tampPrivilege)
{
  UNUSED(RTCx);
  MODIFY_REG(TAMP->PRIVCR, TAMP_PRIVCR_TAMPPRIV, tampPrivilege);
}

/**
  * @brief  Get TAMPER privilege level.
  * @rmtoll TAMP_SMCR          TAMPDPROT           LL_RTC_GetTampPrivilege
  * @param  RTCx RTC Instance
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_TAMP_PRIVILEGE_FULL_YES
  *         @arg @ref LL_TAMP_PRIVILEGE_FULL_NO
  */
__STATIC_INLINE uint32_t LL_RTC_GetTampPrivilege(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return READ_BIT(TAMP->PRIVCR, TAMP_PRIVCR_TAMPPRIV);
}

/**
  * @brief  Set Backup Registers privilege level.
  * @note   bckupRegisterPrivilege is only writable in secure mode or if trustzone is disabled
  * @rmtoll TAMP_PRIVCR          BKPWPRIV           LL_RTC_SetTampPrivilege
  * @rmtoll TAMP_PRIVCR          BKPRWPRIV          LL_RTC_SetTampPrivilege
  * @param  RTCx RTC Instance
  * @param  bckupRegisterPrivilege This parameter can be one of the following values:
  *         @arg @ref LL_RTC_PRIVILEGE_BKUP_ZONE_NONE
  *         @arg @ref LL_RTC_PRIVILEGE_BKUP_ZONE_1
  *         @arg @ref LL_RTC_PRIVILEGE_BKUP_ZONE_2
  *         @arg @ref LL_RTC_PRIVILEGE_BKUP_ZONE_ALL
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetBackupRegisterPrivilege(RTC_TypeDef *RTCx, uint32_t bckupRegisterPrivilege)
{
  UNUSED(RTCx);
  MODIFY_REG(TAMP->PRIVCR, (TAMP_PRIVCR_BKPWPRIV | TAMP_PRIVCR_BKPRWPRIV), bckupRegisterPrivilege);
}

/**
  * @brief  Get Backup Registers privilege level.
  * @rmtoll TAMP_PRIVCR          BKPWPRIV           LL_RTC_SetTampPrivilege
  * @rmtoll TAMP_PRIVCR          BKPRWPRIV          LL_RTC_SetTampPrivilege
  * @param  RTCx RTC Instance
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RTC_PRIVILEGE_BKUP_ZONE_NONE
  *         @arg @ref LL_RTC_PRIVILEGE_BKUP_ZONE_1
  *         @arg @ref LL_RTC_PRIVILEGE_BKUP_ZONE_2
  *         @arg @ref LL_RTC_PRIVILEGE_BKUP_ZONE_ALL
  */
__STATIC_INLINE uint32_t LL_RTC_GetBackupRegisterPrivilege(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return READ_BIT(TAMP->PRIVCR, (TAMP_PRIVCR_BKPWPRIV | TAMP_PRIVCR_BKPRWPRIV));
}
/**
  * @}
  */

/** @defgroup RTC_LL_EF_BACKUP_REG_PROTECTION PROTECTION_BACKUP_REG_Management
  * @brief    Backup register protection is common to security and privilege.
  * @{
  */

/**
  * @brief  Set Backup registers protection level.
  * @note   Zone 1 : read protection write protection
  * @note   Zone 2 : read non-protection  write protection
  * @note   Zone 3 : read non-protection  write non-protection
  * @note   Warning : this parameter is only writable in secure mode or if trustzone is disabled
  * @rmtoll TAMP_SMCR          BKPWDPROT           LL_RTC_SetBackupRegProtection
  * @rmtoll TAMP_SMCR          BKPRWDPROT          LL_RTC_SetBackupRegProtection
  * @param  RTCx RTC Instance
  * @param  startZone2 This parameter can be one of the following values:
  *         @arg @ref LL_RTC_BKP_DR0
  *         @arg @ref LL_RTC_BKP_DR1
  *         @arg @ref LL_RTC_BKP_DR2
  *         @arg @ref LL_RTC_BKP_DR3
  *         @arg @ref LL_RTC_BKP_DR4
  *         @arg @ref LL_RTC_BKP_DR5
  *         @arg @ref LL_RTC_BKP_DR6
  *         @arg @ref LL_RTC_BKP_DR7
  *         @arg @ref LL_RTC_BKP_DR8
  *         @arg @ref LL_RTC_BKP_DR9
  *         @arg @ref LL_RTC_BKP_DR10
  *         @arg @ref LL_RTC_BKP_DR11
  *         @arg @ref LL_RTC_BKP_DR12
  *         @arg @ref LL_RTC_BKP_DR13
  *         @arg @ref LL_RTC_BKP_DR14
  *         @arg @ref LL_RTC_BKP_DR15
  *         @arg @ref LL_RTC_BKP_DR16
  *         @arg @ref LL_RTC_BKP_DR17
  *         @arg @ref LL_RTC_BKP_DR18
  *         @arg @ref LL_RTC_BKP_DR19
  *         @arg @ref LL_RTC_BKP_DR20
  *         @arg @ref LL_RTC_BKP_DR21
  *         @arg @ref LL_RTC_BKP_DR22
  *         @arg @ref LL_RTC_BKP_DR23
  *         @arg @ref LL_RTC_BKP_DR24
  *         @arg @ref LL_RTC_BKP_DR25
  *         @arg @ref LL_RTC_BKP_DR26
  *         @arg @ref LL_RTC_BKP_DR27
  *         @arg @ref LL_RTC_BKP_DR28
  *         @arg @ref LL_RTC_BKP_DR29
  *         @arg @ref LL_RTC_BKP_DR30
  *         @arg @ref LL_RTC_BKP_DR31
  * @param  startZone3 This parameter can be one of the following values:
  *         @arg @ref LL_RTC_BKP_DR0
  *         @arg @ref LL_RTC_BKP_DR1
  *         @arg @ref LL_RTC_BKP_DR2
  *         @arg @ref LL_RTC_BKP_DR3
  *         @arg @ref LL_RTC_BKP_DR4
  *         @arg @ref LL_RTC_BKP_DR5
  *         @arg @ref LL_RTC_BKP_DR6
  *         @arg @ref LL_RTC_BKP_DR7
  *         @arg @ref LL_RTC_BKP_DR8
  *         @arg @ref LL_RTC_BKP_DR9
  *         @arg @ref LL_RTC_BKP_DR10
  *         @arg @ref LL_RTC_BKP_DR11
  *         @arg @ref LL_RTC_BKP_DR12
  *         @arg @ref LL_RTC_BKP_DR13
  *         @arg @ref LL_RTC_BKP_DR14
  *         @arg @ref LL_RTC_BKP_DR15
  *         @arg @ref LL_RTC_BKP_DR16
  *         @arg @ref LL_RTC_BKP_DR17
  *         @arg @ref LL_RTC_BKP_DR18
  *         @arg @ref LL_RTC_BKP_DR19
  *         @arg @ref LL_RTC_BKP_DR20
  *         @arg @ref LL_RTC_BKP_DR21
  *         @arg @ref LL_RTC_BKP_DR22
  *         @arg @ref LL_RTC_BKP_DR23
  *         @arg @ref LL_RTC_BKP_DR24
  *         @arg @ref LL_RTC_BKP_DR25
  *         @arg @ref LL_RTC_BKP_DR26
  *         @arg @ref LL_RTC_BKP_DR27
  *         @arg @ref LL_RTC_BKP_DR28
  *         @arg @ref LL_RTC_BKP_DR29
  *         @arg @ref LL_RTC_BKP_DR30
  *         @arg @ref LL_RTC_BKP_DR31
  * @retval None
  */
__STATIC_INLINE void LL_RTC_SetBackupRegProtection(RTC_TypeDef *RTCx, uint32_t startZone2, uint32_t startZone3)
{
  UNUSED(RTCx);
  MODIFY_REG(TAMP->SMCR, (TAMP_SMCR_BKPRWDPROT_Msk | TAMP_SMCR_BKPWDPROT_Msk), (startZone2 << TAMP_SMCR_BKPRWDPROT_Pos) | (startZone3 << TAMP_SMCR_BKPWDPROT_Pos));
}

/**
  * @brief  Get Backup registers protection level start zone 2.
  * @note   Zone 1 : read protection write protection
  * @note   Zone 2 : read non-protection/non-privile  write protection
  * @note   Zone 3 : read non-protection  write non-protection
  * @rmtoll TAMP_SMCR          BKPRWDPROT         LL_RTC_GetBackupRegProtectionStartZone2
  * @param  RTCx RTC Instance
  * @retval Start zone 2
  */
__STATIC_INLINE uint32_t LL_RTC_GetBackupRegProtectionStartZone2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return READ_BIT(TAMP->SMCR, TAMP_SMCR_BKPRWDPROT_Msk) >> TAMP_SMCR_BKPRWDPROT_Pos;
}

/**
  * @brief  Get Backup registers protection level start zone 3.
  * @note   Zone 1 : read protection write protection
  * @note   Zone 2 : read non-protection  write protection
  * @note   Zone 3 : read non-protection  write non-protection
  * @rmtoll TAMP_SMCR          BKPWDPROT           LL_RTC_GetBackupRegProtectionStartZone3
  * @param  RTCx RTC Instance
  * @retval Start zone 2
  */
__STATIC_INLINE uint32_t LL_RTC_GetBackupRegProtectionStartZone3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return READ_BIT(TAMP->SMCR, TAMP_SMCR_BKPWDPROT_Msk) >> TAMP_SMCR_BKPWDPROT_Pos;
}
/**
  * @}
  */

/** @defgroup RTC_LL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  Enable Time-stamp interrupt
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR          TSIE         LL_RTC_EnableIT_TS
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TS(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TSIE);
}

/**
  * @brief  Disable Time-stamp interrupt
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR          TSIE         LL_RTC_DisableIT_TS
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TS(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TSIE);
}

/**
  * @brief  Enable Wakeup timer interrupt
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR          WUTIE         LL_RTC_EnableIT_WUT
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_WUT(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_WUTIE);
}

/**
  * @brief  Disable Wakeup timer interrupt
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR          WUTIE         LL_RTC_DisableIT_WUT
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_WUT(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_WUTIE);
}

/**
  * @brief  Enable Alarm B interrupt
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ALRBIE        LL_RTC_EnableIT_ALRB
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_ALRB(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRBIE);
}

/**
  * @brief  Disable Alarm B interrupt
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ALRBIE        LL_RTC_DisableIT_ALRB
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_ALRB(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRBIE);
}

/**
  * @brief  Enable Alarm A interrupt
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ALRAIE        LL_RTC_EnableIT_ALRA
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_ALRA(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRAIE);
}

/**
  * @brief  Disable Alarm A interrupt
  * @note   Bit is write-protected. @ref LL_RTC_DisableWriteProtection function should be called before.
  * @rmtoll RTC_CR           ALRAIE        LL_RTC_DisableIT_ALRA
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_ALRA(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRAIE);
}

/**
  * @brief  Check if Time-stamp interrupt is enabled or not
  * @rmtoll RTC_CR           TSIE          LL_RTC_IsEnabledIT_TS
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TS(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_TSIE) == (RTC_CR_TSIE)) ? 1U : 0U);
}

/**
  * @brief  Check if Wakeup timer interrupt is enabled or not
  * @rmtoll RTC_CR           WUTIE         LL_RTC_IsEnabledIT_WUT
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_WUT(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_WUTIE) == (RTC_CR_WUTIE)) ? 1U : 0U);
}

/**
  * @brief  Check if Alarm B interrupt is enabled or not
  * @rmtoll RTC_CR           ALRBIE        LL_RTC_IsEnabledIT_ALRB
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ALRB(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_ALRBIE) == (RTC_CR_ALRBIE)) ? 1U : 0U);
}

/**
  * @brief  Check if Alarm A interrupt is enabled or not
  * @rmtoll RTC_CR           ALRAIE        LL_RTC_IsEnabledIT_ALRA
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ALRA(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_ALRAIE) == (RTC_CR_ALRAIE)) ? 1U : 0U);
}

/**
  * @brief  Enable tamper 1 interrupt.
  * @rmtoll TAMP_IER           TAMP1IE          LL_RTC_EnableIT_TAMP1
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_TAMP1IE);
}

/**
  * @brief  Disable tamper 1 interrupt.
  * @rmtoll TAMP_IER           TAMP1IE          LL_RTC_DisableIT_TAMP1
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_TAMP1IE);
}

/**
  * @brief  Enable tamper 2 interrupt.
  * @rmtoll TAMP_IER           TAMP2IE          LL_RTC_EnableIT_TAMP2
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_TAMP2IE);
}

/**
  * @brief  Disable tamper 2 interrupt.
  * @rmtoll TAMP_IER           TAMP2IE          LL_RTC_DisableIT_TAMP2
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_TAMP2IE);
}

/**
  * @brief  Enable tamper 3 interrupt.
  * @rmtoll TAMP_IER           TAMP3IE          LL_RTC_EnableIT_TAMP3
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_TAMP3IE);
}
/**
  * @brief  Disable tamper 3 interrupt.
  * @rmtoll TAMP_IER           TAMP3IE          LL_RTC_DisableIT_TAMP3
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_TAMP3IE);
}
/**
  * @brief  Enable tamper 4 interrupt.
  * @rmtoll TAMP_IER           TAMP4IE          LL_RTC_EnableIT_TAMP4
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TAMP4(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_TAMP4IE);
}
/**
  * @brief  Disable tamper 4 interrupt.
  * @rmtoll TAMP_IER           TAMP4IE          LL_RTC_DisableIT_TAMP4
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TAMP4(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_TAMP4IE);
}

/**
  * @brief  Enable tamper 5 interrupt.
  * @rmtoll TAMP_IER           TAMP5IE          LL_RTC_EnableIT_TAMP5
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_TAMP5IE);
}
/**
  * @brief  Disable tamper 5 interrupt.
  * @rmtoll TAMP_IER           TAMP5IE          LL_RTC_DisableIT_TAMP5
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_TAMP5IE);
}

/**
  * @brief  Enable tamper 6 interrupt.
  * @rmtoll TAMP_IER           TAMP6IE          LL_RTC_EnableIT_TAMP6
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TAMP6(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_TAMP6IE);
}
/**
  * @brief  Disable tamper 6 interrupt.
  * @rmtoll TAMP_IER           TAMP6IE          LL_RTC_DisableIT_TAMP6
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TAMP6(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_TAMP6IE);
}

/**
  * @brief  Enable tamper 7 interrupt.
  * @rmtoll TAMP_IER           TAMP7IE          LL_RTC_EnableIT_TAMP7
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TAMP7(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_TAMP7IE);
}
/**
  * @brief  Disable tamper 7 interrupt.
  * @rmtoll TAMP_IER           TAMP7IE          LL_RTC_DisableIT_TAMP7
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TAMP7(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_TAMP7IE);
}

/**
  * @brief  Enable tamper 8 interrupt.
  * @rmtoll TAMP_IER           TAMP8IE          LL_RTC_EnableIT_TAMP8
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_TAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_TAMP8IE);
}
/**
  * @brief  Disable tamper 8 interrupt.
  * @rmtoll TAMP_IER           TAMP8IE          LL_RTC_DisableIT_TAMP8
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_TAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_TAMP8IE);
}

/**
  * @brief  Enable internal tamper 1 interrupt.
  * @rmtoll TAMP_IER           ITAMP1IE          LL_RTC_EnableIT_ITAMP1
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_ITAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_ITAMP1IE);
}

/**
  * @brief  Disable internal tamper 1 interrupt.
  * @rmtoll TAMP_IER           ITAMP1IE          LL_RTC_DisableIT_ITAMP1
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_ITAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_ITAMP1IE);
}

/**
  * @brief  Enable internal tamper 2 interrupt.
  * @rmtoll TAMP_IER           ITAMP2IE          LL_RTC_EnableIT_ITAMP2
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_ITAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_ITAMP2IE);
}

/**
  * @brief  Disable internal tamper 2 interrupt.
  * @rmtoll TAMP_IER           ITAMP2IE          LL_RTC_DisableIT_ITAMP2
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_ITAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_ITAMP2IE);
}

/**
  * @brief  Enable internal tamper 3 interrupt.
  * @rmtoll TAMP_IER           ITAMP3IE          LL_RTC_EnableIT_ITAMP3
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_ITAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_ITAMP3IE);
}
/**
  * @brief  Disable internal tamper 3 interrupt.
  * @rmtoll TAMP_IER           ITAMP3IE          LL_RTC_DisableIT_ITAMP3
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_ITAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_ITAMP3IE);
}

/**
  * @brief  Enable internal tamper 5 interrupt.
  * @rmtoll TAMP_IER           ITAMP5IE          LL_RTC_EnableIT_ITAMP5
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_ITAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_ITAMP5IE);
}
/**
  * @brief  Disable internal tamper 5 interrupt.
  * @rmtoll TAMP_IER           ITAMP5IE          LL_RTC_DisableIT_ITAMP5
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_ITAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_ITAMP5IE);
}

/**
  * @brief  Enable internal tamper 8 interrupt.
  * @rmtoll TAMP_IER           ITAMP8IE          LL_RTC_EnableIT_ITAMP8
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableIT_ITAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->IER, TAMP_IER_ITAMP8IE);
}
/**
  * @brief  Disable internal tamper 8 interrupt.
  * @rmtoll TAMP_IER           TAMP8IE          LL_RTC_DisableIT_ITAMP8
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableIT_ITAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->IER, TAMP_IER_ITAMP8IE);
}

/**
  * @brief  Check if tamper 1 interrupt is enabled or not.
  * @rmtoll TAMP_IER           TAMP1IE        LL_RTC_IsEnabledIT_TAMP1
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_TAMP1IE) == (TAMP_IER_TAMP1IE)) ? 1U : 0U);
}

/**
  * @brief  Check if tamper 2 interrupt is enabled or not.
  * @rmtoll TAMP_IER           TAMP2IE        LL_RTC_IsEnabledIT_TAMP2
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_TAMP2IE) == (TAMP_IER_TAMP2IE)) ? 1U : 0U);
}

/**
  * @brief  Check if tamper 3 interrupt is enabled or not.
  * @rmtoll TAMP_IER           TAMP3IE        LL_RTC_IsEnabledIT_TAMP3
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_TAMP3IE) == (TAMP_IER_TAMP3IE)) ? 1U : 0U);
}
/**
  * @brief  Check if tamper 4 interrupt is enabled or not.
  * @rmtoll TAMP_IER           TAMP4IE        LL_RTC_IsEnabledIT_TAMP4
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP4(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_TAMP4IE) == (TAMP_IER_TAMP4IE)) ? 1U : 0U);
}
/**
  * @brief  Check if tamper 5 interrupt is enabled or not.
  * @rmtoll TAMP_IER           TAMP1IE        LL_RTC_IsEnabledIT_TAMP5
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_TAMP5IE) == (TAMP_IER_TAMP5IE)) ? 1U : 0U);
}
/**
  * @brief  Check if tamper 6 interrupt is enabled or not.
  * @rmtoll TAMP_IER           TAMP6IE        LL_RTC_IsEnabledIT_TAMP6
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP6(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_TAMP6IE) == (TAMP_IER_TAMP6IE)) ? 1U : 0U);
}
/**
  * @brief  Check if tamper 7 interrupt is enabled or not.
  * @rmtoll TAMP_IER           TAMP1IE        LL_RTC_IsEnabledIT_TAMP7
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP7(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_TAMP7IE) == (TAMP_IER_TAMP7IE)) ? 1U : 0U);
}
/**
  * @brief  Check if tamper 8 interrupt is enabled or not.
  * @rmtoll TAMP_IER           TAMP8IE        LL_RTC_IsEnabledIT_TAMP8
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_TAMP8IE) == (TAMP_IER_TAMP8IE)) ? 1U : 0U);
}

/**
  * @brief  Check if internal tamper 1 interrupt is enabled or not.
  * @rmtoll TAMP_IER           ITAMP1IE        LL_RTC_IsEnabledIT_ITAMP1
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ITAMP1(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_ITAMP1IE) == (TAMP_IER_ITAMP1IE)) ? 1U : 0U);
}

/**
  * @brief  Check if internal tamper 2 interrupt is enabled or not.
  * @rmtoll TAMP_IER           ITAMP2IE        LL_RTC_IsEnabledIT_ITAMP2
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ITAMP2(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_ITAMP2IE) == (TAMP_IER_ITAMP2IE)) ? 1U : 0U);
}

/**
  * @brief  Check if internal tamper 3 interrupt is enabled or not.
  * @rmtoll TAMP_IER           ITAMP3IE        LL_RTC_IsEnabledIT_ITAMP3
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ITAMP3(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_ITAMP3IE) == (TAMP_IER_ITAMP3IE)) ? 1U : 0U);
}

/**
  * @brief  Check if internal tamper 5 interrupt is enabled or not.
  * @rmtoll TAMP_IER           ITAMP5IE        LL_RTC_IsEnabledIT_ITAMP5
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ITAMP5(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_ITAMP5IE) == (TAMP_IER_ITAMP5IE)) ? 1U : 0U);
}

/**
  * @brief  Check if internal tamper 8 interrupt is enabled or not.
  * @rmtoll TAMP_IER           ITAMP8IE        LL_RTC_IsEnabledIT_ITAMP8
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ITAMP8(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return ((READ_BIT(TAMP->IER, TAMP_IER_ITAMP8IE) == (TAMP_IER_ITAMP8IE)) ? 1U : 0U);
}


/**
  * @brief  Increment Monotonic counter.
  * @rmtoll TAMP_COUNTR         COUNT        LL_RTC_IncrementMonotonicCounter
  * @param  RTCx RTC Instance
  * @retval None.
  */
__STATIC_INLINE void LL_RTC_IncrementMonotonicCounter(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  WRITE_REG(TAMP->COUNTR, 0u);
}

/**
  * @brief  Increment Monotonic counter.
  * @rmtoll TAMP_COUNTR         COUNT        LL_RTC_GetMonotonicCounter
  * @param  RTCx RTC Instance
  * @retval Monotonic counter value.
  */
__STATIC_INLINE uint32_t LL_RTC_GetMonotonicCounter(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  return READ_REG(TAMP->COUNTR);
}

/**
  * @brief  Enable Temperature Monitoring.
  * @rmtoll TAMP_CFGR           TMONEN          LL_RTC_EnableTemperatureMonitoring
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableTemperatureMonitoring(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->CFGR, TAMP_CFGR_TMONEN);
}

/**
  * @brief  Disable Temperature Monitoring.
  * @rmtoll TAMP_CFGR           TMONEN          LL_RTC_DisableTemperatureMonitoring
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableTemperatureMonitoring(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->CFGR, TAMP_CFGR_TMONEN);
}

/**
  * @brief  Enable Voltage Monitoring.
  * @rmtoll TAMP_CFGR           VMONEN          LL_RTC_EnableVoltageMonitoring
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableVoltageMonitoring(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->CFGR, TAMP_CFGR_VMONEN);
}

/**
  * @brief  Disable Voltage Monitoring.
  * @rmtoll TAMP_CFGR           VMONEN          LL_RTC_DisableVoltageMonitoring
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableVoltageMonitoring(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->CFGR, TAMP_CFGR_VMONEN);
}

/**
  * @brief  Enable WUT Monitoring.
  * @rmtoll TAMP_CFGR           WUTMONEN          LL_RTC_EnableWUTMonitoring
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_EnableWUTMonitoring(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  SET_BIT(TAMP->CFGR, TAMP_CFGR_WUTMONEN);
}

/**
  * @brief  Disable WUT Monitoring.
  * @rmtoll TAMP_CFGR           WUTMONEN          LL_RTC_DisableWUTMonitoring
  * @param  RTCx RTC Instance
  * @retval None
  */
__STATIC_INLINE void LL_RTC_DisableWUTMonitoring(RTC_TypeDef *RTCx)
{
  UNUSED(RTCx);
  CLEAR_BIT(TAMP->CFGR, TAMP_CFGR_WUTMONEN);
}


/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RTC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_RTC_DeInit(RTC_TypeDef *RTCx);
ErrorStatus LL_RTC_Init(RTC_TypeDef *RTCx, LL_RTC_InitTypeDef *RTC_InitStruct);
void        LL_RTC_StructInit(LL_RTC_InitTypeDef *RTC_InitStruct);
ErrorStatus LL_RTC_TIME_Init(RTC_TypeDef *RTCx, uint32_t RTC_Format, LL_RTC_TimeTypeDef *RTC_TimeStruct);
void        LL_RTC_TIME_StructInit(LL_RTC_TimeTypeDef *RTC_TimeStruct);
ErrorStatus LL_RTC_DATE_Init(RTC_TypeDef *RTCx, uint32_t RTC_Format, LL_RTC_DateTypeDef *RTC_DateStruct);
void        LL_RTC_DATE_StructInit(LL_RTC_DateTypeDef *RTC_DateStruct);
ErrorStatus LL_RTC_ALMA_Init(RTC_TypeDef *RTCx, uint32_t RTC_Format, LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
ErrorStatus LL_RTC_ALMB_Init(RTC_TypeDef *RTCx, uint32_t RTC_Format, LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
void        LL_RTC_ALMA_StructInit(LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
void        LL_RTC_ALMB_StructInit(LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
ErrorStatus LL_RTC_EnterInitMode(RTC_TypeDef *RTCx);
ErrorStatus LL_RTC_ExitInitMode(RTC_TypeDef *RTCx);
ErrorStatus LL_RTC_WaitForSynchro(RTC_TypeDef *RTCx);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(RTC) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32L5xx_LL_RTC_H */


