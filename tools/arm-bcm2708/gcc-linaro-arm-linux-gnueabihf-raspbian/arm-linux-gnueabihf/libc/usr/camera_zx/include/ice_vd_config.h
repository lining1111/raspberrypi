/*! \file ice_vd_config.h
\brief ice_vd_config.h document.
*/

#ifndef __ICE_VD_CONFIG_H__
#define __ICE_VD_CONFIG_H__

#include "ice_base_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

//! \ingroup group_vd
//! ��������¼����Ͷ���
typedef enum 
{
	ICE_VD_LANE_EVENT_TYPE_NOON 						= 0x0000,				//!<  ��										
	ICE_VD_LANE_EVENT_TYPE_COMMON_PASS 					= 0x0001,				//!<  ��ͨ����			
	ICE_VD_LANE_EVENT_TYPE_TRUCK_FORBIDDEN  			= 0x0002,				//!<  ��������� 								
	ICE_VD_LANE_EVENT_TYPE_BUS_LANE_FORBIDDEN 			= 0x0004,				//!<  �Ƿ����������� 							
	ICE_VD_LANE_EVENT_TYPE_EMERGENCY_LANE_FORBIDDEN 	= 0x0008,				//!<  �Ƿ�ռ��Ӧ������ 							
	ICE_VD_LANE_EVENT_TYPE_NORMOTOR_FORBIDDEN 			= 0x0010,				//!<  �Ƿ�ռ�÷ǻ�������						
	ICE_VD_LANE_EVENT_TYPE_CROSS_LINE_FORBIDDEN 		= 0x0020,				//!<  �Ƿ�ѹ��								
	ICE_VD_LANE_EVENT_TYPE_CHANGE_LANE_FORBIDDEN 		= 0x0040,				//!<  �Ƿ��任����							
	ICE_VD_LANE_EVENT_TYPE_REVERSE_TRAFFIC 				= 0x0080,				//!<  ������ʻ								
	ICE_VD_LANE_EVENT_TYPE_OVER_SPEED 					= 0x0100				//!<  ������ʻ									
}ICE_VD_LANE_EVENT_TYPE_E;

//! \ingroup group_vd
//! ������⳵���߼���������
typedef struct 
{
	ICE_S32 s32AdaptiveThreshOnOff;					//!<  ����Ӧ��ֵ����  (1:�� 0:��  Ĭ��:��)								
	ICE_S32 s32DayTriggerThresh;					//!<  ���촥����ֵ    (��Χ:1-100 Ĭ��:25)													
	ICE_S32 s32NightTriggerThresh;					//!<  ҹ�䴥����ֵ    (��Χ:1-100 Ĭ��:50)													
	ICE_S32 s32TriggerSensitivity;					//!<  ����������      (��Χ:1-100 Ĭ��:10)													
	ICE_S32 s32FilterByPlate;						//!<  ���ƹ��˿���    (1:�� 0:��  Ĭ��:��)														
	ICE_S32 s32TrigerInterval;						//!<  �������        (��Χ:10-500  Ĭ��:50)
	ICE_S32 s32DetectDoubleDirectOnOff;				//!<  ���˫��������(1:�� 0:��  Ĭ��:��)
	ICE_S32 u32Reserved[14];                        //!<  ����ֵ     																					
}ICE_VD_LANE_ADV_PARAM_S;

//! \ingroup group_vd
//! ������ⷽ����
typedef enum 
{
	ICE_VD_VERHICLE_DIR_HEAD			 = 0,				//!<  ��ͷ���� 			
	ICE_VD_VERHICLE_DIR_TAIL			 = 1,				//!<  ��β���� 			
	ICE_VD_VERHICLE_DIR_HEAD_AND_TAIL	 = 2				//!<  ��ͷ�ͳ�β���� 	
}ICE_VD_VERHICLE_DIR_E;

//! \ingroup group_vd
//! �ٶȼ�ⷽ������
typedef enum 
{
	ICE_VD_MEASURE_SPEED_METHOD_VIDEO 		= 0,				//!<  ��Ƶ����			
	ICE_VD_MEASURE_SPEED_METHOD_RADAR 		= 1,				//!<  �״���� 			
	ICE_VD_MEASURE_SPEED_METHOD_INDUC_LOOP = 2					//!<  �ظ���Ȧ����	
}ICE_VD_MEASURE_SPEED_METHOD_E;


