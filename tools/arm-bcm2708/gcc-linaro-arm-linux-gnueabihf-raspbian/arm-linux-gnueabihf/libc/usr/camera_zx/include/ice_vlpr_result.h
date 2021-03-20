/*! \file ice_vlpr_result.h
\brief ice_vlpr_result.h document.
*/
#ifndef __ICE_VLPR_RESULT_H__
#define __ICE_VLPR_RESULT_H__

#include "ice_base_type.h"

#ifdef __cplusplus
extern "C"
{
#endif



//-------------------------------------------
// �ַ����Ͷ���              		 
//-------------------------------------------

//! �ַ����Ͷ���
typedef enum 
{
	ICE_CHARTYPE_CHARACTER			= 0,	//!< ���ּ���ĸ
	ICE_CHARTYPE_ONLYDIGITAL		= 1,	//!< ����
	ICE_CHARTYPE_ONLYALPHABET		= 2,	//!< ��ĸ 

	ICE_HANZI_CHINA					= 3,	//!< ȫ��
	ICE_HANZI_BEIJING				= 4,	//!< ����
	ICE_HANZI_SHANGHAI				= 5,	//!< �Ϻ�
	ICE_HANZI_TIANJIN				= 6,	//!< ���
	ICE_HANZI_CHONGQING				= 7,	//!< ����
	ICE_HANZI_HEILONGJIANG			= 8,	//!< ������
	ICE_HANZI_JILIN					= 9,	//!< ����
	ICE_HANZI_LIAONING				= 10,	//!< ����
	ICE_HANZI_NEIMENG				= 11,	//!< ���ɹ�
	ICE_HANZI_HEBEI					= 12,	//!< �ӱ�
	ICE_HANZI_SHANDONG				= 13,	//!< ɽ��
	ICE_HANZI_SHANXI				= 14,	//!< ɽ��
	ICE_HANZI_ANHUI					= 15,	//!< ����
	ICE_HANZI_JIANGSU				= 16,	//!< ����
	ICE_HANZI_ZHEJIANG				= 17,	//!< �㽭
	ICE_HANZI_FUJIAN				= 18,	//!< ����
	ICE_HANZI_GUANGDONG				= 19,	//!< �㶫
	ICE_HANZI_HENAN					= 20,	//!< ����
	ICE_HANZI_JIANGXI				= 21,	//!< ����
	ICE_HANZI_HUNAN					= 22,	//!< ����
	ICE_HANZI_HUBEI					= 23,	//!< ����
	ICE_HANZI_GUANGXI				= 24,	//!< ����
	ICE_HANZI_HAINAN				= 25,	//!< ����
	ICE_HANZI_YUNNAN				= 26,	//!< ����
	ICE_HANZI_GUIZHOU				= 27,	//!< ����
	ICE_HANZI_SICHUAN				= 28,	//!< �Ĵ�
	ICE_HANZI_XIAN					= 29,	//!< ����
	ICE_HANZI_GANSU					= 30,	//!< ����
	ICE_HANZI_NINGXIA				= 31,	//!< ����
	ICE_HANZI_QINGHAI				= 32,	//!< �ຣ
	ICE_HANZI_XIZANG				= 33,	//!< ����
	ICE_HANZI_XINJIANG				= 34	//!< �½�
}ICE_VLPR_CHARTYPE_E;	

//-------------------------------------------------------
// �������Ͷ���      									 
//-------------------------------------------------------

//! �������Ͷ���
typedef enum 
{
	ICE_PLATE_UNCERTAIN			= 0,			//!< ��ȷ����
	ICE_PLATE_BLUE				= 1,			//!< ���Ƴ�
	ICE_PLATE_YELLOW			= 2,			//!< ������Ƴ�
	ICE_PLATE_POLICE			= 4,			//!< ����
	ICE_PLATE_WUJING			= 8,			//!< �侯����
	ICE_PLATE_DBYELLOW			= 16,			//!< ˫�����
	ICE_PLATE_MOTOR				= 32,			//!< Ħ�г�
	ICE_PLATE_INSTRUCTIONCAR	= 64,			//!< ������
	ICE_PLATE_MILITARY			= 128,			//!< ����
	ICE_PLATE_PERSONAL			= 256,			//!< ���Ի���
	ICE_PLATE_GANGAO			= 512,			//!< �۰ĳ�
	ICE_PLATE_EMBASSY			= 1024,			//!< ʹ�ݳ�
	ICE_PLATE_NONGLARE			= 2048,			//!< ��ʽ����(������)
	ICE_PLATE_AVIATION			= 4096,			//!< �񺽳���
	ICE_PLATE_NEWENERGY			= 8192,			//!< ����Դ����

	ICE_PLATE_WHITE_TWOTWO		= 0x10000001,	//!< 2+2ģ�ͣ�
	ICE_PLATE_WHITE_TWOTHR		= 0x10000002,	//!< 2+3ģ�ͣ�
	ICE_PLATE_WHITE_THRTWO		= 0x10000004,	//!< 3+2ģ�ͣ�
	ICE_PLATE_WHITE_THRTHR		= 0x10000008,	//!< 3+3ģ�ͣ�
	ICE_PLATE_WHITE_THRFOR		= 0x10000010,	//!< 3+4ģ�ͣ�

	ICE_PLATE_BLACK_THRTWO		= 0x10000020,	//!< 3+2ģ�ͣ�
	ICE_PLATE_BLACK_TWOTHR		= 0x10000040,	//!< 2+3ģ�ͣ�
	ICE_PLATE_BLACK_THRTHR		= 0x10000080,	//!< 3+3ģ�ͣ�
	ICE_PLATE_BLACK_TWOFOR		= 0x10000100,	//!< 2+4ģ�ͣ�
	ICE_PLATE_BLACK_FORTWO		= 0x10000200,	//!< 4+2ģ�ͣ�
	ICE_PLATE_BLACK_THRFOR		= 0x10000400,	//!< 3+4ģ�ͣ�
}ICE_PLATETYPE_E;

//-------------------------------------------------------
// ������ɫ����
//-------------------------------------------------------

// ������ɫ
typedef enum
{
	ICE_PLATE_COLOR_UNKNOWN		= 0,	//!<  δ֪
	ICE_PLATE_COLOR_BLUE		= 1,	//!<  ���װ���
	ICE_PLATE_COLOR_YELLOW		= 2,	//!<  �Ƶ׺���
	ICE_PLATE_COLOR_WHITE		= 3,	//!<  �׵׺���
	ICE_PLATE_COLOR_BLACK		= 4,	//!<  �ڵװ���
	ICE_PLATE_COLOR_GREEN		= 5		//!<  �̵װ���
}ICE_PLATECOLOR_E;

typedef enum
{
	ICE_VEHICLE_COLOR_UNKOWN= 0,		//!<  δ֪
	ICE_VEHICLE_COLOR_RED = 1,			//!<  ��ɫ
	ICE_VEHICLE_COLOR_GREEN = 2,		//!<  ��ɫ
	ICE_VEHICLE_COLOR_BLUE = 3,			//!<  ��ɫ
	ICE_VEHICLE_COLOR_YELLOW = 4,		//!<  ��ɫ
	ICE_VEHICLE_COLOR_WHITE = 5,		//!<  ��ɫ
	ICE_VEHICLE_COLOR_GRAY = 6,			//!<  ��ɫ
	ICE_VEHICLE_COLOR_BLACK = 7,		//!<  ��ɫ
	ICE_VEHICLE_COLOR_PURPLE=8,			//!<  ��ɫ
	ICE_VEHICLE_COLOR_BROWN=9,			//!<  ��ɫ
	ICE_VEHICLE_COLOR_PINK=10			//!<  ��ɫ
}ICE_VEHICLECOLOR_E;

//----------------------------------------------
// ����ʶ������ṹ����
//----------------------------------------------

#define ICE_VLPR_PLATE_CHAR_NUM		7								//!<  �����ַ���    
#define ICE_VLPR_PLATE_BUFLEN		16                              //!<  ���ƺ����ֵ  

//! \ingroup group_vlpr
//! ����ʶ������ṹ
typedef struct 
{
	ICE_S8				as8PlateNum[ICE_VLPR_PLATE_BUFLEN];			//!<  ���ƺ�
	ICE_RECT_S			stPlateRect;								//!<  ���ƾ��ο�
	ICE_RECT_S			astPlateCharRect[ICE_VLPR_PLATE_CHAR_NUM];	//!<  �����ַ����ο�
	ICE_FLOAT			aflPlateCharConfid[ICE_VLPR_PLATE_CHAR_NUM];//!<  �����ַ����Ŷ�
	ICE_FLOAT			flConfidence;								//!<  �������Ŷ�
	ICE_S32				s32PlateIntensity;							//!<  ��������
	ICE_PLATECOLOR_E	ePlateColor;								//!<  ������ɫ
	ICE_PLATETYPE_E		ePlateType;									//!<  ��������
	ICE_VEHICLECOLOR_E	eVehicleColor;								//!<  ������ɫ

	ICE_FLOAT			flPlateAngleH;								//!<  ����ˮƽ��б�Ƕ�
	ICE_FLOAT			flPlateAngleV;								//!<  ������ֱ��б�Ƕ�
	ICE_S8				astReserve[24];								//!<  Ԥ������
}ICE_VLPR_OUTPUT_S;


//----------------------------------------------
// ����ʶ����������
//----------------------------------------------

#define ICE_VLPR_MAX_OUTPUT_NUM		16							//!< �������  

//! \ingroup group_vlpr
//! ����ʶ���㷨������
typedef struct 
{
	ICE_S32				s32NumOutput;							//!< ����������   
	ICE_VLPR_OUTPUT_S	astOutput[ICE_VLPR_MAX_OUTPUT_NUM];		//!< ���������
}ICE_VLPR_RULT_S;


#ifdef __cplusplus
}
#endif


#endif
