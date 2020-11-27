/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef MOTION_BUSINNESS_LOGIC_HPP
#define MOTION_BUSINNESS_LOGIC_HPP

#include "MotionCommInfo.hpp"
#include "MotionDetectionParams.hpp"
#include "Motion2SysInfo.hpp"

namespace istvan_richard
{
    class CMotionBusinnessLogic
    {
    public:
        CMotionBusinnessLogic(const CMotionCommInfo &f_motionCommInfo_r, const CMotionDetectionParam &f_motionDetectParam_r,
            TimeStamp& f_timeStamp_r, CMotion2SysInfo& f_MotionToSysInfo_r):
            m_motionCommInfo_r(f_motionCommInfo_r),
            m_motionDetectParam_r(f_motionDetectParam_r),
            m_TimeStamp_r(f_timeStamp_r),
            m_MotionToSysInfo_r(f_MotionToSysInfo_r)
        {}

        void fUpdateMotionLogic();

    private:

        bool fIsInValidTime();

        const CMotionCommInfo& m_motionCommInfo_r;
        const CMotionDetectionParam& m_motionDetectParam_r;
        TimeStamp& m_TimeStamp_r;
        CMotion2SysInfo& m_MotionToSysInfo_r;

    };

}//end of namespace

#endif