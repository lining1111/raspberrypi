/*! \file ice_com_type.h
\brief ice_com_type.h document.
*/
#ifndef _ICE_COM_TYPE_H_
#define _ICE_COM_TYPE_H_

#include "ice_base_type.h"

//! \defgroup group_communication ͨ��Э��
//!  ͨ��Э����������
//! \{
//! \}

#ifdef __cplusplus
extern "C"
{
#endif


#define ICE_BUF_SIZE_CONTROL	(64-32)
#define ICE_BUF_SIZE_EVENT		(64-32)
#define ICE_BUF_SIZE_VPRO		(16*1024-32)
#define ICE_BUF_SIZE_CONFIG		(128*1024-32)

#define ICE_BUFLEN_PACKET	(1024*512)

#define ICE_EVENT_ID_SLAVE_MIN	0x00000000
#define ICE_EVENT_ID_SLAVE_MAX	0xFFFFFFFF

#define ICE_BUF_SIZE_FRAME		(1920*1080*2 + 128)

typedef struct 
{
	int enable;   //0 ����, 1 ͼ�� default 1   
	int defalut_state;    //0 off ,1 on, default 1
	int dayJudgeCnt;   //100 cnt
	int nightJudgeCnt;    //10 cnt
	int day_to_night_delay;  // 5s
	int night_to_day_delay; // 90s
	int photosensitive_day_limit;  //75
	int photosensitive_night_limit; //40
	int  reserved[5];
} ISP_light_switch_param;


//! \ingroup group_communication
//! ״̬��
typedef enum
{
	ICE_STATUS_SUCCESS				= 0x00000000,		//!<  �ɹ�
	ICE_STATUS_COMMAND				= 0x00010000,		//!<  ����
	ICE_STATUS_ERROR2				= 0x00080000,		//!<  ����
	ICE_STATUS_ERROR_NOT_FOUND		= 0x00080001,		//!<  û�в��ҵ�
	ICE_STATUS_ERROR_NOT_SUPPORTED	= 0x00080002,		//!<  ��֧��
} ICE_COM_STATUS_E;

//! \ingroup group_communication
//! ����ͨ������
typedef struct 
{
	ICE_U32	u32Size;							//!<  ���ݰ�����
	ICE_U32	u32Type;							//!<  ����
	ICE_U32	u32Status;							//!<  ״̬
	ICE_U32	u32Channel;							//!<  ͨ����
	ICE_U32	u32Time;							//!<  ʱ��
	ICE_U32	u32Date;							//!<  ����
	ICE_U32	u32Id;								//!<  ��ʶ
	ICE_U32	u32Level;							//!<  ��������
} ICE_OPER_DATA_S;

///////////////////////////////////////////////////////////////////////////////////////////////////
// ���������������

// ��������
typedef struct
{
	ICE_U32	u32Size;							//!< ��i?I�㨹3��?��
	ICE_U8	u8SDKType;						//!< SDK��??������G��
	ICE_U8	u8Reserved[127];					//!<���ꨢ???
}ICE_NET_CONN_INFO_S;

///////////////////////////////////////////////////////////////////////////////////////////////////
// ?????��1?��i?I����G��

// ��?��?2������
typedef struct
{
	char filename[128];		//�����������ļ�����.g711a
	int index;				//���鲥������������

	char reserved[124];
	
} Broadcast_Param;

typedef struct
{
	unsigned char idle_state;
	unsigned int delay_time;
	
} relay_output;


typedef struct
{
	unsigned int IPaddr;
	unsigned int netmaskAddr;
	unsigned int gatewayAddr;
}NET_BASE_PARAM;

typedef enum
{
	ICE_NET_CONN_STAT_PC_SDK_OFFLINE = 0x00,
	ICE_NET_CONN_STAT_PC_SDK_ONLINE = 0x01,
	ICE_NET_CONN_STAT_BOARD_SDK_OFFLINE = 0x02,
	ICE_NET_CONN_STAT_BOARD_SDK_ONLINE = 0x03,
	ICE_NET_CONN_STAT_UNKNOW
}ICE_NET_CONN_STAT_TYPE_E;

typedef struct 
{
	ICE_NET_CONN_STAT_TYPE_E eNetStat;
	ICE_S32	s32Reserved[8];
}ICE_NET_CONN_STAT_S;


//! \ingroup group_communication
//! ��������������
typedef enum
{		
	ICE_CONTROL_TYPE_BASE 						= 0x1000,			//!< ���ƻ����ֶ�
	ICE_CONTROL_TYPE_VDR_ARM					= 0x1001,			//!< ��������
	ICE_CONTROL_TYPE_VDR_ARM_RSP				= 0x1002,			//!< ��������Ӧ��
	ICE_CONTROL_TYPE_VDR_DISARM					= 0x1003,			//!< �������
	ICE_CONTROL_TYPE_VDR_DISARM_RSP			    = 0x1004,			//!< �������Ӧ��
	ICE_CONTROL_TYPE_VDR_CLEAR_ALARAM			= 0x1005,			//!< �������
	ICE_CONTROL_TYPE_VDR_CLEAR_ALARAM_RSP     	= 0x1006,			//!< �������Ӧ��
	ICE_CONTROL_TYPE_VDR_REQUEST_ALARM_DATA		= 0x1007,			//!< ���󱨾�����
	ICE_CONTROL_TYPE_VDR_REQUEST_ALARM_DATA_RSP = 0x1008,			//!< ���󱨾�����Ӧ��	
	ICE_CONTROL_TYPE_STREAM_CONNECT			    = 0x1010,			//!< ������Ƶ����
	ICE_CONTROL_TYPE_STREAM_CONNECT_RSP     	= 0x1011,			//!< ������Ƶ����Ӧ��
	ICE_CONTROL_TYPE_STREAM_DISCONNECT			= 0x1012,			//!< �Ͽ���Ƶ����
	ICE_CONTROL_TYPE_STREAM_DISCONNECT_RSP     	= 0x1013,			//!< �Ͽ���Ƶ����Ӧ��
	ICE_CONTROL_TYPE_RESTART					= 0x1020,			//!< �����豸
	ICE_CONTROL_TYPE_RESTART_RSP     			= 0x1021,			//!< �����豸Ӧ��	
	ICE_CONTROL_TYPE_HEART_BEAT					= 0x1022,			//!< �豸����
	ICE_CONTROL_TYPE_HEART_BEAT_RSP     		= 0x1023,			//!< �豸����Ӧ��	
	ICE_CONTROL_TYPE_ERROR_REPORT				= 0x1024,			//!< �豸�����ϱ�
	ICE_CONTROL_TYPE_ERROR_REPORT_RSP     		= 0x1025,			//!< �豸�����ϱ�Ӧ��	
	ICE_CONTROL_TYPE_REQUEST_COUNT				= 0x1026,			//!< �������ͳ�ƽ��
	ICE_CONTROL_TYPE_REQUEST_COUNT_RSP     		= 0x1027,			//!< �������ͳ�ƽ��Ӧ��
	ICE_CONTROL_TYPE_TALK_DATA					= 0x1028,			//!< �����Խ�
	ICE_CONTROL_TYPE_TALK_BEGIN					= 0x1029,			//!< �����Խ���ʼ
	ICE_CONTROL_TYPE_TALK_END					= 0x1030,			//!< �����Խ�����
	ICE_CONTROL_TYPE_SDCARD_FORMAT              = 0x1031,           //!<sd����ʽ��	
	ICE_CONTROL_TYPE_SDCARD_FORMAT_RSP          = 0x1032,           //!<sd����ʽ��Ӧ��	
	ICE_CONTROL_TYPE_CAPTURE					= 0x1033,           //!< ץ�ģ���������ʶ��
	ICE_CONTROL_TYPE_CAPTURE_RSP				= 0x1034,           //!< ץ�ģ���������ʶ��Ӧ��
	ICE_CONTROL_TYPE_SDCARD_UNLOAD				= 0x1035,			//!< SD��ж��
	ICE_CONTROL_TYPE_SDCARD_UNLOAD_RSP			= 0x1036,			//!<SD ��ж��Ӧ��
	
	ICE_CONTROL_TYPE_TRANS_SERIAL_PORT			= 0x1037,           //!< ͸��������������
	ICE_CONTROL_TYPE_TRANS_SERIAL_PORT_RSP		= 0x1038,           //!< ͸��������������Ӧ��
	
	ICE_CONTROL_TYPE_BROADCSAT					= 0x1039,           //!< ������������
	ICE_CONTROL_TYPE_BROADCSAT_RSP				= 0x1040,           //!< ������������Ӧ��

	ICE_CONTROL_TYPE_VDR_REQUEST_ALARM_DATA_PASSWD		= 0x1041,			//!< ���󱨾����ݣ������룩
	ICE_CONTROL_TYPE_VDR_REQUEST_ALARM_DATA_PASSWD_RSP	= 0x1042,			//!< ���󱨾����ݣ������룩Ӧ��	
	
	ICE_CONTROL_TYPE_TRANS_SERIAL_PORT_RS232			= 0x1043,           //!< ͸��������������
	ICE_CONTROL_TYPE_TRANS_SERIAL_PORT_RS232_RSP		= 0x1044,           //!< ͸��������������Ӧ��
	
	ICE_CONTROL_TYPE_GET_IO_IN_STATE							= 0x1045,		//!<IO ����״̬��ȡ����
	ICE_CONTROL_TYPE_GET_IO_IN_STATE_RSP					= 0x1046,			//!<IO ����״̬��ȡ����Ӧ��

	ICE_CONTROL_TYPE_VDR_REQUEST_ALARM_DATA_NO_PIC	= 0x1047,			//!< ���󱨾�����(��ͼƬ����)
	ICE_CONTROL_TYPE_VDR_REQUEST_ALARM_DATA_NO_PIC_RSP = 0x1048,			//!< ���󱨾�����Ӧ��(��ͼƬ����)	

	ICE_CONTROL_TYPE_VDR_REQUEST_ALARM_DATA_NO_PIC_PASSWD = 0x1049,			//!< ���󱨾�����(��ͼƬ����)
	ICE_CONTROL_TYPE_VDR_REQUEST_ALARM_DATA_NO_PIC_PASSWD_RSP = 0x1050,			//!< ���󱨾�����Ӧ��(��ͼƬ����)

	ICE_CONTROL_TYPE_GET_CAMERA_HARDWARE_INFO	= 0x1051,	 //!< �������Ӳ����Ϣ
	ICE_CONTROL_TYPE_GET_CAMERA_HARDWARE_INFO_RSP = 0x1052,	 //!< �������Ӳ����ϢӦ��
	
	ICE_CONTROL_TYPE_GET_CAMERA_SOFTWARE_INFO	= 0x1053,			//!< ???��?��?������?tD??��	
	ICE_CONTROL_TYPE_GET_CAMERA_SOFTWARE_INFO_RSP = 0x1054,			//!< ???��?��?������?tD??�騮|��e	
	ICE_CONTROL_TYPE_SDCARD_FORMAT_ONLY              = 0x1055,           //!<sd?��??��??��2?��???	
	ICE_CONTROL_TYPE_SDCARD_FORMAT_ONLY_RSP          = 0x1056,           //!<sd?��??��??����|��e	2?��???

	ICE_CONTROL_TYPE_GET_OFFLINE_STATE_INFO	= 0x1057,			//!< ??��??��?����??��D??��
	ICE_CONTROL_TYPE_GET_OFFLINE_STATE_INFO_RSP	= 0x1058,		//!< ??��??��?����??��D??�騮|��e
	
	ICE_CONTROL_TYPE_END						= 0x105F,			
} ICE_CONTROL_TYPE_E;


//! ���������ݻ���
typedef union 
{
	ICE_U8 au8Buffer[ICE_BUF_SIZE_CONTROL];
} ICE_CONTROL_DATA_INTERNAL_U;

//! \ingroup group_communication
//! ����������ͷ�����ݻ���
typedef struct 
{
	ICE_OPER_DATA_S stHead;						
	ICE_CONTROL_DATA_INTERNAL_U unData;			
} ICE_CONTROL_DATA_S;

// ���Ʋ��������������
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
// �¼������������

//! \ingroup group_communication
//! �¼���������
typedef enum
{
	ICE_EVENT_TYPE_BASE			= 0x2000,		//!< ��??s?����?��???
	ICE_EVENT_TYPE_DTCA_EVENT	= 0x2001,		//!< ?��??��??s?��o?
	ICE_EVENT_TYPE_VLPR_EVENT	= 0x2002,		//!< ?��?����??s?��o?
    ICE_EVENT_TYPE_SFDV_EVENT	= 0x2004,		//!< GG3�̨�??s?��o?
	ICE_EVENT_TYPE_VLPREXT_EVENT	= 0x2005,	//!< 3��??��??1��??s?��o?
	ICE_EVENT_TYPE_HCNT_EVENT	= 0x2006,		//!< ��?��i��??s?��o?
	ICE_EVENT_TYPE_IPG_EVENT	= 0x2007,		//!< 3��??��??s?��o?
	ICE_EVENT_TYPE_NET_STAT_EVENT = 0x20fc, 	//!< ��???���䨬?��??t?��o?	
	ICE_EVENT_TYPE_VLPR_CFG_NOTIFY_EVENT = 0x20fd,	//!< ??������?��e??������??������?a��??t
	ICE_EVENT_TYPE_IO_EVENT     = 0x20fe,		//!< ��??��IO���䨬???�̡�
	ICE_EVENT_TYPE_RS232_EVENT	= 0x20ff,		//!< ��??�¡�??��(rs232)??��?��i?I
	ICE_EVENT_TYPE_RS485_EVENT	= 0x2100,		//!< ��??�¡�??��(rs485)??��?��i?I
	ICE_EVENT_TYPE_IO_EVENT_EXPIRED     = 0x2101,		//!< ��??��IO���䨬???�̡�!!��??��??��IG??����aG����a��?3i��?SDK???�㨺1��?rtsp?����?
	ICE_EVENT_TYPE_END			= 0x2102,		
} ICE_EVENT_TYPE_E;




//! �¼����ݻ���
typedef union 
{
	ICE_U8 au8Buffer[ICE_BUF_SIZE_EVENT];			//!< �¼����ݻ���
} ICE_EVENT_DATA_INTERNAL_U;

//! \ingroup group_communication
//! �¼�����ͷ�����ݻ���
typedef struct 
{
	ICE_OPER_DATA_S stHead;							//!< ����ͷ
	ICE_EVENT_DATA_INTERNAL_U unData;				//!< �¼�����
} ICE_EVENT_DATA_S;

// �¼������������
///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
// ��Ƶ���������������

//! \ingroup group_communication
//! Ŀ�괦����������
typedef enum
{
	ICE_VPRO_TYPE_BASE 				= 0x3000,		//!< Ŀ�����ݻ����ֶ�
	ICE_VPRO_TYPE_DTCA_TARGET_SET	= 0x3001,		//!< �ܽ��㷨Ŀ��
	ICE_VPRO_TYPE_VLPR_TARGET_SET	= 0x3002,		//!< �����㷨Ŀ��
	ICE_VPRO_TYPE_SFDV_TARGET_SET	= 0x3004,		//!< �г��㷨Ŀ��
	ICE_VPRO_TYPE_SNAP				= 0x3100,		//!< ץ������
	ICE_VPRO_TYPE_END				= 0x3101,		
} ICE_VPRO_TYPE_E;


//! Ŀ�괦�����ݻ���
typedef union 
{
	ICE_U8 au8Buffer[ICE_BUF_SIZE_VPRO];			//!< Ŀ�����ݻ���
} ICE_VPRO_DATA_INTERNAL_U;

//! \ingroup group_communication
//! Ŀ�괦������ͷ�����ݻ���
typedef struct 
{
	ICE_OPER_DATA_S stHead;							//!< ����ͷ
	ICE_VPRO_DATA_INTERNAL_U unData;				//!< Ŀ������
} ICE_VPRO_DATA_S;

// ��Ƶ���������������
///////////////////////////////////////////////////////////////////////////////////////////////////


//! \ingroup group_communication
//! �㷨���������������
typedef enum
{
	ICE_ALGO_CONFIG_TYPE_BASE 						= 0x4000,		//!< �㷨�������ͻ����ֶ�

	ICE_ALGO_CONFIG_TYPE_SET_AGLO_MODULE			= 0x4001,		//!< �����㷨ģ��
	ICE_ALGO_CONFIG_TYPE_SET_AGLO_MODULE_RSP		= 0x4002,		//!< �����㷨ģ��Ӧ��	
	ICE_ALGO_CONFIG_TYPE_GET_AGLO_MODULE			= 0x4003,		//!< ��ȡ�㷨ģ��
	ICE_ALGO_CONFIG_TYPE_GET_AGLO_MODULE_RSP		= 0x4004,		//!< ��ȡ�㷨ģ��Ӧ��

	ICE_ALGO_CONFIG_TYPE_SET_VIDEO_SOURCE_MODE		= 0x4100,		//!< ������Ƶ������ʽ
	ICE_ALGO_CONFIG_TYPE_SET_VIDEO_SOURCE_MODE_RSP	= 0x4101,		//!< ������Ƶ������ʽӦ��
	
	ICE_ALGO_CONFIG_TYPE_GET_VIDEO_SOURCE_MODE		= 0x4102,		//!< ��ȡ��Ƶ������ʽ
	ICE_ALGO_CONFIG_TYPE_GET_VIDEO_SOURCE_MODE_RSP	= 0x4103,		//!< ��ȡ��Ƶ������ʽӦ��
	

	ICE_ALGO_CONFIG_TYPE_SET_DTCA_ALGO_LIB_INFO		= 0x4200,		//!< �����ܽ��㷨����Ϣ(������ )
	ICE_ALGO_CONFIG_TYPE_SET_DTCA_ALGO_LIB_INFO_RSP	= 0x4201,		//!< �����ܽ��㷨����ϢӦ��	
	ICE_ALGO_CONFIG_TYPE_GET_DTCA_ALGO_LIB_INFO		= 0x4202,		//!< ��ȡ�ܽ��㷨����Ϣ�������롢�汾�š�������Ŀ�������ȣ�
	ICE_ALGO_CONFIG_TYPE_GET_DTCA_ALGO_LIB_INFO_RSP	= 0x4203,		//!< ��ȡ�ܽ��㷨����ϢӦ��
	
	ICE_ALGO_CONFIG_TYPE_SET_VLPR_ALGO_LIB_INFO		= 0x4204,		//!< ���ÿ����㷨����Ϣ(������ )
	ICE_ALGO_CONFIG_TYPE_SET_VLPR_ALGO_LIB_INFO_RSP	= 0x4205,		//!< ���ÿ����㷨����ϢӦ��	
	ICE_ALGO_CONFIG_TYPE_GET_VLPR_ALGO_LIB_INFO		= 0x4206,		//!< ��ȡ�����㷨����Ϣ�������롢�汾�š�������Ŀ�������ȣ�
	ICE_ALGO_CONFIG_TYPE_GET_VLPR_ALGO_LIB_INFO_RSP	= 0x4207,		//!< ��ȡ�����㷨����ϢӦ��
	
	ICE_ALGO_CONFIG_TYPE_SET_SFDV_ALGO_LIB_INFO		= 0x4208,		//!< �����г��㷨����Ϣ(������ )
	ICE_ALGO_CONFIG_TYPE_SET_SFDV_ALGO_LIB_INFO_RSP	= 0x4209,		//!< �����г��㷨����ϢӦ��	
	ICE_ALGO_CONFIG_TYPE_GET_SFDV_ALGO_LIB_INFO		= 0x4210,		//!< ��ȡ�г��㷨����Ϣ�������롢�汾�š�������Ŀ�������ȣ�
	ICE_ALGO_CONFIG_TYPE_GET_SFDV_ALGO_LIB_INFO_RSP	= 0x4211,		//!< ��ȡ�г��㷨����ϢӦ��
	
	ICE_ALGO_CONFIG_TYPE_SET_ITSE_ALGO_LIB_INFO		= 0x4212,		//!< ���ý�ͨ�¼��㷨����Ϣ(������ )
	ICE_ALGO_CONFIG_TYPE_SET_ITSE_ALGO_LIB_INFO_RSP	= 0x4213,		//!< ���ý�ͨ�¼��㷨����ϢӦ��	
	ICE_ALGO_CONFIG_TYPE_GET_ITSE_ALGO_LIB_INFO		= 0x4214,		//!< ��ȡ��ͨ�¼��㷨����Ϣ�������롢�汾�š�������Ŀ�������ȣ�
	ICE_ALGO_CONFIG_TYPE_GET_ITSE_ALGO_LIB_INFO_RSP	= 0x4215,		//!< ��ȡ��ͨ�¼��㷨����ϢӦ��

	ICE_ALGO_CONFIG_TYPE_SET_DTCA_RULE_PARAM		= 0x4300,		//!< �����ܽ��㷨��������
	ICE_ALGO_CONFIG_TYPE_SET_DTCA_RULE_PARAM_RSP	= 0x4301,		//!< �����ܽ��㷨��������Ӧ��
	ICE_ALGO_CONFIG_TYPE_GET_DTCA_RULE_PARAM		= 0x4302, 		//!< ��ȡ�ܽ��㷨��������
	ICE_ALGO_CONFIG_TYPE_GET_DTCA_RULE_PARAM_RSP	= 0x4303, 		//!< ��ȡ�ܽ��㷨��������Ӧ��
	
	ICE_ALGO_CONFIG_TYPE_SET_VLPR_RULE_PARAM		= 0x4304,		//!< ���ÿ����㷨��������
	ICE_ALGO_CONFIG_TYPE_SET_VLPR_RULE_PARAM_RSP	= 0x4305,		//!< ���ÿ����㷨��������Ӧ��
	ICE_ALGO_CONFIG_TYPE_GET_VLPR_RULE_PARAM		= 0x4305,		//!< ��ȡ�����㷨��������
	ICE_ALGO_CONFIG_TYPE_GET_VLPR_RULE_PARAM_RSP	= 0x4306,		//!< ��ȡ�����㷨��������Ӧ��
	
	ICE_ALGO_CONFIG_TYPE_SET_SFDV_RULE_PARAM		= 0x4307,		//!< �����г��㷨��������
	ICE_ALGO_CONFIG_TYPE_SET_SFDV_RULE_PARAM_RSP	= 0x4308,		//!< �����г��㷨��������Ӧ��
	ICE_ALGO_CONFIG_TYPE_GET_SFDV_RULE_PARAM		= 0x4309, 		//!< ��ȡ�г��㷨��������
	ICE_ALGO_CONFIG_TYPE_GET_SFDV_RULE_PARAM_RSP	= 0x4310, 		//!< ��ȡ�г��㷨��������Ӧ��
	
	ICE_ALGO_CONFIG_TYPE_SET_HCNT_RULE_PARAM		= 0x4311,		//!< ���ü����㷨��������
	ICE_ALGO_CONFIG_TYPE_SET_HCNT_RULE_PARAM_RSP	= 0x4312,		//!< ���ü����㷨��������Ӧ��
	ICE_ALGO_CONFIG_TYPE_GET_HCNT_RULE_PARAM		= 0x4313, 		//!< ��ȡ�����㷨��������
	ICE_ALGO_CONFIG_TYPE_GET_HCNT_RULE_PARAM_RSP	= 0x4314, 		//!< ��ȡ�����㷨��������Ӧ��
	
	ICE_ALGO_CONFIG_TYPE_END						= 0x4315,		
} ICE_ALGO_CONFIG_TYPE_E;

///////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
	ICE_U32 u32Expline;			//�ֶ��ع�ʱ��
	ICE_S32 s32AGain;			//�ֶ�ģ������
	ICE_S32 s32DGain;			//�ֶ���������

	ICE_U32 u32Mode;			//ģʽ��0�Զ���1��ʱ��2�ֶ�

	ICE_U32 u32DayBegin;		//���쿪ʼʱ�䣨����Ϊ��λ������8��Ϊ480��
	ICE_U32 u32DayEnd;			//�������ʱ�䣨����Ϊ��λ������18��Ϊ1080��
	ICE_U32 u32DayExplineMin;	//������С�ع�ʱ��
	ICE_U32 u32DayExplineMax;	//��������ع�ʱ��
	ICE_S32 s32DayAGainMin;		//������Сģ������
	ICE_S32 s32DayAGainMax;		//�������ģ������
	ICE_S32 s32DayDGainMin;		//������С��������
	ICE_S32 s32DayDGainMax;		//���������������

	ICE_U32 u32NightBegin;		//���Ͽ�ʼʱ�䣨����Ϊ��λ������20��Ϊ1200��
	ICE_U32 u32NightEnd;		//���Ͻ���ʱ�䣨����Ϊ��λ������6��Ϊ360��
	ICE_U32 u32NightExplineMin;	//������С�ع�ʱ��
	ICE_U32 u32NightExplineMax;	//��������ع�ʱ��
	ICE_S32 s32NightAGainMin;	//������Сģ������
	ICE_S32 s32NightAGainMax;	//�������ģ������
	ICE_S32 s32NightDGainMin;	//������С��������
	ICE_S32 s32NightDGainMax;	//���������������

	ICE_U32 u32OtherExplineMin;	//����ʱ����С�ع�ʱ��
	ICE_U32 u32Focus;			//����
	ICE_S32 s32Height;			//��װ�߶�
	ICE_S32 s32HeightAlgo;		//��װ�߶��Զ�����
	ICE_S32 s32Distance;		//��װ����
	ICE_S32 s32DistAlgo;		//��װ�����Զ�����

	ICE_U32 u32LightMode;		//�����ģʽ
	ICE_U32 u32ColorMode;		//��ת��ģʽ

	ICE_U32 u32AlgoWidth;
	ICE_U32 u32AlgoHeight;

} ICE_ExpAttr_S;

