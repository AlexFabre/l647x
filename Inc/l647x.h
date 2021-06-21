

#ifndef _L647X_H_
#define _L647X_H_
#include <stdint.h>


typedef union {
	uint16_t value;
	struct {
		uint16_t HiZ :1;
		uint16_t BUSY :1;
		uint16_t SW_F :1;
		uint16_t SW_EVN :1;
		uint16_t DIR :1;
		uint16_t MOTSTATUT :2;
		uint16_t NOTPERF_CMD :1;
		uint16_t WRONG_CMD :1;
		uint16_t UVLO :1;
		uint16_t TH_WRN :1;
		uint16_t TH_SD :1;
		uint16_t OCD :1;
		uint16_t STEP_LOSS_A:1;
		uint16_t STEP_LOSS_B:1;
		uint16_t SCK_MOD :1;
	};
} l647x_status_register;

typedef union {
    uint8_t value;
    struct {
        
    }
} l647x_alarm_register;

typedef union {
    uint16_t value;
    struct l6470_config_register_s {
        uint16_t OSC_SEL:3;
        uint16_t EXT_CLK:1;
        uint16_t SW_MODE:1;
        uint16_t EN_VSCOMP:1;
        uint16_t RESERVED:1;
        uint16_t OC_SD:1;
        uint16_t POW_SR:2;
        uint16_t F_PWM_DEC:3;
        uint16_t F_PWM_INT:3;
    }
    struct l6472_config_register_s {
        uint16_t OSC_SEL:3;
        uint16_t EXT_CLK:1;
        uint16_t SW_MODE:1;
        uint16_t EN_TQREG:1;
        uint16_t RESERVED:1;
        uint16_t OC_SD:1;
        uint16_t POW_SR:2;
        uint16_t TSW:5;
        uint16_t PRED_EN:1;
    }
} l647x_config_register;




















//------------------------------------------------------------------------------
//                Limit values
//------------------------------------------------------------------------------
/*MAX_SPEED*/
#define HIGH_MAX_SPEED_PARAM    0x3CFA  //15610 step/s
#define LOW_MAX_SPEED_PARAM     0x0010  //16 step/s

/*MIN_SPEED*/
#define HIGH_MIN_SPEED_PARAM    0x02A4  //676 step/s
#define LOW_MIN_SPEED_PARAM     0x0000  //0 step/s

/*FS_SPD*/
#define MIN_FS_SPD_PARAM        0x0008  //8 step/s
#define MAX_FS_SPD_PARAM        0x3D09  //15625 step/s

/*CURRENT SPEED*/
#define MAX_CURRENT_SPEED_PARAM 0x3D09  //15625 step/s
#define MIN_CURRENT_SPEED_PARAM 0x0000  //0 step/s

/*ACC/DEC*/
#define MAX_ACC_DEC_PARAM       0xE8C6  //59590 step/s�
#define MIN_ACC_DEC_PARAM       0x000F  //15 step/s�

/*TVAL_X*/
#define MAX_TVAL_X_PARAM        0xFA0   //4A
#define MIN_TVAL_X_PARAM        0x020   //32mA

/*ODC_TH*/
#define MAX_ODC_TH_PARAM        0x1770   //6A
#define MIN_ODC_TH_PARAM        0x0177   //375mA

/*ABS_POS*/
#define ABS_POS_MAX             0x3FFFFF

//------------------------------------------------------------------------------
//            L6472    Available options for config parameter
//------------------------------------------------------------------------------
#define _PRED_ON_POSITION       0x000F
#define _TSW_POSITION           0x000A
#define _POW_SR_POSITION        0x0008
#define _OC_SD_ON_POSITION      0x0007
#define _EN_TQREG_ON_POSITION   0x0005
#define _SW_MODE_ON_POSITION    0x0004
#define _EXT_CLK_ON_POSITION    0x0003

// Predictive current control - values are mutually exclusive
#define PRED_ON                 (1u << _PRED_ON_POSITION)
#define PRED_OFF		(0u)

