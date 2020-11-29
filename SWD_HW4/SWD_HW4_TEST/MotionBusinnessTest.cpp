/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: Testing the encapsulated module of Motion Businness Logic
/// --------------------------------------------------------

#include "gtest/gtest.h"
#include "pch.h"
#include "../SWD_HW4/Motion2SysInfo.hpp"
#include "../SWD_HW4/MotionBusinnessLogic.hpp"

namespace istvan_richard
{
    TEST(MotionBusinnessTest, TestingDefaults)
    {
        //ARRANGE
        CMotionCommInfo         l_MotionCommInfo;
        CMotionDetectionParam   l_MotionParam;
        TimeStamp               l_currentTime;
        CMotion2SysInfo         l_motionToSysInfo;
        CMotionBusinnessLogic   l_businesslogic(l_MotionCommInfo, l_MotionParam, l_currentTime, l_motionToSysInfo);
        //ACT
        l_businesslogic.fUpdateMotionLogic();
        //ASSERT
        EXPECT_EQ(l_motionToSysInfo.fGetMotionState(), CMotion2SysInfo::E_StateOfMotionBussiness::ALL_OK);
    }

    /// Testing ID_22
    TEST(MotionBusinnessTest, TestingValidMotionValidTime)
    {
        //ARRANGE
        CMotionCommInfo         l_MotionCommInfo(10.F, 100, true);
        CMotionDetectionParam   l_MotionParam;
        TimeStamp               l_currentTime;
        CMotion2SysInfo         l_motionToSysInfo;
        CMotionBusinnessLogic   l_businesslogic(l_MotionCommInfo, l_MotionParam, l_currentTime, l_motionToSysInfo);
        //ACT
        l_businesslogic.fUpdateMotionLogic();
        //ASSERT
        EXPECT_EQ(l_motionToSysInfo.fGetMotionState(), CMotion2SysInfo::E_StateOfMotionBussiness::ALL_OK);
    }

    /// Testing ID_21
    TEST(MotionBusinnessTest, TestingNoValidMotionValidTime)
    {
        /// Motion Confidentality is too low to accept. State shall be in ALL_OK

        //ARRANGE
        CMotionCommInfo         l_MotionCommInfo(10.F, 5, false);
        CMotionDetectionParam   l_MotionParam;
        TimeStamp               l_currentTime;
        DailyDateTime           l_dailyCurrentTime(std::string("MONDAY"), 12, 0, 0);
        l_currentTime.fUpdateCurrentTime(l_dailyCurrentTime);
        CMotion2SysInfo         l_motionToSysInfo;
        CMotionBusinnessLogic   l_businesslogic(l_MotionCommInfo, l_MotionParam, l_currentTime, l_motionToSysInfo);
        //ACT
        l_businesslogic.fUpdateMotionLogic();
        //ASSERT
        EXPECT_EQ(l_motionToSysInfo.fGetMotionState(), CMotion2SysInfo::E_StateOfMotionBussiness::WARNING_IN_TIME);
    }

    ///Testing ID_23
    TEST(MotionBusinnessTest, TestingValidMotionInValidTime)
    {
        //ARRANGE
        CMotionCommInfo         l_MotionCommInfo(10.F, 100, true);
        CMotionDetectionParam   l_MotionParam;
        TimeStamp               l_currentTime;
        DailyDateTime           l_dailyTime(std::string("MONDAY"), 5, 0, 0);
        l_currentTime.fUpdateCurrentTime(l_dailyTime);
        CMotion2SysInfo         l_motionToSysInfo;
        CMotionBusinnessLogic   l_businesslogic(l_MotionCommInfo, l_MotionParam, l_currentTime, l_motionToSysInfo);
        //ACT
        l_businesslogic.fUpdateMotionLogic();
        //ASSERT
        EXPECT_EQ(l_motionToSysInfo.fGetMotionState(), CMotion2SysInfo::E_StateOfMotionBussiness::WARNING_OUT_OF_TIME);
    }

    /// Testing ID_24
    TEST(MotionBusinnessTest, TestingInValidMotionInValidTime)
    {
        //ARRANGE
        CMotionCommInfo         l_MotionCommInfo(10.F, 2, true);
        CMotionDetectionParam   l_MotionParam;
        TimeStamp               l_currentTime;
        DailyDateTime           l_dailyTime(std::string("MONDAY"), 5, 0, 0);
        l_currentTime.fUpdateCurrentTime(l_dailyTime);
        CMotion2SysInfo         l_motionToSysInfo;
        CMotionBusinnessLogic   l_businesslogic(l_MotionCommInfo, l_MotionParam, l_currentTime, l_motionToSysInfo);
        //ACT
        l_businesslogic.fUpdateMotionLogic();
        //ASSERT
        EXPECT_EQ(l_motionToSysInfo.fGetMotionState(), CMotion2SysInfo::E_StateOfMotionBussiness::ALL_OK);
    }

    TEST(MotionBusinnessTest, TestingStartOfValidMotionInTime)
    {
        //ARRANGE
        CMotionCommInfo         l_MotionCommInfo(0.5F, 30, true);
        CMotionDetectionParam   l_MotionParam;
        TimeStamp               l_currentTime;
        DailyDateTime           l_dailyTime(std::string("MONDAY"), 16, 0, 0);
        l_currentTime.fUpdateCurrentTime(l_dailyTime);
        CMotion2SysInfo         l_motionToSysInfo;
        CMotionBusinnessLogic   l_businesslogic(l_MotionCommInfo, l_MotionParam, l_currentTime, l_motionToSysInfo);
        //ACT
        l_businesslogic.fUpdateMotionLogic();
        //ASSERT
        EXPECT_EQ(l_motionToSysInfo.fGetMotionState(), CMotion2SysInfo::E_StateOfMotionBussiness::SUS);
    }
    TEST(MotionBusinnessTest, TestingStartOfValidMotionInvalidTime)
    {
        //ARRANGE
        CMotionCommInfo         l_MotionCommInfo(0.5F, 30, true);
        CMotionDetectionParam   l_MotionParam;
        TimeStamp               l_currentTime;
        DailyDateTime           l_dailyTime(std::string("MONDAY"), 5, 0, 0);
        l_currentTime.fUpdateCurrentTime(l_dailyTime);
        CMotion2SysInfo         l_motionToSysInfo;
        CMotionBusinnessLogic   l_businesslogic(l_MotionCommInfo, l_MotionParam, l_currentTime, l_motionToSysInfo);
        //ACT
        l_businesslogic.fUpdateMotionLogic();
        //ASSERT
        EXPECT_EQ(l_motionToSysInfo.fGetMotionState(), CMotion2SysInfo::E_StateOfMotionBussiness::SUS);
    }

}//end of namespace
