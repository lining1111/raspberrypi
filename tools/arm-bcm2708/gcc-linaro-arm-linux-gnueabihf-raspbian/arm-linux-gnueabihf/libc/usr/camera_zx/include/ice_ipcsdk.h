#ifndef _ICE_IPCSDK__H_
#define _ICE_IPCSDK__H_

#include "ice_base_type.h"
#include "ice_com_type.h"
#include "ice_vdc_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @brief  相机事件枚举类型
*/
typedef enum
{
	ICE_DEVICE_OFFLINE,		    //离线
	ICE_DEVICE_ONLINE,		    //在线
	ICE_DEVICE_IO_CHANGED		//IO状态改变
} ICE_DEVICE_EVENT_TYPE;

/**
 * @brief  车牌类型枚举值
 * typedef enum 
	{
		ICE_PLATE_UNCERTAIN	    = 0,	        不确定的
		ICE_PLATE_BLUE	        = 1,	        蓝牌车
		ICE_PLATE_YELLOW	    = 2,	        单层黄牌车
		ICE_PLATE_POL	        = 4,	        警车
		ICE_PLATE_WUJING	    = 8,	        武警车辆
		ICE_PLATE_DBYELLOW	    = 16,	        双层黄牌
		ICE_PLATE_MOTOR	        = 32,	        摩托车
		ICE_PLATE_INSTRUCTIONCAR= 64,	        教练车
		ICE_PLATE_MILITARY	    = 128,	        军车
		ICE_PLATE_PERSONAL	    = 256,	        个性化车
		ICE_PLATE_GANGAO	    = 512,	        港澳车
		ICE_PLATE_EMBASSY	    = 1024,	        使馆车
		ICE_PLATE_NONGLARE	    = 2048,	        老式车牌(不反光)
		ICE_PLATE_AVIATION		= 4096,			民航车牌

		ICE_PLATE_WHITE_TWOTWO	= 0x10000001,	2+2模型；
		ICE_PLATE_WHITE_TWOTHR	= 0x10000002,	2+3模型；
		ICE_PLATE_WHITE_THRTWO	= 0x10000004,	3+2模型；
		ICE_PLATE_WHITE_THRTHR	= 0x10000008,	 3+3模型；
		ICE_PLATE_WHITE_THRFOR	= 0x10000010,	3+4模型；

		ICE_PLATE_BLACK_THRTWO	= 0x10000020,	3+2模型；
		ICE_PLATE_BLACK_TWOTHR	= 0x10000040,	2+3模型；
		ICE_PLATE_BLACK_THRTHR	= 0x10000080,	3+3模型；
		ICE_PLATE_BLACK_TWOFOR	= 0x10000100,	2+4模型；
		ICE_PLATE_BLACK_FORTWO	= 0x10000200,	4+2模型；
		ICE_PLATE_BLACK_THRFOR	= 0x10000400,	3+4模型；
	}ICE_PLATETYPE_E;
 */

/*
 * @brief   报警类型枚举值
	typedef enum{
		ICE_VDC_HD_TRIGER,						//实时_硬触发+临时车辆(0),
		ICE_VDC_VIDEO_TRIGER, 					//实时_视频触发+临时车辆（1），
		ICE_VDC_SOFT_TRIGER,					//实时_软触发+临时车辆（2），
		ICE_VDC_HD_TRIGER_AND_WHITELIST,		//实时_硬触发+有效白名单(3),
		ICE_VDC_VIDEO_TRIGER_AND_WHITELIST,		//实时_视频触发+有效白名单（4），
		ICE_VDC_SOFT_TRIGER_AND_WHITELIST,  	//实时_软触发+有效白名单（5），
		ICE_VDC_HD_TRIGER_AND_BLACKLIST,		//实时_硬触发+黑名单(6),
		ICE_VDC_VIDEO_TRIGER_AND_BLACKLIST,		//实时_视频触发+黑名单（7），
		ICE_VDC_SOFT_TRIGER_AND_BLACKLIST,  	//实时_软触发+黑名单（8），

		ICE_VDC_NC_HD_TRIGER,					//脱机_硬触发+临时车辆(9),
		ICE_VDC_NC_VIDEO_TRIGER, 				//脱机_视频触发+临时车辆（10），
		ICE_VDC_NC_SOFT_TRIGER,					//脱机_软触发+临时车辆（11），
		ICE_VDC_NC_HD_TRIGER_AND_WHITELIST,		//脱机_硬触发+有效白名单(12),
		ICE_VDC_NC_VIDEO_TRIGER_AND_WHITELIST,	//脱机_视频触发+有效白名单（13），
		ICE_VDC_NC_SOFT_TRIGER_AND_WHITELIST,  	//脱机_软触发+有效白名单（14），
		ICE_VDC_NC_HD_TRIGER_AND_BLACKLIST,		//脱机_硬触发+黑名单(15),
		ICE_VDC_NC_VIDEO_TRIGER_AND_BLACKLIST,	//脱机_视频触发+黑名单（16），
		ICE_VDC_NC_SOFT_TRIGER_AND_BLACKLIST,  	//脱机_软触发+黑名单（17），

		ICE_VDC_HD_TRIGER_AND_OVERDUE_WHITELIST,		//实时_硬触发+过期白名单(18),
		ICE_VDC_VIDEO_TRIGER_AND_OVERDUE_WHITELIST,		//实时_视频触发+过期白名单（19），
		ICE_VDC_SOFT_TRIGER_AND_OVERDUE_WHITELIST,  	//实时_软触发+过期白名单（20），
		ICE_VDC_NC_HD_TRIGER_AND_OVERDUE_WHITELIST,		//脱机_硬触发+过期白名单(21),
		ICE_VDC_NC_VIDEO_TRIGER_AND_OVERDUE_WHITELIST,	//脱机_视频触发+过期白名单（22），
		ICE_VDC_NC_SOFT_TRIGER_AND_OVERDUE_WHITELIST,  	//脱机_软触发+过期白名单（23），

		ICE_VDC_ALARM_UNKOWN,
	}ICE_VDC_ALARM_TYPE;
 * /

/**
*  @brief  通过该回调函数获得实时识别数据
*  @param  [out] pvParam               用户自定义参数,用来区分不同的sdk使用者,类似于线程入口函数的参数(与设置此回调接口的最后一个参数相同)
*  @param  [out] pcIp                  相机ip
*  @param  [OUT] pcNumber              车牌号
*  @param  [OUT] pcColor               车牌颜色("蓝色","黄色","白色","黑色","绿色")
*  @param  [OUT] pvPicData             全景数据
*  @param  [OUT] nPicLen               全景数据长度
*  @param  [OUT] pvPlatePicData        车牌数据
*  @param  [OUT] nPlatePicLen          车牌数据长度
*  @param  [OUT] nPlatePosLeft         车牌区域左上角横坐标
*  @param  [OUT] nPlatePosTop          车牌区域左上角纵坐标
*  @param  [OUT] nPlatePosRight        车牌区域右上角横坐标
*  @param  [OUT] nPlatePosBottom       车牌区域右上角纵坐标
*  @param  [OUT] fPlateConfidence      车牌打分值(SDK输出的范围大于IE界面设置的车牌阈值, 上限是28, 例如: IE设置的是10, 范围: 10-28)
*  @param  [OUT] nVehicleColor         车身颜色(车辆特征码相机版本：(-1:未知,0:黑色,1:蓝色,2:灰色,3:棕色,4:绿色,5:夜间深色,6:紫色,7:红色,8:白色,9:黄色)
*                                           其它相机版本：(0:未知,1:红色,2:绿色,3:蓝色,4:黄色,5:白色,6:灰色,7:黑色,8:紫色,9:棕色,10:粉色))
*  @param  [OUT] nPlateType            车牌类型，详见车牌类型ICE_PLATETYPE_E枚举值
*  @param  [OUT] nVehicleDir           车辆方向 (0:车头方向,1:车尾方向,2:车头和车尾方向)
*  @param  [OUT] nAlarmType            报警输出，详见报警输出ICE_VDC_ALARM_TYPE枚举值
*  @param  [OUT] nSpeed                车辆速度
*  @param  [OUT] nCapTime              实时抓拍时间，从1970年1月1日零点开始的秒数
*  @param  [OUT] nVehicleType          车辆类型 (0:未知,1:普通汽车,2:面包车,3:大客车,4:箱式货车,5:大货车,6:非机动车)
*  @param  [OUT] nResultHigh           车牌识别数据结构体(ICE_VDC_PICTRUE_INFO_S)指针高8位(64位sdk时需要使用)
*  @param  [OUT] nResultLow            车牌识别数据结构体（ICE_VDC_PICTRUE_INFO_S）指针低8位
*/
typedef void (*ICE_IPCSDK_Plate)(void *pvParam, 
	const char* pcIP, const char* pcNumber, const char* pcColor, 
	void* pvPicData, long nPicLen, void* pvPlatePicData, long nPlatePicLen,
	long nPlatePosLeft, long nPlatePosTop, long nPlatePosRight, long nPlatePosBottom, 
	float fPlateConfidence, long nVehicleColor, 
	long nPlateType, long nVehicleDir, long nAlarmType, long nSpeed,
	long nCapTime, long nVehicleType, long nResultHigh, long nResultLow);

