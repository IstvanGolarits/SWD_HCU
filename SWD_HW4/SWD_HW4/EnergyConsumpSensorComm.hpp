/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------


#ifndef ENERGY_CONS_SENSOR_COMM_HPP
#define ENERGY_CONS_SENSOR_COMM_HPP

#include <stdlib.h>
#include <string>

namespace istvan_richard
{
    class CEnergyConsumptionSensorComm
    {
    public:
        //C'Tors
        CEnergyConsumptionSensorComm():
            m_ConsumedPower_f64(0)
        {}
        CEnergyConsumptionSensorComm(const CEnergyConsumptionSensorComm& f__r) :
            m_ConsumedPower_f64(0)
        {
            if (this != &f__r)
            {
                this->m_ConsumedPower_f64 = f__r.m_ConsumedPower_f64;
            }
        }
        CEnergyConsumptionSensorComm(const float& f__newVal_r):
            m_ConsumedPower_f64(f__newVal_r)
        {}

        //Functions
        const float fGetConsumedPower() const
        {
            return m_ConsumedPower_f64;
        }
        void fReadConsumedPower(const float& f_powerConsumed_r)
        {
            m_ConsumedPower_f64 = f_powerConsumed_r;
        }

    private:
        
        float           m_ConsumedPower_f64;

    };


}//end of namespace



#endif