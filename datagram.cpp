//START_BYTE
#define START_BYTE 0x21
//channel
#define CHANNEL_C1_TCH_LVC 0b00
#define CHANNEL_C1_FL_LVC 0b01
#define CHANNEL_C1_TCH_C1_FL 0b10
// interaction_algorithm
#define INTERACTION_ALGORITHM_ODK_PDK 0b0110
#define INTERACTION_ALGORITHM_DUPLEX_2 0b0111
#define INTERACTION_ALGORITHM_5C55_ARAGVA 0b1000
#define INTERACTION_ALGORITHM_V42 0b1011
// plume
#define PLUME_ON 0b1
#define PLUME_OFF 0b0
// PDK
#define PDK_ODK 0b0
#define PDK_PDK 0b1
// UZO
#define UZO_ODK1_PDK1 0b0
#define UZO_ODK2_PDK2 0b1
// TANGENT
#define TANGENT_ON 0b1
#define TANGENT_OFF 0b0
// PHASING
#define PHASING_PERIOD 0b0
#define PHASING_ONE 0b1
// SPEED_AND_TYPE_OF_MODULATION_С1_TCH
#define SPEED_AND_TYPE_OF_MODULATION_С1_TCH_1 0b000
#define SPEED_AND_TYPE_OF_MODULATION_С1_TCH_2 0b001
#define SPEED_AND_TYPE_OF_MODULATION_С1_TCH_3 0b010
#define SPEED_AND_TYPE_OF_MODULATION_С1_TCH_4 0b011
#define SPEED_AND_TYPE_OF_MODULATION_С1_TCH_5 0b100
#define SPEED_AND_TYPE_OF_MODULATION_С1_TCH_6 0b101
#define SPEED_AND_TYPE_OF_MODULATION_С1_TCH_7 0b110
#define SPEED_AND_TYPE_OF_MODULATION_С1_TCH_8 0b111
// TRANSMISSION_LEVEL_C1_TCH
#define TRANSMISSION_LEVEL_C1_TCH_1 0b0000
#define TRANSMISSION_LEVEL_C1_TCH_2 0b0001
#define TRANSMISSION_LEVEL_C1_TCH_3 0b0010
#define TRANSMISSION_LEVEL_C1_TCH_4 0b0011
#define TRANSMISSION_LEVEL_C1_TCH_5 0b0100
#define TRANSMISSION_LEVEL_C1_TCH_6 0b0101
#define TRANSMISSION_LEVEL_C1_TCH_7 0b0110
#define TRANSMISSION_LEVEL_C1_TCH_8 0b0111
#define TRANSMISSION_LEVEL_C1_TCH_9 0b1000
#define TRANSMISSION_LEVEL_C1_TCH_10 0b1001
#define TRANSMISSION_LEVEL_C1_TCH_11 0b1010
#define TRANSMISSION_LEVEL_C1_TCH_12 0b1011
#define TRANSMISSION_LEVEL_C1_TCH_13 0b1100
#define TRANSMISSION_LEVEL_C1_TCH_14 0b1101
#define TRANSMISSION_LEVEL_C1_TCH_15 0b1110
#define TRANSMISSION_LEVEL_C1_TCH_16 0b1111
// MODULE_V26
#define MODULE_V26_A 0b0
#define MODULE_V26_B 0b1
// FREQUENCE_V29
#define FREQUENCE_V29_1800 0b0
#define FREQUENCE_V29_1700 0b1
// SCRAMBLER
#define SCRAMBLER_ON 0b0
#define SCRAMBLER_OFF 0b1
// ADAPTATION_CORRECTOR
#define ADAPTATION_CORRECTOR_ON 0b0
#define ADAPTATION_CORRECTOR_OFF 0b1
// CABLE_CORRECTOR_ON_TRANSMISSION
#define CABLE_CORRECTOR_ON_TRANSMISSION_ON 0b1
#define CABLE_CORRECTOR_ON_TRANSMISSION_OFF 0b0
// CABLE_CORRECTOR_AT_RECEPTION
#define CABLE_CORRECTOR_AT_RECEPTION_ON 0b1
#define CABLE_CORRECTOR_AT_RECEPTION_OFF 0b0
// SPEED_C1_FL
#define SPEED_C1_FL_1 0b0000
#define SPEED_C1_FL_2 0b0001
#define SPEED_C1_FL_3 0b0010
#define SPEED_C1_FL_4 0b0011
#define SPEED_C1_FL_5 0b0100
#define SPEED_C1_FL_6 0b0101
#define SPEED_C1_FL_7 0b0111
#define SPEED_C1_FL_8 0b1000
#define SPEED_C1_FL_9 0b1001
// MANAGE_OF_TANGENT
#define MANAGE_OF_TANGENT_ON 0b1
#define MANAGE_OF_TANGENT_OFF 0b0
// V42_N400
#define V42_N400_0 0b0000
#define V42_N400_1 0b0001
#define V42_N400_2 0b0010
#define V42_N400_3 0b0011
#define V42_N400_4 0b0100
#define V42_N400_5 0b0101
#define V42_N400_6 0b0110
#define V42_N400_7 0b0111
#define V42_N400_8 0b1000
#define V42_N400_9 0b1001
#define V42_N400_10 0b1010
#define V42_N400_11 0b1011
#define V42_N400_12 0b1100
#define V42_N400_13 0b1101
#define V42_N400_14 0b1110
#define V42_N400_15 0b1111
// BLOCK_LENGTH
#define BLOCK_LENGTH_1 0b00
#define BLOCK_LENGTH_2 0b01
#define BLOCK_LENGTH_3 0b10
// NUBMERS_OF_REQUERIES
#define NUBMERS_OF_REQUERIES_1 0b00
#define NUBMERS_OF_REQUERIES_2 0b01
#define NUBMERS_OF_REQUERIES_3 0b10
#define NUBMERS_OF_REQUERIES_4 0b11
// DEPHASING_CRITERION
#define DEPHASING_CRITERION_1 0b000
#define DEPHASING_CRITERION_2 0b001
#define DEPHASING_CRITERION_3 0b010
#define DEPHASING_CRITERION_4 0b011
#define DEPHASING_CRITERION_5 0b100
#define DEPHASING_CRITERION_6 0b101
#define DEPHASING_CRITERION_7 0b110
#define DEPHASING_CRITERION_8 0b111
// BLOCK_DEPTH
#define BLOCK_DEPTH_1 0b00
#define BLOCK_DEPTH_2 0b01
#define BLOCK_DEPTH_3 0b10
#define BLOCK_DEPTH_4 0b11
// FORMAT_5C55
#define FORMAT_5C55_1 0b0
#define FORMAT_5C55_2 0b1
// INV_TRANSFER
#define INV_TRANSFER_1 0b0
#define INV_TRANSFER_2 0b1
// INV_RECEPTION
#define INV_RECEPTION_1 0b0
#define INV_RECEPTION_2 0b1
// RESPONSE_MODE_V42
#define RESPONSE_MODE_V42_1 0b0
#define RESPONSE_MODE_V42_2 0b1
// PDK_PAUSE
#define PDK_PAUSE 0b01010101
// ADD_DATA_ODK2_PDK2
#define ADD_DATA_ODK2_PDK2 0b00000
// V_42_T400_PDK_T_START
#define V_42_T400_PDK_T_START 0b00000000
// V_42_T400_PDK_T_STOP
#define V_42_T400_PDK_T_STOP 0b00000000
// LOAN_AMOUNT_V42_K
#define LOAN_AMOUNT_V42 0b0000
// MAX_LENGTH_KADR_V42_N401
#define MAX_LENGTH_KADR_V42 0b00000000