/**
*  @brief  通过该回调函数获得断网续传识别数据
*  @param  [out] pvParam               用户自定义参数,用来区分不同的sdk使用者,类似于线程入口函数的参数(与设置此回调接口的最后一个参数相同)
*  @param  [out] pcIp                  相机ip
*  @param  [OUT] nCapTime              实时抓拍时间，从1970年1月1日零点开始的秒数
*  @param  [OUT] pcNumber              车牌号
*  @param  [OUT] pcColor               车牌颜色("蓝色","黄色","白色","黑色","绿色")
*  @param  [OUT] pvPicData             全景数据
*  @param  [OUT] nPicLen               全景数据长度
*  @param  [OUT] pvPlatePicData        车牌数据
*  @param  [OUT] nPlatePicLen          车牌数据长度
*  @param  [OUT] nPlatePosLeft         车牌区域左上角横坐标
*  @param  [OUT] nPlatePosTop          车牌区域左上角纵坐标
*  @param  [OUT] nPlatePosRight        车牌区域右上角横坐标
*  @param  [OUT] nPlatePosBottom       车牌区域右上角纵坐标
*  @param  [OUT] fPlateConfidence      车牌打分值(SDK输出的范围大于IE界面设置的车牌阈值, 上限是28, 例如: IE设置的是10, 范围: 10-28)
*  @param  [OUT] nVehicleColor         车身颜色(车辆特征码相机版本：(-1:未知,0:黑色,1:蓝色,2:灰色,3:棕色,4:绿色,5:夜间深色,6:紫色,7:红色,8:白色,9:黄色)
*                                           其它相机版本：(0:未知,1:红色,2:绿色,3:蓝色,4:黄色,5:白色,6:灰色,7:黑色,8:紫色,9:棕色,10:粉色))
*  @param  [OUT] nPlateType            车牌类型，详见车牌类型ICE_PLATETYPE_E枚举值
*  @param  [OUT] nVehicleDir           车辆方向 (0:车头方向,1:车尾方向,2:车头和车尾方向)
*  @param  [OUT] nAlarmType            报警输出，详见报警输出ICE_VDC_ALARM_TYPE枚举值
*  @param  [OUT] nReserved1            预留参数1
*  @param  [OUT] nReserved1            预留参数2
*  @param  [OUT] nReserved1            预留参数3
*  @param  [OUT] nReserved1            预留参数4
*/
typedef void (*ICE_IPCSDK_OnPastPlate)(void *pvParam, const char *pcIP, 
	long nCapTime, const char *pcNumber, const char *pcColor, 
	void *pvPicData, long nPicLen, void *pvPlatePicData, long nPlatePicLen, 
	long nPlatePosLeft, long nPlatePosTop, long nPlatePosRight, long nPlatePosBottom, 
	float fPlateConfidence, long nVehicleColor, long nPlateType, long nVehicleDir, 
	long nAlarmType, long nReserved1, long nReserved2, long nReserved3, long nReserved4);

 /**
 *  @brief  通过该回调函数获得RS485数据
 *  @param  [OUT] pvParam   用户自定义参数，用来区分不同的sdk使用者，类似于线程入口函数的参数（即ICE_IPCSDK_SetSerialPortCallBack传入的最后一个参数）
 *  @param  [OUT] pcIP      相机ip
 *  @param  [OUT] pcData    串口数据首地址
 *  @param  [OUT] u32Len    串口数据长度
 *  @return void
 */
typedef void (*ICE_IPCSDK_OnSerialPort)(void *pvParam, 
	const char *pcIP, char *pcData, long u32Len);

/**
 *  @brief  通过该回调函数获得RS232数据
 *  @param  [OUT] pvParam   用户自定义参数，用来区分不同的sdk使用者，类似于线程入口函数的参数（即ICE_IPCSDK_SetSerialPortCallBack_RS232传入的最后一个参数）
 *  @param  [OUT] pcIP      相机ip
 *  @param  [OUT] pcData    串口数据首地址
 *  @param  [OUT] u32Len    串口数据长度
 *  @return void
 */
typedef void (*ICE_IPCSDK_OnSerialPort_RS232)(void *pvParam, 
	const char *pcIP, char *pcData, long u32Len);

/**
*  @brief  通过该回调函数获取相机的连接状态
*  @param  [OUT] pvParam             相机连接回调参数, 用于区分不同相机连接事件(ICE_IPCSDK_SetDeviceEventCallBack传入的最后一个参数)
*  @param  [OUT] pcIP                相机ip
*  @param  [OUT] u32EventType        事件类型 0：离线 1：在线
*  @param  [OUT] u32EventData1       预留参数1 
*  @param  [OUT] u32EventData2       预留参数2
*  @param  [OUT] u32EventData3       预留参数3
*  @param  [OUT] u32EventData4       预留参数4
*/
typedef void(*ICE_IPCSDK_OnDeviceEvent)(void *pvParam, const char *pcIP, long u32EventType, 
	long u32EventData1, long u32EventData2, long u32EventData3, long u32EventData4);