//����ƿ���ģʽ
typedef enum
{
	ICE_LIGHT_MODE_AUTO = 0,		//�����Զ����
	ICE_LIGHT_MODE_BY_TIME,			//ʱ�����
	ICE_LIGHT_MODE_BY_TMLS,			//������ʱ���ۺϿ��ƣ������ǹ���������Ϊʱ�����
} ICE_LIGHT_MODE_TYPE_E;

typedef enum
{
	ICE_COLOR_MODE_AUTO = 0,		//�����Զ����
	ICE_COLOR_MODE_COLOR,			//��ɫ
	ICE_COLOR_MODE_NOCOLOR,			//�ڰ�
	
} ICE_COLOR_MODE_TYPE_E;


typedef enum
{
	ICE_RS485_PROTOCOL_HN = 1,		//���Ͽ���������
	ICE_RS485_PROTOCOL_HL,			//�Ϻ���������
	ICE_RS485_PROTOCOL_BA,			//�Ϻ�����
	ICE_RS485_PROTOCOL_ICE,		//��оԭ��
	ICE_RS485_PROTOCOL_AJS,     //������Э��
	
} ICE_RS485_PROTOCOL_TYPE_E;

typedef enum
{
	ICE_HCNT_DOOR_FRONT = 0,		//ǰ��
	ICE_HCNT_DOOR_MID,				//����
	ICE_HCNT_DOOR_BACK				//����
	
} ICE_HCNT_DOOR_TYPE_E;

