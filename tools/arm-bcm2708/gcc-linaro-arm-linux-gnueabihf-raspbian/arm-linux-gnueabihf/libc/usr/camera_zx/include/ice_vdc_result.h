/*! \file ice_vd_result.h
\brief ice_vd_result.h document.
*/
#ifndef __ICE_VDC_RESULT_H__
#define __ICE_VDC_RESULT_H__

#include "ice_base_type.h"
#include "ice_vlpr_result.h"
#include "ice_vdc_config.h"
#include "ice_vehibrand_interface.h"
#include "ice_com_type.h"

#ifdef __cplusplus
extern "C"
{
#endif


typedef enum
{
	ICE_VDC_HD_TRIGER,						//ʵʱ_Ӳ����+��ʱ����(0),
	ICE_VDC_VIDEO_TRIGER, 					//ʵʱ_��Ƶ����+��ʱ������1����
	ICE_VDC_SOFT_TRIGER,					//ʵʱ_����+��ʱ������2����
	ICE_VDC_HD_TRIGER_AND_WHITELIST,		//ʵʱ_Ӳ����+��Ч������(3),
	ICE_VDC_VIDEO_TRIGER_AND_WHITELIST,		//ʵʱ_��Ƶ����+��Ч��������4����
	ICE_VDC_SOFT_TRIGER_AND_WHITELIST,  	//ʵʱ_����+��Ч��������5����
	ICE_VDC_HD_TRIGER_AND_BLACKLIST,		//ʵʱ_Ӳ����+������(6),
	ICE_VDC_VIDEO_TRIGER_AND_BLACKLIST,		//ʵʱ_��Ƶ����+��������7����
	ICE_VDC_SOFT_TRIGER_AND_BLACKLIST,  	//ʵʱ_����+��������8����
	
	ICE_VDC_NC_HD_TRIGER,					//�ѻ�_Ӳ����+��ʱ����(9),
	ICE_VDC_NC_VIDEO_TRIGER, 				//�ѻ�_��Ƶ����+��ʱ������10����
	ICE_VDC_NC_SOFT_TRIGER,					//�ѻ�_����+��ʱ������11����
	ICE_VDC_NC_HD_TRIGER_AND_WHITELIST,		//�ѻ�_Ӳ����+��Ч������(12),
	ICE_VDC_NC_VIDEO_TRIGER_AND_WHITELIST,	//�ѻ�_��Ƶ����+��Ч��������13����
	ICE_VDC_NC_SOFT_TRIGER_AND_WHITELIST,  	//�ѻ�_����+��Ч��������14����
	ICE_VDC_NC_HD_TRIGER_AND_BLACKLIST,		//�ѻ�_Ӳ����+������(15),
	ICE_VDC_NC_VIDEO_TRIGER_AND_BLACKLIST,	//�ѻ�_��Ƶ����+��������16����
	ICE_VDC_NC_SOFT_TRIGER_AND_BLACKLIST,  	//�ѻ�_����+��������17����
	
	ICE_VDC_HD_TRIGER_AND_OVERDUE_WHITELIST,		//ʵʱ_Ӳ����+���ڰ�����(18),
	ICE_VDC_VIDEO_TRIGER_AND_OVERDUE_WHITELIST,		//ʵʱ_��Ƶ����+���ڰ�������19����
	ICE_VDC_SOFT_TRIGER_AND_OVERDUE_WHITELIST,  	//ʵʱ_����+���ڰ�������20����
	ICE_VDC_NC_HD_TRIGER_AND_OVERDUE_WHITELIST,		//�ѻ�_Ӳ����+���ڰ�����(21),
	ICE_VDC_NC_VIDEO_TRIGER_AND_OVERDUE_WHITELIST,	//�ѻ�_��Ƶ����+���ڰ�������22����
	ICE_VDC_NC_SOFT_TRIGER_AND_OVERDUE_WHITELIST,  	//�ѻ�_����+���ڰ�������23����
	
	ICE_VDC_ALARM_UNKOWN,
}ICE_VDC_ALARM_TYPE;

//��������
typedef enum
{
	ICE_VDC_HD_TRIGGER,						//Ӳ����,
	ICE_VDC_VIDEO_TRIGGER, 					//��Ƶ������
	ICE_VDC_SOFT_TRIGGER,					//������
	ICE_VDC_TRIGGER_UNKOWN,
}ICE_VDC_TRIGGER_TYPE;

//!��������
typedef enum
{
	ICE_VDC_PLATE_TEMP,			  //��ʱ����0
	ICE_VDC_PLATE_WHITELIST,		  //��Ч������1
	ICE_VDC_PLATE_BLACKLIST,		  //������2,
	ICE_VDC_PLATE_OVERDUE_WHITELIST, //���ڰ�����3
	ICE_VDC_PLATE_UNKOWN,
}ICE_VDC_PLATE_TYPE; 

typedef struct
{
	ICE_VLPR_OUTPUT_S stPlateInfo;//������Ϣ
	ICE_VDC_PLATE_TYPE s32PlateType; //��������
	ICE_U16 u32StartYear; //��������Ч����ʼʱ��
	ICE_U8 u32StartMon;
	ICE_U8 u32StartDay;
	ICE_U16 u32EndYear; //��������Ч�ڽ���ʱ��
	ICE_U8 u32EndMon;
	ICE_U8 u32EndDay;
	ICE_SYSTEMTIME_S  stLiveCapTime;    					//!< ʵʱ���� ץ��ʱ��
	ICE_S32 u32Reserved[6];  
}ICE_VDC_CAR_INFO_S;


typedef enum
{
	ICE_VDC_VEHICLE_TYPE_UNKOWN				= 0,			//!<  δ֪
	ICE_VDC_VEHICLE_TYPE_NORMAL_CAR			= 1,			//!<  �γ�
	ICE_VDC_VEHICLE_TYPE_MINIBUS			= 2,			//!<  �����
	ICE_VDC_VEHICLE_TYPE_BUS				= 3,			//!<  ���Ϳͳ�
	ICE_VDC_VEHICLE_TYPE_MEDIUMBUS			= 4,			//!<  ���Ϳͳ�
	ICE_VDC_VEHICLE_TYPE_PICK_UP_TRUCK		= 5,			//!<  Ƥ��
	ICE_VDC_VEHICLE_TYPE_NONMOTORIZED	    = 6,			//!<  �ǻ�����
	ICE_VDC_VEHICLE_TYPE_SUV				= 7,			//!<  SUV
	ICE_VDC_VEHICLE_TYPE_MPV				= 8,			//!<  MPV
	ICE_VDC_VEHICLE_TYPE_MINITRUCK			= 9,			//!<  ΢�ͻ���
	ICE_VDC_VEHICLE_TYPE_PICKUPTRUCK		= 10,			//!<  ���ͻ���
	ICE_VDC_VEHICLE_TYPE_MEDIUMTRUCK		= 11,			//!<  ���ͻ���
	ICE_VDC_VEHICLE_TYPE_HEAVYTRUCK			= 12,			//!<  ���ͻ���
}ICE_VDC_VEHICLETYPE_E;



//! \ingroup group_vd
//! ͼƬ��Ϣ���ݽṹ
typedef struct 
{
	ICE_S32 s32EventCode;									//!< �¼���
	ICE_S32   s32LandId;									//!< ����ID
#ifdef X64
	ICE_CHAR  cFileName[120];  								//!< �ļ���
#else
	ICE_CHAR  cFileName[124];  								//!< �ļ���
#endif
	ICE_VBR_RESULT_S *pstVbrResult;							//!< ������
	ICE_VDC_ALARM_TYPE   s32AlarmType;						//!< ������������
	ICE_SYSTEMTIME_S  stLiveCapTime;    					//!< ʵʱ���� ץ��ʱ��
	ICE_U32  u32SerialNum;  								//!< ������ˮ��     	
	ICE_U32  u32PlateWidth;  								//!< ʵ�ʳ������	
	ICE_U32  u32ExtSnapPixel;  								//!< ץ��ͼ��osd���ظ߶�
	ICE_Phone_Mac_List* pPhoneMacList;						//!< ���յ��ն�mac�б�
#ifndef X64
	ICE_CHAR  cPhoneMacListReserve[4];  					//!< mac�б�64λָ�����Ԥ��
#endif
	ICE_U32	 u32PictureHashID;								//!< ͼƬ��ϣID
	ICE_CHAR  cReserve[76];									//!< Ԥ��
	ICE_S32 enVehicleColor;					//!< ������ɫ
	ICE_VDC_VEHICLETYPE_E s32VehicleType;					//!< ��������
	ICE_SYSTEMTIME_S  stCapTime;    						//!< ץ��ʱ��
	ICE_S32    s32HaveCloseUp;     							//!< �Ƿ�����дͼ��
	ICE_RECT_S stVehilceRect;	  							//!< �������
	ICE_VDC_VERHICLE_DIR_E 	enDirect;         	            //!< ��������
	ICE_FLOAT 	fSpeed;         	                		//!< �����ٶ�(��λ:ǧ��/Сʱ)
	ICE_CHAR 	cVehicleColor[32];							//!< ������ɫ
	ICE_CHAR 	cPlateColor[32];							//!< ������ɫ
	ICE_S32    s32HavePlate;       							//!< �Ƿ���ڳ���                						
	ICE_VLPR_OUTPUT_S stPlateInfo;							//!< ������Ϣ
	ICE_S16    s16PicWidth;     							//!< ͼƬ���					   						
	ICE_S16    s16PicHeight;     							//!< ͼƬ�߶�
	ICE_S32   s32PicDataLen;								//!< ͼƬ��С
	ICE_S8    *ps8PictureData;     							//!< ͼƬ����					
}ICE_VDC_PICTRUE_INFO_S;


typedef struct 
{
	ICE_S32 s32EventCode;									//!< �¼���
	ICE_S32   s32LandId;									//!< ����ID    			   	   						
#ifdef X64
	ICE_CHAR  cFileName[120];  								//!< �ļ���
#else
	ICE_CHAR  cFileName[124];  								//!< �ļ���
#endif
	ICE_VBR_RESULT_S *pstVbrResult;							//!< ������
	ICE_VDC_ALARM_TYPE   s32AlarmType;						//!< ������������
	ICE_SYSTEMTIME_S  stLiveCapTime;    					//!< ʵʱ���� ץ��ʱ��
	ICE_U32  u32SerialNum;  								//!< ������ˮ��     	
	ICE_U32  u32PlateWidth;  								//!< ʵ�ʳ������	
	ICE_U32  u32ExtSnapPixel;  								//!< ץ��ͼ��osd���ظ߶�	
	ICE_Phone_Mac_List* pPhoneMacList;						//!< ���յ��ն�mac�б�
#ifndef X64
	ICE_CHAR  cPhoneMacListReserve[4];  					//!< mac�б�64λָ�����Ԥ��
#endif
	ICE_U32	 u32PictureHashID;							//!< ͼƬ��ϣID
	ICE_CHAR  cReserve[76];									//!< Ԥ��
	ICE_S32 enVehicleColor;					//!< ������ɫ
	ICE_VDC_VEHICLETYPE_E s32VehicleType;					//!< ��������
	ICE_SYSTEMTIME_S  stCapTime;    						//!< ץ��ʱ��     			   						
	ICE_S32    s32HaveCloseUp;     							//!< �Ƿ�����дͼ��     						
	ICE_RECT_S stVehilceRect;	  							//!< �������    			   						
	ICE_VDC_VERHICLE_DIR_E 	enDirect;         	            //!< �������� 								
	ICE_FLOAT 	fSpeed;         	                		//!< �����ٶ�(��λ:ǧ��/Сʱ) 							
	ICE_CHAR 	cVehicleColor[32];							//!< ������ɫ
	ICE_CHAR 	cPlateColor[32];							//!< ������ɫ
	ICE_S32    s32HavePlate;       							//!< �Ƿ���ڳ���                						
	ICE_VLPR_OUTPUT_S stPlateInfo;							//!< ������Ϣ
	ICE_S16    s16PicWidth;     							//!< ͼƬ���					   						
	ICE_S16    s16PicHeight;     							//!< ͼƬ�߶�
	ICE_S32   s32PicDataLen;								//!< ͼƬ��С
	ICE_S8    as8PictureData[1024*1024];     				//!< ͼƬ����					   						
}ICE_VDC_PICTRUE_INFO_BUFFER_S;

//! \ingroup group_vd
//!������������Ϣ���ݽṹ
typedef struct 
{
	ICE_S32 s32EventCode;									//!< �¼���
	ICE_S32   s32LandId;									//!< ����ID    			   	   						
#ifdef X64
	ICE_CHAR  cFileName[120];  								//!< �ļ���
#else
	ICE_CHAR  cFileName[124];  								//!< �ļ���
#endif
	ICE_VBR_RESULT_S *pstVbrResult;							//!< ������
	ICE_VDC_ALARM_TYPE   s32AlarmType;						//!< ������������
	ICE_SYSTEMTIME_S  stLiveCapTime;    					//!< ʵʱ���� ץ��ʱ��
	ICE_U32  u32SerialNum;  								//!< ������ˮ��     	
	ICE_U32  u32PlateWidth;  								//!< ʵ�ʳ������	
	ICE_U32  u32ExtSnapPixel;  								//!< ץ��ͼ��osd���ظ߶�	
	ICE_Phone_Mac_List* pPhoneMacList;						//!< ���յ��ն�mac�б�
#ifndef X64
	ICE_CHAR  cPhoneMacListReserve[4];  					//!< mac�б�64λָ�����Ԥ��
#endif
	ICE_U32	 u32PictureHashID;							//!< ͼƬ��ϣID
	ICE_CHAR  cReserve[76];									//!< Ԥ��
	ICE_S32 enVehicleColor;					//!< ������ɫ
	ICE_VDC_VEHICLETYPE_E s32VehicleType;					//!< ��������
	ICE_SYSTEMTIME_S  stCapTime;    						//!< ץ��ʱ��     			   						
	ICE_S32    s32HaveCloseUp;     							//!< �Ƿ�����дͼ��     						
	ICE_RECT_S stVehilceRect;	  							//!< �������    			   						
	ICE_VDC_VERHICLE_DIR_E 	enDirect;         	            //!< �������� 								
	ICE_FLOAT 	fSpeed;         	                		//!< �����ٶ�(��λ:ǧ��/Сʱ) 							
	ICE_CHAR 	cVehicleColor[32];							//!< ������ɫ
	ICE_CHAR 	cPlateColor[32];							//!< ������ɫ
	ICE_S32    s32HavePlate;       							//!< �Ƿ���ڳ���                						
	ICE_VLPR_RULT_S	stVlprRult;								//!< ������Ϣ
	ICE_S16    s16PicWidth;     							//!< ͼƬ���					   						
	ICE_S16    s16PicHeight;     							//!< ͼƬ�߶�
	ICE_S32   s32PicDataLen;								//!< ͼƬ��С
	ICE_S8    as8PictureData[1024*1024];     				//!< ͼƬ����					   						
}ICE_VDC_PICTRUE_INFO_BUFFER_EXT_S;



typedef struct 
{				   						
	ICE_S32   s32CloseupPicDataLen;								//!< ͼƬ��С
	ICE_S8    as8CloseupPictureData[64*1024];     				//!< ͼƬ����	
}ICE_VDC_PICTRUE_INFO_BUFFER2_S;




//! \ingroup group_vd
//!������������Ϣ���ݽṹ
typedef struct 
{
	void *pRgbOImage;								//!< ԭʼRBGͼ��
	void *pRgbPImage;								//!< ������Ȧ�����RBGͼ��
	void *pRgbCImage[3];							//!< ��дRBGͼ���б�,��Ӧ��ͬ�ĳ���
	void *pRgbPlateImage[3];						//!< ����RBGͼ���б�,��Ӧ��ͬ�ĳ���
	ICE_S32 s32EventCode[4];						//!< �����¼���			
	ICE_S32    s32HavePlate[4];						//!< �Ƿ���ڳ���
	ICE_VLPR_OUTPUT_S pVlprResult[4];				//!< ������Ϣ
	ICE_CHAR cPlateColor[4][32];					//!< ������ɫ
}ICE_VDC_DEBUG_INFO_S;

/*----------------------------------------------*
* vdc result defination            				*
*----------------------------------------------*/ 
typedef struct 
{
	ICE_S32 s32IsNight;										//!< ҹ���־(1��ʾҹ�� 0��ʾ����)    			
	ICE_S32 s32IsTriger;									//!< �ⴥ����־(1��ʾǿ�ƴ��� 0��ʾ�ڲ�����)    			
	ICE_S32 s32TrigerLaneId;								//!< �ⴥ������ID(0-3��-1��ʾ���г���ȫ������)
	ICE_S32 s32TrigerSpecialDeal;							//!< �ⴥ�����⴦���־(1��ʾ�������⴦�� 0���������⴦��)
	ICE_S32 u32Reserved[13];                         		//!< ����
}ICE_VDC_OUT_INTFC_S;

#ifdef __cplusplus
}
#endif


#endif
	