// Slew rate value of the power bridge output - values are mutually exclusive
#define TSW_124             (31u << _TSW_POSITION)    /* 124�s */
#define TSW_120             (30u << _TSW_POSITION)    /* 120�s */
#define TSW_116             (29u << _TSW_POSITION)    /* 116�s */
#define TSW_112             (28u << _TSW_POSITION)    /* 112�s */
#define TSW_108             (27u << _TSW_POSITION)    /* 108�s */
#define TSW_104             (26u << _TSW_POSITION)    /* 104�s */
#define TSW_100             (25u << _TSW_POSITION)    /* 100�s */
#define TSW_96              (24u << _TSW_POSITION)    /* 96�s */
#define TSW_92              (23u << _TSW_POSITION)    /* 92�s */
#define TSW_88              (22u << _TSW_POSITION)    /* 88�s */
#define TSW_84              (21u << _TSW_POSITION)    /* 84�s */
#define TSW_80              (20u << _TSW_POSITION)    /* 80�s */
#define TSW_76              (19u << _TSW_POSITION)    /* 76�s */
#define TSW_72              (18u << _TSW_POSITION)    /* 72�s */
#define TSW_68              (17u << _TSW_POSITION)    /* 68�s */
#define TSW_64              (16u << _TSW_POSITION)    /* 64�s */
#define TSW_60              (15u << _TSW_POSITION)    /* 60�s */
#define TSW_56              (14u << _TSW_POSITION)    /* 56�s */
#define TSW_52              (13u << _TSW_POSITION)    /* 52�s */
#define TSW_48              (12u << _TSW_POSITION)    /* 48�s */
#define TSW_44              (11u << _TSW_POSITION)    /* 44�s */
#define TSW_40              (10u << _TSW_POSITION)    /* 40�s */
#define TSW_36              (9u << _TSW_POSITION)     /* 36�s */
#define TSW_32              (8u << _TSW_POSITION)     /* 32�s */
#define TSW_28              (7u << _TSW_POSITION)     /* 28�s */
#define TSW_24              (6u << _TSW_POSITION)     /* 24�s */
#define TSW_20              (5u << _TSW_POSITION)     /* 20�s */
#define TSW_16              (4u << _TSW_POSITION)     /* 16�s */
#define TSW_12              (3u << _TSW_POSITION)     /* 12�s */
#define TSW_8               (2u << _TSW_POSITION)     /* 8�s  */
#define TSW_4               (0u)                      /* 4�s  */

// Slew rate value of the power bridge output - values are mutually exclusive
#define POW_SR_270              (3u << _POW_SR_POSITION)     /* 270 [V/�s] */
#define POW_SR_110              (2u << _POW_SR_POSITION)     /* 110 [V/�s] */
#define POW_SR_75               (1u << _POW_SR_POSITION)     /* 75 [V/�s]  */
#define POW_SR_320              (0u)                         /* 320 [V/�s] */



//------------------------------------------------------------------------------
//            L6470    Available options for config parameter
//------------------------------------------------------------------------------
#define _EN_VSCOMP_POSITION   0x0005
#define _F_PWM_DEC_POSITION   0x000A
#define _F_PWM_INT_POSITION	  0x000D


// Overcurrent event - values are mutually exclusive
#define OC_SD_ON                (1u << _OC_SD_ON_POSITION)   /*Bridges shut down */
#define OC_SD_OFF		(0u)                         /*Bridges do not shut down */

// Torque regulation - values are mutually exclusive
#define EN_TQREG_ON             (1u << _EN_TQREG_ON_POSITION)   /* ADC_OUT prevalue is used to regulate output current amplitude */
#define EN_TQREG_OFF		(0u)                         /*output current amplitude is managed by the TVAL_HOLD, TVAL_RUN, TVAL_ACC and TVAL_DEC registers  */

// External switch hard stop interrupt mode - values are mutually exclusive
#define SW_MODE_OFF              (1u << _SW_MODE_ON_POSITION)   /*User disposal */
#define SW_MODE_ON		(0u)                         /*HardStop interrupt  */

// External
#define EXT_CLK_ON            (1u << _EXT_CLK_ON_POSITION)
#define EXT_CLK_OFF		(0u)
#define EXT_CLK_OSC_SEL_DEFAULT     0x04 // EXTERN CLOCK


//------------------------------------------------------------------------------
//                Limit values
//------------------------------------------------------------------------------
/*L6470_INT_SPEED*/
#define INT_SPEED_MAX_PARAM    		0x3FFF  //976.5 step/s
#define INT_SPEED_MIN_PARAM     	0x0000  //0 step/

/*KVAL_X*/
#define MAX_KVAL_X_PARAM        0x00FF   //0.996 x VS
#define MIN_KVAL_X_PARAM        0x0000   //
/*L6470_ST_SLP*/
#define MAX_ST_SLP_PARAM        0x00FF   //0.004
#define MIN_ST_SLP_PARAM        0x0000   //0

/*FN_SLP_X*/
#define MAX_FN_SLP_X_PARAM      0x00FF   //0.004
#define MIN_FN_SLP_X_PARAM      0x0000   //0

/*L6470_K_THERM*/
#define MAX_K_THERM_PARAM       0x000F   //1.46875
#define MIN_K_THERM_PARAM       0x0000   //1

/*L647x_ADC_OUT*/
#define MAX_ADC_OUT_PARAM       0x001F   //0.65625
#define MIN_ADC_OUT_PARAM       0x0000   //1.968875

/*L6470_STALL_TH*/
#define MAX_STALL_TH_PARAM      0x007F   //4 A
#define MIN_STALL_TH_PARAM      0x0000   //31.25 mA




