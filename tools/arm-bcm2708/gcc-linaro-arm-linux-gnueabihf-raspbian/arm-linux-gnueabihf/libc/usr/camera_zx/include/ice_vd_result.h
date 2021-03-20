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
//! 车辆数据结构
typedef struct 
{
	ICE_S32 	s32LaneId;         	                		//!< 车道ID  								
	ICE_RECT_S  stRect;         	                		//!< 车辆外框 										
	ICE_VD_VERHICLE_DIR_E 	enDirect;         	            //!< 车辆方向  								
	ICE_FLOAT 	fSpeed;         	                		//!< 车辆速度(单位:千米/小时) 							
	ICE_CHAR 	cVehicleColor[32];							//!< 车辆颜色  									
	ICE_BOOL 	bHasPlate;         	                		//!< 是否有车牌  							
	ICE_VLPR_OUTPUT_S stPlateInfo;							//!< 车牌信息
	ICE_S32 	u32Reserved[15];                         	//!< 保留     			    						
}ICE_VD_VEHICLE_S;

//! \ingroup group_vd
//! 车辆列表数据结构
typedef struct 
{
	ICE_S32 s32VehiceleNum;         	                //!< 有效车辆数量 	
	ICE_VD_VEHICLE_S astVehicele[ICE_MAX_VD_NUM];       //!< 车辆数据 	
	ICE_S32 u32Reserved[16];                         	//!< 保留
}ICE_VD_VEHICLE_LIST_S;

//! \ingroup group_vd
//! 交通参数数据结构
typedef struct 
{
	ICE_S32 s32ValidLaneNum;								//!< 有效车道数量   		       		 		    
	ICE_S32 s32Flow[ICE_MAX_LANE_NUM];         				//!< 每个车道流量  		       		 		
	ICE_S32 s32AvgSpeed[ICE_MAX_LANE_NUM];       			//!< 每个车道平均速度    		 		
	ICE_S32 s32OccupancyLane[ICE_MAX_LANE_NUM];  			//!< 每个车道平均车道占有率  	   		 		
	ICE_S32 s32AvgTimeHeadway[ICE_MAX_LANE_NUM]; 			//!< 每个车道平均车头时距     		 		
	ICE_S32 s32AvgDistHeadway[ICE_MAX_LANE_NUM]; 			//!< 每个车道平均车头间距 	     		
	ICE_S32 s32AvgVehileLen[ICE_MAX_LANE_NUM];   			//!< 每个车道平均车辆长度   		 		
	ICE_S32 s32AvgQueueLen[ICE_MAX_LANE_NUM];    			//!< 每个车道平均排队长度   		

	ICE_S32 s32TotalFlow;         	                		//!< 车道总流量 			   		 		
	ICE_S32 s32TotalAvgSpeed;  								//!< 平均速度    		
	ICE_S32 s32TotalOccupancyLane;  						//!< 平均车道占有率   	   	 		
	ICE_S32 s32TotalAvgTimeHeadway; 						//!< 平均车头时距     		
	ICE_S32 s32TotalAvgDistHeadway; 						//!< 平均车头间距  		
	ICE_S32 s32TotalAvgVehileLen;   						//!< 平均车辆长度   		
	ICE_S32 s32TotalAvgQueueLen;    						//!< 每个车道平均排队长度   
	ICE_S32 u32Reserved[16];                         		//!< 保留     			    		   		 		
}ICE_VD_TRAFFIC_PARAM_DATA_S;


#define ICE_PICTURE_SIZE (1600*1200)

//! \ingroup group_vd
//! 图片信息数据结构
typedef struct 
{
	ICE_S32 s32EventCode;									//!< 事件码
	ICE_S32   s32LandId;									//!< 车道ID    			   	   						
	ICE_CHAR  cFileName[256];  								//!< 文件名     			   	   						
	ICE_SYSTEMTIME_S  stCapTime;    						//!< 抓拍时间     			   						
	ICE_S32    s32HaveCloseUp;     							//!< 是否有特写图像     						
	ICE_RECT_S stVehilceRect;	  							//!< 车辆外框    			   						
	ICE_VD_VERHICLE_DIR_E 	enDirect;         	            //!< 车辆方向 								
	ICE_FLOAT 	fSpeed;         	                		//!< 车辆速度(单位:千米/小时) 							
	ICE_CHAR 	cVehicleColor[32];							//!< 车辆颜色
	ICE_CHAR 	cPlateColor[32];							//!< 车牌颜色
	ICE_S32    s32HavePlate;       							//!< 是否存在车牌                						
	ICE_VLPR_OUTPUT_S stPlateInfo;							//!< 车牌信息
	ICE_S16    s16PicWidth;     							//!< 图片宽度					   						
	ICE_S16    s16PicHeight;     							//!< 图片高度
	ICE_S32   s32PicDataLen;								//!< 图片大小
	ICE_S8    *ps8PictureData;     							//!< 图片数据					   						
}ICE_VD_PICTRUE_INFO_S;