//! \ingroup group_vd
//! �״����Ͷ���
typedef enum 
{
	ICE_VD_RADAR_TYPE_NOON 				= 0,				//!<  ��						
	ICE_VD_RADAR_TYPE_ADL 					= 1,				//!<  �������״� 			
	ICE_VD_RADAR_TYPE_CS 					= 2,				//!<  �����״� 				
	ICE_VD_RADAR_TYPE_MTY 					= 3					//!<  èͷӥ 				
}ICE_VD_RADAR_TYPE_E;

//! \ingroup group_vd
//! �״��������
typedef struct 
{
	ICE_VD_RADAR_TYPE_E enRadarType;				 	//!<  �״����� 									
	ICE_S32 s32ComId;								//!<  ���� id��1-10�� 	
	ICE_S32 s32Baud;								//!<  ������
	ICE_S32 s32RadarSensitivity;					//!<  �״������Ȳ���								
	ICE_S32 u32Reserved[15];                        //!<  ����     										
}ICE_VD_RADAR_PARAM_S;


//! \ingroup group_vd
//! IO״̬����
typedef enum 
{
	ICE_VD_IO_STATUS_TYPE_FAILING_EDGE 						= 0,						//!<  �½�����Ч 			
	ICE_VD_IO_STATUS_TYPE_RISING_EDGE 						= 1,						//!<  ��������Ч 			
	ICE_VD_IO_STATUS_TYPE_RISING_EDGE_AND_FAILING_EDGE		= 2, 						//!<  �����ػ��½�����Ч		
	ICE_VD_IO_STATUS_TYPE_HIGH_LEVEL 						= 3,						//!<  �ߵ�ƽ��Ч 			
	ICE_VD_IO_STATUS_TYPE_LOW_LEVEL 						= 4							//!<  �͵�ƽ��Ч 			
}ICE_VD_IO_STATUS_TYPE_E;

//! \ingroup group_vd
//! IO��Ȧ���������
 typedef struct 
{
	ICE_S32 s32OnOff;				 				//!<  �Ƿ����ñ�־  	  Ĭ�ϣ�1						
	ICE_S32 s32IoLoop1Id;				 			//!<  IO��Ȧ1��id ��1-8�� Ĭ�ϣ�1						
	ICE_VD_IO_STATUS_TYPE_E enIoLoop1InStatus;		//!<  IO��Ȧ1����״̬     Ĭ�ϣ�0						
	ICE_S32 s32IoLoop2Id;				 			//!<  IO��Ȧ2��id ��1-8�� Ĭ�ϣ�2						
	ICE_VD_IO_STATUS_TYPE_E enIoLoop2InStatus;		//!<  IO��Ȧ2����״̬     Ĭ�ϣ�0						
	ICE_S32 s32LoopDistance;						//!<  ��Ȧʵ�ʾ��루��λ�����棩        Ĭ�ϣ�600cm		
	ICE_S32 u32Reserved[16];                        //!<  ����     										
}ICE_VD_IO_LOOP_GROUP_PARAM_S;

 //! \ingroup group_vd
 //! ��IO��Ȧ��������
 typedef struct 
{
	ICE_S32 s32OnOff;				 				//!<  �Ƿ����ñ�־  		 Ĭ�ϣ�1						
	ICE_S32 s32IoLoopId;				 			//!<  IO��Ȧ��id ��1-4��  Ĭ�ϣ�1						
	ICE_VD_IO_STATUS_TYPE_E enIoLoopInStatus;		//!<  IO��Ȧ����״̬      Ĭ�ϣ�0						
	ICE_S32 u32Reserved[16];                        //!<  ����     										
}ICE_VD_IO_LOOP_SINGLE_PARAM_S;

#define ICE_MAX_IO_LOOP_GROUP_NUM 4

 //! \ingroup group_vd
 //! IO��Ȧ�鼯�ϲ�������
