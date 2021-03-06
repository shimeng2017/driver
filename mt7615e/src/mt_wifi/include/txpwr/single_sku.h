/*
 ***************************************************************************
 * MediaTek Inc.
 *
 * All rights reserved. source code is an unpublished work and the
 * use of a copyright notice does not imply otherwise. This source code
 * contains confidential trade secret material of MediaTek. Any attemp
 * or participation in deciphering, decoding, reverse engineering or in any
 * way altering the source code is stricitly prohibited, unless the prior
 * written consent of MediaTek, Inc. is obtained.
 ***************************************************************************

	Module Name:
	single_sku.h
*/

#ifndef __CMM_SINGLE_SKU_H__
#define __CMM_SINGLE_SKU_H__


// TODO: shiang-usw, integrate these data structures to a single one!
#define	SINGLE_SKU_TABLE_LENGTH		(SINGLE_SKU_TABLE_CCK_LENGTH+SINGLE_SKU_TABLE_OFDM_LENGTH+(SINGLE_SKU_TABLE_HT_LENGTH*2)+SINGLE_SKU_TABLE_VHT_LENGTH)

#define SINGLE_SKU_TABLE_EFFUSE_ADDRESS 0x12C

#define SINGLE_SKU_TABLE_CCK_LENGTH	    2
#define SINGLE_SKU_TABLE_OFDM_LENGTH	5
#define SINGLE_SKU_TABLE_HT_LENGTH	   16
#define SINGLE_SKU_TABLE_VHT_LENGTH	    7 /* VHT80 MCS 0 ~ 9 */
#define BF_GAIN_TABLE_LENGTH            4

#define SINGLE_SKU_TABLE_TX_OFFSET_NUM  3 


#define SKUTABLE_1                      1
#define SKUTABLE_2                      2
#define SKUTABLE_3                      3
#define SKUTABLE_4                      4
#define SKUTABLE_5                      5
#define SKUTABLE_6                      6
#define SKUTABLE_7                      7
#define SKUTABLE_8                      8
#define SKUTABLE_9                      9
#define SKUTABLE_10                    10
#define SKUTABLE_11                    11
#define SKUTABLE_12                    12
#define SKUTABLE_13                    13
#define SKUTABLE_14                    14
#define SKUTABLE_15                    15
#define SKUTABLE_16                    16
#define SKUTABLE_17                    17
#define SKUTABLE_18                    18
#define SKUTABLE_19                    19
#define SKUTABLE_20                    20

#define VHT20_OFFSET                    0
#define VHT40_OFFSET                    7
#define VHT80_OFFSET                   14
#define VHT160C_OFFSET                 21

#define SKU_VHT_RATE_M0                 0
#define SKU_VHT_RATE_M12                1
#define SKU_VHT_RATE_M34                2
#define SKU_VHT_RATE_M56                3
#define SKU_VHT_RATE_M7                 4
#define SKU_VHT_RATE_M8                 5
#define SKU_VHT_RATE_M9                 6

// TODO: shiang-usw, need to re-organize these for MT7610/MT7601/MT7620!!
typedef struct _CH_POWER_{
	DL_LIST		List;
	UCHAR		StartChannel;
	UCHAR		num;
	UCHAR		*Channel;
    UCHAR       band;
	UCHAR		PwrCCK[SINGLE_SKU_TABLE_CCK_LENGTH];
	UCHAR		PwrOFDM[SINGLE_SKU_TABLE_OFDM_LENGTH];
	UCHAR		PwrHT20[SINGLE_SKU_TABLE_HT_LENGTH];
	UCHAR		PwrHT40[SINGLE_SKU_TABLE_HT_LENGTH];
	UCHAR		PwrVHT20[SINGLE_SKU_TABLE_VHT_LENGTH];
	UCHAR		PwrVHT40[SINGLE_SKU_TABLE_VHT_LENGTH];
	UCHAR		PwrVHT80[SINGLE_SKU_TABLE_VHT_LENGTH];
	UCHAR		PwrVHT160[SINGLE_SKU_TABLE_VHT_LENGTH];
	UCHAR		PwrTxStreamDelta[SINGLE_SKU_TABLE_TX_OFFSET_NUM];
}CH_POWER;

typedef struct _BFback_POWER_{
	DL_LIST		List;
	UCHAR		StartChannel;
	UCHAR		num;
	UCHAR		*Channel;
    UCHAR       band;
	UCHAR		PwrMax[3];
}BFback_POWER;

typedef struct _BF_POWER_{
	DL_LIST		List;
	UCHAR		StartNsstream;
	UCHAR		num;
	UCHAR		*Nsstream;
	UCHAR		BFGain[BF_GAIN_TABLE_LENGTH];
}BF_POWER;


INT	MtSingleSkuLoadParam(struct _RTMP_ADAPTER *pAd);
VOID MtSingleSkuUnloadParam(struct _RTMP_ADAPTER *pAd);
INT	MtBfBackOffLoadParam(struct _RTMP_ADAPTER *pAd);
INT8 SKUTxPwrOffsetGet(struct _RTMP_ADAPTER *pAd, UINT8 ucBW, UINT8 ucMCS, UINT8 ucBandIdx);

#endif /*__CMM_SINGLE_SKU_H__*/