typedef struct 
{
	ICE_S32 s32EventCode;									//!< 事件码
	ICE_S32   s32LandId;									//!< 车道ID    			   	   						
	ICE_CHAR  cFileName[256];  								//!< 文件名     			   	   						
	ICE_SYSTEMTIME_S  stCapTime;    						//!< 抓拍时间     			   						
	ICE_S32    s32HaveCloseUp;     							//!< 是否有特写图像     						
	ICE_RECT_S stVehilceRect;	  							//!< 车辆外框    			   						
	ICE_VD_VERHICLE_DIR_E 	enDirect;         	            //!< 车辆方向 								
	ICE_FLOAT 	fSpeed;         	                		//!< 车辆速度(单位:千米/小时) 							
	ICE_CHAR 	cVehicleColor[32];							//!< 车辆颜色
	ICE_CHAR 	cPlateColor[32];							//!< 车牌颜色
	ICE_S32    s32HavePlate;       							//!< 是否存在车牌                						
	ICE_VLPR_OUTPUT_S stPlateInfo;							//!< 车牌信息
	ICE_S16    s16PicWidth;     							//!< 图片宽度					   						
	ICE_S16    s16PicHeight;     							//!< 图片高度
	ICE_S32   s32PicDataLen;								//!< 图片大小
	ICE_S8    as8PictureData[1024*1024];     				//!< 图片数据					   						
}ICE_VD_PICTRUE_INFO_BUFFER_S;


#define ICE_MAX_PICTURE_NUM 5

//! \ingroup group_vd
//! 抓拍信息数据结构
typedef struct 
{
	ICE_S32    s32PictureNum;     								//!< 图像总数  	   
	ICE_VD_PICTRUE_INFO_S stPictureInfo[ICE_MAX_PICTURE_NUM];	//!< 图片信息  	  	   
	ICE_S32    s32LaneId;										//!< 车道号 	    			   
	ICE_VD_LANE_EVENT_TYPE_E    enEventType; 					//!< 事件码     			   
	ICE_CHAR  cDeviceID[64];  									//!< 设备（编号）				   
	ICE_CHAR  cDeviceName[32];  								//!< 设备名称					   
	ICE_CHAR  cCrossInfo[256];  								//!< 道路信息					   
	ICE_CHAR  cDirInfo[32];     								//!< 方向信息					   
	ICE_CHAR  cRoadInfo[32];    								//!< 道路信息					   
	ICE_CHAR  cRoadNum[32];     								//!< 车道编号					   
	ICE_S32 u32Reserved[16];                         	 		//!< 保留     				   
}ICE_VD_CAPTURE_S;

#define ICE_MAX_CAP_GROUP_NUM 4

//! \ingroup group_vd
//! 抓拍信息列表数据结构
typedef struct 
{
	ICE_S32 s32CapNum;         	               			 //!< 有效抓拍数目 	
	ICE_VD_CAPTURE_S astCapture[ICE_MAX_CAP_GROUP_NUM];  //!< 抓拍信息  	
	ICE_S32 u32Reserved[16];                         	 //!< 保留
}ICE_VD_CAPTURE_LIST_S;

//! \ingroup group_vd
//! 车道状态数据结构
typedef struct 
{
	ICE_S32 s32LaneId;	         						//!< 车道ID  	
	ICE_S32 astHaveVehicle[2];							//!< 虚拟线圈是否有车存在(1表示有车 0表示无车)  	
	ICE_S32 s32EventCode[2];							//!< 事件码
	ICE_FLOAT fSpeed;									//!< 速度
	ICE_S32 s32TrafficJamLevel;							//!< 拥堵级别
	ICE_S32 u32Reserved[14];                         	//!< 保留
}ICE_VD_LANE_STATUS_S;

//! \ingroup group_vd
//! 车道列表数据结构
typedef struct 
{
	ICE_S32 s32LaneNum;         							//!< 有效车道数目  	
	ICE_VD_LANE_STATUS_S astLaneStatus[ICE_MAX_LANE_NUM];	//!< 车道状态信息	
	ICE_S32 u32Reserved[16];                         		//!< 保留
}ICE_VD_LANE_LIST_S;

//! \ingroup group_vd
//!车辆检测结果数据结构
typedef struct 
{
	ICE_VD_LANE_LIST_S stLaneList;							//!< 车道状态列表  		
	ICE_VD_VEHICLE_LIST_S stVehilceList;					//!< 车辆列表  		
	ICE_VD_TRAFFIC_PARAM_DATA_S stTrafficParamData;			//!< 交通参数数据  	
	ICE_VD_CAPTURE_LIST_S stCaptureList;					//!< 抓拍列表  		
}ICE_VD_RESULT_S;

//! \ingroup group_vd
//!车辆检测调试信息数据结构
typedef struct 
{
	void *pRgbOImage;								//!< 原始RBG图像
	void *pRgbPImage;								//!< 虚拟线圈处理的RBG图像
	void *pRgbCImage[3];							//!< 特写RBG图像列表,对应不同的车道
	void *pRgbPlateImage[3];						//!< 车牌RBG图像列表,对应不同的车道
	ICE_S32 s32EventCode[4];						//!< 车道事件码			
	ICE_S32    s32HavePlate[4];						//!< 是否存在车牌
	ICE_VLPR_OUTPUT_S pVlprResult[4];				//!< 车牌信息
	ICE_CHAR cPlateColor[4][32];					//!< 车牌颜色
}ICE_VD_DEBUG_INFO_S;

/*----------------------------------------------*
* vd result defination            				*
*----------------------------------------------*/ 
typedef struct 
{
	ICE_S32 s32IsNight;										//!< 夜间标志(1表示夜间 0表示白天)    			
	ICE_S32 u32Reserved[16];                         		//!< 保留
}ICE_VD_OUT_INTFC_S;

#ifdef __cplusplus
}
#endif


#endif
