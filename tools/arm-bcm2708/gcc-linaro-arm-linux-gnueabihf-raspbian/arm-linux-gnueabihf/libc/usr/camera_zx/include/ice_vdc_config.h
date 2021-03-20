/*! \file ice_vdc_config.h
\brief ice_vdc_config.h document.
*/

#ifndef __ICE_VDC_CONFIG_H__
#define __ICE_VDC_CONFIG_H__

#include "ice_base_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

//! \ingroup group_vd
//! ³öÈë¿Ú³µµÀ¸ß¼¶²ÎÊý¶¨Òå
typedef struct 
{
	ICE_S32 s32AdaptiveThreshOnOff;					//!<  ×ÔÊÊÓ¦ãÐÖµ¿ª¹Ø  (1:¿ª 0:¹Ø  Ä¬ÈÏ:¹Ø)								
	ICE_S32 s32DayTriggerThresh;					//!<  °×Ìì´¥·¢ãÐÖµ    (·¶Î§:1-100 Ä¬ÈÏ:25)													
	ICE_S32 s32NightTriggerThresh;					//!<  Ò¹¼ä´¥·¢ãÐÖµ    (·¶Î§:1-100 Ä¬ÈÏ:50)													
	ICE_S32 s32TriggerSensitivity;					//!<  ´¥·¢ÁéÃô¶È      (·¶Î§:1-100 Ä¬ÈÏ:10)													
	ICE_S32 s32FilterByPlate;						//!<  ÎÞ³µÅÆ¹ýÂË¿ª¹Ø  (1:¿ª 0:¹Ø  Ä¬ÈÏ:¿ª)														
	ICE_S32 s32TrigerInterval;						//!<  ÎÞÅÆ³µ´¥·¢¼ä¸ô  (·¶Î§:10-500  Ä¬ÈÏ:50)
	ICE_S32 s32DetectDoubleDirectOnOff;				//!<  ¼ì²âË«Ïò³µÁ¾¿ª¹Ø(2:Ö§³ÖË«Ïò³µÁ¾²¢Êä³ö·½ÏòÐÅÏ¢ 1:Ö§³ÖË«Ïò³µÁ¾µ«²»Êä³ö·½ÏòÐÅÏ¢ 0:Ö»Êä³öµ¥Ïò³µÁ¾  Ä¬ÈÏ:1)
	ICE_S32 s32EnableSamePlateCar;					//!<  ÔÊÐíÏàÍ¬³µÁ¾¿ª¹Ø(1:¿ª 0:¹Ø  Ä¬ÈÏ:¹Ø)
	ICE_S32 s32SamePlateCarOutputTime;				//!<  ÏàÍ¬³µÁ¾Êä³ö¼ä¸ô(·¶Î§:1-3600 Ä¬ÈÏ:30 µ¥Î»:Ãë)
	ICE_S32 s32EnableNonMotorizedVehicles;			//!<  ¿ªÆô·Ç»ú¶¯³µ¼ì²â¿ª¹Ø(1:¿ª 0:¹Ø  Ä¬ÈÏ:¹Ø)
	ICE_S32 s32FilterNonMotorizedVehicles;			//!<  ÊÇ·ñ¹ýÂË·Ç»ú¶¯³µÁ¾(1:¿ª 0:¹Ø  Ä¬ÈÏ:¹Ø)
	ICE_S32 u32Reserved[10];                        //!<  ±£ÁôÖµ     																					
}ICE_VDC_ADV_PARAM_S;

//! \ingroup group_vdc
//! ³öÈë¿Ú·½Ïò¶¨Òå
typedef enum 
{
	ICE_VDC_VERHICLE_DIR_HEAD			 = 0,				//!<  ³µÍ··½Ïò 			
	ICE_VDC_VERHICLE_DIR_TAIL			 = 1,				//!<  ³µÎ²·½Ïò 			
	ICE_VDC_VERHICLE_DIR_HEAD_AND_TAIL	 = 2				//!<  ³µÍ·ºÍ³µÎ²·½Ïò 	
}ICE_VDC_VERHICLE_DIR_E;

//! \ingroup group_vdc
//! ´¥·¢·½Ê½¶¨Òå
typedef enum 
{
	ICE_VDC_TRIGER_MODE_HDWARE				= 0,				//!<  Íâ´¥·¢£¨¿ª¹ØÁ¿ÊäÈë£© 			
	ICE_VDC_TRIGER_MODE_VIDEO				= 1,				//!<  ÊÓÆµ´¥·¢ 			
	ICE_VDC_TRIGER_MODE_HDWARE_AND_VIDEO	= 2					//!<  Íâ´¥·¢ºÍÊÓÆµ»ìºÏ´¥·¢ 	
}ICE_VDC_TRIGER_MODE_E;

