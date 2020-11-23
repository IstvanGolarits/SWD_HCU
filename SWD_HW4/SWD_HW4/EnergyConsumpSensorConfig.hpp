/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file:
/// --------------------------------------------------------

#include <stdlib.h>
#include <string>

#ifndef ENERGY_CONSUMPTION_SENSOR_CONFIG_HPP
#define ENERGY_CONSUMPTION_SENSOR_CONFIG_HPP

namespace istvan_richard
{
    class CEnergyConsumptionSensorConfig
    {
    public:
        float fGetResolution();
        float fGetMinRange();
        float fGetMaxRange();
        float fGetSamplingRate();
    private:
        std::string     m_SensorType_s;
        float           m_Resolution_f64;
        float           m_MinRange_f64;
        float           m_MaxRange_f64;
        float           m_SamplingRate_f64;

    };


}//end of namespace



#endif
