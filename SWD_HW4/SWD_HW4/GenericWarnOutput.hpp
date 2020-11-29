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
    class CGenericWarningOutput
    {
    public:
        enum class E_MotionWarning
        {

        };

        enum class E_EnergyConsumptionWarning
        {

        };

        enum class E_Acknowlegdement
        {

        };

        enum class E_ErrorType
        {

        };

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
