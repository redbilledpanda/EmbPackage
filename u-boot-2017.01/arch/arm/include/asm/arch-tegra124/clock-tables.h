/*
 * (C) Copyright 2013
 * NVIDIA Corporation <www.nvidia.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

/* Tegra124 clock PLL tables */

#ifndef _TEGRA124_CLOCK_TABLES_H_
#define _TEGRA124_CLOCK_TABLES_H_

/* The PLLs supported by the hardware */
enum clock_id {
	CLOCK_ID_FIRST,
	CLOCK_ID_CGENERAL = CLOCK_ID_FIRST,
	CLOCK_ID_MEMORY,
	CLOCK_ID_PERIPH,
	CLOCK_ID_AUDIO,
	CLOCK_ID_USB,
	CLOCK_ID_DISPLAY,

	/* now the simple ones */
	CLOCK_ID_FIRST_SIMPLE,
	CLOCK_ID_XCPU = CLOCK_ID_FIRST_SIMPLE,
	CLOCK_ID_EPCI,
	CLOCK_ID_SFROM32KHZ,
	CLOCK_ID_DP,	/* Special for Tegra124 */

	/* These are the base clocks (inputs to the Tegra SoC) */
	CLOCK_ID_32KHZ,
	CLOCK_ID_OSC,
	CLOCK_ID_CLK_M,

	CLOCK_ID_COUNT,	/* number of PLLs */

	/*
	 * These are clock IDs that are used in table clock_source[][]
	 * but will not be assigned as a clock source for any peripheral.
	 */
	CLOCK_ID_DISPLAY2,
	CLOCK_ID_CGENERAL2,
	CLOCK_ID_CGENERAL3,
	CLOCK_ID_MEMORY2,
	CLOCK_ID_SRC2,

	CLOCK_ID_NONE = -1,
};

/* The clocks supported by the hardware */
enum periph_id {
	PERIPH_ID_FIRST,

	/* Low word: 31:0 (DEVICES_L) */
	PERIPH_ID_CPU = PERIPH_ID_FIRST,
	PERIPH_ID_COP,
	PERIPH_ID_TRIGSYS,
	PERIPH_ID_ISPB,
	PERIPH_ID_RESERVED4,
	PERIPH_ID_TMR,
	PERIPH_ID_UART1,
	PERIPH_ID_UART2,

	/* 8 */
	PERIPH_ID_GPIO,
	PERIPH_ID_SDMMC2,
	PERIPH_ID_SPDIF,
	PERIPH_ID_I2S1,
	PERIPH_ID_I2C1,
	PERIPH_ID_RESERVED13,
	PERIPH_ID_SDMMC1,
	PERIPH_ID_SDMMC4,

	/* 16 */
	PERIPH_ID_TCW,
	PERIPH_ID_PWM,
	PERIPH_ID_I2S2,
	PERIPH_ID_RESERVED19,
	PERIPH_ID_VI,
	PERIPH_ID_RESERVED21,
	PERIPH_ID_USBD,
	PERIPH_ID_ISP,

	/* 24 */
	PERIPH_ID_RESERVED24,
	PERIPH_ID_RESERVED25,
	PERIPH_ID_DISP2,
	PERIPH_ID_DISP1,
	PERIPH_ID_HOST1X,
	PERIPH_ID_VCP,
	PERIPH_ID_I2S0,
	PERIPH_ID_CACHE2,

	/* Middle word: 63:32 (DEVICES_H) */
	PERIPH_ID_MEM,
	PERIPH_ID_AHBDMA,
	PERIPH_ID_APBDMA,
	PERIPH_ID_RESERVED35,
	PERIPH_ID_RESERVED36,
	PERIPH_ID_STAT_MON,
	PERIPH_ID_RESERVED38,
	PERIPH_ID_FUSE,

	/* 40 */
	PERIPH_ID_KFUSE,
	PERIPH_ID_SBC1,
	PERIPH_ID_SNOR,
	PERIPH_ID_RESERVED43,
	PERIPH_ID_SBC2,
	PERIPH_ID_XIO,
	PERIPH_ID_SBC3,
	PERIPH_ID_I2C5,

	/* 48 */
	PERIPH_ID_DSI,
	PERIPH_ID_RESERVED49,
	PERIPH_ID_HSI,
	PERIPH_ID_HDMI,
	PERIPH_ID_CSI,
	PERIPH_ID_RESERVED53,
	PERIPH_ID_I2C2,
	PERIPH_ID_UART3,