/*
*  @brief   state callback
*  @param  [OUT] pvParam
*
*
*/
typedef void(*ICE_IPCSDK_StateEvent)(void *pvParam, const char *pcIP, char *pcData, long u32Len);
 /**
 *  @brief  连接相机
 *  @param  [IN] pcIP                           相机ip
 *  @param  [IN] ICE_IPCSDK_Plate               车牌回调信息
 *  @param  [IN] pvParam                        用户自定义参数，用来区分不同的sdk使用者
 *  @return sdk句柄(连接不成功时，返回值为null）
 */
ICE_HANDLE ICE_IPCSDK_Open(const char* pcIP, 
	ICE_IPCSDK_Plate pfOnPlate, void *pvParam);

 /**
 *  @brief  连接相机(使用密码)
 *  @param  [IN] pcIP                           相机ip
 *  @param  [IN] passwd                         连接相机的密码
 *  @param  [IN] ICE_IPCSDK_Plate               车牌回调信息
 *  @param  [IN] pvParam                        用户自定义参数，用来区分不同的sdk使用者
 *  @return sdk句柄(连接不成功时，返回值为null）
 */
ICE_HANDLE ICE_IPCSDK_Open_Passwd(const char* pcIP, const ICE_CHAR *passwd, 
	ICE_IPCSDK_Plate pfOnPlate, void *pvParam);


/**
*  @brief  断开连接
*  @param  [IN]  连接相机时返回的句柄值
*  @return void
*/
void ICE_IPCSDK_Close(ICE_HANDLE hSDK);

/**
*  @brief  设置获得断网续传识别数据的相关回调函数
*  @param  [IN] hSDK               连接相机时返回的sdk句柄
*  @param  [IN] pfOnPastPlate      断网识别数据，通过该回调获得
*  @param  [IN] pvPastPlateParam   回调函数中的参数，能区分开不同的使用者即可
*  @return void
*/
void ICE_IPCSDK_SetPastPlateCallBack(ICE_HANDLE hSDK, 
	ICE_IPCSDK_OnPastPlate pfOnPastPlate, void *pvPastPlateParam);

/**
*  @brief  设置相机连接状态回调事件
*  @param  [IN] pfOnDeviceEvent              相机连接回调
*  @param  [IN] pvDeviceEventParam           相机连接回调参数,用于区分不同相机连接事件
*  @param  [IN] nReserved1                   预留参数1
*/
void ICE_IPCSDK_SetDeviceEventCallBack(ICE_IPCSDK_OnDeviceEvent pfOnDeviceEvent, 
	void *pvDeviceEventParam, long nReserved1);

/**
*  @brief  连接状态回调
*  @param  [IN] pfStateEvent            
*  @param  [IN] pvDeviceEventParam         
*  @param  [IN] nReserved1                   
*/
void ICE_IPCSDK_SetStateEventCallBack(ICE_IPCSDK_StateEvent pfStateEvent, 
	void *pvStateEventParam, long nReserved1);
	
/**
*  @brief  软触发
*  @param  [IN]  hSDK          由连接相机接口获得的句柄
*  @param  [OUT] pcNumber      车牌号
*  @param  [OUT] pcColor       车牌颜色（"蓝色","黄色","白色","黑色",“绿色”）
*  @param  [OUT] pvPicData     抓拍图片数据
*  @param  [OUT] nBufSize      抓拍图片缓冲区大小
*  @param  [OUT] nPicLen       抓拍图片实际长度
*  @return 1表示成功，0表示失败
*/
int ICE_IPCSDK_Trigger(ICE_HANDLE hSDK, char* pcNumber, char* pcColor, 
	void* pvPicData, long nBufSize, long* nPicLen);

/**
*  @brief  通过ip触发
*  @param  [IN] pcIP     相机ip
*  @return 触发结果(0  ip为空,-1 连接相机失败,-2 发送软触发信号失败,1  成功)
*/
int ICE_IPCSDK_TriggerByIp(const char* pcIP);

 /**
 *  @brief   打开道闸
 *  @param   [IN] hSDK 由连接相机接口获得的句柄
 *  @return  1表示成功，0表示失败
 */
int ICE_IPCSDK_OpenGate(ICE_HANDLE hSDK);


/**
 *  @brief  获取相机连接状态
 *  @param  [IN] hSDK   由连接相机接口获得的句柄
 *  @return 1表示在线，0表示离线
 */
int ICE_IPCSDK_GetStatus(ICE_HANDLE hSDK);

/**
*  @brief  配置抓拍规则
*  @param  [IN] hSDK          sdk句柄
*  @param  [IN] nSnap         是否抓拍全景图
*  @param  [IN] nSnapPlate    是否抓拍车牌图
*  @return void
*/
void ICE_ICPSDK_SetSnapCfg(ICE_HANDLE hSDK, long nSnap, long nSnapPlate);

//
int ICE_IPCSDK_SetOsdCfg_new(ICE_HANDLE hSDK, ICE_OSDAttr_S *pstOSDAttr);

/**
*  @brief 实时视频叠加位置枚举值：
	typedef enum
	{
		ICE_OSD_LOCATION_LEFT_TOP = 0,	//左上
		ICE_OSD_LOCATION_RIGHT_TOP,		//右上
		ICE_OSD_LOCATION_LEFT_BOTTOM,	//左下
		ICE_OSD_LOCATION_RIGHT_BOTTOM,	//右下
		ICE_OSD_LOCATION_TOP_MID,		//上居中
		ICE_OSD_LOCAtiON_BOTTOM_MID		//下居中
		
	} ICE_OSD_LOCATION_TYPE_E;
*/

