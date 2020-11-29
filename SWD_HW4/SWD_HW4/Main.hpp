/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file:
/// --------------------------------------------------------


#ifndef MAIN_HPP
#define MAIN_HPP

#include "MotionCommInfo.hpp"
#include "MotionDetectionParams.hpp"
#include "MotionBusinnessLogic.hpp"

namespace istvan_richard
{
    class CMainLogic
    {
    public:
        CMainLogic():
            m_TimeStamp(),
            m_MotionComm(),
            m_MotionDetectParam(),
            m_MotionBusinness(m_MotionComm, m_MotionDetectParam, m_TimeStamp, m_Motion2SysInfo)
        {}
    private:
        TimeStamp               m_TimeStamp;
        CMotion2SysInfo         m_Motion2SysInfo;
        CMotionCommInfo         m_MotionComm;
        CMotionDetectionParam   m_MotionDetectParam;
        CMotionBusinnessLogic   m_MotionBusinness;
    };

}//end of namespace

#endif

