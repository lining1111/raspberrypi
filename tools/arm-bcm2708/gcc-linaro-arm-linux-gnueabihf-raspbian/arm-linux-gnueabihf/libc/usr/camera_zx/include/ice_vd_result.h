/*! \file ice_vd_result.h
\brief ice_vd_result.h document.
*/
#ifndef __ICE_VD_RESULT_H__
#define __ICE_VD_RESULT_H__

#include "ice_base_type.h"
#include "ice_vlpr_result.h"
#include "ice_vd_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

//! \ingroup group_vd
//! �������ݽṹ
typedef struct 
{
	ICE_S32 	s32LaneId;         	                		//!< ����ID  								
	ICE_RECT_S  stRect;         	                		//!< ������� 										
	ICE_VD_VERHICLE_DIR_E 	enDirect;         	            //!< ��������  								
	ICE_FLOAT 	fSpeed;         	                		//!< �����ٶ�(��λ:ǧ��/Сʱ) 							
	ICE_CHAR 	cVehicleColor[32];							//!< ������ɫ  									
	ICE_BOOL 	bHasPlate;         	                		//!< �Ƿ��г���  							
	ICE_VLPR_OUTPUT_S stPlateInfo;							//!< ������Ϣ
	ICE_S32 	u32Reserved[15];                         	//!< ����     			    						
}ICE_VD_VEHICLE_S;

//! \ingroup group_vd
//! �����б����ݽṹ
typedef struct 
{
	ICE_S32 s32VehiceleNum;         	                //!< ��Ч�������� 	
	ICE_VD_VEHICLE_S astVehicele[ICE_MAX_VD_NUM];       //!< �������� 	
	ICE_S32 u32Reserved[16];                         	//!< ����
}ICE_VD_VEHICLE_LIST_S;

//! \ingroup group_vd
//! ��ͨ�������ݽṹ
typedef struct 
{
	ICE_S32 s32ValidLaneNum;								//!< ��Ч��������   		       		 		    
	ICE_S32 s32Flow[ICE_MAX_LANE_NUM];         				//!< ÿ����������  		       		 		
	ICE_S32 s32AvgSpeed[ICE_MAX_LANE_NUM];       			//!< ÿ������ƽ���ٶ�    		 		
	ICE_S32 s32OccupancyLane[ICE_MAX_LANE_NUM];  			//!< ÿ������ƽ������ռ����  	   		 		
	ICE_S32 s32AvgTimeHeadway[ICE_MAX_LANE_NUM]; 			//!< ÿ������ƽ����ͷʱ��     		 		
	ICE_S32 s32AvgDistHeadway[ICE_MAX_LANE_NUM]; 			//!< ÿ������ƽ����ͷ��� 	     		
	ICE_S32 s32AvgVehileLen[ICE_MAX_LANE_NUM];   			//!< ÿ������ƽ����������   		 		
	ICE_S32 s32AvgQueueLen[ICE_MAX_LANE_NUM];    			//!< ÿ������ƽ���Ŷӳ���   		

	ICE_S32 s32TotalFlow;         	                		//!< ���������� 			   		 		
	ICE_S32 s32TotalAvgSpeed;  								//!< ƽ���ٶ�    		
	ICE_S32 s32TotalOccupancyLane;  						//!< ƽ������ռ����   	   	 		
	ICE_S32 s32TotalAvgTimeHeadway; 						//!< ƽ����ͷʱ��     		
	ICE_S32 s32TotalAvgDistHeadway; 						//!< ƽ����ͷ���  		
	ICE_S32 s32TotalAvgVehileLen;   						//!< ƽ����������   		
	ICE_S32 s32TotalAvgQueueLen;    						//!< ÿ������ƽ���Ŷӳ���   
	ICE_S32 u32Reserved[16];                         		//!< ����     			    		   		 		
}ICE_VD_TRAFFIC_PARAM_DATA_S;


#define ICE_PICTURE_SIZE (1600*1200)

//! \ingroup group_vd
//! ͼƬ��Ϣ���ݽṹ
typedef struct 
{
	ICE_S32 s32EventCode;									//!< �¼���
	ICE_S32   s32LandId;									//!< ����ID    			   	   						
	ICE_CHAR  cFileName[256];  								//!< �ļ���     			   	   						
	ICE_SYSTEMTIME_S  stCapTime;    						//!< ץ��ʱ��     			   						
	ICE_S32    s32HaveCloseUp;     							//!< �Ƿ�����дͼ��     						
	ICE_RECT_S stVehilceRect;	  							//!< �������    			   						
	ICE_VD_VERHICLE_DIR_E 	enDirect;         	            //!< �������� 								
	ICE_FLOAT 	fSpeed;         	                		//!< �����ٶ�(��λ:ǧ��/Сʱ) 							
	ICE_CHAR 	cVehicleColor[32];							//!< ������ɫ
	ICE_CHAR 	cPlateColor[32];							//!< ������ɫ
	ICE_S32    s32HavePlate;       							//!< �Ƿ���ڳ���                						
	ICE_VLPR_OUTPUT_S stPlateInfo;							//!< ������Ϣ
	ICE_S16    s16PicWidth;     							//!< ͼƬ���					   						
	ICE_S16    s16PicHeight;     							//!< ͼƬ�߶�
	ICE_S32   s32PicDataLen;								//!< ͼƬ��С
	ICE_S8    *ps8PictureData;     							//!< ͼƬ����					   						
}ICE_VD_PICTRUE_INFO_S;

