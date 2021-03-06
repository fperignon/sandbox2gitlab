#include "TaskFunctionDefinition.h"
#include <math.h>
void TaskJacobian(J, q)
double J[36];
double q[6];
{
  double t1;
  double t10;
  double t108;
  double t111;
  double t112;
  double t115;
  double t12;
  double t138;
  double t139;
  double t14;
  double t141;
  double t145;
  double t16;
  double t165;
  double t18;
  double t19;
  double t2;
  double t20;
  double t21;
  double t22;
  double t24;
  double t25;
  double t26;
  double t28;
  double t3;
  double t30;
  double t31;
  double t33;
  double t34;
  double t36;
  double t37;
  double t38;
  double t4;
  double t42;
  double t43;
  double t44;
  double t46;
  double t48;
  double t5;
  double t50;
  double t52;
  double t55;
  double t57;
  double t6;
  double t62;
  double t65;
  double t70;
  double t73;
  double t74;
  double t76;
  double t79;
  double t8;
  double t80;
  double t81;
  double t84;
  double t9;
  double t90;
  double t92;
  double t98;
  double t99;
  {
    t1 = q[0];
    t2 = sin(t1);
    t3 = q[1];
    t4 = cos(t3);
    t5 = q[2];
    t6 = sin(t5);
    t8 = 0.45 * t4 * t6;
    t9 = sin(t3);
    t10 = cos(t5);
    t12 = 0.45 + 0.45 * t10;
    t14 = t8 + t9 * t12;
    J[0] = -t2 * t14;
    J[1] = 0.0;
    t16 = cos(t1);
    J[2] = -t16 * t14;
    t18 = q[3];
    t19 = cos(t18);
    t20 = t10 * t19;
    t21 = q[4];
    t22 = sin(t21);
    t24 = cos(t21);
    t25 = t6 * t24;
    t26 = t20 * t22 + t25;
    t28 = t6 * t19;
    t30 = t10 * t24;
    t31 = -t28 * t22 + t30;
    t33 = t4 * t26 + t9 * t31;
    t34 = t2 * t33;
    t36 = sin(t18);
    t37 = t16 * t36;
    t38 = t37 * t22;
    J[3] = -0.1 * t34 - 0.1 * t38;
    t42 = t19 * t24;
    t43 = q[5];
    t44 = sin(t43);
    t46 = cos(t43);
    t48 = t42 * t44 + t36 * t46;
    t50 = t6 * t22;
    t52 = t10 * t48 - t50 * t44;
    t55 = t10 * t22;
    t57 = -t6 * t48 - t55 * t44;
    t62 = t36 * t24;
    t65 = -t62 * t44 + t19 * t46;
    J[4] = -0.15 * t34 - 0.15 * t38 - 0.5E-1 * t2 * (t4 * t52 + t9 * t57) + 0.5E-1 * t16 * t65;
    t70 = t2 * t36;
    J[5] = -0.1 * t16 * t33 + 0.1 * t70 * t22;
    t73 = t9 * t6;
    t74 = 0.45 * t73;
    t76 = -t74 + t4 * t12;
    J[6] = t16 * t76;
    J[7] = -t14;
    J[8] = -t2 * t76;
    t79 = t4 * t31;
    t80 = -t9 * t26 + t79;
    t81 = t16 * t80;
    J[9] = 0.1 * t81;
    t84 = t4 * t57;
    J[10] = 0.15 * t81 + 0.5E-1 * t16 * (-t9 * t52 + t84);
    J[11] = -0.1 * t2 * t80;
    t90 = t4 * t10;
    t92 = 0.45 * t90 - t74;
    J[12] = t16 * t92;
    J[13] = -0.45 * t9 * t10 - t8;
    J[14] = -t2 * t92;
    t98 = -t9 * t26 + t79;
    t99 = t16 * t98;
    J[15] = 0.1 * t99;
    J[16] = 0.15 * t99 + 0.5E-1 * t16 * (-t9 * t52 + t84);
    J[17] = -0.1 * t2 * t98;
    J[18] = 0.0;
    J[19] = 0.0;
    J[20] = 0.0;
    t108 = t36 * t22;
    t111 = -t90 * t108 + t73 * t108;
    t112 = t16 * t111;
    t115 = t2 * t19 * t22;
    J[21] = 0.1 * t112 - 0.1 * t115;
    J[22] = 0.15 * t112 - 0.15 * t115 + 0.5E-1 * t16 * (t90 * t65 - t73 * t65) - 0.5E-1 * t2 * t48;
    J[23] = -0.1 * t2 * t111 - 0.1 * t16 * t19 * t22;
    J[24] = 0.0;
    J[25] = 0.0;
    J[26] = 0.0;
    t138 = t4 * (t20 * t24 - t50) + t9 * (-t28 * t24 - t55);
    t139 = t16 * t138;
    t141 = t70 * t24;
    J[27] = 0.1 * t139 - 0.1 * t141;
    t145 = t22 * t44;
    J[28] = 0.15 * t139 - 0.15 * t141 + 0.5E-1 * t16 * (t4 * (-t20 * t145 - t25 * t44) + t9 * (t28 * t145
            - t30 * t44)) + 0.5E-1 * t70 * t145;
    J[29] = -0.1 * t2 * t138 - 0.1 * t37 * t24;
    J[30] = 0.0;
    J[31] = 0.0;
    J[32] = 0.0;
    J[33] = 0.0;
    t165 = t42 * t46 - t36 * t44;
    J[34] = 0.5E-1 * t16 * (t4 * (t10 * t165 - t50 * t46) + t9 * (-t6 * t165 - t55 * t46)) + 0.5E-1 * t2 *
            (-t62 * t46 - t19 * t44);
    J[35] = 0.0;
    return;
  }
}

