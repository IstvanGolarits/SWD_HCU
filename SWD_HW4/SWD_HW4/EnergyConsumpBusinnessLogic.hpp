/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef ENERGY_CONSUMP_BUSINNESS_LOGIC_HPP
#define ENERGY_CONSUMP_BUSINNESS_LOGIC_HPP

#include "EnergyConsump2SysInfo.hpp"
#include "EnergyConsumpParamConfig.hpp"
#include "EnergyConsumpSensorComm.hpp"
#include "EnergyConsumpSensorConfig.hpp"
#include "CommTypeConfig.hpp"
#include "CustomTypes.hpp"

namespace istvan_richard
{
    class CEnergyConsumptionLogic
    {
    public:
        CEnergyConsumptionLogic(
            CEnergyConsumptionParamConfig& f_EneryConsumpParamConfig_r,
            CEnergyConsumptionSensorConfig& f_EnergyConsumpSensorConfi_r,
            CEnergyConsumptionSensorComm& f_EnergyConsumpSensor_r,
            TimeStamp& f_TimeStamp_r,
            CEnergyConsump2SysInfo& f_Energy2sysInfo_r):
            m_EneryConsumpParamConfig_r(f_EneryConsumpParamConfig_r),
            m_EnergyConsumpSensorConfi_r(f_EnergyConsumpSensorConfi_r),
            m_EnergyConsumpSensor_r(f_EnergyConsumpSensor_r),
            m_TimeStamp_r(f_TimeStamp_r),
            m_EnergyConst2SysInfo_r(f_Energy2sysInfo_r),
            m_WasThereTooHighEnergy_b(false),
            m_StartTimeStampOfTooHighenergy(std::string(" "), 0, 0, 0)
        {}

        void fUpdateEnergyConsumptionLogic();

    private:
        void fCheckTooHighEnergy();
        bool fIsInTimeFrame();

        CEnergyConsumptionParamConfig&    m_EneryConsumpParamConfig_r  ;
        CEnergyConsumptionSensorConfig&   m_EnergyConsumpSensorConfi_r ;
        CEnergyConsumptionSensorComm&     m_EnergyConsumpSensor_r      ;
        TimeStamp& m_TimeStamp_r;
        CEnergyConsump2SysInfo& m_EnergyConst2SysInfo_r;
        
        bool m_WasThereTooHighEnergy_b;
        DailyDateTime       m_StartTimeStampOfTooHighenergy;
        //const CCommTypeConfig& m_CommTypeConfig_r;
    };
}//end of namespace

#endif