typedef struct 
{
	ICE_VD_IO_LOOP_GROUP_PARAM_S stLoopGroupParam[ICE_MAX_IO_LOOP_GROUP_NUM];		//!<  IO��Ȧ�����ò��� ,���ڿ���+����ʹ��    				
	ICE_S32 u32Reserved[16];                        							//!<  ����     											
}ICE_VD_IO_LOOP_G_PARAM_S;

#define ICE_MAX_IO_LOOP_SINGLE_NUM 4

//! \ingroup group_vd
//! ��IO��Ȧ���ϲ�������
typedef struct 
{
	ICE_VD_IO_LOOP_SINGLE_PARAM_S stLoopSingleParam[ICE_MAX_IO_LOOP_SINGLE_NUM];	//!<  IO����Ȧ���ò��� ,���ڿ���ʹ��    						
	ICE_S32 u32Reserved[16];                        								//!<  ����     											
}ICE_VD_IO_LOOP_S_PARAM_S;

//! \ingroup group_vd
//! Ӳ����������������
typedef struct 
{
	ICE_S32 u32Reserved[16];                        //!<  ����     										
}ICE_VD_LOOP_VD_PARAM_S;

//! \ingroup group_vd
//! Ӳ���豸��������
typedef union 
{
	ICE_VD_RADAR_PARAM_S stRadarParam;					//!<  �״���� 
	ICE_VD_IO_LOOP_S_PARAM_S stIoLoopSingleParam;		//!<  ��IO��Ȧ 
	ICE_VD_IO_LOOP_G_PARAM_S stIoLoopGroupParam;		//!<  ��IO��Ȧ 
	ICE_VD_LOOP_VD_PARAM_S stLoopVdParam;				//!<  ������ 
	ICE_S32 u32Reserved[16];							//!<  ����     										
}ICE_VD_HARDWARE_DEVICE_PARAM_S;

//! \ingroup group_vd
//! �ٶȲ�������
typedef struct 
{
	ICE_S32 s32DetectSpeedOnOff;				 		//!<  �ٶȼ�⿪�� (1:�� 0:��  Ĭ��:0) 			
	ICE_VD_MEASURE_SPEED_METHOD_E enMeasureSpdMethod;	//!<  �ٶȼ�ⷽ��																 			
	ICE_S32 s32LimitSpeedValue;				 			//!<  ����ֵ(��λ:ǧ��/Сʱ)   		  														
	ICE_S32 s32SignLimitSpeedValue;				 		//!<  �ο�����ֵ(��λ:ǧ��/Сʱ)  										
	ICE_FLOAT fLoopRealDist;				 			//!<  ��Ȧʵ�ʾ���(��)   		  																
	ICE_FLOAT fSpeedAdjustCoeff;				 		//!<  �ٶȵ���ϵ��(��Χ:0.1-10)   		  															
	ICE_S32 u32Reserved[8];								//!<  ����     																					
}ICE_VD_SPEED_PARAM_S;

//! \ingroup group_vd
//! ѹ�߲�������
typedef struct
{
	ICE_S32 s32DetectCrossLineOnOff;				 //!<  ѹ�߼�⿪�� (1:�� 0:��  Ĭ��:0) 	
	ICE_LINE_S stCrossLine;							 //!<  �ߵ�λ����Ϣ 																					
	ICE_S32 s32MinDist;								 //!<  ѹ������������					
	ICE_S32 u32Reserved[4];							 //!<  ����     																					
}ICE_VD_CROSS_LINE_PARAM_S;

//! \ingroup group_vd
//! ʱ�����Ʋ�������
typedef struct 
{
	ICE_S32 s32LimitTimeOnOff;				 		//!<  ʱ�����ƿ��� (1:�� 0:��  Ĭ��:0) 
	ICE_S32 s32BeginTime;				 			//!<  ��ʼʱ��(��8λ��Ԥ���� �θ�8λ(ʱ) �ε�8λ���֣� ��8λ���룩)   							
	ICE_S32 s32EndTime;				 				//!<  ����ʱ��(��8λ��Ԥ���� �θ�8λ(ʱ) �ε�8λ���֣� ��8λ���룩)   		 					
	ICE_S32 s32LimitEventCode;						//!<  ����ʱ����¼���(�¼������)			
	ICE_S32 u32Reserved[15];						//!<  ����     																					
}ICE_VD_LIMIT_TIME_PARAM_S;

