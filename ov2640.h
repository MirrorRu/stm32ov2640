/**
  ******************************************************************************
  * File Name          : ov2640.h
  * Description        :
  *
  ******************************************************************************
  */
#ifndef __ov2640_H
#define __ov2640_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "i2c_routines.h"

typedef struct
{
  uint8_t Manufacturer_ID1;
  uint8_t Manufacturer_ID2;
  uint8_t PIDH;
  uint8_t PIDL;
} OV2640Id_TypeDef;
extern OV2640Id_TypeDef ov2640Id;

typedef enum {
	IF_QCIF,
	IF_QVGA,
	IF_CIF,
	IF_VGA,
	IF_SVGA,
	IF_XGA,
	IF_SXGA,
	IF_UXGA
} CameraImageFormat;

// Настройки камеры для съемки
typedef struct
{
	int8_t		resolution; 	// Разрешение съемки [0...7]
	int8_t		effects;	// Эффекты [0...7]
	int8_t		brightness;	// Яркость [-2..2]
	int8_t		contrast;	// Контрастность [-2..2]
	int8_t		saturation; 	// Насыщенность [-2..2]
	int8_t		light;		// Освещение [0...4]
} CameraSetupStruct;
extern CameraSetupStruct cameraSetup;

// Отклонение значений параметра
typedef enum {
	CPD_NORMAL = 0,
	CPD_PLUS1,
	CPD_PLUS2,
	CPD_MINUS1,
	CPD_MINUS2
} CameraParamDeviationEnum;

// Режим освещения
typedef enum {
	CL_AUTO = 0,
	CL_SUNNY,
	CL_CLOUDY,
	CL_OFFICE,
	CL_HOME
} CameraLightEnum;

// Эффект
typedef enum {
	CE_NORMAL = 0,
	CE_ANTIQUE,
	CE_BLUISH,
	CE_GREENISH,
	CE_REDDISH,
	CE_BW,
	CE_NEGATIVE,
	CE_BWNEGATIVE
} CameraEffectsEnum;

//void CameraReset();

void CameraReset();
void CameraReadId(OV2640Id_TypeDef *id);
void CameraEnable();
void CameraDisable();
void CameraInit();
uint32_t CameraGetPicture(uint8_t *buf, uint32_t maxBufSize);

//void Send2Camera(const struct_regval_list data[]);


//#define DCMI_TIMEOUT_MAX               100000

#define OV2640_DEVICE_WRITE_ADDRESS    0x60
#define OV2640_DEVICE_READ_ADDRESS     0x61


#ifdef __cplusplus
}
#endif
#endif /*__ov2640_H */