/**
 *  @brief  设置OSD参数
 *  @param  [IN] hSDK               由连接相机接口获得的句柄
 *  @param  [IN] nPosVideo          实时视频叠加位置
 *  @parame [IN] nColorVideo        实时视频OSD文字颜色，格式为0x00bbggrr
 *  @parame [IN] nDateTimeVideo     实时视频是否叠加日期时间
 *  @parame [IN] nLicense           实时视频是否叠加授权信息
 *  @parame [IN] nCustomVideo       实时视频是否叠加自定义信息
 *  @parame [IN] bstrCustomVideo    实时视频自定义信息，最多支持6行，换行使用"\r\n"，每行最多支持64个字符（包括换行符）
 *  @parame [IN] nPosJpeg           抓拍图片叠加位置，取值同实时视频叠加位置
 *  @parame [IN] nColorJpeg         抓拍图片OSD文字颜色，格式为0x00bbggrr
 *  @parame [IN] nDateTimeJpeg      抓拍图片是否叠加日期时间
 *  @parame [IN] nAlgo              抓拍图片是否叠加算法信息
 *  @parame [IN] nCustomJpeg        抓拍图片是否叠加自定义信息
 *  @parame [IN] bstrCustomJpeg     抓拍图片自定义信息，约束条件同实时视频自定义信息
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_SetOsdCfg(ICE_HANDLE hSDK, long nPosVideo, long nColorVideo, 
	long nDateTimeVideo, long nLicense, long nCustomVideo, const char* bstrCustomVideo, 
	long nPosJpeg, long nColorJpeg, long nDateTimeJpeg, long nAlgo, 
	long nCustomJpeg, const char* bstrCustomJpeg);

/**
*  @brief  osd扩展设置
*  @param  [IN] hSDK              sdk句柄
*  @param  [IN] nDisplayMode      信息显示模式  0：多行显示   1：单行显示
*  @param  [IN] nDateMode         日期显示模式  0：yyyy/mm/dd 1：yyyy年mm月dd日
*  @param  [IN] nBgColor          OSD背景色     0：背景透明   1：背景黑色
*  @param  [IN] nFontSize         字体大小      0：小         1：中          2：大
*  @param  [IN] nExpandMode       扩展模式      0：不扩张     1：图像上扩张  2：图像下扩张
*  @param  [IN] nRsrv1            预留参数1
*  @param  [IN] nRsrv2            预留参数2
*  @param  [IN] nRsrv3            预留参数3
*  @param  [IN] nRsrv4            预留参数4
*  @return 设置状态 0  设置失败   1  设置成功
*/
int ICE_IPCSDK_SetOsdExtCfg(ICE_HANDLE hSDK, long nDisplayMode, 
	long nDateMode, long nBgColor, long nFontSize, long nExpandMode,
	long nRsrv1, long nRsrv2, long nRsrv3, long nRsrv4);

/**
*  @brief  获取osd参数设置
*  @param  [IN] hSDK              sdk句柄
*  @param  [IN] pstOSDAttr        osd结构体，定义如下
*  @return 获取状态 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetOSDCfg(ICE_HANDLE hSDK, ICE_OSDAttr_S *pstOSDAttr);

 /**
 *  @brief  手动抓拍，不做识别，直接抓拍一张码流的图片
 *  @param  [IN]  hSDK          由连接相机接口获得的句柄
 *  @param  [OUT] pvPicData     抓拍图片数据
 *  @param  [OUT] nPicSize      抓拍图片缓冲区大小
 *  @param  [OUT] nPicLen       抓拍图片实际长度
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_Capture(ICE_HANDLE hSDK, void* pvPicData, long nPicSize, long* nPicLen);

/**
 *  @brief  重启相机
 *  @param  [IN] hSDK   由连接相机接口获得的句柄
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_Reboot(ICE_HANDLE hSDK);

/**
 *  @brief  语音播放，单条语音
 *  @param  [IN] hSDK      由连接相机接口获得的句柄
 *  @parame [IN] nIndex    语音文件索引号，详见《语音列表.txt》
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_Broadcast(ICE_HANDLE hSDK, short nIndex);

/**
*  @brief  通过文件名进行语音播报（单播）
*  @param  [IN] hSDK        连接相机时返回的sdk句柄
*  @param  [IN] pcName      语音播报文件名
*  @return 0 失败 1 成功
*/
int ICE_IPCSDK_Broadcast_ByName(ICE_HANDLE hSDK, const char* pcName);

/**
*  @brief  通过文件名进行组播
*  @param  [IN] hSDK        连接相机时返回的sdk句柄
*  @param  [IN] pcName      包含语音文件名的字符串
*							注：中间可以用, ; \t \n或者空格分开；如：1 2 3 4或者1,2,3,4
*  @return 0 失败 1 成功
*/
int ICE_IPCSDK_BroadcastGroup_ByName(ICE_HANDLE hSDK, const char* pcName);

/**
 *  @brief  获取相机mac地址
 *  @param  [IN] hSDK      由连接相机接口获得的句柄
 *  @param  [OUT] szDevID  相机mac地址
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_GetDevID(ICE_HANDLE hSDK, char* szDevID);

/**
 *  @brief  写入用户数据
 *  @param  [IN] hSDK       由连接相机接口获得的句柄
 *  @parame [IN] szData     需要写入的用户数据
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_WriteUserData(ICE_HANDLE hSDK, const char* szData);

/**
 *  @brief  读取用户数据
 *  @param  [IN] hSDK       由连接相机接口获得的句柄
 *  @parame [OUT] szData    读取的用户数据
 *  @return 1 表示成功，0 表示失败
 */
int ICE_IPCSDK_ReadUserData(ICE_HANDLE hSDK, char* szData);

/**
 *  @brief  发送RS485串口数据
 *  @param  [IN] hSDK      由连接相机接口获得的句柄
 *  @param  [IN] nData     RS485串口数据
 *  @param  [IN] nLen      串口数据长度
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_TransSerialPort(ICE_HANDLE hSDK, char* nData, long nLen);

/**
 *  @brief  发送RS232串口数据
 *  @param  [IN] hSDK      由连接相机接口获得的句柄
 *  @param  [IN] nData     RS232串口数据
 *  @param  [IN] nLen      串口数据长度
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_TransSerialPort_RS232(ICE_HANDLE hSDK, char* nData, long nLen);

 /**
 *  @brief  设置获得RS485数据的相关回调函数
 *  @param  [IN] hSDK               连接相机时返回的sdk句柄
 *  @param  [IN] pfOnSerialPort     相机发送的RS485数据，通过该回调获得
 *  @param  [IN] pvSerialPortParam  回调函数中的参数，能区分开不同的使用者即可
 *  @return void
 */
void ICE_IPCSDK_SetSerialPortCallBack(ICE_HANDLE hSDK, 
	ICE_IPCSDK_OnSerialPort pfOnSerialPort, void *pvSerialPortParam);

/**
 *  @brief  设置获得RS232数据的相关回调函数
 *  @param  [IN] hSDK               连接相机时返回的sdk句柄
 *  @param  [IN] pfOnSerialPort     相机发送的RS232数据，通过该回调获得
 *  @param  [IN] pvSerialPortParam  回调函数中的参数，能区分开不同的使用者即可
 *  @return void
 */
void ICE_IPCSDK_SetSerialPortCallBack_RS232(ICE_HANDLE hSDK, 
	ICE_IPCSDK_OnSerialPort_RS232 pfOnSerialPort, void *pvSerialPortParam);

/**
*  @brief  设置识别区域              注意：4个坐标。
*  @param  [IN] hSDK           sdk句柄
*  @param  [IN] pstParam          识别区域左坐标点（以左上角为坐标原点）
*/
int ICE_IPCSDK_SetVDCParam(ICE_HANDLE hSDK, const ICE_VDC_PARAM_S *pstParam);

