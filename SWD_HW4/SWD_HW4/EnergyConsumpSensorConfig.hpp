/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file:
/// --------------------------------------------------------


#ifndef ENERGY_CONSUMPTION_SENSOR_CONFIG_HPP
#define ENERGY_CONSUMPTION_SENSOR_CONFIG_HPP

#include <stdlib.h>
#include <string>

namespace istvan_richard
{
    class CEnergyConsumptionSensorConfig
    {
    public:
        const float fGetResolution() const
        {
            return m_Resolution_f64;
        }
        const float fGetMinRange() const
        {
            return m_MinRange_f64;
        }
        const float fGetMaxRange() const
        {
            return m_MaxRange_f64;
        }
        const float fGetSamplingRate() const 
        {
            return m_SamplingRate_f64;
        }
        const std::string fGetSensorType() const
        {
            return m_SensorType_s;
        }
    private:
        std::string     m_SensorType_s;
        float           m_Resolution_f64;
        float           m_MinRange_f64;
        float           m_MaxRange_f64;
        float           m_SamplingRate_f64;

    };


}//end of namespace



#endif