//! \ingroup group_vdc
//! °²×°Î»ÖÃ¶¨Òå
typedef enum 
{
	ICE_VDC_INSTALL_POS_DRIVER_SIDE					= 0,				//!<  Ë¾»úÍ¬²à£¨ÍÆ¼ö£©		
	ICE_VDC_INSTALL_POS_DRIVER_REVERSE_SIDE			= 1					//!<  Ë¾»úÒì²à 			
}ICE_VDC_INSTALL_POS_E;

//! \ingroup group_vd
//! ³µµÀ²ÎÊý¶¨Òå
/*typedef struct 
{																						
	ICE_VDC_VERHICLE_DIR_E enVehiceleDirection;				//!<  ³µÁ¾·½Ïò(Ä¬ÈÏ:³µÍ·)											
	ICE_RECT_S astLoop;				 						//!<  ÐéÄâÏßÈ¦(Ê¶±ðÇøÓò)																					
	ICE_VDC_ADV_PARAM_S stAdvParam;							//!<  ¸ß¼¶²ÎÊý
	ICE_VDC_TRIGER_MODE_E enTrigerMode;						//!<  ´¥·¢Ä£Ê½
	ICE_S32 u32Reserved[15];                        		//!<  ±£Áô     																					
}ICE_VDC_LANE_S;*/

typedef struct 
{																						
	ICE_VDC_VERHICLE_DIR_E enVehiceleDirection;				//!<  è½¦è¾†æ–¹å‘(é»˜è®¤:è½¦å¤´)											
	ICE_RECT_S astLoop;				 						//!<  è™šæ‹Ÿçº¿åœˆ(è¯†åˆ«åŒºåŸŸ)																					
	ICE_VDC_ADV_PARAM_S stAdvParam;							//!<  é«˜çº§å‚æ•°
	ICE_VDC_TRIGER_MODE_E enTrigerMode;						//!<  è§¦å‘æ¨¡å¼

	ICE_S32 s32QuqdrangleEnable;							//!<  è™šæ‹Ÿçº¿åœˆå¤šè¾¹å½¢è¯†åˆ«åŒºåŸŸä½¿èƒ½
	ICE_S32 s32TripWiresEnable;								//!<  ç»Šçº¿ä½¿èƒ½æ ‡å¿—
	ICE_LINE_S stTripWiresLane;								//!<  ç»Šçº¿
	ICE_LINE_S stTripWiresLane2;							//!<  åŒå‘æ¨¡å¼ä¸‹ä¸Šæ–¹çš„ç»Šçº¿
	ICE_S32 s32OnekeyConfigEnable;							//!<  å¼€å¯ä¸€é”®è°ƒè¯•åŠŸèƒ½  

	ICE_S32 u32Reserved[8];                        		//!<  ä¿ç•™     																					
	//ICE_S32 u32Reserved[15];                        		//!<  ä¿ç•™     																					
}ICE_VDC_LANE_S;


//! \ingroup group_vd
//! ³µÅÆ²ÎÊý¶¨Òå
/*typedef struct 
{
	ICE_S32	s32MinPlateWidth;						//!<  ×îÐ¡³µÅÆ¿í¶È 									   
	ICE_S32	s32MaxPlateWidth;						//!<  ×î´ó³µÅÆ¿í¶È 									 
	ICE_CHAR cPriorCity[32];					 	//!<  ÓÅÏÈ³ÇÊÐ 										 
	ICE_S32	s32PlateConfidThrld;					//!<  ³µÅÆ¿ÉÐÅ¶ÈãÐÖµ£¨-28-28£©£¬Ä¬ÈÏ£º15 			 
	ICE_FLOAT fPlateAngle;							//!<  ³µÅÆÇãÐ±½Ç¶È£¬Ä¬ÈÏ£º0 
	ICE_S32 s32PlateTypeSp;							//!<  Ö§³Ö³µÅÆÀàÐÍ     0Ä¬ÈÏÈ«²¿¿ªÆô£»
	ICE_S32	s32CarColorOn;							//!<  ³µÉíÑÕÉ«¶îÆôÓÃ£» 0²»ÆôÓÃ
	ICE_S32 s32PriorCityType;						//!<  ÓÅÏÈ³ÇÊÐÀàÐÍ
	ICE_S32 s32PriorArmyPlate;						//!<  ¾üÅÆÓÅÏÈ
	ICE_VDC_INSTALL_POS_E enCameraInstallPos;		//!<  Ïà»ú°²×°Î»ÖÃ£¨Ä¬ÈÏ£ºË¾»úÍ¬²à£©
	ICE_S32 u32Reserved[10];                        //!<  ±£Áô     									
}ICE_VDC_PLATE_CONFIG_S;*/

