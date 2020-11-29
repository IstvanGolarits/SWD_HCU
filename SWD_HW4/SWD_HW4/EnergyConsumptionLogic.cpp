/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#include "EnergyConsumpBusinnessLogic.hpp"

namespace istvan_richard
{
    void CEnergyConsumptionLogic::fUpdateEnergyConsumptionLogic()
    {
        fCheckTooHighEnergy();
        if (fIsInTimeFrame())
        {
            if (m_EneryConsumpParamConfig_r.fGetConsumedPowerThreshold() <= m_EnergyConsumpSensor_r.fGetConsumedPower())
            {
                auto l_TimeSinceTooHigh = m_EneryConsumpParamConfig_r.fGetStartDateTime().fGetTimeDiffSinceRefInSec(m_StartTimeStampOfTooHighenergy, m_TimeStamp_r);
                if (l_TimeSinceTooHigh >= m_EneryConsumpParamConfig_r.fGetTimeSpawn())
                {
                    m_EnergyConst2SysInfo_r.fUpdateEnergyStateValue(CEnergyConsump2SysInfo::E_EnergyConsumptionState::WARNING);
                }
                else
                {
                    m_EnergyConst2SysInfo_r.fUpdateEnergyStateValue(CEnergyConsump2SysInfo::E_EnergyConsumptionState::SUS);
                }
            }
            else
            {
                m_EnergyConst2SysInfo_r.fUpdateEnergyStateValue(CEnergyConsump2SysInfo::E_EnergyConsumptionState::ALL_OK);
            }
        }
        else
        {
            if (m_EneryConsumpParamConfig_r.fGetConsumedPowerThreshold() <= m_EnergyConsumpSensor_r.fGetConsumedPower())
            {
                m_EnergyConst2SysInfo_r.fUpdateEnergyStateValue(CEnergyConsump2SysInfo::E_EnergyConsumptionState::WARNING);
            }
            else
            {
                m_EnergyConst2SysInfo_r.fUpdateEnergyStateValue(CEnergyConsump2SysInfo::E_EnergyConsumptionState::ALL_OK);
            }
        }

    }

    void CEnergyConsumptionLogic::fCheckTooHighEnergy()
    {
        if (m_EneryConsumpParamConfig_r.fGetConsumedPowerThreshold() <= m_EnergyConsumpSensor_r.fGetConsumedPower()
            && !m_WasThereTooHighEnergy_b)
        {
            m_StartTimeStampOfTooHighenergy = m_TimeStamp_r.fGetCurrentTime();
            m_WasThereTooHighEnergy_b = true;
        }
        else if(m_EneryConsumpParamConfig_r.fGetConsumedPowerThreshold() > m_EnergyConsumpSensor_r.fGetConsumedPower()
            && m_WasThereTooHighEnergy_b)
        {
            m_StartTimeStampOfTooHighenergy = { std::string(" "), 0, 0, 0 };
            m_WasThereTooHighEnergy_b = false;
        }
    }

    bool CEnergyConsumptionLogic::fIsInTimeFrame()
    {
        auto l_startTimeForDay(m_EneryConsumpParamConfig_r.fGetStartDateTime().fGetCurrentDaySetup(m_TimeStamp_r));
        auto l_endTimeForDay(m_EneryConsumpParamConfig_r.fGetEndOfTimeFrame().fGetCurrentDaySetup(m_TimeStamp_r));
        if (l_startTimeForDay <= m_TimeStamp_r.fGetCurrentTime()
            && l_endTimeForDay >= m_TimeStamp_r.fGetCurrentTime())
        {
            return true;
        }
        return false;
    }
}//end of namespace