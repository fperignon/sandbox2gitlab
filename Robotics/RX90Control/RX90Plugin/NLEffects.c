#include <math.h>
#include "LagrangianModel.h"

void NLEffects(N, q, qdot)
double N[6];
double q[6];
double qdot[6];
{
  double C0 = cos(q[0]);
  double S0 = sin(q[0]);
  double C1 = cos(q[1]);
  double S1 = sin(q[1]);
  double C2 = cos(q[2]);
  double S2 = sin(q[2]);
  double C3 = cos(q[3]);
  double S3 = sin(q[3]);
  double C4 = cos(q[4]);
  double S4 = sin(q[4]);
  double C5 = cos(q[5]);
  double S5 = sin(q[5]);
  double tmp1 = -pow(qdot[0], 2);
  double tmp7 = -S1 * qdot[0];
  double tmp8 = C1 * qdot[0];
  double tmp9 = -tmp8 * qdot[1];
  double tmp10 = tmp7 * qdot[1];
  double tmp11 = -0.981e1 * S1;
  double tmp12 = 0.981e1 * C1;
  double tmp13 = -0.10e0 * tmp1;
  double tmp14 = tmp10 - tmp7 * qdot[1];
  double tmp16 = -pow(qdot[1], 2) - tmp7 * tmp7;
  double tmp17 = -tmp9 - tmp8 * qdot[1];
  double tmp19 = tmp9 - tmp8 * qdot[1];
  double tmp22 = tmp8 * tmp7;
  double tmp23 = 0.18042e2 * tmp11 + 0.54126e1 * tmp22 + 0.1407276e1 * tmp14;
  double tmp24 = 0.18042e2 * tmp12 + 0.54126e1 * tmp16 + 0.1407276e1 * tmp17;
  double tmp26 = 0.20305475e1 * tmp9 + tmp8 * (-0.4551828e0 * tmp8 - 0.189078e1 * qdot[1]) + qdot[1] * (0.1397675e0 * tmp8 + 0.4551828e0 * qdot[1]) + 0.54126e1 * tmp13 - 0.1407276e1 * tmp12;
  double tmp27 = 0.1397675e0 * tmp10 - 0.20305475e1 * tmp7 * qdot[1] - tmp7 * (-0.4551828e0 * tmp8 - 0.189078e1 * qdot[1]) + 0.1407276e1 * tmp11;
  double tmp28 = -0.4551828e0 * tmp10 + tmp7 * (0.1397675e0 * tmp8 + 0.4551828e0 * qdot[1]) - 0.20305475e1 * tmp8 * tmp7 - 0.54126e1 * tmp11;
  double tmp29 = C2 * tmp7 - S2 * tmp8;
  double tmp30 = S2 * tmp7 + C2 * tmp8;
  double tmp31 = C2 * tmp9 - S2 * tmp10 - tmp30 * qdot[2];
  double tmp32 = S2 * tmp9 + C2 * tmp10 + tmp29 * qdot[2];
  double tmp33 = C2 * (tmp11 + 0.45e0 * tmp22) - S2 * (tmp12 + 0.45e0 * tmp16);
  double tmp34 = S2 * (tmp11 + 0.45e0 * tmp22) + C2 * (tmp12 + 0.45e0 * tmp16);
  double tmp35 = tmp13 + 0.45e0 * tmp19;
  double tmp36 = tmp32 + (-qdot[1] - qdot[2]) * tmp29;
  double tmp38 = -pow(-qdot[1] - qdot[2], 2) - tmp29 * tmp29;
  double tmp39 = -tmp31 + (-qdot[1] - qdot[2]) * tmp30;
  double tmp41 = tmp31 + (-qdot[1] - qdot[2]) * tmp30;
  double tmp42 = -tmp30 * tmp30 - tmp29 * tmp29;
  double tmp44 = tmp30 * tmp29;
  double tmp45 = 0.1637e2 * tmp33 - 0.11459e0 * tmp44 - 0.14733e1 * tmp36;
  double tmp46 = 0.1637e2 * tmp34 - 0.11459e0 * tmp38 - 0.14733e1 * tmp39;
  double tmp47 = 0.1637e2 * tmp35 - 0.11459e0 * tmp41 - 0.14733e1 * tmp42;
  double tmp48 = 0.1833991e0 * tmp31 + tmp30 * (-0.143131e-1 * tmp30 - 0.428021e-1 * qdot[1] - 0.428021e-1 * qdot[2]) - (-qdot[1] - qdot[2]) * (0.179597e0 * tmp30 + 0.143131e-1 * qdot[1] + 0.143131e-1 * qdot[2]) - 0.11459e0 * tmp35 + 0.14733e1 * tmp34;
  double tmp49 = 0.179597e0 * tmp32 + 0.1833991e0 * (-qdot[1] - qdot[2]) * tmp29 - tmp29 * (-0.143131e-1 * tmp30 - 0.428021e-1 * qdot[1] - 0.428021e-1 * qdot[2]) - 0.14733e1 * tmp33;
  double tmp50 = -0.143131e-1 * tmp32 + tmp29 * (0.179597e0 * tmp30 + 0.143131e-1 * qdot[1] + 0.143131e-1 * qdot[2]) - 0.1833991e0 * tmp30 * tmp29 + 0.11459e0 * tmp33;
  double tmp51 = C3 * tmp29 - S3 * (-qdot[1] - qdot[2]);
  double tmp52 = S3 * tmp29 + C3 * (-qdot[1] - qdot[2]);
  double tmp53 = C3 * tmp31 - tmp52 * qdot[3];
  double tmp54 = S3 * tmp31 + tmp51 * qdot[3];
  double tmp55 = C3 * (tmp33 + 0.7e-1 * tmp44 + 0.1e0 * tmp36) - S3 * (tmp35 + 0.7e-1 * tmp41 + 0.1e0 * tmp42);
  double tmp56 = tmp34 + 0.7e-1 * tmp38 + 0.1e0 * tmp39;
  double tmp57 = S3 * (tmp33 + 0.7e-1 * tmp44 + 0.1e0 * tmp36) + C3 * (tmp35 + 0.7e-1 * tmp41 + 0.1e0 * tmp42);
  double tmp59 = tmp54 + (tmp30 + qdot[3]) * tmp51;
  double tmp60 = -tmp52 * tmp52 - tmp51 * tmp51;
  double tmp62 = -tmp32 + tmp52 * tmp51;
  double tmp63 = tmp53 + tmp52 * (tmp30 + qdot[3]);
  double tmp65 = -tmp52 * tmp52 - pow(tmp30 + qdot[3], 2);
  double tmp66 = -tmp54 + (tmp30 + qdot[3]) * tmp51;
  double tmp67 = 0.11362e2 * tmp55 + 0.11362e-1 * tmp65 + 0.2897310e1 * tmp66;
  double tmp68 = 0.11362e2 * tmp56 + 0.11362e-1 * tmp59 + 0.2897310e1 * tmp60;
  double tmp69 = 0.11362e2 * tmp57 + 0.11362e-1 * tmp62 + 0.2897310e1 * tmp63;
  double tmp70 = 0.9148140e0 * tmp53 + 0.71027e-2 * tmp32 + 0.9138254e0 * tmp52 * (tmp30 + qdot[3]) - tmp52 * (0.71027e-2 * tmp51 + 0.60114e-2 * tmp30 + 0.60114e-2 * qdot[3]) + 0.2897310e1 * tmp57;
  double tmp71 = 0.71027e-2 * tmp53 + 0.60114e-2 * tmp32 + tmp52 * (0.9148140e0 * tmp51 + 0.71027e-2 * tmp30 + 0.71027e-2 * qdot[3]) - 0.9138254e0 * tmp52 * tmp51 - 0.11362e-1 * tmp57;
  double tmp72 = 0.9138254e0 * tmp54 + tmp51 * (0.71027e-2 * tmp51 + 0.60114e-2 * tmp30 + 0.60114e-2 * qdot[3]) - (tmp30 + qdot[3]) * (0.9148140e0 * tmp51 + 0.71027e-2 * tmp30 + 0.71027e-2 * qdot[3]) + 0.11362e-1 * tmp56 - 0.2897310e1 * tmp55;
  double tmp73 = C4 * tmp51 - S4 * (tmp30 + qdot[3]);
  double tmp74 = S4 * tmp51 + C4 * (tmp30 + qdot[3]);
  double tmp75 = C4 * tmp53 - S4 * tmp32 - tmp74 * qdot[4];
  double tmp77 = C4 * (tmp55 + 0.38e0 * tmp66) - S4 * (tmp56 + 0.38e0 * tmp60);
  double tmp78 = S4 * (tmp55 + 0.38e0 * tmp66) + C4 * (tmp56 + 0.38e0 * tmp60);
  double tmp79 = tmp57 + 0.38e0 * tmp63;
  double tmp82 = -pow(tmp52 - qdot[4], 2) - tmp73 * tmp73;
  double tmp85 = tmp75 + (tmp52 - qdot[4]) * tmp74;
  double tmp88 = -tmp54 + tmp74 * tmp73;
  double tmp89 = 0.578e0 * tmp77 + 0.1156e-1 * tmp88;
  double tmp90 = 0.578e0 * tmp78 + 0.1156e-1 * tmp82;
  double tmp91 = 0.578e0 * tmp79 + 0.1156e-1 * tmp85;
  double tmp92 = 0.1156e-1 * tmp79;
  double tmp93 = -0.1156e-1 * tmp77;
  double tmp94 = C5 * tmp73 - S5 * (tmp52 - qdot[4]);
  double tmp95 = S5 * tmp73 + C5 * (tmp52 - qdot[4]);
  double tmp96 = C5 * tmp75 - S5 * tmp54 - tmp95 * qdot[5];
  double tmp97 = S5 * tmp75 + C5 * tmp54 + tmp94 * qdot[5];
  double tmp98 = C5 * tmp77 - S5 * tmp79;
  double tmp99 = S5 * tmp77 + C5 * tmp79;
  double tmp102 = -tmp95 * tmp95 - tmp94 * tmp94;
  double tmp105 = tmp96 + tmp95 * (tmp74 + qdot[5]);
  double tmp108 = -tmp97 + (tmp74 + qdot[5]) * tmp94;
  double tmp109 = 0.302e0 * tmp98 + 0.1208e-1 * tmp108;
  double tmp110 = 0.302e0 * tmp78 + 0.1208e-1 * tmp102;
  double tmp111 = 0.302e0 * tmp99 + 0.1208e-1 * tmp105;
  double tmp112 = 0.1208e-1 * tmp99;
  double tmp113 = -0.1208e-1 * tmp98;
  double tmp114 = C5 * tmp109 + S5 * tmp111;
  double tmp115 = -S5 * tmp109 + C5 * tmp111;
  double tmp116 = C5 * tmp112 + S5 * tmp113;
  double tmp117 = -S5 * tmp112 + C5 * tmp113;
  double tmp118 = tmp89 + tmp114;
  double tmp119 = tmp90 + tmp110;
  double tmp120 = tmp91 + tmp115;
  double tmp121 = tmp92 + tmp116;
  double tmp122 = tmp93 + tmp117;
  double tmp123 = C4 * tmp118 + S4 * tmp119;
  double tmp124 = -S4 * tmp118 + C4 * tmp119;
  double tmp125 = C4 * tmp121 + 0.38e0 * tmp120;
  double tmp126 = -S4 * tmp121;
  double tmp127 = tmp122 - 0.38e0 * tmp123;
  double tmp128 = tmp67 + tmp123;
  double tmp129 = tmp68 + tmp124;
  double tmp130 = tmp69 + tmp120;
  double tmp131 = tmp70 + tmp125;
  double tmp132 = tmp71 + tmp126;
  double tmp133 = tmp72 + tmp127;
  double tmp134 = C3 * tmp128 + S3 * tmp130;
  double tmp135 = -S3 * tmp128 + C3 * tmp130;
  double tmp136 = C3 * tmp131 + S3 * tmp133 + 0.7e-1 * tmp135 - 0.1e0 * tmp129;
  double tmp137 = tmp132 + 0.1e0 * tmp134;
  double tmp138 = -S3 * tmp131 + C3 * tmp133 - 0.7e-1 * tmp134;
  double tmp139 = tmp45 + tmp134;
  double tmp140 = tmp46 + tmp129;
  double tmp141 = tmp47 + tmp135;
  double tmp142 = tmp48 + tmp136;
  double tmp143 = tmp49 + tmp137;
  double tmp144 = tmp50 + tmp138;
  double tmp145 = C2 * tmp139 + S2 * tmp140;
  double tmp146 = -S2 * tmp139 + C2 * tmp140;
  double tmp147 = C2 * tmp142 + S2 * tmp143 + 0.45e0 * tmp141;
  double tmp148 = -S2 * tmp142 + C2 * tmp143;
  double tmp149 = tmp144 - 0.45e0 * tmp145;
  double tmp150 = tmp23 + tmp145;
  double tmp151 = tmp24 + tmp146;
  double tmp153 = tmp26 + tmp147;
  double tmp154 = tmp27 + tmp148;
  double tmp155 = tmp28 + tmp149;
  double tmp156 = C1 * tmp150 + S1 * tmp151;
  double tmp159 = -S1 * tmp153 + C1 * tmp154 - 0.10e0 * tmp156;
  N[0] = tmp159;
  N[1] = -tmp155;
  N[2] = -tmp144;
  N[3] = tmp132;
  N[4] = -tmp122;
  N[5] = 0.0e0;
}
