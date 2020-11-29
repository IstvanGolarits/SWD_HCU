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
    enum class E_MotionWarning: unsigned short int
    {
        MotionWarningOK                    =  0,
        MotionWarningInsideDailyTimeFrame  =  1,
        MotionWarningOutsideDailyTimeFrame =  2,
        MotioNWarningInsideNightTimeFrame  =  3,
        MotionWarningNightTimeFrame        =  4,
        MotionWarningSuspicious            = 10,
        MotionWarningUndefined             = 99
    };

    enum class E_EnergyConsumptionWarning: unsigned short int
    {
        EnergyConsumptionWarningOK                     =  0,
        EnergyConsumptionWarningInsideDailyTimeFrame   =  1,
        EnergyConsumptionWarningOutsideDailyTimeFrame  =  2,
        EnergyConsumptionWarningInsideNightTimeFrame   =  3,
        EnergyConsumptionWarningOutsideNightTimeFrame  =  4,
        EnergyConsumptionWarningSuspicious             = 10,
        EnergyConsumptionUndefined                     = 99

    };

    enum class E_Acknowlegdement : unsigned short int
    {
        AcknowledgementOK         =  0,
        AcknowledgementSent       =  1,
        AcknowledgementReceived   =  2,
        AcknowledgementWarning    =  3,
        AcknowledgementUndefined  = 99
    };

    enum class E_ErrorType : unsigned short int
    {
        ErrorOK                       =  0,
        ErrorMotionRelated            =  1,
        ErrorEnergyConsumptionRelated =  2,
        ErrorSystemRelated            =  3,
        ErrorCommunicationRelated     =  4,
        ErrorUndefined                = 99

    };

    class CGenericWarningOutput
    {
    public:
       
        CGenericWarningOutput();
        const E_MotionWarning             fGetMotionWarningStateGet() const;
        const E_EnergyConsumptionWarning  fGetEnergyConsumptionStateGet() const;
        const E_Acknowlegdement           fGetAcknowledgementGet() const;
        const E_ErrorType                 fGetErrorTypeGet() const;

        void fUpdateWarnStates(E_MotionWarning& f_ref1_r, E_EnergyConsumptionWarning& f_ref2_r, E_Acknowlegdement& f_ref3_r,
            E_ErrorType& f_ref4_r);
    private:
        E_MotionWarning             m_MotionWarningState_e;
        E_EnergyConsumptionWarning  m_EnergyConsumptionState_e;
        E_Acknowlegdement           m_Acknowledgement_e;
        E_ErrorType                 m_ErrorType_e;
    };

}//end of namespace



#endif