typedef enum
{
	ICE_HCNT_LINK_SERVER_NET = 0,		//����������Ӳ�����̫��ģʽ
	ICE_HCNT_LINK_SERVER_RS485,			//����������Ӳ�������rs485 ģʽ
	
} ICE_HCNT_IPC_LINK_SERVER_MODE_E;

typedef enum
{
	ICE_HCNT_CLEAR_PERIOD = 0,		//����
	ICE_HCNT_CLEAR_TRIGGER,			//�ⴥ��
	
} ICE_HCNT_CLEAR_MODE_E;

typedef enum
{
	ICE_HCNT_TRIGGER_RELAYIN = 0,		//����������
	ICE_HCNT_TRIGGER_RS485,				//RS485����
	ICE_HCNT_TRIGGER_PROGRAM,			//�������
	
} ICE_HCNT_TRIGGER_MODE_E;

typedef enum
{
	ICE_HCNT_RELAYIN_OFF = 0,		//�պϴ�������
	ICE_HCNT_RELAYIN_ON,			//�򿪴�������
	
} ICE_HCNT_RELAYIN_MODE_E;

typedef enum
{
	ICE_HCNT_STORE_FLASH = 0,		//FLASH�洢
	ICE_HCNT_STORE_SDCARD,			//SD���洢

} ICE_HCNT_STORE_MODE;