//#define EXT_CLK_OSC_SEL_DEFAULT     0x08 // INTERN CLOCK
typedef enum {
    L647x_ABS_POS     =((uint8_t)0x01),   /*< Current position */
    L647x_EL_POS      =((uint8_t)0x02),   /*< Electrical position */
    L647x_MARK        =((uint8_t)0x03),   /*< Mark position */
    L647x_SPEED       =((uint8_t)0x04),   /*< Current speed */
    L647x_ACC         =((uint8_t)0x05),   /*< Acceleration */
    L647x_DEC         =((uint8_t)0x06),   /*< Deceleration */
    L647x_MAX_SPEED   =((uint8_t)0x07),   /*< Maximum speed */
    L647x_MIN_SPEED   =((uint8_t)0x08),   /*< Minimum speed */

    L6472_TVAL_HOLD   =((uint8_t)0x09),   /*< Holding Tval */
    L6470_KVAL_HOLD   =((uint8_t)0x09),   /*< Holding Kval */
    L647x_VAL_HOLD    =((uint8_t)0x09),   /*< Holding generic value */

    L6472_TVAL_RUN    =((uint8_t)0x0A),   /*< Constant speed Tval */
    L6470_KVAL_RUN    =((uint8_t)0x0A),   /*< Constant speed Kval */
    L647x_VAL_RUN     =((uint8_t)0x0A),   /*< Constant speed generic value */

    L6472_TVAL_ACC    =((uint8_t)0x0B),   /*< Acceleration starting Tval */
    L6470_KVAL_ACC    =((uint8_t)0x0B),   /*< Acceleration starting Kval */

    L6472_TVAL_DEC    =((uint8_t)0x0C),   /*< Deceleration starting Tval */
    L6470_KVAL_DEC    =((uint8_t)0x0C),   /*< Deceleration starting Kval */

    L6470_INT_SPEED   =((uint8_t)0x0D),   /*< Intersect */

    L6472_T_FAST      =((uint8_t)0x0E),   /*< Fast decay/fall step time */
    L6470_ST_SLP      =((uint8_t)0x0E),   /*< Start slope */

    L6472_TON_MIN     =((uint8_t)0x0F),   /*< Minimum ON time */
    L6470_FN_SLP_ACC  =((uint8_t)0x0F),   /*< Acceleration final slope */

    L6472_TOFF_MIN    =((uint8_t)0x10),   /*< Minimum OFF time */
    L6470_FN_SLP_DEC  =((uint8_t)0x10),   /*< Deceleration final slope */

    L6470_K_THERM     =((uint8_t)0x11),   /*< Thermal compensation factor */
    L647x_ADC_OUT     =((uint8_t)0x12),   /*< ADC output */
    L647x_OCD_TH      =((uint8_t)0x13),   /*< OCD threshold */
    L6470_STALL_TH    =((uint8_t)0x14),   /*< STALL threshold */
    L647x_FS_SPD      =((uint8_t)0x15),   /*< Full step speed */
    L647x_STEP_MODE   =((uint8_t)0x16),   /*< Step mode */
    L647x_ALARM_EN    =((uint8_t)0x17),   /*< Alarms enables */
    L647x_CONFIG      =((uint8_t)0x18),   /*< IC configuration */
    L647x_STATUS      =((uint8_t)0x19),   /*< Status */
}L647x_register_list_t;
typedef enum {
	MOTOR_SWITCH_DISABLE, MOTOR_SWITCH_ENABLE,
} motor_switch_status_t;

//------------------------------------------------------------------------------
//                Step mode parameter
//------------------------------------------------------------------------------
/*When the L647x_STEP_MODE register is written, the bit #3 is should be set 0,
 * otherwise anomalous behaviors could occur.*/
typedef enum {
    FULL_STEP_MODE_PARAM                        = (uint8_t)0x00,    /*Pas entier*/
    HALF_STEP_MODE_PARAM                        = (uint8_t)0x01,    /*1/2 pas*/
    QUART_STEP_MODE_PARAM                       = (uint8_t)0x02,    /*1/4 de pas*/
    EIGHTH_STEP_MODE_PARAM                      = (uint8_t)0x03,    /*1/8 de pas*/
    SIXTEENTH_STEP_MODE_PARAM                   = (uint8_t)0x04,    /*1/16 de pas*/
    THIRTY_SECOND_STEP_MODE_PARAM               = (uint8_t)0x05,    /*1/32 de pas*/
    SIXTY_FOURTH_STEP_MODE_PARAM                = (uint8_t)0x06,    /*1/64 de pas*/
    ONE_HUNDRED_TWENTY_EIGHTH_STEP_MODE_PARAM   = (uint8_t)0x07     /*1/128 de pas*/
}motor_step_mode_param_t;