//! \ingroup group_vd
//! ���Ʋ�������
#define ICE_VD_MAX_LIMIT_TIME_NUM 4
typedef struct 
{
	ICE_S32 s32ValidTimeQuantum;											//!<  ��Чʱ������� (0-4) 
	ICE_VD_LIMIT_TIME_PARAM_S astLimitTimeParam[ICE_VD_MAX_LIMIT_TIME_NUM];	//!<  ʱ�����Ʋ���     							
	ICE_S32 u32Reserved[15];                       							//!<  ����     								
}ICE_VD_LIMIT_PARAM_S;

//! \ingroup group_vd
//! ����ץ�Ĳ�������
typedef struct 
{
	ICE_S32 s32FlashOnOff;				 			//!<  ����ƿ��� (1:�� 0:��  Ĭ��:0) 											
	ICE_S32 s32FlashId;				 				//!<  ����� ID  																				
	ICE_S32 s32TrigerFlashLoopId;				    //!<  ��������Ƶ���ȦID(0��Ӧloop1 1��Ӧloop2)  																
	ICE_S32 s32FlashCapWaitTime;				    //!<  ����ץ��ͼƬ��ȴ�ʱ�� Ĭ��:100����λ�����룩 	
	ICE_S32 u32Reserved[16];                        //!<  ����     								
}ICE_VD_FLASH_CAP_PARAM_S;

//! \ingroup group_vd
//! ץ�Ĳ�������
typedef struct 
{
	ICE_S32 s32Loop1CapNum;							//!<  ��Ȧ1ץ��������0-2��	Ĭ�ϣ�1									
	ICE_S32 s32Loop2CapNum;							//!<  ��Ȧ2ץ��������0-2��	Ĭ�ϣ�0									
	ICE_S32 s32CapInterval;							//!<  ���֡�� 											
	ICE_VD_FLASH_CAP_PARAM_S stFlashCapParam;		//!<  ����ץ�²��� 											
	ICE_S32 u32Reserved[16];                        //!<  ����     													
}ICE_VD_CAP_PARAM_S;

//! \ingroup group_vd
//! �������Ͷ���
typedef enum 
{
	ICE_VD_TRIGER_TYPE_VIRTUAL_LOOP   						= 0,					//!<  ��Ƶ������Ȧ���� 									
	ICE_VD_TRIGER_TYPE_IO_SINGLE_LOOP   					= 1,					//!<  ���ظ���Ȧ���� 								
	ICE_VD_TRIGER_TYPE_IO_GROUP_LOOP   						= 2,					//!<  ��ظ���Ȧ���� 								
	ICE_VD_TRIGER_TYPE_VD_LOOP   							= 3,					//!<  ���������� 									
	ICE_VD_TRIGER_TYPE_RADAR   								= 4,					//!<  �״ﴥ�� 										
	ICE_VD_TRIGER_TYPE_IO_SINGLE_LOOP_AND_VIRTUAL_LOOP   	= 5,					//!<  ���ظ���Ȧ�����Ƶ������Ȧ�������ظ����� 			
	ICE_VD_TRIGER_TYPE_IO_GROUP_LOOP_AND_VIRTUAL_LOOP   	= 6,					//!<  ��ظ���Ȧ�����Ƶ������Ȧ�������ظ����� 			
	ICE_VD_TRIGER_TYPE_VD_LOOP_AND_VIRTUAL_LOOP   			= 7,					//!<  �����������Ƶ������Ȧ�������������� 				
	ICE_VD_TRIGER_TYPE_RADAR_AND_VIRTUAL_LOOP   			= 8,					//!<  �״�����Ƶ������Ȧ�������״����� 				
	ICE_VD_TRIGER_TYPE_IO_VIRTUAL_LOOP_AND_SINGLE_LOOP 		= 9,					//!<  ��Ƶ������Ȧ��ϵ��ظ���Ȧ��������Ƶ������Ȧ���� 		
	ICE_VD_TRIGER_TYPE_IO_VIRTUAL_LOOP_AND_GROUP_LOOP   	= 10,					//!<  ��Ƶ������Ȧ�����ظ���Ȧ��������Ƶ������Ȧ���� 		
	ICE_VD_TRIGER_TYPE_VIRTUAL_LOOP_AND_VD_LOOP   			= 11,					//!<  ��Ƶ������Ȧ��ϳ�������������Ƶ������Ȧ���� 			
	ICE_VD_TRIGER_TYPE_VIRTUAL_LOOP_AND_RADAR   			= 12					//!<  ��Ƶ������Ȧ����״ﴥ������Ƶ������Ȧ���� 			
}ICE_VD_TRIGER_TYPE_E;

        
#define ICE_MAX_VD_NUM 8											//!< max vehicele num  		
#define ICE_MAX_DETECT_REGION_NUM	4								//!< max detect region num  
#define ICE_MAX_LANE_NUM	     ICE_MAX_DETECT_REGION_NUM			//!< max lane num  	        