typedef enum
{
	ICE_HCNT_COLLECT_HOUR = 0,		//Сʱ����
	ICE_HCNT_COLLECT_DAY,			//�����

} ICE_HCNT_COLLECT_MODE;

#define MAX_HCNT_TEXT 64
typedef struct
{
	ICE_S32 s32RS485Type;
	ICE_U32 u32DoorType;
	ICE_U32 u32Railway;
	
	ICE_S8 as8ServerIP[16];
	ICE_S8 as8Username[MAX_HCNT_TEXT];
	ICE_S8 as8Password[MAX_HCNT_TEXT];
	ICE_S8 as8CameraID[MAX_HCNT_TEXT];
	ICE_U32 u32HBInterval;			//��������
	
	ICE_U32 u32ClearMode;			//����ģʽ
	ICE_U32 u32ClearInterval;		//��������
	ICE_U32 u32TriggerMode;			//�ⴥ��ģʽ
	ICE_U32 u32RelayinMode;			//����������ģʽ
	
	ICE_U32 u32DataStore;			//�Ƿ����ݴ洢
	ICE_U32 u32StoreMode;			//���ݴ洢ģʽ
	ICE_U32 u32StoreSize;			//�洢�ռ�
	ICE_U32 u32StoreStat;			//�Ƿ�ͳ�ƴ洢
	ICE_U32 u32StatCollect;			//�Ƿ����ݻ���
	ICE_U32 u32CollectMode;			//����ģʽ
	
	ICE_U32 au32Reserved[32];

} ICE_HCNTAttr_S;


//ͼ����OSDλ������

typedef enum
{
	ICE_OSD_LOCATION_LEFT_TOP = 0,	//����
	ICE_OSD_LOCATION_RIGHT_TOP,		//����
	ICE_OSD_LOCATION_LEFT_BOTTOM,	//����
	ICE_OSD_LOCATION_RIGHT_BOTTOM,	//����
	ICE_OSD_LOCATION_TOP_MID,		//�Ͼ���
	ICE_OSD_LOCATION_BOTTOM_MID,		//�¾���
} ICE_OSD_LOCATION_TYPE_E;

//ͼ������OSDλ������
typedef enum
{
	ICE_OSD_LOCATION_IN_IMAGE = 0,
	ICE_OSD_LOCATION_OUT_TOP,	   //ͼ���Ϸ�
	ICE_OSD_LOCATION_OUT_BOTTOM,   //ͼ���·�
} ICE_OSD_BIG_LOCATION_TYPE_E;



typedef enum
{
	ICE_CAMERA_DIRECTION_NORTH = 0,	//������
	ICE_CAMERA_DIRECTION_WEST,		//�ɶ�����
	ICE_CAMERA_DIRECTION_EAST,		//������
	ICE_CAMERA_DIRECTION_SOUTH		//�ɱ�����
	
} ICE_CAMERA_DIRECTION_TYPE_E;


typedef enum
{
	ICE_OSD_FONTSIZE_SMALL= 0,	//С
	ICE_OSD_FONTSIZE_MEDIUM,		//��
	ICE_OSD_FONTSIZE_LARGE,		//��
} ICE_OSD_FONTSIZE_TYPE_E;


#define MAX_OSD_TEXT 64
#define MAX_CUSTOM_OSD_LINE_NUM 6

typedef struct
{
	//video
	ICE_U32 u32OSDLocationVideo;		//����λ��
	ICE_U32 u32ColorVideo;				//��ɫ

	ICE_U32 u32DateVideo;				//�Ƿ��������ʱ��
	ICE_U32 u32License;					//�Ƿ������Ȩ��Ϣ

	ICE_U32 u32CustomVideo;				//�Ƿ�����Զ�����Ϣ
	char szCustomVideo[MAX_OSD_TEXT];	//�Զ�����Ϣ

	//jpeg
	ICE_U32 u32OSDLocationJpeg;			//����λ��
	ICE_U32 u32ColorJpeg;				//��ɫ

	ICE_U32 u32DateJpeg;				//�Ƿ��������ʱ��
	ICE_U32 u32Algo;					//�Ƿ�����㷨��Ϣ

	ICE_U32 u32DeviceID;				//�Ƿ�����豸ID
	char szDeviceID[MAX_OSD_TEXT];		//�豸ID

	ICE_U32 u32DeviceName;				//�Ƿ�����豸����
	char szDeviceName[MAX_OSD_TEXT];	//�豸����

	ICE_U32 u32CamreaLocation;			//�Ƿ���ӵص���Ϣ
	char szCamreaLocation[MAX_OSD_TEXT];	//�ص���Ϣ

	ICE_U32 u32SubLocation;				//�Ƿ�����ӵص���Ϣ
	char szSubLocation[MAX_OSD_TEXT];	//�ӵص���Ϣ

	ICE_U32 u32ShowDirection;			//�Ƿ�����������
	ICE_U32 u32CameraDirection;			//�������

	ICE_U32 u32CustomJpeg;				//�Ƿ�����Զ�����Ϣ

	ICE_U32 u32ItemDisplayMode;             //ͼƬ��Ϣ��ʾģʽ��0��������ʾ��1��������ʾ,Ĭ��0
	ICE_U32 u32DateMode;                 //������ʾģʽ��0��xxxx/xx/xx   1��xxxx��xx��xx�գ�Ĭ��0
	ICE_U32 u32BgColor;                  //OSD ����ɫ��0����ȫ͸����1��������ɫ��Ĭ��0
	ICE_U32 u32FontSize;				//�����С��0:С��1:�� 2:��,Ĭ��Ϊ�У���540P ���£��л�ת��ΪС
	ICE_U32 u32ExpandMode;				//����ģʽ��0:�����ţ�1:ͼ�������ţ�2:ͼ��������
	char szCustomJpeg[MAX_OSD_TEXT - 20];	//�Զ�����Ϣ
	
	char szCustomVideo6[MAX_CUSTOM_OSD_LINE_NUM * MAX_OSD_TEXT];	//�Զ�����Ϣ
	char szCustomJpeg6[MAX_CUSTOM_OSD_LINE_NUM * MAX_OSD_TEXT];	//�Զ�����Ϣ

} ICE_OSDAttr_S;


#define ICE_SCHED_TASK_MASK_ARM		0x00000003
#define ICE_SCHED_TASK_MASK_RELAY	0x0000000C
#define ICE_SCHED_TASK_MASK_COLOR	0x00000030

typedef enum
{
	ICE_SCHED_TASK_TYPE_ARM			= 0x00000001, 	//����
	ICE_SCHED_TASK_TYPE_DISARM		= 0x00000002, 	//����
	ICE_SCHED_TASK_TYPE_RELAY_ON	= 0x00000004, 	//�������պ�
	ICE_SCHED_TASK_TYPE_RELAY_OFF	= 0x00000008, 	//��������
	ICE_SCHED_TASK_TYPE_GRAY		= 0x00000010,	//��ת��
	ICE_SCHED_TASK_TYPE_COLOR		= 0x00000020, 	//��ת��
	
} ICE_SCHED_TASK_TYPE_E;

typedef struct
{
	ICE_U32 u32Time;		//ʱ�䣨����Ϊ��λ������20��Ϊ1200��
	ICE_U32 u32Type;		//�������ͣ����������߿��������
	ICE_U32 u32TimeEnd;		//ʱ�䣨����Ϊ��λ������20��Ϊ1200��
	ICE_U32 u32Reserved[7];	//�����ֶ�
	
} ICE_SCHED_TASK_S;

typedef struct
{
	ICE_U8 u8UseSnapCamera;
	ICE_U32 u32IP;
	ICE_U32 u32Delay;
	ICE_U32 u32SnapCount;
	ICE_U32 u32SnapInterval;
	ICE_U32 u32Reserved[8];
	
} ICE_SNAP_CAMERA_S;

typedef enum
{
	ICE_PHYCHN_MODE_SUB_VENC = 0,		//������
	ICE_PHYCHN_MODE_VO,					//vo���
	
} ICE_PHYCHN_MODE_TYPE_E;


typedef struct
{
	ICE_U32 u32PhyChn;
	ICE_U32 u32RCMain;
	ICE_U32 u32RCSub;
	ICE_U32 u32CloseupEn; //�Ƿ����������дͼ��
	ICE_U32 u32Qfactor;//ץ��ͼƬ����1~99,Ĭ��90
	ICE_U32 u32FullEn;//�Ƿ�ץ�ĳ���ȫ��ͼ
	ICE_U32 u32CloseupInFullEn; //�Ƿ���ȫ��ͼ�ϵ��ӳ�����дͼ
	ICE_U16 u16Width;//ץ�ķֱ��� ���
	ICE_U16 u16Height;//ץ�ķֱ��ʸ߶�
	ICE_U32 u32PlateSize;	//����ͼ�Ŵ�����1 2 3
	ICE_U32 u32Reserved[2];
	
} ICE_PHYCHN_CFG_S;