typedef struct 
{
	ICE_S32	s32MinPlateWidth;						//!<  æœ€å°è½¦ç‰Œå®½åº¦ 									   
	ICE_S32	s32MaxPlateWidth;						//!<  æœ€å¤§è½¦ç‰Œå®½åº¦ 
	ICE_QUADRANGLE_S stVLoopRect;					//!<  è™šæ‹Ÿçº¿åœˆå››è¾¹å½¢åŒºåŸŸ
	ICE_S32 u32Reserved1[4];                        //!<  ä¿ç•™    
	//ICE_CHAR cPriorCity[32];					 	//!<  ä¼˜å…ˆåŸŽå¸‚ï¼ˆç›®å‰æœªä½¿ç”¨ï¼Œå¯ä»¥ç”¨ä½œå¤šè¾¹å½¢åŒºåŸŸï¼‰ 										 
	ICE_S32	s32PlateConfidThrld;					//!<  è½¦ç‰Œå¯ä¿¡åº¦é˜ˆå€¼ï¼ˆ-28-28ï¼‰ï¼Œé»˜è®¤ï¼š15 			 
	ICE_FLOAT fPlateAngle;							//!<  è½¦ç‰Œå€¾æ–œè§’åº¦ï¼Œé»˜è®¤ï¼š0 
	ICE_S32 s32PlateTypeSp;							//!<  æ”¯æŒè½¦ç‰Œç±»åž‹     0é»˜è®¤å…¨éƒ¨å¼€å¯ï¼›
	ICE_S32	s32CarColorOn;							//!<  è½¦èº«é¢œè‰²é¢å¯ç”¨ï¼› 0ä¸å¯ç”¨
	ICE_S32 s32PriorCityType;						//!<  ä¼˜å…ˆåŸŽå¸‚ç±»åž‹
	ICE_S32 s32PriorArmyPlate;						//!<  å†›ç‰Œä¼˜å…ˆ
	ICE_VDC_INSTALL_POS_E enCameraInstallPos;		//!<  ç›¸æœºå®‰è£…ä½ç½®ï¼ˆé»˜è®¤ï¼šå¸æœºåŒä¾§ï¼‰
	ICE_S32 s32EnableOnePlateSameChars;				//!<  æ”¯æŒ1è½¦ç‰Œé‡å¤å­—ç¬¦ï¼ˆä¾‹å¦‚:äº¬N11111ï¼‰ 0ä¸å¯ç”¨ 1å¯åŠ¨ ï¼Œé»˜è®¤ï¼š0ï¼ˆé»˜è®¤ï¼š0ï¼‰
	ICE_S32 s32EnableOneCarMultiPlates;				//!<  æ”¯æŒ1è½¦å¤šç‰Œ   0ä¸å¯ç”¨ 1å¯åŠ¨ ï¼Œé»˜è®¤ï¼š0
	ICE_S32 s32EnableWJChineseChar;					//!<  æ”¯æŒæ­¦è­¦æ±‰å­—è¾“å‡º   0ä¸å¯ç”¨ 1å¯åŠ¨ ï¼Œé»˜è®¤ï¼š0
	ICE_S32 u32Reserved[7];                         //!<  ä¿ç•™     									
}ICE_VDC_PLATE_CONFIG_S;


//! \ingroup group_vd
//! ³öÈë¿Ú²ÎÊý¶¨Òå
typedef struct  
{
	ICE_VDC_LANE_S astLane;				 						 //!<  ³µµÀ²ÎÊý 		  						  
	ICE_VDC_PLATE_CONFIG_S stPlateParam;						 //!<  ³µÅÆ²ÎÊý   		  						  	  
	ICE_S32 s32Width;											 //!<  ÅäÖÃËùÔÚ²Î¿¼Í¼Ïñ¿í¶È		  						  	  
	ICE_S32 s32Height;											 //!<  ÅäÖÃËùÔÚ²Î¿¼Í¼Ïñ¸ß¶È
	ICE_S32 as32Reserved[8];              						 //!<  ±£Áô 											  
}ICE_VDC_PARAM_S;

#ifdef __cplusplus
}
#endif


#endif// __ICE_VDC_CONFIG_H__