/**
*  @brief  获取识别区域              注意：4个坐标。
*  @param  [IN] hSDK           sdk句柄
*  @param  [IN] pstParam       识别区域左坐标点（以左上角为坐标原点）
*/
int ICE_IPCSDK_GetVDCParam(ICE_HANDLE hSDK, ICE_VDC_PARAM_S *pstParam);

/**
*  @brief  设置识别区域        注意：绘制时以左下、右上为坐标基点来绘制识别矩形框。
*  @param  [IN] hSDK           sdk句柄
*  @param  [IN] nLeft          识别区域左坐标点（以左上角为坐标原点）
*  @param  [IN] nBottom        识别区域下坐标点（以左上角为坐标原点）
*  @param  [IN] nRight         识别区域右坐标点（以左上角为坐标原点）
*  @param  [IN] nTop           识别区域上坐标点（以左上角为坐标原点）
*  @param  [IN] nWidth         坐标是在什么分辨率下取得的，表示宽（如在1280*720下取得的，宽为1280）
*  @param  [IN] nHeight        坐标是在什么分辨率下取得的，表示高（如在1280*720下取得的，高为720）
*  @rerun 设置状态 1 设置成功 0 设置失败
*/
int ICE_ICPSDK_SetLoop(ICE_HANDLE hSDK, long nLeft, long nBottom, 
	long nRight, long nTop, long nWidth, long nHeight);

/**
*  @brief  获取识别区域        注意：绘制时以左下、右上为坐标基点来绘制识别矩形框。
*  @param  [IN] hSDK           sdk句柄
*  @param  [OUT] nLeft          识别区域左坐标点（以左上角为坐标原点）
*  @param  [OUT] nBottom        识别区域下坐标点（以左上角为坐标原点）
*  @param  [OUT] nRight         识别区域右坐标点（以左上角为坐标原点）
*  @param  [OUT] nTop           识别区域上坐标点（以左上角为坐标原点）
*  @param  [OUT] nWidth         坐标是在什么分辨率下取得的，表示宽（如在1280*720下取得的，宽为1280）
*  @param  [OUT] nHeight        坐标是在什么分辨率下取得的，表示高（如在1280*720下取得的，宽为720）
*  @rerun 设置状态 1 获取成功 0 获取失败
*/
int ICE_ICPSDK_GetLoop(ICE_HANDLE hSDK, long *nLeft, long *nBottom, 
	long *nRight, long *nTop, long nWidth, long nHeight);

/**
 *  @brief  搜索区域网内相机
 *  @param  [IN]  szIfName 接口名称，如eth0，可通过ifconfig查看
 *  @param  [OUT] szDevs   设备mac地址和ip地址的字符串
 *                         设备mac地址和ip地址的字符串，格式为：mac地址 ip地址 例如：00-00-00-00-00-00 192.168.55.150\r\n
 *  @return void
 */
void ICE_IPCSDK_SearchDev(const char *szIfName, char *szDevs, int nSize, int nTimeoutMs);

/**
 *  @brief  设置相机网络参数
 *  @param  [IN] hSDK        由连接相机接口获得的句柄
 *  @parame [IN] pcIP        相机ip
 *  @param  [IN] pcMask      相机掩码
 *  @param  [IN] pcGateway   相机网关
 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_SetIPAddr(ICE_HANDLE hSDK, const char* pcIP, 
	const char* pcMask, const char* pcGateway);

/**********************************************************
优先城市列表：
全国;北京;上海;天津;重庆;黑龙江;吉林;辽宁;内蒙古;河北;
山东;山西;安徽;江苏;浙江;福建;广东;河南;江西;湖南;湖北;
广西;海南;云南;贵州;四川;陕西;甘肃;宁夏;青海;西藏;新疆;
优先城市接口中的索引对应以上列表中的顺序，从0开始
**********************************************************/
/**
 *  @brief  设置优先城市
 *  @param  [IN] hSDK      由连接相机接口获得的句柄
 *  @parame [IN] nIndex    优先城市的索引号
 *  优先城市列表：（0  全国；1  北京；2  上海；3  天津；4  重庆；5  黑龙江；6  吉林；7  辽宁；8  内蒙古；9  河北；10 山东
				 11 山西；12 安徽；13 江苏；14 浙江；15 福建；16 广东；17 河南；18 江西；19 湖南；20 湖北；21 广西
				 22 海南；23 云南；24 贵州；25 四川；26 陕西；27 甘肃；28 宁夏；29 青海；30 西藏；31 新疆）

 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_SetCity(ICE_HANDLE hSDK, long nIndex);

/**
 *  @brief  获取优先城市
 *  @param  [IN] hSDK      由连接相机接口获得的句柄
 *  @parame [OUT] nIndex    优先城市的索引号
 *  优先城市列表：（0  全国；1  北京；2  上海；3  天津；4  重庆；5  黑龙江；6  吉林；7  辽宁；8  内蒙古；9  河北；10 山东
				 11 山西；12 安徽；13 江苏；14 浙江；15 福建；16 广东；17 河南；18 江西；19 湖南；20 湖北；21 广西
				 22 海南；23 云南；24 贵州；25 四川；26 陕西；27 甘肃；28 宁夏；29 青海；30 西藏；31 新疆）

 *  @return 1表示成功，0表示失败
 */
int ICE_IPCSDK_GetCity(ICE_HANDLE hSDK, long *nIndex);

/**
*  @brief  设置曝光时间模式
*  @param  [IN] hSDK     sdk句柄
*  @param  [IN] nMode    曝光模式（1 自动模式，2 手动模式）
*  @return 设置状态 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetExposureMode(ICE_HANDLE hSDK, long nMode);

/**
*  @brief  获取曝光时间模式
*  @param  [IN] hSDK     sdk句柄
*  @param  [OUT] nMode   曝光模式（1 自动模式，2 手动模式）
*  @return 获取状态 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetExposureMode(ICE_HANDLE hSDK, long *nMode);

/**********************************************************
曝光时间参数V82和V82-D参数取值范围不一样，需参考使用说明
Expline	曝光时间
AGain	模拟增益
DGain	数字增益
**********************************************************/