typedef struct
{
	ICE_U32 u32VFDRelayout;			//����������������
	ICE_U32 u32DTCARelayout;		//�ܽ�������������
	
	ICE_U32 u32Expline;			//������ֶ��ع�ʱ��
	ICE_S32 s32AGain;			//������ֶ�ģ������
	ICE_S32 s32DGain;			//������ֶ���������
	ICE_U32 u32Mode;			//������ع�ģʽ��0��ȫ�Զ���1�Զ���2�ֶ�
	ICE_U32 u32ExplineMin;		//�������С�ع�ʱ��
	ICE_U32 u32ExplineMax;		//���������ع�ʱ��
	ICE_S32 s32AGainMin;		//�������Сģ������
	ICE_S32 s32AGainMax;		//��������ģ������
	ICE_S32 s32DGainMin;		//�������С��������
	ICE_S32 s32DGainMax;		//����������������
	
	ICE_U32 u32Reserved[1024];			//�����ֶ�
	
} ICE_VFD_PARAM_S;


//�Զ��ع��Ե��ڲ���
typedef struct
{
	int expARegulateEn;//�Ƿ����ع��Ե��ڣ�0�رգ�1������Ĭ��Ϊ��1 ����
	int dayOrNightJudgeCnt; //�����жϵ�����������һ�δ��һ�룻Ĭ��Ϊ��10
	int lumLimitForDay; //�������ȷֽ��ߣ�Ĭ��Ϊ��75
	int lumLimitForNight; //ҹ�����ȷֽ��ߣ�Ĭ��Ϊ��65
	int maxValidBright; //����ʶ��Ч���������ޣ�Ĭ��Ϊ��120
	int minValidBright; //����ʶ��Ч���������ޣ�Ĭ��Ϊ��80
	int maxValidForEnvBright; //������Ƴ��������������ޣ�Ĭ��Ϊ��110
	int minValidForEnvBright; //������Ƴ��������������ޣ�Ĭ��Ϊ��90
	int maxExpCompensation; //�عⲹ���������ֵ��Ĭ��Ϊ��160
	int minExpCompensation;//�عⲹ��������Сֵ��Ĭ��Ϊ��30
	int initExpCompensation;//�عⲹ��ֵ��ʼֵ��Ĭ��Ϊ��70
	int expReguateInterval;//�������������عⲹ�����ĵ��������Ĭ��Ϊ��5
	
	int antiflickerEn;  //ISP����˸�Ƿ�ʹ�� 0 �رգ� 1ʹ�ܣ�Ĭ��ֵΪ��0 �ر�
	int antiflickerFrequency; //ISP ����Ƶ��ֵ������ԴƵ��Ϊ 50Hz ʱ������Ƶ��ֵ����Ϊ 50������ԴƵ��Ϊ 60Hz ʱ������Ƶ��ֵ����Ϊ 60��Ĭ��Ϊ�� 50HZ
	int antiflickerMode; //ISP ����ģʽ 0��1�� Ĭ��Ϊ��1
	int s32PowerFrequencyCompensation; //��Ƶ����
	int as32Reserved[9]; //Ԥ������
}ICE_EXP_AREGULATE_PARAM;

//ע���Զ��ع��Ե��ڲ���������ֻ��Ҫ��ʾ�����͹رռ��ɣ�ISP����˸����Ҫ��¶�������������������Ҫ���ԣ��������ز����ļ��ֶ��޸ģ�Ȼ���ٵ��뵽���


//HTTP post ������


typedef struct
{
	int httpPostEn; //�Ƿ��http post ���ܣ�Ĭ�Ϲر�
	int directionFalg; //������ڷ����־��0 ��ڣ�1 ����Ĭ��ֵΪ��0 ���
	int parkID; //ͣ����ID��Ĭ��Ϊ��13
	char ipStr[20]; //������IP��ַ��Ĭ��Ϊ��123.57.136.148
	int port; //���������ʶ˿ڣ�Ĭ��Ϊ��80
	char domainName[44]; //������IP��Ӧ��������Ĭ��Ϊ��service.tigmall.com
	char ipStr_bak[20]; //���÷�����IP��ַ
	char path[64]; //·�������ϳ���ڷ����־��ͣ������Ŵ���Ĭ��Ϊ: /parking/count
	int maxSendCnt; //����������, Ĭ��Ϊ��3
	int mode; // 2������ģʽ2 ��   1��3������ģʽ1
	int autoAlarmoutEn; //�Ƿ���������Զ���բ,Ĭ�ϲ�����
	int autoAlarmoutMode;//  ģʽ1��ʶ��ɹ���բ����Ĭ�ϣ�,ģʽ2��ȫ����բ��
	int snap_full;//  �Ƿ���ȫ��ͼ��
	int snap_closeup;//  �Ƿ��ͳ�����дͼ��
	int enable_baksvr;	//�Ƿ����ñ��÷�����
	short enable_offline;	//�Ƿ����ö�������
	short interval;	//���������������
	int as32Reserved[3]; //Ԥ������
}ICE_HTTP_POST_PARAM;



#define MAX_USEABLE_UART_CNT 2  //�������õĴ��ڸ���

typedef enum{
	UART_PLATENUM_PROTOCOL_ONE =0,	//����Э��1
	UART_TRANS_TRANSMIT,	//͸������
	UART_LED_CONTROL,	//LED������
	UART_MIX_MODE,		//���ģʽ
	UART_PLATENUM_PROTOCOL_TWO,   //����Э��2
	UART_PLATENUM_PROTOCOL_THR,   //����Э��3  ������
	UART_PLATENUM_PROTOCOL_FOUR,	 // ����Э��4 ���ͨ
	UART_RS232_GETPHONEMAC     // rs232  wifi ̽��Э��
}ICE_UART_WORK_MODE_E;

//ǿ������ѻ���������
typedef struct {
	int force_offline_enable;
	int reserved[15];
}Force_camera_offline_cfg_param;

typedef enum
{
	LED_CARD_SERIAL_PROTOL1 = 0,   //���Э�� led ���ƿ�Э��1
	LED_CARD_SERIAL_PROTOL2,
	LED_CARD_SERIAL_MAX_VALUE
}LED_CARD_SERIAL_TYPE_PROTOL;

typedef struct
{
	int uartEn; //�����Ƿ�ʹ��0 �����ã�1ʹ�ã�Ĭ��Ϊ1ʹ��
	int uartWorkMode; //���ڹ���ģʽ��0:����Э�飬1:͸�����ڣ�Ĭ��Ϊ0 ����Э��
	int baudRate;  //�����ʣ�Ĭ��ֵΪ9600�����ò����� 1200��2400��4800��9600��19200��38400��115200
	int dataBits;  //����λ��Ĭ��ֵΪ 8����ѡֵΪ�� 5��6��7��8
	int parity;    //У��λ��Ĭ��ֵΪ �ޣ���ѡֵΪ���ޡ���У�顢żУ�顢��ǡ��ո�
	int stopBits;  //ֹͣλ��Ĭ��ֵΪ 1����ѡֵΪ��1��2
	int flowControl; //����ģʽ��Ĭ��ֵΪ �ޣ���ѡֵΪ��  �ޡ�Ӳ����Xon/Xoff
	int LEDControlCardType; //����LED ����ģʽ�£����ƿ�������
	int LEDBusinessType;   //ĳһ��LED���ƿ���ҵ�����ͣ�ʲô�����µ�������ӡ��Щ��Ϣ
	int as32Reserved[3]; //Ԥ������
}ice_uart;

typedef struct{
	ice_uart uart_param[MAX_USEABLE_UART_CNT];//�����������
	int as32Reserved[10]; //Ԥ������
}ICE_UART_PARAM;

//SD ����ز���

typedef enum{
	SDS_NO =1,	//SD��������
	SDS_ERROR,	//SD�����ִ���
	SDS_ENOUGH,	//SD������û����������
	SDS_FULL,		//SD������
	SDS_UNFORMATTED   //SD��δ��ʽ��
}DISK_STATUS;

typedef enum{
	STORE_NO_CLIENT_CONNET =0,	//SD�������洢
	STORE_ALWAYS,	//SD��ʵʱ�洢
	STORE_NEVER	//SD card not store
}DISK_STORE_MODE;

typedef struct
{
	int status; //SD ��״̬��
	int totalSize; //�ܿռ��С
	int usedSize;//���ÿռ��С
	int availableSize; //���ÿռ��С
	int SDStoreMode; //sd �洢ģʽ�������洢��ʵʱ�洢��Ĭ�϶���
	int SDFormatFlag; //sd ���Ƿ��ڸ�ʽ����
	int SDUnloadFlag; //SD ������ж��
	int SDUmountFlag;//SD �Ƿ���Խ�ң����ڸ�ʽ����ж��
	int u32Reserved[6];
}SD_card_param;

#define	MAX_DISK_NAME_LEN		128	//�������������
#define MAX_DISK_MOUNT_PATH_LEN	128	//����Mount·���������
#define DISK_DEV_NODE_LEN			12	// EX: /dev/sda	


typedef struct
{
	int SDTotalNum;
	SD_card_param SDCard_param;
	char	MountPoint[MAX_DISK_MOUNT_PATH_LEN];	//����д��̣�Mount��Ŀ¼���ƣ�ע������������"/"����
	char	DevNode[DISK_DEV_NODE_LEN];	// EX: /dev/mmcblk0
}SD_CARD;

typedef struct
{
	int EnUserExtPartModel;
	int UserExtPartSize;
	char UserExtPartMountPath[MAX_DISK_MOUNT_PATH_LEN];
	int u32Reserved[32];
}SD_CARD_USER_EXT_CFG;

typedef struct
{
	char	id[64];

} Dev_ID;



