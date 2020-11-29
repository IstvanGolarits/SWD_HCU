/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef SYSTEM_MONITORING_HPP
#define SYSTEM_MONITORING_HPP

#include "SysMonitoringConfig.hpp"
#include "Motion2SysInfo.hpp"
#include "EnergyConsump2SysInfo.hpp"
#include "CustomTypes.hpp"
#include "GenericWarnOutput.hpp"

namespace istvan_richard
{
    class CSystemMonitoring
    {
    public:
        CSystemMonitoring(
            CSysMonitoringConfig&   f_reConf,
            CMotion2SysInfo&        f_refMotion,
            CEnergyConsump2SysInfo& f_refEnergy,
            TimeStamp&              f_CurrTime,
            CGenericWarningOutput& f_WarningOutput
        ):
            m_SysMonitorConfig(f_reConf),
            m_motion2SysInfo(f_refMotion),
            m_Energy2SysInfo(f_refEnergy),
            m_CurrentTime(f_CurrTime),
            m_WarningOutput(f_WarningOutput),
            m_timeStampOfWarningSent(std::string(" "), 0, 0, 0),
            m_shallInitiateMotionWarning_b(false),
            m_shallInitiateEnergyWarning_b(false),
            m_shallInterruptEnergy_b(false),
            m_IsSystemError_b(false),
            m_IsMotionSensorError_b(false),
            m_IsMotionLogicError_b(false),
            m_IsEnergySensorError_b(false),
            m_IsEnergyLogicError_b(false)
        {}

        void fUpdateSysMonitoring();

    private:
        bool fDidRecievedAcknowledgement();
        bool fIsSysOK();
        void fUpdateErrorStates();

        CSysMonitoringConfig&   m_SysMonitorConfig;
        CMotion2SysInfo&        m_motion2SysInfo;
        CEnergyConsump2SysInfo& m_Energy2SysInfo;
        TimeStamp&              m_CurrentTime;
        CGenericWarningOutput& m_WarningOutput;

        DailyDateTime   m_timeStampOfWarningSent;

        bool m_shallInitiateMotionWarning_b;
        bool m_shallInitiateEnergyWarning_b;
        bool m_shallInterruptEnergy_b;

        bool m_IsSystemError_b;
        bool m_IsMotionSensorError_b;
        bool m_IsMotionLogicError_b;
        bool m_IsEnergySensorError_b;
        bool m_IsEnergyLogicError_b;
    };

}//end of namespace

#endif
