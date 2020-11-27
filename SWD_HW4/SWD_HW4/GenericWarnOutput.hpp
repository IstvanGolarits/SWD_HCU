/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: containing interfaces, and system setup handlers.
/// --------------------------------------------------------

#ifndef GENERIC_WARNING_OUTPUT_HPP
#define GENERIC_WARNING_OUTPUT_HPP

#include <stdlib.h>

namespace istvan_richard
{
	enum class E_MotionWarning : unsigned short int
	{
		NoMotionWorning = 0,
		MotionWarningTemporarily = 1,
		MotionWarningInsideDayTimeWindow = 2,
		MotionWarningOutsideDayTimeWindow = 3,
		MotionWarningInsideEveningTimeWindow = 4,
		MotionWarningOutsideEveningTimeWindow = 5,
		MotionWarningUnhandledState = 6

	};

	enum class E_EnergyConsumptionWarning : unsigned short int
	{
		NoConsumptionWarning = 0,
		ConsumptionWarningTemporarily = 1,
		ConsumptionWarningInsideDayTimeWindow = 2,
		ConsumptionWarningOutsideDayTimeWindow = 3,
		ConsumptionWarningInsideEveningTimeWindow = 4,
		ConsumptionWarningOutsideEveningTimeWindow = 5,
		ConsumptionWarningUnhandledState = 6

	};

	enum class E_Acknowlegdement : unsigned short int
	{
		AcknowledgementSent = 0,
		AcknowledgementReceived = 1,
		WaitForAcknowledgement = 2,
		AcknowledgementUnknown = 3
	};

	enum class E_ErrorType : unsigned short int
	{

		NoMotionError = 1,
		NoConsumptionError = 2,
		NoError = 3,
		MotionSensorError = 4,
		ConsumptionSensorError = 5,
		TransmitionError = 6,
		UIError = 7,
		FredosarError = 8,
		CommunicationError = 9,
		UnknownError = 10

	};
	class CGenericWarningOutput
	{
	public:
		

		const E_MotionWarning             fGetMotionWarningStateGet() const;
		const E_EnergyConsumptionWarning  fGetEnergyConsumptionStateGet() const;
		const E_Acknowlegdement           fGetAcknowledgementGet() const;
		const E_ErrorType                 fGetErrorTypeGet() const;

	private:
		E_MotionWarning             m_MotionWarningState_e;
		E_EnergyConsumptionWarning  m_EnergyConsumptionState_e;
		E_Acknowlegdement           m_Acknowledgement_e;
		E_ErrorType                 m_ErrorType_e;
	};

}//end of namespace



#endif
