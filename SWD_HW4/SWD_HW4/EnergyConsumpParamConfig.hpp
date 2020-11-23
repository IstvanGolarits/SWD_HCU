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

#ifndef ENERGY_CONSUMPTION_PARAM_CONFIG_HPP
#define ENERGY_CONSUMPTION_PARAM_CONFIG_HPP

namespace istvan_richard
{
    class CEnergyConsumptionParamConfig
    {
    public:
        std::string fGetUnitOfThreshold();
        std::string fGetUnitOfTimeSpawn();
        float fGetTimeSpawn();
        float fGetConsumedPowerThreshold();
    private:
        std::string     m_UnitOfThreshold_s;
        std::string     m_UnitOfTimeSpawn_s;
        float           m_TimeSpawn_f64;
        float           m_ConsumedPowerThreshold_f64;

    };


}//end of namespace



#endif
