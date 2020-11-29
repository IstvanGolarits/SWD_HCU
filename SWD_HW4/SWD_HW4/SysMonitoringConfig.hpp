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
#include "CustomTypes.hpp"
#include <stdlib.h>
#include <string>
#include <vector>

namespace istvan_richard
{
    class CSysMonitoringConfig
    {

    private:
        int m_NotificationFrequency_i32;
        int m_AcknowledgementTimeThreshold_i32;
        bool m_NotificationStatus_b;
        bool m_MonitoringOnOff_b;
        bool m_EnergyConsumpRiskDetectFailSwitch_b;
        bool m_EnergyConsumpInteractFeatureSwitch_b;


    public:
        
        CSysMonitoringConfig() :
            m_NotificationFrequency_i32(0),
            m_AcknowledgementTimeThreshold_i32(0),
            m_NotificationStatus_b(false),
            m_MonitoringOnOff_b(false),
            m_EnergyConsumpRiskDetectFailSwitch_b(false),
            m_EnergyConsumpInteractFeatureSwitch_b(false)
        {};

        CSysMonitoringConfig(
            int&    f_ref1_r,
            int&    f_ref2_r,
            bool&    f_ref3_r,
            bool&    f_ref4_r,
            bool&    f_ref5_r,
            bool&    f_ref6_r
        ) :
            m_NotificationFrequency_i32(f_ref1_r),
            m_AcknowledgementTimeThreshold_i32(f_ref2_r),
            m_NotificationStatus_b(f_ref3_r),
            m_MonitoringOnOff_b(f_ref4_r),
            m_EnergyConsumpRiskDetectFailSwitch_b(f_ref5_r),
            m_EnergyConsumpInteractFeatureSwitch_b(f_ref6_r)
        {}

        const int  fGetNotificationFrequency() const;
        const int  fGetAcknowledgementTimeThreshold() const;
        const bool fGetNotificationStatus_b() const;
        const bool fGetMonitoringOnOff() const;
        const bool fGetEnergyConsumpRiskDetectFailSwitch() const;
        const bool fGetEnergyConsumpInteractFeatureSwitch() const;



    };


}//end of namespace

#endif