	/* 56 */
	PERIPH_ID_MIPI_CAL,
	PERIPH_ID_EMC,
	PERIPH_ID_USB2,
	PERIPH_ID_USB3,
	PERIPH_ID_RESERVED60,
	PERIPH_ID_VDE,
	PERIPH_ID_BSEA,
	PERIPH_ID_BSEV,

	/* Upper word 95:64 (DEVICES_U) */
	PERIPH_ID_RESERVED64,
	PERIPH_ID_UART4,
	PERIPH_ID_UART5,
	PERIPH_ID_I2C3,
	PERIPH_ID_SBC4,
	PERIPH_ID_SDMMC3,
	PERIPH_ID_PCIE,
	PERIPH_ID_OWR,

	/* 72 */
	PERIPH_ID_AFI,
	PERIPH_ID_CORESIGHT,
	PERIPH_ID_PCIEXCLK,
	PERIPH_ID_AVPUCQ,
	PERIPH_ID_LA,
	PERIPH_ID_TRACECLKIN,
	PERIPH_ID_SOC_THERM,
	PERIPH_ID_DTV,

	/* 80 */
	PERIPH_ID_RESERVED80,
	PERIPH_ID_I2CSLOW,
	PERIPH_ID_DSIB,
	PERIPH_ID_TSEC,
	PERIPH_ID_RESERVED84,
	PERIPH_ID_RESERVED85,
	PERIPH_ID_RESERVED86,
	PERIPH_ID_EMUCIF,

	/* 88 */
	PERIPH_ID_RESERVED88,
	PERIPH_ID_XUSB_HOST,
	PERIPH_ID_RESERVED90,
	PERIPH_ID_MSENC,
	PERIPH_ID_RESERVED92,
	PERIPH_ID_RESERVED93,
	PERIPH_ID_RESERVED94,
	PERIPH_ID_XUSB_DEV,

	PERIPH_ID_VW_FIRST,
	/* V word: 31:0 */
	PERIPH_ID_CPUG = PERIPH_ID_VW_FIRST,
	PERIPH_ID_CPULP,
	PERIPH_ID_V_RESERVED2,
	PERIPH_ID_MSELECT,
	PERIPH_ID_V_RESERVED4,
	PERIPH_ID_I2S3,
	PERIPH_ID_I2S4,
	PERIPH_ID_I2C4,

	/* 104 */
	PERIPH_ID_SBC5,
	PERIPH_ID_SBC6,
	PERIPH_ID_AUDIO,
	PERIPH_ID_APBIF,
	PERIPH_ID_DAM0,
	PERIPH_ID_DAM1,
	PERIPH_ID_DAM2,
	PERIPH_ID_HDA2CODEC2X,

	/* 112 */
	PERIPH_ID_ATOMICS,
	PERIPH_ID_V_RESERVED17,
	PERIPH_ID_V_RESERVED18,
	PERIPH_ID_V_RESERVED19,
	PERIPH_ID_V_RESERVED20,
	PERIPH_ID_V_RESERVED21,
	PERIPH_ID_V_RESERVED22,
	PERIPH_ID_ACTMON,

	/* 120 */
	PERIPH_ID_EXTPERIPH1,
	PERIPH_ID_EXTPERIPH2,
	PERIPH_ID_EXTPERIPH3,
	PERIPH_ID_OOB,
	PERIPH_ID_SATA,
	PERIPH_ID_HDA,
	PERIPH_ID_V_RESERVED30,
	PERIPH_ID_V_RESERVED31,

	/* W word: 31:0 */
	PERIPH_ID_HDA2HDMICODEC,
	PERIPH_ID_SATACOLD,
	PERIPH_ID_W_RESERVED2,
	PERIPH_ID_W_RESERVED3,
	PERIPH_ID_W_RESERVED4,
	PERIPH_ID_W_RESERVED5,
	PERIPH_ID_W_RESERVED6,
	PERIPH_ID_W_RESERVED7,

	/* 136 */
	PERIPH_ID_CEC,
	PERIPH_ID_W_RESERVED9,
	PERIPH_ID_W_RESERVED10,
	PERIPH_ID_W_RESERVED11,
	PERIPH_ID_W_RESERVED12,
	PERIPH_ID_W_RESERVED13,
	PERIPH_ID_XUSB_PADCTL,
	PERIPH_ID_W_RESERVED15,

	/* 144 */
	PERIPH_ID_W_RESERVED16,
	PERIPH_ID_W_RESERVED17,
	PERIPH_ID_W_RESERVED18,
	PERIPH_ID_W_RESERVED19,
	PERIPH_ID_W_RESERVED20,
	PERIPH_ID_ENTROPY,
	PERIPH_ID_DDS,
	PERIPH_ID_W_RESERVED23,