/**
*  @brief  设置自动曝光参数
*  @param  [IN] hSDK            sdk句柄
*  @param  [IN] nExplineMin     最小曝光时间
*  @param  [IN] nExplineMax     最大曝光时间
*  @param  [IN] nAGainMin       最小模拟增益
*  @param  [IN] nAGainMax       最大模拟增益
*  @param  [IN] nDGainMin       最小数字增益
*  @param  [IN] nDGainMax       最大数字增益
*  @return 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetAutoExpParam(ICE_HANDLE hSDK, 
	long nExplineMin, long nExplineMax, 
	long nAGainMin, long nAGainMax, 
	long nDGainMin, long nDGainMax);

/**
*  @brief  获取自动曝光参数
*  @param  [IN] hSDK            sdk句柄
*  @param  [OUT] nExplineMin     最小曝光时间
*  @param  [OUT] nExplineMax     最大曝光时间
*  @param  [OUT] nAGainMin       最小模拟增益
*  @param  [OUT] nAGainMax       最大模拟增益
*  @param  [OUT] nDGainMin       最小数字增益
*  @param  [OUT] nDGainMax       最大数字增益
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetAutoExpParam(ICE_HANDLE hSDK, 
	long *nExplineMin, long *nExplineMax, 
	long *nAGainMin, long *nAGainMax, 
	long *nDGainMin, long *nDGainMax);

/**
*  @brief  设置手动曝光时间
*  @param  [IN] hSDK            sdk句柄
*  @param  [IN] nExpline        曝光时间
*  @param  [IN] nAGain          模拟增益
*  @param  [IN] nDGain          数字增益
*  @return 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetManualExpParam(ICE_HANDLE hSDK, 
	long nExpline, long nAGain, long nDGain);

/**
*  @brief  获取手动曝光时间
*  @param  [IN] hSDK             sdk句柄
*  @param  [OUT] nExpline        曝光时间
*  @param  [OUT] nAGain          模拟增益
*  @param  [OUT] nDGain          数字增益
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetManualExpParam(ICE_HANDLE hSDK, 
	long *nExpline, long *nAGain, long *nDGain);

/**********************************************************
安装距离：3.5米以下;3.5米-4.5米;4.5米-5米;5米-6米;6米以上
安装距离接口中的索引对应以上列表中的顺序，从0开始

安装距离自动关联：0表示关闭，1表示开启，建议开启
**********************************************************/

/**
*  @brief  设置安装距离
*  @param  [IN] hSDK           sdk句柄
*  @param  [IN] nIndex         安装距离
*  @param  [IN] nEnable        安装距离自动关联：0表示关闭，1表示开启，建议开启
*  @rerurn 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetDistance(ICE_HANDLE hSDK, long nIndex, long nEnable);

/**
*  @brief  获取安装距离
*  @param  [IN] hSDK            sdk句柄
*  @param  [OUT] nIndex         安装距离
*  @param  [OUT] nEnable        安装距离自动关联：0表示关闭，1表示开启，建议开启
*  @rerurn 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetDistance(ICE_HANDLE hSDK, long *nIndex, long *nEnable);

/**
*  @brief  设置曝光自调节开关
*  @param  [IN] hSDK        sdk句柄
*  @param  [IN] nEnable     曝光自调节开关：0表示关闭，1表示开启
*  @return 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetARegParam(ICE_HANDLE hSDK, long nEnable);

/**
*  @brief  获取曝光自调节开关
*  @param  [IN] hSDK        sdk句柄
*  @param  [OUT] nEnable     曝光自调节开关：0表示关闭，1表示开启
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetARegParam(ICE_HANDLE hSDK, long *nEnable);

/**
*  @brief  恢复默认参数
*  @param  [IN] hSDK        sdk句柄
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_DefaultParam(ICE_HANDLE hSDK);

/**
*  @brief  设置抓拍图像分辨率
*  @param  [IN] hSDK          sdk句柄
*  @param  [IN] nWidth        图像的宽度
*  @param  [IN] nHeight       图像的高度
*  @return 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetSnapSize(ICE_HANDLE hSDK, long nWidth, long nHeight);

/**
*  @brief  获取抓拍图像分辨率
*  @param  [IN] hSDK           sdk句柄
*  @param  [OUT] nWidth        图像的宽度
*  @param  [OUT] nHeight       图像的高度
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetSnapSize(ICE_HANDLE hSDK, long *nWidth, long *nHeight);

/**
*  @brief  获取IO状态
*  @param  [IN] hSDK             sdk句柄
*  @param  [OUT] u32Index        IO口索引（0：IO1 1:IO2 2:IO3 3:IO4）
*  @param  [OUT] pu32IOState     IO口状态（0：无数据 1：有数据）
*  @param  [OUT] pu32Reserve1    预留参数1
*  @param  [OUT] pu32Reserve2    预留参数2
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetIOState(ICE_HANDLE hSDK, long u32Index, long *pu32IOState, 
							long *pu32Reserve1, long *pu32Reserve2);

/**  @brief  补光灯参数枚举值
typedef struct
{
	ICE_U32 u32Luminance;		//亮度
	ICE_U32 u32Reserved[7];		//预留
	
} LightParam;
*/

/**
*  @brief  获取补光灯参数
*  @param  [IN] hSDK             sdk句柄
*  @param  [OUT] pstParam        补光灯参数, 详情见LightParam
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetLightParam(ICE_HANDLE hSDK, LightParam *pstParam);

/**
*  @brief  设置补光灯参数
*  @param  [IN] hSDK             sdk句柄
*  @param  [IN] pstParam        补光灯参数, 详情见LightParam
*  @return 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetLightParam(ICE_HANDLE hSDK, const LightParam *pstParam);

/**
*  @brief  特征码比较
*  @param  [IN] _pfResFeat1    需要比较的特征码1
*  @param  [IN] _iFeat1Len     特征码1的长度，目前需输入20
*  @param  [IN] _pfReaFeat2    需要比较的特征码2
*  @param  [IN] _iFeat2Len     特征码2的长度，目前需输入20
*  @return  匹配度，范围：0-1，值越大越匹配
*/
float ICE_IPCSDK_VBR_CompareFeat(float *_pfResFeat1, long _iFeat1Len,
									float *_pfReaFeat2, long _iFeat2Len);

/**********************************************************
黑白名单接口注意事项:
1、获取黑白名单数量为新旧模式共用
2、旧模式白名单不支持黑名单，是以序号为索引，由SDK端进行处理（考虑老用户兼容性使用此接口）
3、新模式黑白名单是以车牌号为索引，由相机端进行处理（相机端支持版本为20151028版本及其以后）
4、白名单格式
   格式：车牌号码+TAB键+起始有效期+TAB键+截止有效期+ TAB键+起始时间+ TAB键+截止时间+回车键+TAB键+白名单类型（B/W）
   实例：吉AP889Q	2015/09/21	2015/10/20	00:00:00	23:59:59	W
   注意：起始时间必须早于截止时间，这两个时间是指一个时间段，与起始有效期和截止有效期无关。
   比如：2015/09/21	2015/10/20	00:00:00	23:59:59是正确的，
       而2015/09/21	2015/10/20	22:00:00	11:00:00是错误的时间。
**********************************************************/