typedef struct
{
	int mode;		//0��ʾ����������1��ʾʵʱ����,2 ��������բ�򲻹���
	int match;		//������ƥ�����ƣ���Χ��60%-100%����Ĭ�ϣ�80%
	int black_mode; //������������բģʽ��0 ��������բ��1 ��բ
	int black_match; //������ƥ�����ƣ���Χ��60%-100%����Ĭ�ϣ�80%
	int temp_mode;  //��ʱ��������բģʽ��0 ��������բ��1 ��բ
	char reserved[112];
	
} WhiteList_Param;


typedef struct
{
	int alarm_in_delay;
	int alarm_in_stable_frame;   
	int alarm_in_check_interval; //�ظ���Ȧģʽ�£�������ʱ����0~2000ms,Ĭ��0
	int max_again_process_cnt;   //�ظ���Ȧģʽ�£����Ƴ����δ������0~30,Ĭ��10
	int u32Reserved[10];  
} HDTrigger_Param;

#define WHITELIST_VALID_TIME_LEN 10
typedef struct{
	char plate_number[16];
	char valid_sdate[WHITELIST_VALID_TIME_LEN+1];
	char valid_edate[WHITELIST_VALID_TIME_LEN+1];	
	char valid_stime[WHITELIST_VALID_TIME_LEN+1];
	char valid_etime[WHITELIST_VALID_TIME_LEN+1];	
	char type[WHITELIST_VALID_TIME_LEN+1];	
	char reserved[64];	
}WHITELIST_ITEM;

typedef struct
{
	ICE_U32 u32Enable;		//�Ƿ���
	ICE_U32 u32Time;		//����Ϊ��λ������8��Ϊ480
	ICE_U32 u32Reserved[16];
	
} AutoRebootParam;

typedef struct
{
	char old_passwd[16];
	char new_passwd[16];
	ICE_U32 u32Reserved[64];
	
} PasswdParam;

typedef struct
{
	ICE_U32 u32DNS;		//��ѡDNS
	ICE_U32 u32DNS2;	//����DNS
	ICE_U32 u32Reserved[6];
	
} DNSParam;

typedef struct
{
	ICE_U32 u32Luminance;		//����
	ICE_U32 u32Reserved[7];
	
} LightParam;

typedef struct
{
	ICE_U32 u32Enable;			//��?��??a??
	ICE_U32 u32Interval;		//?s��??a?��?��?��
	ICE_U32 u32VideoReoutTimeOutCount;		// ����?�̡䣤����?�꨺??t��??a?��3?����??��y
	ICE_U32 u32Reserved[15];
	
} ReOpenParam;

typedef struct
{
	ICE_U8 io_in_0;
	ICE_U8 io_in_1;
	ICE_U8 io_in_2;
	ICE_U8 io_in_3;
}IoInState;

typedef struct
{
	ICE_U8 isOpen;
}TimerReboot;

typedef struct
{
	ICE_U32 u32IP;		//FTP server ip
	char szUserName[64];		//user name
	char szPasswd[64];		//passwd
	ICE_U32 u32HeartBeatInt;		//heart inverval
	ICE_U32 u32Enable;  //FTP upload open or close
	ICE_U32 u32Plate; // �ļ����Ƿ�������ƺ�
	ICE_U32 u32XML; //�Ƿ��ϴ�XML �ļ�
	char s8Path[100]; //�ϴ�·��
	ICE_U32 u32Reserved[2];
	
}FTPParam;

typedef struct
{
	int enable;	//�Ƿ�ʹ��
	char ledip[16];//led��ip
	int ledport;//led�Ķ˿ں�
	int as32Reserved[4]; //Ԥ������

} ICE_LED_PARAM;

//!��ȡ���Ӳ����Ϣ
typedef struct
{
	ICE_U32 u32FlashSize;
	ICE_U32 u32AlpuIcType;
	ICE_U32 reserved[14];

} ICE_CAMERA_HW_INFO_S;

typedef struct
{
	ICE_U16 u16EnStrobeCtl;			//�Ƿ�������������
	ICE_U16 u16TriggerDelay;			//����-ʶ����ʱ
	ICE_U16 u16StrobeLastTime;		//�����Ƴ���ʱ��
	ICE_U16 u16StrobeMode;				//0:����ģʽ��1:����ģʽ
	ICE_U16 u16Reserved;				//short����
	ICE_U32 reserved[7];				//����λ
}strobe_light_param_st;//����������

#define ISP_CFG_FILE "ISP_param.cfg"
#define UART_CFG_FILE "uart_param.cfg"
#define SD_CFG_FILE "SD_param.cfg"
#define WHITELIST_CFG_FILE "whitelist_param.cfg"
#define WHITELIST_FILE "whitelist.txt"
#define USER_DATA_FILE "user_data.cfg"
#define HDTRIGGER_CFG_FILE "alarm_in_stable.txt"
#define UAER_PASSWD_FILE "user_passwd.cfg"
#define FILE_LIGHT_FILE "fill_light.cfg"
#define LED_CFG_FILE "Led_Param.cfg"
#define STROBE_LIGHT_CFG "strobe_light.cfg"




