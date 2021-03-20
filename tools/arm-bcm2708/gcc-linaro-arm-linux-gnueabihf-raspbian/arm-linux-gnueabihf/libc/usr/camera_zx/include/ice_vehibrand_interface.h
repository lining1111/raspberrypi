#ifndef ice_vehibrand_interface_h__
#define ice_vehibrand_interface_h__

/********************************************************************
Copyright (C), 1994-2016, �Ƽ����޹�˾

�ļ�����: 	ice_vehibrand_interface.h
�ļ�����:	����ʶ��ͷ�ļ�
�ļ����ߣ�	
�޸���ʷ��	2016-4-26 15:10:38	 creat V1.0.001 
*********************************************************************/

#include "ice_base_type.h"

#define VBR_RES_TOPN 10               //���ؽ������

typedef struct
{
	ICE_S8 szLogName[20];             //��Ʒ��
	ICE_S8 szSubLogName[20];          //�ݲ�ʹ��
	ICE_S8 szProductYearName[20];     //�ݲ�ʹ��

	ICE_S8 szLabelTotal[40];           //�ݲ�ʹ��
	ICE_U32 iLabelIndex;               //�ݲ�ʹ��
	ICE_FLOAT fScore;                  //�ݲ�ʹ��

	//first VBR_RES_TOPN:label
	//last VBR_RES_TOPN:score
	ICE_FLOAT fResFeature[VBR_RES_TOPN*2];  //������
 
// 	ICE_S8 szLabelTotalTopN[VBR_RES_TOPN][40]; //����top n�����,����ʶ����ʱ���Ե���

// 	ICE_FLOAT fScoreTopN[VBR_TOP_N];
// 	ICE_U32 iIndexTopN[VBR_TOP_N];

	ICE_U32  iReserved[4];             //Ԥ��
}ICE_VBR_RESULT_S;

typedef struct      
{
	char * strModelPath;              //cnn model·��

	ICE_U32 iInputW;                   //����ͼ���С
	ICE_U32 iInuptH;                    
	ICE_U32  iReserved[4];             //Ԥ��
}ICE_VBR_INPUTPARAM_S;

typedef struct
{
	ICE_RECT_S stRect;
	ICE_U32 iType;//0-from plate.1-from vehicle detection
	ICE_U32  iReserved[4];
}ICE_VBR_RTEX_S;

//////////////////////////////////////////////////////////////////////////
//vehicle brand recognization  interface
ICE_EXPORTS ICE_HANDLE ICE_VehiBrandRegCreate();
ICE_EXPORTS ICE_STATUS_E ICE_VehiBrandRegInit(ICE_HANDLE _hHandle, ICE_VBR_INPUTPARAM_S *_pstInputRaram);

ICE_EXPORTS ICE_STATUS_E ICE_VehiBrandRegProcess(ICE_HANDLE hHandle,ICE_GRAY_IMAGE_S *pGrayImage, 
												 ICE_VBR_RTEX_S _stRectex, ICE_VBR_RESULT_S *pstRult);

ICE_EXPORTS ICE_STATUS_E ICE_VehiBrandRegRelease(ICE_HANDLE hHandle);

//! \brief ��ȡ�㷨�汾��
//! \param Object	�㷨����
//! \param Version  ����汾�ŵ�ַָ�롣Ҫ��ָ����ָ���鳤�ȴ���64 BYTE
//! \return			����״̬���ο�\ref ICE_STATUS_E
ICE_EXPORTS ICE_STATUS_E  ICE_VehiBrandReg_GetVersion(void   *_hHandle, char * Version);

//�㷨���Ӷ�Ϊ��VBR_RES_TOPN*VBR_RES_TOPN*COMPARE_CNT(�����Ƚϴ���).
ICE_EXPORTS ICE_FLOAT ICE_VehiBrandReg_CompareFeat(ICE_FLOAT *_pfResFeat1, ICE_U32 _iFeat1Len,
												  ICE_FLOAT *_pfReaFeat2, ICE_U32 _iFeat2Len);


#endif // ice_vehibrand_interface_h__