typedef struct 
{
	ICE_S32 s32EventCode;									//!< �¼���
	ICE_S32   s32LandId;									//!< ����ID    			   	   						
	ICE_CHAR  cFileName[256];  								//!< �ļ���     			   	   						
	ICE_SYSTEMTIME_S  stCapTime;    						//!< ץ��ʱ��     			   						
	ICE_S32    s32HaveCloseUp;     							//!< �Ƿ�����дͼ��     						
	ICE_RECT_S stVehilceRect;	  							//!< �������    			   						
	ICE_VD_VERHICLE_DIR_E 	enDirect;         	            //!< �������� 								
	ICE_FLOAT 	fSpeed;         	                		//!< �����ٶ�(��λ:ǧ��/Сʱ) 							
	ICE_CHAR 	cVehicleColor[32];							//!< ������ɫ
	ICE_CHAR 	cPlateColor[32];							//!< ������ɫ
	ICE_S32    s32HavePlate;       							//!< �Ƿ���ڳ���                						
	ICE_VLPR_OUTPUT_S stPlateInfo;							//!< ������Ϣ
	ICE_S16    s16PicWidth;     							//!< ͼƬ���					   						
	ICE_S16    s16PicHeight;     							//!< ͼƬ�߶�
	ICE_S32   s32PicDataLen;								//!< ͼƬ��С
	ICE_S8    as8PictureData[1024*1024];     				//!< ͼƬ����					   						
}ICE_VD_PICTRUE_INFO_BUFFER_S;


#define ICE_MAX_PICTURE_NUM 5

//! \ingroup group_vd
//! ץ����Ϣ���ݽṹ
typedef struct 
{
	ICE_S32    s32PictureNum;     								//!< ͼ������  	   
	ICE_VD_PICTRUE_INFO_S stPictureInfo[ICE_MAX_PICTURE_NUM];	//!< ͼƬ��Ϣ  	  	   
	ICE_S32    s32LaneId;										//!< ������ 	    			   
	ICE_VD_LANE_EVENT_TYPE_E    enEventType; 					//!< �¼���     			   
	ICE_CHAR  cDeviceID[64];  									//!< �豸����ţ�				   
	ICE_CHAR  cDeviceName[32];  								//!< �豸����					   
	ICE_CHAR  cCrossInfo[256];  								//!< ��·��Ϣ					   
	ICE_CHAR  cDirInfo[32];     								//!< ������Ϣ					   
	ICE_CHAR  cRoadInfo[32];    								//!< ��·��Ϣ					   
	ICE_CHAR  cRoadNum[32];     								//!< �������					   
	ICE_S32 u32Reserved[16];                         	 		//!< ����     				   
}ICE_VD_CAPTURE_S;

#define ICE_MAX_CAP_GROUP_NUM 4

//! \ingroup group_vd
//! ץ����Ϣ�б����ݽṹ
typedef struct 
{
	ICE_S32 s32CapNum;         	               			 //!< ��Чץ����Ŀ 	
	ICE_VD_CAPTURE_S astCapture[ICE_MAX_CAP_GROUP_NUM];  //!< ץ����Ϣ  	
	ICE_S32 u32Reserved[16];                         	 //!< ����
}ICE_VD_CAPTURE_LIST_S;

//! \ingroup group_vd
//! ����״̬���ݽṹ
typedef struct 
{
	ICE_S32 s32LaneId;	         						//!< ����ID  	
	ICE_S32 astHaveVehicle[2];							//!< ������Ȧ�Ƿ��г�����(1��ʾ�г� 0��ʾ�޳�)  	
	ICE_S32 s32EventCode[2];							//!< �¼���
	ICE_FLOAT fSpeed;									//!< �ٶ�
	ICE_S32 s32TrafficJamLevel;							//!< ӵ�¼���
	ICE_S32 u32Reserved[14];                         	//!< ����
}ICE_VD_LANE_STATUS_S;

//! \ingroup group_vd
//! �����б����ݽṹ
typedef struct 
{
	ICE_S32 s32LaneNum;         							//!< ��Ч������Ŀ  	
	ICE_VD_LANE_STATUS_S astLaneStatus[ICE_MAX_LANE_NUM];	//!< ����״̬��Ϣ	
	ICE_S32 u32Reserved[16];                         		//!< ����
}ICE_VD_LANE_LIST_S;

//! \ingroup group_vd
//!������������ݽṹ
typedef struct 
{
	ICE_VD_LANE_LIST_S stLaneList;							//!< ����״̬�б�  		
	ICE_VD_VEHICLE_LIST_S stVehilceList;					//!< �����б�  		
	ICE_VD_TRAFFIC_PARAM_DATA_S stTrafficParamData;			//!< ��ͨ��������  	
	ICE_VD_CAPTURE_LIST_S stCaptureList;					//!< ץ���б�  		
}ICE_VD_RESULT_S;

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
}ICE_VD_DEBUG_INFO_S;

/*----------------------------------------------*
* vd result defination            				*
*----------------------------------------------*/ 
typedef struct 
{
	ICE_S32 s32IsNight;										//!< ҹ���־(1��ʾҹ�� 0��ʾ����)    			
	ICE_S32 u32Reserved[16];                         		//!< ����
}ICE_VD_OUT_INTFC_S;

#ifdef __cplusplus
}
#endif


#endif