//! \ingroup group_communication
//! ������������������
typedef enum
{
	ICE_CAMERA_CONFIG_TYPE_BASE 					= 0x5000,		//!< ����������ͻ����ֶ�

	ICE_CAMERA_CONFIG_TYPE_SET_BASE_PARAM			= 0x5001,		//!< ��������������������ơ�IP��ַ���豸��ŵȣ�
	ICE_CAMERA_CONFIG_TYPE_SET_BASE_PARAM_RSP		= 0x5002,		//!< ���������������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_BASE_PARAM			= 0x5003,		//!< ��ȡ�����������
	ICE_CAMERA_CONFIG_TYPE_GET_BASE_PARAM_RSP		= 0x5004,		//!< ��ȡ�����������Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_SYSTEM_TIME			= 0x5005,		//!< �������ϵͳʱ��
	ICE_CAMERA_CONFIG_TYPE_SET_SYSTEM_TIME_RSP		= 0x5006,		//!< �������ϵͳʱ��Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_SYSTEM_TIME			= 0x5007,		//!< ��ȡ���ϵͳʱ��
	ICE_CAMERA_CONFIG_TYPE_GET_SYSTEM_TIME_RSP		= 0x5008,		//!< ��ȡ���ϵͳʱ��Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_ISP_PARAM			= 0x5009,		//!< ����ISP�������ع⡢���桢��ƽ��)
	ICE_CAMERA_CONFIG_TYPE_SET_ISP_PARAM_RSP		= 0x5010,		//!< ����ISP����Ӧ!��
	ICE_CAMERA_CONFIG_TYPE_GET_ISP_PARAM			= 0x5011,		//!< ��ȡISP����
	ICE_CAMERA_CONFIG_TYPE_GET_ISP_PARAM_RSP		= 0x5012,		//!< ��ȡISP����Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_VENC_PARAM			= 0x5013,		//!< ���ñ���������������ֱ��ʡ����ʿ��Ʒ�ʽ�ȣ�
	ICE_CAMERA_CONFIG_TYPE_SET_VENC_PARAM_RSP		= 0x5014,		//!< ���ñ������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_VENC_PARAM			= 0x5015,		//!< ��ȡ�������
	ICE_CAMERA_CONFIG_TYPE_GET_VENC_PARAM_RSP		= 0x5016,		//!< ���ñ������Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_IO_PARAM				= 0x5017,		//!< ����IO��������ƽ������ߡ��͡������ء��½��أ������������
	ICE_CAMERA_CONFIG_TYPE_SET_IO_PARAM_RSP			= 0x5018,		//!< ����IO����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_IO_PARAM				= 0x5019,		//!< ��ȡIO����
	ICE_CAMERA_CONFIG_TYPE_GET_IO_PARAM_RSP			= 0x5020,		//!< ����IO����Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_COM_PARAM			= 0x5021,		//!< ���ô��ڲ�����232/485 ������ ��
	ICE_CAMERA_CONFIG_TYPE_SET_COM_PARAM_RSP		= 0x5022,		//!< ���ô��ڲ���Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_COM_PARAM			= 0x5023,		//!< ��ȡ���ڲ���
	ICE_CAMERA_CONFIG_TYPE_GET_COM_PARAM_RSP		= 0x5024,		//!< ���ô��ڲ���Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_UPDATE_PROGRAM			= 0x5025,		//!< ��������
	ICE_CAMERA_CONFIG_TYPE_UPDATE_PROGRAM_RSP		= 0x5026,		//!< ��������Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_DEFAULT_PROGRAM			= 0x5027,		//!< �ָ�����Ĭ�ϳ���
	ICE_CAMERA_CONFIG_TYPE_DEFAULT_PROGRAM_RSP		= 0x5028,		//!< �ָ�����Ĭ��Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_DEFAULT_PARAM			= 0x5029,		//!< �ָ�Ĭ�ϲ���
	ICE_CAMERA_CONFIG_TYPE_DEFAULT_PARAM_RSP		= 0x5030,		//!< �ָ�Ĭ�ϲ���Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_DEFAULT_PARAM_EXP_IP		= 0x5031,		//!< �ָ���IP���Ĭ�ϲ���
	ICE_CAMERA_CONFIG_TYPE_DEFAULT_PARAM_EXP_IP_RSP	= 0x5032,		//!< �ָ���IP���Ĭ�ϲ���Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_FTP_PARAM			= 0x5033,		//!< ����FTP������FTP��ַ���û��������룩
	ICE_CAMERA_CONFIG_TYPE_SET_FTP_PARAM_RSP		= 0x5034,		//!< ����FTP����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_FTP_PARAM			= 0x5035,		//!< ��ȡFTP����
	ICE_CAMERA_CONFIG_TYPE_GET_FTP_PARAM_RSP		= 0x5036,		//!< ��ȡFTP����Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_SNAP_PARAM			= 0x5037,		//!< ����ץ�Ļ��������Ƿ�����ץ�Ļ���ץ�Ļ���ַ��ץ����ʱ��
	ICE_CAMERA_CONFIG_TYPE_SET_SNAP_PARAM_RSP		= 0x5038,		//!< ����ץ�Ļ�����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_SNAP_PARAM			= 0x5039,		//!< ��ȡץ�Ļ�����
	ICE_CAMERA_CONFIG_TYPE_GET_SNAP_PARAM_RSP		= 0x5040,		//!< ��ȡץ�Ļ�����Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_HCNT_PARAM			= 0x5041,		//!< ��������ͳ�Ʋ�����rs485Э�����͡��������ͣ�
	ICE_CAMERA_CONFIG_TYPE_SET_HCNT_PARAM_RSP		= 0x5042,		//!< ��������ͳ�Ʋ���Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_HCNT_PARAM			= 0x5043,		//!< ��ȡ����ͳ�Ʋ���
	ICE_CAMERA_CONFIG_TYPE_GET_HCNT_PARAM_RSP		= 0x5044,		//!< ��ȡ����ͳ�Ʋ���Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_ALARM_IN_CFG			= 0x5045,		//!< ���ø澯�������ã������򳣱գ�
	ICE_CAMERA_CONFIG_TYPE_SET_ALARM_IN_CFG_RSP		= 0x5046,		//!< ���ø澯��������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_ALARM_IN_CFG			= 0x5047,		//!< ��ȡ�澯��������
	ICE_CAMERA_CONFIG_TYPE_GET_ALARM_IN_CFG_RSP		= 0x5048,		//!< ��ȡ�澯��������Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_TMSYNC_CFG				= 0x5049,		//!< ����ʱ��ͬ������
	ICE_CAMERA_CONFIG_TYPE_SET_TMSYNC_CFG_RSP			= 0x5050,		//!< ����ʱ��ͬ������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_TMSYNC_CFG				= 0x5051,		//!< ��ȡʱ��ͬ������
	ICE_CAMERA_CONFIG_TYPE_GET_TMSYNC_CFG_RSP			= 0x5052,		//!< ��ȡʱ��ͬ������Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_OSD_CFG				= 0x5053,		//!< ����OSD����
	ICE_CAMERA_CONFIG_TYPE_SET_OSD_CFG_RSP			= 0x5054,		//!< ����OSD����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_OSD_CFG				= 0x5055,		//!< ��ȡOSD����
	ICE_CAMERA_CONFIG_TYPE_GET_OSD_CFG_RSP			= 0x5056,		//!< ��ȡOSD����Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_SCHED_TASK_CFG		= 0x5061,		//!< ���üƻ���������
	ICE_CAMERA_CONFIG_TYPE_SET_SCHED_TASK_CFG_RSP	= 0x5062,		//!< ���üƻ���������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_SCHED_TASK_CFG		= 0x5063,		//!< ��ȡ�ƻ���������
	ICE_CAMERA_CONFIG_TYPE_GET_SCHED_TASK_CFG_RSP	= 0x5064,		//!< ��ȡ�ƻ���������Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_RELAY_OUT		= 0x5065,		//!< ���ÿ��������
	ICE_CAMERA_CONFIG_TYPE_SET_RELAY_OUT_RSP	= 0x5066,		//!< ���ÿ��������Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_PHYCHN_CFG				= 0x5067,		//!< ��������ͨ������
	ICE_CAMERA_CONFIG_TYPE_SET_PHYCHN_CFG_RSP			= 0x5068,		//!< ��������ͨ������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_PHYCHN_CFG				= 0x5069,		//!< ��ȡ����ͨ������
	ICE_CAMERA_CONFIG_TYPE_GET_PHYCHN_CFG_RSP			= 0x5070,		//!< ��ȡ����ͨ������Ӧ��

	
	ICE_CAMERA_CONFIG_TYPE_CHECK_VFD_COMM			= 0x5071,		//!< ��֤�����������ͨѶ
	ICE_CAMERA_CONFIG_TYPE_CHECK_VFD_COMM_RSP		= 0x5072,		//!< ��֤�����������ͨѶӦ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_VFD_PARAM		= 0x5073,		//!< ���û����������
	ICE_CAMERA_CONFIG_TYPE_SET_VFD_PARAM_RSP	= 0x5074,		//!< ���û����������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_VFD_PARAM		= 0x5075,		//!< ��ȡ�����������
	ICE_CAMERA_CONFIG_TYPE_GET_VFD_PARAM_RSP	= 0x5076,		//!< ��ȡ�����������Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_UART_PARAM		= 0x5077,		//!< ����������ڲ���
	ICE_CAMERA_CONFIG_TYPE_SET_UART_PARAM_RSP	= 0x5078,		//!< ����������ڲ���Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_UART_PARAM		= 0x5079,		//!< ��ȡ������ڲ���
	ICE_CAMERA_CONFIG_TYPE_GET_UART_PARAM_RSP	= 0x5080,		//!< ��ȡ������ڲ���Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_HTTP_POST_PARAM		= 0x5081,		//!< ����HTTP POST����
	ICE_CAMERA_CONFIG_TYPE_SET_HTTP_POST_PARAM_RSP	= 0x5082,		//!< ����HTTP POST����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_HTTP_POST_PARAM		= 0x5083,		//!< ��ȡHTTP POST����
	ICE_CAMERA_CONFIG_TYPE_GET_HTTP_POST_PARAM_RSP	= 0x5084,		//!< ��ȡHTTP POST����Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_EXP_AREGULATE_PARAM		= 0x5085,		//!< �����ع��Զ����ڲ���
	ICE_CAMERA_CONFIG_TYPE_SET_EXP_AREGULATE_PARAM_RSP	= 0x5086,		//!< �����ع��Զ����ڲ���Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_EXP_AREGULATE_PARAM		= 0x5087,		//!< ��ȡ�ع��Զ����ڲ���
	ICE_CAMERA_CONFIG_TYPE_GET_EXP_AREGULATE_PARAM_RSP	= 0x5088,		//!< ��ȡ�ع��Զ����ڲ���Ӧ��


	ICE_CAMERA_CONFIG_TYPE_SET_SDCARD_PARAM		= 0x5089,		//!< ����VDC SD���洢����
	ICE_CAMERA_CONFIG_TYPE_SET_SDCARD_PARAM_RSP	= 0x5090,		//!< ����VDC SD���洢����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_SDCARD_PARAM		= 0x5091,		//!< ��ȡVDC SD���洢����
	ICE_CAMERA_CONFIG_TYPE_GET_SDCARD_PARAM_RSP	= 0x5092,		//!< ��ȡVDC SD���洢����Ӧ��

	ICE_CAMERA_CONFIG_TYPE_GET_DEV_ID		= 0x5093,		//!< ��ȡ�豸ΨһID
	ICE_CAMERA_CONFIG_TYPE_GET_DEV_ID_RSP	= 0x5094,		//!< ��ȡ�豸ΨһIDӦ��

	ICE_CAMERA_CONFIG_TYPE_SET_WHITELIST_PARAM		= 0x5095,		//!< ���ð���������
	ICE_CAMERA_CONFIG_TYPE_SET_WHITELIST_PARAM_RSP	= 0x5096,		//!< ���ð���������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_WHITELIST_PARAM		= 0x5097,		//!< ��ȡ����������
	ICE_CAMERA_CONFIG_TYPE_GET_WHITELIST_PARAM_RSP	= 0x5098,		//!< ��ȡ����������Ӧ��

	ICE_CAMERA_CONFIG_TYPE_WRITE_USER_DATA		= 0x5099,		//!< д���û�����
	ICE_CAMERA_CONFIG_TYPE_WRITE_USER_DATA_RSP	= 0x5100,		//!< д���û�����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_READ_USER_DATA		= 0x5101,		//!< �����û�����
	ICE_CAMERA_CONFIG_TYPE_READ_USER_DATA_RSP	= 0x5102,		//!< �����û�����Ӧ��

	ICE_CAMERA_CONFIG_TYPE_WRITE_WHITE_LIST		= 0x5103,		//!< д�������
	ICE_CAMERA_CONFIG_TYPE_WRITE_WHITE_LIST_RSP	= 0x5104,		//!< д�������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_READ_WHITE_LIST		= 0x5105,		//!< ����������
	ICE_CAMERA_CONFIG_TYPE_READ_WHITE_LIST_RSP	= 0x5106,		//!< ����������Ӧ��
	

	ICE_CAMERA_CONFIG_TYPE_SET_HDTRIGGER_PARAM		= 0x5107,		//!< ����Ӳ��������
	ICE_CAMERA_CONFIG_TYPE_SET_HDTRIGGER_PARAM_RSP	= 0x5108,		//!< ����Ӳ��������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_HDTRIGGER_PARAM		= 0x5109,		//!< ��ȡӲ��������
	ICE_CAMERA_CONFIG_TYPE_GET_HDTRIGGER_PARAM_RSP	= 0x5110,		//!< ��ȡӲ��������Ӧ��

	ICE_CAMERA_CONFIG_TYPE_ADD_WHITE_LIST		= 0x5111,		//!< ���Ӱ�����
	ICE_CAMERA_CONFIG_TYPE_ADD_WHITE_LIST_RSP	= 0x5112,		//!< ���Ӱ�����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_DEL_WHITE_LIST		= 0x5113,		//!< ɾ��������
	ICE_CAMERA_CONFIG_TYPE_DEL_WHITE_LIST_RSP	= 0x5114,		//!< ɾ��������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_EDIT_WHITE_LIST		= 0x5115,		//!< �༭������
	ICE_CAMERA_CONFIG_TYPE_EDIT_WHITE_LIST_RSP	= 0x5116,		//!< �༭������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_FIND_WHITE_LIST		= 0x5117,		//!< ���Ұ�����
	ICE_CAMERA_CONFIG_TYPE_FIND_WHITE_LIST_RSP	= 0x5118,		//!< ���Ұ�����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_DELALL_WHITE_LIST		= 0x5119,		//!< ɾ�����а�����
	ICE_CAMERA_CONFIG_TYPE_DELALL_WHITE_LIST_RSP	= 0x5120,		//!< ɾ�����а�����Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_AUTO_REBOOT_PARAM		= 0x5121,		//!< �����Զ���������
	ICE_CAMERA_CONFIG_TYPE_SET_AUTO_REBOOT_PARAM_RSP	= 0x5122,		//!< �����Զ���������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_AUTO_REBOOT_PARAM		= 0x5123,		//!< ��ȡ�Զ���������
	ICE_CAMERA_CONFIG_TYPE_GET_AUTO_REBOOT_PARAM_RSP	= 0x5124,		//!< ��ȡ�Զ���������Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_PASSWD_PARAM		= 0x5125,		//!< �����������
	ICE_CAMERA_CONFIG_TYPE_SET_PASSWD_PARAM_RSP	= 0x5126,		//!< �����������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_RM_LOG_FILE		= 0x5127,		//!< ɾ����־�ļ�
	ICE_CAMERA_CONFIG_TYPE_RM_LOG_FILE_RSP	= 0x5128,		//!<  ɾ����־�ļ�Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_DNS_PARAM			= 0x5129,		//!< �������DNS����
	ICE_CAMERA_CONFIG_TYPE_SET_DNS_PARAM_RSP		= 0x5130,		//!< �������DNS����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_DNS_PARAM			= 0x5131,		//!< ��ȡ���DNS����
	ICE_CAMERA_CONFIG_TYPE_GET_DNS_PARAM_RSP		= 0x5132,		//!< ��ȡ���DNS����Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_LIGHT_PARAM			= 0x5133,		//!< ���ò���Ʋ���
	ICE_CAMERA_CONFIG_TYPE_SET_LIGHT_PARAM_RSP		= 0x5134,		//!< ���ò���Ʋ���Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_LIGHT_PARAM			= 0x5135,		//!< ��ȡ����Ʋ���
	ICE_CAMERA_CONFIG_TYPE_GET_LIGHT_PARAM_RSP		= 0x5136,		//!< ��ȡ����Ʋ���Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_RELAY_OUT2		= 0x5137,		//!< ���ÿ�����2���
	ICE_CAMERA_CONFIG_TYPE_SET_RELAY_OUT2_RSP	= 0x5138,		//!< ���ÿ�����2���Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_REOPEN_PARAM		= 0x5139,		//!< ���ö��ο�բ����
	ICE_CAMERA_CONFIG_TYPE_SET_REOPEN_PARAM_RSP	= 0x5140,		//!< ���ö��ο�բ����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_REOPEN_PARAM		= 0x5141,		//!< ��ȡ���ο�բ����
	ICE_CAMERA_CONFIG_TYPE_GET_REOPEN_PARAM_RSP	= 0x5142,		//!< ��ȡ���ο�բ����Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_OFFLINE_AO_PLAY_PARAM = 0x5143, //!<�����ѻ�������������
	ICE_CAMERA_CONFIG_TYPE_SET_OFFLINE_AO_PLAY_PARAM_RSP = 0x5144,//!>�����ѻ�������������Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_OFFLINE_AO_PLAY_PARAM = 0x5145, //!> ��ȡ�ѻ�������������
	ICE_CAMERA_CONFIG_TYPE_GET_OFFLINE_AO_PLAY_PARAM_RSP = 0x5146,//!>��ȡ�ѻ�������������Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_LED_PARAM		= 0x5147,		//!< ����LED����
	ICE_CAMERA_CONFIG_TYPE_SET_LED_PARAM_RSP	= 0x5148,		//!< ����LED����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_LED_PARAM		= 0x5149,		//!< ��ȡLED����
	ICE_CAMERA_CONFIG_TYPE_GET_LED_PARAM_RSP	= 0x514A,		//!< ��ȡLED����Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_CGI_PARAM		= 0x514B,		//!< ����CGI����
	ICE_CAMERA_CONFIG_TYPE_SET_CGI_PARAM_RSP	= 0x514C,		//!< ����CGI����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_CGI_PARAM		= 0x514D,		//!< ��ȡCGI����
	ICE_CAMERA_CONFIG_TYPE_GET_CGI_PARAM_RSP	= 0x514E,		//!< ��ȡCGI����Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_LED_PROTOCOL1    = 0x5150,       //����ledЭ��1����(���)
	ICE_CAMERA_CONFIG_TYPE_SET_LED_PROTOCOL1_RSP    = 0x5151,   // ����ledЭ��1����Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_LED_PROTOCOL1    = 0x5152,       //��ȡledЭ��1����
	ICE_CAMERA_CONFIG_TYPE_GET_LED_PROTOCOL1_RSP    = 0x5153,   // ��ȡledЭ��1����Ӧ��
	
	ICE_CAMERA_CONFIG_TYPE_SET_CAMERA_OFFLINE_PARAM  = 0x5154,       //!<�������ǿ���ѻ������Ĳ���
	ICE_CAMERA_CONFIG_TYPE_SET_CAMERA_OFFLINE_PARAM_RSP  = 0x5155,   //!<�������ǿ���ѻ������Ĳ���Ӧ��	
	ICE_CAMERA_CONFIG_TYPE_GET_CAMERA_OFFLINE_PARAM  = 0x5156,       //!<��ȡ���ǿ���ѻ������Ĳ���
	ICE_CAMERA_CONFIG_TYPE_GET_CAMERA_OFFLINE_PARAM_RSP  = 0x5157,   //!<��ȡ���ǿ���ѻ������Ĳ���Ӧ��

	ICE_CAMERA_CONFIG_TYPE_SET_STROBE_LIGHT_PARAM  = 0x5158,       //!<���ð��Ʊ����Ʋ���
	ICE_CAMERA_CONFIG_TYPE_SET_STROBE_LIGHT_PARAM_RSP  = 0x5159,   //!<���ð��Ʊ����Ʋ���Ӧ��
	ICE_CAMERA_CONFIG_TYPE_GET_STROBE_LIGHT_PARAM  = 0x5160,       //!<��ȡ���Ʊ����Ʋ���
	ICE_CAMERA_CONFIG_TYPE_GET_STROBE_LIGHT_PARAM_RSP  = 0x5161,   //!<��ȡ���Ʊ����Ʋ���Ӧ��


	ICE_CAMERA_CONFIG_TYPE_END                      = 0x5162        

} ICE_CAMERA_CONFIG_TYPE_E;

