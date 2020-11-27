/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: Testing Energy Consumption Businness Logic encapsulated module
/// --------------------------------------------------------


#include "gtest/gtest.h"
#include "pch.h"
#include "../SWD_HW4/EnergyConsumpBusinnessLogic.hpp"
#include <string>

namespace istvan_richard
{
    TEST(EnergyConsumptionLogicTest, TestingDefaults)
    {
        //ARRANGE
        CEnergyConsumptionParamConfig   l_EneryConsumpParamConfig;
        CEnergyConsumptionSensorConfig  l_EnergyConsumpSensorConfig;
        CEnergyConsumptionSensorComm    l_EnergyConsumpSensor;
        TimeStamp                       l_TimeStamp;
        CEnergyConsump2SysInfo          l_EnergyCons2Sysinfo;
        CEnergyConsumptionLogic         l_energyConsumption(l_EneryConsumpParamConfig, l_EnergyConsumpSensorConfig, l_EnergyConsumpSensor, l_TimeStamp, l_EnergyCons2Sysinfo);
        //ACT
        l_energyConsumption.fUpdateEnergyConsumptionLogic();
        //ASSERT
        EXPECT_EQ(l_EnergyCons2Sysinfo.fGetEnergyState(), CEnergyConsump2SysInfo::E_EnergyConsumptionState::ALL_OK);
    }

    TEST(EnergyConsumptionLogicTest, TestingTooHighEnergy)
    {
        //ARRANGE
        CEnergyConsumptionParamConfig   l_EneryConsumpParamConfig;
        CEnergyConsumptionSensorConfig  l_EnergyConsumpSensorConfig;
        CEnergyConsumptionSensorComm    l_EnergyConsumpSensor(4000);
        DailyDateTime                   l_dailyTime(std::string("MONDAY"), 15, 0, 0);
        TimeStamp                       l_TimeStamp;
        l_TimeStamp.fUpdateCurrentTime(l_dailyTime);
        CEnergyConsump2SysInfo          l_EnergyCons2Sysinfo;
        CEnergyConsumptionLogic         l_energyConsumption
        (l_EneryConsumpParamConfig, 
            l_EnergyConsumpSensorConfig, 
            l_EnergyConsumpSensor, 
            l_TimeStamp, 
            l_EnergyCons2Sysinfo);
        //ACT
        l_energyConsumption.fUpdateEnergyConsumptionLogic();
        //ASSERT
        EXPECT_EQ(l_EnergyCons2Sysinfo.fGetEnergyState(), CEnergyConsump2SysInfo::E_EnergyConsumptionState::SUS);
        //ARRANGE
        l_dailyTime = { std::string("MONDAY"), 15, 0, 30 };
        //ACT
        l_energyConsumption.fUpdateEnergyConsumptionLogic();
        //ASSERT
        EXPECT_EQ(l_EnergyCons2Sysinfo.fGetEnergyState(), CEnergyConsump2SysInfo::E_EnergyConsumptionState::WARNING);
    }

    TEST(EnergyConsumptionLogicTest, TestingEnergySpike)
    {
        /// Teststeps:
        /// 1.: Consumption too high - time -> referance
        /// 2.: Consumption too high - time -> Just before the limit
        /// 3.: Consumption is lower than threshold - time -> Just after threshold
        /// 
        /// Expectations:
        /// 1.: SUS
        /// 2.: SUS
        /// 3.: ALL_OK

        //ARRANGE
        CEnergyConsumptionParamConfig   l_EneryConsumpParamConfig;
        CEnergyConsumptionSensorConfig  l_EnergyConsumpSensorConfig;
        CEnergyConsumptionSensorComm    l_EnergyConsumpSensor(4000);
        DailyDateTime                   l_dailyTime(std::string("MONDAY"), 15, 0, 0);
        TimeStamp                       l_TimeStamp;
        l_TimeStamp.fUpdateCurrentTime(l_dailyTime);
        CEnergyConsump2SysInfo          l_EnergyCons2Sysinfo;
        CEnergyConsumptionLogic         l_energyConsumption
        (l_EneryConsumpParamConfig,
            l_EnergyConsumpSensorConfig,
            l_EnergyConsumpSensor,
            l_TimeStamp,
            l_EnergyCons2Sysinfo);
        //ACT
        l_energyConsumption.fUpdateEnergyConsumptionLogic();
        //ASSERT
        EXPECT_EQ(l_EnergyCons2Sysinfo.fGetEnergyState(), CEnergyConsump2SysInfo::E_EnergyConsumptionState::SUS);
        //ARRANGE
        l_dailyTime = { std::string("MONDAY"), 15, 0, int(l_EneryConsumpParamConfig.fGetTimeSpawn()-1U) };
        //ACT
        l_energyConsumption.fUpdateEnergyConsumptionLogic();
        //ASSERT
        EXPECT_EQ(l_EnergyCons2Sysinfo.fGetEnergyState(), CEnergyConsump2SysInfo::E_EnergyConsumptionState::SUS);
        //ARRANGE
        l_EnergyConsumpSensor.fReadConsumedPower(l_EneryConsumpParamConfig.fGetConsumedPowerThreshold() - 1);
        l_dailyTime = { std::string("MONDAY"), 15, 0, int(l_EneryConsumpParamConfig.fGetTimeSpawn() + 1U) };
        //ACT
        l_energyConsumption.fUpdateEnergyConsumptionLogic();
        //ASSERT
        EXPECT_EQ(l_EnergyCons2Sysinfo.fGetEnergyState(), CEnergyConsump2SysInfo::E_EnergyConsumptionState::ALL_OK);
    }

    TEST(EnergyConsumptionLogicTest, TestingNormalEnergy)
    {
        //ARRANGE
        CEnergyConsumptionParamConfig   l_EneryConsumpParamConfig;
        CEnergyConsumptionSensorConfig  l_EnergyConsumpSensorConfig;
        CEnergyConsumptionSensorComm    l_EnergyConsumpSensor(l_EneryConsumpParamConfig.fGetConsumedPowerThreshold()-1);
        DailyDateTime                   l_dailyTime(std::string("MONDAY"), 15, 0, 0);
        TimeStamp                       l_TimeStamp;
        l_TimeStamp.fUpdateCurrentTime(l_dailyTime);
        CEnergyConsump2SysInfo          l_EnergyCons2Sysinfo;
        CEnergyConsumptionLogic         l_energyConsumption
        (l_EneryConsumpParamConfig,
            l_EnergyConsumpSensorConfig,
            l_EnergyConsumpSensor,
            l_TimeStamp,
            l_EnergyCons2Sysinfo);
        //ACT
        l_energyConsumption.fUpdateEnergyConsumptionLogic();
        //ASSERT
        EXPECT_EQ(l_EnergyCons2Sysinfo.fGetEnergyState(), CEnergyConsump2SysInfo::E_EnergyConsumptionState::ALL_OK);
        //ARRANGE
        l_dailyTime = { std::string("MONDAY"), 17, 0, 0 };
        //ACT
        l_energyConsumption.fUpdateEnergyConsumptionLogic();
        //ASSERT
        EXPECT_EQ(l_EnergyCons2Sysinfo.fGetEnergyState(), CEnergyConsump2SysInfo::E_EnergyConsumptionState::ALL_OK);
    }

}//end of namespace
