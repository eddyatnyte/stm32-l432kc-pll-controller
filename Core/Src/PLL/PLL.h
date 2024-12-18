/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PLL.h
 *
 * Code generated for Simulink model 'PLL'.
 *
 * Model version                  : 1.67
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May 14 18:42:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef PLL_h_
#define PLL_h_
#ifndef PLL_COMMON_INCLUDES_
#define PLL_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PLL_COMMON_INCLUDES_ */

#include "PLL_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S6>/For Each Subsystem' */
typedef struct {
  real_T VariableIntegerDelay_DSTATE[45];/* '<S7>/Variable Integer Delay' */
} DW_CoreSubsys_PLL_T;

/* Block signals (default storage) */
typedef struct {
  real_T Probe[2];                     /* '<S6>/Probe' */
} B_PLL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S6>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_n;           /* '<S6>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S6>/Unit Delay1' */
  real_T DiscreteDerivative_states;    /* '<S3>/Discrete Derivative ' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S3>/Discrete-Time Integrator' */
  real_T Delay_x1_DSTATE;              /* '<S8>/Delay_x1' */
  real_T Delay_x2_DSTATE;              /* '<S8>/Delay_x2' */
  real_T PrevY;                        /* '<S2>/Rate Limiter' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S2>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S6>/Discrete-Time Integrator' */
  boolean_T Initial_FirstOutputTime;   /* '<S2>/Initial' */
  DW_CoreSubsys_PLL_T CoreSubsys[1];   /* '<S6>/For Each Subsystem' */
} DW_PLL_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint16_T ADC_IN;                     /* '<Root>/ADC_IN' */
} ExtU_PLL_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Frequency;                  /* '<Root>/Frequency' */
  real32_T Phase;                      /* '<Root>/Phase' */
} ExtY_PLL_T;

/* Real-time Model Data Structure */
struct tag_RTM_PLL_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_PLL_T PLL_B;

/* Block states (default storage) */
extern DW_PLL_T PLL_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PLL_T PLL_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PLL_T PLL_Y;

/* Model entry point functions */
extern void PLL_initialize(void);
extern void PLL_step(void);
extern void PLL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PLL_T *const PLL_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PLL'
 * '<S1>'   : 'PLL/PLL'
 * '<S2>'   : 'PLL/PLL/Model'
 * '<S3>'   : 'PLL/PLL/Model/Discrete'
 * '<S4>'   : 'PLL/PLL/Model/Moving Average (Variable Frequency)'
 * '<S5>'   : 'PLL/PLL/Model/Second-Order Filter'
 * '<S6>'   : 'PLL/PLL/Model/Moving Average (Variable Frequency)/Discrete'
 * '<S7>'   : 'PLL/PLL/Model/Moving Average (Variable Frequency)/Discrete/For Each Subsystem'
 * '<S8>'   : 'PLL/PLL/Model/Second-Order Filter/Model'
 * '<S9>'   : 'PLL/PLL/Model/Second-Order Filter/Model/A*k(k-1)'
 * '<S10>'  : 'PLL/PLL/Model/Second-Order Filter/Model/B*(u(k)+u(k-1))'
 * '<S11>'  : 'PLL/PLL/Model/Second-Order Filter/Model/C*x(k)'
 */
#endif                                 /* PLL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