//!�����ѻ������������� 
typedef struct
{
	ICE_U32 u32Mode;             //����ģʽ�� 0 ������, 1 ����(ԭ���Ļ�ӭ����/һ·˳��), 2 ����+ƥ�������   Ĭ�� 2
	ICE_U32 u32Broadcast_order;     //����˳��   0 ����������  1�󲥱�����  2 �Ȳ��������ٲ���������Ϣ  Ĭ�� 2
	ICE_U32 u32Reserved[15];           
} OfflineAoParam;

//���մ洢���ն�mac list ����
typedef struct {
  ICE_S32 mac_list_size;  //  list����
  ICE_S8 phone_mac_list[100 ][18];
  ICE_S8 reserved[50*18];
} ICE_Phone_Mac_List;


//! �������ݻ���
typedef union
{
	ICE_U8 au8Buffer[ICE_BUF_SIZE_CONFIG];		//!< �������ݻ���
} ICE_CONFIG_DATA_INTERNAL_U;

//! \ingroup group_communication
//! ��������ͷ�����ݻ���
typedef struct  
{
	ICE_OPER_DATA_S stHead;					//!< ����ͷ
	ICE_CONFIG_DATA_INTERNAL_U unData;		//!< ��������
} ICE_CONFIG_DATA_S;

///////////////////////////////////////////////////////////////////////////////////////////////////
//! \ingroup group_communication
//! ������Ƶ����������
typedef enum
{
	ICE_VIDEO_STREAM_TYPE_BASE 						= 0x6000,		//!< ������Ƶ���������ͻ����ֶ�
	ICE_VIDEO_STREAM_TYPE_VENC_H264					= 0x6001,		//!< H264����
	ICE_VIDEO_STREAM_TYPE_VENC_MJPEG				= 0x6002,		//!< MJPEG����
	ICE_VIDEO_STREAM_TYPE_VENC_MPEG2				= 0x6004,		//!< MPEG2����
	ICE_VIDEO_STREAM_TYPE_VENC_MPEG4				= 0x6008,		//!< MPEG4����
	ICE_VIDEO_STREAM_TYPE_END						= 0x6009,		
}ICE_VIDEO_STREAM_E;

//���led��ʾ�û��Զ�����Ϣ �ṹ��
typedef struct{
	char default_data[64];  //�޳���ʱ
	char blacklist_data[64]; //������
	char tmp_data[64];      // ��ʱ����
	char reserve[256];
} Led_Display_Pro1_Param;


#ifdef __cplusplus
}
#endif


#endif // __ICE_COM_H__