//! \ingroup group_vd
//! lane region defination             			
typedef struct 
{
	ICE_S32 s32LaneId;								//!< ����ID  (1-4)    																				
	ICE_POLYGON_S stPoly;				 			//!< ����ʶ����������  		  											
	ICE_S32 u32Reserved[16];                        //!< ����     																					
}ICE_VD_LANE_REGION_S;

//! \ingroup group_vd
//! ������������
typedef struct 
{																						
	ICE_VD_TRIGER_TYPE_E enTrigerType;						//!<  ������ʽ																					
	ICE_VD_VERHICLE_DIR_E enVehiceleDirection;				//!<  ��������											
	ICE_VD_LANE_EVENT_TYPE_E enEventCode;					//!<  �¼���(֧�ֶ��¼��밴λ���)
	ICE_VD_LANE_REGION_S stLaneRegion;						//!<  ��������																			
	ICE_RECT_S astLoop[2];				 					//!<  ������Ȧ
	ICE_VD_SPEED_PARAM_S stSpeedParam;						//!<  �ٶȲ���
	ICE_VD_CROSS_LINE_PARAM_S stCrossLineParam;				//!<  ѹ�߲���
	ICE_VD_LIMIT_PARAM_S stLimitParam;						//!<  ���Ʋ���																					
	ICE_VD_CAP_PARAM_S stCapParam;							//!<  ץ�Ĳ���																						
	ICE_VD_HARDWARE_DEVICE_PARAM_S stHardWareDeviceParam;	//!<  Ӳ���豸����																					
	ICE_VD_LANE_ADV_PARAM_S stAdvParam;						//!<  �߼�����																					
	ICE_S32 u32Reserved[16];                        		//!<  ����     																					
}ICE_VD_LANE_S;

//! \ingroup group_vd
//! OSD��������
typedef struct 
{
	ICE_S32   s32OsdOnOff;							//!<  �Ƿ�����ǰ��OSD����							
	ICE_CHAR  cDeviceID[64];  						//!<  �豸����ţ�									
	ICE_CHAR  cDeviceName[32];  					//!<  �豸����										
	ICE_CHAR  cCrossInfo[256];  					//!<  ��·��Ϣ										
	ICE_CHAR  cDirInfo[32];     					//!<  ������Ϣ										
	ICE_CHAR  cRoadInfo[32];    					//!<  ��·��Ϣ										
	ICE_CHAR  cRoadNum[32];     					//!<  �������										
	ICE_S32  s32SpeedOsdOnOff;						//!<  �Ƿ�����ٶ���Ϣ������ֵ�͵�ǰ�����ٶȣ�		
	ICE_S32  s32VehicleOsdOnOff;					//!<  �Ƿ���ӳ�����Ϣ��������ɫ �������ͣ�			
	ICE_S32  s32PlateOsdOnOff;						//!<  �Ƿ���ӳ�����Ϣ�����ƺ��� ������ɫ �������ͣ�	
	ICE_S16  s16PositionX;							//!<  ���ӵ���ʵλ��	x����							
	ICE_S16  s16PositionY;							//!<  ���ӵ���ʵλ��	y����							
	ICE_S32  s32RColor; 							//!<  ����OSD R��ɫ(0-255)									
	ICE_S32  s32GColor; 							//!<  ����OSD G��ɫ(0-255)									
	ICE_S32  s32BColor; 							//!<  ����OSD B��ɫ(0-255)								
	ICE_S32  s32AlphaColor; 						//!<  ����OSD ͸��ͨ����ɫ(0-255)								
	ICE_S32 u32Reserved[20];                        //!<  ����     									
}ICE_VD_OSD_CONFIG_S;