	/* 152 */
	PERIPH_ID_DP2,
	PERIPH_ID_AMX0,
	PERIPH_ID_ADX0,
	PERIPH_ID_DVFS,
	PERIPH_ID_XUSB_SS,
	PERIPH_ID_W_RESERVED29,
	PERIPH_ID_W_RESERVED30,
	PERIPH_ID_W_RESERVED31,

	PERIPH_ID_X_FIRST,
	/* X word: 31:0 */
	PERIPH_ID_SPARE = PERIPH_ID_X_FIRST,
	PERIPH_ID_X_RESERVED1,
	PERIPH_ID_X_RESERVED2,
	PERIPH_ID_X_RESERVED3,
	PERIPH_ID_CAM_MCLK,
	PERIPH_ID_CAM_MCLK2,
	PERIPH_ID_I2C6,
	PERIPH_ID_X_RESERVED7,

	/* 168 */
	PERIPH_ID_X_RESERVED8,
	PERIPH_ID_X_RESERVED9,
	PERIPH_ID_X_RESERVED10,
	PERIPH_ID_VIM2_CLK,
	PERIPH_ID_X_RESERVED12,
	PERIPH_ID_X_RESERVED13,
	PERIPH_ID_EMC_DLL,
	PERIPH_ID_X_RESERVED15,

	/* 176 */
	PERIPH_ID_HDMI_AUDIO,
	PERIPH_ID_CLK72MHZ,
	PERIPH_ID_VIC,
	PERIPH_ID_X_RESERVED19,
	PERIPH_ID_ADX1,
	PERIPH_ID_DPAUX,
	PERIPH_ID_SOR0,
	PERIPH_ID_X_RESERVED23,

	/* 184 */
	PERIPH_ID_GPU,
	PERIPH_ID_AMX1,
	PERIPH_ID_AFC5,
	PERIPH_ID_AFC4,
	PERIPH_ID_AFC3,
	PERIPH_ID_AFC2,
	PERIPH_ID_AFC1,
	PERIPH_ID_AFC0,

	PERIPH_ID_COUNT,
	PERIPH_ID_NONE = -1,
};

enum pll_out_id {
	PLL_OUT1,
	PLL_OUT2,
	PLL_OUT3,
	PLL_OUT4
};

/*
 * Clock peripheral IDs which sadly don't match up with PERIPH_ID. we want
 * callers to use the PERIPH_ID for all access to peripheral clocks to avoid
 * confusion bewteen PERIPH_ID_... and PERIPHC_...
 *
 * We don't call this CLOCK_PERIPH_ID or PERIPH_CLOCK_ID as it would just be
 * confusing.
 */
enum periphc_internal_id {
	/* 0x00 */
	PERIPHC_I2S1,
	PERIPHC_I2S2,
	PERIPHC_SPDIF_OUT,
	PERIPHC_SPDIF_IN,
	PERIPHC_PWM,
	PERIPHC_05h,
	PERIPHC_SBC2,
	PERIPHC_SBC3,

	/* 0x08 */
	PERIPHC_08h,
	PERIPHC_I2C1,
	PERIPHC_I2C5,
	PERIPHC_0bh,
	PERIPHC_0ch,
	PERIPHC_SBC1,
	PERIPHC_DISP1,
	PERIPHC_DISP2,

	/* 0x10 */
	PERIPHC_10h,
	PERIPHC_11h,
	PERIPHC_VI,
	PERIPHC_13h,
	PERIPHC_SDMMC1,
	PERIPHC_SDMMC2,
	PERIPHC_G3D,
	PERIPHC_G2D,

	/* 0x18 */
	PERIPHC_18h,
	PERIPHC_SDMMC4,
	PERIPHC_VFIR,
	PERIPHC_1Bh,
	PERIPHC_1Ch,
	PERIPHC_HSI,
	PERIPHC_UART1,
	PERIPHC_UART2,

	/* 0x20 */
	PERIPHC_HOST1X,
	PERIPHC_21h,
	PERIPHC_22h,
	PERIPHC_HDMI,
	PERIPHC_24h,
	PERIPHC_25h,
	PERIPHC_I2C2,
	PERIPHC_EMC,

	/* 0x28 */
	PERIPHC_UART3,
	PERIPHC_29h,
	PERIPHC_VI_SENSOR,
	PERIPHC_2bh,
	PERIPHC_2ch,
	PERIPHC_SBC4,
	PERIPHC_I2C3,
	PERIPHC_SDMMC3,

