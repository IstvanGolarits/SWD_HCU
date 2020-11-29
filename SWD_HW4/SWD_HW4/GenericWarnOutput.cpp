#include"GenericWarnOutput.hpp""

namespace istvan_richard
{
    CGenericWarningOutput::CGenericWarningOutput()
    {
        m_MotionWarningState_e = E_MotionWarning::MotionWarningUndefined;
        m_EnergyConsumptionState_e = E_EnergyConsumptionWarning::EnergyConsumptionUndefined;
        m_Acknowledgement_e = E_Acknowlegdement::AcknowledgementUndefined;
        m_ErrorType_e = E_ErrorType::ErrorUndefined;
    }
    const E_MotionWarning CGenericWarningOutput::fGetMotionWarningStateGet() const
    {
        return m_MotionWarningState_e;
    }
    const E_EnergyConsumptionWarning CGenericWarningOutput::fGetEnergyConsumptionStateGet() const
    {
        return m_EnergyConsumptionState_e;
    }
    const E_Acknowlegdement CGenericWarningOutput::fGetAcknowledgementGet() const
    {
        return m_Acknowledgement_e;
    }
    const E_ErrorType CGenericWarningOutput::fGetErrorTypeGet() const
    {
        return m_ErrorType_e;
    }
}