//------------------------------------------------------------------------------
//                ALARM_EN register
//------------------------------------------------------------------------------
typedef enum {
	OVERCURRENT_ALARM, SHUTDOWN_ALARM, WARNING_ALARM, UNDERVOLTAGE_ALARM, TURN_ON_EVENT_ALARM, WRONG_COMMAND_ALARM, NO_ALARM,
} alarm_reg_t;

//------------------------------------------------------------------------------
//                STATUS register
//------------------------------------------------------------------------------
typedef enum {
	SCK_MOD, OCD, TH_SD, TH_WRN, UVLO, WRONG_CMD, NOTPERF_CMD, MOT_STATUS, DIR, SW_EVN, SW_F, BUSY, HiZ,

	STATUS_REG_NBER,
} status_reg_t;



#define SCK_MOD_MASK        0x8000
#define OCD_MASK            0x1000
#define TH_SD_MASK          0x0800
#define TH_WRN_MASK         0x0400
#define UVLO_MASK           0x0200
#define WRONG_CMD_MASK      0x0100
#define NOTPERF_CMD_MASK    0x0080
#define MOT_STATUS_MASK     0x0060
#define DIR_MASK            0x0010
#define SW_EVN_MASK         0x0008
#define SW_F_MASK           0x0004
#define BUSY_MASK           0x0002
#define HIZ_MASK            0x0001

#define SCK_MOD_DECAL        0x0F
#define OCD_DECAL            0x0C
#define TH_SD_DECAL          0x0B
#define TH_WRN_DECAL         0x0A
#define UVLO_DECAL           0x09
#define WRONG_CMD_DECAL      0x08
#define NOTPERF_CMD_DECAL    0x07
#define MOT_STATUS_DECAL     0x05
#define DIR_DECAL            0x04
#define SW_EVN_DECAL         0x03
#define SW_F_DECAL           0x02
#define BUSY_DECAL           0x01
#define HIZ_DECAL            0x00

typedef struct {
	uint16_t mask;
	uint8_t decal;
} str_status_reg;

//------------------------------------------------------------------------------
//                Application commands
//------------------------------------------------------------------------------
typedef enum {
	CMD_NOP = ((uint8_t) 0x00), CMD_SET_PARAM = ((uint8_t) 0x00),/*Writes VALUE in the PARAM register*/
	CMD_GET_PARAM = ((uint8_t) 0x20),/*Returns the stored value in the PARAM register*/
	CMD_RUN = ((uint8_t) 0x50),/*Sets the target speed and the motor direction*/
	CMD_STEP_CLOCK = ((uint8_t) 0x58),/*Puts the device into step-clock mode andimposes DIR direction */
	CMD_MOVE = ((uint8_t) 0x40),/*Makes N_STEP (micro) steps in DIR direction (non-performable when motor is running) */
	CMD_GOTO = ((uint8_t) 0x60),/*Brings motor in ABS_POS position (minimum  path) */
	CMD_GOTO_DIR = ((uint8_t) 0x68),/*Brings motor in ABS_POS position forcing DIR direction */
	CMD_GO_UNTIL = ((uint8_t) 0x82),/*Performs a motion in DIR direction with speed  SPD until SW is closed, the ACT action is
	 executed then a SoftStop takes place */
	CMD_GO_UNTIL_ACT_CPY = ((uint8_t) 0x8A), CMD_RELEASE_SW = ((uint8_t) 0x92),/*Performs a motion in DIR direction at minimum
	 speed until the SW is released (open), the ACT
	 action is executed then a HardStop takes place */
	CMD_GO_HOME = ((uint8_t) 0x70),/*Brings the motor in HOME position */
	CMD_GO_MARK = ((uint8_t) 0x78), /*Brings the motor in MARK position */
	CMD_RESET_POS = ((uint8_t) 0xD8),/*Resets the ABS_POS register (set HOMEposition) */
	CMD_RESET_DEVICE = ((uint8_t) 0xC0),/*Device is reset to power-up conditions */
	CMD_SOFT_STOP = ((uint8_t) 0xB0),/*Stops motor with a deceleration phase*/
	CMD_HARD_STOP = ((uint8_t) 0xB8), /*Stops motor immediately*/
	CMD_SOFT_HIZ = ((uint8_t) 0xA0),/*Puts the bridges in high-impedance status after a deceleration phase*/
	CMD_HARD_HIZ = ((uint8_t) 0xA8),/*Puts the bridges in high-impedance status immediately */
	CMD_GET_STATUS = ((uint8_t) 0xD0), /*Returns the STATUS register value*/
	CMD_RESERVED_CMD2 = ((uint8_t) 0xEB), CMD_RESERVED_CMD1 = ((uint8_t) 0xF8)
} L6472_Commands_t;



#endif /* GENERIC_PERIPHERAL_L647XH_H_ */