	/* 0x30 */
	PERIPHC_UART4,
	PERIPHC_UART5,
	PERIPHC_VDE,
	PERIPHC_OWR,
	PERIPHC_NOR,
	PERIPHC_CSITE,
	PERIPHC_I2S0,
	PERIPHC_DTV,

	/* 0x38 */
	PERIPHC_38h,
	PERIPHC_39h,
	PERIPHC_3ah,
	PERIPHC_3bh,
	PERIPHC_MSENC,
	PERIPHC_TSEC,
	PERIPHC_3eh,
	PERIPHC_OSC,

	PERIPHC_VW_FIRST,
	/* 0x40 */
	PERIPHC_40h = PERIPHC_VW_FIRST,
	PERIPHC_MSELECT,
	PERIPHC_TSENSOR,
	PERIPHC_I2S3,
	PERIPHC_I2S4,
	PERIPHC_I2C4,
	PERIPHC_SBC5,
	PERIPHC_SBC6,

	/* 0x48 */
	PERIPHC_AUDIO,
	PERIPHC_49h,
	PERIPHC_DAM0,
	PERIPHC_DAM1,
	PERIPHC_DAM2,
	PERIPHC_HDA2CODEC2X,
	PERIPHC_ACTMON,
	PERIPHC_EXTPERIPH1,

	/* 0x50 */
	PERIPHC_EXTPERIPH2,
	PERIPHC_EXTPERIPH3,
	PERIPHC_52h,
	PERIPHC_I2CSLOW,
	PERIPHC_SYS,
	PERIPHC_55h,
	PERIPHC_56h,
	PERIPHC_57h,

	/* 0x58 */
	PERIPHC_58h,
	PERIPHC_SOR,
	PERIPHC_5ah,
	PERIPHC_5bh,
	PERIPHC_SATAOOB,
	PERIPHC_SATA,
	PERIPHC_HDA,		/* 0x428 */
	PERIPHC_5fh,

	PERIPHC_X_FIRST,
	/* 0x60 */
	PERIPHC_XUSB_CORE_HOST = PERIPHC_X_FIRST,	/* 0x600 */
	PERIPHC_XUSB_FALCON,
	PERIPHC_XUSB_FS,
	PERIPHC_XUSB_CORE_DEV,
	PERIPHC_XUSB_SS,
	PERIPHC_CILAB,
	PERIPHC_CILCD,
	PERIPHC_CILE,

	/* 0x68 */
	PERIPHC_DSIA_LP,
	PERIPHC_DSIB_LP,
	PERIPHC_ENTROPY,
	PERIPHC_DVFS_REF,
	PERIPHC_DVFS_SOC,
	PERIPHC_TRACECLKIN,
	PERIPHC_ADX0,
	PERIPHC_AMX0,

	/* 0x70 */
	PERIPHC_EMC_LATENCY,
	PERIPHC_SOC_THERM,
	PERIPHC_72h,
	PERIPHC_73h,
	PERIPHC_74h,
	PERIPHC_75h,
	PERIPHC_VI_SENSOR2,
	PERIPHC_I2C6,

	/* 0x78 */
	PERIPHC_78h,
	PERIPHC_EMC_DLL,
	PERIPHC_HDMI_AUDIO,
	PERIPHC_CLK72MHZ,
	PERIPHC_ADX1,
	PERIPHC_AMX1,
	PERIPHC_VIC,
	PERIPHC_7fh,

	PERIPHC_COUNT,

	PERIPHC_NONE = -1,
};

/* Converts a clock number to a clock register: 0=L, 1=H, 2=U, 0=V, 1=W */
#define PERIPH_REG(id) \
	(id < PERIPH_ID_VW_FIRST) ? \
		((id) >> 5) : ((id - PERIPH_ID_VW_FIRST) >> 5)

/* Mask value for a clock (within PERIPH_REG(id)) */
#define PERIPH_MASK(id) (1 << ((id) & 0x1f))

/* return 1 if a PLL ID is in range */
#define clock_id_is_pll(id) ((id) >= CLOCK_ID_FIRST && (id) < CLOCK_ID_COUNT)

/* return 1 if a peripheral ID is in range */
#define clock_periph_id_isvalid(id) ((id) >= PERIPH_ID_FIRST && \
		(id) < PERIPH_ID_COUNT)

#endif	/* _TEGRA124_CLOCK_TABLES_H_ */