/**
*  @brief  设置黑白名单参数
*  @param  [IN] hSDK         sdk句柄
*  @param  [IN] mode         白名单模式（0表示断网关联，1表示实时工作,2 不关联开闸或不工作）
*  @param  [IN] match        白名单匹配相似度（范围（70%-100%），默认：80%）
*  @param  [IN] bmode        黑名单模式（0 不关联开闸，1 开闸）
*  @param  [IN] bmatch       黑名单匹配相似度（范围（70%-100%），默认：80%）
*  @param  [IN] tmode        临时车模式（0 不关联开闸，1 开闸）
*  @return 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetWhiteListParam(ICE_HANDLE hSDK, 
	int mode, int match, int bmode, int bmatch, int tmode);

/**
*  @brief  获取黑白名单参数
*  @param  [IN] hSDK          sdk句柄
*  @param  [OUT] mode         白名单模式（0表示断网关联，1表示实时工作,2 不关联开闸或不工作）
*  @param  [OUT] match        白名单匹配相似度（范围（70%-100%），默认：80%）
*  @param  [OUT] bmode        黑名单模式（0 不关联开闸，1 开闸）
*  @param  [OUT] bmatch       黑名单匹配相似度（范围（70%-100%），默认：80%）
*  @param  [OUT] tmode        临时车模式（0 不关联开闸，1 开闸）
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetWhiteListParam(ICE_HANDLE hSDK, 
	int* mode, int* match, int *bmode, int *bmatch, int *tmode);

/**
*  @brief  编辑黑白名单项(以车牌号为索引)
*  @param  [IN] hSDK              sdk句柄
*  @param  [IN] pcNumber          黑白名单项中的车牌号
*  @param  [IN] pcDateBegin       黑白名单项中的开始日期(格式为yyyy/MM/dd)
*  @param  [IN] pcDateEnd         黑白名单项中的结束日期(格式为yyyy/MM/dd)
*  @param  [IN] pcTimeBegin       黑白名单项中的开始时间(格式为HH:mm:ss)
*  @param  [IN] pcTimeEnd         黑白名单项中的结束时间(格式为HH:mm:ss)
*  @param  [IN] pcType            名单类型（白名单"W"/黑名单"B"）
*  @param  [IN] pcRsrv1           预留字段1
*  @param  [IN] pcRsrv2           预留字段2
*  @param  [IN] pcRsrv3           预留字段3
*  @param  [IN] pcRsrv4           预留字段4
*  @return 1 编辑成功 0 编辑失败
*/
int ICE_IPCSDK_WhiteListEditItem_ByNumber(ICE_HANDLE hSDK, const char* pcNumber, 
	const char* pcDateBegin, const char* pcDateEnd, 
	const char* pcTimeBegin, const char* pcTimeEnd, const char* pcType, 
	const char* pcRsrv1, const char* pcRsrv2, const char* pcRsrv3, const char* pcRsrv4);

/**
*  @brief  添加黑白名单项(以车牌号为索引)
*  @param  [IN] hSDK              sdk句柄
*  @param  [IN] pcNumber          黑白名单项中的车牌号
*  @param  [IN] pcDateBegin       黑白名单项中的开始日期(格式为yyyy/MM/dd)
*  @param  [IN] pcDateEnd         黑白名单项中的结束日期(格式为yyyy/MM/dd)
*  @param  [IN] pcTimeBegin       黑白名单项中的开始时间(格式为HH:mm:ss)
*  @param  [IN] pcTimeEnd         黑白名单项中的结束时间(格式为HH:mm:ss)
*  @param  [IN] pcType            名单类型（白名单"W"/黑名单"B"）
*  @param  [IN] pcRsrv1           预留字段1
*  @param  [IN] pcRsrv2           预留字段2
*  @param  [IN] pcRsrv3           预留字段3
*  @param  [IN] pcRsrv4           预留字段4
*  @return 1 添加成功 0 添加失败
*/
int ICE_IPCSDK_WhiteListInsertItem_ByNumber(ICE_HANDLE hSDK, const char* pcNumber, 
	const char* pcDateBegin, const char* pcDateEnd, const char* 
	pcTimeBegin, const char* pcTimeEnd, const char* pcType, 
	const char* pcRsrv1, const char* pcRsrv2, const char* pcRsrv3, const char* pcRsrv4);

/**
*  @brief  删除黑白名单项(以车牌号为索引)
*  @param  [IN] hSDK              sdk句柄
*  @param  [IN] pcNumber          要删除的车牌号
*  @return 1 删除成功 0 删除失败
*/
int ICE_IPCSDK_WhiteListDeleteItem_ByNumber(ICE_HANDLE hSDK, const char* pcNumber);

/**
*  @brief  删除所有黑白名单项(以车牌号为索引)
*  @param  [IN] hSDK              sdk句柄
*  @return 1 删除成功 0 删除失败
*/
int ICE_IPCSDK_WhiteListDelAllItems_ByNumber(ICE_HANDLE hSDK);

/**
*  @brief  删除所有白名单项(不含黑名单)
*  @param  [IN] hSDK              sdk句柄
*  @return 1 删除成功 0 删除失败
*/
int ICE_IPCSDK_DelAllWhiteItems(ICE_HANDLE hSDK);

/**
*  @brief  删除所有黑名单项(不含白名单)
*  @param  [IN] hSDK              sdk句柄
*  @return 1 删除成功 0 删除失败
*/
int ICE_IPCSDK_DelAllBlackItems(ICE_HANDLE hSDK);

/**
*  @brief  查找黑白名单项(以车牌号为索引)
*  @param  [IN] hSDK               sdk句柄
*  @param  [IN] pcNumber           黑白名单项中的车牌号
*  @param  [OUT] pcDateBegin       黑白名单项中的开始日期(格式为yyyy/MM/dd)
*  @param  [OUT] pcDateEnd         黑白名单项中的结束日期(格式为yyyy/MM/dd)
*  @param  [OUT] pcTimeBegin       黑白名单项中的开始时间(格式为HH:mm:ss)
*  @param  [OUT] pcTimeEnd         黑白名单项中的结束时间(格式为HH:mm:ss)
*  @param  [OUT] pcType            名单类型（白名单"W"/黑名单"B"）
*  @param  [OUT] pcRsrv1           预留字段1
*  @param  [OUT] pcRsrv2           预留字段2
*  @param  [OUT] pcRsrv3           预留字段3
*  @param  [OUT] pcRsrv4           预留字段4
*  @return 1 查找成功 0 查找失败
*/
int ICE_IPCSDK_WhiteListFindItem_ByNumber(ICE_HANDLE hSDK, const char* pcNumber, 
	char* pcDateBegin, char* pcDateEnd, char* pcTimeBegin, char* pcTimeEnd, char* pcType, 
	char* pcRsrv1, char* pcRsrv2, char* pcRsrv3, char* pcRsrv4);

