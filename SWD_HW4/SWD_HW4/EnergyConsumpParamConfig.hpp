/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file:
/// --------------------------------------------------------

#ifndef ENERGY_CONSUMPTION_PARAM_CONFIG_HPP
#define ENERGY_CONSUMPTION_PARAM_CONFIG_HPP

#include <stdlib.h>
#include <string>
#include "CustomTypes.hpp"

namespace istvan_richard
{
    class CEnergyConsumptionParamConfig
    {
    public:
        CEnergyConsumptionParamConfig() :
            m_UnitOfThreshold_s("Watts"),
            m_UnitOfTimeSpawn_s("Sec"),
            m_TimeSpawn_f64(100),
            m_ConsumedPowerThreshold_f64(3800),
            m_StartOfTimeFrame(),
            m_EndOfTimeFrame()
        {}

        CEnergyConsumptionParamConfig(const CEnergyConsumptionParamConfig& f__r):
            m_UnitOfThreshold_s("Watts"),
            m_UnitOfTimeSpawn_s("Sec"),
            m_TimeSpawn_f64(100),
            m_ConsumedPowerThreshold_f64(3800),
            m_StartOfTimeFrame(),
            m_EndOfTimeFrame()
        {
            if (this != &f__r)
            {
                this->m_UnitOfThreshold_s           = f__r.m_UnitOfThreshold_s;
                this->m_UnitOfTimeSpawn_s           = f__r.m_UnitOfTimeSpawn_s;
                this->m_TimeSpawn_f64               = f__r.m_TimeSpawn_f64;
                this->m_ConsumedPowerThreshold_f64  = f__r.m_ConsumedPowerThreshold_f64;
                this->m_StartOfTimeFrame            = f__r.m_StartOfTimeFrame;
                this->m_EndOfTimeFrame              = f__r.m_EndOfTimeFrame;
            }
        }

        CEnergyConsumptionParamConfig(const std::string& f_ThreshUnit_r, const std::string& f_TimeUnit_r,
        const float& f_TimeSpawn_r, const float& f_ConsumedPowerThresh_r,
            const DateTime& f_StartTimes_r, const DateTime& f_EndTimes_r) :
            m_UnitOfThreshold_s(f_ThreshUnit_r),
            m_UnitOfTimeSpawn_s(f_TimeUnit_r),
            m_TimeSpawn_f64(f_TimeSpawn_r),
            m_ConsumedPowerThreshold_f64(f_ConsumedPowerThresh_r),
            m_StartOfTimeFrame(f_StartTimes_r),
            m_EndOfTimeFrame(f_EndTimes_r)
        {}

        void operator = (const CEnergyConsumptionParamConfig& f__r)
        {
            if (this != &f__r)
            {

                this->m_UnitOfThreshold_s = f__r.m_UnitOfThreshold_s;
                this->m_UnitOfTimeSpawn_s = f__r.m_UnitOfTimeSpawn_s;
                this->m_TimeSpawn_f64 = f__r.m_TimeSpawn_f64;
                this->m_ConsumedPowerThreshold_f64 = f__r.m_ConsumedPowerThreshold_f64;
                this->m_StartOfTimeFrame = f__r.m_StartOfTimeFrame;
                this->m_EndOfTimeFrame = f__r.m_EndOfTimeFrame;
            }
        }

        const std::string fGetUnitOfThreshold()  const
        {
            return m_UnitOfThreshold_s;
        }
        const std::string fGetUnitOfTimeSpawn()  const
        {
            return m_UnitOfTimeSpawn_s;
        }
        const float fGetTimeSpawn()              const
        {
            return m_TimeSpawn_f64;
        }
        const float fGetConsumedPowerThreshold() const
        {
            return m_ConsumedPowerThreshold_f64;
        }

        DateTime fGetStartDateTime()
        {
            return m_StartOfTimeFrame;
        }
        DateTime fGetEndOfTimeFrame()
        {
            return m_EndOfTimeFrame;
        }
    private:
        std::string     m_UnitOfThreshold_s;
        std::string     m_UnitOfTimeSpawn_s;
        //Unit is assumed to be [s] - sec as default
        float           m_TimeSpawn_f64;
        //Unit is assumed to be [W] - Watts as default
        float           m_ConsumedPowerThreshold_f64;
        DateTime        m_StartOfTimeFrame;
        DateTime        m_EndOfTimeFrame;

    };


}//end of namespace



#endif