//! \ingroup group_vd
//! ��ͨ��������
typedef struct 
{
	ICE_S32   s32TrafficOnOff;							//!<  ������ͨ����ͳ�ƿ��� (1:�� 0:��  Ĭ��:0) 						
	ICE_S32   s32TrafficReportInterval;					//!<  �����ϱ�ʱ������Ĭ�ϣ�60����λ���� 0Ϊʵʱ�ϱ���			
	ICE_S32 u32Reserved[16];                        	//!<  ����     									
}ICE_VD_TRAFFIC_CONFIG_S;

//! \ingroup group_vd
//! ���Ʋ�������
typedef struct 
{
	ICE_S32	s32MinPlateWidth;						//!<  ��С���ƿ�� 									   
	ICE_S32	s32MaxPlateWidth;						//!<  ����ƿ�� 									 
	ICE_CHAR cPriorCity[32];					 	//!<  ���ȳ��� 										 
	ICE_S32	s32PlateConfidThrld;					//!<  ���ƿ��Ŷ���ֵ��-28-28����Ĭ�ϣ�15 			 
	ICE_FLOAT fPlateAngle;							//!<  ������б�Ƕȣ�Ĭ�ϣ�0 
	ICE_S32 s32PlateTypeSp;							//!<  ֧�ֳ�������     0Ĭ��ȫ��������
	ICE_S32	s32CarColorOn;							//!<  ������ɫ�����ã� 0������
	ICE_S32 s32PriorCityType;						//!<  ���ȳ�������
	ICE_S32 s32PriorArmyPlate;						//!<  ��������
	ICE_S32 u32Reserved[11];                        //!<  ����     									
}ICE_VD_PLATE_CONFIG_S;

//! \ingroup group_vd
//! �洢��������
typedef struct
{
	ICE_CHAR cSavePath[256];						//!<  �洢·�� 										   
	ICE_S32 u32Reserved[16];                        //!<  ����     									
}ICE_VD_SAVE_CONFIG_S;

//! \ingroup group_vd
//! �궨��������
typedef struct
{
	ICE_S32 s32CalibrationOnOff;					//!<  �Ƿ����궨
	ICE_LINE_S stHLine[2];							//!<  ˮƽ�����߶�
	ICE_FLOAT fHLineDist;							//!<  ˮƽ�����߶�ʵ�ʾ���
	ICE_LINE_S stVLine[2];							//!<  ��ֱ�����߶�
	ICE_FLOAT fVLineDist;							//!<  ��ֱ�����߶�ʵ�ʾ���
	ICE_S32 as32Reserved;							//!<  ���� 
}ICE_VD_CALIBRATION_S;
//! \ingroup group_vd
//! ��������������
typedef struct  
{
 	ICE_S32 s32LaneNum;									 	 	 //!<  ��Ч��������  		  					  		  
	ICE_VD_LANE_S astLane[ICE_MAX_LANE_NUM];				 	 //!<  �������� 		  						  
	ICE_VD_OSD_CONFIG_S stOsdParam;								 //!<  OSD����   		  						  		  
	ICE_VD_TRAFFIC_CONFIG_S stTrafficParam;						 //!<  ��ͨ����  		  						  	  
	ICE_VD_PLATE_CONFIG_S stPlateParam;							 //!<  ���Ʋ���   		  						  	  
	ICE_VD_SAVE_CONFIG_S stSaveParam;							 //!<  �洢����   		  						  		 
	ICE_S32 s32Width;											 //!<  �������ڲο�ͼ����		  						  	  
	ICE_S32 s32Height;											 //!<  �������ڲο�ͼ��߶�
	ICE_VD_CALIBRATION_S stCalbiration;							 //!<  �궨����
	ICE_S32 as32Reserved[8];              						 //!<  ���� 											  
}ICE_VD_PARAM_S;

#ifdef __cplusplus
}
#endif


#endif// __ICE_VD_CONFIG_H__
