/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PLL.c
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

#include "PLL.h"
#include <math.h>
#include "PLL_private.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_PLL_T PLL_B;

/* Block states (default storage) */
DW_PLL_T PLL_DW;

/* External inputs (root inport signals with default storage) */
ExtU_PLL_T PLL_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PLL_T PLL_Y;

/* Real-time model */
static RT_MODEL_PLL_T PLL_M_;
RT_MODEL_PLL_T *const PLL_M = &PLL_M_;
real_T rt_roundd(real_T u) {
	real_T y;
	if (fabs(u) < 4.503599627370496E+15) {
		if (u >= 0.5) {
			y = floor(u + 0.5);
		} else if (u > -0.5) {
			y = 0.0;
		} else {
			y = ceil(u - 0.5);
		}
	} else {
		y = u;
	}

	return y;
}

/* Model step function */
void PLL_step(void) {
	real_T Initial;
	real_T rtb_A21;
	real_T rtb_ImpAsg_InsertedFor_Out1_at_;
	real_T rtb_MathFunction1;
	real_T rtb_RoundingFunction1;
	real_T rtb_Saturation;
	real_T rtb_x2k;
	int32_T idxDelay;
	boolean_T rtb_RelationalOperator;

	/* Outport: '<Root>/Frequency' incorporates:
	 *  Gain: '<Root>/Gain1'
	 *  UnitDelay: '<S2>/Unit Delay'
	 */
	PLL_Y.Frequency = (real32_T) (PLL_DW.UnitDelay_DSTATE);

	/* RelationalOperator: '<S2>/Relational Operator' incorporates:
	 *  Constant: '<S2>/Constant2'
	 */
	rtb_RelationalOperator = (PLL_DW.DiscreteTimeIntegrator_DSTATE
			> 6.2831853071795862);

	/* InitialCondition: '<S2>/Initial' */
	if (PLL_DW.Initial_FirstOutputTime) {
		PLL_DW.Initial_FirstOutputTime = false;

		/* InitialCondition: '<S2>/Initial' */
		Initial = 0.0;
	} else {
		/* InitialCondition: '<S2>/Initial' incorporates:
		 *  Constant: '<S2>/Constant2'
		 *  Sum: '<S2>/Subtract'
		 */
		Initial = PLL_DW.DiscreteTimeIntegrator_DSTATE - 6.2831853071795862;
	}

	/* End of InitialCondition: '<S2>/Initial' */

	/* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
	if (rtb_RelationalOperator
			&& (PLL_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
		PLL_DW.DiscreteTimeIntegrator_DSTATE = Initial;
	}

	/* Outport: '<Root>/Phase' incorporates:
	 *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
	 *  Gain: '<Root>/Gain2'
	 */
	PLL_Y.Phase = (real32_T) (1000.0 * PLL_DW.DiscreteTimeIntegrator_DSTATE);

	/* Saturate: '<S6>/Saturation' incorporates:
	 *  UnitDelay: '<S2>/Unit Delay'
	 */
	rtb_Saturation = fmax(PLL_DW.UnitDelay_DSTATE, 2.2204460492503131E-16);

	/* Product: '<S2>/Product1' incorporates:
	 *  DataTypeConversion: '<Root>/Cast To Double'
	 *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
	 *  Inport: '<Root>/ADC_IN'
	 *  Trigonometry: '<S2>/Trigonometric Function2'
	 */
	 Initial = (0.00004884004884F * (real32_T)PLL_U.ADC_IN - 0.1F) * cos
	    (PLL_DW.DiscreteTimeIntegrator_DSTATE);

	/* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
	if (PLL_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
		/* DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
		PLL_DW.DiscreteTimeIntegrator_DSTATE_p += 0.00025 * Initial;
	}

	/* End of DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */

	/* Math: '<S6>/Math Function1' incorporates:
	 *  Product: '<S6>/Product2'
	 *
	 * About '<S6>/Math Function1':
	 *  Operator: reciprocal
	 */
	rtb_MathFunction1 = 1.0 / (PLL_B.Probe[0] * rtb_Saturation);

	/* Rounding: '<S6>/Rounding Function1' */
	rtb_RoundingFunction1 = rt_roundd(rtb_MathFunction1);

	/* Outputs for Iterator SubSystem: '<S6>/For Each Subsystem' incorporates:
	 *  ForEach: '<S7>/For Each'
	 */
	/* Delay: '<S7>/Variable Integer Delay' incorporates:
	 *  Sum: '<S6>/Sum4'
	 */
	if (rtb_RoundingFunction1 < 1.0) {
		/* ForEachSliceAssignment generated from: '<S7>/Out1' incorporates:
		 *  ForEachSliceSelector generated from: '<S7>/In1'
		 */
		rtb_ImpAsg_InsertedFor_Out1_at_ =
				PLL_DW.DiscreteTimeIntegrator_DSTATE_p;
	} else {
		if (rtb_RoundingFunction1 > 45.0) {
			idxDelay = 45;
		} else {
			idxDelay = (int32_T) (uint32_T) fmod(rtb_RoundingFunction1,
					4.294967296E+9);
		}

		/* ForEachSliceAssignment generated from: '<S7>/Out1' */
		rtb_ImpAsg_InsertedFor_Out1_at_ =
				PLL_DW.CoreSubsys[0].VariableIntegerDelay_DSTATE[45U
						- (uint32_T) idxDelay];
	}

	/* End of Delay: '<S7>/Variable Integer Delay' */

	/* Update for Delay: '<S7>/Variable Integer Delay' incorporates:
	 *  ForEachSliceSelector generated from: '<S7>/In1'
	 */
	for (idxDelay = 0; idxDelay < 44; idxDelay++) {
		PLL_DW.CoreSubsys[0].VariableIntegerDelay_DSTATE[idxDelay] =
				PLL_DW.CoreSubsys[0].VariableIntegerDelay_DSTATE[idxDelay + 1];
	}

	PLL_DW.CoreSubsys[0].VariableIntegerDelay_DSTATE[44] =
			PLL_DW.DiscreteTimeIntegrator_DSTATE_p;

	/* End of Update for Delay: '<S7>/Variable Integer Delay' */
	/* End of Outputs for SubSystem: '<S6>/For Each Subsystem' */

	/* Sum: '<S6>/Sum3' incorporates:
	 *  Constant: '<S6>/Constant2'
	 *  UnitDelay: '<S6>/Unit Delay'
	 */
	PLL_DW.UnitDelay_DSTATE_n++;

	/* Switch: '<S6>/Switch' incorporates:
	 *  Gain: '<S6>/Gain1'
	 *  Math: '<S6>/Math Function2'
	 *  Product: '<S6>/Product'
	 *  Product: '<S6>/Product1'
	 *  RelationalOperator: '<S6>/Relational Operator'
	 *  Rounding: '<S6>/Rounding Function2'
	 *  Sum: '<S6>/Sum'
	 *  Sum: '<S6>/Sum1'
	 *  Sum: '<S6>/Sum2'
	 *  UnitDelay: '<S6>/Unit Delay'
	 *  UnitDelay: '<S6>/Unit Delay1'
	 *
	 * About '<S6>/Math Function2':
	 *  Operator: reciprocal
	 */
	if (PLL_DW.UnitDelay_DSTATE_n >= rt_roundd(1.0 / (50.0 * PLL_B.Probe[0]))) {
		PLL_DW.UnitDelay1_DSTATE = (rtb_MathFunction1 - rtb_RoundingFunction1)
				* Initial / rtb_MathFunction1
				+ (PLL_DW.DiscreteTimeIntegrator_DSTATE_p
						- rtb_ImpAsg_InsertedFor_Out1_at_) * rtb_Saturation;
	}

	/* End of Switch: '<S6>/Switch' */

	/* DiscreteTransferFcn: '<S3>/Discrete Derivative ' incorporates:
	 *  UnitDelay: '<S6>/Unit Delay1'
	 */
	rtb_ImpAsg_InsertedFor_Out1_at_ = (PLL_DW.UnitDelay1_DSTATE
			- -0.0005 * PLL_DW.DiscreteDerivative_states) / 0.001;

	/* Saturate: '<S3>/Saturation1' incorporates:
	 *  DiscreteIntegrator: '<S3>/Discrete-Time Integrator'
	 *  DiscreteTransferFcn: '<S3>/Discrete Derivative '
	 *  Gain: '<S3>/Kp4'
	 *  Sum: '<S3>/Sum6'
	 *  UnitDelay: '<S6>/Unit Delay1'
	 */
	rtb_Saturation = fmax(
			(180.0 * PLL_DW.UnitDelay1_DSTATE
					+ PLL_DW.DiscreteTimeIntegrator_DSTATE_c)
					+ (rtb_ImpAsg_InsertedFor_Out1_at_
							- PLL_DW.DiscreteDerivative_states), 0.0);

	/* Gain: '<S2>/Gain10' */
	rtb_MathFunction1 = 0.15915494309189535 * rtb_Saturation;

	/* RateLimiter: '<S2>/Rate Limiter' */
	rtb_RoundingFunction1 = rtb_MathFunction1 - PLL_DW.PrevY;
	if (rtb_RoundingFunction1 > 0.006) {
		rtb_MathFunction1 = PLL_DW.PrevY + 0.006;
	} else if (rtb_RoundingFunction1 < -0.006) {
		rtb_MathFunction1 = PLL_DW.PrevY - 0.006;
	}

	PLL_DW.PrevY = rtb_MathFunction1;

	/* End of RateLimiter: '<S2>/Rate Limiter' */

	/* UnitDelay: '<S8>/Delay_x1' */
	rtb_RoundingFunction1 = PLL_DW.Delay_x1_DSTATE;

	/* UnitDelay: '<S8>/Delay_x2' */
	rtb_x2k = PLL_DW.Delay_x2_DSTATE;

	/* Gain: '<S9>/A21' incorporates:
	 *  UnitDelay: '<S8>/Delay_x1'
	 */
	rtb_A21 = -11.682623176051715 * PLL_DW.Delay_x1_DSTATE;

	/* Sum: '<S8>/A*x1(k) + B*u1(k) ' incorporates:
	 *  Gain: '<S10>/B11'
	 *  Gain: '<S9>/A11'
	 *  Gain: '<S9>/A12'
	 *  Sum: '<S9>/sum2'
	 *  UnitDelay: '<S8>/Delay_x1'
	 *  UnitDelay: '<S8>/Delay_x2'
	 */
	PLL_DW.Delay_x1_DSTATE = (0.99707934420598721 * PLL_DW.Delay_x1_DSTATE
			+ 0.00047299218241765627 * PLL_DW.Delay_x2_DSTATE)
			+ 0.00023649609120882098 * rtb_MathFunction1;

	/* Sum: '<S8>/A*x2(k) + B*u2(k)' incorporates:
	 *  Gain: '<S10>/B21'
	 *  Gain: '<S9>/A22'
	 *  Sum: '<S9>/sum3'
	 *  UnitDelay: '<S8>/Delay_x2'
	 */
	PLL_DW.Delay_x2_DSTATE = (0.89196872967067631 * PLL_DW.Delay_x2_DSTATE
			+ rtb_A21) + 0.94598436483533821 * rtb_MathFunction1;

	/* Sum: '<S8>/C*X(k)+D*u(k)' incorporates:
	 *  Gain: '<S11>/C11'
	 *  Gain: '<S11>/C12'
	 *  Gain: '<S8>/D*u(k)'
	 *  Sum: '<S11>/sum2'
	 *  UnitDelay: '<S2>/Unit Delay'
	 */
	PLL_DW.UnitDelay_DSTATE = (12.331665457862051 * rtb_RoundingFunction1
			+ 0.0029206557940127608 * rtb_x2k)
			+ 0.0014603278970063804 * rtb_MathFunction1;

	/* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
	PLL_DW.DiscreteTimeIntegrator_DSTATE += 0.0005 * rtb_Saturation;
	PLL_DW.DiscreteTimeIntegrator_PrevRese = (int8_T) rtb_RelationalOperator;

	/* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
	PLL_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
	PLL_DW.DiscreteTimeIntegrator_DSTATE_p += 0.00025 * Initial;

	/* Update for DiscreteTransferFcn: '<S3>/Discrete Derivative ' */
	PLL_DW.DiscreteDerivative_states = rtb_ImpAsg_InsertedFor_Out1_at_;

	/* Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' incorporates:
	 *  UnitDelay: '<S6>/Unit Delay1'
	 */
	PLL_DW.DiscreteTimeIntegrator_DSTATE_c += 1.6 * PLL_DW.UnitDelay1_DSTATE;
	if (PLL_DW.DiscreteTimeIntegrator_DSTATE_c < 0.0) {
		PLL_DW.DiscreteTimeIntegrator_DSTATE_c = 0.0;
	}

	/* End of Update for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
}

/* Model initialize function */
void PLL_initialize(void) {
	/* Start for InitialCondition: '<S2>/Initial' */
	PLL_DW.Initial_FirstOutputTime = true;

	/* Start for Probe: '<S6>/Probe' */
	PLL_B.Probe[0] = 0.0005;
	PLL_B.Probe[1] = 0.0;

	/* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
	PLL_DW.UnitDelay_DSTATE = 50.0;

	/* InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
	PLL_DW.DiscreteTimeIntegrator_PrevRese = 2;

	/* InitializeConditions for DiscreteIntegrator: '<S3>/Discrete-Time Integrator' */
	PLL_DW.DiscreteTimeIntegrator_DSTATE_c = 314.15926535897933;

	/* InitializeConditions for RateLimiter: '<S2>/Rate Limiter' */
	PLL_DW.PrevY = 50.0;

	/* InitializeConditions for UnitDelay: '<S8>/Delay_x1' */
	PLL_DW.Delay_x1_DSTATE = 4.0486813217365336;

	/* Enable for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
	PLL_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;
}

/* Model terminate function */
void PLL_terminate(void) {
	/* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
