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

namespace istvan_richard
{
    class CMotionBusinnessLogic
    {
    public:
        CMotionBusinnessLogic(const CMotionCommInfo &f_motionCommInfo_r, const CMotionDetectionParam &f_motionDetectParam_r,
            const TimeStamp& f_timeStamp_r):
            m_motionCommInfo_r(f_motionCommInfo_r),
            m_motionDetectParam_r(f_motionDetectParam_r),
            m_TimeStamp_r(f_timeStamp_r)
        {}

        void fUpdateMotionLogic();
        void fUpdateMotion2SysInfo();
    private:
        const CMotionCommInfo& m_motionCommInfo_r;
        const CMotionDetectionParam& m_motionDetectParam_r;
        const TimeStamp& m_TimeStamp_r;

    };

}//end of namespace

#endif