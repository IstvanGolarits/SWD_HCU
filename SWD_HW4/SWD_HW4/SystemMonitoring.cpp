/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#include "SystemMonitoring.hpp"

namespace istvan_richard
{

    void CSystemMonitoring::fUpdateSysMonitoring()
    {
        fUpdateErrorStates();
        if(fIsSysOK())
        {
            if (!m_IsMotionLogicError_b && !m_IsMotionSensorError_b)
            {
                if (m_SysMonitorConfig.fGetMonitoringOnOff())
                {
                    switch (m_motion2SysInfo.fGetMotionState())
                    {
                    case CMotion2SysInfo::E_StateOfMotionBussiness::WARNING_IN_TIME:
                    {
                        m_WarningOutput.fUpdateMotionWarn(E_MotionWarning::MotionWarningInsideDailyTimeFrame);
                        break;
                    }
                    case CMotion2SysInfo::E_StateOfMotionBussiness::WARNING_OUT_OF_TIME:
                    {
                        m_WarningOutput.fUpdateMotionWarn(E_MotionWarning::MotionWarningOutsideDailyTimeFrame);
                        break;
                    }
                    case CMotion2SysInfo::E_StateOfMotionBussiness::SUS:
                    {
                        m_WarningOutput.fUpdateMotionWarn(E_MotionWarning::MotionWarningSuspicious);
                        break;
                    }
                    case CMotion2SysInfo::E_StateOfMotionBussiness::ALL_OK:
                    {
                        m_WarningOutput.fUpdateMotionWarn(E_MotionWarning::MotionWarningOK);
                        break;
                    }
                    default:
                    {
                        m_WarningOutput.fUpdateMotionWarn(E_MotionWarning::MotionWarningUndefined);
                        break;
                    }
                    }
                }
            }
        }
    }

    bool CSystemMonitoring::fIsSysOK()
    {
        return !m_IsSystemError_b;
    }

    void CSystemMonitoring::fUpdateErrorStates()
    {
        //Handled the two motion error as the same, as there is no way to differ them just yet.
        m_IsMotionLogicError_b = (CMotion2SysInfo::E_StateOfMotionBussiness::ERROR == m_motion2SysInfo.fGetMotionState());
        m_IsMotionSensorError_b = (CMotion2SysInfo::E_StateOfMotionBussiness::ERROR == m_motion2SysInfo.fGetMotionState());
    }

}//end of namespace