/**
*  @brief  获取白名单项总数（包括黑白名单）
*  @param  [IN] hSDK              sdk句柄
*  @param  [OUT] pu32Count        白名单项总数
*  @param 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_WhiteListGetCount(ICE_HANDLE hSDK, long *pu32Count);

/**
*  @brief  获取白名单的总数（不含黑名单）
*  @param  [IN] hSDK              sdk句柄
*  @param  [OUT] pu32Count        白名单项总数
*  @param 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetWhiteCount(ICE_HANDLE hSDK, long *pu32Count);

/**
*  @brief  获取黑名单总数
*  @param  [IN] hSDK              sdk句柄
*  @param  [OUT] pu32Count        黑名单总数
*  @param 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetBlackCount(ICE_HANDLE hSDK, long *pu32Count);

/**
*  @brief  获取白名单项(旧模式,以序列号为索引)
*  @param  [IN] hSDK             sdk句柄
*  @param  [IN] s32Index         需要获取的白名单的索引
*  @param  [OUT] pcNumber        白名单项中的车牌号
*  @param  [OUT] pcDateBegin     白名单项中的开始日期(格式为yyyy/MM/dd)
*  @param  [OUT] pcDateEnd       白名单项中的结束日期(格式为yyyy/MM/dd)
*  @param  [OUT] pcTimeBegin     白名单项中的开始时间(格式为HH:mm:ss)
*  @param  [OUT] pcTimeEnd       白名单项中的结束时间(格式为HH:mm:ss)
*  @param  [OUT] pcType          白名单项类型(白名单"W",黑名单"B")
*  @param  [OUT] pcRsrv1         预留字段1
*  @param  [OUT] pcRsrv2         预留字段2
*  @param  [OUT] pcRsrv3         预留字段3
*  @param  [OUT] pcRsrv4         预留字段4
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_WhiteListGetItem(ICE_HANDLE hSDK, long s32Index, char* pcNumber, 
	char* pcDateBegin, char* pcDateEnd, char* pcTimeBegin, char* pcTimeEnd, char *pcType,
	char* pcRsrv1, char* pcRsrv2, char* pcRsrv3, char* pcRsrv4);

/**
*  @brief  获取白名单项(不包含黑名单,通过索引号获取)
*  @param  [IN] hSDK             sdk句柄
*  @param  [IN] s32Index         需要获取的白名单的索引
*  @param  [OUT] pcNumber        白名单项中的车牌号
*  @param  [OUT] pcDateBegin     白名单项中的开始日期(格式为yyyy/MM/dd)
*  @param  [OUT] pcDateEnd       白名单项中的结束日期(格式为yyyy/MM/dd)
*  @param  [OUT] pcTimeBegin     白名单项中的开始时间(格式为HH:mm:ss)
*  @param  [OUT] pcTimeEnd       白名单项中的结束时间(格式为HH:mm:ss)
*  @param  [OUT] pcType          白名单项类型(白名单"W",黑名单"B")
*  @param  [OUT] pcRsrv1         预留字段1
*  @param  [OUT] pcRsrv2         预留字段2
*  @param  [OUT] pcRsrv3         预留字段3
*  @param  [OUT] pcRsrv4         预留字段4
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetWhiteItem(ICE_HANDLE hSDK, long s32Index, char* pcNumber, 
	char* pcDateBegin, char* pcDateEnd, char* pcTimeBegin, char* pcTimeEnd, char *pcType,
	char* pcRsrv1, char* pcRsrv2, char* pcRsrv3, char* pcRsrv4);

/**
*  @brief  获取黑名单项(通过索引号获取)
*  @param  [IN] hSDK             sdk句柄
*  @param  [IN] s32Index         需要获取的白名单的索引
*  @param  [OUT] pcNumber        黑名单项中的车牌号
*  @param  [OUT] pcDateBegin     黑名单项中的开始日期(格式为yyyy/MM/dd)
*  @param  [OUT] pcDateEnd       黑名单项中的结束日期(格式为yyyy/MM/dd)
*  @param  [OUT] pcTimeBegin     黑名单项中的开始时间(格式为HH:mm:ss)
*  @param  [OUT] pcTimeEnd       黑名单项中的结束时间(格式为HH:mm:ss)
*  @param  [OUT] pcType          黑名单项类型(白名单"W",黑名单"B")
*  @param  [OUT] pcRsrv1         预留字段1
*  @param  [OUT] pcRsrv2         预留字段2
*  @param  [OUT] pcRsrv3         预留字段3
*  @param  [OUT] pcRsrv4         预留字段4
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetBlackItem(ICE_HANDLE hSDK, long s32Index, char* pcNumber, 
	char* pcDateBegin, char* pcDateEnd, char* pcTimeBegin, char* pcTimeEnd, char *pcType,
	char* pcRsrv1, char* pcRsrv2, char* pcRsrv3, char* pcRsrv4);

/**
*  @brief  获取支持的车牌类型
*  @param  [IN] hSDK             sdk句柄
*  @param  [OUT] nPlateTypeSp    检测支持的车牌类型值
*  @return 1 获取成功 0 获取失败
*/
int ICE_IPCSDK_GetSupportPlateType(ICE_HANDLE hSDK, int *nPlateTypeSp);

/**
*  @brief  设置支持的车牌类型
*  @param  [IN] hSDK            sdk句柄
*  @param  [IN] nPlateTypeSp    检测支持的车牌类型值
*  @param  [IN] nLimit          限制是否强制支持蓝牌和黄牌，1为强制，0为不强制
*  @return 1 设置成功 0 设置失败
*/
int ICE_IPCSDK_SetSupportPlateType(ICE_HANDLE hSDK, int nPlateTypeSp, int nLimit);

/**
*  @brief  时间同步
*  @param  [IN] hSDK          连接相机时返回的sdk句柄
*  @param  [IN] u16Year       同步时间的年
*  @param  [IN] u8Month       同步时间的月
*  @param  [IN] u8Day         同步时间的日
*  @param  [IN] u8Hour        同步时间的时
*  @param  [IN] u8Min         同步时间的分
*  @param  [IN] u8Sec         同步时间的秒
*  @return 0 失败, 1 成功
*/
int ICE_IPCSDK_SyncTime(ICE_HANDLE hSDK, short u16Year, char u8Month, char u8Day, 
							char u8Hour, char u8Min, char u8Sec);

/**
*  @brief  时间同步扩展 不在要求客户输入UTC时间
*  @param  [IN] hSDK          连接相机时返回的sdk句柄
*  @param  [IN] u16Year       同步时间的年
*  @param  [IN] u8Month       同步时间的月
*  @param  [IN] u8Day         同步时间的日
*  @param  [IN] u8Hour        同步时间的时
*  @param  [IN] u8Min         同步时间的分
*  @param  [IN] u8Sec         同步时间的秒
*  @return 0 失败, 1 成功
*/
int ICE_IPCSDK_SyncTimeExt(ICE_HANDLE hSDK, short u16Year, char u8Month, char u8Day, 
							char u8Hour, char u8Min, char u8Sec);

/**
*  @brief  控制开关量输出(如道闸)
*  @param  [IN] hSDK            连接相机时返回的sdk句柄
*  @param  [IN] u32Index        控制的IO口(0:表示IO1 1:表示IO2)
*  @return 1 成功 0 失败
*/
int ICE_IPCSDK_ControlAlarmOut(ICE_HANDLE hSDK, int u32Index);

/*
*  @brief  get offline state
*  @param  [IN] hSDK
*
*
*/
int ICE_IPCSDK_OffLineState(ICE_HANDLE hSDK);
#ifdef __cplusplus
}
#endif

#endif