struct DatagramAPD
{
    unsigned start_byte:8;
    unsigned kod_byte:8;
    //0
    unsigned channel:2;
    unsigned interaction_algorithm:4;
    unsigned :2;
    //1
    unsigned :3;
    unsigned plume:1;
    unsigned :4;
    //2
    unsigned PDK:1;
    unsigned UZO:1;
    unsigned :1;
    unsigned tangent:1;
    unsigned :3;
    unsigned phasing:1;
    //3
    unsigned speed_and_type_of_modulation_С1_TCH:3;
    unsigned :1;
    unsigned transmission_level_C1_TCH:4;
    //4
    unsigned module_V26:1;
    unsigned frequence_V29:1;
    unsigned scrambler:1;
    unsigned :1;
    unsigned adaptation_corrector:1;
    unsigned cable_corrector_on_transmission:1;
    unsigned cable_corrector_at_reception:1;
    unsigned :1;
    //5
    unsigned speed_C1_FL:4;
    unsigned :4;
    //6
    unsigned manage_of_tangent:1;
    unsigned :3;
    unsigned V42_N400:4;
    //7
    unsigned block_length:2;
    unsigned nubmers_of_requeries:2;
    unsigned dephasing_criterion:3;
    unsigned :1;
    //8
    unsigned block_depth:2;
    unsigned :2;
    unsigned format_5C55:1;
    unsigned inv_transfer:1;
    unsigned inv_reception:1;
    unsigned response_mode_V42:1;
    //9
    unsigned PDK_pause:8;
    //10
    unsigned add_data_ODK2_PDK2:5;
    unsigned :3;
    //11
    unsigned V_42_T400_PDK_T_start:8;
    //12
    unsigned V_42_T400_PDK_T_stop:8;
    //13
    unsigned :2;
    unsigned loan_amount_V42:4;
    unsigned :2;
    //14
    unsigned max_length_kadr_V42:8;
    //15
    unsigned end_byte:8;
}__attribute__((packed));
