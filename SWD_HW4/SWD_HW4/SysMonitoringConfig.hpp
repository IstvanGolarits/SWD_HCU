/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef SYS_MONITORING_CONFIG_HPP
#define SYS_MONITORING_CONFIG_HPP

#include <stdlib.h>
#include <string>
#include <vector>

namespace istvan_richard
{
    class CSysMonitoringConfig
    {
    public:
        
        CSysMonitoringConfig():
            m_NotificationFrequency_i32 (0),
            m_AcknowledgementTimeThreshold_i32(0),
            m_NotificationStatus_b(false),
            m_EnergyConsumpRiskDetectFailSwitch_b(false),
            m_EnergyConsumpInteractFeatureSwitch_b(false)
        {}

        const int  fGetNotificationFrequency() const;
        const int  fGetcknowledgementTimeThreshold() const;
        const bool fGetNotificationStatus_b() const;
        const bool fGetMonitoringOnOff() const;
        const bool fGetEnergyConsumpRiskDetectFailSwitch() const;
        const bool fGetEnergyConsumpInteractFeatureSwitch() const;

    private:
        int m_NotificationFrequency_i32;
        int m_AcknowledgementTimeThreshold_i32;
        bool m_NotificationStatus_b;
        bool m_MonitoringOnOff_b;
        bool m_EnergyConsumpRiskDetectFailSwitch_b;
        bool m_EnergyConsumpInteractFeatureSwitch_b;

    };


}//end of namespace

#endif

